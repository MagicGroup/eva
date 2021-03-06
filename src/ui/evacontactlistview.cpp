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

#include "evacontactlistview.h"
#include "evamain.h"
#include "evaaddingmanager.h"
#include "evaipseeker.h"
#include "evauser.h"
#include "evausersetting.h"
#include "evaqtutil.h"
#include "evaresource.h"
#include "evaipseeker.h"
#include "evahtmlparser.h"
#include "evauhmanager.h"
#include "evaqunlist.h"

#include <ntqdragobject.h>
#include <ntqtextcodec.h>
#include <ntqpopupmenu.h>
#include <tdemessagebox.h>
#include <kdebug.h>
#include <tdelocale.h>
#include <tdeconfig.h>

EvaBuddyItem::EvaBuddyItem( const TQQFriend& buddy, TQListViewItem *parent)
    : EvaListViewItem(parent,""),
    m_buddy(buddy),
    m_numOfMessages(0)
{
	m_type = E_LVIBuddy;
	update();
}

const unsigned int EvaBuddyItem::QQ()
{
	return m_buddy.getQQ();
}

void EvaBuddyItem::nickChanged()
{
    update();
}

void EvaBuddyItem::onlineChanged()
{
    update();
}

void EvaBuddyItem::signatureChanged()
{
    update();
}

void EvaBuddyItem::faceChanged()
{
    update();
}

void EvaBuddyItem::newMessage()
{
    ++m_numOfMessages;
    update();
}

void EvaBuddyItem::takeMessage()
{
    m_numOfMessages = 0;
    update();
}

void EvaBuddyItem::update( )
{
	
	EvaImageResource *images = EvaMain::images;

	m_buddy = *(EvaMain::user->getFriends()->getFriend(m_buddy.getQQ()));
	
// 	if((m_buddy.isStatusChanged() && s != m_buddy.getStatus()) || !m_icon ){
// 		m_buddy.inactiveEvaUpdateFlag(StatusChanged);
		TQPixmap *pixmap = images->getFaceByID(m_buddy.getFace(), false);
		switch(m_buddy.getStatus()){
		case TQQ_FRIEND_STATUS_ONLINE:
		case TQQ_FRIEND_STATUS_LEAVE:
			if(m_buddy.hasUserHead()){
				if(images->getUserHeadPixmap(m_buddy.getQQ())) {
					pixmap = images->getUserHeadPixmap(m_buddy.getQQ());
				} else {
					pixmap =  images->getFaceByID(m_buddy.getFace(), true);
				}
			}else
				pixmap =  images->getFaceByID(m_buddy.getFace(), true);
			break;
		case TQQ_FRIEND_STATUS_OFFLINE:
		case TQQ_FRIEND_STATUS_INVISIBLE:
			if(m_buddy.hasUserHead()){
				if(images->getUserHeadPixmap(m_buddy.getQQ())) {
					pixmap = images->getUserHeadPixmap(m_buddy.getQQ(), true);
				}
			}
			break;
		}
	
		if(m_buddy.getStatus() == TQQ_FRIEND_STATUS_LEAVE){
				TQPixmap *na = images->getIcon("NA");
				if(na){
//					TQPixmap scaledNa = na->convertToImage().smoothScale(EvaMain::global->getFaceSize()/ 1.5);
					TQPixmap scaledNa = na->convertToImage().smoothScale(TQSize(12,12));
					copyBlt(pixmap, pixmap->width() - scaledNa.width(), pixmap->height()- scaledNa.height(), 
									&scaledNa, 0, 0, scaledNa.width(), scaledNa.height());
				} else
					kdDebug() << "[EvaBuddyItem] Null image of \"NA\"" << endl;
		}
		
		if( !pixmap || pixmap->isNull())
			pixmap = images->getFaceByID(0, false);
	
//		TQPixmap head = pixmap->convertToImage().smoothScale(EvaMain::global->getFaceSize());
//		updateIcon(&head);
		updateIcon(pixmap);
//   }

	EvaUserSetting * setting = EvaMain::user->getSetting();
// 	if(m_buddy->isNickChanged() || m_buddy->isSignatureChanged() || setting->needRepaint()){

// 		m_buddy->inactiveEvaUpdateFlag(NickChanged);
// 		m_buddy->inactiveEvaUpdateFlag(SignatureChanged);
		setting->setNeedRepaint(false);
		
		TQString nick = EvaTextFilter::filter(codec->toUnicode(m_buddy.getMemo().name.c_str()));
		if(nick.isEmpty())
			nick = EvaTextFilter::filter(codec->toUnicode(m_buddy.getNick().c_str()));

		TQString signature = EvaTextFilter::filter(codec->toUnicode(m_buddy.getSignature().c_str()));
		
		TQString htmlName = nick;
		if(setting->isShowSmileyInNickName()){
						EvaHtmlParser parser;
						parser.setAbsImagePath(EvaMain::images->getSmileyPath());
						parser.convertToHtml(htmlName, false, true);
		}
		TQColor showColor = TQt::black;
		if(m_numOfMessages){
						if(setting->isBuddyFlashBold())
										htmlName = ("<b>" + htmlName + "</b>");
						if(setting->isBuddyFlashUnderline())
										htmlName = ("<u>" + htmlName + "</u>");
						if(setting->isBuddyFlashItalic())
										htmlName = ("<i>" + htmlName + "</i>");
						showColor = setting->getBuddyFlashColor();
		} else {
						if(setting->isBuddyNameBold())
										htmlName = ("<b>" + htmlName + "</b>");
						if(setting->isBuddyNameUnderline())
										htmlName = ("<u>" + htmlName + "</u>");
						if(setting->isBuddyNameItalic())
										htmlName = ("<i>" + htmlName + "</i>");
						showColor = setting->getBuddyNameColor();
		}
		//printf("html name: %s\n", htmlName.ascii());
		TQString showName = "<nobr><font color=\"" + showColor.name() + "\">&nbsp;" + htmlName + "</font></nobr>";
	
		TQString showSig = signature;
		if( !signature.isEmpty() ){
						if(setting->isShowSignatureInSeperateLine())
										showName += "<br>";
						if(setting->isBuddySigBold())
										showSig = ("<b>" + showSig + "</b>");
						if(setting->isBuddySigUnderline())
										showSig = ("<u>" + showSig + "</u>");
						if(setting->isBuddySigItalic())
										showSig = ("<i>" + showSig + "</i>");
						showName += ("<nobr><font color=\"" + setting->getBuddySigColor().name() + "\">&nbsp;(" + showSig + ")</font></nobr>");
		} else {
						if(setting->isShowSignatureInSeperateLine())  // just to make sure each item has the same height
										showName += "<br>&nbsp;";
		}
		setText(showName);
// 	}

	if(isVisible())
		listView()->repaintItem(this);
}

void EvaBuddyItem::updateIcon(TQPixmap *p)
{
	if(!p) return;
	if(m_icon) delete m_icon;
	m_icon = new TQPixmap( p->convertToImage().smoothScale(EvaMain::global->getFaceSize() ));
}


TQString EvaBuddyItem::tip()
{
	TQString tip = "<qt>";
	//	if(getFriend()){
	EvaIPSeeker ipAddr(EvaGlobal::getDirPath().latin1());
	TQTextCodec *codec = TQTextCodec::codecForName("GB18030");
	TQString addr = codec->toUnicode(ipAddr.getIPLocation(m_buddy.getIP()).c_str());
	if(addr.length()<4) addr = "0.0.0.0";

	TQString htmlName = EvaTextFilter::filter(codec->toUnicode(m_buddy.getNick().c_str()));
	EvaHtmlParser parser;
	parser.setAbsImagePath(EvaMain::images->getSmileyPath());
	parser.convertToHtml(htmlName, false, true);
	TQString signature = codec->toUnicode(m_buddy.getSignature().c_str());
	if(signature.length() > 40)
		signature = signature.left(37) + "...";
	//		if(!signature.isEmpty())
	//			signature = "[" + signature + "]";
	TQString facePath = "<img src=\"" + EvaMain::images->getFacePath() + "/" +
		TQString::number(EvaMain::images->getFaceFileIndex(m_buddy.getFace())) + 
		".png\"></img>";
	if(m_buddy.hasUserHead() && EvaMain::uhManager){
		TQString uhFileName = EvaMain::uhManager->getFileName(m_buddy.getQQ());
		if(!uhFileName.isEmpty())
			facePath = "<img src=\"" + uhFileName + "\"></img>";
	}
	TQString level = "";
	if ( m_buddy.getLevel() != 0)
	{
		int suns, moons, stars;
		EvaUtil::calcSuns(m_buddy.getLevel(), &suns, &moons, &stars);
		TQString strSun =  "<img src=\"" + EvaMain::images->getIconFullPath("TIME_SUN") + "\"></img>";
		TQString strMoon = "<img src=\"" + EvaMain::images->getIconFullPath("TIME_MOON") + "\"></img>";
		TQString strStar = "<img src=\"" + EvaMain::images->getIconFullPath("TIME_STAR") + "\"></img>";
		for(int i=0; i<suns; i++){
			level += strSun;
		}
		for(int i=0; i<moons; i++){
			level += strMoon;
		}
		for(int i=0; i<stars; i++){
			level += strStar;
		}

		level += "(" + TQString::number(m_buddy.getLevel()) +")";
	}

	tip += "<table width = 250><tr><td width=50 align = left valign = top>" + facePath + 
		"</td><td align = left valign = middle><b><font color = blue>" + htmlName + " (" +  
		TQString::number(m_buddy.getQQ()) + ") </font></b>" +
		"</nobr><br>"+ signature + "<br>" + 
		level + "</td></tr></table>";
	/*
	   } else
	   tip += "<b><font color = blue>" + EvaTextFilter::filter(codec->toUnicode(m_buddy.getNick().c_str())) + 
	   " ("+ TQString::number(m_buddy.getQQ()) +
	   ") </font></b>";
	   */
	tip += "</qt>";
	return tip;
}


TQString EvaBuddyItem::key( int, bool ) const
{
    TQString prefix;
    if(m_numOfMessages)
        prefix = "0";
    else
        prefix = "1";

    switch(m_buddy.getStatus()){
        case TQQ_FRIEND_STATUS_ONLINE:
            prefix = "0";
            break;
        case TQQ_FRIEND_STATUS_LEAVE:
            prefix = "1";
            break;
        case TQQ_FRIEND_STATUS_INVISIBLE:
            prefix = "2";
            break;
        case TQQ_FRIEND_STATUS_OFFLINE:
        default:
            prefix = "3";
    }

    TQString nick = EvaTextFilter::filter(codec->toUnicode(m_buddy.getMemo().name.c_str()));
    if(nick.isEmpty())
        nick = EvaTextFilter::filter(codec->toUnicode(m_buddy.getNick().c_str()));
    return prefix + nick;
}


/** ============================================================== */


EvaGroupItem::EvaGroupItem( int groupIndex, TQListView *parent)
    : EvaListViewItem(parent),
    m_groupIndex(groupIndex)
{
    m_type = E_LVIGroup;
    //setOpen(false);
    update();
}

bool EvaGroupItem::hasMessage()
{
    EvaBuddyItem *item = dynamic_cast<EvaBuddyItem *>(firstChild());
    while(item){
        if(item->hasMessage())
            return true;
        item = dynamic_cast<EvaBuddyItem *>(item->nextSibling());
    }
    return false;
}

void EvaGroupItem::setOpen(bool o)
{
    TDEConfig* const config = EvaMain::user->config( "Group Open Status" );
    config->writeEntry(groupName(), o);

    EvaImageResource *images = EvaMain::images;
    TQPixmap *p;
    if(o){
            p = images->getIcon("OPEN");
    }else{
            p = images->getIcon("CLOSE");
    }
    updateIcon(p);
    TQListViewItem::setOpen(o);
}
	
void EvaGroupItem::okRename( int col )
{
	TQListViewItem::okRename(col);
	setRenameEnabled( 0, false );
	update();
}

void EvaGroupItem::cancelRename( int col )
{
	TQListViewItem::cancelRename(col);
	setRenameEnabled( 0, false );
	update();
}

TQString EvaGroupItem::groupName()
{
    return codec->toUnicode(EvaMain::user->groupNameAtIndex(m_groupIndex).c_str());
}

const int EvaGroupItem::countOnlineFriends()
{
	EvaBuddyItem *item = dynamic_cast<EvaBuddyItem *>(firstChild());
	char s = TQQ_FRIEND_STATUS_OFFLINE;
	int numOnlineFriends = 0;
	while(item){
		s = item->getFriend().getStatus();
		if(s==TQQ_FRIEND_STATUS_ONLINE || s==TQQ_FRIEND_STATUS_LEAVE)
			numOnlineFriends++;
		item = dynamic_cast<EvaBuddyItem *>(item->nextSibling());
	}
	return numOnlineFriends;
}

void EvaGroupItem::update()
{
	sort();
	int num = countOnlineFriends();

	EvaUserSetting * setting = EvaMain::user->getSetting();
	TQColor showColor = TQt::black;
	TQString fontedName = groupName();
	if(hasMessage()){
		if(setting->isGroupFlashBold())
			fontedName = ("<b>" + fontedName + "</b>");
		if(setting->isGroupFlashUnderline())
			fontedName = ("<u>" + fontedName + "</u>");
		if(setting->isGroupFlashItalic())
			fontedName = ("<i>" + fontedName + "</i>");
		showColor = setting->getGroupFlashColor();
	} else {
		if(setting->isGroupNameBold())
			fontedName = ("<b>" + fontedName + "</b>");
		if(setting->isGroupNameUnderline())
			fontedName = ("<u>" + fontedName + "</u>");
		if(setting->isGroupNameItalic())
			fontedName = ("<i>" + fontedName + "</i>");
		showColor = setting->getGroupNameColor();
	}
	//TQColor showColor = isMsgShown?setting->getGroupFlashColor():setting->getGroupNameColor();
	TQString showName = "<font color=\"" + showColor.name() + "\">&nbsp;" + fontedName + "</font>";

	TQString counting = TQString::number(num) + "/" +  TQString::number(childCount());
	if(setting->isGroupOnlineCountBold())
		counting = ("<b>" + counting + "</b>");
	if(setting->isGroupOnlineCountUnderline())
		counting = ("<u>" + counting + "</u>");
	if(setting->isGroupOnlineCountItalic())
		counting = ("<i>" + counting + "</i>");

	showName += (" (<font color=\"" + setting->getGroupCountColor().name() + "\">" + counting + "</font>)");

	setText("<nobr>" + showName +"</nobr>");

	if(listView() && isVisible()){
		listView()->repaintItem(this);
		widthChanged( 0 );
	}
}

TQString EvaGroupItem::tip()
{
	TQString tip = "<table><tr><td align = left valign = middle><nobr><font color = red><b>"+
			i18n("Group") + ": </b></font>"+ groupName() +"</nobr><br><b><font color = red>"+ 
			i18n("Members") +": </font></b>"+ TQString::number(childCount()) +
			"</td></tr></table>";
	return tip;
}

void EvaGroupItem::setGroupName(const TQString name)
{
	setText(name);
	if(listView() && isVisible()){
		listView()->repaintItem(this);
		widthChanged( 0 );
	}
}

TQString EvaGroupItem::key( int, bool ) const
{
	TQString sKey = "";
	if(m_groupIndex == 0)
		sKey = "A";
	else	if(m_groupIndex == EvaUser::getAnonymousIndex() || m_groupIndex == EvaUser::getBlackIndex())
				sKey = "Z";
			else
				sKey = "B";
        sKey += (TQString("%1").arg(m_groupIndex, 3));
	return sKey;
}



/** ============================================================== */


EvaContactListView::EvaContactListView(TQWidget *parent, const char *name, WFlags f)
	: EvaListView(parent, name, f)
{
	setPaletteBackgroundPixmap(*EvaMain::images->getIcon("BACK_GROUND"));
	setStaticBackground(true);

	initPopup();


	TQObject::connect(this, SIGNAL(itemRenamed(TQListViewItem *, int)),
			 		SLOT(slotItemRenamed(TQListViewItem *, int)));
	TQObject::connect(this, SIGNAL(contextMenuRequested(TQListViewItem *, const TQPoint & , int)),
					SLOT(slotContextMenu(TQListViewItem *, const TQPoint & , int)));
	TQObject::connect(this, SIGNAL(doubleClicked(TQListViewItem *, const TQPoint & , int)),
					SLOT(slotBuddyDoubleClick(TQListViewItem *, const TQPoint & , int)));
	TQObject::connect(this, SIGNAL(clicked(TQListViewItem *)),
					SLOT(slotListViewClicked(TQListViewItem *)));
}

void EvaContactListView::loadContacts()
{
	/// clear first
//	TQListView::clear();	
/*	
	/// load groups
	EvaUser *user =  EvaMain::user;
	if(!user) return;
	std::list<std::string> names = user->getGroupNames();
	std::list<std::string>::iterator iter;
	int i=0;

	for(iter = names.begin(); iter!= names.end(); ++iter){
		m_groups[i]  = new EvaGroupItem(i, this);
		i++;
	}

	if (m_groups.size() == 0) return;

	m_groups[user->getAnonymousIndex()] = new EvaGroupItem(user->getAnonymousIndex(), this);
	m_groups[user->getBlackIndex()] = new EvaGroupItem(user->getBlackIndex(), this);
	/// load all contacts
	FriendList *list = EvaMain::user->getFriends();
	TQQFriend *f = list->firstFriend();
	while( f ){
		m_contacts[f->getQQ()] = new EvaBuddyItem(*f, m_groups[f->getGroupIndex()]);
		f = list->nextFriend();
	}
	if(user->getSetting()->isShowOnlineEnabled())
		showOnlineOnly();
	else
		showAll();
	// update group online counts
	TDEConfig* const config = EvaMain::user->config( "Group Open Status" );
	std::map<int, EvaGroupItem *>::iterator it = m_groups.begin();
	while(it != m_groups.end()){
		it->second->setOpen( config->readBoolEntry(it->second->groupName(), false) );
		it->second->update();
		it++;
	}
*/
	updateContacts();
	sort();
}

void EvaContactListView::updateContacts()
{
	/// load groups
	EvaUser *user =  EvaMain::user;
	if(!user) return;
	std::list<std::string> names = user->getGroupNames();
	std::list<std::string>::iterator iter;
	int i=0;
	for(iter = names.begin(); iter!= names.end(); ++iter){
		if(  m_groups.count(i) == 0)
			m_groups[i]  = new EvaGroupItem(i, this);
		i++;
	}

	if (!m_groups.count(user->getAnonymousIndex()))
		m_groups[user->getAnonymousIndex()] = new EvaGroupItem(user->getAnonymousIndex(), this);
	if (!m_groups.count(user->getBlackIndex()))
		m_groups[user->getBlackIndex()] = new EvaGroupItem(user->getBlackIndex(), this);

	/// load all contacts
	int gIndex = 0;
	FriendList *list = EvaMain::user->getFriends();
	TQQFriend *f = list->firstFriend();
	while( f ){
		if ((!m_contacts.count(f->getQQ()))&&(f->getQQ()!=0)){
			gIndex = m_groups.count(f->getGroupIndex())?f->getGroupIndex():0;
			m_contacts[f->getQQ()] = new EvaBuddyItem(*f, m_groups[gIndex]);
		}

		f = list->nextFriend();
	}
	if(user->getSetting()->isShowOnlineEnabled())
		showOnlineOnly();
	else
		showAll();
	
	// update group online counts
	TDEConfig* const config = EvaMain::user->config( "Group Open Status" );
	std::map<int, EvaGroupItem *>::iterator it = m_groups.begin();
	while(it != m_groups.end()){
		it->second->setOpen( config->readBoolEntry(it->second->groupName(), false) );
		it->second->update();
		it++;
	}
}

void EvaContactListView::slotFaceSizeChanged()
{
	FriendList *list = EvaMain::user->getFriends();
	TQQFriend *f = list->firstFriend();
	while( f ){
		if (!m_contacts.count(f->getQQ()))
			m_contacts[f->getQQ()] = new EvaBuddyItem(*f, m_groups[f->getGroupIndex()]);
		else
			m_contacts[f->getQQ()]->update();

		f = list->nextFriend();
	}
}


void EvaContactListView::clear()
{
	m_groups.clear();
	m_contacts.clear();
	TQListView::clear();
}

void EvaContactListView::showAll()
{
	std::map<unsigned int, EvaBuddyItem *>::iterator iter;
	for(iter = m_contacts.begin(); iter != m_contacts.end(); ++iter){
		if(!iter->second->isVisible()) iter->second->setVisible( true);
	}
	EvaMain::user->getSetting()->setShowOnlineEnabled(false);
	EvaMain::user->getSetting()->saveSettings();
}

void EvaContactListView::showOnlineOnly()
{
	std::map<unsigned int, EvaBuddyItem *>::iterator iter;
	TQQFriend f;
	char s = TQQ_FRIEND_STATUS_OFFLINE;
	for(iter = m_contacts.begin(); iter != m_contacts.end(); ++iter){
		f = iter->second->getFriend();
		s = f.getStatus();
		if( s==TQQ_FRIEND_STATUS_ONLINE || s==TQQ_FRIEND_STATUS_LEAVE )
			iter->second->setVisible(true);
		else
			iter->second->setVisible(false);
	}
	EvaMain::user->getSetting()->setShowOnlineEnabled(true);
	EvaMain::user->getSetting()->saveSettings();
}

void EvaContactListView::keyPressEvent( TQKeyEvent *e )
{
    EvaGroupItem *item = dynamic_cast<EvaGroupItem *>(currentItem());
    if ( (e->key() == TQt::Key_F2) && item ){
        item->setGroupName(item->groupName());  // this is to elimate the online number statistics
        item->setRenameEnabled(0, true);
        item->startRename(0);
    }else
        TQListView::keyPressEvent(e);
}

void EvaContactListView::startDrag()
{
    EvaBuddyItem *item = dynamic_cast<EvaBuddyItem *>(currentItem());
    if(!item) return;
    EvaGroupItem * group = dynamic_cast<EvaGroupItem *>(currentItem()->parent());
    if(!group) return;

    closeAllGroups();
    TQDragObject *d = new TQTextDrag(TQString::number(item->QQ()), this);
    d->dragCopy();
}

void EvaContactListView::dragEnterEvent(TQDragEnterEvent *event)
{
    event->accept(TQTextDrag::canDecode(event));
}

void EvaContactListView::dropEvent(TQDropEvent *event)
{
    TQPoint p(contentsToViewport(event->pos()));
    TQListViewItem *i=itemAt( p );
    if(!i) return;
    EvaGroupItem * group = dynamic_cast<EvaGroupItem *>(i);
    if(!group){
        group = dynamic_cast<EvaGroupItem *>(i->parent());
        if(!group) return;
    }

    if( EvaUser::getAnonymousIndex() == group->groupIndex()) return; // cannot drop buddy in Anonymous group


    TQString text;
    if(TQTextDrag::decode(event, text)){
        bool ok;
        unsigned int id = text.toUInt(&ok);

        // if id is in my friend list
        if( EvaMain::user->getFriends()->hasFriend(id)){

		TQQFriend* f = EvaMain::user->getFriends()->getFriend(id);
            int index = f->getGroupIndex();
            // drop in same group
            if( index == group->groupIndex())
                return;

            // if drop in the Black list
            if(EvaUser::getBlackIndex()  == group->groupIndex()) {
                emit deleteMeFrom(id);
                return;
            }

            // if drag buddy from Anonymous or Black List into other group
            if(index == EvaUser::getAnonymousIndex() || index == EvaUser::getBlackIndex()){
                EvaMain::g_AddingManager->slotAddBuddy(id);
                return;
            }

            // now should be group changing happened
            EvaListViewItem *item = m_contacts[id];
            m_groups[index]->takeItem(item);
            if(item){
                group->insertItem(item);
                group->setOpen(true);
                f->setGroupIndex(group->groupIndex());
                m_contacts[id]->update();
                EvaMain::user->saveGroupedBuddyList();
                updateAllGroups();
                emit groupChanged(id, group->groupIndex());
            }
        } else { // if id is not in my friend list, dragged from other client maybe

            // if drop in Black list, just rejected
            if( EvaUser::getBlackIndex()  == group->groupIndex()) {
                return;
            }

            // otherwise, add her/him :)
            EvaMain::g_AddingManager->slotAddBuddy(id);
        }
    }
}

void EvaContactListView::openAllGroups()
{
    EvaGroupItem *group = dynamic_cast<EvaGroupItem *>(firstChild());
    while(group){
        group->setOpen(true);
        group = dynamic_cast<EvaGroupItem *>(group->nextSibling());
    }
}

void EvaContactListView::closeAllGroups()
{
    EvaGroupItem *group = dynamic_cast<EvaGroupItem *>(firstChild());
    while(group){
        if(group->isOpen()) group->setOpen(false);
        group = dynamic_cast<EvaGroupItem *>(group->nextSibling());
    }
}

void EvaContactListView::updateAllGroups()
{
    EvaGroupItem *group = dynamic_cast<EvaGroupItem *>(firstChild());
    while(group){
        group->update();
        group = dynamic_cast<EvaGroupItem *>(group->nextSibling());
    }
}

void EvaContactListView::friendStatusChanged(const int id)
{
	std::map<unsigned int, EvaBuddyItem *>::iterator it = m_contacts.find(id);
	if(it == m_contacts.end()) {
		buddyAdded(id);
		return;
	}
	EvaBuddyItem *b = it->second;
	
	TQQFriend *f;
	char s = TQQ_FRIEND_STATUS_OFFLINE;
	f = EvaMain::user->getFriends()->getFriend(id);
	if(!f->isStatusChanged()) return;
	s = f->getStatus();
	if( s==TQQ_FRIEND_STATUS_ONLINE || s==TQQ_FRIEND_STATUS_LEAVE )
		b->setVisible(true);
	else if(EvaMain::user->getSetting()->isShowOnlineEnabled())
		b->setVisible(false);

	b->update();

	int index = b->getFriend().getGroupIndex();
	std::map<int, EvaGroupItem *>::iterator itr = m_groups.find(index);
	if(itr == m_groups.end()) return;
	
	m_groups[index]->update();

	f->inactiveEvaUpdateFlag(StatusChanged);
}

void EvaContactListView::changeGroupTo( const unsigned int id, const int index )
{
	EvaBuddyItem * i = m_contacts[id];
	int group = i->getFriend().getGroupIndex();
	m_groups[group]->takeItem(i);
	m_groups[index]->insertItem(i);
}

void EvaContactListView::newMessage(const unsigned int id)
{
	std::map<unsigned int,  EvaBuddyItem *>::iterator it = m_contacts.find(id);
	if(it == m_contacts.end()) {
		TQQFriend *f = EvaMain::user->getFriends()->getFriend(id);
		if(!f) {
			kdDebug() << "[EvaContactListView] no friend in the friend list" << endl;
			return;
		}
		m_contacts[f->getQQ()] = new EvaBuddyItem(*f, m_groups[f->getGroupIndex()]);
	}

	m_contacts[id]->newMessage();

	EvaBuddyItem * i = m_contacts[id];
	int group = i->getFriend().getGroupIndex();
	m_groups[group]->update();
	
}

void EvaContactListView::getMessage(const unsigned int id)
{
	 m_contacts[id]->takeMessage();

	EvaBuddyItem * i = m_contacts[id];
	int group = i->getFriend().getGroupIndex();
	m_groups[group]->update();
}

void EvaContactListView::deleteBuddy( const unsigned int id)
{
	std::map<unsigned int, EvaBuddyItem *>::iterator it = m_contacts.find(id);
	if(it == m_contacts.end()) return;

	EvaBuddyItem *item = m_contacts[id];
	int group = item->getFriend().getGroupIndex();
	m_contacts.erase(it);
	delete item;
	m_groups[group]->update();
}

void EvaContactListView::initPopup( )
{
	EvaImageResource *img = EvaMain::images;
	m_groupMenu = new TQPopupMenu();
	m_groupMenu->insertItem(TQIconSet(*(img->getIcon("RENAME"))), i18n("Rename"), this, SLOT(slotRenameGroup()), -1, 0);
	m_groupMenu->insertItem(TQIconSet(*(img->getIcon("ADD_GROUP"))), i18n( "New Group"), this, SLOT(slotNewGroup()), -1, 1);
	m_groupMenu->insertItem(TQIconSet(*(img->getIcon("DEL_GROUP"))), i18n( "Delele Group"), this, SLOT(slotDelGroup()), -1, 2);	
	m_groupMenu->insertSeparator(-1);
	//m_groupMenu->insertItem(TQIconSet(*qun), i18n( "Create Qun"), this, SLOT(slotQunCreate()), -1);
	//m_groupMenu->insertSeparator(-1);
	m_groupMenu->insertItem(TQIconSet(*(img->getIcon("SHOW_ONLINE_BUDDIES"))), i18n( "Show Online"), this, 
				SLOT(showOnlineOnly()), -1);
	m_groupMenu->insertItem(TQIconSet(*(img->getIcon("SHOW_ALL_BUDDIES"))), i18n( "Show All"), this, SLOT(showAll()), -1);

	m_buddyMenu = new TQPopupMenu();
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("CHAT"))), i18n( "Chat"), this, SLOT(slotIMChat()), -1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("FILE_TRANSFER"))), i18n( "Send File"), this, SLOT(slotSendFile()), -1);
	m_buddyMenu->insertSeparator(-1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("TIME_SUN"))), i18n( "Update Level"), this, SLOT(slotUpdataLevel()), -1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("DETAILS"))), i18n( "Details"), this, SLOT(slotDetails()), -1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("MEMO"))), i18n("Modify Memo"), this, SLOT(slotModifyMemo()),-1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("HISTORY"))), i18n( "History"), this, SLOT(slotHistory()), -1);
	m_buddyMenu->insertSeparator(-1);
	
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("DEL_BUDDY"))), i18n( "Delete Buddy"), this, SLOT(slotDelBuddy()), -1);
}

void EvaContactListView::slotRenameGroup( )
{
	EvaGroupItem *g = dynamic_cast<EvaGroupItem *>(selectedItem());
	if(!g) return;
	if(g->groupIndex() == 0) return;   // first group cannot be renamed
	g->setGroupName(g->groupName());  // this is to elimate the online number statistics
	g->setRenameEnabled(0, true);
	g->startRename(0);
}

void EvaContactListView::slotNewGroup( )
{
	TQString name(i18n( "new group"));
	std::string gname = std::string(codec->fromUnicode(name));
	EvaMain::user->newGroup( gname );
	
	int index = EvaMain::user->getGroupIndexOf( gname ); // minus Black list & Anonymous
	EvaGroupItem *g = new EvaGroupItem(index, this);
	m_groups[index]  = g;
	EvaMain::user->saveGroupedBuddyList();
	//emit groupAdded(name, index);
	
	clearSelection();
	g->setSelected(true);
	g->setRenameEnabled(0, true);
	g->startRename(0);
}

void EvaContactListView::slotDelGroup( )
{
	EvaGroupItem *g = dynamic_cast<EvaGroupItem *>(selectedItem());
	if(!g) return;
	if(g->groupIndex() == 0) return;   // first group cannot be deleted
	if(g->childCount()){
		TQMessageBox::information( this, i18n( "Delete group"),
			i18n( "Only empty group can be deleted.\n\n"));
		return;
	}
	int index = g->groupIndex();

	EvaMain::user->removeGroupName(index);

	takeItem(g);

	std::map<int, EvaGroupItem *>::iterator it = m_groups.find(index);
	if(it == m_groups.end()) return;
	m_groups.erase(it);

	delete g;
	emit groupDeleted(index);
}

void EvaContactListView::slotIMChat( )
{
	EvaBuddyItem *b = dynamic_cast<EvaBuddyItem *>(selectedItem());
	if(!b) return;
	emit requestChat(b->QQ());
}

void EvaContactListView::slotSendFile( )
{
	EvaBuddyItem *b = dynamic_cast<EvaBuddyItem *>(selectedItem());
	if(!b) return;
	emit requestSendFile(b->QQ());
}

void EvaContactListView::slotUpdataLevel( )
{
	EvaBuddyItem *b = dynamic_cast<EvaBuddyItem *>(selectedItem());
	if(!b) return;
	emit requestLevel(b->QQ());
}

void EvaContactListView::slotDetails( )
{
	EvaBuddyItem *b = static_cast<EvaBuddyItem *>(selectedItem());
	if(!b) return;
	emit requestDetails(b->QQ());
}

void EvaContactListView::slotHistory( )
{
	EvaBuddyItem *b = dynamic_cast<EvaBuddyItem *>(selectedItem());
	if(!b) return;
	emit requestHistory(b->QQ());
}

void EvaContactListView::slotDelBuddy( )
{
	EvaBuddyItem *b = dynamic_cast<EvaBuddyItem *>(selectedItem());
	if(!b) return;
	TQString info = TQString(i18n("Delete friend \"%1\" from your list, are you sure?\n\n")).arg(b->text(0));
	
	if(KMessageBox::Cancel == KMessageBox::warningContinueCancel( this,
			info, i18n( "Delete a friend" ), i18n( "Deleting" ) ))
		return;
	emit requestDelete(b->QQ());
}

void EvaContactListView::slotModifyMemo( )
{
	EvaBuddyItem *b = static_cast<EvaBuddyItem *>(selectedItem());
	if(!b) return;
	emit requestModifyMemo(b->QQ());
}

void EvaContactListView::slotBuddyDoubleClick( TQListViewItem *item, const TQPoint &, int )
{
	EvaBuddyItem *b = dynamic_cast<EvaBuddyItem *>(item);
	if(b){
		EvaGroupItem *group = dynamic_cast<EvaGroupItem *>(((TQListViewItem*)b)->parent());
		if(!group) return;
		b->takeMessage();
		group->update();
		emit requestChat(b->QQ());
	}
}

void EvaContactListView::slotListViewClicked( TQListViewItem * item)
{
	EvaGroupItem *g = dynamic_cast<EvaGroupItem *>(item);
	if(g && g->childCount() ){
		g->setOpen(! g->isOpen());
	}
}

void EvaContactListView::slotContextMenu( TQListViewItem *item, const TQPoint &p, int col)
{
	if(col!=0) return;
	EvaGroupItem *g = dynamic_cast<EvaGroupItem *>(item);
	EvaBuddyItem *b = dynamic_cast<EvaBuddyItem *>(item);
	
	if ( item && !item->isSelected() ){
		clearSelection();
		item->setSelected( true );
	}
	
	if ( !item )
		clearSelection();
	if(g && m_groupMenu){
		if(g->groupIndex() == 0 || g->groupIndex() > numOfGroups() ){
			m_groupMenu->setItemEnabled(0, false);
			m_groupMenu->setItemEnabled(2, false);
		}else{
			m_groupMenu->setItemEnabled(0, true);
			m_groupMenu->setItemEnabled(2, true);
		}
		m_groupMenu->popup(p);
	}else if(b && m_buddyMenu ){
		m_buddyMenu->popup(p);
	}
}

void EvaContactListView::slotItemRenamed( TQListViewItem * item, int )
{
	EvaGroupItem *g = dynamic_cast<EvaGroupItem *>(item);
	if(!g) return;
	g->setGroupName( g->text(0));
	emit groupRenamed(g->text(0), g->groupIndex());
}

void EvaContactListView::buddyAdded( const unsigned int id )
{
	/// load all contacts
	
	std::map<unsigned int, TQQFriend> list = EvaMain::user->getFriendList().getAllFriendsMap();

	if (m_groups.size() == 0)
		return;

	printf("add friend: %d\n", id);
	if( list.count(id) ){

		TQQFriend f = list[id];
		printf("add friend: %d\n", f.getQQ());
		m_contacts[f.getQQ()] = new EvaBuddyItem(f, m_groups[f.getGroupIndex()]);
		m_groups[f.getGroupIndex()]->update();
		if(EvaMain::user->getSetting()->isShowOnlineEnabled())
			showOnlineOnly();
		else
			showAll();
	}
}


/// * ================================================ */


EvaQunListViewItem::EvaQunListViewItem( Qun * q, TQListView * parent )
    : EvaListViewItem(parent),
	m_qun(q),
	m_numOfMessages(0)
{
	m_type = E_LVIQun;
	updateIcon( EvaMain::images->getIcon("TQUN"));
	update();
}

const TQString EvaQunListViewItem::name( )
{
	return codec->toUnicode(m_qun->getDetails().getName().c_str());
}


void EvaQunListViewItem::newMessage( )
{
	m_numOfMessages++;
	update();
}

void EvaQunListViewItem::getMessage( )
{
	m_numOfMessages = 0;
	update();
}

void EvaQunListViewItem::update( )
{
	EvaUserSetting * setting = EvaMain::user->getSetting();
	TQString fontedName = name();
	TQColor showColor = TQt::black;
	if(m_numOfMessages){
		if(setting->isQunFlashBold())
			fontedName = ("<b>" + fontedName + "</b>");
		if(setting->isQunFlashUnderline())
			fontedName = ("<u>" + fontedName + "</u>");
		if(setting->isQunFlashItalic())
			fontedName = ("<i>" + fontedName + "</i>");
		showColor = setting->getQunFlashColor();
	} else {
		if(setting->isQunNameBold())
			fontedName = ("<b>" + fontedName + "</b>");
		if(setting->isQunNameUnderline())
			fontedName = ("<u>" + fontedName + "</u>");
		if(setting->isQunNameItalic())
			fontedName = ("<i>" + fontedName + "</i>");
		showColor = setting->getQunNameColor();
	}
	
	TQString showName = "<font color=\"" + showColor.name() + "\">&nbsp;" + fontedName + "</font>";

	if(m_numOfMessages)
		showName += ("&nbsp;&nbsp;("+TQString::number(m_numOfMessages) +")");
	setText("<nobr>" + showName + "</nobr>" );
	if(listView() && isVisible())
		listView()->repaintItem(this);
	//widthChanged( 0 );
}


TQString EvaQunListViewItem::tip( )
{
	TQString decription = "";
	if(m_qun && m_qun->getDetails().getQunID() ){
		decription = codec->toUnicode(m_qun->getDetails().getDescription().c_str());
	}else
		printf("--------------------------No Qun description\n");
	TQString tip = "<table><tr><td align = left valign = middle><font color = blue><b>"+
			i18n("Qun name") + ": </b></font>"+ name() +"<br><b><font color = blue>"+ 
			i18n("Qun Number") + ": </b></font>"+ TQString::number(m_qun->getDetails().getExtID()) +"<br><br><b><font color = blue>" + 
			i18n("Qun Description") +": </font></b><br>  "+ decription + "</td></tr></table>";
	return tip;
}


const unsigned int EvaQunListViewItem::getQunID( ) const
{
	return m_qun->getQunID();
}

/// * ================================================ */


EvaQunsListView::EvaQunsListView( TQWidget * parent, const char * name, WFlags f )
	: EvaListView(parent, name, f)
{
	setPaletteBackgroundPixmap(*EvaMain::images->getIcon("BACK_GROUND"));
	setStaticBackground(true);

	initPopup();


// 	TQObject::connect(this, SIGNAL(itemRenamed(TQListViewItem *, int)),
// 					SLOT((TQListViewItem *, int)));
	TQObject::connect(this, SIGNAL(contextMenuRequested(TQListViewItem *, const TQPoint & , int)),
					SLOT(slotContextMenu(TQListViewItem *, const TQPoint & , int)));
	TQObject::connect(this, SIGNAL(doubleClicked(TQListViewItem *, const TQPoint & , int)),
					SLOT(slotQunDoubleClick(TQListViewItem *, const TQPoint & , int)));
// 	TQObject::connect(this, SIGNAL(clicked(TQListViewItem *)),
// 					SLOT(slotListViewClicked(TQListViewItem *)));
}

void EvaQunsListView::initPopup( )
{
	EvaImageResource *img = EvaMain::images;
	m_popup =  new TQPopupMenu();
	m_popup->insertItem(TQIconSet(*(img->getIcon("CHAT"))), i18n( "Chat"), this, SLOT(slotIMQunChat()), -1);
	m_popup->insertSeparator(-1);
	m_popup->insertItem(TQIconSet(*(img->getIcon("DETAILS"))), i18n( "Details"), this, SLOT(slotQunDetails()), -1);
	m_popup->insertItem(TQIconSet(*(img->getIcon("HISTORY"))), i18n( "History"), this, SLOT(slotQunHistory()), -1);
	m_popup->insertSeparator(-1);
	m_popup->insertItem(TQIconSet(*(img->getIcon("TQUN"))), i18n( "Create Qun"), this, SIGNAL(requestQunCreate()), -1);
	m_popup->insertItem(TQIconSet(*(img->getIcon("TQUN_EXIT"))), i18n( "Exit Qun" ), this, SLOT(slotQunExit()), -1);
}

void EvaQunsListView::slotIMQunChat( )
{
	EvaQunListViewItem *q = dynamic_cast<EvaQunListViewItem *>(selectedItem());
	if(!q) return;
	emit requestQunChat(q->getQunID());
}

void EvaQunsListView::slotQunDetails( )
{
	EvaQunListViewItem *q = dynamic_cast<EvaQunListViewItem *>(selectedItem());
	if(!q) return;
	emit requestQunDetails(q->getQunID());
}

void EvaQunsListView::slotQunHistory( )
{
	EvaQunListViewItem *q = dynamic_cast<EvaQunListViewItem *>(selectedItem());
	if(!q) return;
	emit requestQunHistory(q->getQunID());
}

void EvaQunsListView::slotQunExit( )
{
	EvaQunListViewItem *q = dynamic_cast<EvaQunListViewItem *>(selectedItem());
	if(!q) return;
	emit requestQunExit(q->getQunID());
}

void EvaQunsListView::slotContextMenu( TQListViewItem *item, const TQPoint &p, int col)
{
	if(col!=0) return;
	EvaQunListViewItem *q = dynamic_cast<EvaQunListViewItem *>(item);
	
	if ( item && !item->isSelected() ){
		clearSelection();
		item->setSelected( true );
	}
	
	if ( !item )
		clearSelection();
	if(q && m_popup){
		m_popup->popup(p);
	}
}

void EvaQunsListView::slotQunDoubleClick( TQListViewItem *item, const TQPoint &, int )
{
	EvaQunListViewItem *q = dynamic_cast<EvaQunListViewItem *>(item);
	if(q){
		q->getMessage();
		q->update();
		emit requestQunChat(q->getQunID());
	}
}

void EvaQunsListView::loadAllQuns( )
{	
	TQListView::clear();

	EvaUser *user = EvaMain::user;
	if(!user) return;

	QunList *list = user->getQunList();
	
	Qun *q = list->first();
	while(q){
		new EvaQunListViewItem(q, this);
		q = list->next();
	}
}

void EvaQunsListView::newMessage( const unsigned int id )
{
	EvaQunListViewItem *item = dynamic_cast<EvaQunListViewItem *>(firstChild());
	while(item){
		if(item->getQunID() == id ){
			item->newMessage();
			return;
		}
		item = dynamic_cast<EvaQunListViewItem *>(item->nextSibling());
	}
}

void EvaQunsListView::getMessage( const unsigned int id )
{
	EvaQunListViewItem *item = dynamic_cast<EvaQunListViewItem *>(firstChild());
	while(item){
		if(item->getQunID() == id ){
			item->getMessage();
			return;
		}
		item = dynamic_cast<EvaQunListViewItem *>(item->nextSibling());
	}
}

void EvaQunsListView::updateQun( const unsigned int id )
{
	EvaQunListViewItem *item = dynamic_cast<EvaQunListViewItem *>(firstChild());
	while(item){
		if(item->getQunID() == id ){
			item->update();
			return;
		}
		item = dynamic_cast<EvaQunListViewItem *>(item->nextSibling());
	}
}

void EvaQunsListView::addQun( const unsigned int id )
{
	QunList *list = EvaMain::user->getQunList();
	
	Qun *q = list->getQun( id);
	if(!q) return;

	EvaQunListViewItem *item = dynamic_cast<EvaQunListViewItem *>(firstChild());
	while(item){
		if(item->getQunID() == id ){
			item->update();
			return;
		}
		item = dynamic_cast<EvaQunListViewItem *>(item->nextSibling());
	}
	new EvaQunListViewItem(q, this);
}




/// * ================================================ */



EvaRecentContactLVItem::EvaRecentContactLVItem( const bool isQun, TQQFriend * f, Qun * q, TQListView * parent )
	: EvaListViewItem(parent),
	m_qun(q),
	m_buddy(f),
	m_numOfMessages(0),
	m_time(0)
{
	if(isQun){
		m_type = E_LVIQun;
		updateIcon( EvaMain::images->getIcon("TQUNS"));
	} else {
		m_type = E_LVIBuddy;
	}

	update();
}

const unsigned int EvaRecentContactLVItem::QQ( )
{
	if(isQun()) return 0;

	return m_buddy->getQQ();
}

void EvaRecentContactLVItem::newMessage( const unsigned int t, bool isInChat)
{
	m_time = t;
	if(!isInChat)
		++m_numOfMessages;
	update();
}

void EvaRecentContactLVItem::getMessage( )
{
	m_numOfMessages = 0;
	update();
}

const TQString EvaRecentContactLVItem::QunName( )
{
	if(!isQun()) return "";
	return codec->toUnicode(m_qun->getDetails().getName().c_str());
}

const unsigned int EvaRecentContactLVItem::getQunID( ) const
{
	if(!isQun()) return 0;
	return m_qun->getQunID();
}

void EvaRecentContactLVItem::update( )
{
	if(isQun())
		qunUpdate();
	else
		buddyUpdate();
}

void EvaRecentContactLVItem::buddyUpdate( )
{
    if(!m_buddy){
        kdDebug() << "[EvaRecentContactLVItem] no buddy details available" << endl;
        return;
    }

    EvaImageResource *images = EvaMain::images;

    TQString nick = EvaTextFilter::filter(codec->toUnicode(m_buddy->getMemo().name.c_str()));
    if(nick.isEmpty())
        nick = EvaTextFilter::filter(codec->toUnicode(m_buddy->getNick().c_str()));
    TQString signature = EvaTextFilter::filter(codec->toUnicode(m_buddy->getSignature().c_str()));

    TQPixmap *pixmap = images->getFaceByID(m_buddy->getFace(), false);
    switch(m_buddy->getStatus()){
    case TQQ_FRIEND_STATUS_ONLINE:
    case TQQ_FRIEND_STATUS_LEAVE:
            if(m_buddy->hasUserHead()){
                pixmap = images->getUserHeadPixmap(m_buddy->getQQ());
            }else
                pixmap =  images->getFaceByID(m_buddy->getFace(), true);
            break;
    case TQQ_FRIEND_STATUS_OFFLINE:
    case TQQ_FRIEND_STATUS_INVISIBLE:
            if(m_buddy->hasUserHead()){
                pixmap = images->getUserHeadPixmap(m_buddy->getQQ(), true);
            }
            break;
		}
		
		if(!pixmap || pixmap->isNull())
			pixmap = images->getFaceByID(0);
		
    if(m_buddy->getStatus() == TQQ_FRIEND_STATUS_LEAVE){
			TQPixmap *na = images->getIcon("NA");
			copyBlt(pixmap, pixmap->width() - na->width(), pixmap->height()- na->height(), 
							na, 0, 0, na->width(), na->height());
    }

//    TQPixmap head = pixmap->convertToImage().smoothScale(EvaMain::global->getFaceSize());
//		updateIcon(&head);
    updateIcon(pixmap);


    EvaUserSetting * setting = EvaMain::user->getSetting();
    TQString htmlName = nick;
    if(setting->isShowSmileyInNickName()){
            EvaHtmlParser parser;
            parser.setAbsImagePath(EvaMain::images->getSmileyPath());
            parser.convertToHtml(htmlName, false, true);
    }
    TQColor showColor = TQt::black;
    if(m_numOfMessages){
            if(setting->isBuddyFlashBold())
                    htmlName = ("<b>" + htmlName + "</b>");
            if(setting->isBuddyFlashUnderline())
                    htmlName = ("<u>" + htmlName + "</u>");
            if(setting->isBuddyFlashItalic())
                    htmlName = ("<i>" + htmlName + "</i>");
            showColor = setting->getBuddyFlashColor();
    } else {
            if(setting->isBuddyNameBold())
                    htmlName = ("<b>" + htmlName + "</b>");
            if(setting->isBuddyNameUnderline())
                    htmlName = ("<u>" + htmlName + "</u>");
            if(setting->isBuddyNameItalic())
                    htmlName = ("<i>" + htmlName + "</i>");
            showColor = setting->getBuddyNameColor();
    }
    //printf("html name: %s\n", htmlName.ascii());
    TQString showName = "<nobr><font color=\"" + showColor.name() + "\">&nbsp;" + htmlName + "</font></nobr>";

    TQString showSig = signature;
    if( !signature.isEmpty() ){
            if(setting->isShowSignatureInSeperateLine())
                    showName += "<br>";
            if(setting->isBuddySigBold())
                    showSig = ("<b>" + showSig + "</b>");
            if(setting->isBuddySigUnderline())
                    showSig = ("<u>" + showSig + "</u>");
            if(setting->isBuddySigItalic())
                    showSig = ("<i>" + showSig + "</i>");
            showName += ("<nobr><font color=\"" + setting->getBuddySigColor().name() + "\">&nbsp;(" + showSig + ")</font></nobr>");
    } else {
            if(setting->isShowSignatureInSeperateLine())  // just to make sure each item has the same height
                    showName += "<br>&nbsp;";
    }
    setText(showName);

    if(isVisible())
            listView()->repaintItem(this);
}

void EvaRecentContactLVItem::qunUpdate( )
{
	if(m_icon && m_icon->size() != EvaMain::global->getFaceSize()){
		TQPixmap *pixmap = EvaMain::images->getIcon("TQUNS");
		if(pixmap){
  //		TQPixmap head = pixmap->convertToImage().smoothScale(EvaMain::global->getFaceSize());
//			updateIcon(&head);
			updateIcon(pixmap);
		}
	}
	
	EvaUserSetting * setting = EvaMain::user->getSetting();
	TQString fontedName = QunName();
	TQColor showColor = TQt::black;
	if(m_numOfMessages){
		if(setting->isQunFlashBold())
			fontedName = ("<b>" + fontedName + "</b>");
		if(setting->isQunFlashUnderline())
			fontedName = ("<u>" + fontedName + "</u>");
		if(setting->isQunFlashItalic())
			fontedName = ("<i>" + fontedName + "</i>");
		showColor = setting->getQunFlashColor();
	} else {
		if(setting->isQunNameBold())
			fontedName = ("<b>" + fontedName + "</b>");
		if(setting->isQunNameUnderline())
			fontedName = ("<u>" + fontedName + "</u>");
		if(setting->isQunNameItalic())
			fontedName = ("<i>" + fontedName + "</i>");
		showColor = setting->getQunNameColor();
	}
	
	TQString showName = "<font color=\"" + showColor.name() + "\">&nbsp;" + fontedName + "</font>";
	
	if(m_numOfMessages)
		showName += ("&nbsp;&nbsp;("+TQString::number(m_numOfMessages) +")");

	showName = "<nobr>" + showName + "</nobr>";
	//just to make sure Qun item got the same height as Buddy item
	if(setting->isShowSignatureInSeperateLine())
		showName += "<br>&nbsp;";

	setText(showName);

	if(listView() && isVisible())
		listView()->repaintItem(this);
	//widthChanged( 0 );
}

TQString EvaRecentContactLVItem::tip( )
{
	if(isQun())
		return qunTip();
	else
		return buddyTip();
}

TQString EvaRecentContactLVItem::buddyTip( )
{
	TQString tip = "<qt>";
	if(m_buddy){
		EvaIPSeeker ipAddr(EvaGlobal::getDirPath().latin1());
		TQTextCodec *codec = TQTextCodec::codecForName("GB18030");
		TQString addr = codec->toUnicode(ipAddr.getIPLocation(m_buddy->getIP()).c_str());
		if(addr.length()<4) addr = "0.0.0.0";
		
		TQString htmlName = EvaTextFilter::filter(codec->toUnicode(m_buddy->getNick().c_str()));
		EvaHtmlParser parser;
		parser.setAbsImagePath(EvaMain::images->getSmileyPath());
		parser.convertToHtml(htmlName, false, true);
		TQString signature = codec->toUnicode(m_buddy->getSignature().c_str());
		if(signature.length() > 40)
			signature = signature.left(37) + "...";
//		if(!signature.isEmpty())
//			signature = "[" + signature + "]";
		TQString facePath = "<img src=\"" + EvaMain::images->getFacePath() + "/" +
				TQString::number(EvaMain::images->getFaceFileIndex(m_buddy->getFace())) + 
				".png\"></img>";
		if(m_buddy->hasUserHead() && EvaMain::uhManager){
			TQString uhFileName = EvaMain::uhManager->getFileName(m_buddy->getQQ());
			if(!uhFileName.isEmpty())
				facePath = "<img src=\"" + uhFileName + "\"></img>";
		}
		TQString level = "";
		if ( m_buddy->getLevel() != 0)
		{
			int suns, moons, stars;
			EvaUtil::calcSuns(m_buddy->getLevel(), &suns, &moons, &stars);
			TQString strSun =  "<img src=\"" + EvaMain::images->getIconFullPath("TIME_SUN") + "\"></img>";
			TQString strMoon = "<img src=\"" + EvaMain::images->getIconFullPath("TIME_MOON") + "\"></img>";
			TQString strStar = "<img src=\"" + EvaMain::images->getIconFullPath("TIME_STAR") + "\"></img>";
			for(int i=0; i<suns; i++){
				level += strSun;
			}
			for(int i=0; i<moons; i++){
				level += strMoon;
			}
			for(int i=0; i<stars; i++){
				level += strStar;
			}

			level += "(" + TQString::number(m_buddy->getLevel()) +")";
		}
		
		
		tip += "<table width = 250><tr><td width=50 align = left valign = top>" + facePath + 
			"</td><td align = left valign = middle><b><font color = blue>" + htmlName + " (" +  
		TQString::number(m_buddy->getQQ()) + ") </font></b>" +
			"</nobr><br>"+ signature + "<br>" + 
			level + "</td></tr></table>";

	} else
		tip += "<b><font color = blue>" + EvaTextFilter::filter(codec->toUnicode(m_buddy->getNick().c_str())) + 
			" ("+ TQString::number(m_buddy->getQQ()) +
			") </font></b>";
/*
		int suns, moons, stars;
		EvaUtil::calcSuns(m_buddy->getLevel(), &suns, &moons, &stars);
		TQString strSun =  "<img src=\"" + EvaMain::images->getIconFullPath("TIME_SUN") + "\"></img>";
		TQString strMoon = "<img src=\"" + EvaMain::images->getIconFullPath("TIME_MOON") + "\"></img>";
		TQString strStar = "<img src=\"" + EvaMain::images->getIconFullPath("TIME_STAR") + "\"></img>";
		TQString level;
		for(int i=0; i<suns; i++){
			level += strSun;
		}
		for(int i=0; i<moons; i++){
			level += strMoon;
		}
		for(int i=0; i<stars; i++){
			level += strStar;
		}
		
		tip += "<table width = 200><tr><td width=50 align = center valign = middle>" + facePath + 
			"</td><td align = left valign = middle><b><font color = blue>"+
			i18n("QQ") +": </font></b>"+ TQString::number(m_buddy->getQQ()) +"<br><nobr><b><font color = blue>"+
			i18n("Nickname:") + " </font></b>"+htmlName +"</nobr><br>"+ signature + "<br><b><font color = blue>"+ 
			i18n("Level") +": </font></b>"+ level + "  (" + TQString::number(m_buddy->getLevel()) +")<br><b><font color = blue>"+
			i18n("IP:") +" </font></b>"+ addr + "</td></tr></table>";
	} else
		tip += "<b><font color = blue>" + 
			i18n("QQ") +": </font></b><br>"+ TQString::number(m_buddy->getQQ()) +
			i18n("Nickname:") +" </font></b>"+ EvaTextFilter::filter(codec->toUnicode(m_buddy->getNick().c_str())) +"<br><b><font color = blue>"; */
	tip += "</qt>";
	return tip;
}

TQString EvaRecentContactLVItem::qunTip( )
{
	TQString decription = "";
	if(m_qun && m_qun->getDetails().getQunID() ){
		decription = codec->toUnicode(m_qun->getDetails().getDescription().c_str());
	}
	TQString tip = "<table><tr><td align = left valign = middle><font color = blue><b>"+
			i18n("Qun name") + ": </b></font>"+ QunName() +"<br><b><font color = blue>"+ 
			i18n("Qun Number") + ": </b></font>"+ TQString::number(m_qun->getDetails().getExtID()) +"<br><br><b><font color = blue>" + 
			i18n("Qun Description") +": </font></b><br>  "+ decription + "</td></tr></table>";
	return tip;
}

TQString EvaRecentContactLVItem::key( int /*col*/, bool /*ascending*/ ) const
{
	return TQString("%1").arg(m_time, 8, 16);
}





/// * ================================================ */




EvaRecentContactsListView::EvaRecentContactsListView( TQWidget * parent, const char * name, WFlags f )
	: EvaListView(parent, name, f)
{
	setPaletteBackgroundPixmap(*EvaMain::images->getIcon("BACK_GROUND"));
	setStaticBackground(true);
	setSorting(0, false);

	initBuddyPopup();
	initQunPopup();


	TQObject::connect(this, SIGNAL(contextMenuRequested(TQListViewItem *, const TQPoint & , int)),
					SLOT(slotContextMenu(TQListViewItem *, const TQPoint & , int)));
	TQObject::connect(this, SIGNAL(doubleClicked(TQListViewItem *, const TQPoint & , int)),
					SLOT(slotContactDoubleClick(TQListViewItem *, const TQPoint & , int)));
}

void EvaRecentContactsListView::initBuddyPopup( )
{
	EvaImageResource *img = EvaMain::images;
	m_buddyMenu = new TQPopupMenu();
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("CHAT"))), i18n( "Chat"), this, SLOT(slotIMChat()), -1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("FILE_TRANSFER"))), i18n( "Send File"), this, SLOT(slotSendFile()), -1);
	m_buddyMenu->insertSeparator(-1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("TIME_SUN"))), i18n( "Update Level"), this, SLOT(slotUpdataLevel()), -1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("DETAILS"))), i18n( "Details"), this, SLOT(slotDetails()), -1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("MEMO"))), i18n("Modify Memo"), this, SLOT(slotModifyMemo()),-1);
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("HISTORY"))), i18n( "History"), this, SLOT(slotHistory()), -1);
	m_buddyMenu->insertSeparator(-1);
	
	m_buddyMenu->insertItem(TQIconSet(*(img->getIcon("DEL_BUDDY"))), i18n( "Delete Buddy"), this, SLOT(slotDelBuddy()), -1);
}

void EvaRecentContactsListView::initQunPopup( )
{
	EvaImageResource *img = EvaMain::images;
	m_qunMenu =  new TQPopupMenu();
	m_qunMenu->insertItem(TQIconSet(*(img->getIcon("CHAT"))), i18n( "Chat"), this, SLOT(slotIMQunChat()), -1);
	m_qunMenu->insertSeparator(-1);
	m_qunMenu->insertItem(TQIconSet(*(img->getIcon("DETAILS"))), i18n( "Details"), this, SLOT(slotQunDetails()), -1);
	m_qunMenu->insertItem(TQIconSet(*(img->getIcon("HISTORY"))), i18n( "History"), this, SLOT(slotQunHistory()), -1);
	m_qunMenu->insertSeparator(-1);
	m_qunMenu->insertItem(TQIconSet(*(img->getIcon("TQUN"))), i18n( "Create Qun"), this, SIGNAL(requestQunCreate()), -1);
	m_qunMenu->insertItem(TQIconSet(*(img->getIcon("TQUN_EXIT"))), i18n( "Exit Qun" ), this, SLOT(slotQunExit()), -1);
}

void EvaRecentContactsListView::slotContextMenu( TQListViewItem *item, const TQPoint  &p, int col)
{
	if(col!=0) return;
	EvaRecentContactLVItem *q = dynamic_cast<EvaRecentContactLVItem *>(item);
	
	if ( item && !item->isSelected() ){
		clearSelection();
		item->setSelected( true );
	}
	
	if ( !item )
		clearSelection();
	if(q ){
		if(q->isQun() && m_qunMenu){
			m_qunMenu->popup(p);
		} else if( !q->isQun() && m_buddyMenu)
				m_buddyMenu->popup(p);
	}
}

void EvaRecentContactsListView::slotContactDoubleClick( TQListViewItem *item, const TQPoint &, int )
{
	EvaRecentContactLVItem *b = dynamic_cast<EvaRecentContactLVItem *>(item);
	if(b){
		b->getMessage();
		b->update();
		if(b->isQun())
			emit requestQunChat(b->getQunID());
		else
			emit requestChat(b->QQ());
	}
}


void EvaRecentContactsListView::slotIMChat( )
{
	EvaRecentContactLVItem *b = dynamic_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!b) return;
	emit requestChat(b->QQ());
}

void EvaRecentContactsListView::slotSendFile( )
{
	EvaRecentContactLVItem *b = dynamic_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!b) return;
	emit requestSendFile(b->QQ());
}

void EvaRecentContactsListView::slotUpdataLevel( )
{
	EvaRecentContactLVItem *b = dynamic_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!b) return;
	emit requestLevel(b->QQ());
}

void EvaRecentContactsListView::slotDetails( )
{
	EvaRecentContactLVItem *b = static_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!b) return;
	emit requestDetails(b->QQ());
}

void EvaRecentContactsListView::slotHistory( )
{
	EvaRecentContactLVItem *b = dynamic_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!b) return;
	emit requestHistory(b->QQ());
}

void EvaRecentContactsListView::slotDelBuddy( )
{
	EvaRecentContactLVItem *b = dynamic_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!b) return;
	TQString info = TQString(i18n("Delete friend \"%1\" from your list, are you sure?\n\n")).arg(b->text(0));
	
	if(KMessageBox::Cancel == KMessageBox::warningContinueCancel( this,
			info, i18n( "Delete a friend" ), i18n( "Deleting" ) ))
		return;
	emit requestDelete(b->QQ());
}

void EvaRecentContactsListView::slotModifyMemo( )
{
	EvaRecentContactLVItem *b = static_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!b) return;
	emit requestModifyMemo(b->QQ());
}


void EvaRecentContactsListView::slotIMQunChat( )
{
	EvaRecentContactLVItem *q = dynamic_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!q) return;
	emit requestQunChat(q->getQunID());
}

void EvaRecentContactsListView::slotQunDetails( )
{
	EvaRecentContactLVItem *q = dynamic_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!q) return;
	emit requestQunDetails(q->getQunID());
}

void EvaRecentContactsListView::slotQunHistory( )
{
	EvaRecentContactLVItem *q = dynamic_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!q) return;
	emit requestQunHistory(q->getQunID());
}

void EvaRecentContactsListView::slotQunExit( )
{
	EvaRecentContactLVItem *q = dynamic_cast<EvaRecentContactLVItem *>(selectedItem());
	if(!q) return;
	emit requestQunExit(q->getQunID());
}

void EvaRecentContactsListView::loadRecentContacts( )
{
	TQListView::clear();

	EvaUser *user = EvaMain::user;
	if(!user) return;

	EvaUserSetting * setting = user->getSetting();
	std::list<RecentContact> list = setting->getRecentContacts();
	std::list<RecentContact>::iterator it;
	for(it = list.begin(); it != list.end(); ++it){
		RecentContact c = *it;
		Qun *q = 0;
		TQQFriend *f = 0;
		if(c.isQun){
			q = user->getQunList()->getQun( c.id );
			if(!q) continue;
		} else {
			f = user->getFriends()->getFriend( c.id);
			if(!f) continue;
	
		}
		EvaRecentContactLVItem *g = new EvaRecentContactLVItem(c.isQun, f, q, this);
		g->setTime(c.time);
	}
	sort();
}

void EvaRecentContactsListView::updateConfig( )
{
	// update config file
	std::list<RecentContact> list;
	EvaRecentContactLVItem *item = dynamic_cast<EvaRecentContactLVItem *>(firstChild());
	while(item){
		RecentContact c;
		c.isQun = item->isQun();
		c.id = (item->isQun())?(item->getQunID()):(item->QQ());
		c.time = item->getTime();
		list.push_back(c);
		item = dynamic_cast<EvaRecentContactLVItem *>(item->nextSibling());
	}
	EvaMain::user->getSetting()->updateRecentContact(list);
}

void EvaRecentContactsListView::newMessage( const unsigned int id, bool isInChat, const unsigned int time)
{
	EvaRecentContactLVItem *item = addBuddy(id, time);
	if(item)
		item->newMessage( time, isInChat);
}

void EvaRecentContactsListView::getMessage( const unsigned int id )
{
	EvaRecentContactLVItem *item = dynamic_cast<EvaRecentContactLVItem *>(firstChild());
	while(item){
		if( !item->isQun() && (item->QQ() == id) ){
			item->getMessage();
			return;
		}
		item = dynamic_cast<EvaRecentContactLVItem *>(item->nextSibling());
	}
}

void EvaRecentContactsListView::newQunMessage( const unsigned int id, bool isInChat, const unsigned int time )
{
	EvaRecentContactLVItem *item = addQun(id, time);
	if(item)
		item->newMessage( time, isInChat);
}

void EvaRecentContactsListView::getQunMessage( const unsigned int id )
{
	EvaRecentContactLVItem *item = dynamic_cast<EvaRecentContactLVItem *>(firstChild());
	while(item){
		if(  item->isQun() && (item->getQunID() == id) ){
			item->getMessage();
			return;
		}
		item = dynamic_cast<EvaRecentContactLVItem *>(item->nextSibling());
	}
}

EvaRecentContactLVItem * EvaRecentContactsListView::addBuddy( const unsigned int id, const unsigned int time )
{
	EvaRecentContactLVItem *item = dynamic_cast<EvaRecentContactLVItem *>(firstChild());
	EvaRecentContactLVItem *oldest = item;
	while(item){
		if( !item->isQun() && (item->QQ() == id) ){
			// we have it in the list, update the time
			item->setTime( time);
			sort();
			updateConfig();
			return item;
		}
		if(oldest->getTime() > item->getTime()){
			// the less the older one
			oldest = item;
		}
		item = dynamic_cast<EvaRecentContactLVItem *>(item->nextSibling());
	}

	// so should be someone who is not in the recent list
	int max = EvaMain::user->getSetting()->recentContactListSize();
	if(childCount() >= max){
		// remove the oldest contact if list size reached the max
		takeItem(oldest);
		delete oldest;
	}

	TQQFriend *f = EvaMain::user->getFriends()->getFriend(id);
	if(f){
		item = new EvaRecentContactLVItem(false, f, 0, this);
		item->setTime(time);
		sort();
	} else
		item = NULL;

	updateConfig();
	return item;
}

void EvaRecentContactLVItem::updateIcon(TQPixmap *p)
{
	if(!p) return;
	if(m_icon) delete m_icon;
	m_icon = new TQPixmap( p->convertToImage().smoothScale(EvaMain::global->getFaceSize() ));
}

EvaRecentContactLVItem * EvaRecentContactsListView::addQun( const unsigned int id, const unsigned int time )
{
	EvaRecentContactLVItem *item = dynamic_cast<EvaRecentContactLVItem *>(firstChild());
	EvaRecentContactLVItem *oldest = item;
	while(item){
		if( item->isQun() && (item->getQunID() == id) ){
			item->setTime( time);
			sort();
			updateConfig();
			return item;
		}
		if(oldest->getTime() > item->getTime()){
			// the less the later one
			oldest = item;
		}
		item = dynamic_cast<EvaRecentContactLVItem *>(item->nextSibling());
	}

	// so should be someone who is not in the recent list
	int max = EvaMain::user->getSetting()->recentContactListSize();
	if(childCount() >= max){
		takeItem(oldest);
		delete oldest;
	}

	Qun *q = EvaMain::user->getQunList()->getQun( id );
	if(q){
		item = new EvaRecentContactLVItem(true, 0, q, this);
		item->setTime(time);
		sort();
	}else
		item = NULL;

	updateConfig();
	return item;
}


