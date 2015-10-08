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

#include "evasyssettinguibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqheader.h>
#include <ntqlistview.h>
#include <ntqwidgetstack.h>
#include <ntqwidget.h>
#include <ntqlabel.h>
#include <ntqtextedit.h>
#include <ntqlineedit.h>
#include <ntqcombobox.h>
#include <ntqgroupbox.h>
#include <ntqtoolbutton.h>
#include <kpushbutton.h>
#include <ntqbuttongroup.h>
#include <ntqradiobutton.h>
#include <ntqcheckbox.h>
#include <ntqspinbox.h>
#include <ntqslider.h>
#include <kkeybutton.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <ntqimage.h>
#include <ntqpixmap.h>

#include <ntqiconview.h>
#include <tdelocale.h>

#include "../evamain.h"
#include "evaresource.h"


/*
 *  Constructs a EvaSysSettingUIBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
 
 EvaSettingListItem::EvaSettingListItem( TQListView* parent, TQListViewItem* after, int index )
	:TQListViewItem( parent, after)
{
	itemIndex = index;
}

EvaSettingListItem::EvaSettingListItem( TQListViewItem* parent, TQListViewItem* after, int index )
	:TQListViewItem( parent, after)
{
	itemIndex = index;
}

EvaSettingListItem::~ EvaSettingListItem()
{
}

/*--------------------------------------------------------------*/
EvaSysSettingUIBase::EvaSysSettingUIBase( TQWidget* parent, const char* name, bool modal, WFlags fl )
    : TQDialog( parent, name, modal, fl )
{
	if ( !name )
		setName( "EvaSysSettingUIBase" );
	EvaSysSettingUIBaseLayout = new TQGridLayout( this, 1, 1, 11, 6, "EvaSysSettingUIBaseLayout"); 
	
	layout57 = new TQVBoxLayout( 0, 0, 6, "layout57"); 
	
	layout55 = new TQHBoxLayout( 0, 0, 6, "layout55"); 
	
	lvSettingItem = new TQListView( this, "lvSettingItem" );
	lvSettingItem->addColumn( tr( "ListView" ) );
	lvSettingItem->setFrameShape( TQListView::Box );
	lvSettingItem->setFrameShadow( TQListView::Plain );
	lvSettingItem->setLineWidth( 1 );
	lvSettingItem->setItemMargin( 1 );
	lvSettingItem->setResizeMode( TQListView::LastColumn );
	lvSettingItem->setMaximumWidth(94);
	
	layout55->addWidget( lvSettingItem );
	
	wsSetting = new TQWidgetStack( this, "wsSetting" );
	wsSetting->setFrameShape( TQWidgetStack::Box );
	wsSetting->setSizePolicy(TQSizePolicy::Expanding, TQSizePolicy::Expanding);
	
	wspUserInfo = new TQWidget( wsSetting, "wspUserInfo" );
	wspUserInfoLayout = new TQGridLayout( wspUserInfo, 1, 1, 11, 6, "wspUserInfoLayout"); 
	spacer37 = new TQSpacerItem( 20, 20, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	wspUserInfoLayout->addItem( spacer37, 1, 0 );
	
	layout44 = new TQGridLayout( 0, 1, 1, 0, 6, "layout44"); 
	
	layout43 = new TQGridLayout( 0, 1, 1, 0, 6, "layout43"); 
	
	layout41 = new TQVBoxLayout( 0, 0, 6, "layout41"); 
	
	lblSignature = new TQLabel( wspUserInfo, "lblSignature" );
	layout41->addWidget( lblSignature );
	spacer15 = new TQSpacerItem( 20, 16, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout41->addItem( spacer15 );
	
	layout43->addLayout( layout41, 0, 0 );
	
	layout70 = new TQHBoxLayout( 0, 0, 6, "layout70"); 
	
	lblLevel = new TQLabel( wspUserInfo, "lblLevel" );
	layout70->addWidget( lblLevel );
	
	layout61 = new TQHBoxLayout( 0, 0, 6, "layout61"); 
	
	lblLevelDisplay = new TQLabel( wspUserInfo, "lblLevelDisplay" );
	layout61->addWidget( lblLevelDisplay );
	spacer16 = new TQSpacerItem( 181, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout61->addItem( spacer16 );
	layout70->addLayout( layout61 );
	
	layout43->addMultiCellLayout( layout70, 1, 1, 0, 1 );
	
	teSignature = new TQTextEdit( wspUserInfo, "teSignature" );
	teSignature->setEnabled( TRUE );
	teSignature->setMinimumSize( TQSize( 0, 50 ) );
	teSignature->setMaximumSize( TQSize( 32767, 50 ) );
	teSignature->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
	teSignature->setPaletteBackgroundColor( TQColor( 255, 255, 255 ) );
	teSignature->setFrameShape( TQTextEdit::Box );
	teSignature->setFrameShadow( TQTextEdit::Plain );
	teSignature->setLineWidth( 1 );
	teSignature->setResizePolicy( TQTextEdit::Manual );
	teSignature->setVScrollBarMode( TQTextEdit::AlwaysOff );
	teSignature->setHScrollBarMode( TQTextEdit::AlwaysOff );
	teSignature->setDragAutoScroll( FALSE );
	teSignature->setTextFormat( TQTextEdit::PlainText );
	teSignature->setWordWrap( TQTextEdit::WidgetWidth );
	teSignature->setWrapColumnOrWidth( 333 );
	teSignature->setAutoFormatting((unsigned int)( TQTextEdit::AutoAll ) );
	
	layout43->addWidget( teSignature, 0, 1 );
	
	layout44->addLayout( layout43, 1, 0 );
	
	layout73 = new TQHBoxLayout( 0, 0, 6, "layout73"); 
	
	layout72 = new TQVBoxLayout( 0, 0, 6, "layout72"); 
	
	lblAboutMe = new TQLabel( wspUserInfo, "lblAboutMe" );
	layout72->addWidget( lblAboutMe );
	spacer17 = new TQSpacerItem( 20, 41, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout72->addItem( spacer17 );
	layout73->addLayout( layout72 );
	
	teAboutMe = new TQTextEdit( wspUserInfo, "teAboutMe" );
	teAboutMe->setEnabled( TRUE );
	teAboutMe->setMinimumSize( TQSize( 0, 80 ) );
	teAboutMe->setMaximumSize( TQSize( 32767, 80 ) );
	teAboutMe->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
	teAboutMe->setPaletteBackgroundColor( TQColor( 255, 255, 255 ) );
	teAboutMe->setFrameShape( TQTextEdit::Box );
	teAboutMe->setFrameShadow( TQTextEdit::Plain );
	teAboutMe->setLineWidth( 1 );
	teAboutMe->setVScrollBarMode( TQTextEdit::Auto );
	teAboutMe->setHScrollBarMode( TQTextEdit::AlwaysOff );
	teAboutMe->setWordWrap( TQTextEdit::WidgetWidth );
	layout73->addWidget( teAboutMe );
	
	layout44->addLayout( layout73, 3, 0 );
	
	layout56 = new TQHBoxLayout( 0, 0, 6, "layout56"); 
	
	layout55_2 = new TQHBoxLayout( 0, 0, 6, "layout55_2"); 
	
	layout54 = new TQVBoxLayout( 0, 0, 6, "layout54"); 
	
	lblRealName = new TQLabel( wspUserInfo, "lblRealName" );
	layout54->addWidget( lblRealName );
	
	lblSchool = new TQLabel( wspUserInfo, "lblSchool" );
	layout54->addWidget( lblSchool );
	
	lblOccupation = new TQLabel( wspUserInfo, "lblOccupation" );
	layout54->addWidget( lblOccupation );
	
	lblHomePage = new TQLabel( wspUserInfo, "lblHomePage" );
	layout54->addWidget( lblHomePage );
	layout55_2->addLayout( layout54 );
	
	layout53 = new TQVBoxLayout( 0, 0, 6, "layout53"); 
	
	layout52 = new TQHBoxLayout( 0, 0, 6, "layout52"); 
	
	leRealName = new TQLineEdit( wspUserInfo, "leRealName" );
	leRealName->setEnabled( TRUE );
	leRealName->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
	leRealName->setFrameShape( TQLineEdit::Box );
	leRealName->setFrameShadow( TQLineEdit::Plain );
	leRealName->setLineWidth( 1 );
	leRealName->setMaxLength( 10 );
	layout52->addWidget( leRealName );
	
	lblSex = new TQLabel( wspUserInfo, "lblSex" );
	layout52->addWidget( lblSex );
	
	cbSex = new TQComboBox( FALSE, wspUserInfo, "cbSex" );
	layout52->addWidget( cbSex );
	layout53->addLayout( layout52 );
	
	leSchool = new TQLineEdit( wspUserInfo, "leSchool" );
	leSchool->setEnabled( TRUE );
	leSchool->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
	leSchool->setFrameShape( TQLineEdit::Box );
	leSchool->setFrameShadow( TQLineEdit::Plain );
	leSchool->setLineWidth( 1 );
	leSchool->setMaxLength( 20 );
	layout53->addWidget( leSchool );
	
	cbOccupation = new TQComboBox( FALSE, wspUserInfo, "cbOccupation" );
	cbOccupation->setEditable( TRUE );
	layout53->addWidget( cbOccupation );
	
	leHomePage = new TQLineEdit( wspUserInfo, "leHomePage" );
	leHomePage->setEnabled( TRUE );
	leHomePage->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
	leHomePage->setFrameShape( TQLineEdit::Box );
	leHomePage->setFrameShadow( TQLineEdit::Plain );
	leHomePage->setLineWidth( 1 );
	leHomePage->setMaxLength( 50 );
	layout53->addWidget( leHomePage );
	layout55_2->addLayout( layout53 );
	layout56->addLayout( layout55_2 );
	
	layout68 = new TQHBoxLayout( 0, 0, 6, "layout68"); 
	
	layout66 = new TQVBoxLayout( 0, 0, 6, "layout66"); 
	
	lblAge = new TQLabel( wspUserInfo, "lblAge" );
	layout66->addWidget( lblAge );
	
	lblZodiac = new TQLabel( wspUserInfo, "lblZodiac" );
	layout66->addWidget( lblZodiac );
	
	lblHoroscape = new TQLabel( wspUserInfo, "lblHoroscape" );
	layout66->addWidget( lblHoroscape );
	
	lblBlood = new TQLabel( wspUserInfo, "lblBlood" );
	layout66->addWidget( lblBlood );
	layout68->addLayout( layout66 );
	
	layout67 = new TQVBoxLayout( 0, 0, 6, "layout67"); 
	
	leAge = new TQLineEdit( wspUserInfo, "leAge" );
	leAge->setEnabled( TRUE );
	leAge->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
	leAge->setFrameShape( TQLineEdit::Box );
	leAge->setFrameShadow( TQLineEdit::Plain );
	leAge->setLineWidth( 1 );
	leAge->setMaxLength( 3 );
	layout67->addWidget( leAge );
	
	cbZodiac = new TQComboBox( FALSE, wspUserInfo, "cbZodiac" );
	layout67->addWidget( cbZodiac );
	
	cbHoroscape = new TQComboBox( FALSE, wspUserInfo, "cbHoroscape" );
	layout67->addWidget( cbHoroscape );
	
	cbBlood = new TQComboBox( FALSE, wspUserInfo, "cbBlood" );
	layout67->addWidget( cbBlood );
	layout68->addLayout( layout67 );
	layout56->addLayout( layout68 );
	
	layout44->addLayout( layout56, 2, 0 );
	
	layout46 = new TQHBoxLayout( 0, 0, 6, "layout46"); 
	
	layout45 = new TQVBoxLayout( 0, 0, 6, "layout45"); 
	
	lblNumber = new TQLabel( wspUserInfo, "lblNumber" );
	layout45->addWidget( lblNumber );
	
	lblNickName = new TQLabel( wspUserInfo, "lblNickName" );
	layout45->addWidget( lblNickName );
	layout46->addLayout( layout45 );
	
	layout36 = new TQGridLayout( 0, 1, 1, 0, 6, "layout36"); 
	
	leNickName = new TQLineEdit( wspUserInfo, "leNickName" );
	leNickName->setEnabled( TRUE );
	leNickName->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
	leNickName->setFrameShape( TQLineEdit::Box );
	leNickName->setFrameShadow( TQLineEdit::Plain );
	leNickName->setLineWidth( 1 );
	leNickName->setMaxLength( 12 );
	
	layout36->addWidget( leNickName, 1, 0 );
	spacer13 = new TQSpacerItem( 101, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout36->addMultiCell( spacer13, 0, 1, 1, 1 );
	
	leNumber = new TQLineEdit( wspUserInfo, "leNumber" );
	leNumber->setEnabled( FALSE );
	leNumber->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
	leNumber->setFrameShape( TQLineEdit::Box );
	leNumber->setFrameShadow( TQLineEdit::Plain );
	leNumber->setLineWidth( 1 );
	
	layout36->addWidget( leNumber, 0, 0 );
	
	lblFace = new TQLabel( wspUserInfo, "lblFace" );
	lblFace->setMinimumSize( TQSize( 46, 46 ) );
	lblFace->setMaximumSize( TQSize( 46, 46 ) );
	lblFace->setFrameShape( TQLabel::Box );
	lblFace->setAlignment( int( TQLabel::AlignCenter ) );
	
	layout36->addMultiCellWidget( lblFace, 0, 1, 2, 2 );
	spacer10 = new TQSpacerItem( 20, 20, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout36->addItem( spacer10, 0, 3 );
	
	pbChangeFace = new TQPushButton( wspUserInfo, "pbChangeFace" );
	
	layout36->addWidget( pbChangeFace, 1, 3 );
	layout46->addLayout( layout36 );
	
	layout44->addLayout( layout46, 0, 0 );
	
	wspUserInfoLayout->addLayout( layout44, 0, 0 );
	wsSetting->addWidget( wspUserInfo, 0 );
	
	wspTQQShow = new TQWidget( wsSetting, "wspTQQShow" );
	wspTQQShowLayout = new TQGridLayout( wspTQQShow, 1, 1, 11, 6, "wspTQQShowLayout"); 
	spacer18 = new TQSpacerItem( 20, 31, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	wspTQQShowLayout->addItem( spacer18, 1, 0 );
	spacer17_2 = new TQSpacerItem( 21, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	wspTQQShowLayout->addItem( spacer17_2, 0, 1 );
	
	gbTQQShow = new TQGroupBox( wspTQQShow, "gbTQQShow" );
	
	TQWidget* privateLayoutWidget = new TQWidget( gbTQQShow, "layout13" );
	privateLayoutWidget->setGeometry( TQRect( 30, 30, 325, 261 ) );
	layout13 = new TQGridLayout( privateLayoutWidget, 1, 1, 11, 6, "layout13"); 
	
	lblTQQShow = new TQLabel( privateLayoutWidget, "lblTQQShow" );
	lblTQQShow->setMinimumSize( TQSize( 147, 233 ) );
	lblTQQShow->setMaximumSize( TQSize( 147, 233 ) );
	lblTQQShow->setFrameShape( TQLabel::Box );
	lblTQQShow->setAlignment( int( TQLabel::AlignCenter ) );
	
	layout13->addWidget( lblTQQShow, 0, 0 );
	spacer6 = new TQSpacerItem( 23, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout13->addItem( spacer6, 0, 1 );
	
	layout12 = new TQGridLayout( 0, 1, 1, 0, 6, "layout12"); 
	spacer5 = new TQSpacerItem( 20, 80, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout12->addItem( spacer5, 4, 0 );
	spacer7 = new TQSpacerItem( 20, 42, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout12->addItem( spacer7, 6, 0 );
	spacer8 = new TQSpacerItem( 20, 20, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout12->addItem( spacer8, 0, 0 );
	
	tbtnHome = new TQToolButton( privateLayoutWidget, "tbtnHome" );
	tbtnHome->setPaletteForegroundColor( TQColor( 0, 0, 255 ) );
	tbtnHome->setCursor( TQCursor( 13 ) );
	tbtnHome->setAutoRaise( TRUE );
	tbtnHome->setUsesTextLabel( TRUE );
	tbtnHome->setTextPosition( TQToolButton::BesideIcon );
	
	layout12->addWidget( tbtnHome, 3, 0 );
	
	tbtnAlbum = new TQToolButton( privateLayoutWidget, "tbtnAlbum" );
	tbtnAlbum->setPaletteForegroundColor( TQColor( 0, 0, 255 ) );
	tbtnAlbum->setCursor( TQCursor( 13 ) );
	tbtnAlbum->setAutoRaise( TRUE );
	tbtnAlbum->setUsesTextLabel( TRUE );
	tbtnAlbum->setTextPosition( TQToolButton::BesideIcon );
	
	layout12->addWidget( tbtnAlbum, 2, 0 );
	
	kpbUpdateShow = new KPushButton( privateLayoutWidget, "kpbUpdateShow" );
	
	layout12->addWidget( kpbUpdateShow, 5, 0 );
	
	tbtnShop = new TQToolButton( privateLayoutWidget, "tbtnShop" );
	tbtnShop->setPaletteForegroundColor( TQColor( 0, 0, 255 ) );
	tbtnShop->setCursor( TQCursor( 13 ) );
	tbtnShop->setAutoRaise( TRUE );
	tbtnShop->setUsesTextLabel( TRUE );
	tbtnShop->setTextPosition( TQToolButton::BesideIcon );
	
	layout12->addWidget( tbtnShop, 1, 0 );
	
	layout13->addLayout( layout12, 0, 2 );
	
	wspTQQShowLayout->addWidget( gbTQQShow, 0, 0 );
	wsSetting->addWidget( wspTQQShow, 1 );
	
	wspContact = new TQWidget( wsSetting, "wspContact" );
	wspContactLayout = new TQGridLayout( wspContact, 1, 1, 11, 6, "wspContactLayout"); 
	spacer29 = new TQSpacerItem( 31, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	wspContactLayout->addItem( spacer29, 0, 1 );
	spacer30 = new TQSpacerItem( 20, 41, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	wspContactLayout->addItem( spacer30, 1, 0 );
	
	layout48 = new TQGridLayout( 0, 1, 1, 0, 6, "layout48"); 
	
	gbContact = new TQGroupBox( wspContact, "gbContact" );
	
	buttonGroup1 = new TQButtonGroup( gbContact, "buttonGroup1" );
	buttonGroup1->setGeometry( TQRect( 10, 20, 293, 44 ) );
	buttonGroup1->setFrameShape( TQButtonGroup::NoFrame );
	buttonGroup1->setFrameShadow( TQButtonGroup::Plain );
	buttonGroup1->setLineWidth( 0 );
	buttonGroup1->setColumnLayout(0, TQt::Vertical );
	buttonGroup1->layout()->setSpacing( 6 );
	buttonGroup1->layout()->setMargin( 11 );
	buttonGroup1Layout = new TQGridLayout( buttonGroup1->layout() );
	buttonGroup1Layout->setAlignment( TQt::AlignTop );
	
	layout54_2 = new TQHBoxLayout( 0, 0, 6, "layout54_2"); 
	
	lblPrompt = new TQLabel( buttonGroup1, "lblPrompt" );
	layout54_2->addWidget( lblPrompt );
	
	rbPublic = new TQRadioButton( buttonGroup1, "rbPublic" );
	layout54_2->addWidget( rbPublic );
	
	rbProtect = new TQRadioButton( buttonGroup1, "rbProtect" );
	layout54_2->addWidget( rbProtect );
	
	rbPrivate = new TQRadioButton( buttonGroup1, "rbPrivate" );
	layout54_2->addWidget( rbPrivate );
	
	buttonGroup1Layout->addLayout( layout54_2, 0, 0 );
	
	TQWidget* privateLayoutWidget_2 = new TQWidget( gbContact, "layout56" );
	privateLayoutWidget_2->setGeometry( TQRect( 10, 60, 210, 128 ) );
	layout56_2 = new TQGridLayout( privateLayoutWidget_2, 1, 1, 11, 6, "layout56_2"); 
	
	leMobile = new TQLineEdit( privateLayoutWidget_2, "leMobile" );
	leMobile->setFrameShape( TQLineEdit::Box );
	leMobile->setFrameShadow( TQLineEdit::Plain );
	leMobile->setLineWidth( 1 );
	
	layout56_2->addWidget( leMobile, 3, 1 );
	
	leEmail = new TQLineEdit( privateLayoutWidget_2, "leEmail" );
	leEmail->setFrameShape( TQLineEdit::Box );
	leEmail->setFrameShadow( TQLineEdit::Plain );
	leEmail->setLineWidth( 1 );
	
	layout56_2->addWidget( leEmail, 0, 1 );
	
	lblPhone = new TQLabel( privateLayoutWidget_2, "lblPhone" );
	
	layout56_2->addWidget( lblPhone, 2, 0 );
	
	lblAddress = new TQLabel( privateLayoutWidget_2, "lblAddress" );
	
	layout56_2->addWidget( lblAddress, 1, 0 );
	
	lblEmail = new TQLabel( privateLayoutWidget_2, "lblEmail" );
	
	layout56_2->addWidget( lblEmail, 0, 0 );
	
	leAddress = new TQLineEdit( privateLayoutWidget_2, "leAddress" );
	leAddress->setFrameShape( TQLineEdit::Box );
	leAddress->setFrameShadow( TQLineEdit::Plain );
	leAddress->setLineWidth( 1 );
	
	layout56_2->addWidget( leAddress, 1, 1 );
	
	lblMobile = new TQLabel( privateLayoutWidget_2, "lblMobile" );
	
	layout56_2->addWidget( lblMobile, 3, 0 );
	
	lePhone = new TQLineEdit( privateLayoutWidget_2, "lePhone" );
	lePhone->setFrameShape( TQLineEdit::Box );
	lePhone->setFrameShadow( TQLineEdit::Plain );
	lePhone->setLineWidth( 1 );
	
	layout56_2->addWidget( lePhone, 2, 1 );
	
	layout48->addMultiCellWidget( gbContact, 1, 1, 0, 1 );
	
	layout57_2 = new TQGridLayout( 0, 1, 1, 0, 6, "layout57_2"); 
	
	lblCity = new TQLabel( wspContact, "lblCity" );
	
	layout57_2->addWidget( lblCity, 2, 0 );
	
	cbArea = new TQComboBox( FALSE, wspContact, "cbArea" );
	cbArea->setEditable( TRUE );
	
	layout57_2->addWidget( cbArea, 0, 1 );
	
	cbCity = new TQComboBox( FALSE, wspContact, "cbCity" );
	cbCity->setEditable( TRUE );
	
	layout57_2->addWidget( cbCity, 2, 1 );
	
	lblProvince = new TQLabel( wspContact, "lblProvince" );
	
	layout57_2->addWidget( lblProvince, 1, 0 );
	
	cbProvince = new TQComboBox( FALSE, wspContact, "cbProvince" );
	cbProvince->setEditable( TRUE );
	
	layout57_2->addWidget( cbProvince, 1, 1 );
	
	lblZipCode = new TQLabel( wspContact, "lblZipCode" );
	
	layout57_2->addWidget( lblZipCode, 3, 0 );
	
	leZipCode = new TQLineEdit( wspContact, "leZipCode" );
	leZipCode->setFrameShape( TQLineEdit::Box );
	leZipCode->setFrameShadow( TQLineEdit::Plain );
	leZipCode->setLineWidth( 1 );
	leZipCode->setFrame( TRUE );
	
	layout57_2->addWidget( leZipCode, 3, 1 );
	
	lblArea = new TQLabel( wspContact, "lblArea" );
	
	layout57_2->addWidget( lblArea, 0, 0 );
	
	layout48->addLayout( layout57_2, 0, 0 );
	spacer28 = new TQSpacerItem( 171, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout48->addItem( spacer28, 0, 1 );
	
	wspContactLayout->addLayout( layout48, 0, 0 );
	wsSetting->addWidget( wspContact, 2 );
	
	wspSecurity = new TQWidget( wsSetting, "wspSecurity" );
	wspSecurityLayout = new TQGridLayout( wspSecurity, 1, 1, 11, 6, "wspSecurityLayout"); 
	
	layout53_2 = new TQVBoxLayout( 0, 6, 6, "layout53_2"); 
	
	gbPassword = new TQGroupBox(wspSecurity, "gbPassword");
	gbPassword->setFrameShape( TQFrame::StyledPanel );
	gbPassword->setFrameShadow( TQFrame::Raised );

	layoutPwButton = new TQVBoxLayout( 0, 6, 6, "layoutPwButton");
	pbChangePassword = new TQPushButton(gbPassword, "pbChangePassword");
	pbChangePassword->setSizePolicy(TQSizePolicy::Minimum, TQSizePolicy::Minimum);
	layoutPwButton->addWidget(pbChangePassword);
	
	pbProtectPassword = new TQPushButton(gbPassword, "pbProtectPassword");
	pbProtectPassword->setSizePolicy(TQSizePolicy::Minimum, TQSizePolicy::Minimum);
	layoutPwButton->addWidget(pbProtectPassword);

	
	layoutPwd = new TQVBoxLayout(gbPassword, 15, 10, "layoutPwd");
	layoutPwd->addLayout(layoutPwButton);
	layout53_2->addWidget( gbPassword);
	
	bgAuthen = new TQButtonGroup( wspSecurity, "bgAuthen" );
	bgAuthen->setColumnLayout(0, TQt::Vertical );
	bgAuthen->layout()->setSpacing( 6 );
	bgAuthen->layout()->setMargin( 11 );
	authButtonLayout = new TQGridLayout( bgAuthen->layout() );
	authButtonLayout->setAlignment( TQt::AlignTop );

	layout49 = new TQVBoxLayout(0, 11, 6, "layout49"); 
	
	rbAuthNoNeed = new TQRadioButton( bgAuthen, "rbAuthNoNeed" );
	layout49->addWidget( rbAuthNoNeed );
	
	rbAuthNeed = new TQRadioButton( bgAuthen, "rbAuthNeed" );
	layout49->addWidget( rbAuthNeed );
	
	rbAuthReject = new TQRadioButton( bgAuthen, "rbAuthReject" );
	layout49->addWidget( rbAuthReject );

	rbAuthQuest = new TQRadioButton( bgAuthen, "rbAuthQuest" );
	layout49->addWidget( rbAuthQuest );

	fraQuestion = new TQFrame(bgAuthen, "fraQuestion");
	fraQuestion->setFrameShape( TQFrame::StyledPanel );
	fraQuestion->setFrameShadow( TQFrame::Raised );
	lblQuestion = new TQLabel(fraQuestion, "lblQuestion");
	lblAnswer = new TQLabel(fraQuestion, "lblAnswer");
	layoutQuestLbl = new TQVBoxLayout(0, 11, 6, "layoutQuestLbl");
	layoutQuestLbl->addWidget(lblQuestion);
	layoutQuestLbl->addWidget(lblAnswer);

	cbbQuestion = new TQComboBox(fraQuestion, "leQuestion");
	cbbQuestion->setEditable(true);
	leAnswer = new TQLineEdit(fraQuestion, "leAnswer");
	layoutQuestContents = new TQVBoxLayout(0, 11, 6, "layoutQuestContents");
	layoutQuestContents->addWidget(cbbQuestion);
	layoutQuestContents->addWidget(leAnswer);

	layoutHQuest =  new TQHBoxLayout(0, 11, 6, "layoutHQuest");
	layoutHQuest->addLayout(layoutQuestLbl);
	layoutHQuest->addLayout(layoutQuestContents);

	layoutQuest = new TQVBoxLayout(fraQuestion, 6, 6, "layoutQuest");
	layoutQuest->addLayout(layoutHQuest);
	layout49->addWidget( fraQuestion );

	authButtonLayout->addLayout(layout49, 0, 0);
	layout53_2->addWidget( bgAuthen );
	
	wspSecurityLayout->addLayout( layout53_2, 0, 0 );
	spacer32 = new TQSpacerItem( 20, 81, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	wspSecurityLayout->addItem( spacer32, 1, 0 );
	spacer33 = new TQSpacerItem( 61, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	wspSecurityLayout->addItem( spacer33, 0, 1 );
	wsSetting->addWidget( wspSecurity, 3 );
	
	wspBasicSetting = new TQWidget( wsSetting, "wspBasicSetting" );
	wspBasicSettingLayout = new TQGridLayout( wspBasicSetting, 1, 1, 11, 6, "wspBasicSettingLayout"); 
	spacer15_2 = new TQSpacerItem( 21, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	wspBasicSettingLayout->addItem( spacer15_2, 0, 1 );
	spacer16_2 = new TQSpacerItem( 20, 41, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	wspBasicSettingLayout->addItem( spacer16_2, 1, 0 );
	
	layout48_2 = new TQVBoxLayout( 0, 0, 6, "layout48_2"); 
	
	gbGeneralSetting = new TQGroupBox( wspBasicSetting, "gbGeneralSetting" );

	layout47 = new TQHBoxLayout( gbGeneralSetting, 11, 6, "layout47"); 
	
	layout45_2 = new TQVBoxLayout( 0, 10, 6, "layout45_2"); 
	
	chbOnlineTip = new TQCheckBox( gbGeneralSetting, "chbOnlineTip" );
	layout45_2->addWidget( chbOnlineTip );
	
	chbShowOnlineUsers = new TQCheckBox( gbGeneralSetting, "chbShowOnlineUsers" );
	layout45_2->addWidget( chbShowOnlineUsers );
	
	chbSound = new TQCheckBox( gbGeneralSetting, "chbSound" );
	layout45_2->addWidget( chbSound );
	
	chbShowNickSmiley = new TQCheckBox( gbGeneralSetting, "chbShowNickSmiley" );
	layout45_2->addWidget( chbShowNickSmiley );

	chbSystemNews = new TQCheckBox( gbGeneralSetting, "chbSystemNews" );
	layout45_2->addWidget( chbSystemNews );
	layout47->addLayout( layout45_2 );
	
	layout46_2 = new TQVBoxLayout( 0, 10, 6, "layout46_2"); 
	
	chbMessage = new TQCheckBox( gbGeneralSetting, "chbMessage" );
	layout46_2->addWidget( chbMessage );
	
	chbSystemBroadcast = new TQCheckBox( gbGeneralSetting, "chbSystemBroadcast" );
	layout46_2->addWidget( chbSystemBroadcast );
	
	chbSendKey = new TQCheckBox( gbGeneralSetting, "chbSendKey" );
	layout46_2->addWidget( chbSendKey );
	
	chbShowSigSeperate = new TQCheckBox( gbGeneralSetting, "chbShowSigSeperate" );
	layout46_2->addWidget( chbShowSigSeperate );
	layout47->addLayout( layout46_2 );
	layout48_2->addWidget( gbGeneralSetting );
	
	gbOtherSetting = new TQGroupBox( wspBasicSetting, "gbOtherSetting" );
	
	TQWidget* privateLayoutWidget_5 = new TQWidget( gbOtherSetting, "layout52" );
	privateLayoutWidget_5->setGeometry( TQRect( 10, 15, 340, 140 ) );
	layout52_3 = new TQVBoxLayout( privateLayoutWidget_5, 11, 6, "layout52_3"); 
	
	layout44_2 = new TQHBoxLayout( 0, 0, 6, "layout44_2"); 
	
	lblPageSize = new TQLabel( privateLayoutWidget_5, "lblPageSize" );
	layout44_2->addWidget( lblPageSize );
	
	sbPageSize = new TQSpinBox( privateLayoutWidget_5, "sbPageSize" );
	sbPageSize->setMaxValue( 50 );
	sbPageSize->setMinValue( 5 );
	sbPageSize->setValue( 25 );
	layout44_2->addWidget( sbPageSize );
	
	lblPageSizeEnd = new TQLabel( privateLayoutWidget_5, "lblPageSizeEnd" );
	layout44_2->addWidget( lblPageSizeEnd );

	layout52_3->addLayout( layout44_2 );

	layout_idt = new TQHBoxLayout( 0, 0, 6, "layout_idt");
	lblIdleTime = new TQLabel( privateLayoutWidget_5, "lblIdleTime" );
	layout_idt->addWidget( lblIdleTime );
	sbIdleTime = new TQSpinBox( privateLayoutWidget_5, "sbIdleTime" );
	sbIdleTime->setMaxValue( 60 );
	sbIdleTime->setMinValue( 0 );
	sbIdleTime->setValue( 5 );
	layout_idt->addWidget( sbIdleTime );
	lblIdleTimeEnd = new TQLabel( privateLayoutWidget_5, "lblIdleTimeEnd" );
	layout_idt->addWidget( lblIdleTimeEnd );
	layout52_3->addLayout( layout_idt );
	
	layout45_3 = new TQHBoxLayout( 0, 0, 6, "layout45_3"); 
	
	lblFaceSize = new TQLabel( privateLayoutWidget_5, "lblFaceSize" );
	layout45_3->addWidget( lblFaceSize );
	
	lblFaceSmall = new TQLabel( privateLayoutWidget_5, "lblFaceSmall" );
	layout45_3->addWidget( lblFaceSmall );
	
	sliderFaceSize = new TQSlider( privateLayoutWidget_5, "sliderFaceSize" );
	sliderFaceSize->setMinValue( 10 );
	sliderFaceSize->setMaxValue( 40 );
	sliderFaceSize->setPageStep( 5 );
	sliderFaceSize->setValue( 16 );
	sliderFaceSize->setOrientation( TQSlider::Horizontal );
	layout45_3->addWidget( sliderFaceSize );
	
	lblFaceBig = new TQLabel( privateLayoutWidget_5, "lblFaceBig" );
	layout45_3->addWidget( lblFaceBig );
	layout52_3->addLayout( layout45_3 );
	
	layout51_2 = new TQHBoxLayout( 0, 0, 6, "layout51_2"); 
	
	lblShortKey = new TQLabel( privateLayoutWidget_5, "lblShortKey" );
	layout51_2->addWidget( lblShortKey );
	
	kkbtnShortKey = new KKeyButton( privateLayoutWidget_5, "kkbtnShortKey" );
	layout51_2->addWidget( kkbtnShortKey );
	spacer19 = new TQSpacerItem( 21, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout51_2->addItem( spacer19 );
	layout52_3->addLayout( layout51_2 );
	layout48_2->addWidget( gbOtherSetting );
	
	wspBasicSettingLayout->addLayout( layout48_2, 0, 0 );
	wsSetting->addWidget( wspBasicSetting, 4 );
	
	wspResource = new TQWidget( wsSetting, "wspResource" );
	wspResourceLayout = new TQGridLayout( wspResource, 1, 1, 11, 6, "wspResourceLayout"); 
	
	gbPath = new TQGroupBox( wspResource, "gbPath" );
	
	TQWidget* privateLayoutWidget_6 = new TQWidget( gbPath, "layout59" );
	privateLayoutWidget_6->setGeometry( TQRect( 10, 15, 350, 160 ) );
	layout59 = new TQVBoxLayout( privateLayoutWidget_6, 11, 6, "layout59"); 
	
	layout56_3 = new TQGridLayout( 0, 1, 1, 0, 6, "layout56_3"); 
	
	lblThemePath = new TQLabel( privateLayoutWidget_6, "lblThemePath" );
	
	layout56_3->addWidget( lblThemePath, 0, 0 );
	spacer20 = new TQSpacerItem( 271, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout56_3->addItem( spacer20, 0, 1 );
	
	layout55_3 = new TQHBoxLayout( 0, 0, 6, "layout55_3"); 
	
	leThemePath = new TQLineEdit( privateLayoutWidget_6, "leThemePath" );
	leThemePath->setFrameShape( TQLineEdit::Box );
	leThemePath->setFrameShadow( TQLineEdit::Plain );
	leThemePath->setLineWidth( 1 );
	layout55_3->addWidget( leThemePath );
	
	pbTheme = new TQPushButton( privateLayoutWidget_6, "pbTheme" );
	layout55_3->addWidget( pbTheme );
	
	layout56_3->addMultiCellLayout( layout55_3, 1, 1, 0, 1 );
	layout59->addLayout( layout56_3 );
	
	layout57_3 = new TQGridLayout( 0, 1, 1, 0, 6, "layout57_3"); 
	
	lblSoundPath = new TQLabel( privateLayoutWidget_6, "lblSoundPath" );
	
	layout57_3->addWidget( lblSoundPath, 0, 0 );
	spacer21 = new TQSpacerItem( 271, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout57_3->addItem( spacer21, 0, 1 );
	
	layout101 = new TQHBoxLayout( 0, 0, 6, "layout101"); 
	
	leSoundPath = new TQLineEdit( privateLayoutWidget_6, "leSoundPath" );
	leSoundPath->setFrameShape( TQLineEdit::Box );
	leSoundPath->setFrameShadow( TQLineEdit::Plain );
	leSoundPath->setLineWidth( 1 );
	layout101->addWidget( leSoundPath );
	
	pbSound = new TQPushButton( privateLayoutWidget_6, "pbSound" );
	layout101->addWidget( pbSound );
	
	layout57_3->addMultiCellLayout( layout101, 1, 1, 0, 1 );
	layout59->addLayout( layout57_3 );
	
	wspResourceLayout->addWidget( gbPath, 0, 0 );
	spacer19_2 = new TQSpacerItem( 21, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	wspResourceLayout->addItem( spacer19_2, 0, 1 );
	spacer20_2 = new TQSpacerItem( 20, 181, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	wspResourceLayout->addItem( spacer20_2, 1, 0 );
	wsSetting->addWidget( wspResource, 5 );
	
	wspReply = new TQWidget( wsSetting, "wspReply" );
	wspReplyLayout = new TQGridLayout( wspReply, 1, 1, 11, 6, "wspReplyLayout"); 
	
	layout44_3 = new TQGridLayout( 0, 1, 1, 0, 6, "layout44_3"); 
	
	gbQuickReply = new TQGroupBox( wspReply, "gbQuickReply" );
	
	TQWidget* privateLayoutWidget_7 = new TQWidget( gbQuickReply, "layout43" );
	privateLayoutWidget_7->setGeometry( TQRect( 10, 15, 350, 120 ) );
	layout43_2 = new TQVBoxLayout( privateLayoutWidget_7, 11, 6, "layout43_2"); 
	
	layout40 = new TQHBoxLayout( 0, 0, 6, "layout40"); 
	
	cbbQuickNo = new TQComboBox( FALSE, privateLayoutWidget_7, "cbbQuickNo" );
	layout40->addWidget( cbbQuickNo );
	spacer24 = new TQSpacerItem( 291, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout40->addItem( spacer24 );
	layout43_2->addLayout( layout40 );
	
	layout42 = new TQHBoxLayout( 0, 0, 6, "layout42"); 
	
	teQuickMessage = new TQTextEdit( privateLayoutWidget_7, "teQuickMessage" );
	teQuickMessage->setFrameShape( TQTextEdit::Box );
	teQuickMessage->setFrameShadow( TQTextEdit::Plain );
	teQuickMessage->setLineWidth( 1 );
	layout42->addWidget( teQuickMessage );
	
	layout41_2 = new TQVBoxLayout( 0, 0, 6, "layout41_2"); 
	spacer25 = new TQSpacerItem( 20, 21, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout41_2->addItem( spacer25 );
	
	pbQuickNew = new TQPushButton( privateLayoutWidget_7, "pbQuickNew" );
	layout41_2->addWidget( pbQuickNew );
	
	pbQuickDelete = new TQPushButton( privateLayoutWidget_7, "pbQuickDelete" );
	layout41_2->addWidget( pbQuickDelete );
	layout42->addLayout( layout41_2 );
	layout43_2->addLayout( layout42 );
	
	layout44_3->addWidget( gbQuickReply, 1, 0 );
	
	gbAutoReply = new TQGroupBox( wspReply, "gbAutoReply" );
	
	TQWidget* privateLayoutWidget_8 = new TQWidget( gbAutoReply, "layout39" );
	privateLayoutWidget_8->setGeometry( TQRect( 10, 15, 352, 120 ) );
	layout39 = new TQVBoxLayout( privateLayoutWidget_8, 11, 6, "layout39"); 
	
	layout32 = new TQHBoxLayout( 0, 0, 6, "layout32"); 
	
	cbbAutoNo = new TQComboBox( FALSE, privateLayoutWidget_8, "cbbAutoNo" );
	cbbAutoNo->setDuplicatesEnabled( FALSE );
	layout32->addWidget( cbbAutoNo );
	
	chbAutoReply = new TQCheckBox( privateLayoutWidget_8, "chbAutoReply" );
	layout32->addWidget( chbAutoReply );
	spacer21_2 = new TQSpacerItem( 61, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout32->addItem( spacer21_2 );
	layout39->addLayout( layout32 );
	
	layout38 = new TQHBoxLayout( 0, 0, 6, "layout38"); 
	
	teAutoMessage = new TQTextEdit( privateLayoutWidget_8, "teAutoMessage" );
	teAutoMessage->setFrameShape( TQTextEdit::Box );
	teAutoMessage->setFrameShadow( TQTextEdit::Plain );
	teAutoMessage->setLineWidth( 1 );
	layout38->addWidget( teAutoMessage );
	
	layout37 = new TQVBoxLayout( 0, 0, 6, "layout37"); 
	spacer23 = new TQSpacerItem( 20, 20, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout37->addItem( spacer23 );
	
	pbAutoNew = new TQPushButton( privateLayoutWidget_8, "pbAutoNew" );
	layout37->addWidget( pbAutoNew );
	
	pbAutoDelete = new TQPushButton( privateLayoutWidget_8, "pbAutoDelete" );
	layout37->addWidget( pbAutoDelete );
	layout38->addLayout( layout37 );
	layout39->addLayout( layout38 );
	
	layout44_3->addWidget( gbAutoReply, 0, 0 );
	
	wspReplyLayout->addLayout( layout44_3, 0, 0 );
	spacer26 = new TQSpacerItem( 20, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	wspReplyLayout->addItem( spacer26, 0, 1 );
	spacer27 = new TQSpacerItem( 20, 31, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	wspReplyLayout->addItem( spacer27, 1, 0 );
	wsSetting->addWidget( wspReply, 6 );
	
	wspMainFont = new MainListFontSettingUIBase(wsSetting,  "wspFont" );
	wsSetting->addWidget(wspMainFont, 7);
	
	layout55->addWidget( wsSetting );
	layout57->addLayout( layout55 );
	
	layout54_3 = new TQHBoxLayout( 0, 0, 6, "layout54_3"); 
	
	pbFaceDefault = new TQPushButton( this, "pbFaceDefault" );
	layout54_3->addWidget( pbFaceDefault );
	spacer34 = new TQSpacerItem( 161, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout54_3->addItem( spacer34 );
	
	pbOk = new TQPushButton( this, "pbOk" );
	layout54_3->addWidget( pbOk );
	
	pbApply = new TQPushButton( this, "pbApply" );
	layout54_3->addWidget( pbApply );
	
	pbCancel = new TQPushButton( this, "pbCancel" );
	layout54_3->addWidget( pbCancel );
	layout57->addLayout( layout54_3 );
	
	EvaSysSettingUIBaseLayout->addLayout( layout57, 0, 0 );
	
	ivFace = new TQIconView( this, "ivFace" );
	ivFace->setGeometry( TQRect( 230, 80, 220, 220 ) );
	ivFace->setFrameShape( TQIconView::WinPanel );
	ivFace->setFrameShadow( TQIconView::Plain );
	ivFace->setSpacing( 4 );
	ivFace->setMaxItemWidth( 100 );
	ivFace->setItemsMovable( FALSE );
	ivFace->setWordWrapIconText( FALSE );
	ivFace->hide();     
	
	languageChange();
	resize( TQSize(551, 433).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
	
	// tab order
	setTabOrder( pbOk, pbCancel );
	setTabOrder( pbCancel, pbApply );
	setTabOrder( pbApply, lvSettingItem );
	setTabOrder( lvSettingItem, leNumber );
	setTabOrder( leNumber, leNickName );
	setTabOrder( leNickName, pbChangeFace );
	setTabOrder( pbChangeFace, teSignature );
	setTabOrder( teSignature, cbSex );
	setTabOrder( cbSex, leRealName );
	setTabOrder( leRealName, leAge );
	setTabOrder( leAge, leSchool );
	setTabOrder( leSchool, cbZodiac );
	setTabOrder( cbZodiac, cbOccupation );
	setTabOrder( cbOccupation, cbHoroscape );
	setTabOrder( cbHoroscape, leHomePage );
	setTabOrder( leHomePage, cbBlood );
	setTabOrder( cbBlood, teAboutMe );
	
	// buddies
	lblRealName->setBuddy( leRealName );
	lblSchool->setBuddy( leRealName );
	lblOccupation->setBuddy( leRealName );
	lblHomePage->setBuddy( leRealName );
	lblZodiac->setBuddy( leRealName );
	lblHoroscape->setBuddy( leRealName );
	lblBlood->setBuddy( leRealName );
	lblNumber->setBuddy( leNumber );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaSysSettingUIBase::~EvaSysSettingUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaSysSettingUIBase::languageChange()
{
	setCaption( i18n("Eva Setting" ) );
	lvSettingItem->header()->setLabel( 0, tr( "ListView" ) );
	lvSettingItem->setTreeStepSize(1);
	lvSettingItem->setSorting( -1 );
	lvSettingItem->clear();
	
	EvaSettingListItem * item_2 = new EvaSettingListItem( lvSettingItem, 0, 0 );
	//item_2->setOpen( TRUE );
	EvaSettingListItem * item = new EvaSettingListItem( item_2, 0, 1 );
	item->setText( 0, i18n( "User Info" ) );
	//item_2->setOpen( TRUE );
	item = new EvaSettingListItem( item_2, item, 2 );
	item->setText( 0, i18n( "TQQShow" ) );
	//item_2->setOpen( TRUE );
	item = new EvaSettingListItem( item_2, item, 3 );
	item->setText( 0, i18n( "Contact" ) );
	//item_2->setOpen( TRUE );
	item = new EvaSettingListItem( item_2, item, 4 );
	item->setText( 0, i18n( "Security" ) );
	//item_2->setText( 0, tr( "User Setting" ) );
	item_2->setText( 0, "");
	item_2->setPixmap(0, *EvaMain::images->getIcon("SETTING_OPEN")); 
	item_2->setOpen( TRUE );
	
	EvaSettingListItem * item_3 = new EvaSettingListItem( lvSettingItem, item_2, 5 );
	//item_3->setOpen( TRUE );
	item = new EvaSettingListItem( item_3, item_2, 6 );
	item->setText( 0, i18n( "Basic" ) );
	//item_3->setOpen( TRUE );
	item = new EvaSettingListItem( item_3, item, 7 );
	item->setText( 0, i18n( "Resource" ) );
	//item_3->setOpen( TRUE );
	item = new EvaSettingListItem( item_3, item, 8 );
	item->setText( 0, i18n( "Reply" ) );
	
	item = new EvaSettingListItem( item_3, item, 9);
	item->setText( 0, i18n("List Font"));

	//item_3->setText( 0, tr( "Sys Setting" ) );
	item_3->setText( 0, "" );
	item_3->setPixmap( 0, *EvaMain::images->getIcon("SYS_OPEN")); 
	item_3->setOpen( TRUE );
	
	lblSignature->setText( i18n( "Signature:" ) );
	lblLevel->setText( i18n( "QQ Level:" ) );
	lblLevelDisplay->setText( TQString::null );
	teSignature->setText( TQString::null );
	lblAboutMe->setText( i18n( "About Me:" ) );
	teAboutMe->setText( TQString::null );
	lblRealName->setText( i18n( "Real Name:" ) );
	lblSchool->setText( i18n( "School:" ) );
	lblOccupation->setText( i18n( "Occupation:" ) );
	lblHomePage->setText( i18n( "Home Page:" ) );
	leRealName->setText( TQString::null );
	lblSex->setText( i18n( "Sex:" ) );
	cbSex->clear();
	cbSex->insertItem( i18n( "male" ) );
	cbSex->insertItem( i18n( "female" ) );
	leSchool->setText( TQString::null );
	cbOccupation->clear();
	cbOccupation->insertItem( TQString::null );
	cbOccupation->insertItem( i18n( "IT" ) );
	cbOccupation->insertItem( i18n( "Teacher" ) );
	cbOccupation->insertItem( i18n( "Doctor" ) );
	cbOccupation->insertItem( i18n( "Student" ) );
	cbOccupation->insertItem( i18n( "Soldier" ) );
	leHomePage->setText( TQString::null );
	lblAge->setText( i18n( "Age:" ) );
	lblZodiac->setText( i18n( "Chinese Zodiac:" ) );
	lblHoroscape->setText( i18n( "Horoscope:" ) );
	lblBlood->setText( i18n( "Blood Type:" ) );
	leAge->setText( TQString::null );
	cbZodiac->clear();
	cbZodiac->insertItem( TQString::null );
	cbZodiac->insertItem( i18n( "Rat" ) );
	cbZodiac->insertItem( i18n( "Ox" ) );
	cbZodiac->insertItem( i18n( "Tiger" ) );
	cbZodiac->insertItem( i18n( "Rabbit" ) );
	cbZodiac->insertItem( i18n( "Dragon" ) );
	cbZodiac->insertItem( i18n( "Snake" ) );
	cbZodiac->insertItem( i18n( "Horse" ) );
	cbZodiac->insertItem( i18n( "Sheep" ) );
	cbZodiac->insertItem( i18n( "Monkey" ) );
	cbZodiac->insertItem( i18n( "Rooster" ) );
	cbZodiac->insertItem( i18n( "Dog" ) );
	cbZodiac->insertItem( i18n( "Pig" ) );
	cbHoroscape->clear();
	cbHoroscape->insertItem( TQString::null );
	cbHoroscape->insertItem( i18n( "Aquarius" ) );
	cbHoroscape->insertItem( i18n( "Pisces" ) );
	cbHoroscape->insertItem( i18n( "Aries" ) );
	cbHoroscape->insertItem( i18n( "Taurus" ) );
	cbHoroscape->insertItem( i18n( "Gemini" ) );
	cbHoroscape->insertItem( i18n( "Cancer" ) );
	cbHoroscape->insertItem( i18n( "Leo" ) );
	cbHoroscape->insertItem( i18n( "Virgo" ) );
	cbHoroscape->insertItem( i18n( "Libra" ) );
	cbHoroscape->insertItem( i18n( "Scoripio" ) );
	cbHoroscape->insertItem( i18n( "Sagittarius" ) );
	cbHoroscape->insertItem( i18n( "Capricorn" ) );
	cbBlood->clear();
	cbBlood->insertItem( TQString::null );
	cbBlood->insertItem( i18n( "A" ) );
	cbBlood->insertItem( i18n( "B" ) );
	cbBlood->insertItem( i18n( "O" ) );
	cbBlood->insertItem( i18n( "AB" ) );
	cbBlood->insertItem( i18n( "Other" ) );
	lblNumber->setText( i18n( "QQ Num:" ) );
	lblNickName->setText( i18n( "Nick Name:" ) );
	leNickName->setText( TQString::null );
	leNumber->setText( TQString::null );
	lblFace->setText( TQString::null );
	pbChangeFace->setText( i18n( "Change" ) );
	gbTQQShow->setTitle( i18n( "TQQShow" ) );
	lblTQQShow->setText( i18n( "QQ Show" ) );
	tbtnHome->setTextLabel( i18n( "QQ home" ) );
	tbtnAlbum->setTextLabel( i18n( "check QQ Show album" ) );
	kpbUpdateShow->setText( i18n( "Update QQ Show" ) );
	tbtnShop->setTextLabel( i18n( "go to QQ Show shop" ) );
	gbContact->setTitle( i18n( "Private Info" ) );
	buttonGroup1->setTitle( TQString::null );
	lblPrompt->setText( i18n( "Following available to" ) );
	rbPublic->setText( i18n( "All" ) );
	rbProtect->setText( i18n( "Friend" ) );
	rbPrivate->setText( i18n( "None" ) );
	lblPhone->setText( i18n( "Phone:" ) );
	lblAddress->setText( i18n( "Address:" ) );
	lblEmail->setText( i18n( "Email:" ) );
	lblMobile->setText( i18n( "Mobile:" ) );
	lblCity->setText( i18n( "City:" ) );
	cbArea->clear();
	cbArea->insertItem( TQString::null );
	cbArea->insertItem( i18n( "China" ) );
	cbArea->insertItem( i18n( "Aboard" ) );
	cbCity->clear();
	cbCity->insertItem( TQString::null );
	lblProvince->setText( i18n( "Province:" ) );
	cbProvince->clear();
	cbProvince->insertItem( TQString::null );
	cbProvince->insertItem( i18n("Beijing") );
	cbProvince->insertItem( i18n("Shanghai") );
	cbProvince->insertItem( i18n("Tianjin") );
	cbProvince->insertItem( i18n("Chongqing") );
	cbProvince->insertItem( i18n("Hebei") );
	cbProvince->insertItem( i18n("Shanxi") );
	cbProvince->insertItem( i18n("Neimenggu") );
	cbProvince->insertItem( i18n("Liaoning") );
	cbProvince->insertItem( i18n("Jilin") );
	cbProvince->insertItem( i18n("Heilongjiang") );
	cbProvince->insertItem( i18n("Jiangsu") );
	cbProvince->insertItem( i18n("Zhejiang") );
	cbProvince->insertItem( i18n("Anhui") );
	cbProvince->insertItem( i18n("Fujian") );
	cbProvince->insertItem( i18n("Jiangxi") );
	cbProvince->insertItem( i18n("Shandong") );
	cbProvince->insertItem( i18n("Henan") );
	cbProvince->insertItem( i18n("Hubei") );
	cbProvince->insertItem( i18n("Hunan") );
	cbProvince->insertItem( i18n("Guangdong") );
	cbProvince->insertItem( i18n("Guangxi") );
	cbProvince->insertItem( i18n("Hainan") );
	cbProvince->insertItem( i18n("Sichuan") );
	cbProvince->insertItem( i18n("Guizhou") );
	cbProvince->insertItem( i18n("Yunnan") );
	cbProvince->insertItem( i18n("Xizang") );
	cbProvince->insertItem( i18n("Shaanxi") );
	cbProvince->insertItem( i18n("Gansu") );
	cbProvince->insertItem( i18n("Ningxia") );
	cbProvince->insertItem( i18n("Qinghai") );
	cbProvince->insertItem( i18n("Xinjiang") );
	cbProvince->insertItem( i18n("Hong Kong") );
	cbProvince->insertItem( i18n("Macao") );
	cbProvince->insertItem( i18n("Taiwan") );
	lblZipCode->setText( i18n("Postal Code:" ) );
	lblArea->setText( i18n("Region:" ) );
	gbPassword->setTitle( i18n("Password Setting"));
	pbChangePassword->setText(i18n("Change password"));
	pbProtectPassword->setText(i18n("Apply password protection"));
	bgAuthen->setTitle( i18n("Authentication" ) );
	rbAuthNoNeed->setText( i18n("Freely adding to anybody" ) );
	rbAuthNeed->setText( i18n("Need authentication to add me" ) );
	rbAuthReject->setText( i18n("Reject any adding request" ) );
	rbAuthQuest->setText( i18n("Add me only if answer is correct"));
	lblQuestion->setText(i18n("Set question"));
	lblAnswer->setText(i18n("Set answer"));
	cbbQuestion->insertItem( TQString::null );
	cbbQuestion->insertItem( i18n( "my email address?" ) );
	cbbQuestion->insertItem( i18n( "my car make?" ) );
	cbbQuestion->insertItem( i18n( "my telephone number?" ) );
	cbbQuestion->insertItem( i18n( "my cellphone number?" ) );
	cbbQuestion->insertItem( i18n( "my real name?" ) );
	cbbQuestion->insertItem( i18n( "my company name?" ) );
	cbbQuestion->insertItem( i18n( "my favourate Linux distro?" ) );

	gbGeneralSetting->setTitle( i18n("General" ) );
	chbOnlineTip->setText( i18n("Display buddy online tip" ) );
	chbShowOnlineUsers->setText( i18n("Display online users only" ) );
	chbSound->setText( i18n("Sound enabled" ) );
	chbShowNickSmiley->setText( i18n("Show smiley icon in buddy list") );
	chbSystemNews->setText( i18n("Show QQ News") );
	chbMessage->setText( i18n("Display message tip" ) );
	chbSystemBroadcast->setText( i18n("Display system ad. tip" ) );
	chbSendKey->setText( i18n("Change send key to \"Enter\"" ) );
	chbShowSigSeperate->setText( i18n( "Display buddy signature in separate line" ) );
	gbOtherSetting->setTitle( i18n("Miscellaneous" ) );
	lblPageSize->setText( i18n("Message page size:" ) );
	lblPageSizeEnd->setText( i18n("entries" ) );
	lblIdleTime->setText( i18n("Change status to away after:" ) );
	lblIdleTimeEnd->setText( i18n("minutes" ) );
	lblFaceSize->setText( i18n("Face size:" ) );
	lblFaceSmall->setText( i18n("small" ) );
	lblFaceBig->setText( i18n("large" ) );
	lblShortKey->setText( i18n("Shortcut Key for reading messages:" ) );
	kkbtnShortKey->setText( i18n("None" ) );
	gbPath->setTitle( i18n("Path" ) );
	lblThemePath->setText( i18n("Theme path:" ) );
	pbTheme->setText( i18n("Browse" ) );
	lblSoundPath->setText( i18n("Sound path:" ) );
	pbSound->setText( i18n("Browse" ) );
	gbQuickReply->setTitle( i18n("Quick Reply (within 50 words):" ) );
	pbQuickNew->setText( i18n("New" ) );
	pbQuickDelete->setText( i18n("Delete" ) );
	gbAutoReply->setTitle( i18n("Auto-Reply (within 50 words):" ) );
	chbAutoReply->setText( i18n("Reply automatically when away" ) );
	pbAutoNew->setText( i18n("New" ) );
	pbAutoDelete->setText( i18n("Delete" ) );
	pbFaceDefault->setText( i18n("Default" ) );
	pbOk->setText( i18n("OK" ) );
	pbApply->setText( i18n("Apply" ) );
	pbCancel->setText( i18n("Cancel" ) );
}

