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

#ifndef EVATQUNLISTVIEW_H
#define EVATQUNLISTVIEW_H

#include <ntqlistview.h>
#include <list>

class TQPixmap;
//class EvaToolTip;
class TQCustomEvent;
class TQPopupMenu;


class EvaQunBuddyItem :  public TQObject, public TQListViewItem
{
	Q_OBJECT
public:
	EvaQunBuddyItem( TQListView *parent, const TQString &name, const unsigned int id, const TQPixmap *pic, const TQPixmap *offPic);
	
	void update(const unsigned int id, const TQString &name, const TQPixmap *pic, const TQPixmap *offPic, const bool isCreator = false);
	void setCreator(bool isCreator);
	void setAdmin(bool isAdmin);
	void setShareHolder();
	
	void setOnline(const bool online);
	const bool isOnline() const { return mIsOnline; }
	const unsigned int &getQQ() const { return qqNum; }
	const TQString &getNick() const { return nick; }
	
	virtual TQString key( int col, bool ascending) const;
	TQString tip(); 
protected:
	virtual void customEvent( TQCustomEvent *e);
private:
	unsigned int qqNum;
	TQString nick;
	const TQPixmap *facePic;
	const TQPixmap *faceOffPic;
	bool mIsOnline;
	bool mIsCreator;
	bool mIsAdmin;
};

class EvaQunListView : public TQListView 
{
	Q_OBJECT
public:
	EvaQunListView( TQWidget *parent=0, const char *name =0, WFlags f= 0);
	~EvaQunListView();
	
	EvaQunBuddyItem * addQunBuddy(const TQString &nick, const unsigned int id, const TQPixmap *pic, const TQPixmap *offpic);

	void updateOnlineMembers(const std::list<unsigned int> &onlines);
	
	void setCreator(int);
signals:
	void requestBuddyInfo(const unsigned int);
	void requestQunCard(const unsigned int);
	void requestQunMembers();
	void requestChat(const unsigned int);
private:
	//EvaToolTip *mToolTip;
	TQPopupMenu *popupMenu;
private slots:
	void slotContextMenu(TQListViewItem *, const TQPoint & , int);
	void slotDetails();
	void slotDoRefreshMembers();
	void slotQunCard();
	void slotBuddyDoubleClick( TQListViewItem *item, const TQPoint &, int );
};


#endif 
