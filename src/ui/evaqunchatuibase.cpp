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

#include "evaqunchatuibase.h"
#include "evatextedit.h"
#include "evachatview.h"
#include "evaqunlistview.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqtoolbutton.h>
#include <ntqframe.h>
#include <ntqlabel.h>
#include <ntqheader.h>
#include <ntqlistview.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <ntqimage.h>
#include <ntqpixmap.h>
#include <ntqsplitter.h>
#include <ntqvaluelist.h>
#include <tdelocale.h>

#include <tdeapplication.h>

/*
 *  Constructs a EvaQunChatUIBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EvaQunChatUIBase::EvaQunChatUIBase( TQWidget* parent, const char* name, WFlags fl )
	: TQWidget( parent, name, fl )
{
	if ( !name )
		setName( "EvaQunChatUIBase" );
	setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)5, 3, 3, sizePolicy().hasHeightForWidth() ) );
	setSizeIncrement( TQSize( 2, 2 ) );
	EvaQunChatUIBaseLayout = new TQGridLayout( this, 1, 1, 2, 2, "EvaQunChatUIBaseLayout"); 
	EvaQunChatUIBaseLayout->setResizeMode( TQLayout::FreeResize );
	
	layout16 = new TQHBoxLayout( 0, 0, 6, "layout16"); 
	
	layout15 = new TQVBoxLayout( 0, 0, 2, "layout15");
	
	layout6 = new TQHBoxLayout( 0, 0, 6, "layout6"); 
	
	tbQunDetails = new TQToolButton( this, "tbQunDetails" );
	tbQunDetails->setUsesTextLabel( TRUE );
	tbQunDetails->setAutoRaise( TRUE );
	tbQunDetails->setTextPosition( TQToolButton::BesideIcon );
	layout6->addWidget( tbQunDetails );
	spacer4 = new TQSpacerItem( 81, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout6->addItem( spacer4 );
	layout15->addLayout( layout6 );

	splitter = new TQSplitter( this, "splitter" );
	splitter->setOrientation( TQSplitter::Vertical );

	chatDisplay = new EvaChatView(splitter, "chatDisplay");
	chatDisplay->view()->setHScrollBarMode(TQScrollView::AlwaysOff);
	//chatDisplay->view()->setMinimumSize(TQSize( 0, 170 ) );
	//layout15->addWidget( chatDisplay->view() );

	
	lowerLayoutWidget = new TQWidget(splitter, "lower");

	lowerLayout = new TQVBoxLayout(lowerLayoutWidget, 0, 3, "lowerLayout");
	layout14 = new TQHBoxLayout( 0, 0, 6, "layout14"); 
	
	tbSmiley = new TQToolButton( lowerLayoutWidget, "tbSmiley" );
	tbSmiley->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbSmiley->sizePolicy().hasHeightForWidth() ) );
	tbSmiley->setMinimumSize( TQSize( 24, 24 ) );
	tbSmiley->setMaximumSize( TQSize( 24, 24 ) );
	tbSmiley->setAutoRaise( TRUE );
	layout14->addWidget( tbSmiley );
	
	tbFont = new TQToolButton( lowerLayoutWidget, "tbFont" );
	tbFont->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbFont->sizePolicy().hasHeightForWidth() ) );
	tbFont->setMinimumSize( TQSize( 24, 24 ) );
	tbFont->setMaximumSize( TQSize( 24, 24 ) );
	tbFont->setAutoRaise( TRUE );
	layout14->addWidget( tbFont );
	
	spacer2 = new TQSpacerItem( 20, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
	layout14->addItem( spacer2 );
	
	tbB = new TQToolButton( lowerLayoutWidget, "tbB" );
	tbB->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbB->sizePolicy().hasHeightForWidth() ) );
	tbB->setMinimumSize( TQSize( 24, 24 ) );
	tbB->setMaximumSize( TQSize( 24, 24 ) );
	tbB->setToggleButton( TRUE );
	tbB->setAutoRaise( TRUE );
	layout14->addWidget( tbB );
	
	tbU = new TQToolButton( lowerLayoutWidget, "tbU" );
	tbU->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbU->sizePolicy().hasHeightForWidth() ) );
	tbU->setMinimumSize( TQSize( 24, 24 ) );
	tbU->setMaximumSize( TQSize( 24, 24 ) );
	tbU->setToggleButton( TRUE );
	tbU->setAutoRaise( TRUE );
	layout14->addWidget( tbU );
	
	tbI = new TQToolButton( lowerLayoutWidget, "tbI" );
	tbI->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbI->sizePolicy().hasHeightForWidth() ) );
	tbI->setMinimumSize( TQSize( 24, 24 ) );
	tbI->setMaximumSize( TQSize( 24, 24 ) );
	tbI->setToggleButton( TRUE );
	tbI->setAutoRaise( TRUE );
	layout14->addWidget( tbI );
	spacer3 = new TQSpacerItem( 20, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
	layout14->addItem( spacer3 );
	
	tbImageFile = new TQToolButton( lowerLayoutWidget, "tbImageFile" );
	tbImageFile->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbImageFile->sizePolicy().hasHeightForWidth() ) );
	tbImageFile->setMinimumSize( TQSize( 24, 24 ) );
	tbImageFile->setMaximumSize( TQSize( 24, 24 ) );
	tbImageFile->setAutoRaise( TRUE );
	layout14->addWidget( tbImageFile );
	
	tbScreenShot = new TQToolButton( lowerLayoutWidget, "tbScreenShot" );
	tbScreenShot->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbScreenShot->sizePolicy().hasHeightForWidth() ) );
	tbScreenShot->setMinimumSize( TQSize( 24, 24 ) );
	tbScreenShot->setMaximumSize( TQSize( 24, 24 ) );
	tbScreenShot->setAutoRaise( TRUE );
	layout14->addWidget( tbScreenShot );
	
	tbQuickReply = new TQToolButton( lowerLayoutWidget, "tbQuickReply" );
	tbQuickReply->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbQuickReply->sizePolicy().hasHeightForWidth() ) );
	tbQuickReply->setMinimumSize( TQSize( 24, 24 ) );
	tbQuickReply->setMaximumSize( TQSize( 24, 24 ) );
	tbQuickReply->setAutoRaise( TRUE );
	layout14->addWidget( tbQuickReply );

	tbEnableSound = new TQToolButton( lowerLayoutWidget, "tbEnableSound" );
	tbEnableSound->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbEnableSound->sizePolicy().hasHeightForWidth() ) );
	tbEnableSound->setMinimumSize( TQSize( 24, 24 ) );
	tbEnableSound->setMaximumSize( TQSize( 24, 24 ) );
	tbEnableSound->setToggleButton( TRUE );
	tbEnableSound->setUsesTextLabel( FALSE );
	tbEnableSound->setAutoRaise( TRUE );
	layout14->addWidget( tbEnableSound );

	spacer5 = new TQSpacerItem( 20, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout14->addItem( spacer5 );

	lowerLayout->addLayout(layout14);
	//layout15->addLayout( layout14 );

	teInput = new EvaTextEdit( lowerLayoutWidget, "kteInput" );
	teInput->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)1, 0, 0, teInput->sizePolicy().hasHeightForWidth() ) );
	teInput->setMinimumSize( TQSize( 0, 10 ) );
	//teInput->setMaximumSize( TQSize( 32767, 160 ) );
	teInput->setHScrollBarMode( KTextEdit::AlwaysOff );
	teInput->setTextFormat(TQt::RichText);
	lowerLayout->addWidget(teInput);

	//layout15->addWidget( teInput );
	layout15->addWidget(splitter);
		
	layout3 = new TQHBoxLayout( 0, 0, 6, "layout3"); 
	
	pbHistory = new TQPushButton( this, "pbHistory" );
	pbHistory->setToggleButton(TRUE);
	layout3->addWidget( pbHistory );
	spacer1 = new TQSpacerItem( 81, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout3->addItem( spacer1 );
	
	pbClose = new TQPushButton( this, "pbClose" );
	layout3->addWidget( pbClose );
	
	pbSend = new TQPushButton( this, "pbSend" );
	layout3->addWidget( pbSend );
	
	pbSendKey = new TQPushButton( this, "pbSendKey" );
	pbSendKey->setMaximumSize( TQSize( 20, 32767 ) );
	layout3->addWidget( pbSendKey );
	layout15->addLayout( layout3 );
	layout16->addLayout( layout15 );
	
	memberSplitter = new TQSplitter( this, "memberSplitter" );
	memberSplitter->setOrientation( TQSplitter::Vertical );

	
	frmNotice = new TQFrame( memberSplitter, "frmNoice" ); /// --------------
	//frmNotice->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)5, 0, 0, frmNotice->sizePolicy().hasHeightForWidth() ) );
	frmNotice->setMaximumSize( TQSize( 140, 32767 ) );
	frmNotice->setFrameShape( TQFrame::LineEditPanel );
	frmNotice->setFrameShadow( TQFrame::Raised );
	frmNoticeLayout = new TQGridLayout( frmNotice, 1, 1, 2, 2, "frmNoiceLayout"); 
	
	layout4 = new TQVBoxLayout( 0, 0, 0, "layout4"); 
	
	tbtnNotice = new TQToolButton( frmNotice, "tbtnNotice" );
	tbtnNotice->setEnabled( TRUE );
	tbtnNotice->setMaximumSize( TQSize( 32767, 24 ) );
	tbtnNotice->setUsesTextLabel( TRUE );
	tbtnNotice->setAutoRaise( TRUE );
	tbtnNotice->setTextPosition( TQToolButton::BesideIcon );
	layout4->addWidget( tbtnNotice );
	
	//kslblNotice = new KSqueezedTextLabel( frmNotice, "kslblNotice" );
//	teNotice = new TQLabel(frmNotice, "teNotice");
	teNotice = new TQTextEdit(frmNotice, "teNotice");
	//kslblNotice->setMaximumSize( TQSize( 32767, 32767 ) );
	teNotice->setMaximumSize( TQSize( 136, 32767 ) );
	teNotice->setPaletteBackgroundColor( TQColor( 255, 253, 211 ) );
	teNotice->setFrameShape( TQLabel::LineEditPanel );
	teNotice->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignTop | TQLabel::AlignLeft ) );
	teNotice->setVScrollBarMode(TQScrollView::AlwaysOff);
	teNotice->setReadOnly(true);
	//layout4->addWidget( kslblNotice );
	layout4->addWidget( teNotice );
	
	frmNoticeLayout->addLayout( layout4, 0, 0 );

	frmMembers = new TQFrame(memberSplitter, "frmMembers");
	frmMemberLayout = new TQVBoxLayout( frmMembers, 1, 1, "memberLayout"); 
	
	lblMembers = new TQLabel( frmMembers, "lblMembers" );
	lblMembers->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)5, 0, 0, lblMembers->sizePolicy().hasHeightForWidth() ) );
	lblMembers->setMaximumSize( TQSize( 140, 32767 ) );
	frmMemberLayout->addWidget( lblMembers );
	
	memberList = new EvaQunListView( frmMembers, "memberList" );
	memberList->addColumn(  "" );
	memberList->addColumn( "" );
	memberList->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)7, 0, 0, memberList->sizePolicy().hasHeightForWidth() ) );
	memberList->setMaximumSize( TQSize( 140, 32767 ) );
	memberList->setAllColumnsShowFocus(true);
	//memberList->setHScrollBarMode( TQListView::AlwaysOff );
	//memberList->setSelectionMode( TQListView::Extended );
	memberList->header()->hide();
	memberList->setSorting(0);
	memberList->setRootIsDecorated( false );
	memberList->setTreeStepSize( 0 );   
	memberList->setDragAutoScroll(true);
	frmMemberLayout->addWidget(memberList);

	layout12 = new TQVBoxLayout( 0, 4, 4, "layout12"); /// --------------	
	layout12->addWidget( memberSplitter );
	layout16->addLayout( layout12 );
	
	EvaQunChatUIBaseLayout->addLayout( layout16, 0, 0 );

	TQValueList<int> list;
	list.append(150);
	list.append(80);
	splitter->setSizes(list);

	languageChange();
	resize( TQSize(470, 422).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
	TQRect scr = TDEApplication::desktop()->screenGeometry();
	move(scr.center()-rect().center());
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaQunChatUIBase::~EvaQunChatUIBase()
{
	// no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaQunChatUIBase::languageChange()
{
	setCaption( i18n( "Qun" ) );
	tbQunDetails->setText( i18n( "..." ) );
	tbSmiley->setText( i18n( "..." ) );
	TQToolTip::add( tbSmiley, i18n( "Add a smiley icon" ) );
	tbFont->setText( i18n( "..." ) );
	TQToolTip::add( tbFont, i18n( "Choose font size and color" ) );
	tbB->setText( i18n( "..." ) );
	tbB->setAccel( TQKeySequence( tr( "Alt+B" ) ) );
	TQToolTip::add( tbB, i18n( "Bold" ) );
	tbU->setText( i18n( "..." ) );
	tbU->setAccel( TQKeySequence( tr( "Alt+U" ) ) );
	TQToolTip::add( tbU, i18n( "Underline" ) );
	tbI->setText( i18n( "..." ) );
	tbI->setAccel( TQKeySequence( tr( "Alt+I" ) ) );
	TQToolTip::add( tbI, i18n( "Italic" ) );
	tbImageFile->setText(i18n("..."));
	tbImageFile->setAccel( TQKeySequence( tr( "Alt+A" ) ) );
	TQToolTip::add( tbImageFile, i18n( "Add a custom smiley (file size less than 50KB)" ) );
	tbScreenShot->setText(i18n("..."));
	tbScreenShot->setAccel( TQKeySequence( tr( "Alt+T" ) ) );
	TQToolTip::add( tbScreenShot, i18n( "Add a screenshot (smaller than 700 x 600)" ) );
	tbQuickReply->setText( i18n( "..." ) );
	tbQuickReply->setAccel( TQKeySequence( tr( "Alt+R" ) ) );
	TQToolTip::add( tbQuickReply, i18n( "Select a tquick-reply message" ) );
	TQToolTip::add( tbEnableSound, i18n( "Toggle sound notification" ) );
	pbHistory->setText( i18n( "History" ) );
	pbHistory->setAccel( TQKeySequence( tr( "Alt+H" ) ) );
	TQToolTip::add( pbHistory, i18n( "View/Hide Qun history (Alt+H)" ) );
	pbClose->setText( i18n( "Close" ) );
	pbClose->setAccel( TQKeySequence( tr( "Alt+X" ) ) );
	TQToolTip::add( pbClose, i18n( "Close this window (Alt+X)" ) );
	pbSend->setText( i18n( "&Send" ) );
	pbSend->setAccel( TQKeySequence( i18n( "Alt+S" ) ) );
	TQToolTip::add( pbSend, i18n( "Send message" ) );
	pbSendKey->setText( TQString::null );
	TQToolTip::add( pbSendKey, i18n( "Change send key" ) );
	tbtnNotice->setTextLabel( i18n( "Notice" ) );
	TQToolTip::add( tbtnNotice, i18n( "Click to open/close Qun notice" ) );
	//kslblNotice->setText( i18n( "Notice Here" ) );
	lblMembers->setText( i18n( "Members" ) );
	//listView1->header()->setLabel( 0, i18n( "Column 1" ) );
	//listView1->header()->setLabel( 1, i18n( "Column 2" ) );
	memberList->clear();
	TQListViewItem * item = new TQListViewItem( memberList, 0 );
	item->setText( 0, i18n( "New Item" ) );

}

