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

#include "evatabwidget.h"

#include <ntqpoint.h>
#include <ntqrect.h>
#include <ntqtooltip.h>
#include <ntqpainter.h>
#include <ntqsizepolicy.h>
#include <ntqimage.h>
#include <ntqmemarray.h>
#include <ntqevent.h>
#include <ntqlayout.h>

#define TAB_BAR_SIZE         26
#define TAB_ICON_SIZE        (TAB_BAR_SIZE - 4)
#define TAB_BAR_GRID_WIDTH   1
//#define TAB_GRID_COLOR      (TQColor(0xDD, 0xE9, 0xF9))
#define TAB_GRID_COLOR      (TQColor(0x2D, 0x7A, 0xFF))
#define TAB_LEFT_MARGIN      4


class EvaTabToolTip : public TQToolTip
{
public:
	EvaTabToolTip(EvaTabBar *bar, TQToolTipGroup *group = 0);
	virtual ~EvaTabToolTip();
protected:
	void maybeTip(const TQPoint &p);
private:
	EvaTabBar *m_bar;
};

EvaTabToolTip::EvaTabToolTip(EvaTabBar *bar, TQToolTipGroup *group)
	: TQToolTip(bar, group),
	m_bar(bar)
{
	//setPalette( TQPalette(TQt::yellow, TQColor(20,190,255)));
}

EvaTabToolTip::~EvaTabToolTip()
{
}

void EvaTabToolTip::maybeTip(const TQPoint &p)
{
    TQRect rect = m_bar->itemRect(p);
    if(rect.width() && rect.height())
        tip(rect, m_bar->tip(p));
}


/// =========================================================


EvaTabBar::EvaTabBar(TQWidget *parent, const char * name, WFlags f )
    : TQWidget(parent, name, f),
    m_CurrentTab(0),
    m_Counter(0),
    m_gridColor(TAB_GRID_COLOR)
{
	m_selectedColor = colorGroup().light();
	//setBackgroundMode(TQWidget::PaletteBase);
	setGeometry(TQRect(0, 0, TAB_BAR_SIZE, 31256));
	setMinimumSize(TAB_BAR_SIZE, 0);
	setMaximumSize(TAB_BAR_SIZE, 31256);
	//     setSizePolicy( TQSizePolicy( TQSizePolicy::Fixed,
	//                                 TQSizePolicy::Preferred,
	//                                 0, 0, false ));
	
	m_toolTip = new EvaTabToolTip(this);
}

EvaTabBar::~EvaTabBar()
{
    m_d.clear();
    delete m_toolTip;
    m_toolTip = 0;
}

// return the key of the just created tab
int EvaTabBar::addTab(TQString &name, TQPixmap icon, TQString &tip)
{
    TabData data;
    if(icon.width() > TAB_ICON_SIZE ||
        icon.height() > TAB_ICON_SIZE){
        data.setData(name, icon.convertToImage().smoothScale(TAB_ICON_SIZE, TAB_ICON_SIZE), tip);
    } else
        data.setData(name, icon, tip);

    m_d[m_Counter++] = data;
		updateBasePixmap();
		TQWidget::update();
    return (m_Counter - 1);
}

bool EvaTabBar::removeTab(int key)
{
    TQMap<int, TabData>::Iterator itr = m_d.find(key);
    if(itr == m_d.end()) return false;

    m_d.erase(itr);
    updateBasePixmap();
		TQWidget::update();
    return true;
}

void EvaTabBar::changeTabTo(int key)
{
    int seq = getTabSequence(key);
    if(seq == -1) return;
    bitBlt(&m_Buffer, 0,0, &m_BasePixmap, 0,0, m_BasePixmap.width(), m_BasePixmap.height());


    int x1,y1,x2,y2;
    x1 = TAB_BAR_GRID_WIDTH;
    y1 = (seq * TAB_BAR_SIZE) + TAB_BAR_GRID_WIDTH;
//     x2 = TAB_BAR_SIZE - TAB_BAR_GRID_WIDTH;
//     y2 = seq * TAB_BAR_SIZE + TAB_BAR_SIZE - TAB_BAR_GRID_WIDTH;

    TQPainter p(&m_Buffer);
    p.setPen(m_selectedColor);
    p.setBrush(m_selectedColor);
    p.drawRect(x1, y1, TAB_BAR_SIZE, TAB_BAR_SIZE);

    p.setPen(TQPen(m_gridColor, TAB_BAR_GRID_WIDTH));
    x1 = 0;
    y1 = (seq * TAB_BAR_SIZE);
    x2 = TAB_BAR_SIZE;
    y2 = y1;
    p.drawLine(x1, y1, x2, y2);

    p.drawLine(x1, y1 + TAB_BAR_SIZE, x2, y2 + TAB_BAR_SIZE);


    x2 = x1;
    y2 = seq * TAB_BAR_SIZE + TAB_BAR_SIZE;
    p.drawLine(x1, y1, x2, y2);

    x1 = (TAB_BAR_SIZE - m_d[key].icon.width()) / 2;
    y1 = y1 + (TAB_BAR_SIZE - m_d[key].icon.height()) / 2;
    p.drawPixmap(x1, y1, m_d[key].icon);

    m_CurrentTab = key;
    //repaint(TQRect(itemRect(TQPoint( TAB_BAR_SIZE/2, (y1+y2)/2))));
    repaint();
}

int EvaTabBar::getTabSequence(int key)
{
    TQMap<int, int>::Iterator it;
    for(it = m_index.begin(); it != m_index.end(); ++it){
        if(it.data() == key)
            return it.key();
    }
    return -1;
}

int EvaTabBar::getTabSequence(int /*x*/, int y)
{
    return  (y / (TAB_BAR_SIZE));
}

int EvaTabBar::getTabKey(int seq)
{
    TQMap<int, int>::Iterator it = m_index.find(seq);
    if(it == m_index.end()) return -1;
    return it.data();
}

int EvaTabBar::getTabKey(int x, int y)
{
    return m_index[getTabSequence(x, y)];
}

void EvaTabBar::wheelEvent ( TQWheelEvent * e )
{
    e->accept();
    int offset = (e->delta()>0)?(-1):1;
    int seq = getTabSequence(m_CurrentTab);
    if(seq == -1) return;

    int next = getTabKey(seq + offset);
    if(next == -1 ) return;
    changeTabTo(next);
    emit clicked(next);
}

void EvaTabBar::mousePressEvent(TQMouseEvent *e)
{
    e->ignore();
}

void EvaTabBar::mouseReleaseEvent( TQMouseEvent *e)
{
    e->accept();
    unsigned int seq = getTabSequence(e->x(), e->y());
    if(seq >= m_d.size()) return;

    int key = getTabKey(seq);
    if(key == -1 ) return;
    changeTabTo( key );
    emit clicked(key);
}

void EvaTabBar::mouseMoveEvent( TQMouseEvent *e)
{
    e->ignore();
}

void EvaTabBar::paintEvent( TQPaintEvent *e)
{
///    TQWidget::paintEvent(e);
    
//     int x = e->rect().x();
//     int y = e->rect().y();
//     int w = e->rect().width();
//     int h = e->rect().height();
// 
//     TQPainter painter(this);
//     painter.drawPixmap(x, y, m_BasePixmap, x, y, w, h);

    TQMemArray<TQRect> rects = e->region().rects();
    for ( uint i = 0; i < rects.count(); i++ ) {
        TQRect r = rects[(int)i];
        bitBlt( this, r.x(), r.y(), &m_Buffer, r.x(), r.y(), r.width(), r.height() );
    }
}

void EvaTabBar::updateBasePixmap()
{
    m_BasePixmap.resize(width(), height());
    m_BasePixmap.fill(colorGroup().background());
    TQPainter p(&m_BasePixmap);
    int x1,y1,x2,y2;
    TQMap<int, TabData>::Iterator iter;
    int i = 0;
    m_index.clear();
    for(iter = m_d.begin(); iter != m_d.end(); ++iter){
        m_index[i] = iter.key();

        x1 = TAB_LEFT_MARGIN;
        y1 = i * TAB_BAR_SIZE;
        x2 = TAB_BAR_SIZE - TAB_LEFT_MARGIN;
        y2 = y1;
        p.setPen(TQPen(m_gridColor.light(), TAB_BAR_GRID_WIDTH));
        p.drawLine(x1, y1, x2, y2);
        p.setPen(TQPen(TQColor(255,255,255), TAB_BAR_GRID_WIDTH));
        p.drawLine(x1 , y1+1, x2, y2+1);

        x1 = (TAB_BAR_SIZE - iter.data().icon.width()) / 2;
        y1 = y1 + (TAB_BAR_SIZE - iter.data().icon.height()) / 2;
        p.drawPixmap(x1, y1, iter.data().icon);

        i++;
    }
    m_Buffer.resize(m_BasePixmap.width(), m_BasePixmap.height());
    bitBlt(&m_Buffer, 0,0, &m_BasePixmap, 0,0, m_BasePixmap.width(), m_BasePixmap.height());
}

TQRect EvaTabBar::itemRect(const TQPoint &p)
{
    uint seq = getTabSequence(p.x(), p.y());
    if(seq >= m_d.size()) return TQRect(0,0,0,0);

    return TQRect( 0, seq * TAB_BAR_SIZE, TAB_BAR_SIZE, TAB_BAR_SIZE);
}

TQString EvaTabBar::tip(const TQPoint &p)
{
    uint seq = getTabSequence(p.x(), p.y());
    if(seq >= m_d.size()) return TQString::null;

    return m_d[getTabKey(p.x(), p.y())].tip;
}



/// =========================================================


EvaWidgetStack::EvaWidgetStack(TQWidget *parent, const char * name, WFlags f )
    : TQWidgetStack(parent, name, f),
    m_CurrentSeq(0)
{
    m_gridColor = TAB_GRID_COLOR;
    m_tabSelectedColor = colorGroup().light();

    setSizePolicy( TQSizePolicy( TQSizePolicy::Expanding, TQSizePolicy::Preferred));
    setBackgroundMode(TQWidget::PaletteBase);
    setFrameShape( TQFrame::Box );
}

 void EvaWidgetStack::raiseWidget(int id, int seq)
{
    m_CurrentSeq = seq;
    TQWidgetStack::raiseWidget(id);
    repaint();
}

void EvaWidgetStack::paintEvent( TQPaintEvent */*e*/)
{
    //TQWidgetStack::paintEvent(e);
    TQPainter p(this);
    p.setPen(TQPen(m_gridColor, TAB_BAR_GRID_WIDTH));
    p.drawRect(0,0, width(), height());

    p.setPen(m_tabSelectedColor);

    int y1 = m_CurrentSeq * TAB_BAR_SIZE;
    int y2 = y1 + TAB_BAR_SIZE;
    p.drawLine(0, y1+1, 0, y2-1);
}




/// =========================================================


EvaTabWidget::EvaTabWidget( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "EvaTabWidget" );
    EvaTabWidgetLayout = new TQGridLayout( this, 1, 1, 3, 6, "EvaTabWidgetLayout");

    layout = new TQHBoxLayout( 0, 0, 0, "layout2"); 

    evaTabBar = new EvaTabBar( this, "EvaTabBar" );
    evaTabBar->m_gridColor = TAB_GRID_COLOR;
    evaTabBar->m_selectedColor = colorGroup().base();
//     evaTabBar->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5,
//                                         (TQSizePolicy::SizeType)5, 0, 0, 
//                                         evaTabBar->sizePolicy().hasHeightForWidth() ) );
//     evaTabBar->setFrameShape( TQFrame::StyledPanel );
//     evaTabBar->setFrameShadow( TQFrame::Raised );
    layout->addWidget( evaTabBar );

    wsView = new EvaWidgetStack( this, "wsView" );
    wsView->m_gridColor = TAB_GRID_COLOR;
    wsView->m_tabSelectedColor  = colorGroup().background();

    //WStackPage = new TQWidget( wsView, "WStackPage" );
    //wsView->addWidget( WStackPage, 0 );
    layout->addWidget( wsView );

    EvaTabWidgetLayout->addLayout( layout, 0, 0 );
    resize( TQSize(350, 233).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    TQObject::connect(evaTabBar, SIGNAL(clicked(int)), SLOT(changeTabTo(int)));
}


EvaTabWidget::~EvaTabWidget()
{
    // no need to delete child widgets, TQt does it all for us
}

int EvaTabWidget::addTab(TQString &name, TQPixmap icon, TQString &tip, TQWidget *w)
{
    int key = evaTabBar->addTab(name, icon, tip);
    wsView->addWidget(w, key);
    return key;
}

TQWidget *EvaTabWidget::getWidget(int id)
{
	return wsView->widget(id);
}

bool EvaTabWidget::removeTab(int key)
{
    if( !evaTabBar->removeTab(key))
        return false;

    TQWidget *w = wsView->widget(key);
    if(!w) return false;

    wsView->removeWidget(w);
    delete w;
    return true;
}

void EvaTabWidget::changeTabTo(int key)
{
    evaTabBar->changeTabTo(key);
    wsView->raiseWidget( key, evaTabBar->getTabSequence(key));
}

void EvaTabWidget::setGridColor(const TQColor &c)
{
    evaTabBar->m_gridColor = c;
    evaTabBar->updateBasePixmap();
    wsView->m_gridColor = c;
    repaint();
}

void EvaTabWidget::setSelectedColor(const TQColor &c)
{
    evaTabBar->m_selectedColor = c;
    wsView->m_tabSelectedColor = c;
    repaint();
}



