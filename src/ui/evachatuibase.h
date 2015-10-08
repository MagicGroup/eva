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

#ifndef EVACHATUIBASE_H
#define EVACHATUIBASE_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQToolButton;
class TQLabel;
class TQLineEdit;
class EvaTextEdit;
class EvaChatView;
class TQPushButton;
class TQSplitter;
class TQFrame;
class EvaFilePanel;

class EvaChatUIBase : public TQWidget
{
	Q_OBJECT

public:
	EvaChatUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
	~EvaChatUIBase();
	
	TQToolButton* tbBuddy;
	TQLabel* lblIP;
	TQLineEdit* leIP;
	TQLabel* lblSignature;
	EvaChatView *chatDisplay;
	TQWidget *lowerLayoutWidget;
	TQToolButton* tbSmiley;
	TQToolButton* tbFont;
	TQToolButton* tbFile;
	TQToolButton* tbB;
	TQToolButton* tbU;
	TQToolButton* tbI;
	TQToolButton* tbAddImage;
	TQToolButton* tbScreenShot;
	TQToolButton* tbQuickReply;
	TQToolButton* tbHideShows;
	TQToolButton* tbEnableSound;
	EvaTextEdit* kteInput;
	TQPushButton* pbHistory;
	TQPushButton* pbClose;
	TQPushButton* pbSend;
	TQPushButton* pbSendKey;
	TQFrame *m_ShowFrame;
	TQLabel* lblBuddyShow;
	TQToolButton* tbShowBuddy;
	TQLabel* lblMeShow;
	TQToolButton* tbShowMe;
	TQSplitter* splitter;

	EvaFilePanel *m_FilePanel;
	TQFrame *m_FilePanelFrame;

protected:
	//TQGridLayout* EvaChatUIBaseLayout;
	TQHBoxLayout* EvaChatUIBaseLayout;
	TQVBoxLayout* layout5;
	TQHBoxLayout* layout4;
	TQHBoxLayout* layout3;
	TQSpacerItem* spcTootBtn1;
	TQSpacerItem* spcToolBtn2;
	TQSpacerItem* spcToolBtn3;
	TQHBoxLayout* layout2;
	TQSpacerItem* spcBottom;
	TQVBoxLayout* layout19;
	TQSpacerItem* spacer12;
	TQSpacerItem* spacer10;
	TQVBoxLayout* lowerLayout;
	TQVBoxLayout* m_ShowLayout;
	TQVBoxLayout* m_FilePanelLayout;

protected slots:
	virtual void languageChange();

};

#endif
