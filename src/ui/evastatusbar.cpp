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
#include "evastatusbar.h"

#include <ntqlabel.h>
#include <ntqtoolbutton.h>
#include <ntqlayout.h>

EvaStatusBar::EvaStatusBar( TQWidget* parent, const char* name, WFlags fl )
    : TQFrame( parent, name, fl )
{
	if ( !name )
		setName( "Eva Status Bar" );

	setFrameShape( TQFrame::NoFrame );
	setFrameShadow( TQFrame::Raised );
	setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)0, 0, 0, sizePolicy().hasHeightForWidth() ) );

	frame4Layout = new TQGridLayout( this, 1, 1, 1, 1, "frame4Layout");

	layout4 = new TQHBoxLayout( 0, 1, 1, "layout4"); 
	
	lblNotification = new TQLabel( this, "lblNotification" );
	lblNotification->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)5, 0, 0, lblNotification->sizePolicy().hasHeightForWidth() ) );
	layout4->addWidget( lblNotification );

	fraSystem = new TQFrame( this, "fraSystem" );
	fraSystem->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)1, 0, 0, fraSystem->sizePolicy().hasHeightForWidth() ) );
	fraSystem->setFrameShape( TQFrame::NoFrame );
	fraSystem->setFrameShadow( TQFrame::Raised );
	fraSystemLayout = new TQGridLayout( fraSystem, 1, 1, 2, 2, "fraSystemLayout"); 

	layout3 = new TQHBoxLayout( 0, 0, 6, "layout3");

	tbSearch = new TQToolButton( fraSystem, "tbSearch" );
	tbSearch->setMinimumSize( TQSize( 24, 24 ) );
	tbSearch->setMaximumSize( TQSize( 24, 24 ) );
	tbSearch->setAutoRaise( TRUE );
	layout3->addWidget( tbSearch );
	
	tbSysMsg = new TQToolButton( fraSystem, "tbSysMsg" );
	tbSysMsg->setMinimumSize( TQSize( 24, 24 ) );
	tbSysMsg->setMaximumSize( TQSize( 24, 24 ) );
	tbSysMsg->setAutoRaise( TRUE );
	layout3->addWidget( tbSysMsg );
	
	tbSystem = new TQToolButton( fraSystem, "tbSystem" );
	tbSystem->setMinimumSize( TQSize( 24, 24 ) );
	tbSystem->setMaximumSize( TQSize( 24, 24 ) );
	//tbSystem->setPopupDelay(0);
	tbSystem->setAutoRaise( TRUE );
	layout3->addWidget( tbSystem );

	fraSystemLayout->addLayout( layout3, 0, 0 );
	layout4->addWidget( fraSystem );
	spacer2 = new TQSpacerItem( 21, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
	layout4->addItem( spacer2 );

	fraStatus = new TQFrame( this, "fraStatus" );
	fraStatus->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)1, 0, 0, fraStatus->sizePolicy().hasHeightForWidth() ) );
	fraStatus->setFrameShape( TQFrame::NoFrame );
	fraStatus->setFrameShadow( TQFrame::Raised );
	fraStatusLayout = new TQGridLayout( fraStatus, 1, 1, 2, 2, "fraStatusLayout"); 
	
	tbStatus = new TQToolButton( fraStatus, "tbStatus" );
	tbStatus->setMinimumSize( TQSize( 24, 24 ) );
	tbStatus->setMaximumSize( TQSize( 24, 24 ) );
	//tbStatus->setPopupDelay(0);
	tbStatus->setAutoRaise( TRUE );
	
	fraStatusLayout->addWidget( tbStatus, 0, 0 );
	layout4->addWidget( fraStatus );

	frame4Layout->addLayout( layout4, 0, 0 );
	resize( TQSize(600, 30).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
}

EvaStatusBar::~EvaStatusBar()
{
}

