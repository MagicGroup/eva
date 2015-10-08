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
  
#ifndef EVAHTMLPARSER_H
#define EVAHTMLPARSER_H

#include "evautil.h"
#include <list>
#include <ntqobject.h>

typedef struct CustomizedPic{
	unsigned char type;  // should be 33, 34, 36, 37, ..     0 means error
	TQString  fileName;
	TQString  shortCutName;
	bool     isExisted;
	int      occurredIndex;
	//TQ_UINT8  sessionID[4];
	TQ_UINT32 sessionID;
	TQ_UINT32 ip;
	TQ_UINT16 port;
	TQ_UINT8  fileAgentKey[16];
	TQString  tmpFileName;
} CustomizedPic;

typedef struct OutCustomizedPic{
	unsigned int imageLength;
	unsigned char md5[16];
	TQString fileName;
} OutCustomizedPic;

class EvaHtmlParser 
{
public:
	EvaHtmlParser(){}
	~EvaHtmlParser(){};
	std::list<CustomizedPic> convertToHtml(TQString &txt, bool isURLOn = true, bool isAbsImgPath = false,
						bool useRealFileName = false);
	const int convertToPlainTxt(TQString &html, TQString &sendFileNameBase);
	void convertToPlainTxt(TQString &html, const unsigned int agentSessionID, 
					const unsigned int agentIP, const unsigned short agentPort );
	std::list<TQString> getCustomImages(const TQString html);
	void parseToAbsPath(TQString &html, const TQString absPath);
	void setAbsImagePath(const TQString &path,const TQString &cachePath = TQString::null) 
				{ absImagePath = path; absCustomCachesPath = cachePath;}
	const TQString getAbsImagePath() const { return absImagePath; }
private:
	TQString absImagePath;
	TQString absCustomCachesPath;
	static unsigned int tmpNum;
	
	std::list< CustomizedPic > picList;
	std::list<CustomizedPic> convertCustomizedPictures(TQString &text, bool useRealFileName = false);
	TQString processPic32( const TQString &src, CustomizedPic * args);
	TQString processPic33( const TQString &src, CustomizedPic *args);
	TQString processPic34( const TQString &src );
	TQString processPic36( const TQString &src, CustomizedPic *args);
	TQString processPic37( const TQString &src );
	
	TQString generateSendFormat(TQString &src, const unsigned int agentSessionID, const unsigned int agentIP, const unsigned short agentPort );
	TQString generateSendFormat32(const TQString sendFileNameBase, const TQString &fileName, const int imgNo);
	//EvaUtil util;
};

#endif
