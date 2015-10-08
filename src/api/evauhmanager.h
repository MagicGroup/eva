/***************************************************************************
 *   Copyright (C) 2004-2005 by yunfan                                     *
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
 
#ifndef EVAUHMANAGER_H
#define EVAUHMANAGER_H

#include <ntqobject.h>
#include <ntqthread.h>
#include <ntqvaluelist.h>
#include <ntqhostaddress.h>
#include <ntqdatetime.h>
#include <ntqmap.h>
#include <ntqimage.h>
#include <ntqevent.h>
#include <ntqsize.h>
#include <list>
#include "evaqtutil.h"

class TQSocketDevice;
class TQDns;
class EvaUHPacket;
class EvaUHFile;
class EvaUHProfile;

class EvaUHManager : public TQObject, public TQThread {
	Q_OBJECT
public:
	EvaUHManager(TQObject *receiver, const TQString &dir); // set the user head directory
	~EvaUHManager();
	// the method will post UH event if profile loaded
	void initiate(TQSize size = TQSize(16, 16));
	void setTQQList(const std::list<unsigned int> list) { mUHList = list; }
	virtual void run();
	void stop();
	TQString getFileName(const unsigned int id, bool isGrayscale = false); 
	TQImage *getUHImage(const unsigned int id, bool isGrayscale = false); 
	TQMap<unsigned int, TQImage> getOnList() { return imageOnList; }
	TQMap<unsigned int, TQImage> getOffList() { return imageOffList; }
private:
	TQObject *mReceiver;
	enum COMMAND {No_CMD, All_Info, Buddy_Info, Buddy_File, All_Done};
	COMMAND cmdSent;
	TQDateTime timeSent;
	int m_retryCount;
	unsigned int AllInfoGotCounter;
	TQString mUHDir;
	TQMap<unsigned int, TQImage> imageOnList;
	TQMap<unsigned int, TQImage> imageOffList;
	
	bool mAskForStop;
	char mBuffer[65535];  // used as internal buffer
	int bytesRead;
	std::list<unsigned int> mUHList;
	TQSocketDevice *mSocket;
	
	EvaUHProfile *mProfileManager;
	EvaUHFile *mCurrentFile;
	
	TQDns *mDns;
	TQValueList<TQHostAddress> mHostAddresses;
	void doDnsRequest();
	
	void send(EvaUHPacket *packet);
	void doAllInfoRequest();
	bool doInfoRequest();
	void doTransferRequest(const unsigned int id, const unsigned int sid,
				const unsigned  int start, const unsigned  int end);
	
	void processComingData();
	void processAllInfoReply();
	void processBuddyInfoReply();
	void processBuddyFileReply();
	
	void checkTimeout();
	void cleanUp();
private slots:
	void slotDnsReady();
};

#endif 
