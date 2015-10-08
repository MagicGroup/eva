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

#ifndef EVA_CONTACT_LISTVIEW_H
#define EVA_CONTACT_LISTVIEW_H

#include "evalistview.h"
#include "evafriendlist.h"
#include <ntqdatetime.h>

class TQQFriend;
class TQPopupMenu;

class EvaBuddyItem : public EvaListViewItem
{
public:
    EvaBuddyItem( const TQQFriend& buddy, TQListViewItem *parent);

    const unsigned int QQ();
    const TQQFriend &getFriend() const { return m_buddy; }

    void setNumOfMessages(const int n) { m_numOfMessages = n; }
    const int numOfMessages() const { return m_numOfMessages; }
    const bool hasMessage() { return (m_numOfMessages != 0); }

    void nickChanged();
    void onlineChanged();
    void signatureChanged();
    void faceChanged();
    void newMessage();
    void takeMessage();
    void updateIcon(TQPixmap *p);

    void update( );
    TQString tip();
    virtual TQString key( int col, bool ascending) const;
private:
    TQQFriend m_buddy;
    int m_numOfMessages;
};

class EvaGroupItem : public EvaListViewItem
{
public:
	EvaGroupItem( int groupIndex, TQListView *parent);
	
	const int groupIndex() const { return m_groupIndex; }
	void update();
	TQString tip();
	bool hasMessage();
	TQString groupName();
	void setGroupName(const TQString name);
	void setOpen(bool o);
	virtual TQString key( int col, bool ascending) const;
protected:
	virtual void okRename(int col);
	virtual void cancelRename(int col);
private:
	int m_groupIndex;

	const int countOnlineFriends();
};

class EvaContactListView : public EvaListView
{
    Q_OBJECT
public:
	EvaContactListView(TQWidget *parent = 0, const char *name = 0, WFlags f = 0);

	void loadContacts();
	void updateContacts();
	void clear();
	void changeGroupTo(const unsigned int id, const int index);

	void deleteBuddy(const unsigned int id);
	const int numOfGroups() const { return m_groups.size(); }
signals:
	void groupDeleted(const int);  // paremeter is the group index
	//void groupAdded(TQString, int); // group name & index
	void groupRenamed(TQString, int); // group name & index
	void groupChanged(const unsigned int, int); // qq number, group index;
	void deleteMeFrom(const unsigned int);  // ask server to delete me in someone's friend list

	void requestChat(const unsigned int);
	void requestSendFile(const unsigned int);
	void requestLevel(const unsigned int);
	void requestDetails(const unsigned int);
	void requestHistory(const unsigned int);
	void requestModifyMemo(const unsigned int);
	void requestDelete(const unsigned int);  // the deleting qq number 

protected:
	virtual void keyPressEvent( TQKeyEvent *e );
	virtual void startDrag();
	virtual void dragEnterEvent(TQDragEnterEvent *event);
	virtual void dropEvent(TQDropEvent *event);

private:
	std::map<int, EvaGroupItem *> m_groups;
	std::map<unsigned int, EvaBuddyItem *> m_contacts;

	TQPopupMenu *m_groupMenu; 
	TQPopupMenu *m_buddyMenu;

	void initPopup();

private slots:
	void showAll();
	void showOnlineOnly();
	void closeAllGroups();
	void openAllGroups();
	void updateAllGroups();

	void slotRenameGroup();
	void slotNewGroup();
	void slotDelGroup();

	void slotIMChat();
	void slotSendFile();
	void slotUpdataLevel();
	void slotDetails();
	void slotHistory();
	void slotDelBuddy();
	void slotModifyMemo();

	void slotItemRenamed(TQListViewItem *, int);
	void slotContextMenu(TQListViewItem *, const TQPoint & , int);

	void slotBuddyDoubleClick(TQListViewItem *, const TQPoint & , int);
	void slotListViewClicked(TQListViewItem *);

public slots:
	void friendStatusChanged(const int id);
	void slotFaceSizeChanged();
	void buddyAdded(const unsigned int id);
	void newMessage(const unsigned int id);
	void getMessage(const unsigned int id);
};

class Qun;

class EvaQunListViewItem : public EvaListViewItem
{
public:
	EvaQunListViewItem( Qun * q, TQListView *parent);
	const TQString name();
	const unsigned int getQunID() const;
	void newMessage();
	void getMessage();
	const int numOfMessages() { return m_numOfMessages; }

	void update();
	TQString tip();
private:
	Qun *m_qun;
	int m_numOfMessages;
};

class EvaQunsListView : public EvaListView
{
	Q_OBJECT
public:
	EvaQunsListView(TQWidget *parent = 0, const char *name = 0, WFlags f = 0);

	void addQun(const unsigned int id);
	void loadAllQuns();

	void updateQun(const unsigned int id);

signals:
	void requestQunChat(const unsigned int);
	void requestQunDetails(const unsigned int);
	void requestQunExit(const unsigned int);
	void requestQunCreate();
	void requestQunHistory(const unsigned int);

private:
	TQPopupMenu *m_popup;

	void initPopup();
private slots:

	void slotContextMenu(TQListViewItem *, const TQPoint & , int);

	void slotQunDoubleClick(TQListViewItem *, const TQPoint & , int);

	void slotIMQunChat();
	void slotQunDetails();
	void slotQunHistory();
	void slotQunExit();

public slots:
	void newMessage(const unsigned int id);
	void getMessage(const unsigned int id);
	
};

// It maybe be better to inherit from EvaBuddyItem and EvaQunListViewItem
// One cnostructor for each.:), (dread diamond maybe)
class EvaRecentContactLVItem : public EvaListViewItem
{
public:
	EvaRecentContactLVItem( const bool isQun, TQQFriend *f, Qun * q, TQListView *parent);
	const bool isQun() const { return m_type == E_LVIQun; }

	// Buddy methods
	const unsigned int QQ();
	TQQFriend * getFriend() { return m_buddy; }

	void newMessage(const unsigned int t, bool isMyWord = false);
	void getMessage();
	const int numOfMessages() { return m_numOfMessages; }

	// Qun methods
	const TQString QunName();
	const unsigned int getQunID() const;

	void updateIcon(TQPixmap *p);
	void update();
	TQString tip();
	virtual TQString key( int col, bool ascending) const;

	void setTime( const unsigned int t) { m_time = t; }
	unsigned int getTime() const { return m_time; }
private:
	Qun *m_qun;
	TQQFriend *m_buddy;
	int m_numOfMessages;
	unsigned int m_time;

	void buddyUpdate();
	TQString buddyTip();
	void qunUpdate();
	TQString qunTip();
};

class EvaRecentContactsListView : public EvaListView
{
	Q_OBJECT
public:
	EvaRecentContactsListView(TQWidget *parent = 0, const char *name = 0, WFlags f = 0);

	void loadRecentContacts();

signals:
	void requestChat(const unsigned int);
	void requestSendFile(const unsigned int);
	void requestLevel(const unsigned int);
	void requestDetails(const unsigned int);
	void requestHistory(const unsigned int);
	void requestModifyMemo(const unsigned int);
	void requestDelete(const unsigned int);  // the deleting qq number


	void requestQunChat(const unsigned int);
	void requestQunDetails(const unsigned int);
	void requestQunExit(const unsigned int);
	void requestQunCreate();
	void requestQunHistory(const unsigned int);

private:
//	std::list<RecentContact>
	TQPopupMenu *m_buddyMenu;
	TQPopupMenu *m_qunMenu;

	void initBuddyPopup();
	void initQunPopup();

	void updateConfig();

private slots:
	void slotContextMenu(TQListViewItem *, const TQPoint & , int);
	void slotContactDoubleClick(TQListViewItem *, const TQPoint & , int);

	void slotIMChat();
	void slotSendFile();
	void slotUpdataLevel();
	void slotDetails();
	void slotHistory();
	void slotDelBuddy();
	void slotModifyMemo();

	void slotIMQunChat();
	void slotQunDetails();
	void slotQunHistory();
	void slotQunExit();

public slots:
	EvaRecentContactLVItem * addBuddy(const unsigned int id, const unsigned int time = TQDateTime::currentDateTime( TQt::LocalTime).toTime_t());
	EvaRecentContactLVItem * addQun(const unsigned int id, const unsigned int time = TQDateTime::currentDateTime( TQt::LocalTime).toTime_t());
	void newMessage(const unsigned int id, bool isMyWord = false, const unsigned int time = TQDateTime::currentDateTime( TQt::LocalTime).toTime_t());
	void newQunMessage(const unsigned int id, bool isMyWord = false, const unsigned int time = TQDateTime::currentDateTime( TQt::LocalTime).toTime_t());
	void getMessage(const unsigned int id);
	void getQunMessage(const unsigned int id);
};

#endif

 
