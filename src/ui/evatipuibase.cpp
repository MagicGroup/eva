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

#include "evatipuibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqframe.h>
#include <ntqlabel.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <ntqimage.h>
#include <ntqpixmap.h>
#include <twin.h>
#include <tdelocale.h>

EvaTipUIBase::EvaTipUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "EvaTipUIBase" );
    EvaTipUIBaseLayout = new TQGridLayout( this, 1, 1, 0, 0, "EvaTipUIBaseLayout"); 

    fraMain = new TQFrame( this, "fraMain" );
    fraMain->setFrameShape( TQFrame::StyledPanel );
    fraMain->setFrameShadow( TQFrame::Sunken );
    fraMain->setLineWidth( 3 );
    fraMain->setMargin( 0 );
    fraMain->setMidLineWidth( 0 );
    fraMain->setCursor( TQCursor( 13 ) );
    fraMainLayout = new TQGridLayout( fraMain, 1, 1, 0, 0, "fraMainLayout"); 

    layout2 = new TQHBoxLayout( 0, 0, 0, "layout2"); 

    lblPixmap = new TQLabel( fraMain, "lblPixmap" );
    lblPixmap->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, lblPixmap->sizePolicy().hasHeightForWidth() ) );
    lblPixmap->setMinimumSize( TQSize( 81, 121 ) );
    lblPixmap->setMaximumSize( TQSize( 81, 121 ) );
    lblPixmap->setFrameShape( TQLabel::NoFrame );
    lblPixmap->setFrameShadow( TQLabel::Plain );
    lblPixmap->setAlignment( int( TQLabel::AlignCenter ) );
    lblPixmap->setCursor( TQCursor( 13 ) );
    layout2->addWidget( lblPixmap );

    layout1 = new TQVBoxLayout( 0, 6, 0, "layout1"); 

    lblNick = new TQLabel( fraMain, "lblNick" );
    lblNick->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)1, 0, 0, lblNick->sizePolicy().hasHeightForWidth() ) );
    lblNick->setMinimumSize( TQSize( 120, 30 ) );
    lblNick->setMaximumSize( TQSize( 120, 30 ) );
    lblNick->setCursor( TQCursor( 13 ) );
    layout1->addWidget( lblNick );

    lblMessage = new TQLabel( fraMain, "lblMessage" );
    lblMessage->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignTop ) );
    lblMessage->setMinimumSize( TQSize( 120, 81 ) );
    lblMessage->setMaximumSize( TQSize( 120, 81 ) );
    lblMessage->setCursor( TQCursor( 13 ) );
    layout1->addWidget( lblMessage );
    layout2->addLayout( layout1 );

    fraMainLayout->addLayout( layout2, 0, 0 );

    EvaTipUIBaseLayout->addWidget( fraMain, 0, 0 );
    languageChange();
    resize( TQSize(227, 135).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}


EvaTipUIBase::~EvaTipUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

void EvaTipUIBase::languageChange()
{
    setCaption( i18n( "Tip - Eva" ) );
    lblPixmap->setText( i18n( "Pix" ) );
    lblNick->setText( i18n( "nickname" ) );
    lblMessage->setText( i18n( "message" ) );
}

