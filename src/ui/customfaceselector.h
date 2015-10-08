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

#ifndef EVACUSTOMFACESELECTOR_H
#define EVACUSTOMFACESELECTOR_H

#include "customfaceuibase.h"
#include "customface.h"
#include <ntqframe.h>
#include <ntqmap.h>
#include <ntqptrlist.h>
#include "evautil.h"

#ifndef NUM_W
#define NUM_W         15
#define NUM_H           8
#define NUM_GRIDS     (NUM_W * NUM_H)
#endif

class CustomFacePanel : public TQFrame
{
	Q_OBJECT

public:
	CustomFacePanel(int groupIndex, TQString &group, FaceList &members, TQWidget* parent = 0);
	virtual ~CustomFacePanel();
	int numPages() { return m_Surfaces.count();}
	int page() { return m_CurrPage; }
	void setPage(int index);
signals:
	void selectSysFace(int);
	void selectCustomFace(TQString, TQString); // group name, file name
private:
	TQString m_groupName;
	int m_groupIndex;
	TQPixmap *m_CurrSurface;
	int m_CurrPage;
	TQPtrList<TQPixmap> m_Surfaces;
	TQMap<int, TQString> files; // index, original file name
	int m_sysIndex[TQQ_SMILEY_AMOUNT];

	void initSysPanel();
	/// return the last added smiley index
	int AddSysPanel(int iStartIndex = 0);
	void initCustomPanel(FaceList &members);
	virtual void paintEvent( TQPaintEvent *e);
	virtual void mouseReleaseEvent( TQMouseEvent * e);
};

class CustomFaceSelector : public CustomFaceUIBase
{
	Q_OBJECT

public:
    CustomFaceSelector( bool useSysFaceOnly = true, TQWidget* parent = 0,
					const char* name = 0,
					WFlags fl = TQt::WStyle_Customize 
							| TQt::WStyle_NoBorder 
							| TQt::WType_Popup);
	~CustomFaceSelector();

signals:
	void selectSysFace(int);
	void selectCustomFace(const TQString &); // file name without path. already in the PictureCache dir

	void addSmileyClicked();

private slots:
	void slotSelectSysFace(int id);
	void slotSelectCustomFace(TQString, TQString);

	void slotAddSmileyClicked();
	void slotUseShortcutClicked();
	void slotPrevClicked();
	void slotNextClicked();
	void slotPanelChanged(TQWidget *);
private:
	bool m_UseSysFaceOnly;

	virtual void paintEvent( TQPaintEvent *e);
	virtual void mouseReleaseEvent( TQMouseEvent * e);
};

#endif // CUSTOMFACESELECTOR_H
