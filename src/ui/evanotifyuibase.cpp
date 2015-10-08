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
#include "evanotifyuibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqgroupbox.h>
#include <ntqlabel.h>
#include <ntqtoolbutton.h>
#include <ntqwidgetstack.h>
#include <ntqtextedit.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <tdelocale.h>

EvaNotifyUIBase::EvaNotifyUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
	if ( !name )
		setName( "EvaNotifyUIBase" );
	EvaNotifyUIBaseLayout = new TQGridLayout( this, 1, 1, 1, 0, "EvaNotifyUIBaseLayout"); 
	
	layout62 = new TQVBoxLayout( 0, 0, 6, "layout62"); 
	
	gbFrom = new TQGroupBox( this, "gbFrom" );
	gbFrom->setMaximumSize( TQSize( 32767, 60 ) );
	gbFrom->setFrameShape( TQGroupBox::GroupBoxPanel );
	gbFrom->setFrameShadow( TQGroupBox::Sunken );
	gbFrom->setColumnLayout(0, TQt::Vertical );
	gbFrom->layout()->setSpacing( 0 );
	gbFrom->layout()->setMargin( 5 );
	gbFromLayout = new TQGridLayout( gbFrom->layout() );
	gbFromLayout->setAlignment( TQt::AlignTop );
	
	layout49 = new TQHBoxLayout( 0, 0, 0, "layout49"); 
	
	textLabel1 = new TQLabel( gbFrom, "textLabel1" );
	layout49->addWidget( textLabel1 );
	
	tlQQ = new TQLabel( gbFrom, "tlQQ" );
	tlQQ->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)5, 0, 0, tlQQ->sizePolicy().hasHeightForWidth() ) );
	tlQQ->setMaximumSize( TQSize( 90, 25 ) );
	tlQQ->setPaletteBackgroundColor( TQColor( 200, 238, 196 ) );
	tlQQ->setFrameShape( TQLabel::Panel );
	tlQQ->setFrameShadow( TQLabel::Sunken );
	layout49->addWidget( tlQQ );
	spacer14 = new TQSpacerItem( 20, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout49->addItem( spacer14 );
	
	textLabel2 = new TQLabel( gbFrom, "textLabel2" );
	layout49->addWidget( textLabel2 );
	
	tlNick = new TQLabel( gbFrom, "tlNick" );
	tlNick->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)5, 0, 0, tlNick->sizePolicy().hasHeightForWidth() ) );
	tlNick->setMaximumSize( TQSize( 90, 25 ) );
	tlNick->setPaletteBackgroundColor( TQColor( 200, 238, 196 ) );
	tlNick->setFrameShape( TQLabel::Panel );
	tlNick->setFrameShadow( TQLabel::Sunken );
	layout49->addWidget( tlNick );
	spacer13 = new TQSpacerItem( 20, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout49->addItem( spacer13 );
	
	textLabel3 = new TQLabel( gbFrom, "textLabel3" );
	textLabel3->setMaximumSize( TQSize( 50, 32767 ) );
	textLabel3->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignVCenter ) );
	layout49->addWidget( textLabel3 );
	
	tbDetails = new TQToolButton( gbFrom, "tbDetails" );
	tbDetails->setUsesBigPixmap( TRUE );
	tbDetails->setAutoRaise( TRUE );
	layout49->addWidget( tbDetails );
	
	gbFromLayout->addLayout( layout49, 0, 0 );
	layout62->addWidget( gbFrom );
	
	gbMain = new TQGroupBox( this, "gbMain" );
	gbMain->setColumnLayout(0, TQt::Vertical );
	gbMain->layout()->setSpacing( 3 );
	gbMain->layout()->setMargin( 5 );
	gbMainLayout = new TQGridLayout( gbMain->layout() );
	gbMainLayout->setAlignment( TQt::AlignTop );
	
	wsMain = new TQWidgetStack( gbMain, "wsMain" );
	
	WStackPage = new TQWidget( wsMain, "WStackPage" );
	WStackPageLayout = new TQGridLayout( WStackPage, 1, 1, 11, 6, "WStackPageLayout"); 
	
	tlP0Tip = new TQLabel( WStackPage, "tlP0Tip" );
	tlP0Tip->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignVCenter ) );
	
	WStackPageLayout->addWidget( tlP0Tip, 0, 0 );
	wsMain->addWidget( WStackPage, 0 );
	
	WStackPage_2 = new TQWidget( wsMain, "WStackPage_2" );
	WStackPageLayout_2 = new TQGridLayout( WStackPage_2, 1, 1, 11, 6, "WStackPageLayout_2"); 
	
	layout54 = new TQHBoxLayout( 0, 0, 6, "layout54"); 
	
	tlP1Tip = new TQLabel( WStackPage_2, "tlP1Tip" );
	tlP1Tip->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignVCenter ) );
	layout54->addWidget( tlP1Tip );
	
	teP1Msg = new TQTextEdit( WStackPage_2, "teP1Msg" );
	teP1Msg->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)1, 0, 0, teP1Msg->sizePolicy().hasHeightForWidth() ) );
	teP1Msg->setMaximumSize( TQSize( 150, 60 ) );
	teP1Msg->setTextFormat( TQTextEdit::PlainText );
	layout54->addWidget( teP1Msg );
	
	WStackPageLayout_2->addLayout( layout54, 0, 0 );
	wsMain->addWidget( WStackPage_2, 1 );
	
	gbMainLayout->addWidget( wsMain, 0, 0 );
	layout62->addWidget( gbMain );
	
	layout52 = new TQHBoxLayout( 0, 0, 6, "layout52"); 
	
	pbApprove = new TQPushButton( this, "pbApprove" );
	pbApprove->setMaximumSize( TQSize( 70, 32767 ) );
	layout52->addWidget( pbApprove );
	
	pbReject = new TQPushButton( this, "pbReject" );
	pbReject->setMaximumSize( TQSize( 70, 32767 ) );
	layout52->addWidget( pbReject );
	spacer15 = new TQSpacerItem( 60, 20, TQSizePolicy::Preferred, TQSizePolicy::Minimum );
	layout52->addItem( spacer15 );
	
	pbAdd = new TQPushButton( this, "pbAdd" );
	pbAdd->setMaximumSize( TQSize( 70, 32767 ) );
	layout52->addWidget( pbAdd );
	
	pbClose = new TQPushButton( this, "pbClose" );
	pbClose->setMaximumSize( TQSize( 70, 32767 ) );
	layout52->addWidget( pbClose );
	layout62->addLayout( layout52 );
	
	EvaNotifyUIBaseLayout->addLayout( layout62, 0, 0 );
	languageChange();
	resize( TQSize(372, 249).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
	
}


EvaNotifyUIBase::~EvaNotifyUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

void EvaNotifyUIBase::languageChange()
{
	setCaption( i18n( "System Message" ) );
	gbFrom->setTitle( i18n( "From" ) );
	textLabel1->setText( i18n( "QQ:" ) );
	tlQQ->setText( "12345" );
	textLabel2->setText( i18n( "Nick:" ) );
	tlNick->setText( i18n( "nickname" ) );
	textLabel3->setText( i18n( "Click for Details" ) );
	tbDetails->setText( TQString::null );
	gbMain->setTitle( i18n( "Contents:" ) );
	tlP0Tip->setText( i18n( "message" ) );
	tlP1Tip->setText( i18n( "tips" ) );
	pbApprove->setText( i18n( "&Approve" ) );
	pbApprove->setAccel( TQKeySequence( tr( "Alt+A" ) ) );
	pbReject->setText( i18n( "&Reject" ) );
	pbReject->setAccel( TQKeySequence( tr( "Alt+R" ) ) );
	pbAdd->setText( i18n( "A&dd" ) );
	pbAdd->setAccel( TQKeySequence( tr( "Alt+D" ) ) );
	pbClose->setText( i18n( "&Close" ) );
	pbClose->setAccel( TQKeySequence( tr( "Alt+C" ) ) );
}


