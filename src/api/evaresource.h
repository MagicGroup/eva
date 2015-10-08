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

#ifndef EVARESOURCE_H 
#define EVARESOURCE_H

#include <ntqobject.h>
#include <ntqfile.h>
#include <ntqmap.h>
#include <ntqpixmap.h>
#include <ntqimage.h>
#include <ntqmovie.h>
#include <ntqsize.h>

#ifndef MaxFaceNumber
//#define MaxFaceNumber 117
#define MaxFaceNumber 134
#endif

class EvaSetting;
class EvaServers;
class EvaHttp;
class EvaImageResource : public TQObject
{
	Q_OBJECT
public:
	EvaImageResource();
	~EvaImageResource();
	
	
	const TQString getFacePath() const;
	const TQString getIconPath() ;
	const TQString getSmileyPath() const;
	const TQString getTQQShowPath() const;
	
	const int getFaceID(const int fileIndex) const ;
	const int getFaceFileIndex(const int faceId);
	TQPixmap *getFace(const int fileIndex, const bool on = true);
	TQPixmap *getFaceByID( const unsigned short faceId, const bool on = true);
	TQPixmap *getIcon(TQString name);
	const TQString getIconFullPath(TQString name);
	const TQString getSmiley(const int fileIndex);
	
	const TQMovie *getLoginMovie();
	
	const bool loadImage();
	const TQString &getImageRootPath() const { return imageRoot; }
	void setImageRootPath( TQString &path) { imageRoot = path; }
	
	const TQString getThemePath() const { return themePath; }
	void setThemePath( const TQString &path) { themePath = path; }

	TQPixmap *getTQQShow(const unsigned int id);
	void setUserHeadImage(TQMap<unsigned int, TQImage> imageOnList, TQMap<unsigned int, TQImage> imageOffList);
	void addUserHeadImage(const unsigned int id, TQImage imgOn, TQImage imgOff);
	TQPixmap *getUserHeadPixmap(const unsigned int id, bool isGrayscale = false);
signals:
	void qqShowReady(const unsigned int);
public slots:	
	void requestTQQShow(const unsigned int id);	
private:
	bool loadFace(const TQSize &size);
	bool loadIcon();
	bool loadSmiley();
	TQMap<TQString, TQPixmap> faceList;
	TQMap<TQString, TQPixmap> iconList;
	TQMap<TQString, TQString> iconFileNameMap;
	TQMap<TQString, TQMovie> smileyList;
	TQMap<int, TQPixmap> imgOnList;
	TQMap<int, TQPixmap> imgOffList;
	TQMovie loginMng;
	int faceId[MaxFaceNumber];  // store faceID, index is the fileID
	TQString imageRoot;
	TQString themePath;
	TQSize faceSize;
	
	bool isDownloadingTQQShow;
	int downloadID;
	TQFile qqshowFile;
	TQString qqshowFilename;
	EvaHttp *http;
	
private slots:
	void slotTQQShowDone(bool error);

private:
	friend class EvaGlobal;
};

class EvaSoundResource
{
public:
	EvaSoundResource();
	~EvaSoundResource(){}
	//const bool loadSound(){ return false; }
	void playNewMessage();
	void playSysMessage();
	void playOnlineSound();
	void setSoundDir(const TQString &path) { soundRoot = path; }
	const TQString &getSoundDir() const { return soundRoot; }
private:
	void playSound(const TQString &filename);
	TQString soundRoot;
};

class EvaGlobal
{
public:
	EvaGlobal();
	virtual ~EvaGlobal();
	
	static TQString &getDirPath();
	const bool loadImage();
        //const bool loadFace();
	//const bool loadSound();
	const bool loadEvaSetting();
	
	EvaImageResource *getImageResource() { return imgResource;}
	EvaSoundResource *getSoundResource() { return sndResource;}
	EvaSetting *getEvaSetting() { return system; }
	EvaServers *getEvaServers() { return servers; }
	
	const TQSize &getFaceSize() const;
	void setFaceSize( const TQSize size);
private:
	void initialize();
	void initImage();
	void initSound();
	void initEvaSetting();
	void initServers();
	
	static TQString dirPath;
	EvaSetting *system;
	EvaServers *servers;
	EvaImageResource *imgResource;
	EvaSoundResource *sndResource;
	TQSize faceSize;
};

#endif
