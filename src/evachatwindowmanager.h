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
#ifndef EVACHATWINDOWMANAGER_H
#define EVACHATWINDOWMANAGER_H

#include "../api/filetrans/evafiledownloader.h"
#include <ntqobject.h>
#include <ntqptrlist.h>
#include <ntqvaluelist.h>
#include <ntqdatetime.h>
#include <kurl.h>
#include <list>

class TQQFriend;
class EvaImageResource;
class EvaUserSetting;
class EvaChatWindow;
class EvaQunChatWindow;
class Qun;

class EvaChatWindowManager : public TQObject
{
	Q_OBJECT
public:
	EvaChatWindowManager(EvaImageResource *img, EvaUserSetting *setting, TQString myNickname, const int id);
	~EvaChatWindowManager();
	
	bool isChatWindowExisted(const unsigned int id);
	EvaChatWindow * openChatWindow(TQQFriend * frd, const bool isSendingFile = false);
	
	bool isQunChatWindowExisted(const unsigned int id);
	void openQunChatWindow(Qun *qun);
	
	void closeAllWindows();
	
	std::list<int> getMessages();
	
	std::list<int> getQunMessages();
	
	void addButton(TQString &scriptName, TQString &buttonName, TQString &image, TQString &tip);
	///Note, if buttonName is null, all buttons added by scriptName will be removed
	void removeButton(TQString &scriptName, const TQString &buttonName = TQString::null);
public slots:
	void graphicChanged();
	void slotReceivedMessage(unsigned int sender, bool isNormal, TQString message, TQDateTime time, const char size=9, 
			const bool u=false, const bool i=false, const bool b=false, 
			const char blue=0, const char green=0, const char red=0);
	void slotSendResult(unsigned int id, bool ok);
	void slotBuddyTQQShowReady(const unsigned int id);
	void slotMyTQQShowReady();
	EvaChatWindow *getWindow(const unsigned int id);
	void setMyName(TQString myName, const unsigned int id);
	
	/// qun
	void slotReceivedQunMessage( unsigned int qunID, unsigned int senderQQ, TQString message, TQDateTime time, const char size, 
					const bool u, const bool i, const bool b, 
					const char blue, const char green, const char red );
	void slotQunSendResult(unsigned int id, bool ok, TQString msg);
	void slotQunJoinEvent(const unsigned int qunID, const short imType, const unsigned int sender, const unsigned int commander); 
	EvaQunChatWindow *getQunWindow(const unsigned int id);
	
	void slotQunOnlineMembers(const unsigned int);
	//void slotUpdateQunMembers(int);
	void slotQunPicReady(const unsigned int id, const TQString fileName, const TQString tmpFileName);
	void slotQunPicSent(const unsigned int, const unsigned int, const unsigned int, const unsigned short);
	void slotSendImageError(const unsigned int id, const TQString message);
	void slotQunMemberInfoReady( const unsigned int);
	void slotQunListUpdated();

	void slotReceivedFileRequest(TQQFriend * frd, const unsigned int session, 
					const TQString fileName, const int size,
					const unsigned char transferType);
	// we need filename instead of session id
	void slotReceivedFileAccepted(const unsigned int id, const unsigned int session, const bool isAccepted,
					const unsigned char transferType);
	void slotChangeFileSessionTo(const unsigned int id, const unsigned int oldSession, 
					const unsigned int newSession);
	void slotFileNotifyNormalInfo(const unsigned int, const unsigned int, EvaFileStatus,
					const TQString, const TQString, const unsigned int,
					const unsigned char);

	void slotFileStatusNotification(const unsigned int id, const unsigned int session, const KURL &url, const unsigned int size,
				const unsigned int bytes, const unsigned int time);
signals:
	void requestDetails(const unsigned int id);
	void sendMessage(const unsigned int receiver, const bool isNormal, TQString &message, const char size, 
			const bool u, const bool i, const bool b, 
			const char blue, const char green, const char red);
	void requestHistory(const unsigned int );
	void requestBuddyTQQShow(const unsigned int);
	void requestMyTQQShow();
	
	/// qun
	void requestQunDetails(const unsigned int id);
	void requestQunCard(const unsigned int id, const unsigned int qq);
	void sendQunMessage(const unsigned int, TQString &, const char , 
			const bool, const bool, const bool, 
			const char, const char, const char);
	void requestQunHistory(const unsigned int );
	void requestQunOnlineList(const unsigned int);
	//void requestQunMembers(const unsigned int);
	void requestQunRealNames(const unsigned int);

	void fileTransferSend(const unsigned int, const unsigned int, const TQValueList<TQString>,
				const TQValueList<unsigned int>, const unsigned char);
	void fileTransferAccept(const unsigned int, const unsigned int, const TQString, const unsigned char);
	void fileTransferCancel(const unsigned int, const unsigned int);
	void fileTransferResume(const unsigned int, const unsigned int, const bool);
private:
	EvaChatWindow *newWindow(TQQFriend *frd);
	TQPtrList<EvaChatWindow> windowList;
	typedef struct{
		unsigned int sender;
		bool isNormal;
		TQString message;
		TQDateTime time;
		char size;
		bool u, i, b;
		char blue, green, red;
	} Message;
	
	TQPtrList<Message> messageQueue;
	EvaUserSetting *userSetting;
	
	// here is all qun windows' structure
	EvaQunChatWindow *newQunWindow(Qun *qun);
	TQPtrList<EvaQunChatWindow> qunWindowList;
	typedef struct{
		unsigned int qunID;
		unsigned int sender;
		TQString message;
		TQDateTime time;
		char size;
		bool u, i, b;
		char blue, green, red;
	} QunMessage;
	TQPtrList<QunMessage> qunMessageQueue;
	
	typedef struct{
		TQString script;
		TQString button;
		TQString tip;
		TQString image;
	} CustomButton;
	std::list<CustomButton> m_btnList;
private:
	void addBuddyWindowButton(CustomButton &btn);
	void addQunWindowButton(CustomButton &btn);
	void removeBuddyWindowButton(CustomButton &btn);
	void removeQunWindowButton(CustomButton &btn);
	void addBtnsToBuddyWin(EvaChatWindow *win);
	void addBtnsToQinWin(EvaQunChatWindow *win);
};

#endif
