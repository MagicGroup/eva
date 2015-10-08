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
#ifndef EVAMAINWINDOW_H
#define EVAMAINWINDOW_H

#include "evamainuibase.h"
#include <ntqpoint.h>
#include <ntqsize.h>
#include <ntqtooltip.h>
#include <ntqmap.h>

#include <kurl.h>
#include <tdehtml_part.h>
#include <list>
#include <string>
#include "evalistview.h"
#include "evamain.h"
#include "evadcopview.h"

class MainWindowTip : public TQToolTip{
public:
	MainWindowTip(TQWidget *parent);
	virtual ~MainWindowTip() {}
	
protected:
	void maybeTip(const TQPoint &);
};

class TQResizeEvent;
class TQListViewItem;
class TDEPopupMenu;
class TDEHTMLPart;
class EvaContactListView;
class EvaQunsListView;
class EvaRecentContactsListView;
class EvaScriptWidget;

class EvaMainWindow : public EvaMainUIBase, virtual public EvaDCOPViewInterface
{
	Q_OBJECT
public:
	EvaMainWindow(TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 ); // | WDestructiveClose
	~EvaMainWindow();
	
	void setMainInfo(const unsigned int id, const TQString &nick, TQPixmap *p);
	TQRect tipRect(const TQPoint &pos);
	TQString myInfoTip();
	const unsigned int getQQ() const { return qqNum; }
	void setSystemMenu( TDEPopupMenu *sys);
	void setStatusMenu( TDEPopupMenu *status);
	
	void setPosAndSize();
	const TQPoint &getPosition() const { return nowPosition; }
	const TQSize &getSize() const { return nowSize; }

	void changeGroupTo(const unsigned int id, const int index);
	void addBuddy(const unsigned int id);

	void updateBuddy(const unsigned int id);
	void updateMyInfo();

	void addQun(const unsigned int id);
	void updateQun(const unsigned int id);

	void clearList();
	void clearQunList();



	void updateContacts();
	void updateQuns();
	void updateRecentContacts();
	
	void ShowTab(int key);
	void showInfoFrame(bool showInfo = false);
	void UpdateLoginInfo(int value, const TQString &msg);

	/// DCOP Actions calls
	int  addTab(TQString scriptName, TQString name, TQString image, TQString contents);
	//void removeTab( int id); // it is in public slots
	void removeTabs(TQString scriptName);
	bool updateTab(int id, TQString contents);
	void addButton(TQString scriptName, TQString buttonName, TQString image, TQString tip);
	void removeButton(TQString scriptName, TQString buttonName);
	void removeButtons(TQString scriptName);
	bool isTabExisted(int id);
	void bringToFront(int id);
	void openChatWindow(unsigned int id, bool isQun);
	void updateStatusBar( TQString message);
	void openUrl(int id, TQString url);

public slots:
	void changeToOnline(unsigned int id);
	void changeToOffline(unsigned int id);
	void changeToLeave(unsigned int id);
	void changeToInvisible(unsigned int id);
	void newMessage(unsigned int id);
	void gotMessage(unsigned int id);
	void newQunMessage(unsigned int id);
	void gotQunMessage(unsigned int id);

	void addBuddyToRecentList(const unsigned int id, bool isMyWord = false);
	void addQunToRecentList(const unsigned int id, bool isMyWord = false);
	void slotFaceSizeChanged();
	
	void deleteBuddy(unsigned int id);
	
	void online();
	void offline();
	void leave();
	void invisible();

	bool removeTab(int id); //! DCOP call
signals:
	void groupDeleted(const int);  // paremeter is the group index
	//void groupAdded(TQString, int); // group name & index
	void groupRenamed(TQString, int); // group name & index
	void deleteMeFrom(const unsigned int);
	void groupChanged(const unsigned int,int);
	
	void requestChat(const unsigned int);
	void requestSendFile(const unsigned int);
	void requestLevel(const unsigned int);
	void requestDetails(const unsigned int);
	void requestModifyMemo(const unsigned int);
	void requestHistory(const unsigned int);
	void requestDelete(const unsigned int);  // the deleting qq number 
	void requestSearch();
	void requestSystemMessages();
	
	void requestQunChat(const unsigned int);
	void requestQunDetails(const unsigned int);
	void requestQunExit(const unsigned int);
	void requestQunCreate();
	void requestQunHistory(const unsigned int);
protected:
	void resizeEvent( TQResizeEvent *event);
	void moveEvent( TQMoveEvent *event );

private slots:
	void slotUpdateBuddyStat();
	void slotTbMyFace();
	
	void slotSearch();
	void slotSystemMessages();
	void slotSystemClicked();
	void slotStatusClicked();

private:
	TQPoint  nowPosition;
	TQSize   nowSize;
	unsigned int qqNum;
	TQMap<int, EvaScriptWidget *> m_customTabs;
	TQMap<int, TQString> m_tabScriptMap;

	TDEPopupMenu *sysMenu;
	TDEPopupMenu *statusMenu;

	TQPixmap *pixOnline;
	TQPixmap *pixOffline;
	TQPixmap *pixLeave;
	TQPixmap *pixInvisible;

	MainWindowTip *myTip;

	EvaContactListView *m_buddyLv;
	int m_buddyTabKey;

	EvaQunsListView *m_qunLv;
	int m_qunTabKey;

	EvaRecentContactsListView *m_recentLv;
	int m_recentTabKey;

	void loadContacts();
	void loadQuns();
	void loadRecentContacts();
	
	EvaScriptWidget *getCustomTab( int id );
	
	friend class EvaMain;
};

#endif
