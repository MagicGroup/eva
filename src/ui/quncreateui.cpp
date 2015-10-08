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
#include "quncreateui.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqlabel.h>
#include <ntqframe.h>
#include <ntqwidgetstack.h>
#include <ntqlineedit.h>
#include <ntqtoolbutton.h>
#include <ntqgroupbox.h>
#include <ntqtextedit.h>
#include <ntqbuttongroup.h>
#include <ntqradiobutton.h>
#include <ntqtable.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <tdelocale.h>

/*
 *  Constructs a QunCreateUI as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
QunCreateUI::QunCreateUI( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "QunCreateUI" );
    QunCreateUILayout = new TQVBoxLayout( this, 11, 6, "QunCreateUILayout"); 

    lblTip = new TQLabel( this, "lblTip" );
    QunCreateUILayout->addWidget( lblTip );

    line1 = new TQFrame( this, "line1" );
    line1->setFrameShape( TQFrame::HLine );
    line1->setFrameShadow( TQFrame::Sunken );
    line1->setFrameShape( TQFrame::HLine );
    QunCreateUILayout->addWidget( line1 );

    wsMain = new TQWidgetStack( this, "wsMain" );

    wsDetails = new TQWidget( wsMain, "wsDetails" );
    wsDetailsLayout = new TQGridLayout( wsDetails, 1, 1, 11, 6, "wsDetailsLayout"); 

    layout44 = new TQVBoxLayout( 0, 0, 16, "layout44"); 

    layout40 = new TQHBoxLayout( 0, 0, 9, "layout40"); 

    lblName = new TQLabel( wsDetails, "lblName" );
    layout40->addWidget( lblName );

    leQunName = new TQLineEdit( wsDetails, "leQunName" );
    layout40->addWidget( leQunName );
    spacer15 = new TQSpacerItem( 51, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout40->addItem( spacer15 );
    layout44->addLayout( layout40 );

    layout41 = new TQHBoxLayout( 0, 0, 7, "layout41"); 

    lblCategory = new TQLabel( wsDetails, "lblCategory" );
    lblCategory->setMaximumSize( TQSize( 50, 32767 ) );
    layout41->addWidget( lblCategory );

    tbCategory = new TQToolButton( wsDetails, "tbCategory" );
    tbCategory->setMaximumSize( TQSize( 32767, 30 ) );
    layout41->addWidget( tbCategory );
    spacer16 = new TQSpacerItem( 51, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout41->addItem( spacer16 );
    layout44->addLayout( layout41 );

    gbNotice = new TQGroupBox( wsDetails, "gbNotice" );
    gbNotice->setColumnLayout(0, TQt::Vertical );
    gbNotice->layout()->setSpacing( 6 );
    gbNotice->layout()->setMargin( 11 );
    gbNoticeLayout = new TQGridLayout( gbNotice->layout() );
    gbNoticeLayout->setAlignment( TQt::AlignTop );

    teNotice = new TQTextEdit( gbNotice, "teNotice" );
    teNotice->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)5, 0, 0, teNotice->sizePolicy().hasHeightForWidth() ) );
    teNotice->setMaximumSize( TQSize( 32767, 50 ) );

    gbNoticeLayout->addWidget( teNotice, 0, 0 );
    layout44->addWidget( gbNotice );

    gbDescription = new TQGroupBox( wsDetails, "gbDescription" );
    gbDescription->setColumnLayout(0, TQt::Vertical );
    gbDescription->layout()->setSpacing( 6 );
    gbDescription->layout()->setMargin( 11 );
    gbDescriptionLayout = new TQGridLayout( gbDescription->layout() );
    gbDescriptionLayout->setAlignment( TQt::AlignTop );

    teDescription = new TQTextEdit( gbDescription, "teDescription" );
    teDescription->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)5, 0, 0, teDescription->sizePolicy().hasHeightForWidth() ) );
    teDescription->setMaximumSize( TQSize( 32767, 60 ) );

    gbDescriptionLayout->addWidget( teDescription, 0, 0 );
    layout44->addWidget( gbDescription );

    bgAuthen = new TQButtonGroup( wsDetails, "bgAuthen" );
    bgAuthen->setExclusive( TRUE );
    bgAuthen->setColumnLayout(0, TQt::Vertical );
    bgAuthen->layout()->setSpacing( 6 );
    bgAuthen->layout()->setMargin( 11 );
    bgAuthenLayout = new TQVBoxLayout( bgAuthen->layout() );
    bgAuthenLayout->setAlignment( TQt::AlignTop );

    rbNoAuthenNeed = new TQRadioButton( bgAuthen, "rbNoAuthenNeed" );
    bgAuthenLayout->addWidget( rbNoAuthenNeed );

    rbNeedAuthen = new TQRadioButton( bgAuthen, "rbNeedAuthen" );
    rbNeedAuthen->setChecked( TRUE );
    bgAuthenLayout->addWidget( rbNeedAuthen );

    rbRejectAnyone = new TQRadioButton( bgAuthen, "rbRejectAnyone" );
    bgAuthenLayout->addWidget( rbRejectAnyone );
    layout44->addWidget( bgAuthen );

    wsDetailsLayout->addLayout( layout44, 0, 0 );
    wsMain->addWidget( wsDetails, 0 );

    wsMembers = new TQWidget( wsMain, "wsMembers" );
    wsMembersLayout = new TQGridLayout( wsMembers, 1, 1, 11, 6, "wsMembersLayout"); 

    layout43 = new TQHBoxLayout( 0, 0, 6, "layout43"); 

    tblMembers = new TQTable( wsMembers, "tblMembers" );
    tblMembers->setNumCols( tblMembers->numCols() + 1 );
    tblMembers->horizontalHeader()->setLabel( tblMembers->numCols() - 1, i18n( "QQ" ) );
    tblMembers->setNumCols( tblMembers->numCols() + 1 );
    tblMembers->horizontalHeader()->setLabel( tblMembers->numCols() - 1, i18n( "Nick" ) );
    tblMembers->setNumCols( tblMembers->numCols() + 1 );
    tblMembers->horizontalHeader()->setLabel( tblMembers->numCols() - 1, i18n( "Gender" ) );
    tblMembers->setMinimumSize( TQSize( 250, 0 ) );
    tblMembers->setMaximumSize( TQSize( 32767, 32767 ) );
    tblMembers->setHScrollBarMode( TQTable::AlwaysOff );
    tblMembers->setNumRows( 3 );
    tblMembers->setNumCols( 4 );
    layout43->addWidget( tblMembers );

    layout42 = new TQVBoxLayout( 0, 0, 6, "layout42"); 

    pbSetMembers = new TQPushButton( wsMembers, "pbSetMembers" );
    layout42->addWidget( pbSetMembers );

    pbDelMembers = new TQPushButton( wsMembers, "pbDelMembers" );
    layout42->addWidget( pbDelMembers );
    spacer17 = new TQSpacerItem( 20, 141, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout42->addItem( spacer17 );
    layout43->addLayout( layout42 );

    wsMembersLayout->addLayout( layout43, 0, 0 );
    wsMain->addWidget( wsMembers, 1 );
    QunCreateUILayout->addWidget( wsMain );

    layout7 = new TQHBoxLayout( 0, 0, 6, "layout7"); 
    spacer18 = new TQSpacerItem( 270, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout7->addItem( spacer18 );

    pbPrev = new TQPushButton( this, "pbPrev" );
    layout7->addWidget( pbPrev );

    pbNext = new TQPushButton( this, "pbNext" );
    layout7->addWidget( pbNext );

    pbCancel = new TQPushButton( this, "pbCancel" );
    layout7->addWidget( pbCancel );
    QunCreateUILayout->addLayout( layout7 );
    languageChange();
    resize( TQSize(487, 502).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( leQunName, teNotice );
    setTabOrder( teNotice, teDescription );
    setTabOrder( teDescription, rbNeedAuthen );
    setTabOrder( rbNeedAuthen, tblMembers );
    setTabOrder( tblMembers, pbSetMembers );
    setTabOrder( pbSetMembers, pbDelMembers );
    setTabOrder( pbDelMembers, pbNext );
    setTabOrder( pbNext, pbCancel );
}

/*
 *  Destroys the object and frees any allocated resources
 */
QunCreateUI::~QunCreateUI()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void QunCreateUI::languageChange()
{
    setCaption( i18n( "Create Qun" ) );
    lblTip->setText( i18n( "Please input Qun details below, then click \"Next\"" ) );
    lblName->setText( i18n( "Name" ) );
    lblCategory->setText( i18n( "Category" ) );
    tbCategory->setText( i18n( "Select a category" ) );
    gbNotice->setTitle( i18n( "Qun Notice (member only)" ) );
    gbDescription->setTitle( i18n( "Qun Description" ) );
    bgAuthen->setTitle( i18n( "Authentication" ) );
    rbNoAuthenNeed->setText( i18n( "No authentication needed." ) );
    rbNeedAuthen->setText( i18n( "Need authentication" ) );
    rbRejectAnyone->setText( i18n( "Reject any request" ) );
    tblMembers->horizontalHeader()->setLabel( 0, i18n( "QQ" ) );
    tblMembers->horizontalHeader()->setLabel( 1, i18n( "Nick" ) );
    tblMembers->horizontalHeader()->setLabel( 2, i18n( "Gender" ) );
    pbSetMembers->setText( i18n( "&Members >>" ) );
    pbSetMembers->setAccel( TQKeySequence( i18n( "Alt+M" ) ) );
    pbDelMembers->setText( i18n( "&Del Members" ) );
    pbDelMembers->setAccel( TQKeySequence( i18n( "Alt+D" ) ) );
    pbPrev->setText( i18n( "&Prev" ) );
    pbPrev->setAccel( TQKeySequence( i18n( "Alt+P" ) ) );
    pbNext->setText( i18n( "&Next" ) );
    pbNext->setAccel( TQKeySequence( i18n( "Alt+N" ) ) );
    pbCancel->setText( i18n( "&Cancel" ) );
    pbCancel->setAccel( TQKeySequence( i18n( "Alt+C" ) ) );
}

