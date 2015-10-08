/***************************************************************************
 *   Copyright (C) 2005 by casper                                          *
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
 
#include "evauseruibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqlabel.h>
#include <ntqtabwidget.h>
#include <ntqwidget.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <ntqtextedit.h>
#include <ntqlineedit.h>
#include <ntqcheckbox.h>
#include <tdelocale.h>

/*
 *  Constructs a EvaUserUIBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
EvaUserUIBase::EvaUserUIBase( TQWidget* parent, const char* name, bool modal, WFlags fl )
    : TQDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "EvaUserUIBase" );
    setMinimumSize( TQSize( 512, 360 ) );
    setMaximumSize( TQSize( 512, 360 ) );

    pbUpdate = new TQPushButton( this, "pbUpdate" );
    pbUpdate->setGeometry( TQRect( 330, 330, 69, 24 ) );

    pbClose = new TQPushButton( this, "pbClose" );
    pbClose->setGeometry( TQRect( 430, 330, 69, 24 ) );

    lblText = new TQLabel( this, "lblText" );
    lblText->setGeometry( TQRect( 10, 330, 200, 19 ) );

    twTabMain = new TQTabWidget( this, "twTabMain" );
    twTabMain->setGeometry( TQRect( 5, 5, 501, 320 ) );
    twTabMain->setMargin( 10 );

    svMain = new TQScrollView( twTabMain, "svMain" );
    svMain->setStaticBackground ( TRUE );
    svMain->setHScrollBarMode(TQScrollView::AlwaysOff);
    svMain->setFrameShape(TQFrame::NoFrame);
    
    qwUserInfo = new EvaUserInfoWidget( svMain, "qwUserInfo");
    svMain->addChild( qwUserInfo );
    
    twTabMain->insertTab( svMain, TQString("") );
   
    //TQQShow Widget For TabWidget
    tabTQQShow = new TQWidget( twTabMain, "tabTQQShow" );
    ///////////////////////////////////////////////////////////////////////
    //lblTQQShowBar = new TQLabel( tabTQQShow, "lblTQQShowBar" );
    //lblTQQShowBar->setGeometry( TQRect( 0, 10, 480, 16 ) );
    
    TQWidget* privateLayoutWidget = new TQWidget( tabTQQShow, "layout13" );
    privateLayoutWidget->setGeometry( TQRect( 10, -15, 350, 290 ) );
    layout13 = new TQGridLayout( privateLayoutWidget, 1, 1, 11, 6, "layout13"); 

    lblTQQShow = new TQLabel( privateLayoutWidget, "lblTQQShow" );
    lblTQQShow->setMinimumSize( TQSize( 147, 233 ) );
    lblTQQShow->setMaximumSize( TQSize( 147, 233 ) );
    lblTQQShow->setFrameShape( TQLabel::Box );
    lblTQQShow->setPaletteBackgroundColor( TQColor( 255, 255, 255 ) );
    lblTQQShow->setScaledContents( FALSE );
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
    twTabMain->insertTab( tabTQQShow, TQString("") );
    ///////////////////////////////////////////////////////////////////////
    //Memo Widget
    TabMemo = new TQWidget( twTabMain, "TabMemo" );
    TabMemoLayout = new TQGridLayout( TabMemo, 1, 1, 11, 6, "TabMemoLayout"); 
    spacer30 = new TQSpacerItem( 20, 21, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    TabMemoLayout->addItem( spacer30, 1, 0 );
    spacer29 = new TQSpacerItem( 91, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    TabMemoLayout->addItem( spacer29, 0, 1 );

    layout117 = new TQVBoxLayout( 0, 0, 6, "layout117"); 

    layout100 = new TQHBoxLayout( 0, 0, 6, "layout100"); 

    layout97 = new TQVBoxLayout( 0, 0, 6, "layout97"); 

    lblMemoName = new TQLabel( TabMemo, "lblMemoName" );
    layout97->addWidget( lblMemoName );

    lblMemoMobile = new TQLabel( TabMemo, "lblMemoMobile" );
    layout97->addWidget( lblMemoMobile );

    lblMemoAddress = new TQLabel( TabMemo, "lblMemoAddress" );
    layout97->addWidget( lblMemoAddress );

    lblMemoEmail = new TQLabel( TabMemo, "lblMemoEmail" );
    layout97->addWidget( lblMemoEmail );
    layout100->addLayout( layout97 );

    layout99 = new TQVBoxLayout( 0, 0, 6, "layout99"); 

    layout98 = new TQHBoxLayout( 0, 0, 6, "layout98"); 

    layout80 = new TQVBoxLayout( 0, 0, 6, "layout80"); 

    leMemoName = new TQLineEdit( TabMemo, "leMemoName" );
    leMemoName->setFrameShape( TQLineEdit::Box );
    leMemoName->setFrameShadow( TQLineEdit::Plain );
    leMemoName->setLineWidth( 1 );
    layout80->addWidget( leMemoName );

    leMemoMobile = new TQLineEdit( TabMemo, "leMemoMobile" );
    leMemoMobile->setFrameShape( TQLineEdit::Box );
    leMemoMobile->setFrameShadow( TQLineEdit::Plain );
    leMemoMobile->setLineWidth( 1 );
    layout80->addWidget( leMemoMobile );
    layout98->addLayout( layout80 );

    layout81 = new TQVBoxLayout( 0, 0, 6, "layout81"); 

    lblMemoTelephone = new TQLabel( TabMemo, "lblMemoTelephone" );
    layout81->addWidget( lblMemoTelephone );

    lblMemoZipCode = new TQLabel( TabMemo, "lblMemoZipCode" );
    layout81->addWidget( lblMemoZipCode );
    layout98->addLayout( layout81 );

    layout82 = new TQVBoxLayout( 0, 0, 6, "layout82"); 

    leMemoTelephone = new TQLineEdit( TabMemo, "leMemoTelephone" );
    leMemoTelephone->setFrameShape( TQLineEdit::Box );
    leMemoTelephone->setFrameShadow( TQLineEdit::Plain );
    leMemoTelephone->setLineWidth( 1 );
    layout82->addWidget( leMemoTelephone );

    leMemoZipCode = new TQLineEdit( TabMemo, "leMemoZipCode" );
    leMemoZipCode->setFrameShape( TQLineEdit::Box );
    leMemoZipCode->setFrameShadow( TQLineEdit::Plain );
    leMemoZipCode->setLineWidth( 1 );
    layout82->addWidget( leMemoZipCode );
    layout98->addLayout( layout82 );
    layout99->addLayout( layout98 );

    layout86 = new TQVBoxLayout( 0, 0, 6, "layout86"); 

    leMemoAddress = new TQLineEdit( TabMemo, "leMemoAddress" );
    leMemoAddress->setFrameShape( TQLineEdit::Box );
    leMemoAddress->setFrameShadow( TQLineEdit::Plain );
    leMemoAddress->setLineWidth( 1 );
    layout86->addWidget( leMemoAddress );

    leMemoEmail = new TQLineEdit( TabMemo, "leMemoEmail" );
    leMemoEmail->setFrameShape( TQLineEdit::Box );
    leMemoEmail->setFrameShadow( TQLineEdit::Plain );
    leMemoEmail->setLineWidth( 1 );
    layout86->addWidget( leMemoEmail );
    layout99->addLayout( layout86 );
    layout100->addLayout( layout99 );
    layout117->addLayout( layout100 );

    layout112 = new TQHBoxLayout( 0, 0, 6, "layout112"); 

    layout111 = new TQVBoxLayout( 0, 0, 6, "layout111"); 

    lblMemoNote = new TQLabel( TabMemo, "lblMemoNote" );
    layout111->addWidget( lblMemoNote );
    spacer32 = new TQSpacerItem( 20, 20, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout111->addItem( spacer32 );
    layout112->addLayout( layout111 );

    teMemoNote = new TQTextEdit( TabMemo, "teMemoNote" );
    teMemoNote->setMinimumSize( TQSize( 0, 50 ) );
    teMemoNote->setMaximumSize( TQSize( 32767, 50 ) );
    teMemoNote->setFrameShape( TQTextEdit::Box );
    teMemoNote->setFrameShadow( TQTextEdit::Plain );
    teMemoNote->setLineWidth( 1 );
    layout112->addWidget( teMemoNote );
    layout117->addLayout( layout112 );
    spacer38 = new TQSpacerItem( 20, 21, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout117->addItem( spacer38 );

    layout116 = new TQHBoxLayout( 0, 0, 6, "layout116"); 
    spacer34 = new TQSpacerItem( 40, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout116->addItem( spacer34 );

    chbAutoUploadMemo = new TQCheckBox( TabMemo, "chbAutoUploadMemo" );
    layout116->addWidget( chbAutoUploadMemo );
    spacer33 = new TQSpacerItem( 61, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout116->addItem( spacer33 );

    pbDownloadMemo = new TQPushButton( TabMemo, "pbDownloadMemo" );
    layout116->addWidget( pbDownloadMemo );
    layout117->addLayout( layout116 );

    TabMemoLayout->addLayout( layout117, 0, 0 );
    twTabMain->insertTab( TabMemo, TQString("") );

    //////////////////////////////////////////////////////////////////////
    
    languageChange();
    resize( TQSize(512, 345).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaUserUIBase::~EvaUserUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaUserUIBase::languageChange()
{
    setCaption( i18n( "User Info" ) );
    pbUpdate->setText( i18n( "Update" ) );
    pbClose->setText( i18n( "Close" ) );
    lblText->setText( "<p align=\"center\"><font color=\"#00557f\"><b>" + i18n("Enjoy Eva, Enjoy Open Source!") + "</b></font></p>" );
    
    //lblTQQShowBar->setText( i18n( " QQ Show Bar" ) );
    lblTQQShow->setText( i18n( "QQ Show" ) );
    //tbtnHome->setTextLabel( i18n( "QQ home" ) );
    tbtnAlbum->setTextLabel( i18n( "check QQ Show album" ) );
    kpbUpdateShow->setText( i18n( "Update QQ Show" ) );
    tbtnShop->setTextLabel( i18n( "go to QQ Show shop" ) );

    twTabMain->changeTab( svMain, i18n( "User Info" ) );
    twTabMain->changeTab( tabTQQShow, i18n( "TQQShow" ) );
    
    lblMemoName->setText( i18n( "Name:" ) );
    lblMemoMobile->setText( i18n( "Mobile:" ) );
    lblMemoAddress->setText( i18n( "Address:" ) );
    lblMemoEmail->setText( i18n( "Email:" ) );
    lblMemoTelephone->setText( i18n( "Telephone:" ) );
    lblMemoZipCode->setText( i18n( "Postal Code:" ) );
    lblMemoNote->setText( i18n( "Note:" ) );
    chbAutoUploadMemo->setText( i18n( "Auto Upload Memo" ) );
    pbDownloadMemo->setText( i18n( "Download Memo" ) );
    twTabMain->changeTab( TabMemo, i18n( "Memo" ) );

}

