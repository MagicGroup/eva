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

#include "evaaddqunuibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqtoolbutton.h>
#include <ntqlabel.h>
#include <ntqframe.h>
#include <ntqlineedit.h>
#include <ntqgroupbox.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>

#include <tdelocale.h>

/*
 *  Constructs a EvaAddQunUIBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EvaAddQunUIBase::EvaAddQunUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "EvaAddQunUIBase" );
    EvaAddQunUIBaseLayout = new TQGridLayout( this, 1, 1, 10, 6, "EvaAddQunUIBaseLayout"); 

    layout21 = new TQVBoxLayout( 0, 0, 6, "layout21"); 

    layout15 = new TQHBoxLayout( 0, 0, 6, "layout15"); 

    tbQunDetails = new TQToolButton( this, "tbQunDetails" );
    tbQunDetails->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)1, 0, 0, tbQunDetails->sizePolicy().hasHeightForWidth() ) );
    tbQunDetails->setUsesBigPixmap( TRUE );
    tbQunDetails->setAutoRaise( TRUE );
    layout15->addWidget( tbQunDetails );

    layout1 = new TQVBoxLayout( 0, 0, 6, "layout1"); 

    lblQunIDTag = new TQLabel( this, "lblQunIDTag" );
    layout1->addWidget( lblQunIDTag );

    lblCreatorTag = new TQLabel( this, "lblCreatorTag" );
    layout1->addWidget( lblCreatorTag );
    layout15->addLayout( layout1 );

    layout2 = new TQVBoxLayout( 0, 0, 6, "layout2"); 

    lblQunExtID = new TQLabel( this, "lblQunExtID" );
    layout2->addWidget( lblQunExtID );

    lblCreator = new TQLabel( this, "lblCreator" );
    layout2->addWidget( lblCreator );
    layout15->addLayout( layout2 );

    layout14 = new TQVBoxLayout( 0, 0, 6, "layout14"); 

    layout13 = new TQHBoxLayout( 0, 0, 6, "layout13"); 

    lblQunNameTag = new TQLabel( this, "lblQunNameTag" );
    layout13->addWidget( lblQunNameTag );

    lblQunName = new TQLabel( this, "lblQunName" );
    layout13->addWidget( lblQunName );
    spacer3 = new TQSpacerItem( 31, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout13->addItem( spacer3 );
    layout14->addLayout( layout13 );

    layout4 = new TQHBoxLayout( 0, 0, 6, "layout4"); 

    tbCreatorDetails = new TQToolButton( this, "tbCreatorDetails" );
    tbCreatorDetails->setPaletteForegroundColor( TQColor( 41, 90, 197 ) );
    tbCreatorDetails->setAutoRaise( TRUE );
    layout4->addWidget( tbCreatorDetails );
    spacer1 = new TQSpacerItem( 20, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout4->addItem( spacer1 );
    layout14->addLayout( layout4 );
    layout15->addLayout( layout14 );
    layout21->addLayout( layout15 );

    fraAuthContents = new TQFrame( this, "fraAuthContents" );
    fraAuthContents->setPaletteBackgroundColor( TQColor( 234, 247, 255 ) );
    fraAuthContents->setFrameShape( TQFrame::StyledPanel );
    fraAuthContents->setFrameShadow( TQFrame::Raised );
    fraAuthContentsLayout = new TQVBoxLayout( fraAuthContents, 11, 6, "fraAuthContentsLayout"); 

    layout20 = new TQVBoxLayout( 0, 0, 6, "layout20"); 

    lblDescription = new TQLabel( fraAuthContents, "lblDescription" );
    lblDescription->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignVCenter ) );
    layout20->addWidget( lblDescription );

    fraAuthGraphic = new TQFrame( fraAuthContents, "fraAuthGraphic" );
    fraAuthGraphic->setFrameShape( TQFrame::StyledPanel );
    fraAuthGraphic->setFrameShadow( TQFrame::Raised );
    fraAuthGraphicLayout = new TQVBoxLayout( fraAuthGraphic, 11, 6, "fraAuthGraphicLayout"); 

    layout19 = new TQVBoxLayout( 0, 0, 6, "layout19"); 

    layout18 = new TQHBoxLayout( 0, 0, 6, "layout18"); 

    lblCode = new TQLabel( fraAuthGraphic, "lblCode" );
    layout18->addWidget( lblCode );

    leCode = new TQLineEdit( fraAuthGraphic, "leCode" );
    layout18->addWidget( leCode );
    spacer4 = new TQSpacerItem( 31, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout18->addItem( spacer4 );
    layout19->addLayout( layout18 );

    layout17 = new TQHBoxLayout( 0, 0, 6, "layout17"); 

    lblTip = new TQLabel( fraAuthGraphic, "lblTip" );
    layout17->addWidget( lblTip );

    lblGraphic = new TQLabel( fraAuthGraphic, "lblGraphic" );
    layout17->addWidget( lblGraphic );

    tbRefresh = new TQToolButton( fraAuthGraphic, "tbRefresh" );
    tbRefresh->setPaletteForegroundColor( TQColor( 41, 90, 197 ) );
    tbRefresh->setAutoRaise( TRUE );
    layout17->addWidget( tbRefresh );
    spacer5 = new TQSpacerItem( 21, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout17->addItem( spacer5 );
    layout19->addLayout( layout17 );
    fraAuthGraphicLayout->addLayout( layout19 );
    layout20->addWidget( fraAuthGraphic );
    fraAuthContentsLayout->addLayout( layout20 );
    layout21->addWidget( fraAuthContents );

    gbMessage = new TQGroupBox( this, "gbMessage" );
    gbMessage->setColumnLayout(0, TQt::Vertical );
    gbMessage->layout()->setSpacing( 6 );
    gbMessage->layout()->setMargin( 11 );
    gbMessageLayout = new TQVBoxLayout( gbMessage->layout() );
    gbMessageLayout->setAlignment( TQt::AlignTop );

    leMessage = new TQLineEdit( gbMessage, "leMessage" );
    gbMessageLayout->addWidget( leMessage );
    layout21->addWidget( gbMessage );

    layout11 = new TQHBoxLayout( 0, 10, 6, "layout11"); 
    spacer2 = new TQSpacerItem( 61, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout11->addItem( spacer2 );

    btnSend = new TQPushButton( this, "btnSend" );
    layout11->addWidget( btnSend );

    btnCancel = new TQPushButton( this, "btnCancel" );
    layout11->addWidget( btnCancel );
    layout21->addLayout( layout11 );

    EvaAddQunUIBaseLayout->addLayout( layout21, 0, 0 );
    languageChange();
    resize( TQSize(357, 334).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaAddQunUIBase::~EvaAddQunUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaAddQunUIBase::languageChange()
{
    setCaption( i18n( "Eva Search/Add Friend" ) );
    ///tbQunDetails->setText( tr( "..." ) );
    lblQunIDTag->setText( i18n( "Qun ID:" ) );
    lblCreatorTag->setText( i18n( "Creator:" ) );
    ///lblQunExtID->setText( tr( "ext id" ) );
    ///lblCreator->setText( tr( "creator" ) );
    lblQunNameTag->setText( i18n( "Qun Name:" ) );
    ///lblQunName->setText( tr( "name" ) );
    tbCreatorDetails->setText( i18n( "Creator Details" ) );
    ///lblDescription->setText( tr( "description" ) );
    lblCode->setText( i18n( "Auth Code:" ) );
    lblTip->setText( i18n( "Please enter the code" ) );
    ///lblGraphic->setText( tr( "--" ) );
    tbRefresh->setText( i18n( "Refresh" ) );
    gbMessage->setTitle( i18n( "Authentication needed, please leave a message" ) );
    btnSend->setText( i18n( "&Send" ) );
    btnSend->setAccel( TQKeySequence( tr( "Alt+S" ) ) );
    btnCancel->setText( i18n( "&Cancel" ) );
    btnCancel->setAccel( TQKeySequence( tr( "Alt+C" ) ) );
}

