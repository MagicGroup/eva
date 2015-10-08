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

#include "evachatuibase.h"
#include "evatextedit.h"
#include "evachatview.h"
#include "evafilepanel.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqtoolbutton.h>
#include <ntqlabel.h>
#include <ntqlineedit.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <ntqimage.h>
#include <ntqpixmap.h>
#include <ntqsplitter.h>
#include <ntqvaluelist.h>
#include <ntqframe.h>
#include <tdelocale.h>

#include <tdeapplication.h>

EvaChatUIBase::EvaChatUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
	if ( !name )
		setName( "EvaChatUIBase" );
	EvaChatUIBaseLayout = new TQHBoxLayout( this, 0, 0, "EvaChatUIBaseLayout");

	splitter = new TQSplitter( this, "splitter" );
	splitter->setOrientation( TQSplitter::Vertical );
	TQWidget *upperLayoutWidget = new TQWidget(splitter, "upper");

	layout5 = new TQVBoxLayout( upperLayoutWidget, 0, 3, "layout5");

	layout4 = new TQHBoxLayout( 0, 3, 6, "layout4"); 
	
	tbBuddy = new TQToolButton( upperLayoutWidget, "tbBuddy" );
	tbBuddy->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbBuddy->sizePolicy().hasHeightForWidth() ) );
	tbBuddy->setMinimumSize( TQSize( 20, 24 ) );
	tbBuddy->setMaximumSize( TQSize( 300, 24 ) );
	tbBuddy->setUsesTextLabel( TRUE );
	tbBuddy->setAutoRaise( TRUE );
	tbBuddy->setTextPosition( TQToolButton::BesideIcon );
	layout4->addWidget( tbBuddy );
	
	lblIP = new TQLabel( upperLayoutWidget, "lblIP" );
	lblIP->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, lblIP->sizePolicy().hasHeightForWidth() ) );
	lblIP->setMinimumSize( TQSize( 15, 0 ) );
	lblIP->setMaximumSize( TQSize( 15, 32767 ) );
	layout4->addWidget( lblIP );
	
	leIP = new TQLineEdit( upperLayoutWidget, "leIP" );
	leIP->setPaletteBackgroundColor( TQColor( 238, 238, 230 ) );
	leIP->setFrameShape( TQLineEdit::NoFrame );
	leIP->setReadOnly( TRUE );
	layout4->addWidget( leIP );
	layout5->addLayout( layout4 );
	
	lblSignature = new TQLabel( upperLayoutWidget, "lblSignature");
	lblSignature->setSizePolicy( TQSizePolicy( TQSizePolicy::Expanding, (TQSizePolicy::SizeType)0, 0, 0, lblSignature->sizePolicy().hasHeightForWidth() ) );
	lblSignature->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignTop | TQLabel::AlignLeft ) );
	layout5->addWidget(lblSignature);
	
	chatDisplay = new EvaChatView(upperLayoutWidget, "chatDisplay");
	chatDisplay->view()->setSizePolicy( TQSizePolicy( TQSizePolicy::Expanding, TQSizePolicy::Preferred, 0, 3, chatDisplay->view()->sizePolicy().hasHeightForWidth() ) );
	chatDisplay->view()->setHScrollBarMode(TQScrollView::AlwaysOff);
	layout5->addWidget( chatDisplay->view() );
	
	
	lowerLayoutWidget = new TQWidget(splitter, "lower");
	lowerLayout = new TQVBoxLayout(lowerLayoutWidget, 0, 3, "toolLayout");

	layout3 = new TQHBoxLayout( 0, 0, 0, "layout3"); 
	
	tbSmiley = new TQToolButton( lowerLayoutWidget, "tbSmiley" );
	tbSmiley->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbSmiley->sizePolicy().hasHeightForWidth() ) );
	tbSmiley->setMinimumSize( TQSize( 24, 24 ) );
	tbSmiley->setMaximumSize( TQSize( 24, 24 ) );
	tbSmiley->setAutoRaise( TRUE );
	layout3->addWidget( tbSmiley );
	
	tbFont = new TQToolButton( lowerLayoutWidget, "tbFont" );
	tbFont->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbFont->sizePolicy().hasHeightForWidth() ) );
	tbFont->setMinimumSize( TQSize( 24, 24 ) );
	tbFont->setMaximumSize( TQSize( 24, 24 ) );
	tbFont->setAutoRaise( TRUE );
	layout3->addWidget( tbFont );

	tbFile = new TQToolButton( lowerLayoutWidget, "tbFile" );
	tbFile->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbFile->sizePolicy().hasHeightForWidth() ) );
	tbFile->setMinimumSize( TQSize( 24, 24 ) );
	tbFile->setMaximumSize( TQSize( 24, 24 ) );
	tbFile->setAutoRaise( TRUE );
	layout3->addWidget( tbFile );

	spcTootBtn1 = new TQSpacerItem( 20, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
	layout3->addItem( spcTootBtn1 );
	
	tbB = new TQToolButton( lowerLayoutWidget, "tbB" );
	tbB->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbB->sizePolicy().hasHeightForWidth() ) );
	tbB->setMinimumSize( TQSize( 24, 24 ) );
	tbB->setMaximumSize( TQSize( 24, 24 ) );
	tbB->setToggleButton( TRUE );
	tbB->setAutoRaise( TRUE );
	layout3->addWidget( tbB );
	
	tbU = new TQToolButton( lowerLayoutWidget, "tbU" );
	tbU->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbU->sizePolicy().hasHeightForWidth() ) );
	tbU->setMinimumSize( TQSize( 24, 24 ) );
	tbU->setMaximumSize( TQSize( 24, 24 ) );
	tbU->setToggleButton( TRUE );
	tbU->setUsesTextLabel( FALSE );
	tbU->setAutoRaise( TRUE );
	layout3->addWidget( tbU );
	
	tbI = new TQToolButton( lowerLayoutWidget, "tbI" );
	tbI->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbI->sizePolicy().hasHeightForWidth() ) );
	tbI->setMinimumSize( TQSize( 24, 24 ) );
	tbI->setMaximumSize( TQSize( 24, 24 ) );
	tbI->setToggleButton( TRUE );
	tbI->setAutoRaise( TRUE );
	layout3->addWidget( tbI );
	spcToolBtn2 = new TQSpacerItem( 20, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
	layout3->addItem( spcToolBtn2 );

	tbAddImage = new TQToolButton( lowerLayoutWidget, "tbAddImage");
	tbAddImage->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbAddImage->sizePolicy().hasHeightForWidth() ) );
	tbAddImage->setMinimumSize( TQSize( 24, 24 ) );
	tbAddImage->setMaximumSize( TQSize( 24, 24 ) );
	tbAddImage->setAutoRaise( TRUE );
	layout3->addWidget( tbAddImage );

	tbScreenShot = new TQToolButton( lowerLayoutWidget, "tbScreenShot" );
	tbScreenShot->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbScreenShot->sizePolicy().hasHeightForWidth() ) );
	tbScreenShot->setMinimumSize( TQSize( 24, 24 ) );
	tbScreenShot->setMaximumSize( TQSize( 24, 24 ) );
	tbScreenShot->setAutoRaise( TRUE );
	layout3->addWidget( tbScreenShot );

	tbQuickReply = new TQToolButton( lowerLayoutWidget, "tbQuickReply" );
	tbQuickReply->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbQuickReply->sizePolicy().hasHeightForWidth() ) );
	tbQuickReply->setMinimumSize( TQSize( 24, 24 ) );
	tbQuickReply->setMaximumSize( TQSize( 24, 24 ) );
	tbQuickReply->setAutoRaise( TRUE );
	layout3->addWidget( tbQuickReply );

	tbEnableSound = new TQToolButton( lowerLayoutWidget, "tbEnableSound" );
	tbEnableSound->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbEnableSound->sizePolicy().hasHeightForWidth() ) );
	tbEnableSound->setMinimumSize( TQSize( 24, 24 ) );
	tbEnableSound->setMaximumSize( TQSize( 24, 24 ) );
	tbEnableSound->setToggleButton( TRUE );
	tbEnableSound->setUsesTextLabel( FALSE );
	tbEnableSound->setAutoRaise( TRUE );
	layout3->addWidget( tbEnableSound );

	spcToolBtn3 = new TQSpacerItem( 71, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout3->addItem( spcToolBtn3 );
	
	tbHideShows = new TQToolButton( lowerLayoutWidget, "tbHideShows" );
	tbHideShows->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbHideShows->sizePolicy().hasHeightForWidth() ) );
	tbHideShows->setMinimumSize( TQSize( 24, 24 ) );
	tbHideShows->setMaximumSize( TQSize( 24, 24 ) );
	tbHideShows->setAutoRaise( TRUE );
	layout3->addWidget( tbHideShows );

	lowerLayout->addLayout(layout3);
	
	kteInput = new EvaTextEdit( lowerLayoutWidget, "kteInput" );
	kteInput->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)2, (TQSizePolicy::SizeType)1, 0, 2, kteInput->sizePolicy().hasHeightForWidth() ) );
	kteInput->setMinimumSize( TQSize( 0, 10 ) );
	kteInput->setHScrollBarMode( KTextEdit::AlwaysOff );
	kteInput->setTextFormat(TQt::RichText);
	lowerLayout->addWidget( kteInput );
	
	layout2 = new TQHBoxLayout( 0, 4, 6, "layout2"); 
	
	pbHistory = new TQPushButton( lowerLayoutWidget, "pbHistory" );
	pbHistory->setToggleButton( TRUE );
	layout2->addWidget( pbHistory );
	spcBottom = new TQSpacerItem( 60, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout2->addItem( spcBottom );
	
	pbClose = new TQPushButton( lowerLayoutWidget, "pbClose" );
	layout2->addWidget( pbClose );
	
	pbSend = new TQPushButton( lowerLayoutWidget, "pbSend" );
	layout2->addWidget( pbSend );
	
	pbSendKey = new TQPushButton( lowerLayoutWidget, "pbSendKey" );
	pbSendKey->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, pbSendKey->sizePolicy().hasHeightForWidth() ) );
	pbSendKey->setMaximumSize( TQSize( 15, 32767 ) );
	layout2->addWidget( pbSendKey );
	lowerLayout->addLayout(layout2);
	
	EvaChatUIBaseLayout->addWidget(splitter);
	
	layout19 = new TQVBoxLayout( 0, 10, 6, "layout19");

	spacer12 = new TQSpacerItem( 20, 3, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout19->addItem( spacer12 );
	
	m_FilePanelFrame = new TQFrame(this, "m_FilePanelFrame");
	m_FilePanelFrame->setMaximumSize(TQSize(115, 200));
	m_FilePanelFrame->setFrameShape(TQFrame::LineEditPanel);
	m_FilePanelLayout = new TQVBoxLayout( m_FilePanelFrame, 2, 2, "m_FilePanelLayout"); // parent, margin, space
		
	m_FilePanel = new EvaFilePanel(m_FilePanelFrame, "m_FilePanel");
	m_FilePanelLayout->addWidget(m_FilePanel);

	layout19->addWidget(m_FilePanelFrame);

	m_ShowFrame = new TQFrame(this, "m_ShowFrame");
	m_ShowFrame->setFrameShape(TQFrame::LineEditPanel);
	m_ShowLayout = new TQVBoxLayout( m_ShowFrame, 10, 1, "m_ShowLayout"); // parent, margin, space

	lblBuddyShow = new TQLabel( m_ShowFrame, "lblBuddyShow" );
	lblBuddyShow->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)7, 0, 0, lblBuddyShow->sizePolicy().hasHeightForWidth() ) );
	lblBuddyShow->setAlignment( int( TQLabel::AlignVCenter ) );
	m_ShowLayout->addWidget( lblBuddyShow );
	
	tbShowBuddy = new TQToolButton( m_ShowFrame, "tbShowBuddy" );
	tbShowBuddy->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)7, 0, 0, tbShowBuddy->sizePolicy().hasHeightForWidth() ) );
	tbShowBuddy->setMinimumSize( TQSize( 95, 120 ) );
	tbShowBuddy->setMaximumSize( TQSize( 95, 120 ) );
	tbShowBuddy->setAutoRepeat( false );
	tbShowBuddy->setUsesBigPixmap( true );
	m_ShowLayout->addWidget( tbShowBuddy );
	
	lblMeShow = new TQLabel( m_ShowFrame, "lblMeShow" );
	lblMeShow->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)7, 0, 0, lblMeShow->sizePolicy().hasHeightForWidth() ) );
	lblMeShow->setAlignment( int( TQLabel::AlignVCenter ) );
	//layout19->addWidget( lblMeShow );
	m_ShowLayout->addWidget( lblMeShow );
	
	tbShowMe = new TQToolButton( m_ShowFrame, "tbShowMe" );
	tbShowMe->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)7, 0, 0, tbShowMe->sizePolicy().hasHeightForWidth() ) );
	tbShowMe->setMinimumSize( TQSize( 95, 120 ) );
	tbShowMe->setMaximumSize( TQSize( 95, 120 ) );
	tbShowMe->setUsesBigPixmap( true );
	tbShowMe->setAutoRaise( false );
	//layout19->addWidget( tbShowMe );
	m_ShowLayout->addWidget(tbShowMe);
	
	layout19->addWidget(m_ShowFrame);

	spacer10 = new TQSpacerItem( 20, 3, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
	layout19->addItem( spacer10 );

	//EvaChatUIBaseLayout->addLayout(layout19);

	m_FilePanelFrame->hide();
	m_ShowFrame->hide();

	TQValueList<int> list;
	list.append(150);
	list.append(120);
	//list.append(100);
	splitter->setSizes(list);

	languageChange();
	resize( TQSize(320, 367).expandedTo(minimumSizeHint()) );
	//resize( TQSize(450, 422).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
	TQRect scr = TDEApplication::desktop()->screenGeometry();
	move(scr.center()-rect().center());
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaChatUIBase::~EvaChatUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaChatUIBase::languageChange()
{
	setCaption( i18n( "Chat" ) );
	tbBuddy->setText( i18n( "..." ) );
	TQToolTip::add( tbBuddy, i18n( "click for details" ) );
	lblIP->setText( i18n( "IP:" ) );
	tbSmiley->setText( i18n( "..." ) );
	tbSmiley->setAccel( TQKeySequence( tr( "Alt+M" ) ) );
	TQToolTip::add( tbSmiley, i18n( "add a smiley icon" ) );
	tbFont->setText( i18n( "..." ) );
	tbFont->setAccel( TQKeySequence( tr( "Alt+F" ) ) );
	TQToolTip::add( tbFont, i18n( "choose font size and color" ) );
	tbFile->setText( i18n( "..." ) );
	tbFile->setAccel( TQKeySequence( tr( "Alt+L" ) ) );
	TQToolTip::add( tbFile, i18n( "send file to friend" ) );

	tbB->setText( i18n( "B" ) );
	tbB->setAccel( TQKeySequence( tr( "Alt+B" ) ) );
	TQToolTip::add( tbB, i18n( "bold" ) );
	tbU->setText( i18n( "U" ) );
	tbU->setAccel( TQKeySequence( tr( "Alt+U" ) ) );
	tbU->setTextLabel( TQString::null );
	TQToolTip::add( tbU, i18n( "underline" ) );
	tbI->setText( i18n( "I" ) );
	tbI->setAccel( TQKeySequence( tr( "Alt+I" ) ) );
	TQToolTip::add( tbI, i18n( "italic" ) );
	tbAddImage->setText("...");
	tbAddImage->setAccel( TQKeySequence( tr( "Alt+A" ) ) );
	tbAddImage->setText( i18n( "..." ) );
	TQToolTip::add( tbAddImage, i18n( "Send image files" ) );
	tbScreenShot->setText(i18n("..."));
	tbScreenShot->setAccel( TQKeySequence( tr( "Alt+T" ) ) );
	TQToolTip::add( tbScreenShot, i18n( "Add a screenshot" ) );
	tbQuickReply->setAccel( TQKeySequence( tr( "Alt+R" ) ) );
	TQToolTip::add( tbQuickReply, i18n( "Select an tquick-reply message" ) );

	TQToolTip::add(tbEnableSound, i18n("Toggle sound notification") );
	
	
	tbHideShows->setText( i18n( "..." ) );
	tbHideShows->setAccel( TQKeySequence( tr( "Alt+P" ) ) );
	TQToolTip::add( tbHideShows, i18n( "Hide/Display QQ Show panel" ) );
	
	pbHistory->setText( i18n( "&History" ) );
	pbHistory->setAccel( TQKeySequence( tr( "Alt+H" ) ) );
	TQToolTip::add( pbHistory, i18n( "View/Hide IM history (Alt+H)" ) );
	pbClose->setText( i18n( "Close" ) );
	pbClose->setAccel( TQKeySequence( tr( "Alt+X" ) ) );
	TQToolTip::add( pbClose, i18n( "Close this window (Alt+X)" ) );
	pbSend->setText( i18n( "&Send" ) );
	pbSend->setAccel( TQKeySequence( tr( "Alt+S" ) ) );
	TQToolTip::add( pbSend, i18n( "Send message" ) );
	pbSendKey->setText( TQString::null );
	pbSendKey->setAccel( TQKeySequence( TQString::null ) );
	TQToolTip::add( pbSendKey, i18n( "Change send key" ) );
	lblBuddyShow->setText( i18n( "Buddy" ) );
	tbShowBuddy->setText( i18n( "..." ) );
	TQToolTip::add( tbShowBuddy, i18n( "Click to update" ) );
	lblMeShow->setText( i18n( "Me" ) );
	tbShowMe->setText( i18n( "..." ) );
	tbShowMe->setAccel( TQKeySequence( TQString::null ) );
	TQToolTip::add( tbShowMe, i18n( "Click to update" ) );
}

