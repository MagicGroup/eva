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

#include "evaadduibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqlabel.h>
#include <ntqframe.h>
#include <ntqtoolbutton.h>
#include <ntqcombobox.h>
#include <ntqlineedit.h>
#include <ntqcheckbox.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <tdelocale.h>

/*
 *  Constructs a EvaAddUIBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EvaAddUIBase::EvaAddUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "EvaAddUIBase" );
    EvaAddUIBaseLayout = new TQVBoxLayout( this, 11, 6, "EvaAddUIBaseLayout"); 

    lblTip = new TQLabel( this, "lblTip" );
    lblTip->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)1, 0, 0, lblTip->sizePolicy().hasHeightForWidth() ) );
    EvaAddUIBaseLayout->addWidget( lblTip );

    frame3 = new TQFrame( this, "frame3" );
    frame3->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)7, 0, 0, frame3->sizePolicy().hasHeightForWidth() ) );
    frame3->setPaletteBackgroundColor( TQColor( 234, 247, 255 ) );
    frame3->setFrameShape( TQFrame::StyledPanel );
    frame3->setFrameShadow( TQFrame::Raised );
    frame3Layout = new TQVBoxLayout( frame3, 11, 6, "frame3Layout"); 

    layout17 = new TQHBoxLayout( 0, 0, 6, "layout17"); 

    lblTopic = new TQLabel( frame3, "lblTopic" );
    lblTopic->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)1, 0, 0, lblTopic->sizePolicy().hasHeightForWidth() ) );
    layout17->addWidget( lblTopic );

    tbtnFace = new TQToolButton( frame3, "tbtnFace" );
    tbtnFace->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)1, 0, 0, tbtnFace->sizePolicy().hasHeightForWidth() ) );
    tbtnFace->setUsesBigPixmap( TRUE );
    tbtnFace->setAutoRaise( TRUE );
    layout17->addWidget( tbtnFace );
    frame3Layout->addLayout( layout17 );

    layout13 = new TQHBoxLayout( 0, 0, 6, "layout13"); 

    lblGroup = new TQLabel( frame3, "lblGroup" );
    layout13->addWidget( lblGroup );

    cbbGroups = new TQComboBox( FALSE, frame3, "cbbGroups" );
    layout13->addWidget( cbbGroups );
    spacer1 = new TQSpacerItem( 177, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout13->addItem( spacer1 );
    frame3Layout->addLayout( layout13 );

    fraVeriGraphic = new TQFrame( frame3, "fraVeriGraphic" );
    fraVeriGraphic->setFrameShape( TQFrame::NoFrame );
    fraVeriGraphic->setFrameShadow( TQFrame::Plain );
    fraVeriGraphicLayout = new TQGridLayout( fraVeriGraphic, 1, 1, 0, 0, "fraVeriGraphicLayout"); 

    layout14 = new TQHBoxLayout( 0, 0, 6, "layout14"); 

    lblVeriCode = new TQLabel( fraVeriGraphic, "lblVeriCode" );
    layout14->addWidget( lblVeriCode );

    leCode = new TQLineEdit( fraVeriGraphic, "leCode" );
    layout14->addWidget( leCode );

    lblCodeGraphic = new TQLabel( fraVeriGraphic, "lblCodeGraphic" );
    layout14->addWidget( lblCodeGraphic );

    btnRefreshCode = new TQToolButton( fraVeriGraphic, "btnRefreshCode" );
    btnRefreshCode->setAutoRaise( TRUE );
    layout14->addWidget( btnRefreshCode );

    fraVeriGraphicLayout->addLayout( layout14, 0, 0 );
    frame3Layout->addWidget( fraVeriGraphic );

    fraQuestion = new TQFrame( frame3, "fraQuestion" );
    fraQuestion->setFrameShape( TQFrame::NoFrame );
    fraQuestion->setFrameShadow( TQFrame::Plain );
    fraQuestionLayout = new TQHBoxLayout( fraQuestion, 0, 0, "fraQuestionLayout"); 

    layout12 = new TQVBoxLayout( 0, 0, 6, "layout12"); 

    lblQuestion = new TQLabel( fraQuestion, "lblQuestion" );
    layout12->addWidget( lblQuestion );

    lblAnswer = new TQLabel( fraQuestion, "lblAnswer" );
    lblAnswer->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)5, 0, 0, lblAnswer->sizePolicy().hasHeightForWidth() ) );
    layout12->addWidget( lblAnswer );
    fraQuestionLayout->addLayout( layout12 );

    layout13_2 = new TQVBoxLayout( 0, 0, 6, "layout13_2"); 

    lblQuesContents = new TQLabel( fraQuestion, "lblQuesContents" );
    lblQuesContents->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)4, 0, 0, lblQuesContents->sizePolicy().hasHeightForWidth() ) );
    lblQuesContents->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignVCenter | TQLabel::AlignLeft ) );
    layout13_2->addWidget( lblQuesContents );

    leAnswer = new TQLineEdit( fraQuestion, "leAnswer" );
    layout13_2->addWidget( leAnswer );
    fraQuestionLayout->addLayout( layout13_2 );
    frame3Layout->addWidget( fraQuestion );

    leMessage = new TQLineEdit( frame3, "leMessage" );
    leMessage->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)7, 0, 0, leMessage->sizePolicy().hasHeightForWidth() ) );
    leMessage->setMaxLength( 255 );
    leMessage->setAlignment( int( TQLineEdit::AlignAuto ) );
    frame3Layout->addWidget( leMessage );
    EvaAddUIBaseLayout->addWidget( frame3 );

    layout13_3 = new TQHBoxLayout( 0, 10, 6, "layout13_3"); 

    chbReverse = new TQCheckBox( this, "chbReverse" );
    layout13_3->addWidget( chbReverse );
    spacer2 = new TQSpacerItem( 31, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout13_3->addItem( spacer2 );

    btnOk = new TQPushButton( this, "btnOk" );
    layout13_3->addWidget( btnOk );

    btnCancel = new TQPushButton( this, "btnCancel" );
    layout13_3->addWidget( btnCancel );
    EvaAddUIBaseLayout->addLayout( layout13_3 );
    languageChange();
    resize( TQSize(430, 280).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaAddUIBase::~EvaAddUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaAddUIBase::languageChange()
{
    setCaption( i18n( "Eva Search/Add Friend" ) );
    //lblTip->setText( i18n( "-" ) );
    //lblTopic->setText( i18n( "-" ) );
    //tbtnFace->setText( i18n( "..." ) );
    lblGroup->setText( i18n( "Select Group:" ) );
    lblVeriCode->setText( i18n( "Verification Code:" ) );
    lblQuestion->setText( i18n( "Personal Question:" ) );
    lblAnswer->setText( i18n( "Your Answer:" ) );
    //lblCodeGraphic->setText( i18n( "-" ) );
    btnRefreshCode->setText( i18n( "Refresh" ) );
    //lblQuesContents->setText( i18n( "-" ) );
    chbReverse->setText( i18n( "allow reverse adding" ) );
    btnOk->setText( i18n( "&OK" ) );
    btnOk->setAccel( TQKeySequence( tr( "Alt+O" ) ) );
    btnCancel->setText( i18n( "&Cancel" ) );
    btnCancel->setAccel( TQKeySequence( tr( "Alt+C" ) ) );
}

