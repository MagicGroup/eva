/****************************************************************************
** Form implementation generated from reading ui file 'createsmileyui.ui'
**
** Created: 五  9月 1 00:01:38 2006
**      by: The User Interface Compiler ($Id: createsmileyui.cpp,v 1.3 2006/09/05 12:18:48 yunfan Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "createsmileyui.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqlabel.h>
#include <ntqlineedit.h>
#include <ntqcombobox.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqrect.h>
#include <ntqwhatsthis.h>
#include <tdelocale.h>
#include <tdeapplication.h>

/*
 *  Constructs a CreateSmileyUI as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
CreateSmileyUI::CreateSmileyUI( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "CreateSmileyUI" );
    CreateSmileyUILayout = new TQGridLayout( this, 1, 1, 11, 6, "CreateSmileyUILayout"); 

    layout21 = new TQVBoxLayout( 0, 0, 6, "layout21"); 

    lblTop = new TQLabel( this, "lblTop" );
    lblTop->setPaletteForegroundColor( TQColor( 0, 51, 153 ) );
    layout21->addWidget( lblTop );

    lblStep1 = new TQLabel( this, "lblStep1" );
    lblStep1->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignVCenter ) );
    layout21->addWidget( lblStep1 );

    layout16 = new TQHBoxLayout( 0, 0, 6, "layout16"); 
    spacer6 = new TQSpacerItem( 20, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout16->addItem( spacer6 );

    lblSelect = new TQLabel( this, "lblSelect" );
    lblSelect->setPaletteForegroundColor( TQColor( 102, 0, 153 ) );
    lblSelect->setFrameShape( TQLabel::Box );
    layout16->addWidget( lblSelect );

    btnSelect = new TQPushButton( this, "btnSelect" );
    layout16->addWidget( btnSelect );
    layout21->addLayout( layout16 );

    lblStep2 = new TQLabel( this, "lblStep2" );
    layout21->addWidget( lblStep2 );

    layout19 = new TQHBoxLayout( 0, 0, 6, "layout19"); 
    spacer6_3 = new TQSpacerItem( 20, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout19->addItem( spacer6_3 );

    leShortcut = new TQLineEdit( this, "leShortcut" );
    leShortcut->setMaxLength( 6 );
    layout19->addWidget( leShortcut );
    spacer9 = new TQSpacerItem( 31, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout19->addItem( spacer9 );

    lblStep2_2 = new TQLabel( this, "lblStep2_2" );
    layout19->addWidget( lblStep2_2 );

    cbbGroup = new TQComboBox( FALSE, this, "cbbGroup" );
    layout19->addWidget( cbbGroup );
    layout21->addLayout( layout19 );

    lblStep3 = new TQLabel( this, "lblStep3" );
    layout21->addWidget( lblStep3 );

    layout17 = new TQHBoxLayout( 0, 0, 6, "layout17"); 
    spacer6_2 = new TQSpacerItem( 20, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout17->addItem( spacer6_2 );

    leTip = new TQLineEdit( this, "leTip" );
    layout17->addWidget( leTip );
    layout21->addLayout( layout17 );

    layout20 = new TQHBoxLayout( 0, 0, 6, "layout20"); 
    spacer6_2_2 = new TQSpacerItem( 20, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout20->addItem( spacer6_2_2 );

    lblCommends = new TQLabel( this, "lblCommends" );
    lblCommends->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignVCenter ) );
    layout20->addWidget( lblCommends );
    layout21->addLayout( layout20 );

    layout14 = new TQHBoxLayout( 0, 0, 6, "layout14"); 
    spacer5 = new TQSpacerItem( 141, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout14->addItem( spacer5 );

    btnOK = new TQPushButton( this, "btnOK" );
    layout14->addWidget( btnOK );

    btnCancel = new TQPushButton( this, "btnCancel" );
    layout14->addWidget( btnCancel );
    layout21->addLayout( layout14 );

    CreateSmileyUILayout->addLayout( layout21, 0, 0 );
    languageChange();
    resize( TQSize(445, 316).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    TQRect scr = TDEApplication::desktop()->screenGeometry();
    move(scr.center()-rect().center());
}

/*
 *  Destroys the object and frees any allocated resources
 */
CreateSmileyUI::~CreateSmileyUI()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CreateSmileyUI::languageChange()
{
    setCaption( i18n("Add custom smiley" ) );
    lblTop->setText( i18n("<b>Please follow the steps below to create your smiley.</b><br>\n"
"<b>You could select one or more files at a time.</b>" ) );
    lblStep1->setText( i18n("1. Select files from your computer.<br>\n"
"&nbsp;&nbsp;&nbsp;&nbsp;<font color=\"#0066cc\">(150 pixels x 150 pixels or smaller size for better quality. )</font>" ) );
    lblSelect->setText( TQString::null );
    btnSelect->setText( i18n("Select Images ..." ) );
    lblStep2->setText( i18n("2. Input the shortcut key for the smiley. Max length is 6 chars.<br>\n"
"&nbsp;&nbsp;&nbsp;&nbsp;<font color=\"#0066cc\">For example: >3Q. You could leave it empty.</font>" ) );
    lblStep2_2->setText( i18n("Select Group:" ) );
    lblStep3->setText( i18n("3. Give your smiley a name." ) );
    lblCommends->setText( i18n("<font color=\"#0099cc\">Note: When creating more than one smileys, the file names would be used as smiley names and shortcuts.</font>" ) );
    btnOK->setText( i18n("&OK" ) );
    btnOK->setAccel( TQKeySequence( tr( "Alt+O" ) ) );
    btnCancel->setText( i18n("&Cancel" ) );
    btnCancel->setAccel( TQKeySequence( tr( "Alt+C" ) ) );
}

