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
#ifndef TQUNDETAILSUI_H
#define TQUNDETAILSUI_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQLabel;
class TQTabWidget;
class TQLineEdit;
class TQToolButton;
class TQGroupBox;
class TQTextEdit;
class TQButtonGroup;
class TQRadioButton;
class TQTable;
class TQPushButton;
class TQComboBox;
class TQFrame;

class QunDetailsUI : public TQWidget
{
    Q_OBJECT

public:
    QunDetailsUI( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QunDetailsUI();

    TQLabel* lblLogo;
    TQTabWidget* tabWMain;
    TQWidget* tabDetails;
    TQLabel* lblID;
    TQLabel* lblCreator;
    TQLabel* lblName;
    TQLineEdit* leQunID;
    TQLineEdit* leCreator;
    TQLineEdit* leQunName;
    TQLabel* lblQunFace;
    TQLabel* lblCategory;
    TQToolButton* tbCategory;
    TQGroupBox* gbNotice;
    TQTextEdit* teNotice;
    TQGroupBox* gbDescription;
    TQTextEdit* teDescription;
    TQButtonGroup* bgAuthen;
    TQRadioButton* rbNoAuthenNeed;
    TQRadioButton* rbNeedAuthen;
    TQRadioButton* rbRejectAnyone;
    TQWidget* tabMember;
    TQTable* tblMembers;
    TQPushButton* pbSetMembers;
    TQPushButton* pbAddToMe;
    TQPushButton* pbDelMembers;
    TQPushButton* pbSetAdmin;
    TQPushButton* pbUnsetAdmin;
    TQPushButton* pbTransfer;
    TQWidget* tabSetting;
    TQButtonGroup* bgSettings;
    TQRadioButton* rbRecord_Show;
    TQRadioButton* rbPopupWindow;
    TQRadioButton* rbDisplayNumbers;
    TQRadioButton* rbRecord_only;
    TQRadioButton* rbRejectMsgs;
    TQWidget* TabCard;
    TQLabel* lblMyName;
    TQLabel* lblMyGender;
    TQLabel* lblMyPhone;
    TQLabel* lblMyEmail;
    TQLineEdit* leMyName;
    TQComboBox* cbbMyGender;
    TQLineEdit* leMyPhone;
    TQLineEdit* leMyEmail;
    TQFrame* line1;
    TQLabel* lblMyComment;
    TQTextEdit* teMyMemo;
    TQPushButton* pbUpdate;
    TQPushButton* pbClose;

protected:
    TQVBoxLayout* QunDetailsUILayout;
    TQHBoxLayout* layout18;
    TQVBoxLayout* tabDetailsLayout;
    TQHBoxLayout* layout17;
    TQVBoxLayout* layout1;
    TQVBoxLayout* layout2;
    TQVBoxLayout* layout25;
    TQHBoxLayout* layout5;
    TQSpacerItem* spacer1;
    TQHBoxLayout* layout24;
    TQGridLayout* gbNoticeLayout;
    TQGridLayout* gbDescriptionLayout;
    TQVBoxLayout* bgAuthenLayout;
    TQGridLayout* tabMemberLayout;
    TQHBoxLayout* layout17_2;
    TQVBoxLayout* layout16;
    TQSpacerItem* spacer6;
    TQSpacerItem* spacer7;
    TQGridLayout* tabSettingLayout;
    TQVBoxLayout* bgSettingsLayout;
    TQVBoxLayout* TabCardLayout;
    TQHBoxLayout* layout19;
    TQVBoxLayout* layout11;
    TQVBoxLayout* layout18_2;
    TQHBoxLayout* layout17_3;
    TQSpacerItem* spacer4;
    TQHBoxLayout* layout20;
    TQSpacerItem* spacer5;
    TQHBoxLayout* layout21;
    TQVBoxLayout* layout15;
    TQSpacerItem* spacer3;
    TQHBoxLayout* layout9;
    TQSpacerItem* spacer2;

protected slots:
    virtual void languageChange();

};

#endif // TQUNDETAILSUI_H
