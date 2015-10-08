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

#include "loginuibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqtoolbutton.h>
#include <ntqgroupbox.h>
#include <ntqlabel.h>
#include <ntqcombobox.h>
#include <ntqlineedit.h>
#include <ntqcheckbox.h>
#include <ntqframe.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <tdelocale.h>

LoginUIBase::LoginUIBase( TQWidget* parent, const char* name, bool modal, WFlags fl )
    : TQDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "frmLogin" );
    setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)5, 0, 0, sizePolicy().hasHeightForWidth() ) );
    setSizeGripEnabled( FALSE );

    cancelBtn = new TQPushButton( this, "cancelBtn" );
    cancelBtn->setGeometry( TQRect( 210, 170, 70, 23 ) );

    tbNetSetup = new TQToolButton( this, "tbNetSetup" );
    tbNetSetup->setGeometry( TQRect( 9, 170, 51, 23 ) );
    tbNetSetup->setCursor( TQCursor( 13 ) );
    tbNetSetup->setToggleButton( TRUE );
    tbNetSetup->setAutoRepeat( TRUE );
    tbNetSetup->setAutoRaise( TRUE );

    groupBox1 = new TQGroupBox( this, "groupBox1" );
    groupBox1->setGeometry( TQRect( 21, 51, 250, 115 ) );
    groupBox1->setColumnLayout(0, TQt::Vertical );
    groupBox1->layout()->setSpacing( 6 );
    groupBox1->layout()->setMargin( 11 );
    groupBox1Layout = new TQGridLayout( groupBox1->layout() );
    groupBox1Layout->setAlignment( TQt::AlignTop );

    layout14 = new TQHBoxLayout( 0, 0, 6, "layout14"); 
    spacer3 = new TQSpacerItem( 21, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout14->addItem( spacer3 );

    layout9 = new TQVBoxLayout( 0, 0, 6, "layout9"); 

    layout8 = new TQHBoxLayout( 0, 0, 6, "layout8"); 

    layout7 = new TQVBoxLayout( 0, 0, 6, "layout7"); 

    textLabel1 = new TQLabel( groupBox1, "textLabel1" );
    layout7->addWidget( textLabel1 );

    textLabel2 = new TQLabel( groupBox1, "textLabel2" );
    layout7->addWidget( textLabel2 );
    layout8->addLayout( layout7 );

    layout6 = new TQVBoxLayout( 0, 0, 6, "layout6"); 

    cbQQ = new TQComboBox( FALSE, groupBox1, "cbQQ" );
    cbQQ->setEditable( TRUE );
    layout6->addWidget( cbQQ );

    lePwd = new TQLineEdit( groupBox1, "lePwd" );
    lePwd->setEchoMode( TQLineEdit::Password );
    layout6->addWidget( lePwd );
    layout8->addLayout( layout6 );
    layout9->addLayout( layout8 );

    layout1 = new TQHBoxLayout( 0, 0, 6, "layout1"); 
    spacer1 = new TQSpacerItem( 41, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout1->addItem( spacer1 );

    chbRecordPwd = new TQCheckBox( groupBox1, "chbRecordPwd" );
    layout1->addWidget( chbRecordPwd );

    chbLoginMode = new TQCheckBox( groupBox1, "chbLoginMode" );
    layout1->addWidget( chbLoginMode );
    layout9->addLayout( layout1 );
    layout14->addLayout( layout9 );
    spacer2 = new TQSpacerItem( 20, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout14->addItem( spacer2 );

    groupBox1Layout->addLayout( layout14, 0, 0 );

    line1 = new TQFrame( this, "line1" );
    line1->setGeometry( TQRect( 31, 204, 200, 16 ) );
    line1->setFrameShape( TQFrame::HLine );
    line1->setFrameShadow( TQFrame::Sunken );
    line1->setFrameShape( TQFrame::HLine );

    lblType = new TQLabel( this, "lblType" );
    lblType->setGeometry(TQRect(20, 220, 106, 23));

    cbbLoginType = new TQComboBox( FALSE, this, "cbbLoginType" );
    cbbLoginType->setGeometry(TQRect(130, 220, 100, 23));

    loginBtn = new TQPushButton( this, "loginBtn" );
    loginBtn->setGeometry( TQRect( 127, 170, 61, 23 ) );
    loginBtn->setDefault(true);

    fraNetSetup = new TQFrame( this, "fraNetSetup" );
    fraNetSetup->setGeometry( TQRect( 1, 252, 290, 76 ) );
    fraNetSetup->setFrameShape( TQFrame::StyledPanel );
    fraNetSetup->setFrameShadow( TQFrame::Raised );
    fraNetSetupLayout = new TQGridLayout( fraNetSetup, 1, 1, 11, 6, "fraNetSetupLayout"); 

    layout13 = new TQVBoxLayout( 0, 0, 6, "layout13"); 

    layout12 = new TQHBoxLayout( 0, 0, 6, "layout12"); 

    tlProxyServer = new TQLabel( fraNetSetup, "tlProxyServer" );
    layout12->addWidget( tlProxyServer );

    leIP = new TQLineEdit( fraNetSetup, "leIP" );
    leIP->setMaximumSize( TQSize( 130, 32767 ) );
    layout12->addWidget( leIP );

    tlProxyPort = new TQLabel( fraNetSetup, "tlProxyPort" );
    tlProxyPort->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)1, 0, 0, tlProxyPort->sizePolicy().hasHeightForWidth() ) );
    layout12->addWidget( tlProxyPort );

    lePort = new TQLineEdit( fraNetSetup, "lePort" );
    lePort->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)5, 0, 0, lePort->sizePolicy().hasHeightForWidth() ) );
    lePort->setMaximumSize( TQSize( 35, 32767 ) );
    layout12->addWidget( lePort );
    layout13->addLayout( layout12 );

    layout11 = new TQHBoxLayout( 0, 0, 6, "layout11"); 

    tlUserName = new TQLabel( fraNetSetup, "tlUserName" );
    tlUserName->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)1, 0, 0, tlUserName->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( tlUserName );

    leUserName = new TQLineEdit( fraNetSetup, "leUserName" );
    leUserName->setMaximumSize( TQSize( 75, 32767 ) );
    layout11->addWidget( leUserName );

    tlPassword = new TQLabel( fraNetSetup, "tlPassword" );
    tlPassword->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)1, 0, 0, tlPassword->sizePolicy().hasHeightForWidth() ) );
    layout11->addWidget( tlPassword );

    lePassword = new TQLineEdit( fraNetSetup, "lePassword" );
    lePassword->setMaximumSize( TQSize( 75, 32767 ) );
    lePassword->setEchoMode( TQLineEdit::Password );
    layout11->addWidget( lePassword );
    layout13->addLayout( layout11 );

    fraNetSetupLayout->addLayout( layout13, 0, 0 );

    lblLogo = new TQLabel( this, "lblLogo" );
    lblLogo->setGeometry( TQRect( 0, 0, 292, 47 ) );
    lblLogo->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, lblLogo->sizePolicy().hasHeightForWidth() ) );
    lblLogo->setMaximumSize( TQSize( 345, 32767 ) );
    lblLogo->setScaledContents( TRUE );
    languageChange();
    resize( TQSize(292, 333).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( loginBtn, SIGNAL( clicked() ), this, SLOT( loginClickSlot() ) );
    connect( cancelBtn, SIGNAL( clicked() ), this, SLOT( cancelClickSlot() ) );
    //connect( tbNetSetup, SIGNAL( clicked() ), this, SLOT( tbNetSetupClicked() ) );
}

LoginUIBase::~LoginUIBase()
{
}

void LoginUIBase::languageChange()
{
    setCaption( i18n("Eva  - An IM Client" ) );
    cancelBtn->setText( i18n("Cancel" ) );
    tbNetSetup->setText( i18n("Network" ) );
    groupBox1->setTitle( i18n("User Login" ) );
    textLabel1->setText( i18n("Account:" ) );
    textLabel2->setText( i18n("Password:" ) );
    chbRecordPwd->setText( i18n("remember" ) );
    chbLoginMode->setText( i18n("Invisible" ) );
    lblType->setText( i18n("Connection Type:" ) );
    cbbLoginType->clear();
    cbbLoginType->insertItem( i18n("UDP" ) );
    cbbLoginType->insertItem( i18n("TCP" ) );
    cbbLoginType->insertItem( i18n("HTTP Proxy" ) );
    loginBtn->setText( i18n("Login" ) );
    tlProxyServer->setText( i18n("Proxy IP:" ) );
    tlProxyPort->setText( i18n("Port:" ) );
    tlUserName->setText( i18n("Username:" ) );
    tlPassword->setText( i18n("Password:" ) );
}

void LoginUIBase::loginClickSlot()
{
    tqWarning( "LoginUIBase::loginClickSlot(): Not implemented yet" );
}

void LoginUIBase::cancelClickSlot()
{
    tqWarning( "LoginUIBase::cancelClickSlot(): Not implemented yet" );
}


