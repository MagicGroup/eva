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
#include "evaresource.h"
#include "evasetting.h"
#include "evaservers.h"
#include "evasocket.h"
#include "evamain.h"
#include "evauser.h"

#include <stdlib.h>
#include <ntqapplication.h>
#include <ntqhttp.h>
#include <ntqdir.h>
#include <ntqfileinfo.h>
#include <ntqdatastream.h>
#include <kaudioplayer.h>
#include <tdeglobal.h>
#include <kstandarddirs.h>


EvaImageResource::EvaImageResource()
{
	//imageRoot = tqApp->applicationDirPath() + "/images";
	themePath = "";
	imageRoot = EvaGlobal::getDirPath() + "/image";
	isDownloadingTQQShow = false;
	http = new EvaHttp();
	connect ( http, SIGNAL(requestFinished(bool)), SLOT(slotTQQShowDone(bool))); 
}

EvaImageResource::~EvaImageResource()
{
}

const TQString EvaImageResource::getFacePath() const
{
	return imageRoot + "/face";
}

const TQString EvaImageResource::getIconPath()
{
	if(themePath == "" )
		themePath = imageRoot + "/theme";
	return themePath;
}

const TQString EvaImageResource::getSmileyPath() const
{
	return imageRoot + "/smiley";
}

const int EvaImageResource::getFaceID(const int fileIndex) const
{
	if(fileIndex<=0 || fileIndex> MaxFaceNumber)
		return faceId[0];
	return faceId[fileIndex-1];
}

const int EvaImageResource::getFaceFileIndex(const int faceId)
{
	int index = (faceId<0)?1:faceId/3 + 1;
	if(index<0 || index> MaxFaceNumber) index = 1;
	return index;
}

TQPixmap *EvaImageResource::getFace(const int fileIndex, const bool on)
{
	TQString key = TQString::number((fileIndex>0)?fileIndex:1);
	if(!on) key+="off";
	TQMap<TQString, TQPixmap>::Iterator iter = faceList.find(key);
	if(iter== faceList.end()) return NULL;
	return &(iter.data());
}

TQPixmap *EvaImageResource::getFaceByID( const unsigned short faceId, const bool on)
{
	return getFace(getFaceFileIndex(faceId), on);
}

TQPixmap *EvaImageResource::getIcon(TQString name)
{
	TQMap<TQString, TQPixmap>::Iterator iter = iconList.find(name);
	if(iter== iconList.end()) return NULL;
	return &(iter.data());
}

const TQString EvaImageResource::getIconFullPath(TQString name)
{
	TQMap<TQString, TQString>::Iterator iter = iconFileNameMap.find(name);
	if(iter== iconFileNameMap.end()) return "";
	return getIconPath() + "/" + iter.data();
}

const TQString EvaImageResource::getSmiley(const int fileIndex)
{
	return getSmileyPath() + TQString("/%1.gif").arg(fileIndex);
	
//	TQString key = TQString::number(fileIndex);
//	TQMap<TQString, TQMovie>::Iterator iter = smileyList.find(key);
//	if(iter== smileyList.end()) return NULL;
//	return &(iter.data());
}

const TQMovie *EvaImageResource::getLoginMovie()
{
	return &loginMng;
}

const bool EvaImageResource::loadImage()
{
	return loadIcon();
	//return (loadFace() && loadIcon() );
	//return (loadFace() && loadIcon() && loadSmiley());
}

bool EvaImageResource::loadFace(const TQSize &/*size*/)
{
	TQString path = getFacePath();
	TQFile file( path + "/face.theme");    
	if(!file.open(IO_ReadOnly)){
		return false;
	}
	faceList.clear();
	TQTextStream stream(&file);
	TQString line, imagePath;
	TQStringList lineList;
	while(!stream.atEnd()){
		line = stream.readLine().stripWhiteSpace();
			
		lineList = TQStringList::split(":", line);
		if(lineList.size() != 2)
			continue;
		
		lineList[0].stripWhiteSpace();
		imagePath = path + "/" + lineList[1].stripWhiteSpace();
		TQPixmap img(imagePath);
		if(!img.isNull()){
//			faceList[lineList[0]] = img.convertToImage().smoothScale(size);
			faceList[lineList[0]] = img;
                }
	}
	
	file.close();
	
	for(int i = 0; i < MaxFaceNumber ; i++) {
		faceId[i] = i * 3 + 1;
	}
	return true;	
}

bool EvaImageResource::loadIcon()
{
	TQString path = getIconPath() + "/eva.theme";
	TQDir d;
	if(!d.exists(path)){
		themePath = ""; // if theme not exist, load default one
		path = getIconPath() + "/eva.theme";
	}
	TQFile file( path);
	if(!file.open(IO_ReadOnly)){
		return false;
	}
	
	TQTextStream stream(&file);
	TQString line, imagePath;
	TQStringList lineList;
	
	while(!stream.atEnd()){
		line = stream.readLine().stripWhiteSpace();
			
		lineList = TQStringList::split(":", line);
		
		if(lineList.size() != 2)
			continue;
		
		lineList[0].stripWhiteSpace();
		imagePath = getIconPath() + "/" + lineList[1].stripWhiteSpace();
		if(lineList[0] == "LOGIN_MNG"){
			loginMng = TQMovie(imagePath);
			continue;
		}
		TQPixmap img(imagePath);
		if(!img.isNull()){
			iconList[lineList[0]] = img;
			iconFileNameMap[lineList[0]] = lineList[1].stripWhiteSpace();
		}
	}
	
	file.close();
	return true;  
}

bool EvaImageResource::loadSmiley()
{
	TQString path = getSmileyPath();
	TQFile file( path + "/smiley.theme");    
	if(!file.open(IO_ReadOnly)){
		return false;
	}
	
	TQTextStream stream(&file);
	TQString line, imagePath;
	TQStringList lineList;
	
	while(!stream.atEnd()){
		line = stream.readLine().stripWhiteSpace();
			
		lineList = TQStringList::split(":", line);
		
		if(lineList.size() != 2)
			continue;
		
		lineList[0].stripWhiteSpace();
		imagePath = path + "/" + lineList[1].stripWhiteSpace();
		TQMovie m(imagePath);
		if(!m.isNull())
			smileyList[lineList[0]] = m;
	}
	
	file.close();
	return true;  
}

const TQString EvaImageResource::getTQQShowPath() const
{
	TQString evaHome = TQDir::homeDirPath() + "/.eva";		
	TQDir d;
	if(!d.exists(evaHome)){
		return "";
	}
	if(!d.cd(evaHome)) return "";
	if(!d.exists("TQQShow")){
		if(!d.mkdir("TQQShow", false))	return "";
	}
	return evaHome + "/TQQShow";	
}

TQPixmap *EvaImageResource::getTQQShow(const unsigned int id)
{
	TQString path = getTQQShowPath() +"/"+ TQString::number(id) + ".gif";
	TQDir d;
	if(d.exists(path))
		return new TQPixmap(path);	
	return NULL;
}

void EvaImageResource::requestTQQShow(const unsigned int id)
{
	if(isDownloadingTQQShow) return;	
	TQString path = getTQQShowPath();
	if(path == "") return;
	EvaUser *user = EvaMain::user;
	if(!user) return;
	
	qqshowFile.setName(path +"/"+ TQString::number(id) + ".gif" );
	if(qqshowFile.exists()){
		qqshowFile.remove();
	}
	
	if ( !qqshowFile.open( IO_WriteOnly ) ) {
		printf("cannot create the image\n");
		return;
	}

	EvaSetting *sysSetting = EvaMain::global->getEvaSetting();
	if(sysSetting->getConnectType(user->getQQ()) == 2){
		http->setProxyServer( TQHostAddress(sysSetting->getServer( user->getQQ())).toString(), 
					sysSetting->getPort( user->getQQ() ));
		http->setBase64AuthParam( sysSetting->getProxyParam( user->getQQ()));
	}
	http->setHost( "qqshow-user.tencent.com" );
	unsigned int picNum = rand()*100;
	TQString remoteFile = "/"+TQString::number(id) + "/10/00/" + TQString::number(picNum) +".gif";
	downloadID = id;	
	http->get( remoteFile, &qqshowFile  );
}

void EvaImageResource::slotTQQShowDone( bool error )
{
	qqshowFile.close();
	if(error){
		printf("download error: %d\n",error);
		isDownloadingTQQShow = false;
		return;
	}		
	isDownloadingTQQShow = false;
	emit qqShowReady(downloadID);
}

void EvaImageResource::setUserHeadImage(TQMap<unsigned int, TQImage> imageOnList, TQMap<unsigned int, TQImage> imageOffList)
{
	TQMap<unsigned int, TQImage>::Iterator it = imageOnList.begin();
	while(it != imageOnList.end()){
		imgOnList[it.key()] = TQPixmap(it.data());
		++it;
	}
	it = imageOffList.begin();
	while(it != imageOffList.end()){
		imgOffList[it.key()] = TQPixmap(it.data());
		++it;
	}
}

TQPixmap *EvaImageResource::getUserHeadPixmap(const unsigned int id, bool isGrayscale)
{
	TQPixmap * result;
	TQMap<int, TQPixmap>::Iterator it;
	if(isGrayscale){
		it = imgOffList.find(id);
		if(it == imgOffList.end())
			result = NULL;
		else
			result = &(it.data());
	}else{
		it = imgOnList.find(id);
		if(it == imgOnList.end()){
			result = NULL;
		}else
			result = &(it.data());
	}
	return result;
}

void EvaImageResource::addUserHeadImage(const unsigned int id, TQImage imgOn, TQImage imgOff)
{
	imgOnList[id] = TQPixmap(imgOn);
	imgOffList[id] = TQPixmap(imgOff);
}

/*  ---------------------------------------------------------------------------------------------- */

EvaSoundResource::EvaSoundResource()
{
	soundRoot = EvaGlobal::getDirPath() + "/sound";
}

void EvaSoundResource::playNewMessage()
{
	playSound("msg.wav");
}

void EvaSoundResource::playSysMessage()
{
	playSound("system.wav");
}

void EvaSoundResource::playOnlineSound()
{
	playSound("online.wav");
}

void EvaSoundResource::playSound(const TQString &filename)
{
	TQString absPath = soundRoot + "/" + filename;
	TQDir d;
	if(!d.exists(absPath)){
		absPath = EvaGlobal::getDirPath() + "/sound" + "/" + filename;
	}
	
	if(!d.exists(absPath))	return;
	
	KAudioPlayer snd(absPath);
	snd.play();
}

/*  ---------------------------------------------------------------------------------------------- */

TQString EvaGlobal::dirPath = "~/eva";

EvaGlobal::EvaGlobal()
{
	initialize();
}

EvaGlobal::~EvaGlobal()
{
	delete imgResource;
	delete sndResource;
	delete system;
	delete servers;
}

TQString &EvaGlobal::getDirPath() 
{ 
	return dirPath; 
}

const bool EvaGlobal::loadImage()
{
	if(!imgResource) return false;
	return imgResource->loadImage();
}

// const bool EvaGlobal::loadFace()
// {
//         imgResource->loadFace();
// }

/*
const bool EvaGlobal::loadSound()
{
	if(!sndResource) return false;
	return sndResource->loadSound();
}*/

const bool EvaGlobal::loadEvaSetting()
{
	if(!system) return false;
	return system->loadSetting();
}

void EvaGlobal::initialize()
{
	dirPath = TDEGlobal::dirs()->findResource("data", TQString::fromLatin1("eva/servers"));
// 	TQStringList dirs = TDEGlobal::dirs()->findDirs("data", TQString::fromLatin1("eva"));
// 	for(uint i=0; i<dirs.size(); i++){
// 		//printf("dir %i:%s\n", i, dirs[i].ascii());
// 		//dirPath = dirs[0];
// 		break;
// 	}
	if(dirPath == TQString::null){
		TQFileInfo fi;
		fi.setFile(TQString(getenv("_")));
		dirPath = fi.dirPath(true);
	}else
		dirPath = dirPath.left(dirPath.length() - strlen("/servers"));

	//printf("found data path: %s\n", dirPath.ascii());
	initImage();
	initSound();
	initEvaSetting();
	initServers();
}

void EvaGlobal::initImage()
{
	imgResource = new EvaImageResource();
}

void EvaGlobal::initSound()
{
	sndResource = new EvaSoundResource();
}

void EvaGlobal::initEvaSetting()
{
	system = new EvaSetting();
}

void EvaGlobal::initServers( )
{
	servers = new EvaServers(dirPath);
}

const TQSize &EvaGlobal::getFaceSize() const
{
    return faceSize;
}

void EvaGlobal::setFaceSize( const TQSize size)
{
    faceSize = size;
    if(imgResource)
        imgResource->loadFace(faceSize);
}





