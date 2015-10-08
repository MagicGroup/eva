/***************************************************************************
 *   Copyright (C) 2007 by yunfan                                          *
 *   yunfan_zg@163.com                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "evalistview.h"
#include "evamain.h"
#include "evaresource.h"
#include <ntqheader.h>
#include <ntqpixmap.h>
#include <ntqimage.h>
#include <ntqtimer.h>
#include <ntqdragobject.h>
#include <ntqtextcodec.h>
#include <ntqpoint.h>
#include <ntqrect.h>
#include <ntqtooltip.h>
#include <ntqpainter.h>
#include <ntqpalette.h>
#include <ntqstyle.h>
#include <ntqsimplerichtext.h>
//#include <ntqapplication.h>
#include <tdelocale.h>

#define EVA_LV_LEFT_MARGIN     6


EvaLVToolTip::EvaLVToolTip(EvaListView *lv, TQToolTipGroup *group)
	: TQToolTip(static_cast<TQWidget *>(lv->viewport()), group),
	m_lv(lv)
{
	//setPalette( TQPalette(TQt::yellow, TQColor(20,190,255)));
}

EvaLVToolTip::~EvaLVToolTip()
{
}

void EvaLVToolTip::maybeTip(const TQPoint &p)
{
	EvaListViewItem *item = dynamic_cast<EvaListViewItem *>(m_lv->itemAt(p));
	if(!item) return;

	int section = m_lv->header()->sectionAt(p.x());
	TQRect itemRect = m_lv->itemRect(item);
	TQRect headerRect = m_lv->header()->sectionRect(section);
	TQRect destRect(headerRect.left(), itemRect.top(), headerRect.width(), itemRect.height());
	
        tip(destRect, item->tip());
	
}

/// ==============================================

EvaListViewItem::EvaListViewItem( TQListViewItem *parent, TQString label, TQPixmap *p)
		: TQListViewItem( parent, label),
                m_richText(0)
{
	codec = TQTextCodec::codecForName("GB18030");
	m_icon = 0;
	if(p)
	m_icon = new TQPixmap(*p);
	setDragEnabled(true);
	setText(label);
}

EvaListViewItem::EvaListViewItem( TQListView *parent)
		: TQListViewItem( parent),
                m_richText(0)
{
	codec = TQTextCodec::codecForName("GB18030");
	m_icon = 0;
	setDragEnabled(false);
}

EvaListViewItem::~EvaListViewItem()
{
    if(m_richText) delete m_richText;
    if(m_icon) delete m_icon;
}

void EvaListViewItem::updateIcon(TQPixmap *p)
{
    if(!p) return;
    if(m_icon) delete m_icon;
    m_icon = new TQPixmap(*p);
}

void EvaListViewItem::setText(const TQString &text)
{
    if(!listView()) return;
    if(m_richText) delete m_richText;
    TQListViewItem::setText(0, text);
    m_richText = new TQSimpleRichText( "<qt><nobr>" + text + "</nobr></qt>",
                                listView()->viewport()->font(), TQString::null, 0/*, mimeFactory_*/ );
}

TQString EvaListViewItem::tip()
{
    return text(0);
}

void EvaListViewItem::paintBranches( TQPainter * p, const TQColorGroup & cg, int w, int /*y*/, int h )
{
	TQListView *lv = listView();
	lv->style().drawComplexControl( TQStyle::CC_ListView,
			p, lv, TQRect( 0, 0, w, h ), cg,
			TQStyle::Style_Enabled | TQStyle::Style_Default, TQStyle::SC_ListView, TQStyle::SC_None,
			TQStyleOption() );
}

void EvaListViewItem::paintCell( TQPainter * painter, const TQColorGroup & colourGroup, int column, int width, int align )
{
    if( ! isVisible() ) return;
    if ( column == 0){
        TQBrush *brush;
        TQPalette palette;

        EvaListView *lv = dynamic_cast<EvaListView *> (listView());
        if( !lv ) return;

        palette = lv->viewport()->palette();
        brush   = 0;

        const BackgroundMode bgmode = lv->viewport()->backgroundMode();
        const TQColorGroup::ColorRole crole = TQPalette::backgroundRoleFromMode( bgmode );
        if ( colourGroup.brush( crole ) != lv->colorGroup().brush( crole ) )
            painter->fillRect( 0, 0, width, height(), colourGroup.brush( crole ) );
        else
            lv->paintEmptyArea( painter, TQRect( 0, 0, width, height() ) );

        if ( isSelected() ) {
            brush = new TQBrush( palette.color(TQPalette::Active, TQColorGroup::Highlight) );
            // painter->setPen( palette.color(TQPalette::Active, TQColorGroup::Text) );
        } else {
            // painter->setPen( palette.color(TQPalette::Normal, TQColorGroup::Text) );
            }

        int icon_width = 0;
        if(m_icon){
            icon_width = lv->itemMargin() + m_icon->width();
        }
        // TODO: Change the font for highlighted text
        m_richText->draw( painter, lv->itemMargin() + icon_width, 0, 
                                TQRect( icon_width, 0, width, height() ), colourGroup, brush );
        //setHeight( m_RichText->height() );
        if(m_icon){
            int xo = lv->itemMargin();
            int yo = ( height() - m_icon->height() ) / 2;
            painter->drawPixmap( xo, yo, *m_icon );
        }
        int height = m_richText->height();
        if(m_icon && m_icon->height() > m_richText->height()){
            height = m_icon->height();
        }
        height += 4;
        setHeight( height );
        widthChanged( 0 );
        delete brush;
    } else {
        TQListViewItem::paintCell( painter, colourGroup, column, width, align );
    }
}


/// =================================================




EvaListView::EvaListView(TQWidget *parent, const char *name, WFlags f)
	: TQListView(parent, name, f)
{
	setItemMargin(EVA_LV_LEFT_MARGIN);
	addColumn("1");
	setColumnWidthMode( 0, Manual);
// 	addColumn("2");
// 	setColumnWidthMode( 1, Manual);
	header()->hide();
	setSorting(0);
	setRootIsDecorated( false );
	setTreeStepSize( 8 );
	setDragAutoScroll(true);
	setHScrollBarMode(TQScrollView::AlwaysOff);
	setFrameShape( TQFrame::NoFrame );
	
	setAcceptDrops( true );
	setSelectionMode( TQListView::Extended );
	setSelectionMode(TQListView::Single);
	m_tooltip = new EvaLVToolTip(this);
	
	clearWFlags( WStaticContents );
	setWFlags( WNoAutoErase );
	
	static_cast<EvaListView*>(viewport())->clearWFlags( WStaticContents );
	static_cast<EvaListView*>(viewport())->setWFlags( WNoAutoErase );
	
	codec = TQTextCodec::codecForName("GB18030");

}

EvaListView::~EvaListView()
{
	delete m_tooltip;
	m_tooltip = 0;
}
