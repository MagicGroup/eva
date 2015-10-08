 /***************************************************************************
 *   Copyright (C) 2006 by yunfan                                          *
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

#include "customfaceselector.h"

#include <ntqtabwidget.h>
#include <ntqcheckbox.h>
#include <ntqtoolbutton.h>
#include <ntqlabel.h>
#include <ntqpainter.h>
#include <ntqimage.h>
#include <ntqbitmap.h>
#include <ntqpixmap.h>
#include <tdelocale.h>
#include <math.h>

#include "../evamain.h"
#include "evauser.h"
#include "evausersetting.h"
#include "evaqtutil.h"
#include "evaresource.h"

#define FACE_GRID_SIZE    TQQ_FACE_THUMBNAIL_SIZE
#define GRID_COLOR    (TQColor(0xDD, 0xE9, 0xF9))

// we need draw some grids
#define GRID_LINE_WIDTH   5
#define FACE_PANEL_WIDTH        ((FACE_GRID_SIZE + GRID_LINE_WIDTH) * NUM_W + GRID_LINE_WIDTH)
#define FACE_PANEL_HEIGHT       ((FACE_GRID_SIZE + GRID_LINE_WIDTH) * NUM_H + GRID_LINE_WIDTH)

// note: index, row, col  ---> (0,1,2,3,...,N)
#define RowOf(index)   ( (int)( (index) / NUM_W) )
#define ColOf(index)    ( (index) % NUM_W )
#define IndexOf(r, c, page)    ( (page) * NUM_GRIDS + (r) * NUM_W + c)

// parameters: pixmap with mask, original image, the color to be ignored
static void CreateMaskFromImage(TQPixmap *pixmap, TQImage *image, int color)
{
	TQImage *maskImage;
	TQBitmap maskBitmap;
	int x, dx, y, pixel;
	unsigned char *sourceLine, *destLine;

	// we only deal with depth of 32 images( QQ thumbnail format)
	if(image->depth() != 32) return;
	maskImage = new TQImage(image->width(), image->height(), 8, 2);

	maskImage->setColor(0, TQt::white.rgb());
	maskImage->setColor(1, TQt::black.rgb());

	for(y=0; y < image->height(); y++) {
		sourceLine = image->scanLine(y);
		destLine = maskImage->scanLine(y);
		dx = 0;
		for(x=0; x <  4* image->width(); x+=4, dx++) {
			pixel = *((int *)(sourceLine + x));
			if(pixel == color) pixel = 0;
			else pixel = 1;
			*(destLine + dx ) = pixel;
		}
	}
	maskBitmap = *maskImage;
	delete maskImage;
	pixmap->setMask(maskBitmap);
}

CustomFacePanel::CustomFacePanel(int groupIndex, TQString &group, FaceList &members, TQWidget* parent)
	: TQFrame(parent, "", WStyle_NoBorder),
	m_groupName(group), m_groupIndex(groupIndex), m_CurrSurface(0), m_CurrPage(0)
{
	setPaletteBackgroundColor( TQColor( 255, 255, 255 ) );
	resize( TQSize(FACE_PANEL_WIDTH, FACE_PANEL_HEIGHT).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
	m_Surfaces.setAutoDelete(true);

	if(m_groupIndex == -1)
		initSysPanel();
	else
		initCustomPanel(members);
}

CustomFacePanel::~CustomFacePanel()
{
	m_Surfaces.clear();
	files.clear();
}

void CustomFacePanel::initSysPanel()
{
	int index = 0;
	while(index < TQQ_SMILEY_AMOUNT)
	{
		m_sysIndex[index++] = -1;
	}

	m_Surfaces.clear();
	files.clear();

	
// 	// create a back-buffer panel
// 	TQPixmap *pic = new TQPixmap(FACE_PANEL_WIDTH, FACE_PANEL_HEIGHT);
// 	pic->fill();
// 
// 	// draw grids for last panel buffer
// 	TQPainter painter(pic);
// 	painter.setPen(TQPen(GRID_COLOR, 1));
// 
// 	// draw rows
// 	for(int r=1; r< NUM_H; r++){
// 		int y = r * (FACE_GRID_SIZE + GRID_LINE_WIDTH) - (GRID_LINE_WIDTH>>1) + GRID_LINE_WIDTH;
// 		painter.drawLine(GRID_LINE_WIDTH, y, FACE_PANEL_WIDTH - GRID_LINE_WIDTH, y);
// 	}
// 
// 	// draw cols
// 	for(int c=1; c<NUM_W; c++){
// 		int x = c * (FACE_GRID_SIZE + GRID_LINE_WIDTH) - (GRID_LINE_WIDTH>>1) + GRID_LINE_WIDTH;
// 		painter.drawLine(x, GRID_LINE_WIDTH, x, FACE_PANEL_HEIGHT - GRID_LINE_WIDTH);
// 	}
// 
// 	for(int row=0; row<7; row++){
// 		for(int col=0; col<15; col++){
// 			if(row == 6 && col == 6) {
// 				col = 14;
// 				break;
// 			};
// 			TQPixmap smiley( EvaMain::images->getSmiley(row * 15 + col)); // load smileys
// 
// 			int y = row * (FACE_GRID_SIZE + GRID_LINE_WIDTH) + GRID_LINE_WIDTH;
// 			int x = col * (FACE_GRID_SIZE + GRID_LINE_WIDTH) + GRID_LINE_WIDTH;
// 			painter.drawPixmap(x, y, smiley);
// 		}
// 	}

	int iPages = TQQ_SMILEY_AMOUNT / NUM_GRIDS + ((TQQ_SMILEY_AMOUNT % NUM_GRIDS)?1:0);
	for(int p = 0; p < iPages; p++)
	{
		AddSysPanel( p * NUM_GRIDS);
	}
	setPage(0);
}

int CustomFacePanel::AddSysPanel(int iStartIndex /*= 0*/)
{
	// create a back-buffer panel
	TQPixmap *pic = new TQPixmap(FACE_PANEL_WIDTH, FACE_PANEL_HEIGHT);
	pic->fill();

	// draw grids for last panel buffer
	TQPainter painter(pic);
	painter.setPen(TQPen(GRID_COLOR, 1));

	// draw rows
	for(int r=1; r< NUM_H; r++){
		int y = r * (FACE_GRID_SIZE + GRID_LINE_WIDTH) - (GRID_LINE_WIDTH>>1) + GRID_LINE_WIDTH;
		painter.drawLine(GRID_LINE_WIDTH, y, FACE_PANEL_WIDTH - GRID_LINE_WIDTH, y);
	}

	// draw cols
	for(int c=1; c<NUM_W; c++){
		int x = c * (FACE_GRID_SIZE + GRID_LINE_WIDTH) - (GRID_LINE_WIDTH>>1) + GRID_LINE_WIDTH;
		painter.drawLine(x, GRID_LINE_WIDTH, x, FACE_PANEL_HEIGHT - GRID_LINE_WIDTH);
	}

// 	for(int row=0; row<7; row++){
// 		for(int col=0; col<15; col++){
// 			if(row == 6 && col == 6) {
// 				col = 14;
// 				break;
// 			};
// 			TQPixmap smiley( EvaMain::images->getSmiley(row * 15 + col)); // load smileys
// 
// 			int y = row * (FACE_GRID_SIZE + GRID_LINE_WIDTH) + GRID_LINE_WIDTH;
// 			int x = col * (FACE_GRID_SIZE + GRID_LINE_WIDTH) + GRID_LINE_WIDTH;
// 			painter.drawPixmap(x, y, smiley);
// 		}
// 	}
	
	bool bDrawn = false;
	int i = iStartIndex , iRow, iCol;
	int page = m_Surfaces.count();
	for(; i < (iStartIndex + NUM_GRIDS) && i < TQQ_SMILEY_AMOUNT; i++)
	{
		iRow = (i % NUM_GRIDS) / NUM_W;
		iCol = (i % NUM_GRIDS) % NUM_W;
		m_sysIndex[page * NUM_GRIDS + iRow * NUM_W + iCol] = i;

		TQPixmap smiley( EvaMain::images->getSmiley(i) ); // load smileys

		int y = iRow * (FACE_GRID_SIZE + GRID_LINE_WIDTH) + GRID_LINE_WIDTH;
		int x = iCol * (FACE_GRID_SIZE + GRID_LINE_WIDTH) + GRID_LINE_WIDTH;
		painter.drawPixmap(x, y, smiley);
		if(!bDrawn)
			bDrawn = true;
	}

	if(bDrawn)
	{
		m_Surfaces.append(pic);
		return i;
	}
	return -1;
}

void CustomFacePanel::initCustomPanel(FaceList &members)
{
	m_Surfaces.clear();
	files.clear();
	int index=0, offset = 0;
	TQPixmap *pic = 0;

	TQString dir = EvaMain::user->getSetting()->getCustomSmileyDir() + "/";
	//TQString dir = "./CustomFace/";
	for(FaceList::Iterator it = members.begin(); it != members.end(); ++it){
		files[index]=(*it).org(); // got file name

		if( !(index%NUM_GRIDS) ){
			// create a back-buffer panel
			pic = new TQPixmap(FACE_PANEL_WIDTH, FACE_PANEL_HEIGHT);
			pic->fill();

			// draw grids for last panel buffer
			TQPainter gridPainter(pic);
			gridPainter.setPen(TQPen(GRID_COLOR, 1));

			// draw rows
			for(int r=1; r< NUM_H; r++){
				int y = r * (FACE_GRID_SIZE + GRID_LINE_WIDTH) - (GRID_LINE_WIDTH>>1) + GRID_LINE_WIDTH;
				gridPainter.drawLine(GRID_LINE_WIDTH, y, FACE_PANEL_WIDTH - GRID_LINE_WIDTH, y);
			}

			// draw cols
			for(int c=1; c<NUM_W; c++){
				int x = c * (FACE_GRID_SIZE + GRID_LINE_WIDTH) - (GRID_LINE_WIDTH>>1) + GRID_LINE_WIDTH;
				gridPainter.drawLine(x, GRID_LINE_WIDTH, x, FACE_PANEL_HEIGHT - GRID_LINE_WIDTH);
			}

			// current page index start offset
			offset = (int)( index / ( NUM_GRIDS ) ) * NUM_GRIDS;
			m_Surfaces.append(pic);
		}

		// draw current pixmap onto the buffer
		TQPainter painter(pic);
		TQString file = dir + (m_groupIndex?(m_groupName + "/" + (*it).fixed()):((*it).fixed()) );
		TQPixmap smiley(file); // load smiley thumbnail
		// ignore the pink background color in case of using thumbnails from Win QQ directly
		TQImage img = smiley.convertToImage();
		CreateMaskFromImage(&smiley, &img, tqRgb(255, 0, 255) );

		int row = RowOf(index - offset);
		int col = ColOf(index - offset);
		int y = row * (FACE_GRID_SIZE + GRID_LINE_WIDTH) + GRID_LINE_WIDTH;
		int x = col * (FACE_GRID_SIZE + GRID_LINE_WIDTH) + GRID_LINE_WIDTH;
		painter.drawPixmap(x, y, smiley);
		
		// now, ready for next smiley
		index++;
	}
	setPage(0);
}

void CustomFacePanel::setPage(int index)
{
	if(index<0 || index >= (int)(m_Surfaces.count()) ) return;
	m_CurrPage = index;
	m_CurrSurface = m_Surfaces.at(index);
	repaint(false);
}

void CustomFacePanel::paintEvent( TQPaintEvent *e)
{
	if(!m_CurrSurface){
		TQFrame::paintEvent(e);
		return;
	}
	
	int x = e->rect().x();
	int y = e->rect().y();
	int w = e->rect().width();
	int h = e->rect().height();

	TQPainter painter(this);
	painter.drawPixmap(x, y, *m_CurrSurface, x, y, w, h);

	drawFrame(&painter);
}

void CustomFacePanel::mouseReleaseEvent( TQMouseEvent * e)
{
	if(e->button() != TQt::LeftButton){
		e->ignore();
		return;
	}

	int row = e->y() / (FACE_GRID_SIZE + GRID_LINE_WIDTH);
	int col = e->x() / (FACE_GRID_SIZE + GRID_LINE_WIDTH);
	if(row < NUM_H && col < NUM_W)
	{
		if(m_groupIndex == -1){
			int index = m_CurrPage * NUM_GRIDS + row * NUM_W + col;
			if( index < TQQ_SMILEY_AMOUNT && m_sysIndex[index] != -1)
				emit selectSysFace(m_sysIndex[index]);
	
		} else {
			int index = IndexOf(row, col, m_CurrPage);
		
			if(index < 0 || index >= (int)(files.size()) ) return;
		
			TQString name = (m_groupIndex)?m_groupName:"";
			emit selectCustomFace(name, files[index]);
		}
	}
}

///*  =========================================== */

CustomFaceSelector::CustomFaceSelector( bool useSysFaceOnly, TQWidget* parent,  const char* name, WFlags fl )
    : CustomFaceUIBase( parent, name, fl ), m_UseSysFaceOnly(useSysFaceOnly)
{
	// system smiley first
	FaceList list;
	TQString gn;
	CustomFacePanel *tab = new CustomFacePanel( -1, gn, list, twSelector);
	twSelector->insertTab(tab, i18n("System"));

	int total = tab->numPages();
	int curr = tab->page();
	lblPage->setText(TQString("%1/%2").arg(curr+1).arg(total));
	connect(tab, SIGNAL(selectSysFace(int)),
		this, SLOT(slotSelectSysFace(int)) );

	
	if(!m_UseSysFaceOnly) {
		TQString dir = EvaMain::user->getSetting()->getCustomSmileyDir() + "/";
		//TQString dir = "./CustomFace/";
		CustomFaceConfig config(dir);
		if(config.loadXML()){
			TQStringList groups = config.groupNames();
			int i = 0;
			for(TQStringList::Iterator it = groups.begin(); it  != groups.end(); ++it){
				FaceList faces = config.groupMembers(i);
				
				tab = new CustomFacePanel(i, *it, faces, twSelector);
				twSelector->insertTab(tab, *it);

				connect(tab, SIGNAL(selectCustomFace(TQString, TQString)),
					this, SLOT(slotSelectCustomFace(TQString, TQString)) );
				i++;
			}
		}
		//TODO: remove these two lines after custom face manager finished
		//tbAdd->hide();
		chbUseShortcut->hide();
	}else{
		tbAdd->hide();
		chbUseShortcut->hide();
		//lblPage->setText( i18n("Enjoy Eva, Enjoy Open Source!") );
		//tbPrev->hide();
		//tbNext->hide();
	}
 
	connect(tbAdd, SIGNAL(clicked()), this, SLOT(slotAddSmileyClicked()) );
	connect(chbUseShortcut, SIGNAL(clicked()), this, SLOT(slotUseShortcutClicked()) );
	connect(tbPrev, SIGNAL(clicked()), this, SLOT(slotPrevClicked() ) );
	connect(tbNext, SIGNAL(clicked()), this, SLOT(slotNextClicked() ) );
	connect(twSelector, SIGNAL(currentChanged( TQWidget *)), this, SLOT(slotPanelChanged(TQWidget *)) );
}

CustomFaceSelector::~CustomFaceSelector()
{
    // no need to delete child widgets, TQt does it all for us
}

void CustomFaceSelector::slotSelectSysFace(int id)
{
	emit selectSysFace(id);
	hide();
}

void CustomFaceSelector::slotSelectCustomFace(TQString group, TQString file)
{
	TQString src = EvaMain::user->getSetting()->getCustomSmileyDir();

	if(!group.isEmpty()){
		src += ("/" + group);
	}
	src += ("/" + file );
	TQString dest = EvaMain::user->getSetting()->getPictureCacheDir() + "/" + file;

 	if(EvaHelper::copyFile(src, dest)){
 		emit selectCustomFace(file);
		close();
 	}
}

void CustomFaceSelector::slotAddSmileyClicked()
{
	emit addSmileyClicked();
	close();
}

void CustomFaceSelector::slotUseShortcutClicked()
{
	printf("Shortcut clicked\n");
}

void CustomFaceSelector::slotPrevClicked()
{
	CustomFacePanel *panel = static_cast<CustomFacePanel*>(twSelector->currentPage());
	if(panel){
		int total = panel->numPages();
		int curr = panel->page();
		if(curr <= 0) return;
		panel->setPage( curr - 1);
		lblPage->setText(TQString("%1/%2").arg(curr).arg(total));
	}
}

void CustomFaceSelector::slotNextClicked()
{
	CustomFacePanel *panel = static_cast<CustomFacePanel*>(twSelector->currentPage());
	if(panel){
		int total = panel->numPages();
		int curr = panel->page();
		if(curr >= total -1 ) return;
		panel->setPage( curr + 1);
		lblPage->setText(TQString("%1/%2").arg(curr+2).arg(total));
	}
}

void CustomFaceSelector::slotPanelChanged(TQWidget * w)
{
	if(m_UseSysFaceOnly) return;
	CustomFacePanel *panel = static_cast<CustomFacePanel*>(w);
	if(panel){
		int total = panel->numPages();
		int curr = panel->page();
		lblPage->setText(TQString("%1/%2").arg(curr+1).arg(total));
	}	
}

void CustomFaceSelector::paintEvent( TQPaintEvent *e)
{
	TQPainter painter(this);
	painter.setPen(TQPen(TQColor(4, 74, 155), 1));
	painter.drawRect(rect());

	TQWidget::paintEvent(e);
}

void CustomFaceSelector::mouseReleaseEvent( TQMouseEvent * e)
{
	if(e->button() != TQt::LeftButton){
		hide();
		e->accept();
	}
	e->ignore();
}
