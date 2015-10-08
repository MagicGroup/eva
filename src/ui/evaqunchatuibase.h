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

#ifndef EVATQUNCHATUIBASE_H
#define EVATQUNCHATUIBASE_H

#include <ntqvariant.h>
#include <ntqwidget.h>
#include <ntqtextedit.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQToolButton;
class TQPushButton;
class TQFrame;
class KSqueezedTextLabel;
class TQLabel;
class EvaTextEdit;
class EvaChatView;
class TQListView;
class EvaQunListView;
class TQSplitter;

class EvaQunChatUIBase : public TQWidget
{
	Q_OBJECT

public:
	EvaQunChatUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
	~EvaQunChatUIBase();
	
	TQToolButton* tbQunDetails;
	EvaChatView* chatDisplay;
	TQWidget *lowerLayoutWidget;
	TQToolButton* tbSmiley;
	TQToolButton* tbFont;
	TQToolButton* tbB;
	TQToolButton* tbU;
	TQToolButton* tbI;
	TQToolButton* tbImageFile;
	TQToolButton* tbScreenShot;
	TQToolButton* tbQuickReply;
	TQToolButton* tbEnableSound;
	EvaTextEdit* teInput;
	TQPushButton* pbHistory;
	TQPushButton* pbClose;
	TQPushButton* pbSend;
	TQPushButton* pbSendKey;
	TQFrame* frmNotice;
	TQToolButton* tbtnNotice;
	TQTextEdit *teNotice;
	TQFrame *frmMembers;
	TQLabel* lblMembers;
	EvaQunListView* memberList;
	TQSplitter *memberSplitter;
	TQSplitter *splitter;

protected:
	TQGridLayout* EvaQunChatUIBaseLayout;
	TQHBoxLayout* layout16;
	TQVBoxLayout* layout15;
	TQHBoxLayout* layout6;
	TQSpacerItem* spacer4;
	TQHBoxLayout* layout14;
	TQSpacerItem* spacer2;
	TQSpacerItem* spacer3;
	TQSpacerItem* spacer5;
	TQHBoxLayout* layout3;
	TQSpacerItem* spacer1;
	TQVBoxLayout* layout12;
	TQGridLayout* frmNoticeLayout;
	TQVBoxLayout* frmMemberLayout;
	TQVBoxLayout* layout4;
	TQVBoxLayout* lowerLayout;

protected slots:
	virtual void languageChange();

};

#endif // EVATQUNCHATUIBASE_H
