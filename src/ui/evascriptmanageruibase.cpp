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

#include "evascriptmanageruibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqframe.h>
#include <ntqheader.h>
#include <tdelistview.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <tdelistview.h>

/*
 *  Constructs a EvaScriptManagerUIBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EvaScriptManagerUIBase::EvaScriptManagerUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "EvaScriptManagerUIBase" );
    EvaScriptManagerUIBaseLayout = new TQGridLayout( this, 1, 1, 0, 6, "EvaScriptManagerUIBaseLayout"); 

    btnInstall = new TQPushButton( this, "btnInstall" );

    EvaScriptManagerUIBaseLayout->addWidget( btnInstall, 0, 1 );

    btnUninstall = new TQPushButton( this, "btnUninstall" );

    EvaScriptManagerUIBaseLayout->addWidget( btnUninstall, 1, 1 );

    line1 = new TQFrame( this, "line1" );
    line1->setFrameShape( TQFrame::HLine );
    line1->setFrameShadow( TQFrame::Sunken );
    line1->setFrameShape( TQFrame::HLine );

    EvaScriptManagerUIBaseLayout->addWidget( line1, 2, 1 );

    btnRun = new TQPushButton( this, "btnRun" );

    EvaScriptManagerUIBaseLayout->addWidget( btnRun, 3, 1 );

    btnStop = new TQPushButton( this, "btnStop" );

    EvaScriptManagerUIBaseLayout->addWidget( btnStop, 4, 1 );

    btnConfig = new TQPushButton( this, "btnConfig" );

    EvaScriptManagerUIBaseLayout->addWidget( btnConfig, 5, 1 );

    btnAbout = new TQPushButton( this, "btnAbout" );

    EvaScriptManagerUIBaseLayout->addWidget( btnAbout, 6, 1 );
    spacer1 = new TQSpacerItem( 20, 31, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    EvaScriptManagerUIBaseLayout->addItem( spacer1, 7, 1 );

    listView = new TDEListView( this, "listView" );
    listView->addColumn( tr( "Scripts" ) );

    EvaScriptManagerUIBaseLayout->addMultiCellWidget( listView, 0, 7, 0, 0 );
    languageChange();
    resize( TQSize(350, 308).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( listView, btnInstall );
    setTabOrder( btnInstall, btnUninstall );
    setTabOrder( btnUninstall, btnRun );
    setTabOrder( btnRun, btnStop );
    setTabOrder( btnStop, btnConfig );
    setTabOrder( btnConfig, btnAbout );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaScriptManagerUIBase::~EvaScriptManagerUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaScriptManagerUIBase::languageChange()
{
    setCaption( tr( "Script Manager" ) );
    btnInstall->setText( tr( "&Install Script" ) );
    btnInstall->setAccel( TQKeySequence( tr( "Alt+I" ) ) );
    btnUninstall->setText( tr( "&Uninstall Script" ) );
    btnUninstall->setAccel( TQKeySequence( tr( "Alt+U" ) ) );
    btnRun->setText( tr( "&Run" ) );
    btnRun->setAccel( TQKeySequence( tr( "Alt+R" ) ) );
    btnStop->setText( tr( "&Stop" ) );
    btnStop->setAccel( TQKeySequence( tr( "Alt+S" ) ) );
    btnConfig->setText( tr( "&Configure" ) );
    btnConfig->setAccel( TQKeySequence( tr( "Alt+C" ) ) );
    btnAbout->setText( tr( "&About" ) );
    btnAbout->setAccel( TQKeySequence( tr( "Alt+A" ) ) );
    listView->header()->setLabel( 0, tr( "Scripts" ) );
    TQToolTip::add( listView, tr( "These scripts are currently known to Eva." ) );
}

