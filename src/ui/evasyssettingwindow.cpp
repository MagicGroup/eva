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
 /*
	revised by tlmcasper 2005
	tlmcasper@163.com
*/
#include "evasyssettingwindow.h"
#include "evaresource.h"
#include "evausersetting.h"

#include "../evamain.h"
#include "evapacket.h"
#include "evauser.h"
#include "evautil.h"

#include <ntqcombobox.h>
#include <ntqpushbutton.h>
#include <ntqslider.h>
#include <ntqtextedit.h>
#include <ntqlineedit.h>
#include <ntqspinbox.h>
#include <ntqcheckbox.h>
#include <ntqlabel.h>
#include <ntqfiledialog.h>
#include <tdelocale.h>
#include <inttypes.h>

#include <ntqlistview.h>
#include <ntqheader.h>
#include <ntqwidgetstack.h>
#include <ntqiconview.h>
#include <ntqradiobutton.h>
#include <ntqtextcodec.h>
#include <ntqtimer.h>
#include <ntqtoolbutton.h>
#include <krun.h>
#include <kpushbutton.h>
#include <kcolorcombo.h>
#include <tdemessagebox.h>
#include <kapp.h>

EvaImageResource *EvaSysSettingWindow::faces = NULL;
EvaSysSettingWindow::EvaSysSettingWindow( TQStringList &user, EvaImageResource * res, EvaUserSetting * setting , TQWidget *parent)
	: EvaSysSettingUIBase(parent, 0, WType_Dialog | WShowModal),
	details(user), selectedFaceIndex(0), isSignatureChanged(false)
{
	userSetting = setting;
	lvSettingItem->setSorting( -1 ); //make the listview do NOT Sort
	lvSettingItem->header()->setHidden( TRUE );//make the listview title hidden
	
	pbFaceDefault->hide();
		
	faces = res; //faces is a pointer of EvaImageResource
	setupFaces();
	
	loadSetting();
	slotCbbAutoNoActivated(0);
	slotCbbQuickNoActivated(0);
	slotAuthChanged();

	TQObject::connect(pbFaceDefault, SIGNAL(clicked()), SLOT(slotPbFaceDefaultClicked()));
	
	TQObject::connect(pbApply, SIGNAL(clicked()), SLOT(slotPbApplyClicked()));
	TQObject::connect(pbCancel, SIGNAL(clicked()), SLOT(close()));
	TQObject::connect(pbOk, SIGNAL(clicked()), SLOT(slotPbOKClicked()));
	TQObject::connect(sliderFaceSize, SIGNAL(valueChanged(int)), SLOT(slotFaceSizeChanged(int)));
	
	TQObject::connect(kkbtnShortKey, SIGNAL(capturedShortcut(const TDEShortcut &)), SLOT(slotCapturedShortcut(const TDEShortcut &)));
	
	TQObject::connect(pbTheme, SIGNAL(clicked()), SLOT(slotPbThemeClicked()));
	TQObject::connect(pbSound, SIGNAL(clicked()), SLOT(slotPbSoundClicked()));
	
	TQObject::connect(cbbAutoNo, SIGNAL(activated(int)), SLOT(slotCbbAutoNoActivated(int)));
	TQObject::connect(pbAutoNew, SIGNAL(clicked()), SLOT(slotPbAutoNewClicked()));
	TQObject::connect(pbAutoDelete, SIGNAL(clicked()), SLOT(slotPbAutoDeleteClicked()));
	TQObject::connect(teAutoMessage, SIGNAL(textChanged()), SLOT(slotTeAutoTextChanged()));
	
	TQObject::connect(cbbQuickNo, SIGNAL(activated(int)), SLOT(slotCbbQuickNoActivated(int)));
	TQObject::connect(pbQuickNew, SIGNAL(clicked()), SLOT(slotPbQuickNewClicked()));
	TQObject::connect(pbQuickDelete, SIGNAL(clicked()), SLOT(slotPbQuickDeleteClicked()));
	TQObject::connect(teQuickMessage, SIGNAL(textChanged()), SLOT(slotTeQuickTextChanged()));
	
	//connect ListView to the WidgetStack,add by casper
	TQObject::connect(lvSettingItem, SIGNAL(clicked(TQListViewItem *)), SLOT(slotSettingListItemClicked(TQListViewItem *)));
	//click face button then show the IconView
	TQObject::connect(pbChangeFace,SIGNAL(clicked()),SLOT(slotPbFaceClicked()));
	//double click the face Icon in the IconView
	TQObject::connect( ivFace, SIGNAL( doubleClicked(TQIconViewItem*) ), SLOT( FaceChoose(TQIconViewItem*) ) );
	//if the text of signature changed
	TQObject::connect( teSignature, SIGNAL(textChanged()), SLOT(slotSignatureChanged()));
	
	//TQQShow
	TQObject::connect( tbtnShop, SIGNAL( clicked() ),  SLOT( slotShopClicked() ) );
	TQObject::connect( tbtnAlbum, SIGNAL( clicked() ),  SLOT( slotAlbumClicked() ) );
	TQObject::connect( tbtnHome, SIGNAL( clicked() ),  SLOT( slotHomeClicked() ) );
	TQObject::connect( kpbUpdateShow, SIGNAL( clicked() ),  SLOT( slotUpdateTQQShow() ) );
	
	//the following connection check if anything of Setting Item changed ,then make apply enable;
	TQObject::connect( leNickName, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( leRealName, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( leAge, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( leSchool, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( leHomePage, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( teSignature, SIGNAL(textChanged()), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( teAboutMe, SIGNAL(textChanged()), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( ivFace, SIGNAL( doubleClicked(TQIconViewItem*) ), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( cbSex, SIGNAL( activated( int )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( cbOccupation, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( cbZodiac, SIGNAL( activated( int )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( cbHoroscape, SIGNAL( activated( int )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( cbBlood, SIGNAL( activated( int )), SLOT( slotUserInfoChanged() ) );
	
	TQObject::connect( cbArea, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( cbProvince, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( cbCity, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( leZipCode, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( leEmail, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( leAddress, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( lePhone, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( leMobile, SIGNAL( textChanged( const TQString & )), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( rbPublic, SIGNAL( clicked() ), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( rbProtect, SIGNAL( clicked() ), SLOT( slotUserInfoChanged() ) );
	TQObject::connect( rbPrivate, SIGNAL( clicked() ), SLOT( slotUserInfoChanged() ) );
	
	TQObject::connect( pbChangePassword, SIGNAL(clicked()), SLOT(slotChangePasswordClicked()));
	TQObject::connect( pbProtectPassword, SIGNAL(clicked()), SLOT(slotProtectPasswordClicked()));
	TQObject::connect( rbAuthNoNeed, SIGNAL( clicked() ), SLOT( slotAuthChanged() ) );
	TQObject::connect( rbAuthNeed, SIGNAL( clicked() ), SLOT( slotAuthChanged() ) );
	TQObject::connect( rbAuthReject, SIGNAL( clicked() ), SLOT( slotAuthChanged() ) );
	TQObject::connect( rbAuthQuest, SIGNAL( clicked() ), SLOT( slotAuthChanged() ) );
	TQObject::connect( cbbQuestion, SIGNAL( textChanged( const TQString & ) ), SLOT( slotAuthChanged() ) );
	TQObject::connect( leAnswer, SIGNAL( textChanged( const TQString & ) ), SLOT( slotAuthChanged() ) );
	
	
	TQObject::connect( chbOnlineTip, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( chbMessage, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( chbShowOnlineUsers, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( chbSystemBroadcast, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( chbSystemNews, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( chbSound, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( chbSendKey, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( chbShowNickSmiley, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( chbShowSigSeperate, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( sbPageSize, SIGNAL( valueChanged( int ) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( sbIdleTime, SIGNAL( valueChanged( int ) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( sliderFaceSize, SIGNAL( valueChanged( int )  ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( kkbtnShortKey, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	
	TQObject::connect( leThemePath, SIGNAL( textChanged( const TQString & )), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( leSoundPath, SIGNAL( textChanged( const TQString & )), SLOT( slotSysSettingChanged() ) );
	
	TQObject::connect( chbAutoReply, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( pbAutoNew, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( pbAutoDelete, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( pbQuickNew, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( pbQuickDelete, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );

	TQObject::connect( wspMainFont->kcbbBuddyNickColor, SIGNAL( activated(int) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbBuddyNickFontB, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbBuddyNickFontU, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbBuddyNickFontI, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->kcbbBuddyFlashColor, SIGNAL( activated(int) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbBuddyFlashFontB, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbBuddyFlashFontU, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbBuddyFlashFontI, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->kcbbBuddySigColor, SIGNAL( activated(int) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbBuddySigFontB, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbBuddySigFontU, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbBuddySigFontI, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );

	TQObject::connect( wspMainFont->kcbbQunNameColor, SIGNAL( activated(int) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbQunNameFontB, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbQunNameFontU, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbQunNameFontI, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->kcbbQunFlashColor, SIGNAL( activated(int) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbQunFlashFontB, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbQunFlashFontU, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbQunFlashFontI, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );

	TQObject::connect( wspMainFont->kcbbGroupNameColor, SIGNAL( activated(int) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbGroupNameFontB, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbGroupNameFontU, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbGroupNameFontI, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->kcbbGroupFlashColor, SIGNAL( activated(int) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbGroupFlashFontB, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbGroupFlashFontU, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbGroupFlashFontI, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->kcbbGroupOnlineColor, SIGNAL( activated(int) ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbGroupOnlineFontB, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbGroupOnlineFontU, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );
	TQObject::connect( wspMainFont->chbGroupOnlineFontI, SIGNAL( clicked() ), SLOT( slotSysSettingChanged() ) );

	
	//setup Icon of TQQShow 
	if(faces){
		TQPixmap *icon = faces->getIcon("TQQ_SHOP");
		if(icon)
			tbtnShop->setIconSet(TQIconSet(*icon));
	} 
	if(faces){
		TQPixmap *icon = faces->getIcon("TQQ_ALBUM");
		if(icon)
			tbtnAlbum->setIconSet(TQIconSet(*icon));
	}
	if(faces){
		TQPixmap *icon = faces->getIcon("TQQ_HOME");
		if(icon)
			tbtnHome->setIconSet(TQIconSet(*icon));
	}
	//show user info in User Info Window
	UpdateData(true); 
	if(details.size()!=37) {
		TQTimer::singleShot(500, this, SLOT(slotFirstUpdate()));
	}
	
	pbApply->setEnabled( FALSE );
	isUserInfoChanged = FALSE;
	isSysSettingChanged = FALSE;
	isFaceSizeChanged = FALSE;
	isSignatureChanged = false;
	m_IsAuthQuestionChanged = false;
}

EvaSysSettingWindow::~ EvaSysSettingWindow( )
{
}

void EvaSysSettingWindow::saveSetting( )
{
	userSetting->setShowBudyOnlineNotifyEnabled(chbOnlineTip->isChecked());
	userSetting->setShowMessageTipEnabled(chbMessage->isChecked());
	userSetting->setShowOnlineEnabled(chbShowOnlineUsers->isChecked());
	userSetting->setShowSystemBroadcastEnabled(chbSystemBroadcast->isChecked());
	userSetting->setShowSystemNewsEnabled(chbSystemNews->isChecked());
	userSetting->setSoundEnabled(chbSound->isChecked());
	userSetting->setShowSmileyInNickName( chbShowNickSmiley->isChecked());
	userSetting->setShowSignatureInSeperateLine( chbShowSigSeperate->isChecked());
	userSetting->setSendKeyEnterEnabled(chbSendKey->isChecked());
	
	userSetting->setFaceSize(TQSize(sliderFaceSize->value(), sliderFaceSize->value()));
	userSetting->setPageSize(sbPageSize->value());
	
	userSetting->setMessageShortcut(kkbtnShortKey->shortcut());

	userSetting->setBuddyNameColor( wspMainFont->kcbbBuddyNickColor->color() );
	userSetting->setBuddyNameBold( wspMainFont->chbBuddyNickFontB->isChecked() );
	userSetting->setBuddyNameUnderline( wspMainFont->chbBuddyNickFontU->isChecked()  );
	userSetting->setBuddyNameItalic( wspMainFont->chbBuddyNickFontI->isChecked()  );
	userSetting->setBuddyFlashColor( wspMainFont->kcbbBuddyFlashColor->color()  );
	userSetting->setBuddyFlashBold( wspMainFont->chbBuddyFlashFontB->isChecked()  );
	userSetting->setBuddyFlashUnderline( wspMainFont->chbBuddyFlashFontU->isChecked()  );
	userSetting->setBuddyFlashItalic( wspMainFont->chbBuddyFlashFontI->isChecked()  );
	userSetting->setBuddySigColor( wspMainFont->kcbbBuddySigColor->color()  );
	userSetting->setBuddySigBold( wspMainFont->chbBuddySigFontB->isChecked()   );
	userSetting->setBuddySigUnderline( wspMainFont->chbBuddySigFontU->isChecked()   );
	userSetting->setBuddySigItalic( wspMainFont->chbBuddySigFontI->isChecked()   );

	userSetting->setQunNameColor( wspMainFont->kcbbQunNameColor->color()  );
	userSetting->setQunNameBold( wspMainFont->chbQunNameFontB->isChecked()   );
	userSetting->setQunNameUnderline( wspMainFont->chbQunNameFontU->isChecked()   );
	userSetting->setQunNameItalic( wspMainFont->chbQunNameFontI->isChecked()   );
	userSetting->setQunFlashColor( wspMainFont->kcbbQunFlashColor->color()  );
	userSetting->setQunFlashBold( wspMainFont->chbQunFlashFontB->isChecked()   );
	userSetting->setQunFlashUnderline( wspMainFont->chbQunFlashFontU->isChecked()   );
	userSetting->setQunFlashItalic( wspMainFont->chbQunFlashFontI->isChecked()   );

	userSetting->setGroupNameColor( wspMainFont->kcbbGroupNameColor->color()  );
	userSetting->setGroupNameBold( wspMainFont->chbGroupNameFontB->isChecked()  );
	userSetting->setGroupNameUnderline( wspMainFont->chbGroupNameFontU->isChecked()  );
	userSetting->setGroupNameItalic( wspMainFont->chbGroupNameFontI->isChecked() );
	userSetting->setGroupFlashColor( wspMainFont->kcbbGroupFlashColor->color()  );
	userSetting->setGroupFlashBold( wspMainFont->chbGroupFlashFontB->isChecked()  );
	userSetting->setGroupFlashUnderline( wspMainFont->chbGroupFlashFontU->isChecked()  );
	userSetting->setGroupFlashItalic( wspMainFont->chbGroupFlashFontI->isChecked()  );
	userSetting->setGroupCountColor( wspMainFont->kcbbGroupOnlineColor->color()  );
	userSetting->setGroupOnlineCountBold( wspMainFont->chbGroupOnlineFontB->isChecked()  );
	userSetting->setGroupOnlineCountUnderline( wspMainFont->chbGroupOnlineFontU->isChecked()  );
	userSetting->setGroupOnlineCountItalic( wspMainFont->chbGroupOnlineFontI->isChecked()  );

	
	userSetting->setThemeDir(leThemePath->text());
	userSetting->setSoundDir(leSoundPath->text());
	//userSetting->setShowOnlineEnabled(false);
	
	userSetting->setAutoReplyList(autoList);
	userSetting->setQuickReplyList(tquickList);
	userSetting->setIdleMaxTime(sbIdleTime->value());
	
	userSetting->saveSettings();
	emit settingChanged();
}

void EvaSysSettingWindow::loadSetting( const bool isLoadDefault)
{	
	chbOnlineTip->setChecked(userSetting->isShowBudyOnlineNotifyEnabled());
	chbMessage->setChecked(userSetting->isShowMessageTipEnabled());
	chbShowOnlineUsers->setChecked(userSetting->isShowOnlineEnabled());
	chbSystemBroadcast->setChecked(userSetting->isShowSystemBroadcastEnabled());
	chbSystemNews->setChecked(userSetting->isShowSystemNewsEnabled());
	chbSound->setChecked(userSetting->isSoundEnabled());
	chbShowNickSmiley->setChecked(userSetting->isShowSmileyInNickName());
	chbShowSigSeperate->setChecked(userSetting->isShowSignatureInSeperateLine());
	chbSendKey->setChecked(userSetting->isSendKeyEnterEnabled());
		
	sliderFaceSize->setValue( userSetting->getFaceSize().width() ); // assume width == height
	slotFaceSizeChanged(userSetting->getFaceSize().width());
	sbPageSize->setValue(userSetting->getPageSize());
	sbIdleTime->setValue(userSetting->getIdleMaxTime());
	
	chbAutoReply->setChecked(userSetting->isAutoReplyEnabled());
	
	leThemePath->setText(userSetting->getThemeDir());
	leSoundPath->setText(userSetting->getSoundDir());
	
	kkbtnShortKey->setShortcut(userSetting->getMessageShortcut(), false);

	wspMainFont->kcbbBuddyNickColor->setColor(userSetting->getBuddyNameColor());
	wspMainFont->chbBuddyNickFontB->setChecked(userSetting->isBuddyNameBold());
	wspMainFont->chbBuddyNickFontU->setChecked(userSetting->isBuddyNameUnderline());
	wspMainFont->chbBuddyNickFontI->setChecked(userSetting->isBuddyNameItalic());

	wspMainFont->kcbbBuddyFlashColor->setColor(userSetting->getBuddyFlashColor());
	wspMainFont->chbBuddyFlashFontB->setChecked(userSetting->isBuddyFlashBold());
	wspMainFont->chbBuddyFlashFontU->setChecked(userSetting->isBuddyFlashUnderline());
	wspMainFont->chbBuddyFlashFontI->setChecked(userSetting->isBuddyFlashItalic());

	wspMainFont->kcbbBuddySigColor->setColor(userSetting->getBuddySigColor());
	wspMainFont->chbBuddySigFontB->setChecked(userSetting->isBuddySigBold());
	wspMainFont->chbBuddySigFontU->setChecked(userSetting->isBuddySigUnderline());
	wspMainFont->chbBuddySigFontI->setChecked(userSetting->isBuddySigItalic());

	wspMainFont->kcbbQunNameColor->setColor(userSetting->getQunNameColor());
	wspMainFont->chbQunNameFontB->setChecked(userSetting->isQunNameBold());
	wspMainFont->chbQunNameFontU->setChecked(userSetting->isQunNameUnderline());
	wspMainFont->chbQunNameFontI->setChecked(userSetting->isQunNameItalic());

	wspMainFont->kcbbQunFlashColor->setColor(userSetting->getQunFlashColor());
	wspMainFont->chbQunFlashFontB->setChecked(userSetting->isQunFlashBold());
	wspMainFont->chbQunFlashFontU->setChecked(userSetting->isQunFlashUnderline());
	wspMainFont->chbQunFlashFontI->setChecked(userSetting->isQunFlashItalic());

	wspMainFont->kcbbGroupNameColor->setColor(userSetting->getGroupNameColor());
	wspMainFont->chbGroupNameFontB->setChecked(userSetting->isGroupNameBold());
	wspMainFont->chbGroupNameFontU->setChecked(userSetting->isGroupNameUnderline());
	wspMainFont->chbGroupNameFontI->setChecked(userSetting->isGroupNameItalic());

	wspMainFont->kcbbGroupFlashColor->setColor(userSetting->getGroupFlashColor());
	wspMainFont->chbGroupFlashFontB->setChecked(userSetting->isGroupFlashBold());
	wspMainFont->chbGroupFlashFontU->setChecked(userSetting->isGroupFlashUnderline());
	wspMainFont->chbGroupFlashFontI->setChecked(userSetting->isGroupFlashItalic());

	wspMainFont->kcbbGroupOnlineColor->setColor(userSetting->getGroupCountColor());
	wspMainFont->chbGroupOnlineFontB->setChecked(userSetting->isGroupOnlineCountBold());
	wspMainFont->chbGroupOnlineFontU->setChecked(userSetting->isGroupOnlineCountUnderline());
	wspMainFont->chbGroupOnlineFontI->setChecked(userSetting->isGroupOnlineCountItalic());
	
	if(!isLoadDefault){
		autoList = userSetting->getAutoReplyList();
		cbbAutoNo->clear();
		for(uint i=0; i<autoList.size(); i++)
			cbbAutoNo->insertItem(TQString::number(i+1));
		slotCbbAutoNoActivated(0);
				
		tquickList = userSetting->getQuickReplyList();
		cbbQuickNo->clear();
		for(uint i=0; i<tquickList.size(); i++)
			cbbQuickNo->insertItem(TQString::number(i+1));
		slotCbbQuickNoActivated(0);
	}
}


void EvaSysSettingWindow::slotPbFaceDefaultClicked( )
{
	userSetting->loadDefaultSettings();
	loadSetting(false);
}


void EvaSysSettingWindow::slotPbApplyClicked( )
{
	
	if( isUserInfoChanged ){
		bool ok;
		unsigned int id = details[0].toUInt(&ok, 10);
		if(!ok) return;
		
		if(m_IsAuthQuestionChanged){
			if(cbbQuestion->currentText().stripWhiteSpace() == ""){
				KMessageBox::information(this, i18n( "Question cannot be empty."), i18n( "Modify Personal Details")); 
				cbbQuestion->setFocus();
				return;
			}

			if(leAnswer->text().stripWhiteSpace() == ""){
				KMessageBox::information(this, i18n( "Answer cannot be empty.."), i18n( "Modify Personal Details")); 
				leAnswer->setFocus();
				return;
			}
			requestMyUpdateQuestion(cbbQuestion->currentText(), leAnswer->text());
			return;
		}
		
		if(UpdateData(false)){
			if(isSignatureChanged){
				if(teSignature->text().local8Bit().size() > 100){
					KMessageBox::information(this, i18n("Signature is too long!"), i18n("Modify Settings"));
					teSignature->setFocus();
					return;
				}
			}
			//emit requestModify(details, leOldPwd->text(), leNewPwd->text());
			emit requestModify(details, "", "");
			if(isSignatureChanged){
				TQString contents = teSignature->text();
				if(contents.isEmpty()){
					emit requestDeleteSignature();
				}else{
					emit requestUpdateSignature(contents);
				}
			}
		
			//if( chbChangePwd->isChecked() )
			//	chbChangePwd->setChecked( FALSE );
			slotChangePwdClicked();
	
		}else
			emit requestUpdate(id);
	}
	if( isSysSettingChanged ){
		saveSetting( );
	}

	if( isFaceSizeChanged ) {
		emit faceSizeChanged();
	}
	
	isUserInfoChanged = FALSE;
	isSysSettingChanged = FALSE;
	isFaceSizeChanged = FALSE;
	pbApply->setEnabled( FALSE );
	
}

void EvaSysSettingWindow::slotPbOKClicked( )
{
	slotPbApplyClicked();
	close();
}

void EvaSysSettingWindow::slotFaceSizeChanged( int value )
{
	TQString txt = i18n("large" ) + " (" + TQString::number(value) + ")";
	lblFaceBig->setText( txt );

	isFaceSizeChanged = TRUE;
	
}

void EvaSysSettingWindow::slotCapturedShortcut(const TDEShortcut &key)
{
	kkbtnShortKey->setShortcut(key, false);
}

void EvaSysSettingWindow::slotPbThemeClicked( )
{
	TQFileDialog *fd = new TQFileDialog(this, i18n("Choose Theme Path  - Eva"), true);
	fd->setMode(TQFileDialog::DirectoryOnly);
	fd->setFilter("Theme (eva.theme)");
	TQString path;
	if(fd->exec() == TQDialog::Accepted)
		path = fd->selectedFile();
	else
		return;
		
	//path = path.left(path.length() - strlen("/eva.theme"));
	
	leThemePath->setText(path);
}

void EvaSysSettingWindow::slotPbSoundClicked( )
{
	TQFileDialog *fd = new TQFileDialog(this, i18n("Choose Sound Path  - Eva"), true);
	fd->setMode(TQFileDialog::DirectoryOnly);
	fd->setFilter("all (*)");
	TQString path;
	if(fd->exec() == TQDialog::Accepted)
		path = fd->selectedFile();
	else
		return;
	
	leSoundPath->setText(path);
}

void EvaSysSettingWindow::slotCbbAutoNoActivated( int index)
{
	if((uint)index>=autoList.size()) return;
	std::list<TQString>::iterator iter = autoList.begin();
	for(int i=0; i<index; i++)
		iter++;
	teAutoMessage->setText(*iter);
}

void EvaSysSettingWindow::slotPbAutoNewClicked( )
{	
	cbbAutoNo->insertItem(TQString::number(cbbAutoNo->count()+1));
	cbbAutoNo->setCurrentItem(cbbAutoNo->count()-1);
	autoList.push_back(teAutoMessage->text());
	teAutoMessage->selectAll(true);
}

void EvaSysSettingWindow::slotPbAutoDeleteClicked( )
{
	TQString txt = teAutoMessage->text();
	int index = cbbAutoNo->currentItem();
	std::list<TQString>::iterator iter = autoList.begin();
	for(int i=0; i<index; i++)
		iter++;
	autoList.erase(iter);
	cbbAutoNo->removeItem(cbbAutoNo->count()-1);
	slotCbbAutoNoActivated(cbbAutoNo->currentItem());
}

void EvaSysSettingWindow::slotTeAutoTextChanged()
{
	int index = cbbAutoNo->currentItem();
	TQString txt = teAutoMessage->text();
	if((uint)index > autoList.size()) return;
	
	std::list<TQString>::iterator iter = autoList.begin();
	for(int i=0; i<index; i++)
		iter++;
	*iter = txt;
}

void EvaSysSettingWindow::slotCbbQuickNoActivated( int index)
{
	if((uint)index>=tquickList.size()) return;
	std::list<TQString>::iterator iter = tquickList.begin();
	for(int i=0; i<index; i++)
		iter++;
	teQuickMessage->setText(*iter);
}

void EvaSysSettingWindow::slotPbQuickNewClicked( )
{
	cbbQuickNo->insertItem(TQString::number(cbbQuickNo->count()+1));
	cbbQuickNo->setCurrentItem(cbbQuickNo->count()-1);
	tquickList.push_back(teQuickMessage->text());
	teQuickMessage->selectAll(true);
}

void EvaSysSettingWindow::slotPbQuickDeleteClicked( )
{
	int index = cbbQuickNo->currentItem();
	if((uint)index > tquickList.size()) return;
	std::list<TQString>::iterator iter = tquickList.begin();
	for(int i=0; i<index; i++)
		iter++;
	tquickList.erase(iter);

	cbbQuickNo->removeItem(cbbQuickNo->count()-1);
	slotCbbQuickNoActivated(cbbQuickNo->currentItem());
}

void EvaSysSettingWindow::slotTeQuickTextChanged()
{
	int index = cbbQuickNo->currentItem();
	TQString txt = teQuickMessage->text();
	if((uint)index >= tquickList.size()) return;
	
	std::list<TQString>::iterator iter = tquickList.begin();
	for(int i=0; i<index; i++){
		iter++;
	}
	*iter = txt;
}

void EvaSysSettingWindow::slotSettingListItemClicked(TQListViewItem* item)
{ 
	if(!item)
		return;
	
	EvaSettingListItem* listItem = dynamic_cast<EvaSettingListItem *>(item);
	//printf( "Clicked Item Index:%d\n",listItem->itemIndex);
	int index = listItem->itemIndex;
	switch(index){
	case 0:						//User Setting
		if( item->isOpen() ){
			item->setPixmap(0, *faces->getIcon("SETTING_CLOSE")); 
			item->setOpen( FALSE );
		}else{
			item->setPixmap(0, *faces->getIcon("SETTING_OPEN")); 
			item->setOpen( TRUE );
		}
		pbFaceDefault->hide();
		break;
	case 1:						//User Info
		wsSetting->raiseWidget(0);
		pbFaceDefault->hide();
		break;
	case 2:						//QQ Show
		wsSetting->raiseWidget(1);
		pbFaceDefault->hide();
		break;
	case 3:						//Contact
		wsSetting->raiseWidget(2);
		pbFaceDefault->hide();
		break;
	case 4:						//Security
		wsSetting->raiseWidget(3);
		pbFaceDefault->hide();
		break;
	case 5:						//Sys Setting
		if( item->isOpen() ){
			item->setPixmap(0, *faces->getIcon("SYS_CLOSE"));
			item->setOpen( FALSE );
		}else{
			item->setPixmap(0, *faces->getIcon("SYS_OPEN"));
			item->setOpen( TRUE );
		}
		
		break;
	case 6:						//Basic Setting
		wsSetting->raiseWidget(4);
		pbFaceDefault->show();
		break;
	case 7:						//Resource
		wsSetting->raiseWidget(5);
		pbFaceDefault->show();
		break;
	case 8:						//Reply
		wsSetting->raiseWidget(6);
		pbFaceDefault->show();
		break;	
	case 9:						// font setting
		wsSetting->raiseWidget(7);
		pbFaceDefault->show();
		break;
	default:
		break;
	}
	//tqDebug( item->itemPos() );*/
	
}

void EvaSysSettingWindow::setupFaces()
{
	if(!faces) return;
	ivFace->clear();
	//printf("setupFaces run !\n");
	for(int i=1; i< MaxFaceNumber; i++){
		TQIconViewItem *item =  new TQIconViewItem( ivFace, TQString::null );
		item->setPixmap(*(faces->getFace(i)));
		item->setKey( TQString::number(i));  // set face file index as key
	}
}

void EvaSysSettingWindow::slotPbFaceClicked()
{
	
	if(ivFace->isVisible()) 
		ivFace->hide();
	else
		ivFace->show();
}

void EvaSysSettingWindow::FaceChoose( TQIconViewItem * item )
{
	if(!faces) return;
	selectedFaceIndex = faces->getFaceID(item->key().toInt());
	//printf("select:%d, %d\n", selectedFaceIndex, item->key().toInt());
	lblFace->setPixmap(*(item->pixmap()));
	ivFace->hide();
}

bool EvaSysSettingWindow::UpdateData(bool toShow)
{
	leNumber->setText( details[0] );
	if(details.size()!=37) return false;

	bool OK;
	unsigned int id = details[0].toUInt(&OK);
	if(!OK) return false;
	slotBuddyTQQShowReady(id);
	
	int level = 0;
	TQString signature = "";
	level = EvaMain::user->getLevel();
	signature = TQTextCodec::codecForName("GB18030")->toUnicode(EvaMain::user->getSignature().c_str());
	
	int suns, moons, stars;
	EvaUtil::calcSuns(level, &suns, &moons, &stars);
	TQString strSun =  "<img src=\"" + faces->getIconFullPath("TIME_SUN") + "\"></img>";
	TQString strMoon = "<img src=\"" + faces->getIconFullPath("TIME_MOON") + "\"></img>";
	TQString strStar = "<img src=\"" + faces->getIconFullPath("TIME_STAR") + "\"></img>";
	TQString strLevel;
	for(int i=0; i<suns; i++){
		strLevel += strSun;
	}
	for(int i=0; i<moons; i++){
		strLevel += strMoon;
	}
	for(int i=0; i<stars; i++){
		strLevel += strStar;
	}
	lblLevelDisplay->setText("(" + TQString::number(level) + ")" + strLevel);
	lblLevelDisplay->adjustSize();
	leNumber->setReadOnly(true);
	if (toShow)
	{
		leNumber->setText( details[0] );			
		leNickName->setText( details[1]);
		leAge->setText( details[7] );
		cbSex->setCurrentText( details[8] );
		cbArea->setCurrentText( details[2]);
		cbProvince->setCurrentText( details[3] ); 
		cbCity->setCurrentText( details[25] );
		
		bool ok;
		int faceId = details[21].toInt(&ok, 10);
		if(ok){
			selectedFaceIndex = faceId;
			TQPixmap *pix = faces->getUserHeadPixmap(id);
			if(!pix) pix = faces->getFace(faces->getFaceFileIndex(faceId));
			if(pix) lblFace->setPixmap( *pix );
		}else{
			selectedFaceIndex = 0;
			printf("face id converting failed. \"%s\"\n", details[21].local8Bit().data());
		}

		leEmail->setText( details[10] );
		leAddress->setText( details[5] );
		leZipCode->setText( details[4] );
        	lePhone->setText( details[6] );
		leMobile->setText( details[22]);
		
		leRealName->setText( details[9]);
        	leSchool->setText( details[31] );
		cbOccupation->setCurrentText( details[16] );
		leHomePage->setText( details[17] );
		cbZodiac->setCurrentItem( details[33].toInt() );
		cbBlood->setCurrentItem(details[34].toInt());
		cbHoroscape->setCurrentItem( details[32].toInt() );
		teAboutMe->setText( details[24] );
		teSignature->setText(signature);
		
		switch ( details[30].toInt() )
		{
			case 0: rbPublic->setChecked( true );
				break;
			case 1: rbProtect->setChecked( true );
				break;
			case 2: rbPrivate->setChecked( true );
				break;
			default:break;
		}
		TQString authCode = details[18];
		if ( authCode == "0" ){
			rbAuthNoNeed->setChecked(true);
		}else if(authCode == "1"){
			rbAuthNeed->setChecked(true);
		}else if(authCode == "2") {
			rbAuthReject->setChecked(true);
		} else if(authCode == "3"){
			rbAuthQuest->setChecked(true);
			printf("signal emitted\n");
			emit requestMyAuthQuestionSetting();
		}
	}
	else
	{
// 		if(chbChangePwd->isChecked()){
// 			if(leOldPwd->text().stripWhiteSpace() == ""){
// 				KMessageBox::information(this, i18n( "enter your current password please."), i18n( "Modify Personal Details")); 
// 				leOldPwd->setFocus();
// 				return false;
// 			}
// 				
// 			if(leNewPwd->text() != leNewPwdConfirm->text()){
// 				KMessageBox::information(this, i18n( "new password mismatch."), i18n( "Modify Personal Details"));
// 				leNewPwdConfirm->setFocus(); 
// 				return false;
// 			}
// 			if(leNewPwd->text().stripWhiteSpace() == ""){
// 				KMessageBox::information(this, i18n( "Modify Personal Details"), i18n( "new password cannot be empty.")); 
// 				leNewPwd->setFocus();
// 				return false;
// 			}
// 		}
		details.clear();
		details.append(leNumber->text( ));
		details.append(leNickName->text( ));
		details.append(cbArea->currentText(  ));
		details.append(cbProvince->currentText( ));
		details.append(leZipCode->text( ));
		
		
		details.append(leAddress->text(  ));
        	details.append(lePhone->text(  ));
		details.append(leAge->text( ));
		details.append(cbSex->currentText(  )); 
		details.append(leRealName->text(  ));
		
		details.append(leEmail->text( ));
		details.append(""); // pagerSn
		details.append(""); // pagerNum
		details.append(""); // pagerSP
		details.append(""); // pagerBaseNum
		
		details.append(""); // pagerType
		details.append(cbOccupation->currentText( ));
		details.append(leHomePage->text(  ));
		if ( rbAuthNoNeed->isChecked() ){
			details.append("0");
		}else if ( rbAuthNeed->isChecked()){
			details.append("1");
		} else if( rbAuthReject->isChecked()){
			details.append("2");
		} else if (rbAuthQuest->isChecked()){
			details.append("3");
			///TODO: we should update question setting if changed
		} else 
			details.append("2");

		details.append(""); // unknown1
		
		details.append(""); // unknown2
		details.append( TQString::number(selectedFaceIndex) );printf("face index: %d", selectedFaceIndex);
		details.append(leMobile->text( ));
		details.append(""); // mobile type
		details.append(teAboutMe->text(  ));
			
		details.append(cbCity->currentText(  ));
		details.append(""); // unknown3
		details.append(""); // unknown4
		details.append(""); // unknown5
		details.append(""); // open hp
		
		if ( rbPublic->isChecked() ){
			details.append("0");
		}else if ( rbProtect->isChecked()){
			details.append("1");
		} else{
			details.append("2");
		}
        	details.append(leSchool->text( ));
		details.append(TQString::number(cbHoroscape->currentItem(  )));
		details.append(TQString::number(cbZodiac->currentItem(  )));
		details.append(TQString::number(cbBlood->currentItem()));
		
		details.append("0"); // qqshow
		details.append("0"); // unknown6
	}
	
	return true;
}

void EvaSysSettingWindow::slotFirstUpdate()
{
	bool ok;
	unsigned int id = details[0].toUInt(&ok, 10);
	if(!ok) return;
	printf("ask for details\n");
	emit requestUpdate(id);
}

void EvaSysSettingWindow::slotDetailsUpdated(TQStringList list)
{
	if(details[0] != list[0] ) 
		return;
	details = list;
	UpdateData(true);

	isUserInfoChanged = FALSE;
	isSysSettingChanged = FALSE;
	pbApply->setEnabled( FALSE );
}

void EvaSysSettingWindow::slotSignatureChanged( )
{
	isSignatureChanged = true;
}

void EvaSysSettingWindow::slotSignatureReply(const bool ok)
{
	if(ok) printf("Signature modify successed !\n");
	else printf("Signature modify failed !\n");

}

void EvaSysSettingWindow::slotUpdateResult(bool ok, bool isSignature)
{
	if(ok)
		KMessageBox::information(this, i18n( "modify settings successfully."), i18n( "Modify Settings"));
	else
		KMessageBox::information(this, i18n( "failed to modify settings."), i18n( "Modify Settings"));
	if(isSignature && ok)
		isSignatureChanged=false;
}


void EvaSysSettingWindow::slotLinkClicked( const TQString & url)
{
	TQStringList args;
	args<<"exec"<< url;
	kapp->tdeinitExec("kfmclient",args);
	//KRun::runCommand("konqueror \""+url+"\"");
}

void EvaSysSettingWindow::slotShopClicked( )
{
	TQString url = "http://jump.qq.com/clienturl_simp_17?clientuin=" + TQString::number(EvaMain::user->getQQ());
	url+="&clientkey=";
	url+=getClientKeyString();
	slotLinkClicked(url);
}

void EvaSysSettingWindow::slotAlbumClicked( )
{
	TQString url = "http://ptlogin.qq.com/qqshowalbum?clientuin=" + TQString::number(EvaMain::user->getQQ());
	url+="&clientkey=";
	url+=getClientKeyString();
	slotLinkClicked(url);
}

void EvaSysSettingWindow::slotHomeClicked( )
{
	TQString url = "http://jump.qq.com/clienturl_42?clientuin=" + TQString::number(EvaMain::user->getQQ());
	url+="&clientkey=";
	url+=getClientKeyString();
	slotLinkClicked(url);
}

const TQString EvaSysSettingWindow::getClientKeyString()
{
	TQString key="";
	int len = Packet::getClientKeyLength();
	for(int i=0; i<len; i++){
		TQString tmp = TQString::number((unsigned char)(Packet::getClientKey()[i]), 16);
		if(tmp.length()==1)
			tmp = "0" + tmp;
		key+=tmp;
	}
	return key.upper();
}

void EvaSysSettingWindow::slotUpdateTQQShow()
{
	bool ok;
	int id = details[0].toInt(&ok, 10);
	if(ok)
		emit requestTQQShow(id);
}

void EvaSysSettingWindow::slotBuddyTQQShowReady(const unsigned int id)
{
	bool ok;
	unsigned int qq = details[0].toUInt(&ok, 10);
	if(!ok) return;
	if(id != qq) return;
	TQPixmap *pix = faces->getTQQShow(id);
	if(pix){
		lblTQQShow->setPixmap( *pix);
	}
}

void EvaSysSettingWindow:: slotChangePwdClicked()
{
// 	if( chbChangePwd->isChecked() ){
// 		leOldPwd->setEnabled( TRUE );
// 		leNewPwd->setEnabled( TRUE );
// 		leNewPwdConfirm->setEnabled( TRUE );
// 		
// 	}
// 	else{
// 		leOldPwd->setEnabled( FALSE );
// 		leNewPwd->setEnabled( FALSE );
// 		leNewPwdConfirm->setEnabled( FALSE );
// 		
// 	}
}

void EvaSysSettingWindow::slotUserInfoChanged()
{
	isUserInfoChanged = TRUE;
	pbApply->setEnabled( TRUE );
}
void EvaSysSettingWindow:: slotSysSettingChanged()
{
	isSysSettingChanged = TRUE;
	pbApply->setEnabled( TRUE );
}

void EvaSysSettingWindow::closeEvent( TQCloseEvent * e )
{	
	e->accept();
	deleteLater();
}

void EvaSysSettingWindow::slotAuthChanged( )
{
	if(rbAuthQuest->isChecked()){
		fraQuestion->setEnabled(true);
		m_IsAuthQuestionChanged = true;
	} else{
		fraQuestion->setEnabled(false);
		m_IsAuthQuestionChanged = true;
	}
		
	slotUserInfoChanged();
}

void EvaSysSettingWindow::slotReceivedMyAuthSettings( const unsigned char auth,
					const TQString& question,
					const TQString & answer )
{
	if(auth != AUHT_TYPE_QUESTION_GET) return;
	fraQuestion->setEnabled( true );
	cbbQuestion->setCurrentText( question);
	leAnswer->setText( answer );
}

void EvaSysSettingWindow::slotUpdateAuthSettingResult( const unsigned char auth, const unsigned char reply )
{
	if(auth != AUTH_TYPE_QUESTION_SET) return;
	if(reply != 0x00){
		KMessageBox::information(0, TQString(i18n("Update authentication question failed!")),
			i18n("Modify Personal Details"));
		return;
	}
	m_IsAuthQuestionChanged = false;
	// update all details now
	slotPbApplyClicked();
}

void EvaSysSettingWindow::slotChangePasswordClicked( )
{
	TQString url = "http://jump.qq.com/clienturl_173?clientuin=" + TQString::number(EvaMain::user->getQQ());
	url+= "&clientkey=";
	url+= getClientKeyString();
	url+= "&ADUIN=";
	url+= TQString::number(EvaMain::user->getQQ());
	url+= "&ADSESSION=1171468766&ADTAG=CLIENT.QQ.1595_Setting_PasswordTab.0";
	slotLinkClicked(url);
}

void EvaSysSettingWindow::slotProtectPasswordClicked( )
{
	TQString url = "http://service.qq.com/psw/psw_id_index.htm?ADUIN=" + TQString::number(EvaMain::user->getQQ());
	url+= "&ADSESSION=1171468766&ADTAG=CLIENT.QQ.1595_Setting_PasswordTab.0";
	slotLinkClicked(url);
}
	


