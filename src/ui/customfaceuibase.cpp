 /***************************************************************************
 *   Copyright (C) 2006 by yunfan                                          *
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

#include "customfaceuibase.h"

#include <ntqvariant.h>
#include <ntqtabwidget.h>
#include <ntqtoolbutton.h>
#include <ntqcheckbox.h>
#include <ntqlabel.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <tdelocale.h>


CustomFaceUIBase::CustomFaceUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "CustomFaceUIBase" );
    setPaletteBackgroundColor( TQColor( 255, 255, 255 ) );
    CustomFaceUIBaseLayout = new TQGridLayout( this, 1, 1, 1, 0, "CustomFaceUIBaseLayout"); 

    layout2 = new TQVBoxLayout( 0, 0, 0, "layout2"); 

    twSelector = new TQTabWidget( this, "twSelector" );
    twSelector->setPaletteBackgroundColor( TQColor( 255, 255, 255 ) );

    layout2->addWidget( twSelector );

    layout1 = new TQHBoxLayout( 0, 5, 6, "layout1"); 

    tbAdd = new TQToolButton( this, "tbAdd" );
    tbAdd->setBackgroundMode( TQToolButton::PaletteBackground );
    tbAdd->setPaletteForegroundColor( TQColor( 4, 74, 155 ) );
    tbAdd->setAutoRaise( TRUE );
    layout1->addWidget( tbAdd );

    chbUseShortcut = new TQCheckBox( this, "chbUseShortcut" );
    chbUseShortcut->setPaletteForegroundColor( TQColor( 4, 74, 155 ) );
    layout1->addWidget( chbUseShortcut );
    spacer1 = new TQSpacerItem( 41, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout1->addItem( spacer1 );

    lblPage = new TQLabel( this, "lblPage" );
    lblPage->setPaletteForegroundColor( TQColor( 4, 74, 155 ) );
    layout1->addWidget( lblPage );

    tbPrev = new TQToolButton( this, "tbPrev" );
    tbPrev->setPaletteForegroundColor( TQColor( 4, 74, 155 ) );
    layout1->addWidget( tbPrev );

    tbNext = new TQToolButton( this, "tbNext" );
    tbNext->setPaletteForegroundColor( TQColor( 4, 74, 155 ) );
    layout1->addWidget( tbNext );
    layout2->addLayout( layout1 );

    CustomFaceUIBaseLayout->addLayout( layout2, 0, 0 );
    languageChange();
    resize( TQSize(384, 265).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

CustomFaceUIBase::~CustomFaceUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

void CustomFaceUIBase::languageChange()
{
	setCaption( i18n( "CustomFaceUIBase" ) );
	tbAdd->setText( i18n( "Add smiley" ) );
	TQToolTip::add( tbAdd, i18n( "add Custom Smiley" ) );
	chbUseShortcut->setText( i18n( "&Use Shortcut" ) );
	chbUseShortcut->setAccel( TQKeySequence( i18n( "Alt+U" ) ) );
	lblPage->setText( i18n( "0/0" ) );
	tbPrev->setText( i18n( "<<" ) );
	TQToolTip::add( tbPrev, i18n( "previous page" ) );
	tbNext->setText( i18n( ">>" ) );
	TQToolTip::add( tbNext, i18n( "next page" ) );
}

