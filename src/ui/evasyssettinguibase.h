/***************************************************************************
 *   Copyright (C) 2005 by tlmcasper                                          *
 *   tlmcasper@163.com                                                     *
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

#ifndef EVASYSSETTINGUIBASE_H
#define EVASYSSETTINGUIBASE_H

#include <ntqvariant.h>
#include <ntqdialog.h>

#include <ntqlistview.h>
#include "mainlistfontsettinguibase.h"

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQListView;
class TQListViewItem;
class TQWidgetStack;
class TQWidget;
class TQLabel;
class TQTextEdit;
class TQLineEdit;
class TQComboBox;
class TQPushButton;
class TQGroupBox;
class TQToolButton;
class KPushButton;
class TQButtonGroup;
class TQRadioButton;
class TQCheckBox;
class TQSpinBox;
class TQSlider;
class KKeyButton;
class TQFrame;
class TQIconView;
//class MainListFontSettingUIBase;

class EvaSysSettingUIBase : public TQDialog
{
    Q_OBJECT

public:
    EvaSysSettingUIBase( TQWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~EvaSysSettingUIBase();

    TQListView* lvSettingItem;
    TQWidgetStack* wsSetting;
    TQWidget* wspUserInfo;
    TQLabel* lblSignature;
    TQLabel* lblLevel;
    TQLabel* lblLevelDisplay;
    TQTextEdit* teSignature;
    TQLabel* lblAboutMe;
    TQTextEdit* teAboutMe;
    TQLabel* lblRealName;
    TQLabel* lblSchool;
    TQLabel* lblOccupation;
    TQLabel* lblHomePage;
    TQLineEdit* leRealName;
    TQLabel* lblSex;
    TQComboBox* cbSex;
    TQLineEdit* leSchool;
    TQComboBox* cbOccupation;
    TQLineEdit* leHomePage;
    TQLabel* lblAge;
    TQLabel* lblZodiac;
    TQLabel* lblHoroscape;
    TQLabel* lblBlood;
    TQLineEdit* leAge;
    TQComboBox* cbZodiac;
    TQComboBox* cbHoroscape;
    TQComboBox* cbBlood;
    TQLabel* lblNumber;
    TQLabel* lblNickName;
    TQLineEdit* leNickName;
    TQLineEdit* leNumber;
    TQLabel* lblFace;
    TQPushButton* pbChangeFace;
    TQWidget* wspTQQShow;
    TQGroupBox* gbTQQShow;
    TQLabel* lblTQQShow;
    TQToolButton* tbtnHome;
    TQToolButton* tbtnAlbum;
    KPushButton* kpbUpdateShow;
    TQToolButton* tbtnShop;
    TQWidget* wspContact;
    TQGroupBox* gbContact;
    TQButtonGroup* buttonGroup1;
    TQLabel* lblPrompt;
    TQRadioButton* rbPublic;
    TQRadioButton* rbProtect;
    TQRadioButton* rbPrivate;
    TQLineEdit* leMobile;
    TQLineEdit* leEmail;
    TQLabel* lblPhone;
    TQLabel* lblAddress;
    TQLabel* lblEmail;
    TQLineEdit* leAddress;
    TQLabel* lblMobile;
    TQLineEdit* lePhone;
    TQLabel* lblCity;
    TQComboBox* cbArea;
    TQComboBox* cbCity;
    TQLabel* lblProvince;
    TQComboBox* cbProvince;
    TQLabel* lblZipCode;
    TQLineEdit* leZipCode;
    TQLabel* lblArea;
    TQWidget* wspSecurity;

    TQGroupBox* gbPassword;
    TQPushButton* pbChangePassword;
    TQPushButton* pbProtectPassword;

    TQButtonGroup* bgAuthen;
    TQRadioButton* rbAuthNoNeed;
    TQRadioButton* rbAuthNeed;
    TQRadioButton* rbAuthReject;
    TQRadioButton* rbAuthQuest;
    TQFrame *fraQuestion;
    TQLabel *lblQuestion;
    TQLabel *lblAnswer;
    TQComboBox *cbbQuestion;
    TQLineEdit *leAnswer;

    TQWidget* wspBasicSetting;
    TQGroupBox* gbGeneralSetting;
    TQCheckBox* chbOnlineTip;
    TQCheckBox* chbShowOnlineUsers;
    TQCheckBox* chbSound;
    TQCheckBox* chbMessage;
    TQCheckBox* chbSystemBroadcast;
    TQCheckBox* chbSystemNews;

    TQCheckBox* chbSendKey;
    TQCheckBox* chbShowNickSmiley;
    TQCheckBox* chbShowSigSeperate;
    TQGroupBox* gbOtherSetting;
    TQLabel* lblPageSize;
    TQSpinBox* sbPageSize;
    TQLabel* lblPageSizeEnd;
    TQLabel* lblIdleTime;
    TQSpinBox* sbIdleTime;
    TQLabel* lblIdleTimeEnd;
    TQLabel* lblFaceSize;
    TQLabel* lblFaceSmall;
    TQSlider* sliderFaceSize;
    TQLabel* lblFaceBig;
    TQLabel* lblShortKey;
    KKeyButton* kkbtnShortKey;
    TQWidget* wspResource;
    TQGroupBox* gbPath;
    TQLabel* lblThemePath;
    TQLineEdit* leThemePath;
    TQPushButton* pbTheme;
    TQLabel* lblSoundPath;
    TQLineEdit* leSoundPath;
    TQPushButton* pbSound;
    TQWidget* wspReply;
    TQGroupBox* gbQuickReply;
    TQComboBox* cbbQuickNo;
    TQTextEdit* teQuickMessage;
    TQPushButton* pbQuickNew;
    TQPushButton* pbQuickDelete;
    TQGroupBox* gbAutoReply;
    TQComboBox* cbbAutoNo;
    TQCheckBox* chbAutoReply;
    TQTextEdit* teAutoMessage;
    TQPushButton* pbAutoNew;
    TQPushButton* pbAutoDelete;
    TQPushButton* pbFaceDefault;
    TQPushButton* pbOk;
    TQPushButton* pbApply;
    TQPushButton* pbCancel;
    
    TQIconView* ivFace;

    MainListFontSettingUIBase *wspMainFont;
protected:
    TQGridLayout* EvaSysSettingUIBaseLayout;
    TQVBoxLayout* layout57;
    TQHBoxLayout* layout55;
    TQGridLayout* wspUserInfoLayout;
    TQSpacerItem* spacer37;
    TQGridLayout* layout44;
    TQGridLayout* layout43;
    TQVBoxLayout* layout41;
    TQSpacerItem* spacer15;
    TQHBoxLayout* layout70;
    TQHBoxLayout* layout61;
    TQSpacerItem* spacer16;
    TQHBoxLayout* layout73;
    TQVBoxLayout* layout72;
    TQSpacerItem* spacer17;
    TQHBoxLayout* layout56;
    TQHBoxLayout* layout55_2;
    TQVBoxLayout* layout54;
    TQVBoxLayout* layout53;
    TQHBoxLayout* layout52;
    TQHBoxLayout* layout68;
    TQVBoxLayout* layout66;
    TQVBoxLayout* layout67;
    TQHBoxLayout* layout46;
    TQVBoxLayout* layout45;
    TQGridLayout* layout36;
    TQSpacerItem* spacer13;
    TQSpacerItem* spacer10;
    TQGridLayout* wspTQQShowLayout;
    TQSpacerItem* spacer18;
    TQSpacerItem* spacer17_2;
    TQGridLayout* layout13;
    TQSpacerItem* spacer6;
    TQGridLayout* layout12;
    TQSpacerItem* spacer5;
    TQSpacerItem* spacer7;
    TQSpacerItem* spacer8;
    TQGridLayout* wspContactLayout;
    TQSpacerItem* spacer29;
    TQSpacerItem* spacer30;
    TQGridLayout* layout48;
    TQSpacerItem* spacer28;
    TQGridLayout* buttonGroup1Layout;
    TQHBoxLayout* layout54_2;
    TQGridLayout* layout56_2;
    TQGridLayout* layout57_2;
    TQGridLayout* wspSecurityLayout;
    TQSpacerItem* spacer32;
    TQSpacerItem* spacer33;
    TQVBoxLayout* layout53_2;

    TQGridLayout* authButtonLayout;
    TQVBoxLayout* layout49;
    TQGridLayout* wspBasicSettingLayout;
    TQSpacerItem* spacer15_2;
    TQSpacerItem* spacer16_2;
    TQVBoxLayout* layout48_2;
    TQHBoxLayout* layout47;
    TQVBoxLayout* layout45_2;
    TQVBoxLayout* layout46_2;
    TQVBoxLayout* layout52_3;
    TQHBoxLayout* layout44_2;
    TQHBoxLayout* layout_idt;
    TQHBoxLayout* layout45_3;
    TQHBoxLayout* layout51_2;
    TQSpacerItem* spacer19;
    TQGridLayout* wspResourceLayout;
    TQSpacerItem* spacer19_2;
    TQSpacerItem* spacer20_2;
    TQVBoxLayout* layout59;
    TQGridLayout* layout56_3;
    TQSpacerItem* spacer20;
    TQHBoxLayout* layout55_3;
    TQGridLayout* layout57_3;
    TQSpacerItem* spacer21;
    TQHBoxLayout* layout101;
    TQGridLayout* wspReplyLayout;
    TQSpacerItem* spacer26;
    TQSpacerItem* spacer27;
    TQGridLayout* layout44_3;
    TQVBoxLayout* layout43_2;
    TQHBoxLayout* layout40;
    TQSpacerItem* spacer24;
    TQHBoxLayout* layout42;
    TQVBoxLayout* layout41_2;
    TQSpacerItem* spacer25;
    TQVBoxLayout* layout39;
    TQHBoxLayout* layout32;
    TQSpacerItem* spacer21_2;
    TQHBoxLayout* layout38;
    TQVBoxLayout* layout37;
    TQSpacerItem* spacer23;
    TQHBoxLayout* layout54_3;
    TQSpacerItem* spacer34;

    TQVBoxLayout* layoutQuestLbl;
    TQVBoxLayout* layoutQuestContents;
    TQHBoxLayout* layoutHQuest;
    TQVBoxLayout* layoutQuest;

    TQVBoxLayout* layoutPwd;
    TQVBoxLayout* layoutPwButton;
protected slots:
    virtual void languageChange();

};

class EvaSettingListItem : public TQListViewItem
{
public:
	EvaSettingListItem(  TQListView* parent, TQListViewItem* after, int index );
	EvaSettingListItem(  TQListViewItem* parent, TQListViewItem* after, int index );
	~EvaSettingListItem();
	
	int itemIndex;
};

#endif // EVASYSSETTINGUIBASE_H
