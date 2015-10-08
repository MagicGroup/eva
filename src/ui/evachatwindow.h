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

#ifndef EVACHATWINDOW_H
#define EVACHATWINDOW_H

#include "evachatuibase.h"
#include "../api/filetrans/evafiledownloader.h"
#include <ntqdatetime.h>
#include <ntqcolor.h>
#include <kurl.h>
#include <ntqvaluelist.h>
#include <ntqmap.h>
#include <list>

class EvaImageResource;
class TQQFriend;
class CustomFaceSelector;
class TQTextCodec;
class TQKeyEvent;
class TQCloseEvent;
class EvaFontSelecter;
class TQPopupMenu;
class RegionGrabber;
class EvaHistoryViewer;

class EvaChatWindow : public EvaChatUIBase
{
	Q_OBJECT
public:
	EvaChatWindow(TQQFriend * frd, TQWidget* parent = 0, const char* name = 0, WFlags fl = 0);
	~EvaChatWindow();
	static void setupImages(EvaImageResource *res);
	static void setQuickReplyMessages(const std::list<TQString> &list);
	void setQuickReplyMenu();
	const unsigned int getBuddyQQ();
	void showMessages();

	static int myQQ;
	static TQString myName;
	static bool isSentByEnter;

	void openSendFileDialog();
	void appendText(const TQString &txt);
	
	void addToolButton(TQString &scriptName, TQString buttonName, TQString &pixmap, TQString &tip);
  void removeToolButton(TQString &scriptName, TQString buttonName);
public slots:
	void graphicChanged();
	void slotReceivedMessage(unsigned int sender, bool isNormal, TQString message, TQDateTime time, const char size=9, 
			const bool u=false, const bool i=false, const bool b=false, 
			const char blue=0, const char green=0, const char red=0);
	void slotAddMessage(unsigned int sender, TQString sNick, unsigned int receiver, TQString rNick, bool isNormal, TQString message, 
			TQDateTime time, const char size=9, 
			const bool u=false, const bool i=false, const bool b=false, 
			const char blue=0, const char green=0, const char red=0);
	void slotSendResult(bool ok);
	void slotBuddyTQQShowReady(const unsigned int id);
	void slotMyTQQShowReady();

	void slotFileClick();
	void slotReceivedFileRequest(const unsigned int session, const TQString &file, const int size,
					const unsigned char transferType);
	void slotReceivedFileAccepted(const unsigned int session, const bool isAccepted,
					const unsigned char transferType);
	void slotSessionChangedTo(const unsigned int oldSession, const unsigned int newSession);
	void slotFileNotifyNormalInfo(const unsigned int, EvaFileStatus,
					const TQString, const TQString, const unsigned int,
					const unsigned char);
	void slotFileStatusNotification(const unsigned int session, const KURL &url, const unsigned int size,
				const unsigned int bytes, const unsigned int time);

	void slotAddImageToInputEdit( const TQString & destFile);
signals:
	void requestDetails(const unsigned int );
	void sendMessage(const unsigned int , const bool, TQString &, const char , 
			const bool, const bool , const bool , 
			const char , const char , const char );
	void requestHistory(const unsigned int );
	void requestBuddyTQQShow(const unsigned int);
	void requestMyTQQShow();

	void fileTransferSend(const unsigned int, const unsigned int, const TQValueList<TQString>,
				const TQValueList<unsigned int>,
				const unsigned char transferType);
	// last string is the dest path to save the file
	void fileTransferAccept(const unsigned int, const unsigned int, const TQString,
				const unsigned char transferType);
	void fileTransferCancel(const unsigned int, const unsigned int);
	void fileTransferResume(const unsigned int, const unsigned int, const bool);
private:
	void initObjects();
	void initInformation();
	void initConnection();

	
	void displaySendingMessage();
	
	CustomFaceSelector *smileyPopup;
	static EvaImageResource *images;
	
	static std::list<TQString> tquickList;
	TQPopupMenu *tquickMenu;
	
	EvaFontSelecter *fontSelecter;
	TQPopupMenu *sendKey;
	
	TQQFriend *buddy;
	TQTextCodec *codec;

	TQDateTime sendtime;

	int m_NumImages;
	RegionGrabber *grabber;
	EvaHistoryViewer *viewer;

	TQMap<TQString, TQToolButton*> m_btnMap; // button name, button widget
	TQMap<TQString, TQString> m_scriptMap;   // button name, script name
	
	TQMap<unsigned int, TQString> m_FileList;
	TQMap<unsigned int, unsigned int> m_FileNoList;
	const bool addToFileList(const unsigned int session, const TQString filename);
	TQString getFileName(const unsigned int session);
	const unsigned int getSession(const unsigned int showSession);
	void removeFromFileList(const unsigned int session);

	void closeEvent(TQCloseEvent *e);	
private slots:
	void slotSmileySelected(int);
	
	void slotTbBuddyClick();
	
	void slotSmileyClick();
	void slotFontClick();
	void slotQuickReplyClick();
	void slotQuickReplyActivated(int id);
	void slotHideShowsClick();
	
	void slotHistoryClick();
	void slotHistoryWindowClosed();
	void slotSendKeyClick();
	void slotSend();
	
	void slotTbShowBuddyClick();
	void slotTbShowMeClick();
	
	void slotInputKeyPress(TQKeyEvent *e);

	void slotFontChanged(TQColor color, int size)	;

	void setEnterSend();
	void setCtrlEnterSend();
	void slotPbCloseClick();

	void slotFileTransferAcceptClicked(const unsigned int);
	void slotFileTransferSaveAsClicked(const unsigned int);
	void slotFileTransferCancelClicked(const unsigned int);
	void slotFileTransferResume(const unsigned int, const bool);

	void slotFilePanelCloseClicked(const unsigned int);

	void slotAddImageClick();

	void slotScreenShotClick();
	void slotRegionGrabbed( const TQPixmap & );
	
	void slotCustomBtnClick();
};

#endif
