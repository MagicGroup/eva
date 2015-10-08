/***************************************************************************
 *   Copyright (C) 2007 by yunfan                                          *
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

#include "evasysbroadcastuibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqframe.h>
#include <ntqlabel.h>
#include <kurllabel.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>

#include <tdelocale.h>
#include <kurllabel.h>
#include <tdeglobalsettings.h>

/*
 *  Constructs a EvaSysBroadcastUIBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EvaSysBroadcastUIBase::EvaSysBroadcastUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "EvaSysBroadcastUIBase" );
    EvaSysBroadcastUIBaseLayout = new TQGridLayout( this, 1, 1, 11, 6, "EvaSysBroadcastUIBaseLayout"); 

    layout7 = new TQVBoxLayout( 0, 0, 6, "layout7"); 

    fraContents = new TQFrame( this, "fraContents" );
    fraContents->setPaletteBackgroundColor( TQColor( 234, 247, 225 ) );
    fraContents->setFrameShape( TQFrame::StyledPanel );
    fraContents->setFrameShadow( TQFrame::Raised );
    fraContentsLayout = new TQGridLayout( fraContents, 1, 1, 11, 6, "fraContentsLayout"); 

    layout6 = new TQVBoxLayout( 0, 0, 6, "layout6"); 

    layout5 = new TQHBoxLayout( 0, 0, 6, "layout5"); 

    lblTitle = new TQLabel( fraContents, "lblTitle" );
    layout5->addWidget( lblTitle );
    spacer2 = new TQSpacerItem( 111, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout5->addItem( spacer2 );
    layout6->addLayout( layout5 );

    lblContents = new TQLabel( fraContents, "lblContents" );
    lblContents->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)7, 0, 0, lblContents->sizePolicy().hasHeightForWidth() ) );
    TQFont lblContents_font = TDEGlobalSettings::fixedFont();
    lblContents->setFont( lblContents_font ); 
    lblContents->setFrameShape( TQLabel::NoFrame );
    lblContents->setTextFormat( TQLabel::PlainText );
    lblContents->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignTop | TQLabel::AlignLeft ) );
    layout6->addWidget( lblContents );

    kurllblUrl = new KURLLabel( fraContents, "kurllblUrl" );
    kurllblUrl->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)1, 0, 0, kurllblUrl->sizePolicy().hasHeightForWidth() ) );
    kurllblUrl->setFrameShape( KURLLabel::NoFrame );
    layout6->addWidget( kurllblUrl );

    fraContentsLayout->addLayout( layout6, 0, 0 );
    layout7->addWidget( fraContents );

    layout3 = new TQHBoxLayout( 0, 0, 6, "layout3"); 
    spacer1 = new TQSpacerItem( 101, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout3->addItem( spacer1 );

    btnDetails = new TQPushButton( this, "btnDetails" );
    layout3->addWidget( btnDetails );

    btnClose = new TQPushButton( this, "btnClose" );
    layout3->addWidget( btnClose );
    layout7->addLayout( layout3 );

    EvaSysBroadcastUIBaseLayout->addLayout( layout7, 0, 0 );
    languageChange();
    resize( TQSize(400, 248).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaSysBroadcastUIBase::~EvaSysBroadcastUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaSysBroadcastUIBase::languageChange()
{
    setCaption( i18n( "System message" ) );
    lblTitle->setText( i18n( "System Broadcast:" ) );
    //lblContents->setText( tr( "-" ) );
    //kurllblUrl->setText( tr( "-" ) );
    kurllblUrl->setProperty( "url", TQString::null );
    btnDetails->setText( i18n( "&More Details" ) );
    btnDetails->setAccel( TQKeySequence( tr( "Alt+M" ) ) );
    btnClose->setText( i18n( "&Close" ) );
    btnClose->setAccel( TQKeySequence( tr( "Alt+C" ) ) );
}

