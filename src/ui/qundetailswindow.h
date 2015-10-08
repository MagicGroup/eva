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

#ifndef TQUNDETAILSWINDOW_H
#define TQUNDETAILSWINDOW_H

#include "qundetailsui.h"
#include <list>

class Qun;
class TQTextCodec;
class EvaQunMemberPicker;
class TQCloseEvent;
class TQMoveEvent;
class QunDetailsWindow : public QunDetailsUI
{
	Q_OBJECT

public:
	//QunDetailsWindow(TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
	QunDetailsWindow(Qun *qun, const bool isInList = true, TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
	~QunDetailsWindow();
	
public slots:
	void slotQunInfomationReady(const unsigned int id, const bool ok, TQString msg);
	void slotModifyQunInfo(const unsigned int id, const bool ok, TQString msg = TQString::null);
	void slotModifyQunCardReply(const unsigned int id, const bool ok, const unsigned int qq, TQString msg = TQString::null);
	void slotSetAdmin(const unsigned int id, const bool ok, const unsigned int qq, const bool isSetAdmin, TQString msg = TQString::null);
	void slotTransferQun(const unsigned int id, const bool ok, const unsigned int qq, TQString msg = TQString::null);
	void slotModifyQunMembers(const unsigned int id, const bool ok, TQString msg = TQString::null);
	void slotReceivedQunCard(const unsigned int id, const bool ok, const unsigned int qq, TQString realName, const unsigned char gender, 
				TQString phone, TQString email, TQString memo, TQString msg);
	void slotMembersUpdated(const unsigned int id);
signals:
	void requestQunInfo(const unsigned int id);
	void requestQunCard(const unsigned int, const unsigned int);
	void requestModifyQunInfo(const unsigned int id, unsigned char auth, unsigned short cate, TQString name, TQString notice, TQString description);
	void requestModifyQunCard(const unsigned int id, const unsigned int qq, TQString name, unsigned char gender, TQString phone, TQString email, TQString memo);
	void requestQunSetAdmin(const unsigned int id, const unsigned int qq, const bool isSetAdmin);
	void requestQunTransfer(const unsigned int id, const unsigned int qq);
	void requestModifyQunMembers(const unsigned int id, const std::list<unsigned int> list, const bool isAdd);
	void requestAddBuddy(const unsigned int id, const TQString nick, const unsigned short face);
	void requestUpdateQunMessageSettings(const unsigned int id, const signed char type);
	
	void removeMember(const unsigned int id);
protected:
	virtual void closeEvent( TQCloseEvent *event);
	virtual void moveEvent (TQMoveEvent *event);
private:
	Qun *mQun;
	TQTextCodec *codec;
	EvaQunMemberPicker *picker;
	bool m_IsInList;
	
	int numModifications;
	unsigned short category;
	unsigned int m_CardId;
	
	void initTable();
	void initInformation();
	void setWidgetEnabledForInformation(bool enabled);
	
private slots:
	void slotClose();
	void slotLoadMembers();
	void slotUpdateClicked();
	void slotModifyInfo();
	void slotModifyQunCard();
	void slotTableClicked(int row,int col,int button,const TQPoint& mousePos);
	
	void slotSetMembersClicked();
	void slotAddToMeClicked();
	void slotDelMembersClicked();
	void slotSetAdminClicked();
	void slotUnsetAdminClicked();
	void slotTransferClicked();
	
	void slotPickerMemberClicked(const unsigned int id, const bool isChecked);
	
	void slotModifyMembers();
	void slotCategoryClicked();
	void slotCategorySelected(const unsigned short );
	
	void slotUpdateMessageSetting();	
};

#endif

