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

#ifndef EVATQUNCHATWINDOW_H
#define EVATQUNCHATWINDOW_H

#include "evaqunchatuibase.h"
#include "evahtmlparser.h"
#include <ntqdatetime.h>
#include <ntqcolor.h>
#include <list> 

class EvaImageResource;
//class TQQFriend;
class Qun;
class CustomFaceSelector;
class TQTextCodec;
class TQKeyEvent;
class EvaFontSelecter;
class TQPopupMenu;
class TQTimer;
class TQShowEvent;
class TQCloseEvent;
class TQHideEvent;
class RegionGrabber;
class EvaHistoryViewer;

class EvaQunChatWindow : public EvaQunChatUIBase
{
	Q_OBJECT
public:
	EvaQunChatWindow(Qun * qun, TQWidget* parent = 0, const char* name = 0, WFlags fl = 0);
	~EvaQunChatWindow();
	static void setupImages(EvaImageResource *res);
	static void setQuickReplyMessages(const std::list<TQString> &list);
	void setQuickReplyMenu();
	const unsigned int getQunID();
	void showMessages();	
	void appendText(const TQString &txt);

	static unsigned int myQQ;
	static TQString myName;
	static bool isSentByEnter;
	
	void addToolButton( TQString &scriptName, TQString buttonName, TQString &pixmap, TQString &tip );
	void removeToolButton( TQString &scriptName, TQString buttonName );
	void updateQunCountNumbers();
public slots:
	void graphicChanged();
	void slotReceivedMessage(unsigned int qunID, unsigned int senderQQ, TQString message, TQDateTime time, const char size, 
			const bool u, const bool i, const bool b, 
			const char blue, const char green, const char red);
	void slotAddMessage(unsigned int sender, TQString sNick, unsigned int receiver, TQString rNick, bool isNormal, TQString message, 
			TQDateTime time, const char size=9, 
			const bool u=false, const bool i=false, const bool b=false, 
			const char blue=0, const char green=0, const char red=0);
	void slotAddInformation(const TQString &info);
	void slotSendResult(bool ok);
	//void slotBuddyTQQShowReady(const int id);
	//void slotMyTQQShowReady();
	void slotDisplayMembers();
	void slotUpdateOnlineMembers();
	///////////////void slotUpdateOnlineMembers();
	void slotPictureReady(const TQString filename, const TQString tmpFileName);
	void sendImageError(const TQString message);
	void slotSendImageDone(const unsigned int sessionID, const unsigned int ip, const unsigned short port);

	void slotAddImageToInputEdit(const TQString &);
signals:
	void requestQunDetails(const unsigned int );
	void sendQunMessage(const unsigned int, TQString &, const char , 
			const bool, const bool, const bool, 
			const char, const char, const char);
	void requestHistory(const unsigned int );
	//void requestBuddyTQQShow(const int);
	//void requestMyTQQShow();
	void requestQunOnlineList(const unsigned int);
	
	void requestDetails(const unsigned int);
	void requestQunCard(const unsigned int, const unsigned int);
	void requestQunRealNames(const unsigned int);
	void reqeustChat(const unsigned int);
protected:
	virtual void showEvent( TQShowEvent *e);
	virtual void closeEvent( TQCloseEvent *e);
	virtual void hideEvent( TQHideEvent *e);
private:
	void initObjects();
	void initInformation();
	void initConnection();

	
	void displaySendingMessage();
	TQString getSenderName(const unsigned int qqNum);
	
	const std::list<OutCustomizedPic> getSendFiles(const std::list<TQString> &fileList);
	
	CustomFaceSelector *smileyPopup;
	static EvaImageResource *images;
// 	static TQString htmlHeader;
// 	static TQString htmlTail;
	
	static std::list<TQString> tquickList;
	
	EvaFontSelecter *fontSelecter;
	TQPopupMenu *sendKey;
	TQPopupMenu *tquickMenu;
	
	Qun *mQun;
	TQTextCodec *codec;

	TQDateTime sendtime;
	
	TQTimer *timer;
	
	TQString sendingImageMsg;
	
	RegionGrabber *grabber;
	EvaHistoryViewer* viewer;
	//std::list<TQString> outPicList;
	unsigned int sessionID;
	unsigned int ip;
	unsigned short port;
	
	TQMap<TQString, TQToolButton*> m_btnMap; // button name, button widget
	TQMap<TQString, TQString> m_scriptMap;   // button name, script name
private slots:
	void slotSmileySelected(int);
	void slotManageCustomSmileys();
// 	void slotMailClick(const TQString &, const TQString &);
// 	void slotURLClick(const TQString &);
	
	//void slotTbBuddyClick();
	void slotTbQunDetailsClick();
	
	void slotSmileyClick();
	void slotFontClick();
	void slotImageFileClick();
	void slotScreenShotClick();
	void slotQuickReplyClick();
	void slotQuickReplyActivated(int id);
	
	void slotHistoryClick();
	void slotHistoryWindowClosed();
	void slotSendKeyClick();
	void slotSend();
	
	void slotNoticeClick();
	//void slotTbShowBuddyClick();
	//void slotTbShowMeClick();
	
	void slotInputKeyPress(TQKeyEvent *e);
	
	void slotFontChanged(TQColor, int);
	
	void setEnterSend();
	void setCtrlEnterSend();
	void slotPbCloseClick();
	
	void slotTimeout();
	
	void slotRequestQunMembers();
	
	
	void slotRegionGrabbed( const TQPixmap & );
	
	void slotRequestQunCard(const unsigned int id);
	void slotRequestQunRealNames();

	void slotSaveAsCustomSmiley(TQString);
	void slotAddCustomSmileyReady( bool );
	void slotCustomSmileyChanged();
	
	void slotCustomBtnClick();	
	void slotRequestChat(const unsigned int);
};

#endif
