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

#include "mainlistfontsettinguibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ktabwidget.h>
#include <ntqgroupbox.h>
#include <ntqlabel.h>
#include <kcolorcombo.h>
#include <ntqcheckbox.h>
#include <ntqlayout.h>
#include <tdelocale.h>
//#include <ntqtooltip.h>
//#include <ntqwhatsthis.h>


MainListFontSettingUIBase::MainListFontSettingUIBase( TQWidget* parent, const char* name, WFlags fl )
	: TQWidget( parent, name, fl )
{
	if ( !name )
		setName( "MainListFontSettingUIBase" );
	MainListFontSettingUIBaseLayout = new TQGridLayout( this, 1, 1, 11, 6, "MainListFontSettingUIBaseLayout"); 
	
	ktabMainListFont = new KTabWidget( this, "ktabMainListFont" );
	ktabMainListFont->setCurrentPage( 0 );
	
	TabPage = new TQWidget( ktabMainListFont, "TabPage" );
	TabPageLayout = new TQVBoxLayout( TabPage, 11, 9, "TabPageLayout"); 
	
	gbBuddyNick = new TQGroupBox( TabPage, "gbBuddyNick" );
	gbBuddyNick->setColumnLayout(0, TQt::Vertical );
	gbBuddyNick->layout()->setSpacing( 6 );
	gbBuddyNick->layout()->setMargin( 11 );
	gbBuddyNickLayout = new TQVBoxLayout( gbBuddyNick->layout() );
	gbBuddyNickLayout->setAlignment( TQt::AlignTop );
	
	layout1 = new TQHBoxLayout( 0, 0, 6, "layout1"); 

	lblBuddyNickColor = new TQLabel( gbBuddyNick, "lblBuddyNickColor" );
	layout1->addWidget( lblBuddyNickColor );
	
	kcbbBuddyNickColor = new KColorCombo( gbBuddyNick, "kcbbBuddyNickColor" );
	layout1->addWidget( kcbbBuddyNickColor );
	gbBuddyNickLayout->addLayout( layout1 );
	
	layout2 = new TQHBoxLayout( 0, 0, 6, "layout2"); 
	
	chbBuddyNickFontB = new TQCheckBox( gbBuddyNick, "chbBuddyNickFontB" );
	layout2->addWidget( chbBuddyNickFontB );

	chbBuddyNickFontU = new TQCheckBox( gbBuddyNick, "chbBuddyNickFontU" );
	layout2->addWidget( chbBuddyNickFontU );
	
	chbBuddyNickFontI = new TQCheckBox( gbBuddyNick, "chbBuddyNickFontI" );
	layout2->addWidget( chbBuddyNickFontI );
	gbBuddyNickLayout->addLayout( layout2 );
	TabPageLayout->addWidget( gbBuddyNick );
	
	gbBuddyFlash = new TQGroupBox( TabPage, "gbBuddyFlash" );
	gbBuddyFlash->setColumnLayout(0, TQt::Vertical );
	gbBuddyFlash->layout()->setSpacing( 6 );
	gbBuddyFlash->layout()->setMargin( 11 );
	gbBuddyFlashLayout = new TQVBoxLayout( gbBuddyFlash->layout() );
	gbBuddyFlashLayout->setAlignment( TQt::AlignTop );
	
	layout3 = new TQHBoxLayout( 0, 0, 6, "layout3"); 
	
	lblBuddyFlashColor = new TQLabel( gbBuddyFlash, "lblBuddyFlashColor" );
	layout3->addWidget( lblBuddyFlashColor );
	
	kcbbBuddyFlashColor = new KColorCombo( gbBuddyFlash, "kcbbBuddyFlashColor" );
	layout3->addWidget( kcbbBuddyFlashColor );
	gbBuddyFlashLayout->addLayout( layout3 );
	
	layout4 = new TQHBoxLayout( 0, 0, 6, "layout4"); 
	
	chbBuddyFlashFontB = new TQCheckBox( gbBuddyFlash, "chbBuddyFlashFontB" );
	layout4->addWidget( chbBuddyFlashFontB );
	
	chbBuddyFlashFontU = new TQCheckBox( gbBuddyFlash, "chbBuddyFlashFontU" );
	layout4->addWidget( chbBuddyFlashFontU );

	chbBuddyFlashFontI = new TQCheckBox( gbBuddyFlash, "chbBuddyFlashFontI" );
	layout4->addWidget( chbBuddyFlashFontI );
	gbBuddyFlashLayout->addLayout( layout4 );
	TabPageLayout->addWidget( gbBuddyFlash );
	
	gbBuddySignature = new TQGroupBox( TabPage, "gbBuddySignature" );
	gbBuddySignature->setColumnLayout(0, TQt::Vertical );
	gbBuddySignature->layout()->setSpacing( 6 );
	gbBuddySignature->layout()->setMargin( 11 );
	gbBuddySignatureLayout = new TQVBoxLayout( gbBuddySignature->layout() );
	gbBuddySignatureLayout->setAlignment( TQt::AlignTop );
	
	layout5 = new TQHBoxLayout( 0, 0, 6, "layout5"); 
	
	lblBuddySigColor = new TQLabel( gbBuddySignature, "lblBuddySigColor" );
	layout5->addWidget( lblBuddySigColor );

	kcbbBuddySigColor = new KColorCombo( gbBuddySignature, "kcbbBuddySigColor" );
	layout5->addWidget( kcbbBuddySigColor );
	gbBuddySignatureLayout->addLayout( layout5 );
	
	layout6 = new TQHBoxLayout( 0, 0, 6, "layout6"); 
	
	chbBuddySigFontB = new TQCheckBox( gbBuddySignature, "chbBuddySigFontB" );
	layout6->addWidget( chbBuddySigFontB );
	
	chbBuddySigFontU = new TQCheckBox( gbBuddySignature, "chbBuddySigFontU" );
	layout6->addWidget( chbBuddySigFontU );
	
	chbBuddySigFontI = new TQCheckBox( gbBuddySignature, "chbBuddySigFontI" );
	layout6->addWidget( chbBuddySigFontI );
	gbBuddySignatureLayout->addLayout( layout6 );
	TabPageLayout->addWidget( gbBuddySignature );
	
	ktabMainListFont->addTab(TabPage, i18n("Buddy Font"));

	TabPage_2 = new TQWidget( ktabMainListFont, "TabPage_2" );
	TabPageLayout_2 = new TQVBoxLayout( TabPage_2, 11, 9, "TabPageLayout_2"); 

	layout11 = new TQVBoxLayout( 0, 0, 6, "layout11"); 
	
	gbQunName = new TQGroupBox( TabPage_2, "gbQunName" );
	gbQunName->setColumnLayout(0, TQt::Vertical );
	gbQunName->layout()->setSpacing( 6 );
	gbQunName->layout()->setMargin( 11 );
	gbQunNameLayout = new TQVBoxLayout( gbQunName->layout() );
	gbQunNameLayout->setAlignment( TQt::AlignTop );
	
	layout1_2 = new TQHBoxLayout( 0, 0, 6, "layout1_2"); 
	
	lblQunNameColor = new TQLabel( gbQunName, "lblQunNameColor" );
	layout1_2->addWidget( lblQunNameColor );
	
	kcbbQunNameColor = new KColorCombo( gbQunName, "kcbbQunNameColor" );
	layout1_2->addWidget( kcbbQunNameColor );
	gbQunNameLayout->addLayout( layout1_2 );
	
	layout2_2 = new TQHBoxLayout( 0, 0, 6, "layout2_2"); 
	
	chbQunNameFontB = new TQCheckBox( gbQunName, "chbQunNameFontB" );
	layout2_2->addWidget( chbQunNameFontB );
	
	chbQunNameFontU = new TQCheckBox( gbQunName, "chbQunNameFontU" );
	layout2_2->addWidget( chbQunNameFontU );
	
	chbQunNameFontI = new TQCheckBox( gbQunName, "chbQunNameFontI" );
	layout2_2->addWidget( chbQunNameFontI );
	gbQunNameLayout->addLayout( layout2_2 );
	layout11->addWidget( gbQunName );
	
	gbQunFlash = new TQGroupBox( TabPage_2, "gbQunFlash" );
	gbQunFlash->setColumnLayout(0, TQt::Vertical );
	gbQunFlash->layout()->setSpacing( 6 );
	gbQunFlash->layout()->setMargin( 11 );
	gbQunFlashLayout = new TQVBoxLayout( gbQunFlash->layout() );
	gbQunFlashLayout->setAlignment( TQt::AlignTop );
	
	layout3_2 = new TQHBoxLayout( 0, 0, 6, "layout3_2"); 

	lblQunFlashColor = new TQLabel( gbQunFlash, "lblQunFlashColor" );
	layout3_2->addWidget( lblQunFlashColor );
	
	kcbbQunFlashColor = new KColorCombo( gbQunFlash, "kcbbQunFlashColor" );
	layout3_2->addWidget( kcbbQunFlashColor );
	gbQunFlashLayout->addLayout( layout3_2 );
	
	layout4_2 = new TQHBoxLayout( 0, 0, 6, "layout4_2"); 
	
	chbQunFlashFontB = new TQCheckBox( gbQunFlash, "chbQunFlashFontB" );
	layout4_2->addWidget( chbQunFlashFontB );
	
	chbQunFlashFontU = new TQCheckBox( gbQunFlash, "chbQunFlashFontU" );
	layout4_2->addWidget( chbQunFlashFontU );
	
	chbQunFlashFontI = new TQCheckBox( gbQunFlash, "chbQunFlashFontI" );
	layout4_2->addWidget( chbQunFlashFontI );
	gbQunFlashLayout->addLayout( layout4_2 );
	layout11->addWidget( gbQunFlash );
	TabPageLayout_2->addLayout( layout11 );
	ktabMainListFont->addTab(TabPage_2, i18n("Qun Font"));
	
	TabPage_3 = new TQWidget( ktabMainListFont, "TabPage_3" );
	TabPageLayout_3 = new TQVBoxLayout( TabPage_3, 11, 6, "TabPageLayout_3"); 
	
	gbGroupName = new TQGroupBox( TabPage_3, "gbGroupName" );
	gbGroupName->setColumnLayout(0, TQt::Vertical );
	gbGroupName->layout()->setSpacing( 6 );
	gbGroupName->layout()->setMargin( 11 );
	gbGroupNameLayout = new TQVBoxLayout( gbGroupName->layout() );
	gbGroupNameLayout->setAlignment( TQt::AlignTop );
	
	layout1_3 = new TQHBoxLayout( 0, 0, 6, "layout1_3"); 
	
	lblGroupNameColor = new TQLabel( gbGroupName, "lblGroupNameColor" );
	layout1_3->addWidget( lblGroupNameColor );
	
	kcbbGroupNameColor = new KColorCombo( gbGroupName, "kcbbGroupNameColor" );
	layout1_3->addWidget( kcbbGroupNameColor );
	gbGroupNameLayout->addLayout( layout1_3 );
	
	layout2_3 = new TQHBoxLayout( 0, 0, 6, "layout2_3"); 
	
	chbGroupNameFontB = new TQCheckBox( gbGroupName, "chbGroupNameFontB" );
	layout2_3->addWidget( chbGroupNameFontB );
	
	chbGroupNameFontU = new TQCheckBox( gbGroupName, "chbGroupNameFontU" );
	layout2_3->addWidget( chbGroupNameFontU );
	
	chbGroupNameFontI = new TQCheckBox( gbGroupName, "chbGroupNameFontI" );
	layout2_3->addWidget( chbGroupNameFontI );
	gbGroupNameLayout->addLayout( layout2_3 );
	TabPageLayout_3->addWidget( gbGroupName );
	
	gbGroupFlash = new TQGroupBox( TabPage_3, "gbGroupFlash" );
	gbGroupFlash->setColumnLayout(0, TQt::Vertical );
	gbGroupFlash->layout()->setSpacing( 6 );
	gbGroupFlash->layout()->setMargin( 11 );
	gbGroupFlashLayout = new TQVBoxLayout( gbGroupFlash->layout() );
	gbGroupFlashLayout->setAlignment( TQt::AlignTop );
	
	layout3_3 = new TQHBoxLayout( 0, 0, 6, "layout3_3"); 
	
	lblGroupFlashColor = new TQLabel( gbGroupFlash, "lblGroupFlashColor" );
	layout3_3->addWidget( lblGroupFlashColor );
	
	kcbbGroupFlashColor = new KColorCombo( gbGroupFlash, "kcbbGroupFlashColor" );
	layout3_3->addWidget( kcbbGroupFlashColor );
	gbGroupFlashLayout->addLayout( layout3_3 );
	
	layout4_3 = new TQHBoxLayout( 0, 0, 6, "layout4_3"); 
	
	chbGroupFlashFontB = new TQCheckBox( gbGroupFlash, "chbGroupFlashFontB" );
	layout4_3->addWidget( chbGroupFlashFontB );
	
	chbGroupFlashFontU = new TQCheckBox( gbGroupFlash, "chbGroupFlashFontU" );
	layout4_3->addWidget( chbGroupFlashFontU );
	
	chbGroupFlashFontI = new TQCheckBox( gbGroupFlash, "chbGroupFlashFontI" );
	layout4_3->addWidget( chbGroupFlashFontI );
	gbGroupFlashLayout->addLayout( layout4_3 );
	TabPageLayout_3->addWidget( gbGroupFlash );
	
	gbGroupOnlineCount = new TQGroupBox( TabPage_3, "gbGroupOnlineCount" );
	gbGroupOnlineCount->setColumnLayout(0, TQt::Vertical );
	gbGroupOnlineCount->layout()->setSpacing( 6 );
	gbGroupOnlineCount->layout()->setMargin( 11 );
	gbGroupOnlineCountLayout = new TQVBoxLayout( gbGroupOnlineCount->layout() );
	gbGroupOnlineCountLayout->setAlignment( TQt::AlignTop );
	
	layout5_2 = new TQHBoxLayout( 0, 0, 6, "layout5_2"); 
	
	lblGroupOnlineColor = new TQLabel( gbGroupOnlineCount, "lblGroupOnlineColor" );
	layout5_2->addWidget( lblGroupOnlineColor );
	
	kcbbGroupOnlineColor = new KColorCombo( gbGroupOnlineCount, "kcbbGroupOnlineColor" );
	layout5_2->addWidget( kcbbGroupOnlineColor );
	gbGroupOnlineCountLayout->addLayout( layout5_2 );
	
	layout6_2 = new TQHBoxLayout( 0, 0, 6, "layout6_2"); 

	chbGroupOnlineFontB = new TQCheckBox( gbGroupOnlineCount, "chbGroupOnlineFontB" );
	layout6_2->addWidget( chbGroupOnlineFontB );
	
	chbGroupOnlineFontU = new TQCheckBox( gbGroupOnlineCount, "chbGroupOnlineFontU" );
	layout6_2->addWidget( chbGroupOnlineFontU );
	
	chbGroupOnlineFontI = new TQCheckBox( gbGroupOnlineCount, "chbGroupOnlineFontI" );
	layout6_2->addWidget( chbGroupOnlineFontI );
	gbGroupOnlineCountLayout->addLayout( layout6_2 );
	TabPageLayout_3->addWidget( gbGroupOnlineCount );
	ktabMainListFont->addTab(TabPage_3, i18n("Group Font"));

	MainListFontSettingUIBaseLayout->addWidget( ktabMainListFont, 0, 0 );
	languageChange();
	resize( TQSize(341, 345).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
MainListFontSettingUIBase::~MainListFontSettingUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void MainListFontSettingUIBase::languageChange()
{
	setCaption( TQString::null );
	gbBuddyNick->setTitle( i18n("Nickname:" ) );
	lblBuddyNickColor->setText( i18n("nickname color:" ) );
	chbBuddyNickFontB->setText( i18n("bold" ) );
	chbBuddyNickFontU->setText( i18n("underline" ) );
	chbBuddyNickFontI->setText( i18n("italic" ) );
	gbBuddyFlash->setTitle( i18n("Message Flashing:" ) );
	lblBuddyFlashColor->setText( i18n("flashing color:" ) );
	chbBuddyFlashFontB->setText( i18n("bold" ) );
	chbBuddyFlashFontU->setText( i18n("underline" ) );
	chbBuddyFlashFontI->setText( i18n("italic" ) );
	gbBuddySignature->setTitle( i18n("Signature:" ) );
	lblBuddySigColor->setText( i18n("signature color:" ) );
	chbBuddySigFontB->setText( i18n("bold" ) );
	chbBuddySigFontU->setText( i18n("underline" ) );
	chbBuddySigFontI->setText( i18n("italic" ) );
	gbQunName->setTitle( i18n("Name:" ) );
	lblQunNameColor->setText( i18n("name color:" ) );
	chbQunNameFontB->setText( i18n("bold" ) );
	chbQunNameFontU->setText( i18n("underline" ) );
	chbQunNameFontI->setText( i18n("italic" ) );
	gbQunFlash->setTitle( i18n("Message Flashing:" ) );
	lblQunFlashColor->setText( i18n("flashing color:" ) );
	chbQunFlashFontB->setText( i18n("bold" ) );
	chbQunFlashFontU->setText( i18n("underline" ) );
	chbQunFlashFontI->setText( i18n("italic" ) );
	gbGroupName->setTitle( i18n("Name:" ) );
	lblGroupNameColor->setText( i18n("name color:" ) );
	chbGroupNameFontB->setText( i18n("bold" ) );
	chbGroupNameFontU->setText( i18n("underline" ) );
	chbGroupNameFontI->setText( i18n("italic" ) );
	gbGroupFlash->setTitle( i18n("Message Flashing:" ) );
	lblGroupFlashColor->setText( i18n("flashing color:" ) );
	chbGroupFlashFontB->setText( i18n("bold" ) );
	chbGroupFlashFontU->setText( i18n("underline" ) );
	chbGroupFlashFontI->setText( i18n("italic" ) );
	gbGroupOnlineCount->setTitle( i18n("Online statistics:" ) );
	lblGroupOnlineColor->setText( i18n("signature color:" ) );
	chbGroupOnlineFontB->setText( i18n("bold" ) );
	chbGroupOnlineFontU->setText( i18n("underline" ) );
	chbGroupOnlineFontI->setText( i18n("italic" ) );
}

