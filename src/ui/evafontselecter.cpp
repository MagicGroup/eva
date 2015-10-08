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
  
#include "evafontselecter.h"

#include <ntqvariant.h>
#include <ntqlabel.h>
#include <kcolorcombo.h>
#include <knuminput.h>
#include <ntqpushbutton.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <ntqimage.h>
#include <ntqpixmap.h>
#include <ntqframe.h>
#include <tdelocale.h>

#include <stdio.h>

EvaFontSelecter::EvaFontSelecter( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
	if ( !name )
		setName( "EvaFontSelecter" );
	EvaFontWindowLayout = new TQGridLayout( this, 1, 1, 0, 0, "EvaFontWindowLayout");
	
	frame = new TQFrame( this, "frame" );
	frame->setFrameShape( TQFrame::StyledPanel );
	frame->setFrameShadow( TQFrame::Raised );
	frame->setLineWidth( 1 );
	
	EvaFontSelecterLayout = new TQGridLayout( frame, 1, 1, 11, 6, "EvaFontSelecterLayout"); 
	
	layout3 = new TQHBoxLayout( 0, 3, 6, "layout3"); 
	
	lblColor = new TQLabel( frame, "lblColor" );
	layout3->addWidget( lblColor );
	
	color = new KColorCombo( frame, "kColorButton" );
	color->setMaximumSize( TQSize( 80, 32767 ) );
	layout3->addWidget( color );
	TQObject::connect(color, SIGNAL(activated( const TQColor & )), this, SLOT(slotClicked()));
	
	lblSize = new TQLabel( frame, "lblSize" );
	layout3->addWidget( lblSize );
	
	kIntSpinBox = new KIntSpinBox( frame, "kIntSpinBox" );
	kIntSpinBox->setButtonSymbols( KIntSpinBox::UpDownArrows );
	kIntSpinBox->setMaxValue( 20 );
	kIntSpinBox->setMinValue( 8 );
	//kIntSpinBox->setValue( 9 );
	kIntSpinBox->setBase( 10 );
	layout3->addWidget( kIntSpinBox );
	
	pbOK = new TQPushButton( frame, "pbOK" );
	pbOK->setMaximumSize( TQSize( 32767, 50 ) );
	layout3->addWidget( pbOK );
	
	EvaFontSelecterLayout->addLayout( layout3, 0, 0 );
	EvaFontWindowLayout->addWidget( frame, 0, 0 );

	languageChange();
	resize( TQSize(258, 52).expandedTo(minimumSizeHint()) );
	clearWState( WState_Polished );
	TQObject::connect(pbOK, SIGNAL(clicked()), this, SLOT(slotClicked()));
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaFontSelecter::~EvaFontSelecter()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaFontSelecter::languageChange()
{
	setCaption( i18n( "Font Selecter" ) );
	lblColor->setText( i18n( "Color:" ) );
	TQToolTip::add( color, i18n( "select font color" ) );
	lblSize->setText( i18n( "Size:" ) );
	TQToolTip::add( kIntSpinBox, i18n( "select font size" ) );
	pbOK->setText( i18n( "&OK" ) );
	pbOK->setAccel( TQKeySequence( tr( "Alt+O" ) ) );
}

void EvaFontSelecter::slotClicked()
{
	emit fontChanged(color->color(), kIntSpinBox->value());	
	printf("EvaFontSelecter::slotClicked emmited\n");
	close();
	//hide();
}

void EvaFontSelecter::setColor( const TQColor & col )
{
	color->setColor(col);
}

void EvaFontSelecter::setSize( const int size)
{
	kIntSpinBox->setValue(size);
}



