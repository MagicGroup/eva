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
 
#include "evaqunmemberpicker.h"
 
#include <ntqlistview.h>
#include <ntqimage.h>
#include <ntqtextcodec.h>
#include <ntqheader.h>
#include <string>

#include "../evamain.h"
#include "evauser.h"
#include "evafriendlist.h"
#include "evafriend.h"
#include "evaresource.h"
#include "evaqunlist.h"
#include "evaqtutil.h"

EvaQunMemberPicker::EvaQunMemberPicker(TQWidget * parent, const char * name, WFlags fl, Qun *qun )
	: EvaQunMemberPickerUI( parent, name, fl )
{
	mQun = qun;
	initListView();
	updateBuddyListView();
}

void EvaQunMemberPicker::initListView()
{
	lvBuddyList->header()->hide();
	lvBuddyList->setRootIsDecorated( true);
	TQObject::connect(lvBuddyList, SIGNAL(clicked(TQListViewItem *)), SLOT(slotClicked(TQListViewItem *)));
	//lvBuddyList->setTreeStepSize( 0 );   
}

void EvaQunMemberPicker::updateBuddyListView()
{
	//if(!mQun) return;
	lvBuddyList->clear();
	
	TQTextCodec *codec = TQTextCodec::codecForName("GB18030");
	std::list<std::string> names = EvaMain::user->getGroupNames();
	std::list<std::string>::iterator groupIter;
	int i=0;
	for(groupIter = names.begin(); groupIter!= names.end(); ++groupIter){
		TQString g = codec->toUnicode(groupIter->c_str());
		TQCheckListItem *item = new TQCheckListItem(lvBuddyList, g, TQCheckListItem::CheckBox);
		item->setState(TQCheckListItem::Off);
		groups[i++] = item;
	}
	
	//QunInfo info = mQun->getDetails();
	
	std::map<unsigned int, TQQFriend>::iterator iter;
	std::map<unsigned int, TQQFriend> list = (EvaMain::user->getFriendList()).getAllFriendsMap();
	for(iter = list.begin(); iter != list.end(); ++iter){
	
		int id = iter->second.getQQ();
		TQString nick = EvaTextFilter::filter(codec->toUnicode(iter->second.getNick().c_str()));
		
		int groupIndex = iter->second.getGroupIndex();
		TQCheckListItem *group = groups[groupIndex];
		if(!group) continue;
		
		short faceID = (iter->second.getFace())/3 + 1;
		if(faceID<1) faceID = 1;
		TQCheckListItem *item = new TQCheckListItem(group, nick + "(" + TQString::number(id) + ")", TQCheckListItem::CheckBox);

		TQPixmap *pic = EvaMain::images->getFace(faceID, true);
		if(pic) {
			TQImage img(pic->convertToImage().smoothScale(16, 16));
			item->setPixmap(0, TQPixmap(img));
		}else{
			fprintf(stderr, "EvaQunMemberPicker::updateBuddyListView (id:%d, faceID:%d, %s) --  NULL TQPixmap pointer, ignored!\n", id, faceID, nick.ascii());
		}
		if(mQun && mQun->hasMember(id))
			item->setState(TQCheckListItem::On);
		else
			item->setState(TQCheckListItem::Off);
			
		buddyList[id] = item;
	}
}

void EvaQunMemberPicker::slotClicked(TQListViewItem *item)
{
	if(!item) return;
	TQCheckListItem *chkItem = dynamic_cast<TQCheckListItem *>(item);
	if(!chkItem) return;
	unsigned int id;
	TQString txt;
	TQString strID;
	bool ok;
	TQString nick;
	TQPixmap face;
	
	TQCheckListItem *child = dynamic_cast<TQCheckListItem *>(chkItem->firstChild());
	if(!child){
		txt = chkItem->text(0);
		int index = txt.findRev("(");
		nick = txt.left( index );
		strID = txt.mid(index+1, txt.length() - index - 1 - 1);
		id = strID.toUInt(&ok);
		if(!ok) return;
		
		face = *(chkItem->pixmap(0));
		
		emit memberClicked(id, chkItem->isOn());
	}
	while(child){
		child->setOn(chkItem->isOn());
		
		txt = child->text(0);
		int index = txt.findRev("(");
		nick = txt.left( index );
		strID = txt.mid(index+1, txt.length() - index - 1 - 1);
		id = strID.toUInt(&ok);
		if(!ok) return;
		
		face = *(child->pixmap(0));
		
		emit memberClicked(id, child->isOn());
		child = dynamic_cast<TQCheckListItem *>(child->nextSibling());
	}
}

void EvaQunMemberPicker::slotSetMemberOff(const unsigned int id)
{
	std::map<int, TQCheckListItem *>::iterator iter;
	iter = buddyList.find(id);
	if(iter == buddyList.end()) return;
	iter->second->setOn(false);
}



