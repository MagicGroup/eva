/***************************************************************************
 *   Copyright (C) 2004 by yunfan                                          *
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
  
#include "evausersetting.h"
#include "evaqtutil.h"
#include "evamain.h"
#include "qmdcodec.h"
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <ntqdatastream.h>
#include <ntqtextstream.h>
#include <ntqstringlist.h>
#include <ntqfile.h>
#include <ntqdir.h>
#include <tdeconfig.h>
#include <tdelocale.h>
#include <kdebug.h>
#include <sqlite3.h>

EvaUserSetting::EvaUserSetting(const int id)
{
	qqNum = id;
	isUserDirExisted=false;
	pictureCacheDir = getEvaUserDir() + "/customCaches";
	customSmileyDir = getEvaUserDir() + "/CustomFace";
	userHeadDir = getEvaUserDir() + "/UserHead";
	loadDefaultSettings();
	SqlFileName = "user.sqlite3";
	buddyListFileName = "user.dat";
	qunListFileName = "qun.dat";
	chatMsgFileName = "chat.msg";
	qunMsgFileName = "qun.msg";
	userProfileFileName = "user.profile";
	userConfigFileName = "user.cfg";
	
	if(!createDefaultDirs())
		printf("error, cannot create user directory!\n");
	
	m_config = new TDEConfig(getEvaUserDir() + "/" + userConfigFileName);
	
	m_NeedRepaint = true;
}

EvaUserSetting::~EvaUserSetting()
{
	if(m_config){
		m_config->sync();
		delete m_config;
	}
}

void EvaUserSetting::loadMsgToSql(const TQString fullName,const bool isQunMsg)
{
	TQFile file(fullName);
	if(!file.open(IO_ReadOnly))
		return ;
	TQString fullNameSql = getEvaUserDir() + "/"+SqlFileName;
	int result;
	char * errmsg = NULL;
	char **dbResult;
	int nRow, nColumn,i=0;
	sqlite3 *db=NULL;
	result=sqlite3_open(fullNameSql.data(),&db);
	if( result != SQLITE_OK ) return;
	TQString sql;
	sqlite3_exec( db,"begin transaction;",0,0,&errmsg);

	TQ_UINT32 r_buddy;
	TQ_UINT32 sender;
	TQString  sNick;
	TQ_UINT32 receiver;
	TQString  rNick;
	TQ_UINT8  type; // 0 auto reply,  1 normal
	TQString  message;
	TQ_UINT32  intTime;
	TQDateTime time;
	TQ_UINT8   fontSize;
	TQ_UINT8   flag; // start from right.  bit 0: u, bit 1: i, bit 2: b
	TQ_UINT8   blue;
	TQ_UINT8   green;
	TQ_UINT8   red;
	TQDataStream stream(&file);
	std::list<chatMessage>srclist;
	while(!stream.atEnd()){
		stream>>r_buddy;
		stream>>sender;
		stream>>sNick;
		stream>>receiver;
		stream>>rNick;
		stream>>type;
		stream>>message;
		stream>>intTime;
		stream>>fontSize;
		stream>>flag;
		stream>>blue;
		stream>>green;
		stream>>red;
		sql.sprintf("select sender from chat where sender=%d and receiver=%d and time=%d and isQunMsg=%d ",sender,receiver,intTime,isQunMsg);
		result = sqlite3_get_table(db,sql.utf8().data(), &dbResult,&nRow, &nColumn, &errmsg);
		if( SQLITE_OK != result ) 
		{
			sqlite3_exec( db,"commit  transaction;",0,0,&errmsg);
			return;
		}
		if(nRow>0) continue; //找到重复的记录
		i++;
		sql.sprintf("insert into chat values (%d,%d,'%s', %d,'%s',%d, '%s', %d,%d, %d, %d,%d,%d,%d)",r_buddy,sender,sNick.local8Bit().data(),receiver,rNick.local8Bit().data(),type,message.local8Bit().data(),intTime,fontSize,flag,blue,green,red,isQunMsg);
		sqlite3_exec( db , sql.utf8().data() , 0 , 0 , &errmsg );
	}
	printf("load %s %i条\n",fullName.data(),i);
	sqlite3_exec( db,"commit transaction;",0,0,&errmsg);
	file.close();
	TQString newfile;
	newfile=fullName+".old";
	unlink(newfile.local8Bit().data());
	rename(fullName.local8Bit().data(),newfile.local8Bit().data());
	return ;
}


const bool EvaUserSetting::saveBuddyList(TQObject *receiver, std::list<std::string> groups, ContactInfo &myInfo, FriendList &list,
				unsigned short extraInfo, std::string sig, unsigned int sigTime)
{
	if(!isDirExisted(getEvaUserDir())){
		TQDir d;
		if(!d.mkdir(getEvaUserDir()))
			return false;
	}
	
	TQString fullName = getEvaUserDir() + "/" + buddyListFileName;
	TQFile file(fullName);
	if(file.exists()) file.remove();
	if(!file.open(IO_WriteOnly)){
		return false;
	}
	EvaMain::helper->setCategory(EvaHelper::SaveGroupedUsers, receiver);
	EvaMain::helper->setSaveGroupedUsersArgs(&file, groups, myInfo, list, extraInfo, sig, sigTime);
	EvaMain::helper->run();
	return true;
}

const bool EvaUserSetting::loadBuddyList( /*TQObject * receiver*/)
{
	if(!isDirExisted(getEvaUserDir())){
		TQDir d;
		if(!d.mkdir(getEvaUserDir()))
			return false;
}
	//建立chat的新的库文件
	sqlite3 *db=NULL;
	int rc;
	TQString sql=NULL;
	char *errmsg = 0;
	TQString fullNameSql = getEvaUserDir() + "/"+SqlFileName;
	TQFile file1(fullNameSql);
	if(!file1.exists()){ 
		file1.close();
		printf("建立chat库文件\n");
		rc=sqlite3_open(fullNameSql.data(),&db);
		sql="CREATE TABLE chat( \
		     buddy INTEGER, sender INTEGER, sNick text,\
		     receiver INTEGER,rNick text,\
		     isNormal INTEGER,\
		     message text,time INTEGER,fontSize INTEGER,flag INTEGER,\
		     blue INTEGER,green INTEGER,red INTEGER,\
		     isQunMsg INTEGER);";
		sqlite3_exec( db , sql.utf8().data() , 0 , 0 , &errmsg );
		printf("create db chat :%s\n",errmsg);
		sqlite3_exec( db, "CREATE index idxchat on chat(buddy,isQunMsg,time)",0,0,&errmsg);
		sqlite3_exec( db, "CREATE index idxchata on chat(sender,receiver,time,isQunMsg)",0,0,&errmsg);
		printf("create index chat :%s\n",errmsg);
		sqlite3_exec( db,"CREATE TABLE sysmsg (time INTEGER,msgType INTEGER,type INTEGER,fromQQ INTEGER,toQQ INTEGER,message text,internalQunID INTEGER,commander INTEGER,code text,token text)",0,0,&errmsg);
		printf("create db sysmsg :%s\n",errmsg);
		sqlite3_exec( db, "CREATE index idxsys on sysmsg(time,msgType,type,fromQQ,toQQ,internalQunID,commander)",0,0,&errmsg);
		printf("create index sysmsg :%s\n",errmsg);
	}

	TQString fullName = getEvaUserDir() + "/" + chatMsgFileName; //导入 chat.msg 到 sqlite3
	TQFile file(fullName);
	if(file.open(IO_ReadOnly)){ //chat.msg 可读
		file.close();
		loadMsgToSql(fullName,0);
	}

	fullName = getEvaUserDir() + "/" + qunMsgFileName; //导入 qun.msg 到 sqlite3
	file.setName(fullName);
	if(file.open(IO_ReadOnly)){ //qun.msg 可读
		file.close();
		loadMsgToSql(fullName,1);
	}

	fullName = getEvaUserDir() + "/" + buddyListFileName;
	file.setName(fullName);
	if(!file.open(IO_ReadOnly)){
		return false;
	}
	if(!isVersionCorrect(fullName)){
		file.close();
		return false;
	}

	std::list<std::string> groupNames;
	ContactInfo myInfo;
	FriendList list;	
	TQ_UINT32 numGroups=0;
	MemoItem memo;

	TQDataStream stream(&file);
	
	// check version first
	char *flag = new char[3];
	stream.readRawBytes(flag, 3);
	TQ_UINT32 version = 0;
	stream>>version;
	if(!(flag[0]=='E' && flag[1]=='V' && flag[2]=='A' && version == profileVersion)){
		file.close();
		file.remove();
		delete flag;
		return false;
	}
	delete []flag;
	
	// load my details first
	TQ_UINT32 size=0;
	std::string item;
	std::vector<std::string> strlist;
	
	stream>>size;
	char *str = new char[512];
	for(uint i=0; i<size; i++){
		stream>>str;
		item = str;
		strlist.push_back(item);
	}	
	myInfo.setDetails(strlist);

	// read my extra info
	TQ_UINT16 myExtraInfo;
	stream>>myExtraInfo;
	
	// read signature & time
	std::string signature;
	stream>>str; 
	signature = str;
	
	TQ_UINT32 sigTime;
	stream>>sigTime;
	
	// read in how many groups
	stream>>numGroups;
	std::string name;
	// read all groups in
	for(uint i=0; i<numGroups; i++){
		stream>>str;
		name = str;
		groupNames.push_back(name);
	}
	
	TQ_UINT32 id;
	TQ_UINT16 face;
	TQ_UINT8  age;
	TQ_UINT8  gender;
	std::string nick;
	TQ_UINT8  extFlag;
	TQ_UINT8  commonFlag;
	TQ_UINT32 groupIndex;
	TQ_UINT16 extraInfo;
	std::string frdSig;
	TQ_UINT32 frdSigTime;
	TQ_UINT32 fontSize;
	TQ_UINT32 fontColor;
	
	// read in all friends
	while(!stream.atEnd()){
		stream>>id;
		stream>>face;
		stream>>age;
		stream>>gender;
		stream>>str;
		nick = str;
		stream>>extFlag;
		stream>>commonFlag;
		stream>>groupIndex;
		stream>>extraInfo;
		stream>>str;
		frdSig = str;
		stream>>frdSigTime;
		
		strlist.clear();
		stream>>size;
		for(uint i=0; i<size; i++){
			stream>>str;
			item = str;
			strlist.push_back(item);
		}
		stream>>str;memo.name = str;
		stream>>str;memo.mobile = str;
		stream>>str;memo.telephone = str;
		stream>>str;memo.address = str;
		stream>>str;memo.email = str;
		stream>>str;memo.zipcode = str;
		stream>>str;memo.note = str;

		stream>>fontSize>>fontColor;
		TQQFriend f(id, face);
		
		f.setAge(age);
		f.setGender(gender);
		f.setNick(nick);
		f.setExtFlag(extFlag);
		f.setCommonFlag(commonFlag);
		f.setGroupIndex(groupIndex);
		f.setExtraInfo(extraInfo);
		f.setSignature(frdSig, frdSigTime);
		ContactInfo info;
		info.setDetails(strlist);
		f.setUserInformation(info);
		f.setMemo(memo);
		f.setChatFontSize(fontSize);
		f.setChatFontColor(fontColor);
		
		list.addFriend(f);
	}
	delete []str;
	file.close();
	
	EvaUser *user = EvaMain::user;
	if(user)
	{
		user->details              = myInfo;
		user->groupNames           = groupNames;
		user->myFriends            = list;
		user->mExtraInfo           = myExtraInfo;
		user->mSignature           = signature;
		user->mSignatureModifyTime = sigTime;
		return true;
	} else
		return false;	
	
	//EvaMain::helper->setCategory(EvaHelper::LoadGroupedUsers, receiver);
	//EvaMain::helper->setLoadGroupedUsersArgs(&file);
	//EvaMain::helper->run();
	//return true;
}

//保存信息
const bool EvaUserSetting::saveMessage(const int buddy, const int sender, TQString sNick, 
		const int receiver, TQString rNick,
		const bool isNormal, 
		const TQString message, 
		const TQDateTime time, const char fontSize, 
		const bool u, const bool i, const bool b, 
		const char blue, const char green, const char red, const bool isQunMsg)
{
	sqlite3 *db=NULL;
	int rc;
	char *errmsg = 0;
	if(!isDirExisted(getEvaUserDir())){
		TQDir d;
		if(!d.mkdir(getEvaUserDir()))
			return false;
	}	
	TQString fullNameSql = getEvaUserDir() + "/"+SqlFileName;
	rc=sqlite3_open(fullNameSql.data(),&db);
	TQ_UINT8  s_flag = (u?1:0)|( (i?1:0)<<1 ) | ( (b?1:0)<<2 );
	TQString sql;
	sql.sprintf("insert into chat values (%d,%d,'%s', %d,'%s',%d, '%s', %d,%d, %d, %d,%d,%d,%d)",buddy,sender,sNick.utf8().data(),receiver,rNick.utf8().data(),isNormal,message.utf8().data(),time.toTime_t(),fontSize,s_flag,blue,green,red,isQunMsg);

	sqlite3_exec( db , sql.utf8().data() , 0 , 0 , &errmsg );
	sqlite3_close(db);
}

//获得历史信息
std::list<EvaUserSetting::chatMessage> EvaUserSetting::getMessages( const int buddy, const int page,
		const TQDateTime starttime, const TQDateTime endtime, const bool isQunMsg)
{
	std::list<chatMessage>list;
	if(!isDirExisted(getEvaUserDir())) return list;
	TQString fullNameSql = getEvaUserDir() + "/"+SqlFileName;
	int result;
	char * errmsg = NULL;
	char **dbResult;
	int nRow, nColumn,i;
	chatMessage m;
	sqlite3 *db=NULL;
	TQDateTime time;
	result=sqlite3_open(fullNameSql.data(),&db);
	if( result == SQLITE_OK )
	{
		int j;
		TQString sql;
		if(starttime.toTime_t()==0) //starttime=0 获取全部记录
			sql.sprintf("select * from chat where buddy=%d and isQunMsg=%d order by time desc limit %d offset %d",buddy,isQunMsg, pageSize,pageSize*page);   
		else
			sql.sprintf("select * from chat where buddy=%d and isQunMsg=%d and time>=%d and time<=%d order by time desc limit %d offset %d",buddy,isQunMsg, starttime.toTime_t(),endtime.toTime_t(), pageSize,pageSize*page);   
		result = sqlite3_get_table(db,sql.utf8().data(), &dbResult,&nRow, &nColumn, &errmsg);
		if( SQLITE_OK == result )
		{
			for( i = 1; i <= nRow ; i++ )
			{
				j=i*nColumn;
				m.sender=atol(dbResult[j+1]);
				m.sNick = TQString::fromLocal8Bit(dbResult[j+2]);
				m.receiver=atol(dbResult[j+3]);
				m.rNick = TQString::fromLocal8Bit(dbResult[j+4]);
				m.type=atoi(dbResult[j+5]); //isNormal 
				m.message =TQString::fromLocal8Bit(dbResult[j+6]);
				time.setTime_t(atol(dbResult[j+7]));
				m.time = time;
				m.fontSize=atoi(dbResult[j+8]); 
				m.flag=atoi(dbResult[j+9]); // start from right.  bit 0: u, bit 1: i, bit 2: b
				m.blue=atoi(dbResult[j+10]);
				m.green=atoi(dbResult[j+11]);
				m.red=atoi(dbResult[j+12]);
				list.push_back(m);
			}
		}
		sqlite3_free_table( dbResult );
	}
	return list;
}

const bool EvaUserSetting::saveSysMessage(const short msgType, const unsigned char type, const int fromQQ, const int toQQ, 
		const TQString message, const int internalQunID, const unsigned int commander,
		const unsigned char *code, const unsigned short codeLen,
		const unsigned char *token, const unsigned short tokenLen)
{
	if(!isDirExisted(getEvaUserDir())){
		TQDir d;
		if(!d.mkdir(getEvaUserDir()))
			return false;
	}
	TQString sql,codea,tokena;
	TQString fullNameSql = getEvaUserDir() + "/"+SqlFileName;
	codea=TQString::fromUtf8((char *)(code),codeLen);
	tokena=TQString::fromUtf8((char *)(token),tokenLen);
	sql.sprintf("insert into sysmsg values(%d,%d,%d,%d,%d,'%s',%d,%d,'%s','%s')",time(0),msgType,type,fromQQ,toQQ,message.utf8().data(),internalQunID,commander,codea.utf8().data(),TQCodecs::base64Encode(tokena.local8Bit()).data());
	int result;
	char * errmsg = NULL;
	sqlite3 *db=NULL;
	result=sqlite3_open(fullNameSql.data(),&db);
	if( result == SQLITE_OK )
		sqlite3_exec( db , sql.utf8().data() , 0 , 0 , &errmsg );
	sqlite3_close(db);
}

std::list<EvaUserSetting::sysMessage> EvaUserSetting::getSysMessages( const int page) // page number starts from 0
{
	std::list<sysMessage>list;
	if(!isDirExisted(getEvaUserDir())) return list;
	int result;
	char * errmsg = NULL;
	int nRow, nColumn,i;
	sysMessage m;
	sqlite3 *db=NULL;
	TQDateTime time;
	TQString fullNameSql = getEvaUserDir() + "/"+SqlFileName;
	result=sqlite3_open(fullNameSql.data(),&db);
	if( result == SQLITE_OK )
	{
		char **dbResult;
		const	char *tmp;
		int j;
		TQString sql;
		sql.sprintf("select * from sysmsg order by time desc limit %d offset %d", pageSize,pageSize*page);
		result = sqlite3_get_table(db,sql.utf8().data(), &dbResult,&nRow, &nColumn, &errmsg);
		if( SQLITE_OK == result )
		{
			for( i = 1; i <= nRow ; i++ )
			{
				j=i*nColumn;
				m.messageType=atoi(dbResult[j+1]);//msgtype
				m.type = atoi(dbResult[j+2]);//type
				m.from =atol(dbResult[j+3]);//fromQQ
				m.to = atoi(dbResult[j+4]);//toQQ
				m.message =TQString::fromLocal8Bit(dbResult[j+9]); //message
				TQCString tmp1;
				tmp1=TQCodecs::base64Decode(m.message.local8Bit());
				m.internalQunID = atoi(dbResult[j+6]);
				m.commander=atoi(dbResult[j+7]); //message;
				m.codeLen=strlen(dbResult[j+8]);
				if(m.code) delete []m.code;
				m.code = new unsigned char[m.codeLen];
				memcpy(m.code,dbResult[j+8],m.codeLen);
				m.tokenLen=strlen(tmp1);
				if(m.token) delete []m.token;
				m.token = new unsigned char[m.tokenLen];
				memcpy(m.token,tmp1,m.tokenLen);
				m.message =TQString::fromLocal8Bit(dbResult[j+5]); //message
				list.push_back(m);
			}
		}
		sqlite3_free_table( dbResult );
	}
	return list;
}

EvaUserSetting::sysMessage EvaUserSetting::getLastSysMessage()
{
	sysMessage m;
	m.type = 0;
	m.from = 0;
	if(!sysStack.empty()){
		m = sysStack.top();
		sysStack.pop();
	}
	return m;
}

const bool EvaUserSetting::saveSettings()
{
	if(!isDirExisted(getEvaUserDir())){
		TQDir d;
		if(!d.mkdir(getEvaUserDir()))
			return false;
	}

	TDEConfig *cfg = new TDEConfig(getEvaUserDir() + "/" + userConfigFileName);
	
	TDEConfigGroupSaver *groupSaver = new TDEConfigGroupSaver(cfg, "General");
	cfg->writeEntry("DISPLAY_QQ_BROADCAST", showTQQBroadcast);
	cfg->writeEntry("DISPLAY_QQ_NEWS", m_ShowTQQNews);
	cfg->writeEntry("DISPLAY_TIP_MESSAGE_TIP_WINDOW", showMessageTipWindow);
	cfg->writeEntry("DISPLAY_BUDDY_ONLINE_NOTIFY", showBudyOnlineNotifyWindow);
	cfg->writeEntry("DISPLAY_ONLINE_BUDDIES", showOnlineUsers);
	cfg->writeEntry("SEND_KEY", isSendKeyEnter);
	cfg->writeEntry("PLAY_SOUND", playSound);
	cfg->writeEntry("SHOW_SMILEY_IN_NICK", m_ShowSmileyInNickName);
	cfg->writeEntry("SHOW_SIG_IN_SEPERATE_LINE", m_ShowSignatureInSeperateLine);
	delete groupSaver;
	
	groupSaver = new TDEConfigGroupSaver(cfg, "Font");
	cfg->writeEntry("BUDDY_NAME_COLOR", m_BuddyNameColor);
	cfg->writeEntry("BUDDY_NAME_FONT_B", m_BuddyNameFontB);
	cfg->writeEntry("BUDDY_NAME_FONT_U", m_BuddyNameFontU);
	cfg->writeEntry("BUDDY_NAME_FONT_I", m_BuddyNameFontI);

	cfg->writeEntry("BUDDY_SIGNATURE_COLOR", m_BuddySigColor);
	cfg->writeEntry("BUDDY_SIGNATURE_FONT_B", m_BuddySigFontB);
	cfg->writeEntry("BUDDY_SIGNATURE_FONT_U", m_BuddySigFontU);
	cfg->writeEntry("BUDDY_SIGNATURE_FONT_I", m_BuddySigFontI);

	cfg->writeEntry("BUDDY_FLASH_COLOR", m_BuddyFlashColor);
	cfg->writeEntry("BUDDY_FLASH_FONT_B", m_BuddyFlashFontB);
	cfg->writeEntry("BUDDY_FLASH_FONT_U", m_BuddyFlashFontU);
	cfg->writeEntry("BUDDY_FLASH_FONT_I", m_BuddyFlashFontI);

	// save Qun font settings
	cfg->writeEntry("TQUN_NAME_COLOR", m_QunNameColor);
	cfg->writeEntry("TQUN_NAME_FONT_B", m_QunNameFontB);
	cfg->writeEntry("TQUN_NAME_FONT_U", m_QunNameFontU);
	cfg->writeEntry("TQUN_NAME_FONT_I", m_QunNameFontI);

	cfg->writeEntry("TQUN_FLASH_COLOR", m_QunFlashColor);
	cfg->writeEntry("TQUN_FLASH_FONT_B", m_QunFlashFontB);
	cfg->writeEntry("TQUN_FLASH_FONT_U", m_QunFlashFontU);
	cfg->writeEntry("TQUN_FLASH_FONT_I", m_QunFlashFontI);

	// save group font settings
	cfg->writeEntry("GROUP_NAME_COLOR", m_GroupNameColor);
	cfg->writeEntry("GROUP_NAME_FONT_B", m_GroupNameFontB);
	cfg->writeEntry("GROUP_NAME_FONT_U", m_GroupNameFontU);
	cfg->writeEntry("GROUP_NAME_FONT_I", m_GroupNameFontI);

	cfg->writeEntry("GROUP_ONLINE_COUNT_COLOR", m_GroupCountColor);
	cfg->writeEntry("GROUP_ONLINE_COUNT_FONT_B", m_GroupOnlineCountFontB);
	cfg->writeEntry("GROUP_ONLINE_COUNT_FONT_U", m_GroupOnlineCountFontU);
	cfg->writeEntry("GROUP_ONLINE_COUNT_FONT_I", m_GroupOnlineCountFontI);

	cfg->writeEntry("GROUP_FLASH_COLOR", m_GroupFlashColor);
	cfg->writeEntry("GROUP_FLASH_FONT_B", m_GroupFlashFontB);
	cfg->writeEntry("GROUP_FLASH_FONT_U", m_GroupFlashFontU);
	cfg->writeEntry("GROUP_FLASH_FONT_I", m_GroupFlashFontI);

	delete groupSaver;
	
	groupSaver = new TDEConfigGroupSaver(cfg, "Theme");
	cfg->writeEntry("THEME_DIR", themeDir);
	cfg->writeEntry("SOUND_DIR", soundDir);
	delete groupSaver;
	
	groupSaver = new TDEConfigGroupSaver(cfg, "Reply");
	cfg->writeEntry("AUTO_REPLY_SELECTED_INDEX", autoSelectedIndex);
	std::list<TQString>::iterator iter;
	TQStringList strList;
	for(iter = autoList.begin(); iter!=autoList.end(); ++iter){
		strList += (*iter);
	}
	cfg->writeEntry("AUTO_REPLY", strList, '\255');
	strList.clear();
	for(iter = tquickList.begin(); iter!=tquickList.end(); ++iter){
		strList += (*iter);
	}
	cfg->writeEntry("QUICK_REPLY", strList, '\255');	
	delete groupSaver;

	groupSaver = new TDEConfigGroupSaver(cfg, "Others");
	cfg->writeEntry("FACE_SIZE", faceSize);
	cfg->writeEntry("MESSAGE_PAGE_SIZE", pageSize);
	cfg->writeEntry("MESSAGE_SHORTCUT", shortcut.toString());
	cfg->writeEntry("WIN_GEOMETRY_POINT", m_WinLeftTop);
	cfg->writeEntry("WIN_GEOMETRY_SIZE", m_WinSize);
	cfg->writeEntry("MAX_IDLE_TIME", idleMaxTime);
	delete groupSaver;
	
	groupSaver = new TDEConfigGroupSaver(cfg, "Cached_ToBeAdded_Buddies");
	cfg->writeEntry("NUM_BUDDIES", m_CachedToBeAddedBuddy.size());
	std::map<unsigned int, TQString>::iterator itr;
	int num = 0;
	for(itr = m_CachedToBeAddedBuddy.begin(); itr!=m_CachedToBeAddedBuddy.end(); ++itr){
		cfg->writeEntry(TQString("TQQ_%1").arg(num++), itr->second);
	}	
	delete groupSaver;

	groupSaver = new TDEConfigGroupSaver(cfg, "Reject_Forever");
	cfg->writeEntry("TQQ_REJECT_LIST_SIZE", m_RejectForever.size());
	std::list<unsigned int>::iterator rejectIter;
	num = 0;
	for(rejectIter = m_RejectForever.begin(); rejectIter!=m_RejectForever.end(); ++rejectIter){
		cfg->writeEntry(TQString("TQQ_%1").arg(num++), (unsigned int)(*rejectIter));
	}
	delete groupSaver;

	groupSaver = new TDEConfigGroupSaver(cfg, "Qun_Reject_Forever");
	cfg->writeEntry("TQUN_REJECT_LIST_SIZE", m_QunRejectForever.size());
	std::map<unsigned int, std::list<unsigned int> >::iterator qunRejectIter;
	num = 0;
	for(qunRejectIter = m_QunRejectForever.begin(); qunRejectIter!=m_QunRejectForever.end(); ++qunRejectIter){
		cfg->writeEntry(TQString("Qun_%1").arg(num++), qunRejectIter->first);
		cfg->writeEntry("TQUN_REJECT_MEMBER_SIZE", (qunRejectIter->second).size());
		int memberCount = 0;
		for(rejectIter = qunRejectIter->second.begin(); rejectIter!= qunRejectIter->second.end(); ++rejectIter){
			cfg->writeEntry(TQString("Qun_QQ_%1").arg(memberCount++), (unsigned int)(*rejectIter));
		}
	}
	delete groupSaver;

	//cfg->sync();
	delete cfg;
	return true;
}

const bool EvaUserSetting::loadSettings()
{
	if(!isDirExisted(getEvaUserDir())){
		return false;
	}
	
	TQString fullName = getEvaUserDir() + "/" + userProfileFileName;
	TQDir d;
	if(d.exists(fullName)){
		loadOldProfile();
		TQFile::remove(fullName);
		saveSettings();
	}
	
	TDEConfig *cfg = new TDEConfig(getEvaUserDir() + "/" + userConfigFileName);
	
	TDEConfigGroupSaver *groupSaver = new TDEConfigGroupSaver(cfg, "General");
	showTQQBroadcast = cfg->readBoolEntry("DISPLAY_QQ_BROADCAST", true);
	m_ShowTQQNews = cfg->readBoolEntry("DISPLAY_QQ_NEWS", true);
	showMessageTipWindow = cfg->readBoolEntry("DISPLAY_TIP_MESSAGE_TIP_WINDOW", true);
	showBudyOnlineNotifyWindow = cfg->readBoolEntry("DISPLAY_BUDDY_ONLINE_NOTIFY", true);
	showOnlineUsers = cfg->readBoolEntry("DISPLAY_ONLINE_BUDDIES", false);
	isSendKeyEnter = cfg->readBoolEntry("SEND_KEY", false);
	playSound = cfg->readBoolEntry("PLAY_SOUND", true);
	m_ShowSmileyInNickName = cfg->readBoolEntry("SHOW_SMILEY_IN_NICK", false);
	m_ShowSignatureInSeperateLine = cfg->readBoolEntry("SHOW_SIG_IN_SEPERATE_LINE", false);
	delete groupSaver;
	
	groupSaver = new TDEConfigGroupSaver(cfg, "Font");
	m_BuddyNameColor = cfg->readColorEntry("BUDDY_NAME_COLOR", &TQt::black);
	m_BuddyNameFontB = cfg->readBoolEntry("BUDDY_NAME_FONT_B", false);
	m_BuddyNameFontU = cfg->readBoolEntry("BUDDY_NAME_FONT_U", false);
	m_BuddyNameFontI = cfg->readBoolEntry("BUDDY_NAME_FONT_I", false);

	m_BuddySigColor = cfg->readColorEntry("BUDDY_SIGNATURE_COLOR", &TQt::gray);
	m_BuddySigFontB = cfg->readBoolEntry("BUDDY_SIGNATURE_FONT_B", false);
	m_BuddySigFontU = cfg->readBoolEntry("BUDDY_SIGNATURE_FONT_U", false);
	m_BuddySigFontI = cfg->readBoolEntry("BUDDY_SIGNATURE_FONT_I", false);

	m_BuddyFlashColor = cfg->readColorEntry("BUDDY_FLASH_COLOR", &TQt::red);
	m_BuddyFlashFontB = cfg->readBoolEntry("BUDDY_FLASH_FONT_B", false);
	m_BuddyFlashFontU = cfg->readBoolEntry("BUDDY_FLASH_FONT_U", false);
	m_BuddyFlashFontI = cfg->readBoolEntry("BUDDY_FLASH_FONT_I", false);

	m_QunNameColor = cfg->readColorEntry("TQUN_NAME_COLOR", &TQt::black);
	m_QunNameFontB = cfg->readBoolEntry("TQUN_NAME_FONT_B", false);
	m_QunNameFontU = cfg->readBoolEntry("TQUN_NAME_FONT_U", false);
	m_QunNameFontI = cfg->readBoolEntry("TQUN_NAME_FONT_I", false);

	m_QunFlashColor = cfg->readColorEntry("TQUN_FLASH_COLOR", &TQt::red);
	m_QunFlashFontB = cfg->readBoolEntry("TQUN_FLASH_FONT_B", false);
	m_QunFlashFontU = cfg->readBoolEntry("TQUN_FLASH_FONT_U", false);
	m_QunFlashFontI = cfg->readBoolEntry("TQUN_FLASH_FONT_I", false);

	m_GroupNameColor = cfg->readColorEntry("GROUP_NAME_COLOR", &TQt::black);
	m_GroupNameFontB = cfg->readBoolEntry("GROUP_NAME_FONT_B", false);
	m_GroupNameFontU = cfg->readBoolEntry("GROUP_NAME_FONT_U", false);
	m_GroupNameFontI = cfg->readBoolEntry("GROUP_NAME_FONT_I", false);

	m_GroupCountColor = cfg->readColorEntry("GROUP_ONLINE_COUNT_COLOR", &TQt::blue);
	m_GroupOnlineCountFontB = cfg->readBoolEntry("GROUP_ONLINE_COUNT_FONT_B", false);
	m_GroupOnlineCountFontU = cfg->readBoolEntry("GROUP_ONLINE_COUNT_FONT_U", false);
	m_GroupOnlineCountFontI = cfg->readBoolEntry("GROUP_ONLINE_COUNT_FONT_I", false);

	m_GroupFlashColor = cfg->readColorEntry("GROUP_FLASH_COLOR", &TQt::red);
	m_GroupFlashFontB = cfg->readBoolEntry("GROUP_FLASH_FONT_B", false);
	m_GroupFlashFontU = cfg->readBoolEntry("GROUP_FLASH_FONT_U", false);
	m_GroupFlashFontI = cfg->readBoolEntry("GROUP_FLASH_FONT_I", false);

	delete groupSaver;
	
	groupSaver = new TDEConfigGroupSaver(cfg, "Theme");
	themeDir = cfg->readEntry("THEME_DIR");
	soundDir = cfg->readEntry("SOUND_DIR");
	delete groupSaver;

		
	autoList.clear();
	tquickList.clear();
	groupSaver = new TDEConfigGroupSaver(cfg, "Reply");
	autoSelectedIndex = cfg->readNumEntry("AUTO_REPLY_SELECTED_INDEX");
	TQStringList strList;
	strList = cfg->readListEntry("AUTO_REPLY", '\255');
	if(strList.size()){
		for(TQStringList::Iterator iter = strList.begin(); iter != strList.end(); ++iter)
			autoList.push_back(*iter);
	} else {
		autoList.push_back(TQString(i18n("Sorry, I am working.")));
		autoList.push_back(TQString(i18n("Having dinner now./fa")));
		autoList.push_back(TQString(i18n("I am not available now, sorry.")));	
	}
	
	strList.clear();
	strList = cfg->readListEntry("QUICK_REPLY", '\255');
	if(strList.size()){
		for(TQStringList::Iterator iter = strList.begin(); iter != strList.end(); ++iter)
			tquickList.push_back(*iter);
	} else {
		tquickList.push_back(TQString(i18n("Oh.")));
		tquickList.push_back(TQString(i18n("OK, OK, I got you.")));
		tquickList.push_back(TQString(i18n("/jy , really?")));	
	}
	delete groupSaver;

	groupSaver = new TDEConfigGroupSaver(cfg, "Others");
	TQSize size(16, 16);
	faceSize = cfg->readSizeEntry("FACE_SIZE", &size);
	pageSize = cfg->readNumEntry("MESSAGE_PAGE_SIZE", 25);
	TQString shortkey = cfg->readEntry("MESSAGE_SHORTCUT") ;
	if(shortkey.isEmpty())
		shortcut.init(TQt::CTRL + TQt::ALT + TQt::Key_Z);
	else{
		if(!shortcut.init(shortkey))
			shortcut.init(TQt::CTRL + TQt::ALT + TQt::Key_Z);
	}
	TQPoint p(600, 100); 
	m_WinLeftTop = cfg->readPointEntry("WIN_GEOMETRY_POINT", &p);
	TQSize winSize(195, 376);
	m_WinSize = cfg->readSizeEntry("WIN_GEOMETRY_SIZE", &winSize);
	idleMaxTime = cfg->readNumEntry("MAX_IDLE_TIME", 5);
	delete groupSaver;

	m_CachedToBeAddedBuddy.clear();
	groupSaver = new TDEConfigGroupSaver(cfg, "Cached_ToBeAdded_Buddies");
	int num = cfg->readNumEntry("NUM_BUDDIES", 0);
	TQString buddyInfo;
	TQStringList items;
	bool ok;
	for(int i = 0; i< num; i++){
		buddyInfo = cfg->readEntry(TQString("TQQ_%1").arg(i));
		if(!buddyInfo.isEmpty()){
			items = TQStringList::split(",", buddyInfo);
			unsigned int id = items[0].toUInt(&ok);
			if(ok)
				m_CachedToBeAddedBuddy[id] = buddyInfo;
		}
	}
	delete groupSaver;

	m_RejectForever.clear();
	groupSaver = new TDEConfigGroupSaver(cfg, "Reject_Forever");
	num = cfg->readNumEntry("TQQ_REJECT_LIST_SIZE", 0);
	unsigned int id = 0;
	for(int i = 0; i< num; i++){
		id = cfg->readUnsignedNumEntry( TQString("TQQ_%1").arg(i));
		printf("read id: %d\n", id);
		if(id){
			m_RejectForever.push_back(id);
		}
	}
	delete groupSaver;

	m_QunRejectForever.clear();
	unsigned int tmpQun, tmpQQ;
	int memberCount;
	groupSaver = new TDEConfigGroupSaver(cfg, "Qun_Reject_Forever");
	num = cfg->readNumEntry("TQUN_REJECT_LIST_SIZE", 0);
	for(int q = 0; q < num; q++){
		tmpQun = cfg->readNumEntry(TQString("Qun_%1").arg(q), 0);
		memberCount = cfg->readNumEntry("TQUN_REJECT_MEMBER_SIZE", 0);
		std::list<unsigned int> members;
		for(int i = 0; i < memberCount; i++){
			tmpQQ = cfg->readNumEntry( TQString("Qun_QQ_%1").arg(i), 0);
			members.push_back(tmpQQ);
		}
		m_QunRejectForever[tmpQun] = members;
	}
	delete groupSaver;

	//cfg->sync();
	delete cfg;
	return true; 
}

bool EvaUserSetting::loadOldProfile()
{
	if(!isDirExisted(getEvaUserDir())){
		return false;
	}
	
	TQString fullName = getEvaUserDir() + "/" + userProfileFileName;
	TQDir d;
	if(!d.exists(fullName)){
		loadDefaultSettings();
		return true;
	}
	TQFile file(fullName);
	if(!file.open(IO_ReadOnly)){
		return false;
	}
	
	autoList.clear();
	tquickList.clear();
	
	TQString line;
	TQStringList lineList;
	TQTextStream stream(&file);
	while(!stream.atEnd()){
		line = stream.readLine().stripWhiteSpace();
		lineList = TQStringList::split(":", line);
		if(lineList.size() != 2)
			continue;
		
		lineList[0].stripWhiteSpace();
		lineList[1].stripWhiteSpace();
		
		if(lineList[0] ==  "THEME_DIR"){
			themeDir = lineList[1];
		}
		
		if(lineList[0] ==  "SOUND_DIR"){
			soundDir = lineList[1];
		}
		
		if(lineList[0] ==  "FACE_SIZE"){
			TQStringList size = TQStringList::split(",",lineList[1]);
			int width, height;
			bool ok;
			width = size[0].toInt(&ok);
			if(!ok) width = 16;
			height = size[1].toInt(&ok);
			if(!ok) height = 16;
			faceSize = TQSize(width, height);
			continue;
		}
		if(lineList[0] ==  "DISPLAY_QQ_BROADCAST"){
			if(lineList[1] == "false")
				showTQQBroadcast = false;
			else 
				showTQQBroadcast = true;
			continue;
		}
		if(lineList[0] ==  "DISPLAY_TIP_MESSAGE_TIP_WINDOW"){
			if(lineList[1] == "false")
				showMessageTipWindow = false;
			else 
				showMessageTipWindow = true;
			continue;
		}
		if(lineList[0] ==  "DISPLAY_BUDDY_ONLINE_NOTIFY"){
			if(lineList[1] == "false")
				showBudyOnlineNotifyWindow = false;
			else 
				showBudyOnlineNotifyWindow = true;
			continue;
		}
		if(lineList[0] ==  "DISPLAY_ONLINE_BUDDIES"){
			if(lineList[1] == "false")
				showOnlineUsers = false;
			else 
				showOnlineUsers = true;
			continue;
		}
		if(lineList[0] ==  "SEND_KEY"){
			if(lineList[1] == "false")
				isSendKeyEnter = false;
			else 
				isSendKeyEnter = true;
			continue;
		}
		if(lineList[0] ==  "MESSAGE_SHORTCUT"){
			if(!shortcut.init(lineList[1]))
				shortcut.init(TQt::CTRL + TQt::ALT + TQt::Key_Z);
			continue;
		}
		if(lineList[0] ==  "PLAY_SOUND"){
			if(lineList[1] == "false")
				playSound = false;
			else 
				playSound = true;
			continue;
		}
		if(lineList[0] == "AUTO_REPLY_SELECTED_INDEX"){
			bool ok = false;			
			autoSelectedIndex = lineList[1].toInt(&ok);
			if(!ok)
				autoSelectedIndex = 0;
				
		}
		if(lineList[0] == "AUTO_REPLY"){
			autoList.push_back(lineList[1]);
		}		
		if(lineList[0] == "QUICK_REPLY"){
			tquickList.push_back(lineList[1]);
		}
	}
	file.close();
	return true;
}

void EvaUserSetting::loadDefaultSettings()
{
	faceSize = TQSize(16,16);
	showTQQBroadcast = true;
	m_ShowTQQNews = true;
	showMessageTipWindow = true;
	showBudyOnlineNotifyWindow = true;
	showOnlineUsers = false;
	isSendKeyEnter = false;
	shortcut = TDEShortcut(TQt::CTRL + TQt::ALT + TQt::Key_Z);
	playSound = true;
	pageSize = 25;
	autoReply = true;
	themeDir = "";
	soundDir = "";
	autoSelectedIndex = 0;
	idleMaxTime = 5;

	m_BuddyNameColor = TQt::black;
	m_BuddyNameFontB = m_BuddyNameFontU = m_BuddyNameFontI = false;
	m_BuddySigColor = TQt::gray;
	m_BuddySigFontB = m_BuddySigFontU = m_BuddySigFontI = false;
	m_BuddyFlashColor = TQt::red;
	m_BuddyFlashFontB = m_BuddyFlashFontU = m_BuddyFlashFontI = false;

	m_QunNameColor = TQt::black;
	m_QunNameFontB = m_QunNameFontU = m_QunNameFontI = false;
	m_QunFlashColor = TQt::red;
	m_QunFlashFontB = m_QunFlashFontU = m_QunFlashFontI = false;

	m_GroupNameColor = TQt::black;
	m_GroupNameFontB = m_GroupNameFontU = m_GroupNameFontI = false;
	m_GroupCountColor = TQt::blue;
	m_GroupOnlineCountFontB = m_GroupOnlineCountFontU = m_GroupOnlineCountFontI = false;
	m_GroupFlashColor = TQt::red;
	m_GroupFlashFontB = m_GroupFlashFontU = m_GroupFlashFontI = false;

	m_ShowSmileyInNickName = false;
	m_ShowSignatureInSeperateLine = false;

	if(!autoList.size()){
		autoList.push_back(TQString(i18n("Sorry, I am working.")));
		autoList.push_back(TQString(i18n("Having dinner now./fa")));
		autoList.push_back(TQString(i18n("I am not available now, sorry.")));
	}
	
	if(!tquickList.size()){
		tquickList.push_back(TQString(i18n("Oh.")));
		tquickList.push_back(TQString(i18n("OK, OK, I got you.")));
		tquickList.push_back(TQString(i18n("/jy , really?")));
	}
}

const TQString &EvaUserSetting::getSelectedAutoReply()
{
	int index = 0;
	std::list<TQString>::iterator iter;
	for(iter=autoList.begin(); iter!=autoList.end(); ++iter){
		if(index == autoSelectedIndex) break;
		index++;		
	}
	return *iter;
}

const TQString &EvaUserSetting::getQuickReplyMessageAt(const int index)
{
	int i = 0;
	std::list<TQString>::iterator iter;
	for(iter=tquickList.begin(); iter!=tquickList.end(); ++iter){
		if(i == index) break;
		i++;
	}
	return *iter;
}

void EvaUserSetting::addAutoReplyMessage(const TQString &message)
{
	autoList.push_back(message);
}

void EvaUserSetting::addQuickReplyMessage(const TQString &message)
{
	tquickList.push_back(message);
}

const std::list<TQString> &EvaUserSetting::getAutoReplyList()
{
	return autoList;
}

const std::list<TQString> &EvaUserSetting::getQuickReplyList()
{
	return tquickList;
}

const TQString EvaUserSetting::getUserHomeDir()
{
	return TQDir::homeDirPath();
}

const TQString EvaUserSetting::getEvaSettingDir()
{
	return getUserHomeDir()+"/.eva";
}

const TQString EvaUserSetting::getEvaUserDir()
{
	return getEvaSettingDir() + "/" + TQString::number(qqNum);
}
	
const bool EvaUserSetting::isDirExisted(const TQString &dir)
{
	TQDir d;
	if (d.exists(dir))
		return true;
	else
		return false;
}

const bool EvaUserSetting::saveQunList( TQObject * receiver, QunList & list )
{
	if(!isDirExisted(getEvaUserDir())){
		TQDir d;
		if(!d.mkdir(getEvaUserDir()))
			return false;
	}
	
	TQString fullName = getEvaUserDir() + "/" + qunListFileName;
	TQFile file(fullName);
	if(file.exists()) file.remove();
	if(!file.open(IO_WriteOnly)){
		return false;
	}
	EvaMain::helper->setCategory(EvaHelper::SaveQunUsers, receiver);
	EvaMain::helper->setSaveQunListArgs(&file, list);
	EvaMain::helper->run();
	return true;
}

const bool EvaUserSetting::loadQunList( /*TQObject * receiver*/ )
{
	if(!isDirExisted(getEvaUserDir()))
		return false;
	
	TQString fullName = getEvaUserDir() + "/" + qunListFileName;
	TQFile file(fullName);
	if(!file.open(IO_ReadOnly)){
		return false;
	}
	
	TQDataStream stream(&file);

	// check version first
	char *flag = new char[3];
	stream.readRawBytes(flag, 3);
	TQ_UINT32 version = 0;
	stream>>version;
	if(!(flag[0]=='E' && flag[1]=='V' && flag[2]=='A' && version == profileVersion)){
		file.close();
		file.remove();
		delete flag;
		return false;
	}
	delete flag;
	
	QunList list;
	
	TQ_UINT32 qunID;
	TQ_UINT32 extID;
	TQ_UINT8 type;
	TQ_UINT32 creator;
	TQ_UINT8 authType;
	TQ_UINT16 unknown1;
	TQ_UINT16 category;
	TQ_UINT32 versionID;
	std::string name;
	TQ_UINT16 unknown2;
	std::string description;
	std::string notice;
	TQ_UINT32 realNamesVersion;

	TQ_UINT32 fontSize;
	TQ_UINT32 fontColor;
	
	TQ_UINT8 cardGender;
	TQ_UINT8 msgType;
	char *str = new char[1024];
	memset(str, 0, 1024);
	
	while(!stream.atEnd()){
		// load qun basic info
		stream>>qunID>>extID>>type>>creator>>authType>>unknown1>>category>>versionID>>str;
		name = str;
		stream>>unknown2>>str;
		description = str;
		stream>>str;
		notice = str;
		QunInfo info;
		info.setQunID(qunID);
		info.setExtID(extID);
		info.setType(type);
		info.setCreator(creator);
		info.setAuthType(authType);
		info.setUnknown1(unknown1);
		info.setCategory(category);
		info.setVersionID(versionID);
		info.setName(name);
		info.setUnknown2(unknown2);
		info.setDescription(description);
		info.setNotice(notice);
		
		Qun qun(info.getQunID());
		qun.setDetails(info);

		stream >> fontSize >> fontColor;	
		qun.setChatFontSize(fontSize);
		qun.setChatFontColor(fontColor);

		// load message type
		stream>>msgType;
		qun.setMessageType((Qun::MessageType)msgType);
		
		stream >> realNamesVersion;
		qun.setRealNamesVersion(realNamesVersion);
		// load my card for this qun
		stream>>str;
		qun.setCardName(str);
		stream>>cardGender;
		qun.setCardGender(cardGender);
		stream>>str;
		qun.setCardPhone(str);
		stream>>str;
		qun.setCardEmail(str);
		stream>>str;
		qun.setCardMemo(str);
		
		// load all members details
		std::list<FriendItem> members;
		TQ_UINT16 size;
		stream >> size;
		for(int i=0; i< size; i++){
			TQ_UINT32 qqNum;
			TQ_UINT16 face;
			TQ_UINT8 age;
			TQ_UINT8 gender;
			std::string nick;
			TQ_UINT8 extFlag;  
			TQ_UINT8 commonFlag;
			TQ_UINT16 qunGroupIndex;
			TQ_UINT16 qunAdminValue;
			std::string realName;   // added by henry
			
			stream>>qqNum>>face>>age>>gender>>str;
			nick = str;
			stream>>extFlag>>commonFlag>>qunGroupIndex>>qunAdminValue>>str;
			realName = str;
			FriendItem item;
			item.setQQ(qqNum);
			item.setFace(face);
			item.setAge(age);
			item.setGender(gender);
			item.setNick(nick);
			item.setExtFlag(extFlag);
			item.setCommonFlag(commonFlag);
			item.setQunGroupIndex(qunGroupIndex);
			item.setQunAdminValue(qunAdminValue);
			item.setQunRealName( realName); // henry
			members.push_back(item);
		}
		qun.setMembers(members);
		list.add(qun);
	}
	delete []str;
	file.close();
	
	EvaUser *user = EvaMain::user;
	if(user){
		user->qunList = list;
		return true;
	} else
		return false;
	
	//EvaMain::helper->setCategory(EvaHelper::LoadQunUsers, receiver);
	//EvaMain::helper->setLoadQunListArgs(&file);
	//EvaMain::helper->run();
	//return true;
}

bool EvaUserSetting::createDefaultDirs( )
{
	TQDir d;
	if(!isDirExisted(getEvaUserDir())){
		if(!d.mkdir(getEvaUserDir()))
			return false;
	}
	
	if(!isDirExisted(getPictureCacheDir())){
		if(!d.mkdir(getPictureCacheDir()))
			return false;
	}
	
	if(!isDirExisted(getCustomSmileyDir())){
		if(!d.mkdir(getCustomSmileyDir()))
			return false;
	}
	
	if(!isDirExisted(getUserHeadDir())){
		if(!d.mkdir(getUserHeadDir()))
			return false;
	}
	return true;
}

bool EvaUserSetting::isVersionCorrect( const TQString fileName )
{
	TQFile file(fileName);
	if(!file.exists()) return false;
	if(!file.open(IO_ReadOnly)){
		return false;
	}
	TQ_UINT32 version;
	TQDataStream stream(&file);
	char *flag = new char[3];
	stream.readRawBytes(flag, 3);
	stream>>version;
	file.close();
	if(!(flag[0]=='E' && flag[1]=='V' && flag[2]=='A' && version == profileVersion)){
		file.remove();
		delete flag;
		return false;
	}
	delete flag;
	return true;
}

void EvaUserSetting::saveToBeAddedBuddy( BuddyInfoCacheItem info )
{
	TQString line = TQString("%1,%2,%3,%4").arg(info.id).arg(info.nick).arg(info.face).arg(info.group);
	m_CachedToBeAddedBuddy[info.id] = line;
	
	saveSettings();
}

const BuddyInfoCacheItem EvaUserSetting::removeToBeAddedBuddy( const unsigned int id )
{
	BuddyInfoCacheItem info = getToBeAddedBuddy(id);

	/// remove this item
	std::map<unsigned int, TQString>::iterator iter;
	iter = m_CachedToBeAddedBuddy.find(id);
	if(iter == m_CachedToBeAddedBuddy.end())
		return info;
	m_CachedToBeAddedBuddy.erase(iter);

	saveSettings();
	return info;
}

const BuddyInfoCacheItem EvaUserSetting::getToBeAddedBuddy( const unsigned int id )
{
	BuddyInfoCacheItem info(id, TQString::number(id), 0, 0);

	std::map<unsigned int, TQString>::iterator iter;
	iter = m_CachedToBeAddedBuddy.find(id);
	if(iter == m_CachedToBeAddedBuddy.end())
		return info;
	TQStringList items = TQStringList::split(",", iter->second);
	bool ok;
	info.id = items[0].toUInt(&ok);
	if( (!ok) || (info.id != id) ){
		info.id = 0;
		return info;
	}
	info.nick = items[1];
	info.face = items[2].toUShort(&ok);
	if(!ok){
		info.face = 0;
		return info;
	}
	info.group = items[3].toInt(&ok);
	if(!ok){
		info.group = 0;
		return info;
	}

	return info;
}

void EvaUserSetting::addToRejectForever( const unsigned int id )
{
	std::list<unsigned int>::iterator iter;

	for(iter = m_RejectForever.begin(); iter != m_RejectForever.end(); ++iter){
		if( *iter == id) return;
	}
	m_RejectForever.push_back(id);
}

const bool EvaUserSetting::removeFromRejectForever( const unsigned int id )
{
	std::list<unsigned int>::iterator iter;

	for(iter = m_RejectForever.begin(); iter != m_RejectForever.end(); ++iter){
		if( *iter == id){
			m_RejectForever.erase(iter);
			return true;
		}
	}
	return false;
}

const bool EvaUserSetting::isInRejectForever( const unsigned int id )
{
	std::list<unsigned int>::iterator iter;

	for(iter = m_RejectForever.begin(); iter != m_RejectForever.end(); ++iter){
		if( *iter == id) return true;
	}
	return false;
}

void EvaUserSetting::addToQunRejectForever( const unsigned int id, const unsigned int qq )
{
	std::map<unsigned int, std::list<unsigned int> >::iterator iter = m_QunRejectForever.find(id);

	std::list<unsigned int> list;
	if(iter != m_QunRejectForever.end()){
		std::list<unsigned int>::iterator itr;
		list = iter->second;
		for(itr = list.begin(); itr!= list.end(); ++itr){
			if(*itr == qq) return;
		}
		list.push_back(qq);
	} else {
		list.push_back(qq);
	}
	m_QunRejectForever[id] = list;
}

const bool EvaUserSetting::removeFromQunRejectForever( const unsigned int id, const unsigned int qq )
{
	std::map<unsigned int, std::list<unsigned int> >::iterator iter = m_QunRejectForever.find(id);

	std::list<unsigned int> list;
	if(iter != m_QunRejectForever.end()){
		if(qq){
			std::list<unsigned int>::iterator itr;
			list = iter->second;
			for(itr = list.begin(); itr!= list.end(); ++itr){
				if(*itr == qq) {
					list.erase(itr);
					if(list.size())
						m_QunRejectForever[id] = list;
					else
						m_QunRejectForever.erase(iter);
					return true;
				}
			}
		}else // remove all members of the Qun(id)
			m_QunRejectForever.erase(iter);
	}
	return false;;
}

const bool EvaUserSetting::isInQunRejectForever( const unsigned int id, const unsigned int qq )
{
	std::map<unsigned int, std::list<unsigned int> >::iterator iter = m_QunRejectForever.find(id);

	std::list<unsigned int> list;
	if(iter != m_QunRejectForever.end()){
		std::list<unsigned int>::iterator itr;
		list = iter->second;
		for(itr = list.begin(); itr!= list.end(); ++itr){
			if(*itr == qq) return true;
		}
	}
	return false;	
}

void EvaUserSetting::updateRecentContact( std::list<RecentContact>& list )
{
	TQStringList s;
	std::list<RecentContact>::iterator it;
	TQString c;
	for(it = list.begin(); it!=list.end(); ++it){
		c = (it->isQun)?"Qun_":"TQQ_";
		c += TQString::number(it->id);
		c += "_";
		c += TQString::number(it->time);
		s.append(c);
	}

	unsigned int size = recentContactListSize();
	if(size < list.size()){
		kdDebug() << "[EvaUserSetting] recent contact list is out of size limit" << endl;
		return;
	}

	TDEConfig *cfg = new TDEConfig(getEvaUserDir() + "/" + userConfigFileName);
	
	TDEConfigGroupSaver *groupSaver = new TDEConfigGroupSaver(cfg, "Recent_Contacts");
	cfg->writeEntry("RECENT_LIST", s, '\255');
	delete groupSaver;
	delete cfg;	
}

std::list< RecentContact > EvaUserSetting::getRecentContacts( )
{
	TDEConfig *cfg = new TDEConfig(getEvaUserDir() + "/" + userConfigFileName);
	
	TDEConfigGroupSaver *groupSaver = new TDEConfigGroupSaver(cfg, "Recent_Contacts");
	TQStringList s = cfg->readListEntry( "RECENT_LIST", '\255');
	std::list< RecentContact > list;
	RecentContact contact;
	printf("recent size: %d\n", s.size());
	if(s.size()){
		for(TQStringList::Iterator iter = s.begin(); iter != s.end(); ++iter){
			TQString line = (*iter);
			TQStringList parts = TQStringList::split("_", line);
			if(parts.size() != 3) continue;
			
			if(parts[0] == "QQ")
				contact.isQun = false;
			else
				contact.isQun = true;

			bool ok;
			contact.id = parts[1].toUInt(&ok);
			if(!ok) continue;
			contact.time = parts[2].toUInt(&ok);
			if(ok)
				list.push_back(contact);
		}
	}
	cfg->sync();
	delete groupSaver;
	delete cfg;

	return list;
}

void EvaUserSetting::setRecentContactListSize( const int size )
{
	TDEConfig *cfg = new TDEConfig(getEvaUserDir() + "/" + userConfigFileName);
	
	TDEConfigGroupSaver *groupSaver = new TDEConfigGroupSaver(cfg, "Recent_Contacts");
	cfg->writeEntry("RECENT_MAX_SIZE", size);
	cfg->sync();
	delete groupSaver;
	delete cfg;
}

const int EvaUserSetting::recentContactListSize( )
{
	TDEConfig *cfg = new TDEConfig(getEvaUserDir() + "/" + userConfigFileName);
	
	TDEConfigGroupSaver *groupSaver = new TDEConfigGroupSaver(cfg, "Recent_Contacts");
	int size = cfg->readNumEntry("RECENT_MAX_SIZE", 10);
	delete groupSaver;
	delete cfg;
	return size;
}

TDEConfig *EvaUserSetting::config( const TQString &group )
{
	//printf("EvaUserSetting::config: %s\n", group.local8Bit().data());
	m_config->setGroup(group);
	return m_config;
}

