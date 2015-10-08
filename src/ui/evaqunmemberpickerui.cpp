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

#include "evaqunmemberpickerui.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqframe.h>
#include <ntqlabel.h>
#include <ntqheader.h>
#include <ntqlistview.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <ntqimage.h>
#include <ntqpixmap.h>
#include <tdelocale.h>

/*
 *  Constructs a EvaQunMemberPickerUI as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EvaQunMemberPickerUI::EvaQunMemberPickerUI( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
	if ( !name )
		setName( "EvaQunMemberPickerUI" );
	EvaQunMemberPickerUILayout = new TQGridLayout( this, 1, 1, 0, 0, "EvaQunMemberPickerUILayout"); 
	
	fraMain = new TQFrame( this, "fraMain" );
	fraMain->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)1, (TQSizePolicy::SizeType)5, 0, 0, fraMain->sizePolicy().hasHeightForWidth() ) );
	fraMain->setFrameShape( TQFrame::GroupBoxPanel );
	fraMain->setFrameShadow( TQFrame::Raised );
	fraMainLayout = new TQGridLayout( fraMain, 1, 1, 6, 3, "fraMainLayout"); 
	
	layout1 = new TQVBoxLayout( 0, 0, 6, "layout1"); 
	
	line1 = new TQFrame( fraMain, "line1" );
	line1->setFrameShape( TQFrame::HLine );
	line1->setFrameShadow( TQFrame::Raised );
	line1->setFrameShape( TQFrame::HLine );
	layout1->addWidget( line1 );
	
	line2 = new TQFrame( fraMain, "line2" );
	line2->setFrameShape( TQFrame::HLine );
	line2->setFrameShadow( TQFrame::Raised );
	line2->setFrameShape( TQFrame::HLine );
	layout1->addWidget( line2 );
	
	lblTitle = new TQLabel( fraMain, "lblTitle" );
	layout1->addWidget( lblTitle );
	
	lvBuddyList = new TQListView( fraMain, "lvBuddyList" );
	lvBuddyList->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)7, 0, 0, lvBuddyList->sizePolicy().hasHeightForWidth() ) );
	lvBuddyList->addColumn("");
	lvBuddyList->setSelectionMode(TQListView::Single);
	layout1->addWidget( lvBuddyList );
	
	fraMainLayout->addLayout( layout1, 0, 0 );
	
	EvaQunMemberPickerUILayout->addWidget( fraMain, 0, 0 );
	languageChange();
	resize( TQSize(220, 337).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaQunMemberPickerUI::~EvaQunMemberPickerUI()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaQunMemberPickerUI::languageChange()
{
	setCaption( i18n( "Qun Member Picker" ) );
	lblTitle->setText( i18n( "Please select members from your list" ) );
}

