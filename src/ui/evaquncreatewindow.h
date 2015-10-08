/***************************************************************************
 *   Copyright (C) 2005 by yunfan                                          *
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
 
#ifndef TQUNCREATEWINDOW_H
#define TQUNCREATEWINDOW_H

#include "quncreateui.h"
#include <list>

class TQTextCodec;
class EvaQunMemberPicker;
class TQCloseEvent;
class TQMoveEvent; 

class EvaQunCreateWindow : public QunCreateUI
{
	Q_OBJECT
public:
	EvaQunCreateWindow(TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
	virtual ~EvaQunCreateWindow(){};
signals:
	void doQunCreate(const TQString &name, const unsigned short category, const unsigned char auth, const TQString &notice, 
			const TQString &description, const std::list<unsigned int> &members);
	void removeMember(const unsigned int id);
	
public slots:
	void slotQunCreateDone(const unsigned int id);
	void slotQunCreateFailed(TQString msg);
	

protected:
	virtual void closeEvent( TQCloseEvent *event);
	virtual void moveEvent (TQMoveEvent *event);
	
private:
	TQTextCodec *codec;
	EvaQunMemberPicker *picker;
	
	TQString qunName;
	unsigned short qunCategory;
	unsigned char qunAuth;
	TQString qunNotice;
	TQString qunDescription;
	std::list<int> members;
	
	void initTable();
	//void initInformation();
	bool processQunDetailsChecking();
	bool processQunMemberChecking();
	
	void doSendCreateRequest();
	
private slots:
	void slotNextClicked();
	void slotPrevClicked();
	void slotCancel();
	void slotLoadMembers();
	
	void slotTableClicked(int row,int col,int button,const TQPoint& mousePos);
	void slotSetMembersClicked();
	void slotDelMembersClicked();
	void slotPickerMemberClicked(const unsigned int id, const bool isChecked);

	void slotCategoryClicked();
	void slotCategorySelected(const unsigned short );
};

#endif
