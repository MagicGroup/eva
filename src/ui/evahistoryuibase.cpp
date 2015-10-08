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
#include "evahistoryuibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqcheckbox.h>
#include <ntqlabel.h>
#include <ntqdatetimeedit.h>
#include <ntqtable.h>
#include <ntqlayout.h>
#include <ntqimage.h>
#include <ntqpixmap.h>
#include <tdelocale.h>

EvaHistoryUIBase::EvaHistoryUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
	if ( !name )
		setName( "EvaHistoryUIBase" );
	EvaHistoryUIBaseLayout = new TQGridLayout( this, 1, 1, 0, 0, "EvaHistoryUIBaseLayout"); 
	
	layout1 = new TQVBoxLayout( 0, 0, 6, "layout1"); 
	
	layout2 = new TQHBoxLayout( 0, 0, 6, "layout2"); 
	
	chbSelect = new TQCheckBox( this, "chbSelect" );
	layout2->addWidget( chbSelect );
	
	lblFrom = new TQLabel( this, "lblFrom" );
	lblFrom->setMaximumSize( TQSize( 30, 32767 ) );
	layout2->addWidget( lblFrom );
	
	deFrom = new TQDateEdit( this, "deFrom" );
	deFrom->setOrder(TQDateEdit::YMD);
	deFrom->setDate(TQDate::currentDate());
	//deFrom->setMaximumSize( TQSize( 90, 32767 ) );
	layout2->addWidget( deFrom );
	
	lblTo = new TQLabel( this, "lblTo" );
	lblTo->setMaximumSize( TQSize( 20, 32767 ) );
	layout2->addWidget( lblTo );
	
	deTo = new TQDateEdit( this, "deTo" );
	deTo->setOrder(TQDateEdit::YMD);
	deTo->setDate(TQDate::currentDate());
	//deTo->setMaximumSize( TQSize( 90, 32767 ) );
	layout2->addWidget( deTo );
	spacer1 = new TQSpacerItem( 21, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout2->addItem( spacer1 );
	
	pbShow = new TQPushButton( this, "pbShow" );
	layout2->addWidget( pbShow );
	layout1->addLayout( layout2 );
	
	tblDisplay = new TQTable( this, "tblDisplay" );
	TQHeader *vheader = tblDisplay->verticalHeader();
	vheader->hide();
	tblDisplay->setLeftMargin(0);
	tblDisplay->setNumRows( 0 );
	tblDisplay->setNumCols( 3 );
	//tblDisplay->setColumnWidth(0, 10);
	//tblDisplay->setColumnWidth(1, 5);
	//tblDisplay->setColumnWidth(2, 5);
	tblDisplay->setSelectionMode( TQTable::SingleRow );
	tblDisplay->setFocusStyle( TQTable::FollowStyle );
	tblDisplay->setReadOnly( true );
	layout1->addWidget( tblDisplay );
	
	layout3 = new TQHBoxLayout( 0, 0, 6, "layout3"); 
	spacer2 = new TQSpacerItem( 121, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
	layout3->addItem( spacer2 );
	
	pbPrev = new TQPushButton( this, "pbPrev" );
	layout3->addWidget( pbPrev );
	
	pbNext = new TQPushButton( this, "pbNext" );
	layout3->addWidget( pbNext );
	layout1->addLayout( layout3 );
	
	EvaHistoryUIBaseLayout->addLayout( layout1, 0, 0 );
	languageChange();
	resize( TQSize(472, 219).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
}

EvaHistoryUIBase::~EvaHistoryUIBase()
{
}

void EvaHistoryUIBase::languageChange()
{
	setCaption( i18n( "View IM Histroy" ) );
	tblDisplay->horizontalHeader()->setLabel( 0, i18n( "Contents" ) );
	tblDisplay->horizontalHeader()->setLabel( 1, i18n( "Nickname" ) );
	tblDisplay->horizontalHeader()->setLabel( 2, i18n( "Time" ) );
	chbSelect->setText( i18n( "specify period:" ) );
	lblFrom->setText( i18n( "from" ) );
	lblTo->setText( i18n( "to" ) );
	pbShow->setText( i18n( "&Show" ) );
	pbShow->setAccel( TQKeySequence( tr( "Alt+S" ) ) );
	pbPrev->setText( i18n( "&Prev" ) );
	pbPrev->setAccel( TQKeySequence( tr( "Alt+P" ) ) );
	pbNext->setText( i18n( "&Next" ) );
	pbNext->setAccel( TQKeySequence( tr( "Alt+N" ) ) );
}

