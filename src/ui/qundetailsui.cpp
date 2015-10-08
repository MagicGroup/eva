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
#include "qundetailsui.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqlabel.h>
#include <ntqtabwidget.h>
#include <ntqlineedit.h>
#include <ntqtoolbutton.h>
#include <ntqgroupbox.h>
#include <ntqtextedit.h>
#include <ntqbuttongroup.h>
#include <ntqradiobutton.h>
#include <ntqtable.h>
#include <ntqcombobox.h>
#include <ntqframe.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <ntqimage.h>
#include <ntqpixmap.h>
#include <tdelocale.h>

/*
 *  Constructs a QunDetailsUI as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
QunDetailsUI::QunDetailsUI( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "QunDetailsUI" );
    QunDetailsUILayout = new TQVBoxLayout( this, 11, 6, "QunDetailsUILayout"); 

    layout18 = new TQHBoxLayout( 0, 0, 1, "layout18"); 

    lblLogo = new TQLabel( this, "lblLogo" );
    lblLogo->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, lblLogo->sizePolicy().hasHeightForWidth() ) );
    lblLogo->setMinimumSize( TQSize( 120, 0 ) );
    lblLogo->setMaximumSize( TQSize( 120, 32767 ) );
    layout18->addWidget( lblLogo );

    tabWMain = new TQTabWidget( this, "tabWMain" );
    tabWMain->setTabShape( TQTabWidget::Triangular );

    tabDetails = new TQWidget( tabWMain, "tabDetails" );
    tabDetailsLayout = new TQVBoxLayout( tabDetails, 11, 6, "tabDetailsLayout"); 

    layout17 = new TQHBoxLayout( 0, 0, 6, "layout17"); 

    layout1 = new TQVBoxLayout( 0, 0, 6, "layout1"); 

    lblID = new TQLabel( tabDetails, "lblID" );
    layout1->addWidget( lblID );

    lblCreator = new TQLabel( tabDetails, "lblCreator" );
    layout1->addWidget( lblCreator );

    lblName = new TQLabel( tabDetails, "lblName" );
    layout1->addWidget( lblName );
    layout17->addLayout( layout1 );

    layout2 = new TQVBoxLayout( 0, 0, 6, "layout2"); 

    leQunID = new TQLineEdit( tabDetails, "leQunID" );
    leQunID->setReadOnly( TRUE );
    layout2->addWidget( leQunID );

    leCreator = new TQLineEdit( tabDetails, "leCreator" );
    leCreator->setReadOnly( TRUE );
    layout2->addWidget( leCreator );

    leQunName = new TQLineEdit( tabDetails, "leQunName" );
    layout2->addWidget( leQunName );
    layout17->addLayout( layout2 );

    layout25 = new TQVBoxLayout( 0, 0, 6, "layout25"); 

    layout5 = new TQHBoxLayout( 0, 0, 6, "layout5"); 
    spacer1 = new TQSpacerItem( 31, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout5->addItem( spacer1 );

    lblQunFace = new TQLabel( tabDetails, "lblQunFace" );
    lblQunFace->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, lblQunFace->sizePolicy().hasHeightForWidth() ) );
    lblQunFace->setMinimumSize( TQSize( 60, 60 ) );
    lblQunFace->setMaximumSize( TQSize( 60, 60 ) );
    lblQunFace->setAlignment( int( TQLabel::AlignCenter ) );
    layout5->addWidget( lblQunFace );
    layout25->addLayout( layout5 );

    layout24 = new TQHBoxLayout( 0, 0, 6, "layout24"); 

    lblCategory = new TQLabel( tabDetails, "lblCategory" );
    lblCategory->setMaximumSize( TQSize( 50, 32767 ) );
    layout24->addWidget( lblCategory );

    tbCategory = new TQToolButton( tabDetails, "tbCategory" );
    layout24->addWidget( tbCategory );
    layout25->addLayout( layout24 );
    layout17->addLayout( layout25 );
    tabDetailsLayout->addLayout( layout17 );

    gbNotice = new TQGroupBox( tabDetails, "gbNotice" );
    gbNotice->setColumnLayout(0, TQt::Vertical );
    gbNotice->layout()->setSpacing( 6 );
    gbNotice->layout()->setMargin( 11 );
    gbNoticeLayout = new TQGridLayout( gbNotice->layout() );
    gbNoticeLayout->setAlignment( TQt::AlignTop );

    teNotice = new TQTextEdit( gbNotice, "teNotice" );
    teNotice->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)5, 0, 0, teNotice->sizePolicy().hasHeightForWidth() ) );
    teNotice->setMaximumSize( TQSize( 32767, 50 ) );

    gbNoticeLayout->addWidget( teNotice, 0, 0 );
    tabDetailsLayout->addWidget( gbNotice );

    gbDescription = new TQGroupBox( tabDetails, "gbDescription" );
    gbDescription->setColumnLayout(0, TQt::Vertical );
    gbDescription->layout()->setSpacing( 6 );
    gbDescription->layout()->setMargin( 11 );
    gbDescriptionLayout = new TQGridLayout( gbDescription->layout() );
    gbDescriptionLayout->setAlignment( TQt::AlignTop );

    teDescription = new TQTextEdit( gbDescription, "teDescription" );
    teDescription->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)5, 0, 0, teDescription->sizePolicy().hasHeightForWidth() ) );
    teDescription->setMaximumSize( TQSize( 32767, 60 ) );

    gbDescriptionLayout->addWidget( teDescription, 0, 0 );
    tabDetailsLayout->addWidget( gbDescription );

    bgAuthen = new TQButtonGroup( tabDetails, "bgAuthen" );
    bgAuthen->setExclusive( TRUE );
    bgAuthen->setColumnLayout(0, TQt::Vertical );
    bgAuthen->layout()->setSpacing( 6 );
    bgAuthen->layout()->setMargin( 11 );
    bgAuthenLayout = new TQVBoxLayout( bgAuthen->layout() );
    bgAuthenLayout->setAlignment( TQt::AlignTop );

    rbNoAuthenNeed = new TQRadioButton( bgAuthen, "rbNoAuthenNeed" );
    bgAuthenLayout->addWidget( rbNoAuthenNeed );

    rbNeedAuthen = new TQRadioButton( bgAuthen, "rbNeedAuthen" );
    bgAuthenLayout->addWidget( rbNeedAuthen );

    rbRejectAnyone = new TQRadioButton( bgAuthen, "rbRejectAnyone" );
    bgAuthenLayout->addWidget( rbRejectAnyone );
    tabDetailsLayout->addWidget( bgAuthen );
    tabWMain->insertTab( tabDetails, TQString("") );

    tabMember = new TQWidget( tabWMain, "tabMember" );
    tabMemberLayout = new TQGridLayout( tabMember, 1, 1, 11, 6, "tabMemberLayout"); 

    layout17_2 = new TQHBoxLayout( 0, 0, 6, "layout17_2"); 

    tblMembers = new TQTable( tabMember, "tblMembers" );
    tblMembers->setNumCols( tblMembers->numCols() + 1 );
    tblMembers->horizontalHeader()->setLabel( tblMembers->numCols() - 1, i18n( "QQ" ) );
    tblMembers->setNumCols( tblMembers->numCols() + 1 );
    tblMembers->horizontalHeader()->setLabel( tblMembers->numCols() - 1, i18n( "Nick" ) );
    tblMembers->setNumCols( tblMembers->numCols() + 1 );
    tblMembers->horizontalHeader()->setLabel( tblMembers->numCols() - 1, i18n( "Gender" ) );
    tblMembers->setMinimumSize( TQSize( 250, 0 ) );
    tblMembers->setHScrollBarMode( TQTable::AlwaysOff );
    tblMembers->setNumRows( 3 );
    tblMembers->setNumCols( 4 );
    layout17_2->addWidget( tblMembers );

    layout16 = new TQVBoxLayout( 0, 0, 6, "layout16"); 

    pbSetMembers = new TQPushButton( tabMember, "pbSetMembers" );
    layout16->addWidget( pbSetMembers );

    pbAddToMe = new TQPushButton( tabMember, "pbAddToMe" );
    layout16->addWidget( pbAddToMe );

    pbDelMembers = new TQPushButton( tabMember, "pbDelMembers" );
    layout16->addWidget( pbDelMembers );
    spacer6 = new TQSpacerItem( 20, 30, TQSizePolicy::Minimum, TQSizePolicy::Fixed );
    layout16->addItem( spacer6 );

    pbSetAdmin = new TQPushButton( tabMember, "pbSetAdmin" );
    layout16->addWidget( pbSetAdmin );

    pbUnsetAdmin = new TQPushButton( tabMember, "pbUnsetAdmin" );
    layout16->addWidget( pbUnsetAdmin );

    pbTransfer = new TQPushButton( tabMember, "pbTransfer" );
    layout16->addWidget( pbTransfer );
    spacer7 = new TQSpacerItem( 20, 31, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout16->addItem( spacer7 );
    layout17_2->addLayout( layout16 );

    tabMemberLayout->addLayout( layout17_2, 0, 0 );
    tabWMain->insertTab( tabMember, TQString("") );

    tabSetting = new TQWidget( tabWMain, "tabSetting" );
    tabSettingLayout = new TQGridLayout( tabSetting, 1, 1, 11, 6, "tabSettingLayout"); 

    bgSettings = new TQButtonGroup( tabSetting, "bgSettings" );
    bgSettings->setExclusive( TRUE );
    bgSettings->setColumnLayout(0, TQt::Vertical );
    bgSettings->layout()->setSpacing( 6 );
    bgSettings->layout()->setMargin( 11 );
    bgSettingsLayout = new TQVBoxLayout( bgSettings->layout() );
    bgSettingsLayout->setAlignment( TQt::AlignTop );

    rbRecord_Show = new TQRadioButton( bgSettings, "rbRecord_Show" );
    bgSettingsLayout->addWidget( rbRecord_Show );

    rbPopupWindow = new TQRadioButton( bgSettings, "rbPopupWindow" );
    bgSettingsLayout->addWidget( rbPopupWindow );

    rbDisplayNumbers = new TQRadioButton( bgSettings, "rbDisplayNumbers" );
    bgSettingsLayout->addWidget( rbDisplayNumbers );

    rbRecord_only = new TQRadioButton( bgSettings, "rbRecord_only" );
    bgSettingsLayout->addWidget( rbRecord_only );

    rbRejectMsgs = new TQRadioButton( bgSettings, "rbRejectMsgs" );
    bgSettingsLayout->addWidget( rbRejectMsgs );

    tabSettingLayout->addWidget( bgSettings, 0, 0 );
    tabWMain->insertTab( tabSetting, TQString("") );

    TabCard = new TQWidget( tabWMain, "TabCard" );
    TabCardLayout = new TQVBoxLayout( TabCard, 11, 6, "TabCardLayout"); 

    layout19 = new TQHBoxLayout( 0, 0, 6, "layout19"); 

    layout11 = new TQVBoxLayout( 0, 0, 6, "layout11"); 

    lblMyName = new TQLabel( TabCard, "lblMyName" );
    layout11->addWidget( lblMyName );

    lblMyGender = new TQLabel( TabCard, "lblMyGender" );
    layout11->addWidget( lblMyGender );

    lblMyPhone = new TQLabel( TabCard, "lblMyPhone" );
    layout11->addWidget( lblMyPhone );

    lblMyEmail = new TQLabel( TabCard, "lblMyEmail" );
    layout11->addWidget( lblMyEmail );
    layout19->addLayout( layout11 );

    layout18_2 = new TQVBoxLayout( 0, 0, 6, "layout18_2"); 

    leMyName = new TQLineEdit( TabCard, "leMyName" );
    layout18_2->addWidget( leMyName );

    layout17_3 = new TQHBoxLayout( 0, 0, 6, "layout17_3"); 

    cbbMyGender = new TQComboBox( FALSE, TabCard, "cbbMyGender" );
    layout17_3->addWidget( cbbMyGender );
    spacer4 = new TQSpacerItem( 61, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout17_3->addItem( spacer4 );
    layout18_2->addLayout( layout17_3 );

    leMyPhone = new TQLineEdit( TabCard, "leMyPhone" );
    layout18_2->addWidget( leMyPhone );

    leMyEmail = new TQLineEdit( TabCard, "leMyEmail" );
    layout18_2->addWidget( leMyEmail );
    layout19->addLayout( layout18_2 );
    TabCardLayout->addLayout( layout19 );

    layout20 = new TQHBoxLayout( 0, 0, 6, "layout20"); 

    line1 = new TQFrame( TabCard, "line1" );
    line1->setFrameShape( TQFrame::HLine );
    line1->setFrameShadow( TQFrame::Sunken );
    line1->setFrameShape( TQFrame::HLine );
    layout20->addWidget( line1 );
    spacer5 = new TQSpacerItem( 20, 20, TQSizePolicy::Preferred, TQSizePolicy::Minimum );
    layout20->addItem( spacer5 );
    TabCardLayout->addLayout( layout20 );

    layout21 = new TQHBoxLayout( 0, 0, 6, "layout21"); 

    layout15 = new TQVBoxLayout( 0, 0, 6, "layout15"); 

    lblMyComment = new TQLabel( TabCard, "lblMyComment" );
    layout15->addWidget( lblMyComment );
    spacer3 = new TQSpacerItem( 20, 151, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout15->addItem( spacer3 );
    layout21->addLayout( layout15 );

    teMyMemo = new TQTextEdit( TabCard, "teMyMemo" );
    layout21->addWidget( teMyMemo );
    TabCardLayout->addLayout( layout21 );
    tabWMain->insertTab( TabCard, TQString("") );
    layout18->addWidget( tabWMain );
    QunDetailsUILayout->addLayout( layout18 );

    layout9 = new TQHBoxLayout( 0, 0, 6, "layout9"); 
    spacer2 = new TQSpacerItem( 91, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout9->addItem( spacer2 );

    pbUpdate = new TQPushButton( this, "pbUpdate" );
    layout9->addWidget( pbUpdate );

    pbClose = new TQPushButton( this, "pbClose" );
    layout9->addWidget( pbClose );
    QunDetailsUILayout->addLayout( layout9 );
    languageChange();
    resize( TQSize(535, 488).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
QunDetailsUI::~QunDetailsUI()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void QunDetailsUI::languageChange()
{
    setCaption( i18n( "Qun" ) );
    lblLogo->setText( i18n( "Qun Details" ) );
    lblID->setText( i18n( "Qun ID" ) );
    lblCreator->setText( i18n( "Creator" ) );
    lblName->setText( i18n( "Name" ) );
    lblQunFace->setText( i18n( "Qun Face" ) );
    lblCategory->setText( i18n( "Category" ) );
    tbCategory->setText( TQString::null );
    gbNotice->setTitle( i18n( "Qun Notice (member only)" ) );
    gbDescription->setTitle( i18n( "Qun Description" ) );
    bgAuthen->setTitle( i18n( "Authentication" ) );
    rbNoAuthenNeed->setText( i18n( "No authentication needed." ) );
    rbNeedAuthen->setText( i18n( "Need authentication" ) );
    rbRejectAnyone->setText( i18n( "Reject any request" ) );
    tabWMain->changeTab( tabDetails, i18n( "Details" ) );
    tblMembers->horizontalHeader()->setLabel( 0, i18n( "QQ" ) );
    tblMembers->horizontalHeader()->setLabel( 1, i18n( "Nick" ) );
    tblMembers->horizontalHeader()->setLabel( 2, i18n( "Gender" ) );
    pbSetMembers->setText( i18n( "&Members >>" ) );
    pbSetMembers->setAccel( TQKeySequence( i18n( "Alt+M" ) ) );
    pbAddToMe->setText( i18n( "&Add to Me" ) );
    pbAddToMe->setAccel( TQKeySequence( i18n( "Alt+A" ) ) );
    pbDelMembers->setText( i18n( "&Del Members" ) );
    pbDelMembers->setAccel( TQKeySequence( i18n( "Alt+D" ) ) );
    pbSetAdmin->setText( i18n( "&Set Admin" ) );
    pbSetAdmin->setAccel( TQKeySequence( i18n( "Alt+S" ) ) );
    pbUnsetAdmin->setText( i18n( "&Unset Admin" ) );
    pbUnsetAdmin->setAccel( TQKeySequence( i18n( "Alt+U" ) ) );
    pbTransfer->setText( i18n( "&Transfer" ) );
    pbTransfer->setAccel( TQKeySequence( i18n( "Alt+T" ) ) );
    tabWMain->changeTab( tabMember, i18n( "Members Setting" ) );
    bgSettings->setTitle( i18n( "when Qun message arrives" ) );
    rbRecord_Show->setText( i18n( "record and notify in system tray" ) );
    rbPopupWindow->setText( i18n( "popup chatting window" ) );
    rbDisplayNumbers->setText( i18n( "don't notify in system tray" ) );
    rbRecord_only->setText( i18n( "record only" ) );
    rbRejectMsgs->setText( i18n( "reject all messages from this Qun" ) );
    tabWMain->changeTab( tabSetting, i18n( "Message Setting" ) );
    lblMyName->setText( i18n( "Real Name" ) );
    lblMyGender->setText( i18n( "Gender" ) );
    lblMyPhone->setText( i18n( "Telephone" ) );
    lblMyEmail->setText( i18n( "Email" ) );
    cbbMyGender->clear();
    cbbMyGender->insertItem( i18n( "Male" ) );
    cbbMyGender->insertItem( i18n( "Female" ) );
    cbbMyGender->insertItem( i18n( "-" ) );
    lblMyComment->setText( i18n( "Memo" ) );
    tabWMain->changeTab( TabCard, i18n( "Qun Card" ) );
    pbUpdate->setText( i18n( "&Update" ) );
    pbUpdate->setAccel( TQKeySequence( i18n( "Alt+U" ) ) );
    pbClose->setText( i18n( "&Close" ) );
    pbClose->setAccel( TQKeySequence( i18n( "Alt+C" ) ) );
}

