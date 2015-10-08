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

#ifndef EVACHATVIEW_H
#define EVACHATVIEW_H

#include <tdehtmlview.h>
#include <tdehtml_part.h>
#include <kurl.h>
#include <ntqdatetime.h>
#include <ntqcolor.h>

class TDEPopupMenu;
class MenuPrivateData;
//class TDEAction;

class EvaChatView : public TDEHTMLPart
{
	Q_OBJECT
public:
	EvaChatView(TQWidget* parent = 0, const char* name = 0);
	virtual ~EvaChatView();
	void append(TQString & nick, TQDateTime time, TQColor nameColor, bool isNormal, 
			TQColor msgColor, TQ_UINT8 size, 
			bool underline, bool italic, bool bold, TQString contents );
	void updatePicture( const TQString filename , const TQString tmpFileName);
	void showInfomation(const TQString &info);
	void showFileNotification(const TQString &who, const TQString &filename, const int size, 
				const unsigned int session, const bool isSend = false);
	void askResumeMode(const TQString filename, const unsigned int session);
	void showContents();
signals:
	void saveAsCustomSmiley(TQString ); // full name with absolute path
	void fileTransferAcceptRequest(const unsigned int session);
	void fileTransferSaveAsRequest(const unsigned int session);
	void fileTransferCancelRequest(const unsigned int session);
	void fileTransferResume(const unsigned int session, const bool isResume);
protected:
	virtual void startDrag();
private:
		
	TQString wrapFontAttributes(TQColor color, TQ_UINT8 size, 
					bool underline, bool italic, bool bold, TQString contents);
	TQString wrapNickName(TQString &nick, TQDateTime time, TQColor color, bool isNormal);
	
	TDEPopupMenu *menu;
	MenuPrivateData *d;
	TDEAction *copyAction;
	TQString buffer;
	bool m_isScrollAtBottom;
	void updateContents(const TQString &contents);
	static const TQString protocolAccept;
	static const TQString protocolSaveAs;
	static const TQString protocolCancel;
	static const TQString protocolResume;
	static const TQString protocolNewOne;
private slots:
	void slotScrollToBottom();

	void slotPopupMenu(const TQString &url, const TQPoint &point);

	void slotSelectionChanged();
	void slotLinkClicked( const KURL & urls, const KParts::URLArgs &);
	void copy();
	void searchProvider();
	void openSelection();
	void slotCopyLinkLocation();
	void slotCopyImage();
	void slotSaveImageAs();
	void slotSaveAsCustomSmiley();
};
#endif

