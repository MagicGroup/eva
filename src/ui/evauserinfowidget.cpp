/****************************************************************************
** Form implementation generated from reading ui file 'evauserinfowidget.ui'
**
** Created: 三 11月 23 19:45:12 2005
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "evauserinfowidget.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqlabel.h>
#include <ntqlineedit.h>
#include <ntqtextedit.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>

/*
 *  Constructs a EvaUserInfoWidget as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
EvaUserInfoWidget::EvaUserInfoWidget( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "EvaUserInfoWidget" );
    setEnabled( TRUE );
    setMinimumSize( TQSize( 483, 610 ) );
    setMaximumSize( TQSize( 483, 610 ) );
    setBackgroundOrigin( TQWidget::WidgetOrigin );
    EvaUserInfoWidgetLayout = new TQGridLayout( this, 1, 1, 11, 6, "EvaUserInfoWidgetLayout"); 

    layout191 = new TQGridLayout( 0, 1, 1, 0, 6, "layout191"); 
    spacer18 = new TQSpacerItem( 16, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout191->addItem( spacer18, 0, 1 );

    layout189 = new TQVBoxLayout( 0, 0, 6, "layout189"); 

    layout188 = new TQVBoxLayout( 0, 0, 15, "layout188"); 

    lblBasicInfo = new TQLabel( this, "lblBasicInfo" );
    layout188->addWidget( lblBasicInfo );

    layout187 = new TQHBoxLayout( 0, 0, 6, "layout187"); 

    layout186 = new TQHBoxLayout( 0, 0, 6, "layout186"); 

    layout39 = new TQVBoxLayout( 0, 0, 6, "layout39"); 

    lblRealName = new TQLabel( this, "lblRealName" );
    layout39->addWidget( lblRealName );

    lblNickName = new TQLabel( this, "lblNickName" );
    layout39->addWidget( lblNickName );

    lblAge = new TQLabel( this, "lblAge" );
    layout39->addWidget( lblAge );

    lblArea = new TQLabel( this, "lblArea" );
    layout39->addWidget( lblArea );
    layout186->addLayout( layout39 );

    layout178 = new TQVBoxLayout( 0, 0, 6, "layout178"); 

    leRealName = new TQLineEdit( this, "leRealName" );
    leRealName->setEnabled( TRUE );
    leRealName->setMinimumSize( TQSize( 100, 0 ) );
    leRealName->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leRealName->setFrameShape( TQLineEdit::Box );
    leRealName->setFrameShadow( TQLineEdit::Plain );
    leRealName->setLineWidth( 1 );
    leRealName->setReadOnly( TRUE );
    layout178->addWidget( leRealName );

    leNickName = new TQLineEdit( this, "leNickName" );
    leNickName->setEnabled( TRUE );
    leNickName->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leNickName->setFrameShape( TQLineEdit::Box );
    leNickName->setFrameShadow( TQLineEdit::Plain );
    leNickName->setLineWidth( 1 );
    leNickName->setReadOnly( TRUE );
    layout178->addWidget( leNickName );

    leAge = new TQLineEdit( this, "leAge" );
    leAge->setEnabled( TRUE );
    leAge->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leAge->setFrameShape( TQLineEdit::Box );
    leAge->setFrameShadow( TQLineEdit::Plain );
    leAge->setLineWidth( 1 );
    leAge->setReadOnly( TRUE );
    layout178->addWidget( leAge );

    leArea = new TQLineEdit( this, "leArea" );
    leArea->setEnabled( TRUE );
    leArea->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leArea->setFrameShape( TQLineEdit::Box );
    leArea->setFrameShadow( TQLineEdit::Plain );
    leArea->setLineWidth( 1 );
    leArea->setReadOnly( TRUE );
    layout178->addWidget( leArea );
    layout186->addLayout( layout178 );
    layout187->addLayout( layout186 );

    layout163 = new TQHBoxLayout( 0, 0, 6, "layout163"); 

    layout64 = new TQVBoxLayout( 0, 0, 6, "layout64"); 

    lblNumber = new TQLabel( this, "lblNumber" );
    layout64->addWidget( lblNumber );

    lblLevel = new TQLabel( this, "lblLevel" );
    layout64->addWidget( lblLevel );

    lblSex = new TQLabel( this, "lblSex" );
    layout64->addWidget( lblSex );

    lblProvince = new TQLabel( this, "lblProvince" );
    layout64->addWidget( lblProvince );
    layout163->addLayout( layout64 );

    layout162 = new TQVBoxLayout( 0, 0, 6, "layout162"); 

    layout161 = new TQHBoxLayout( 0, 0, 6, "layout161"); 

    layout86 = new TQVBoxLayout( 0, 0, 6, "layout86"); 

    layout66 = new TQHBoxLayout( 0, 0, 6, "layout66"); 

    leNumber = new TQLineEdit( this, "leNumber" );
    leNumber->setEnabled( TRUE );
    leNumber->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leNumber->setFrameShape( TQLineEdit::Box );
    leNumber->setFrameShadow( TQLineEdit::Plain );
    leNumber->setLineWidth( 1 );
    leNumber->setReadOnly( TRUE );
    layout66->addWidget( leNumber );
    layout86->addLayout( layout66 );

    lblLevelDisplay = new TQLabel( this, "lblLevelDisplay" );
    lblLevelDisplay->setEnabled( TRUE );
    layout86->addWidget( lblLevelDisplay );

    layout65 = new TQHBoxLayout( 0, 0, 6, "layout65"); 

    leSex = new TQLineEdit( this, "leSex" );
    leSex->setEnabled( TRUE );
    leSex->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leSex->setFrameShape( TQLineEdit::Box );
    leSex->setFrameShadow( TQLineEdit::Plain );
    leSex->setLineWidth( 1 );
    leSex->setReadOnly( TRUE );
    layout65->addWidget( leSex );
    layout86->addLayout( layout65 );
    layout161->addLayout( layout86 );

    layout103 = new TQHBoxLayout( 0, 0, 6, "layout103"); 
    spacer17 = new TQSpacerItem( 20, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout103->addItem( spacer17 );

    lblFace = new TQLabel( this, "lblFace" );
    lblFace->setMinimumSize( TQSize( 46, 46 ) );
    lblFace->setMaximumSize( TQSize( 46, 46 ) );
    lblFace->setFrameShape( TQLabel::Box );
    lblFace->setAlignment( int( TQLabel::AlignCenter ) );
    layout103->addWidget( lblFace );
    spacer24 = new TQSpacerItem( 20, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout103->addItem( spacer24 );
    layout161->addLayout( layout103 );
    layout162->addLayout( layout161 );

    layout151 = new TQHBoxLayout( 0, 0, 6, "layout151"); 

    leProvince = new TQLineEdit( this, "leProvince" );
    leProvince->setEnabled( TRUE );
    leProvince->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leProvince->setFrameShape( TQLineEdit::Box );
    leProvince->setFrameShadow( TQLineEdit::Plain );
    leProvince->setLineWidth( 1 );
    leProvince->setReadOnly( TRUE );
    layout151->addWidget( leProvince );

    lblCity = new TQLabel( this, "lblCity" );
    layout151->addWidget( lblCity );

    leCity = new TQLineEdit( this, "leCity" );
    leCity->setEnabled( TRUE );
    leCity->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leCity->setFrameShape( TQLineEdit::Box );
    leCity->setFrameShadow( TQLineEdit::Plain );
    leCity->setLineWidth( 1 );
    leCity->setReadOnly( TRUE );
    layout151->addWidget( leCity );
    spacer26 = new TQSpacerItem( 50, 21, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout151->addItem( spacer26 );
    layout162->addLayout( layout151 );
    layout163->addLayout( layout162 );
    layout187->addLayout( layout163 );
    layout188->addLayout( layout187 );

    layout156 = new TQHBoxLayout( 0, 0, 6, "layout156"); 

    layout99 = new TQGridLayout( 0, 1, 1, 0, 6, "layout99"); 

    teSignature = new TQTextEdit( this, "teSignature" );
    teSignature->setEnabled( TRUE );
    teSignature->setMinimumSize( TQSize( 0, 50 ) );
    teSignature->setMaximumSize( TQSize( 32767, 50 ) );
    teSignature->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    teSignature->setPaletteBackgroundColor( TQColor( 255, 255, 255 ) );
    teSignature->setFocusPolicy( TQTextEdit::NoFocus );
    teSignature->setFrameShape( TQTextEdit::Box );
    teSignature->setFrameShadow( TQTextEdit::Plain );
    teSignature->setLineWidth( 1 );
    teSignature->setHScrollBarMode( TQTextEdit::AlwaysOff );
    teSignature->setWordWrap( TQTextEdit::WidgetWidth );
    teSignature->setReadOnly( TRUE );

    layout99->addMultiCellWidget( teSignature, 0, 1, 1, 1 );

    lblSignature = new TQLabel( this, "lblSignature" );

    layout99->addWidget( lblSignature, 0, 0 );
    layout156->addLayout( layout99 );
    spacer14_2 = new TQSpacerItem( 71, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout156->addItem( spacer14_2 );
    layout188->addLayout( layout156 );
    layout189->addLayout( layout188 );

    layout144 = new TQGridLayout( 0, 1, 1, 0, 15, "layout144"); 

    layout143 = new TQGridLayout( 0, 1, 1, 0, 6, "layout143"); 

    layout142 = new TQGridLayout( 0, 1, 1, 0, 6, "layout142"); 

    lePhone = new TQLineEdit( this, "lePhone" );
    lePhone->setEnabled( TRUE );
    lePhone->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    lePhone->setFrameShape( TQLineEdit::Box );
    lePhone->setFrameShadow( TQLineEdit::Plain );
    lePhone->setLineWidth( 1 );
    lePhone->setReadOnly( TRUE );

    layout142->addWidget( lePhone, 0, 0 );

    leHomePage = new TQLineEdit( this, "leHomePage" );
    leHomePage->setEnabled( TRUE );
    leHomePage->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leHomePage->setFrameShape( TQLineEdit::Box );
    leHomePage->setFrameShadow( TQLineEdit::Plain );
    leHomePage->setLineWidth( 1 );
    leHomePage->setReadOnly( TRUE );

    layout142->addMultiCellWidget( leHomePage, 1, 1, 0, 2 );

    lblMobile = new TQLabel( this, "lblMobile" );

    layout142->addWidget( lblMobile, 0, 1 );

    leMobile = new TQLineEdit( this, "leMobile" );
    leMobile->setEnabled( TRUE );
    leMobile->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leMobile->setFrameShape( TQLineEdit::Box );
    leMobile->setFrameShadow( TQLineEdit::Plain );
    leMobile->setLineWidth( 1 );
    leMobile->setReadOnly( TRUE );

    layout142->addWidget( leMobile, 0, 2 );
    spacer28 = new TQSpacerItem( 41, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout142->addItem( spacer28, 0, 3 );
    spacer29 = new TQSpacerItem( 31, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout142->addItem( spacer29, 1, 3 );

    layout143->addMultiCellLayout( layout142, 2, 2, 0, 1 );
    spacer13_2 = new TQSpacerItem( 180, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout143->addItem( spacer13_2, 1, 1 );

    layout141 = new TQGridLayout( 0, 1, 1, 0, 6, "layout141"); 

    layout139 = new TQHBoxLayout( 0, 0, 6, "layout139"); 

    layout138 = new TQGridLayout( 0, 1, 1, 0, 6, "layout138"); 

    leOccupation = new TQLineEdit( this, "leOccupation" );
    leOccupation->setEnabled( TRUE );
    leOccupation->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leOccupation->setFrameShape( TQLineEdit::Box );
    leOccupation->setFrameShadow( TQLineEdit::Plain );
    leOccupation->setLineWidth( 1 );
    leOccupation->setReadOnly( TRUE );

    layout138->addWidget( leOccupation, 0, 1 );

    leBlood = new TQLineEdit( this, "leBlood" );
    leBlood->setEnabled( TRUE );
    leBlood->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leBlood->setFrameShape( TQLineEdit::Box );
    leBlood->setFrameShadow( TQLineEdit::Plain );
    leBlood->setLineWidth( 1 );
    leBlood->setReadOnly( TRUE );

    layout138->addWidget( leBlood, 1, 1 );

    lblBlood = new TQLabel( this, "lblBlood" );

    layout138->addWidget( lblBlood, 1, 0 );

    lblOccupation = new TQLabel( this, "lblOccupation" );

    layout138->addWidget( lblOccupation, 0, 0 );
    layout139->addLayout( layout138 );
    spacer27 = new TQSpacerItem( 30, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout139->addItem( spacer27 );

    layout141->addMultiCellLayout( layout139, 0, 1, 1, 1 );

    leZodiac = new TQLineEdit( this, "leZodiac" );
    leZodiac->setEnabled( TRUE );
    leZodiac->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leZodiac->setFrameShape( TQLineEdit::Panel );
    leZodiac->setFrameShadow( TQLineEdit::Plain );
    leZodiac->setLineWidth( 1 );
    leZodiac->setReadOnly( TRUE );

    layout141->addWidget( leZodiac, 0, 0 );

    leHoroscape = new TQLineEdit( this, "leHoroscape" );
    leHoroscape->setEnabled( TRUE );
    leHoroscape->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leHoroscape->setFrameShape( TQLineEdit::Box );
    leHoroscape->setFrameShadow( TQLineEdit::Plain );
    leHoroscape->setLineWidth( 1 );
    leHoroscape->setReadOnly( TRUE );

    layout141->addWidget( leHoroscape, 1, 0 );

    layout143->addMultiCellLayout( layout141, 0, 0, 0, 1 );

    layout30 = new TQVBoxLayout( 0, 0, 6, "layout30"); 

    leSchool = new TQLineEdit( this, "leSchool" );
    leSchool->setEnabled( TRUE );
    leSchool->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leSchool->setFrameShape( TQLineEdit::Box );
    leSchool->setFrameShadow( TQLineEdit::Plain );
    leSchool->setLineWidth( 1 );
    leSchool->setReadOnly( TRUE );
    layout30->addWidget( leSchool );

    leEmail = new TQLineEdit( this, "leEmail" );
    leEmail->setEnabled( TRUE );
    leEmail->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leEmail->setFrameShape( TQLineEdit::Box );
    leEmail->setFrameShadow( TQLineEdit::Plain );
    leEmail->setLineWidth( 1 );
    leEmail->setReadOnly( TRUE );
    layout30->addWidget( leEmail );

    leAddress = new TQLineEdit( this, "leAddress" );
    leAddress->setEnabled( TRUE );
    leAddress->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leAddress->setFrameShape( TQLineEdit::Box );
    leAddress->setFrameShadow( TQLineEdit::Plain );
    leAddress->setLineWidth( 1 );
    leAddress->setReadOnly( TRUE );
    layout30->addWidget( leAddress );

    leZipCode = new TQLineEdit( this, "leZipCode" );
    leZipCode->setEnabled( TRUE );
    leZipCode->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    leZipCode->setFrameShape( TQLineEdit::Box );
    leZipCode->setFrameShadow( TQLineEdit::Plain );
    leZipCode->setLineWidth( 1 );
    leZipCode->setReadOnly( TRUE );
    layout30->addWidget( leZipCode );

    layout143->addLayout( layout30, 1, 0 );

    layout144->addLayout( layout143, 1, 1 );

    layout51 = new TQVBoxLayout( 0, 0, 6, "layout51"); 

    lblZodiac = new TQLabel( this, "lblZodiac" );
    layout51->addWidget( lblZodiac );

    lblHoroscape = new TQLabel( this, "lblHoroscape" );
    layout51->addWidget( lblHoroscape );

    lblSchool = new TQLabel( this, "lblSchool" );
    layout51->addWidget( lblSchool );

    lblEmail = new TQLabel( this, "lblEmail" );
    layout51->addWidget( lblEmail );

    lblAddress = new TQLabel( this, "lblAddress" );
    layout51->addWidget( lblAddress );

    lblZipCode = new TQLabel( this, "lblZipCode" );
    layout51->addWidget( lblZipCode );

    lblPhone = new TQLabel( this, "lblPhone" );
    layout51->addWidget( lblPhone );

    lblHomePage = new TQLabel( this, "lblHomePage" );
    layout51->addWidget( lblHomePage );

    layout144->addLayout( layout51, 1, 0 );

    lblDetails = new TQLabel( this, "lblDetails" );

    layout144->addMultiCellWidget( lblDetails, 0, 0, 0, 1 );
    layout189->addLayout( layout144 );

    layout95 = new TQVBoxLayout( 0, 0, 15, "layout95"); 

    lblDescription = new TQLabel( this, "lblDescription" );
    layout95->addWidget( lblDescription );

    layout94 = new TQGridLayout( 0, 1, 1, 0, 6, "layout94"); 
    spacer16 = new TQSpacerItem( 20, 77, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout94->addItem( spacer16, 1, 0 );
    spacer14_2_2 = new TQSpacerItem( 71, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout94->addItem( spacer14_2_2, 1, 2 );

    teAboutMe = new TQTextEdit( this, "teAboutMe" );
    teAboutMe->setEnabled( TRUE );
    teAboutMe->setMinimumSize( TQSize( 0, 0 ) );
    teAboutMe->setMaximumSize( TQSize( 32767, 100 ) );
    teAboutMe->setPaletteForegroundColor( TQColor( 0, 0, 0 ) );
    teAboutMe->setPaletteBackgroundColor( TQColor( 255, 255, 255 ) );
    teAboutMe->setFocusPolicy( TQTextEdit::NoFocus );
    teAboutMe->setFrameShape( TQTextEdit::Box );
    teAboutMe->setFrameShadow( TQTextEdit::Plain );
    teAboutMe->setLineWidth( 1 );
    teAboutMe->setHScrollBarMode( TQTextEdit::AlwaysOff );
    teAboutMe->setWordWrap( TQTextEdit::WidgetWidth );
    teAboutMe->setReadOnly( TRUE );

    layout94->addMultiCellWidget( teAboutMe, 0, 1, 1, 1 );

    lblAboutMe = new TQLabel( this, "lblAboutMe" );

    layout94->addWidget( lblAboutMe, 0, 0 );
    layout95->addLayout( layout94 );
    layout189->addLayout( layout95 );

    layout191->addLayout( layout189, 0, 0 );
    spacer31 = new TQSpacerItem( 20, 40, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout191->addItem( spacer31, 1, 0 );

    EvaUserInfoWidgetLayout->addLayout( layout191, 0, 0 );
    languageChange();
    resize( TQSize(483, 610).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // tab order
    setTabOrder( leRealName, leNickName );
    setTabOrder( leNickName, leAge );
    setTabOrder( leAge, leArea );
    setTabOrder( leArea, leNumber );
    setTabOrder( leNumber, leSex );
    setTabOrder( leSex, leProvince );
    setTabOrder( leProvince, leCity );

    // buddies
    lblRealName->setBuddy( leRealName );
    lblArea->setBuddy( leArea );
    lblNumber->setBuddy( leNumber );
    lblSex->setBuddy( leSex );
    lblProvince->setBuddy( leProvince );
    lblCity->setBuddy( leCity );
    lblMobile->setBuddy( leRealName );
    lblBlood->setBuddy( leRealName );
    lblOccupation->setBuddy( leRealName );
    lblZodiac->setBuddy( leRealName );
    lblHoroscape->setBuddy( leRealName );
    lblSchool->setBuddy( leRealName );
    lblEmail->setBuddy( leRealName );
    lblAddress->setBuddy( leRealName );
    lblZipCode->setBuddy( leRealName );
    lblPhone->setBuddy( leRealName );
    lblHomePage->setBuddy( leRealName );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaUserInfoWidget::~EvaUserInfoWidget()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaUserInfoWidget::languageChange()
{
    setCaption( tr( "UserInfoWidget" ) );
    lblBasicInfo->setText( tr( "Basic Info" ) );
    lblRealName->setText( tr( "Real Name:" ) );
    lblNickName->setText( tr( "Nick Name:" ) );
    lblAge->setText( tr( "Age:" ) );
    lblArea->setText( tr( "Region:" ) );
    leRealName->setText( TQString::null );
    leNickName->setText( TQString::null );
    leAge->setText( TQString::null );
    leArea->setText( TQString::null );
    lblNumber->setText( tr( "QQ Num:" ) );
    lblLevel->setText( tr( "QQ Level:" ) );
    lblSex->setText( tr( "Gender:" ) );
    lblProvince->setText( tr( "Province:" ) );
    leNumber->setText( TQString::null );
    lblLevelDisplay->setText( TQString::null );
    leSex->setText( TQString::null );
    lblFace->setText( TQString::null );
    leProvince->setText( TQString::null );
    lblCity->setText( tr( "City:" ) );
    leCity->setText( TQString::null );
    teSignature->setText( TQString::null );
    lblSignature->setText( tr( "Signature:" ) );
    lePhone->setText( TQString::null );
    leHomePage->setText( TQString::null );
    lblMobile->setText( tr( "Mobile:" ) );
    leMobile->setText( TQString::null );
    leOccupation->setText( TQString::null );
    leBlood->setText( TQString::null );
    lblBlood->setText( tr( "Blood Type:" ) );
    lblOccupation->setText( tr( "Occupation:" ) );
    leZodiac->setText( TQString::null );
    leHoroscape->setText( TQString::null );
    leSchool->setText( TQString::null );
    leEmail->setText( TQString::null );
    leAddress->setText( TQString::null );
    leZipCode->setText( TQString::null );
    lblZodiac->setText( tr( "Chinese Zodiac:" ) );
    lblHoroscape->setText( tr( "Horoscope:" ) );
    lblSchool->setText( tr( "School:" ) );
    lblEmail->setText( tr( "Email:" ) );
    lblAddress->setText( tr( "Address:" ) );
    lblZipCode->setText( tr( "Postal Code:" ) );
    lblPhone->setText( tr( "Phone:" ) );
    lblHomePage->setText( tr( "Home Page:" ) );
    lblDetails->setText( tr( "Details" ) );
    lblDescription->setText( tr( "Description" ) );
    teAboutMe->setText( TQString::null );
    lblAboutMe->setText( tr( "About Me:" ) );
}

