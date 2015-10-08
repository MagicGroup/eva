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

#ifndef EVAFILEMANAGER_H
#define EVAFILEMANAGER_H

#include <ntqobject.h>
#include <ntqptrlist.h>
//#include <ntqmap.h>
#include "evafiledownloader.h"
#include "../../libeva/evadefines.h"

class TQCustomEvent;
class EvaFileThread;

class EvaFileManager : public TQObject {
	Q_OBJECT
public:
	EvaFileManager(const int myId, TQObject *parent = 0);
	~EvaFileManager();
	// set before starting a new thread
	void setMyBasicInfo(const unsigned char *key, const unsigned char *token, const unsigned int tokenLen);
	void setMyProxyInfo(const TQHostAddress addr, const short port, const TQCString &param);

	const bool newSession(const unsigned int id, const unsigned int session, 
				const TQValueList<TQString> &dirList, 
				const TQValueList<TQString> &filenameList,
				const TQValueList<unsigned int> &sizeList, const bool isDownload,
				const unsigned char transferType = TQQ_TRANSFER_FILE);
	const bool changeToAgent(const unsigned int id, const unsigned int session);

// 	const bool newSession(const int id, const TQString &dir, const TQString &file, 
// 			const unsigned int session, const unsigned int size, 
// 			const bool isDirectConnection = true, const bool usingProxy = false, 
// 			const bool isDownload = false);

	void changeSessionTo(const unsigned int id, const unsigned int oldSession, const unsigned int newSession);
	void setBuddyAgentKey(const unsigned int id, const unsigned int session, const unsigned char *key);
	void setAgentServer(const unsigned int id, const unsigned int session, const unsigned int ip, const unsigned short port);
	void saveFileTo(const unsigned int id, const unsigned int session, const TQString dir);

	void updateIp(const unsigned int id, const unsigned int session, const unsigned int ip);
	const bool startSession(const unsigned int id, const unsigned int session);

	const TQString getFileName(const unsigned int id, const unsigned int session, const bool isAbs = false);
	const unsigned int getFileSize(const unsigned int id, const unsigned int session);
	const unsigned char getTransferType(const unsigned int id, const unsigned int session);

// 	void newSendThread(const int id, const unsigned int ip, const TQString &srcDir, const TQString &srcFilename,
// 			const bool isDirectConnection = true, const bool usingProxy = false);
//	void newReceiveThread();

	void stopThread(const unsigned int id, const unsigned int session);
	void stopAll();
	const bool isSender(const unsigned int id, const unsigned int session, bool *isExisted);
signals:
	// buddy qq, session id, file size, bytes sent, time elapsed
	void notifyTransferStatus(const unsigned int, const unsigned int, const unsigned int, const unsigned int, const int );
	// buddy qq, agent session id, agent ip, agent port
	void notifyAgentRequest(const unsigned int, const unsigned int, const unsigned int, const unsigned int, const unsigned short, const unsigned char);
	void notifyTransferSessionChanged(const unsigned int, const unsigned int, const unsigned int);
	void notifyTransferNormalInfo(const unsigned int, const unsigned int, EvaFileStatus, const TQString, 
					const TQString, const unsigned int, const unsigned char);
	void notifyAddressRequest(const unsigned int, const unsigned int, const unsigned int, const unsigned int, const unsigned short, 
				 const unsigned int, const unsigned short);

public slots:
	void slotFileTransferResume(const unsigned int id, const unsigned int session, const bool isResume);

protected:
	void customEvent(TQCustomEvent *e);
private:
	// session are the keys
	//TQPtrList<EvaFileThread> m_SendList;
	//TQPtrList<EvaFileThread> m_ReceiveList;
	//TQMap<unsigned int, EvaFileThread *> m_SendList;
	TQPtrList<EvaFileThread> m_ThreadList;
	EvaFileThread *m_LastThread;

	unsigned int m_MyId;
	TQHostAddress m_LocalAddress;

	// my encryption settings
	unsigned char m_FileAgentKey[16];
	unsigned char *m_FileAgentToken;
	unsigned int m_FileAgentTokenLength;

	// my proxy settings
	bool m_IsProxySet;
	TQHostAddress m_ProxyServer;
	short m_ProxyPort;
	TQCString m_ProxyAuthParam;

	//EvaFileThread *getThread(const unsigned int session);
	EvaFileThread *getThread(const unsigned int id, const unsigned int session);
};

#endif // EVAFILEMANAGER

