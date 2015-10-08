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
 
#ifndef EVATQTUTIL_H 
#define EVATQTUTIL_H

#include "evafriendlist.h"
#include "evaqunlist.h"
#include "evahtmlparser.h"

#include <string>
#include <ntqobject.h>
#include <ntqthread.h>
#include <ntqpixmap.h>
#include <ntqimage.h>
#include <ntqsize.h>
#include <ntqevent.h>
#include <ntqmutex.h>

#define EvaLoadGroupedUsersEvent  65535
#define EvaLoadQunUsersEvent      65534
#define EvaLoadSysEvent           65533
#define EvaScaleImageEvent        65532
#define EvaRequestCustomizedPicEvent 65531
#define EvaPictureReadyEvent      65530
#define EvaSendPictureReadyEvent  65529
#define EvaUserHeadReadyEvent     65528
#define EvaEventNotify            65527

const TQ_UINT32 profileVersion = 0x000400;

class TQFile;

// note that this static method is to filer those control chars out and change some printable funny chars into spaces
class EvaTextFilter 
{
public:
	static const TQString filter(const TQString &str);
};

class EvaSysEvent : public TQCustomEvent
{
public:
	EvaSysEvent() : 
		TQCustomEvent(EvaLoadSysEvent){};
};

class EvaScaleEvent : public TQCustomEvent
{
public:
	EvaScaleEvent(const TQPixmap p) : 
		TQCustomEvent(EvaScaleImageEvent), pic(p) {}
	TQPixmap pixmap() { return pic; }
private:
	TQPixmap pic;
};

class EvaBuddyListEvent : public TQCustomEvent
{
public:
	EvaBuddyListEvent() : TQCustomEvent(EvaLoadGroupedUsersEvent) {};
	
	void setGroupNames(const std::list<std::string>& names) { groupNames = names; }
	void setDetails(const ContactInfo &info) { myInfo = info; }
	void setFriendList(const FriendList &l) { list = l; }
	void setExtraInfo(const unsigned short info) { mExtraInfo = info; }
	void setSignature(const std::string sig, const unsigned int time) { mSignature = sig; mSigModiTime = time; }
	
	const std::list<std::string> getGroupNames() const { return groupNames; }
	const ContactInfo getMyInfo() const { return myInfo; }
	const FriendList getMyFriendList() const { return list; }
	const unsigned long long getExtraInfo() const { return mExtraInfo; }
	const std::string getSignature() const { return mSignature;}
	const unsigned int getSignatureTime() const { return mSigModiTime;}
private:
	std::list<std::string> groupNames;
	ContactInfo myInfo;
	FriendList list;
	unsigned long long mExtraInfo;
	std::string mSignature;
	unsigned int mSigModiTime;
};

class EvaQunListEvent : public TQCustomEvent
{
public:
	EvaQunListEvent() : TQCustomEvent(EvaLoadQunUsersEvent) {};
	void setQunList( const QunList &l) { list = l; }
	QunList getQunList() { return list; }
private:
	QunList list;
};

class EvaAskForCustomizedPicEvent : public TQCustomEvent
{
public:
	EvaAskForCustomizedPicEvent() : TQCustomEvent(EvaRequestCustomizedPicEvent) {};
	void setPicList( const std::list<CustomizedPic> &list) { picList = list; }
	std::list<CustomizedPic> getPicList() { return picList; }
	void setQunID(const unsigned int id) { qunID = id; }
	const unsigned int getQunID() const { return qunID; }
private:
	std::list<CustomizedPic> picList;
	unsigned int qunID;
};

class EvaSendCustomizedPicEvent : public TQCustomEvent
{
public:
	EvaSendCustomizedPicEvent() : TQCustomEvent(EvaSendPictureReadyEvent) {};
	void setPicList( const std::list<OutCustomizedPic> &list) { picList = list; }
	std::list<OutCustomizedPic> getPicList() { return picList; }
	void setQunID(const unsigned int id) { qunID = id; }
	const unsigned int getQunID() const { return qunID; }
private:
	std::list<OutCustomizedPic> picList;
	unsigned int qunID;
};

class EvaPicReadyEvent : public TQCustomEvent
{
public:
	EvaPicReadyEvent() : TQCustomEvent(EvaPictureReadyEvent) {};
	void setFileName( const TQString &name) { fileName = name; }
	TQString getFileName() { return fileName; }
	
	void setTmpFileName( const TQString &name) { tmpFileName = name; }
	TQString getTmpFileName() { return tmpFileName; }
	
	void setQunID(const unsigned int id) { qunID = id; }
	const unsigned int getQunID() const { return qunID; }
private:
	unsigned int qunID;
	TQString fileName;
	TQString tmpFileName;
};

class EvaUHReadyEvent : public TQCustomEvent
{
public:
	EvaUHReadyEvent() : TQCustomEvent(EvaUserHeadReadyEvent) {};
	
	void setQQ( const unsigned int id) { mId = id; }
	void setImages( const TQImage on, const TQImage off) { imgOn = on; imgOff = off; }
	
	const unsigned int getQQ() { return mId; }
	const TQImage getOnImage() const { return imgOn; }
	const TQImage getOffImage() const { return imgOff; }
private:
	unsigned int mId;
	TQImage imgOn;
	TQImage imgOff;
};

typedef unsigned int EPARAM;

class EvaNotifyEvent : public TQCustomEvent
{
	public:
		EvaNotifyEvent(int event) 
				: TQCustomEvent(EvaEventNotify),
				m_id(event) 
		{};
		int m_id;
		TQString m_desc;
		EPARAM m_param;
};

class EvaContactManager;
class EvaHelper : public TQThread
{
public:
	enum Type{ LoadGroupedUsers, SaveGroupedUsers, LoadQunUsers, SaveQunUsers, LoadSys, ScaleImage };
	void setCategory(const Type t, TQObject *rec) { type = t; receiver = rec; }
	
	// for loading grouped users list
	void setLoadGroupedUsersArgs(TQFile *file) ;
	
	// for saving grouped users list
	void setSaveGroupedUsersArgs(TQFile *file, std::list<std::string> myGroups, ContactInfo &info, FriendList &myList,
					unsigned short extraInfo, std::string signature, unsigned int sigModiTime);
	
	// for loading Qun list
	void setLoadQunListArgs(TQFile *file);
	
	// for saving Qun list
	void setSaveQunListArgs(TQFile *file, QunList &list);
	
	// for image scaling
	void setScaleArgs(const TQPixmap &p, const TQSize &s) { pic = p; size = s; }
	
	// static method for generating customized smiley file into user's customCaches directory, should be the absolute path
	static const TQString generateCustomSmiley(const TQString &source, const TQString &destDir, const bool withThumbnail = false);
	
	// static method for calculating md5 of a file, should be the absolute path. note: char *md5 must be allocated before calling this method
	static const bool getFileMD5(const TQString &fileName, char *md5);
	
	// convert MD5 into string expression, all converted string are in upper case
	static const TQString md5ToString(const char *md5);
	
	// static method for copying source to dest directory, should be the absolute path
	static const bool copyFile(const TQString &source, const TQString &dest);
	
	// static method for renaming the source file to dest file name, should be the absolute path, note that: this method will delete source file
	static const bool rename(const TQString &source, const TQString &dest);

	// starting the thread
	virtual void run();
private:
	static TQMutex mutex;
	Type type;
	TQObject *receiver;
	
	// for user loading/saving buddy list  use only
	TQFile *file;
	
	// for user saving only
	std::list< std::string > groups;
	ContactInfo myInfo;
	FriendList list;
	TQ_UINT16 mExtraInfo;
	std::string mSignature;
	int mSigModiTime;
	
	// for qun list saving only
	QunList qunList;
	
	
	// for scale the image only
	TQPixmap pic;
	TQSize size;

	
	void doGroupedUserLoading();
	void doGroupedUserSaving();
	void doQunUserLoading();
	void doQunUserSaving();
	void doSysLoading();
	void doImageScaling();
	
	friend class EvaContactManager;
};

// return TQString
#define GB2Unicode( gb_char ) (TQTextCodec::codecForName("GB18030")->toUnicode( gb_char ))
// return char *
#define Unicode2GB( qstring) (TQTextCodec::codecForName("GB18030")->fromUnicode( qstring).data())
		
class EvaTQtUtils {
public:
	static TQRgb toGray(TQRgb rgb);
	// Warning: this can only be used in GUI thread
	static TQPixmap convertToGrayscale(const TQPixmap &pm);
	// This method is thread-safe method
	static void convertToGrayscale (TQImage *destImagePtr);
};

#endif
