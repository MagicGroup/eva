/***************************************************************************
 *   Copyright (C) 2004 by yunfan                                          *
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

#include "evaqunsysmsguibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqframe.h>
#include <ntqtoolbutton.h>
#include <ntqlabel.h>
#include <ntqbuttongroup.h>
#include <ntqradiobutton.h>
#include <ntqlineedit.h>
#include <ntqcheckbox.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>

#include <tdelocale.h>

/*
 *  Constructs a EvaQunSysMsgUIBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EvaQunSysMsgUIBase::EvaQunSysMsgUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "EvaQunSysMsgUIBase" );
    EvaQunSysMsgUIBaseLayout = new TQGridLayout( this, 1, 1, 17, 6, "EvaQunSysMsgUIBaseLayout"); 

    layout12 = new TQVBoxLayout( 0, 0, 6, "layout12"); 

    fraMain = new TQFrame( this, "fraMain" );
    fraMain->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)7, 0, 0, fraMain->sizePolicy().hasHeightForWidth() ) );
    fraMain->setPaletteBackgroundColor( TQColor( 234, 247, 255 ) );
    fraMain->setFrameShape( TQFrame::StyledPanel );
    fraMain->setFrameShadow( TQFrame::Raised );
    fraMainLayout = new TQVBoxLayout( fraMain, 11, 6, "fraMainLayout"); 

    layout6 = new TQVBoxLayout( 0, 0, 6, "layout6"); 

    layout5 = new TQHBoxLayout( 0, 0, 6, "layout5"); 

    tbQQ = new TQToolButton( fraMain, "tbQQ" );
    tbQQ->setPaletteBackgroundColor( TQColor( 234, 247, 255 ) );
    tbQQ->setAutoRaise( TRUE );
    layout5->addWidget( tbQQ );

    lblAction = new TQLabel( fraMain, "lblAction" );
    layout5->addWidget( lblAction );

    tbQun = new TQToolButton( fraMain, "tbQun" );
    tbQun->setPaletteBackgroundColor( TQColor( 234, 247, 255 ) );
    tbQun->setAutoRaise( TRUE );
    layout5->addWidget( tbQun );
    spacer3 = new TQSpacerItem( 81, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout5->addItem( spacer3 );
    layout6->addLayout( layout5 );

    lblMessage = new TQLabel( fraMain, "lblMessage" );
    lblMessage->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)7, 0, 0, lblMessage->sizePolicy().hasHeightForWidth() ) );
    lblMessage->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignTop | TQLabel::AlignLeft ) );
    layout6->addWidget( lblMessage );
    fraMainLayout->addLayout( layout6 );
    layout12->addWidget( fraMain );

    bgActions = new TQButtonGroup( this, "bgActions" );
    bgActions->setFrameShape( TQButtonGroup::NoFrame );
    bgActions->setColumnLayout(0, TQt::Vertical );
    bgActions->layout()->setSpacing( 6 );
    bgActions->layout()->setMargin( 0 );
    bgActionsLayout = new TQVBoxLayout( bgActions->layout() );
    bgActionsLayout->setAlignment( TQt::AlignTop );

    layout1 = new TQHBoxLayout( 0, 0, 6, "layout1"); 

    rbtnAccept = new TQRadioButton( bgActions, "rbtnAccept" );
    layout1->addWidget( rbtnAccept );

    rbtnReject = new TQRadioButton( bgActions, "rbtnReject" );
    layout1->addWidget( rbtnReject );
    spacer1 = new TQSpacerItem( 71, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout1->addItem( spacer1 );
    bgActionsLayout->addLayout( layout1 );
    layout12->addWidget( bgActions );

    fraMessage = new TQFrame( this, "fraMessage" );
    fraMessage->setFrameShape( TQFrame::NoFrame );
    fraMessage->setFrameShadow( TQFrame::Raised );
    fraMessageLayout = new TQVBoxLayout( fraMessage, 0, 6, "fraMessageLayout"); 

    leMessage = new TQLineEdit( fraMessage, "leMessage" );
    fraMessageLayout->addWidget( leMessage );
    layout12->addWidget( fraMessage );

    layout10 = new TQHBoxLayout( 0, 0, 6, "layout10"); 

    chbRejectForever = new TQCheckBox( this, "chbRejectForever" );
    layout10->addWidget( chbRejectForever );
    spacer2 = new TQSpacerItem( 122, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout10->addItem( spacer2 );

    btnOk = new TQPushButton( this, "btnOk" );
    btnOk->setDefault( TRUE );
    layout10->addWidget( btnOk );

    btnClose = new TQPushButton( this, "btnClose" );
    layout10->addWidget( btnClose );
    layout12->addLayout( layout10 );

    EvaQunSysMsgUIBaseLayout->addLayout( layout12, 0, 0 );
    languageChange();
    resize( TQSize(411, 210).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaQunSysMsgUIBase::~EvaQunSysMsgUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaQunSysMsgUIBase::languageChange()
{
    setCaption( i18n( "Qun System Message" ) );
    //tbQQ->setText( tr( "..." ) );
    //lblAction->setText( tr( "request to join Qun" ) );
    //tbQun->setText( tr( "..." ) );
    //lblMessage->setText( tr( "-" ) );
    bgActions->setTitle( TQString::null );
    rbtnAccept->setText( i18n( "Accept" ) );
    rbtnReject->setText( i18n( "Reject" ) );
    chbRejectForever->setText( i18n( "Reject always" ) );
    btnOk->setText( i18n( "&OK" ) );
    btnOk->setAccel( TQKeySequence( tr( "Alt+O" ) ) );
    btnClose->setText( i18n( "&Close" ) );
    btnClose->setAccel( TQKeySequence( tr( "Alt+C" ) ) );
}

