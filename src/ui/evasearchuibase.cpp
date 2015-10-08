/***************************************************************************
 *   Copyright (C) 2006 by casper                                          *
 *   tlmcasper@163.com                                                     *
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



#include "evasearchuibase.h"

#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqtabwidget.h>
#include <ntqwidget.h>
#include <ntqwidgetstack.h>
#include <ntqlabel.h>
#include <ntqbuttongroup.h>
#include <ntqradiobutton.h>
#include <ntqgroupbox.h>
#include <ntqlineedit.h>
#include <ntqtable.h>
#include <ntqtoolbutton.h>
#include <ntqcheckbox.h>
#include <ntqcombobox.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <tdelocale.h>

/*
 *  Constructs a EvaSearchUIBase as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
EvaSearchUIBase::EvaSearchUIBase( TQWidget* parent, const char* name, bool modal, WFlags fl )
    : TQDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "EvaSearchUIBase" );
    setEnabled( TRUE );
    setMinimumSize( TQSize( 535, 360 ) );
    setMaximumSize( TQSize( 535, 360 ) );
    EvaSearchUIBaseLayout = new TQGridLayout( this, 1, 1, 11, 6, "EvaSearchUIBaseLayout"); 
    EvaSearchUIBaseLayout->setResizeMode( TQLayout::Minimum );

    layout127 = new TQGridLayout( 0, 1, 1, 0, 6, "layout127"); 

    twSearchMain = new TQTabWidget( this, "twSearchMain" );
    twSearchMain->setMinimumSize( TQSize( 0, 305 ) );
    twSearchMain->setMaximumSize( TQSize( 32767, 305 ) );
    twSearchMain->setMargin( 0 );

    tabBasicSearch = new TQWidget( twSearchMain, "tabBasicSearch" );
    tabBasicSearchLayout = new TQGridLayout( tabBasicSearch, 1, 1, 11, 6, "tabBasicSearchLayout"); 

    wsBasicSearch = new TQWidgetStack( tabBasicSearch, "wsBasicSearch" );
    wsBasicSearch->setMargin( 0 );

    wsBSPage = new TQWidget( wsBasicSearch, "wsBSPage" );
    wsBSPageLayout = new TQGridLayout( wsBSPage, 1, 1, 11, 6, "wsBSPageLayout"); 

    layout135 = new TQVBoxLayout( 0, 0, 6, "layout135"); 

    layout105 = new TQVBoxLayout( 0, 3, 5, "layout105"); 

    lblSearchOptionTip = new TQLabel( wsBSPage, "lblSearchOptionTip" );
    layout105->addWidget( lblSearchOptionTip );

    layout100 = new TQHBoxLayout( 0, 3, 6, "layout100"); 

    bgBSType = new TQButtonGroup( wsBSPage, "bgBSType" );
    bgBSType->setMaximumSize( TQSize( 32767, 94 ) );
    bgBSType->setFrameShape( TQButtonGroup::NoFrame );
    bgBSType->setRadioButtonExclusive( TRUE );
    bgBSType->setProperty( "selectedId", -1 );
    bgBSType->setColumnLayout(0, TQt::Vertical );
    bgBSType->layout()->setSpacing( 0 );
    bgBSType->layout()->setMargin( 0 );
    bgBSTypeLayout = new TQGridLayout( bgBSType->layout() );
    bgBSTypeLayout->setAlignment( TQt::AlignTop );

    rbCustomSearch = new TQRadioButton( bgBSType, "rbCustomSearch" );

    bgBSTypeLayout->addWidget( rbCustomSearch, 1, 0 );

    rbSearchFrdCenter = new TQRadioButton( bgBSType, "rbSearchFrdCenter" );

    bgBSTypeLayout->addWidget( rbSearchFrdCenter, 2, 0 );

    rbSearchOnline = new TQRadioButton( bgBSType, "rbSearchOnline" );

    bgBSTypeLayout->addWidget( rbSearchOnline, 0, 0 );
    layout100->addWidget( bgBSType );
    spacer54 = new TQSpacerItem( 81, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout100->addItem( spacer54 );
    layout105->addLayout( layout100 );
    layout135->addLayout( layout105 );

    wsBasicCondtion = new TQWidgetStack( wsBSPage, "wsBasicCondtion" );
    wsBasicCondtion->setMargin( -9 );

    wsCustomSearchCondition = new TQWidget( wsBasicCondtion, "wsCustomSearchCondition" );
    wsCustomSearchConditionLayout = new TQGridLayout( wsCustomSearchCondition, 1, 1, 11, 6, "wsCustomSearchConditionLayout"); 

    gbCustomCondition = new TQGroupBox( wsCustomSearchCondition, "gbCustomCondition" );
    gbCustomCondition->setMargin( 0 );
    gbCustomCondition->setColumnLayout(0, TQt::Vertical );
    gbCustomCondition->layout()->setSpacing( 6 );
    gbCustomCondition->layout()->setMargin( 11 );
    gbCustomConditionLayout = new TQGridLayout( gbCustomCondition->layout() );
    gbCustomConditionLayout->setAlignment( TQt::AlignTop );

    layout204_2 = new TQHBoxLayout( 0, 0, 6, "layout204_2"); 

    layout188_2 = new TQVBoxLayout( 0, 0, 6, "layout188_2"); 

    lblTQQNum = new TQLabel( gbCustomCondition, "lblTQQNum" );
    layout188_2->addWidget( lblTQQNum );

    lblNickName = new TQLabel( gbCustomCondition, "lblNickName" );
    layout188_2->addWidget( lblNickName );

    layout204_2->addLayout( layout188_2 );

    layout203_2 = new TQVBoxLayout( 0, 0, 6, "layout203_2"); 

    leTQQNum = new TQLineEdit( gbCustomCondition, "leTQQNum" );
    leTQQNum->setMinimumSize( TQSize( 150, 0 ) );
    leTQQNum->setFrameShape( TQLineEdit::Box );
    leTQQNum->setFrameShadow( TQLineEdit::Plain );
    leTQQNum->setLineWidth( 1 );
    layout203_2->addWidget( leTQQNum );

    leNickName = new TQLineEdit( gbCustomCondition, "leNickName" );
    leNickName->setFrameShape( TQLineEdit::Box );
    leNickName->setFrameShadow( TQLineEdit::Plain );
    leNickName->setLineWidth( 1 );
    layout203_2->addWidget( leNickName );

    layout204_2->addLayout( layout203_2 );

    gbCustomConditionLayout->addLayout( layout204_2, 0, 0 );
    spacer119_2 = new TQSpacerItem( 70, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    gbCustomConditionLayout->addItem( spacer119_2, 0, 1 );

    wsCustomSearchConditionLayout->addWidget( gbCustomCondition, 0, 0 );
    wsBasicCondtion->addWidget( wsCustomSearchCondition, 0 );

    wsFrdCenterSearchCondition = new TQWidget( wsBasicCondtion, "wsFrdCenterSearchCondition" );
    wsFrdCenterSearchConditionLayout = new TQGridLayout( wsFrdCenterSearchCondition, 1, 1, 11, 6, "wsFrdCenterSearchConditionLayout"); 

    gbFrdCenterCondition = new TQGroupBox( wsFrdCenterSearchCondition, "gbFrdCenterCondition" );
    gbFrdCenterCondition->setMargin( 0 );
    gbFrdCenterCondition->setColumnLayout(0, TQt::Vertical );
    gbFrdCenterCondition->layout()->setSpacing( 2 );
    gbFrdCenterCondition->layout()->setMargin( 8 );
    gbFrdCenterConditionLayout = new TQGridLayout( gbFrdCenterCondition->layout() );
    gbFrdCenterConditionLayout->setAlignment( TQt::AlignTop );

    layout46 = new TQVBoxLayout( 0, 0, 6, "layout46"); 
    spacer27 = new TQSpacerItem( 20, 20, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout46->addItem( spacer27 );

    lblTQQFrdTip = new TQLabel( gbFrdCenterCondition, "lblTQQFrdTip" );
    lblTQQFrdTip->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignCenter ) );
    layout46->addWidget( lblTQQFrdTip );
    spacer28 = new TQSpacerItem( 20, 21, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout46->addItem( spacer28 );

    gbFrdCenterConditionLayout->addLayout( layout46, 0, 0 );

    wsFrdCenterSearchConditionLayout->addWidget( gbFrdCenterCondition, 0, 0 );
    wsBasicCondtion->addWidget( wsFrdCenterSearchCondition, 1 );
    layout135->addWidget( wsBasicCondtion );

    layout316_2 = new TQHBoxLayout( 0, 0, 6, "layout316_2"); 

    lblOnlineNumbers = new TQLabel( wsBSPage, "lblOnlineNumbers" );
    layout316_2->addWidget( lblOnlineNumbers );

    lblOnlineNum = new TQLabel( wsBSPage, "lblOnlineNum" );
    layout316_2->addWidget( lblOnlineNum );
    spacer111 = new TQSpacerItem( 183, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout316_2->addItem( spacer111 );
    layout135->addLayout( layout316_2 );

    wsBSPageLayout->addLayout( layout135, 0, 0 );
    wsBasicSearch->addWidget( wsBSPage, 0 );

    wsBSResultPage = new TQWidget( wsBasicSearch, "wsBSResultPage" );
    wsBSResultPageLayout = new TQGridLayout( wsBSResultPage, 1, 1, 11, 6, "wsBSResultPageLayout"); 

    layout47 = new TQVBoxLayout( 0, 0, 6, "layout47"); 

    layout96 = new TQHBoxLayout( 0, 0, 6, "layout96"); 

    lblBSResultTip = new TQLabel( wsBSResultPage, "lblBSResultTip" );
    layout96->addWidget( lblBSResultTip );
    spacer46 = new TQSpacerItem( 71, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout96->addItem( spacer46 );
    layout47->addLayout( layout96 );

    tbBSResult = new TQTable( wsBSResultPage, "tbBSResult" );
    tbBSResult->setNumCols( tbBSResult->numCols() + 1 );
    tbBSResult->horizontalHeader()->setLabel( tbBSResult->numCols() - 1, i18n( "Account" ) );
    tbBSResult->setNumCols( tbBSResult->numCols() + 1 );
    tbBSResult->horizontalHeader()->setLabel( tbBSResult->numCols() - 1, i18n( "Nick Name" ) );
    tbBSResult->setNumCols( tbBSResult->numCols() + 1 );
    tbBSResult->horizontalHeader()->setLabel( tbBSResult->numCols() - 1, i18n( "From" ) );
    tbBSResult->setFrameShape( TQTable::Box );
    tbBSResult->setFrameShadow( TQTable::Plain );
    tbBSResult->setLineWidth( 1 );
    tbBSResult->setHScrollBarMode( TQTable::Auto );
    tbBSResult->setNumRows( 0 );
    tbBSResult->setNumCols( 3 );
    tbBSResult->setShowGrid( TRUE );
    tbBSResult->setReadOnly( TRUE );
    tbBSResult->setSelectionMode( TQTable::SingleRow );
    tbBSResult->setFocusStyle( TQTable::FollowStyle );
    layout47->addWidget( tbBSResult );

    layout46_2 = new TQHBoxLayout( 0, 0, 6, "layout46_2"); 

    lblBSResultPage = new TQLabel( wsBSResultPage, "lblBSResultPage" );
    layout46_2->addWidget( lblBSResultPage );
    spacer47 = new TQSpacerItem( 59, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout46_2->addItem( spacer47 );

    tbBSAll = new TQToolButton( wsBSResultPage, "tbBSAll" );
    tbBSAll->setCursor( TQCursor( 13 ) );
    tbBSAll->setAutoRaise( TRUE );
    layout46_2->addWidget( tbBSAll );

    tbBSDetails = new TQToolButton( wsBSResultPage, "tbBSDetails" );
    tbBSDetails->setCursor( TQCursor( 13 ) );
    tbBSDetails->setAutoRaise( TRUE );
    layout46_2->addWidget( tbBSDetails );

    tbBSPrev = new TQToolButton( wsBSResultPage, "tbBSPrev" );
    tbBSPrev->setCursor( TQCursor( 13 ) );
    tbBSPrev->setAutoRaise( TRUE );
    layout46_2->addWidget( tbBSPrev );

    tbBSNext = new TQToolButton( wsBSResultPage, "tbBSNext" );
    tbBSNext->setCursor( TQCursor( 13 ) );
    tbBSNext->setAutoRaise( TRUE );
    layout46_2->addWidget( tbBSNext );
    layout47->addLayout( layout46_2 );

    wsBSResultPageLayout->addLayout( layout47, 0, 0 );
    wsBasicSearch->addWidget( wsBSResultPage, 1 );

    tabBasicSearchLayout->addWidget( wsBasicSearch, 0, 0 );
    twSearchMain->insertTab( tabBasicSearch, TQString::fromLatin1("") );

    tabAdvancedSearch = new TQWidget( twSearchMain, "tabAdvancedSearch" );
    tabAdvancedSearchLayout = new TQGridLayout( tabAdvancedSearch, 1, 1, 11, 6, "tabAdvancedSearchLayout"); 

    wsAdvancedSearch = new TQWidgetStack( tabAdvancedSearch, "wsAdvancedSearch" );

    wsASPage = new TQWidget( wsAdvancedSearch, "wsASPage" );
    wsASPageLayout = new TQGridLayout( wsASPage, 1, 1, 11, 6, "wsASPageLayout"); 

    layout91 = new TQVBoxLayout( 0, 0, 6, "layout91"); 

    layout371 = new TQVBoxLayout( 0, 0, 6, "layout371"); 

    lblASTip = new TQLabel( wsASPage, "lblASTip" );
    layout371->addWidget( lblASTip );

    layout370 = new TQHBoxLayout( 0, 0, 6, "layout370"); 
    spacer156 = new TQSpacerItem( 31, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout370->addItem( spacer156 );

    layout369 = new TQHBoxLayout( 0, 0, 6, "layout369"); 

    chbOnlineUsers = new TQCheckBox( wsASPage, "chbOnlineUsers" );
    layout369->addWidget( chbOnlineUsers );
    spacer155 = new TQSpacerItem( 20, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout369->addItem( spacer155 );

    chbHaveCamera = new TQCheckBox( wsASPage, "chbHaveCamera" );
    layout369->addWidget( chbHaveCamera );
    layout370->addLayout( layout369 );
    spacer157 = new TQSpacerItem( 41, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout370->addItem( spacer157 );
    layout371->addLayout( layout370 );
    layout91->addLayout( layout371 );

    gbBasicCondition = new TQGroupBox( wsASPage, "gbBasicCondition" );
    gbBasicCondition->setColumnLayout(0, TQt::Vertical );
    gbBasicCondition->layout()->setSpacing( 6 );
    gbBasicCondition->layout()->setMargin( 11 );
    gbBasicConditionLayout = new TQGridLayout( gbBasicCondition->layout() );
    gbBasicConditionLayout->setAlignment( TQt::AlignTop );

    layout376 = new TQHBoxLayout( 0, 0, 6, "layout376"); 

    layout372 = new TQVBoxLayout( 0, 0, 6, "layout372"); 

    lblASProvince = new TQLabel( gbBasicCondition, "lblASProvince" );
    layout372->addWidget( lblASProvince );

    lblASCity = new TQLabel( gbBasicCondition, "lblASCity" );
    layout372->addWidget( lblASCity );

    lblASAge = new TQLabel( gbBasicCondition, "lblASAge" );
    layout372->addWidget( lblASAge );

    lblASGender = new TQLabel( gbBasicCondition, "lblASGender" );
    layout372->addWidget( lblASGender );
    layout376->addLayout( layout372 );

    layout375 = new TQVBoxLayout( 0, 0, 6, "layout375"); 

    cbASProvince = new TQComboBox( FALSE, gbBasicCondition, "cbASProvince" );
    layout375->addWidget( cbASProvince );

    cbASCity = new TQComboBox( FALSE, gbBasicCondition, "cbASCity" );
    layout375->addWidget( cbASCity );

    cbASAge = new TQComboBox( FALSE, gbBasicCondition, "cbASAge" );
    layout375->addWidget( cbASAge );

    layout373 = new TQHBoxLayout( 0, 0, 6, "layout373"); 

    cbASSex = new TQComboBox( FALSE, gbBasicCondition, "cbASSex" );
    cbASSex->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)0, 0, 0, cbASSex->sizePolicy().hasHeightForWidth() ) );
    layout373->addWidget( cbASSex );
    spacer158 = new TQSpacerItem( 51, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout373->addItem( spacer158 );
    layout375->addLayout( layout373 );
    layout376->addLayout( layout375 );

    gbBasicConditionLayout->addLayout( layout376, 0, 0 );
    spacer159 = new TQSpacerItem( 101, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    gbBasicConditionLayout->addItem( spacer159, 0, 1 );
    layout91->addWidget( gbBasicCondition );
    spacer40_2 = new TQSpacerItem( 20, 41, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    layout91->addItem( spacer40_2 );

    wsASPageLayout->addLayout( layout91, 0, 0 );
    wsAdvancedSearch->addWidget( wsASPage, 0 );

    wsASResultPage = new TQWidget( wsAdvancedSearch, "wsASResultPage" );
    wsASResultPageLayout = new TQVBoxLayout( wsASResultPage, 11, 6, "wsASResultPageLayout"); 

    layout47_2 = new TQVBoxLayout( 0, 0, 6, "layout47_2"); 

    layout96_2 = new TQHBoxLayout( 0, 0, 6, "layout96_2"); 

    lblASResultTip = new TQLabel( wsASResultPage, "lblASResultTip" );
    layout96_2->addWidget( lblASResultTip );
    spacer48 = new TQSpacerItem( 71, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout96_2->addItem( spacer48 );
    layout47_2->addLayout( layout96_2 );

    tbASResult = new TQTable( wsASResultPage, "tbASResult" );
    tbASResult->setNumCols( tbASResult->numCols() + 1 );
    tbASResult->horizontalHeader()->setLabel( tbASResult->numCols() - 1, i18n( "Account" ) );
    tbASResult->setNumCols( tbASResult->numCols() + 1 );
    tbASResult->horizontalHeader()->setLabel( tbASResult->numCols() - 1, i18n( "Nick Name" ) );
    tbASResult->setNumCols( tbASResult->numCols() + 1 );
    tbASResult->horizontalHeader()->setLabel( tbASResult->numCols() - 1, i18n( "Gender" ) );
    tbASResult->setNumCols( tbASResult->numCols() + 1 );
    tbASResult->horizontalHeader()->setLabel( tbASResult->numCols() - 1, i18n( "Age" ) );
    tbASResult->setNumCols( tbASResult->numCols() + 1 );
    tbASResult->horizontalHeader()->setLabel( tbASResult->numCols() - 1, i18n( "Province" ) );
    tbASResult->setNumCols( tbASResult->numCols() + 1 );
    tbASResult->horizontalHeader()->setLabel( tbASResult->numCols() - 1, i18n( "City" ) );
    tbASResult->setNumCols( tbASResult->numCols() + 1 );
    tbASResult->horizontalHeader()->setLabel( tbASResult->numCols() - 1, i18n( "Status" ) );
    tbASResult->setFrameShape( TQTable::Box );
    tbASResult->setFrameShadow( TQTable::Plain );
    tbASResult->setLineWidth( 1 );
    tbASResult->setHScrollBarMode( TQTable::Auto );
    tbASResult->setNumRows( 0 );
    tbASResult->setNumCols( 7 );
    tbASResult->setShowGrid( TRUE );
    tbASResult->setReadOnly( TRUE );
    tbASResult->setSelectionMode( TQTable::SingleRow );
    tbASResult->setFocusStyle( TQTable::FollowStyle );
    layout47_2->addWidget( tbASResult );

    layout46_2_2 = new TQHBoxLayout( 0, 0, 6, "layout46_2_2"); 

    lblASResultPage = new TQLabel( wsASResultPage, "lblASResultPage" );
    layout46_2_2->addWidget( lblASResultPage );
    spacer50 = new TQSpacerItem( 59, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout46_2_2->addItem( spacer50 );

    tbASAll = new TQToolButton( wsASResultPage, "tbASAll" );
    tbASAll->setCursor( TQCursor( 13 ) );
    tbASAll->setAutoRaise( TRUE );
    layout46_2_2->addWidget( tbASAll );

    tbASDetails = new TQToolButton( wsASResultPage, "tbASDetails" );
    tbASDetails->setCursor( TQCursor( 13 ) );
    tbASDetails->setAutoRaise( TRUE );
    layout46_2_2->addWidget( tbASDetails );

    tbASPrev = new TQToolButton( wsASResultPage, "tbASPrev" );
    tbASPrev->setCursor( TQCursor( 13 ) );
    tbASPrev->setAutoRaise( TRUE );
    layout46_2_2->addWidget( tbASPrev );

    tbASNext = new TQToolButton( wsASResultPage, "tbASNext" );
    tbASNext->setCursor( TQCursor( 13 ) );
    tbASNext->setAutoRaise( TRUE );
    layout46_2_2->addWidget( tbASNext );
    layout47_2->addLayout( layout46_2_2 );
    wsASResultPageLayout->addLayout( layout47_2 );
    wsAdvancedSearch->addWidget( wsASResultPage, 1 );

    tabAdvancedSearchLayout->addWidget( wsAdvancedSearch, 0, 0 );
    twSearchMain->insertTab( tabAdvancedSearch, TQString::fromLatin1("") );

    tabQunSearch = new TQWidget( twSearchMain, "tabQunSearch" );
    tabQunSearchLayout = new TQGridLayout( tabQunSearch, 1, 1, 11, 6, "tabQunSearchLayout"); 

    wsQunSearch = new TQWidgetStack( tabQunSearch, "wsQunSearch" );

    wsTQSPage = new TQWidget( wsQunSearch, "wsTQSPage" );
    wsTQSPageLayout = new TQGridLayout( wsTQSPage, 1, 1, 11, 6, "wsTQSPageLayout"); 

    layout203 = new TQVBoxLayout( 0, 0, 6, "layout203"); 

    layout92 = new TQHBoxLayout( 0, 0, 0, "layout92"); 
    spacer173_2 = new TQSpacerItem( 40, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout92->addItem( spacer173_2 );

    layout400_2 = new TQVBoxLayout( 0, 0, 0, "layout400_2"); 

    lblTQSTip = new TQLabel( wsTQSPage, "lblTQSTip" );
    layout400_2->addWidget( lblTQSTip );

    layout399_2 = new TQHBoxLayout( 0, 0, 6, "layout399_2"); 

    bgTQSType = new TQButtonGroup( wsTQSPage, "bgTQSType" );
    bgTQSType->setFrameShape( TQButtonGroup::NoFrame );
    bgTQSType->setFrameShadow( TQButtonGroup::Plain );
    bgTQSType->setColumnLayout(0, TQt::Vertical );
    bgTQSType->layout()->setSpacing( 2 );
    bgTQSType->layout()->setMargin( 6 );
    bgTQSTypeLayout = new TQGridLayout( bgTQSType->layout() );
    bgTQSTypeLayout->setAlignment( TQt::AlignTop );

    rbSearchAlumni = new TQRadioButton( bgTQSType, "rbSearchAlumni" );

    bgTQSTypeLayout->addWidget( rbSearchAlumni, 0, 0 );

    rbAccuratelySearch = new TQRadioButton( bgTQSType, "rbAccuratelySearch" );

    bgTQSTypeLayout->addWidget( rbAccuratelySearch, 2, 0 );

    rbSearchByCategory = new TQRadioButton( bgTQSType, "rbSearchByCategory" );

    bgTQSTypeLayout->addWidget( rbSearchByCategory, 1, 0 );
    layout399_2->addWidget( bgTQSType );
    spacer172_2 = new TQSpacerItem( 81, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout399_2->addItem( spacer172_2 );
    layout400_2->addLayout( layout399_2 );
    layout92->addLayout( layout400_2 );
    spacer174_2 = new TQSpacerItem( 51, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout92->addItem( spacer174_2 );
    layout203->addLayout( layout92 );

    gbTQCondition = new TQGroupBox( wsTQSPage, "gbTQCondition" );
    gbTQCondition->setColumnLayout(0, TQt::Vertical );
    gbTQCondition->layout()->setSpacing( 0 );
    gbTQCondition->layout()->setMargin( 8 );
    gbTQConditionLayout = new TQGridLayout( gbTQCondition->layout() );
    gbTQConditionLayout->setAlignment( TQt::AlignTop );

    wsQunCondition = new TQWidgetStack( gbTQCondition, "wsQunCondition" );

    wsCategoryConditon = new TQWidget( wsQunCondition, "wsCategoryConditon" );
    wsCategoryConditonLayout = new TQGridLayout( wsCategoryConditon, 1, 1, 11, 6, "wsCategoryConditonLayout"); 

    layout402_2 = new TQVBoxLayout( 0, 0, 6, "layout402_2"); 

    layout388_2 = new TQHBoxLayout( 0, 0, 6, "layout388_2"); 

    lblCategory = new TQLabel( wsCategoryConditon, "lblCategory" );
    layout388_2->addWidget( lblCategory );

    cbCategory1 = new TQComboBox( FALSE, wsCategoryConditon, "cbCategory1" );
    cbCategory1->setMinimumSize( TQSize( 100, 0 ) );
    layout388_2->addWidget( cbCategory1 );
    layout402_2->addLayout( layout388_2 );

    layout394_2 = new TQHBoxLayout( 0, 0, 6, "layout394_2"); 
    spacer168_2 = new TQSpacerItem( 51, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout394_2->addItem( spacer168_2 );

    layout390_2 = new TQVBoxLayout( 0, 0, 6, "layout390_2"); 

    cbCategory2 = new TQComboBox( FALSE, wsCategoryConditon, "cbCategory2" );
    cbCategory2->setMinimumSize( TQSize( 100, 0 ) );
    layout390_2->addWidget( cbCategory2 );

    cbCategory3 = new TQComboBox( FALSE, wsCategoryConditon, "cbCategory3" );
    layout390_2->addWidget( cbCategory3 );
    layout394_2->addLayout( layout390_2 );
    layout402_2->addLayout( layout394_2 );

    wsCategoryConditonLayout->addLayout( layout402_2, 0, 1 );
    spacer148 = new TQSpacerItem( 50, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    wsCategoryConditonLayout->addItem( spacer148, 0, 0 );
    spacer149 = new TQSpacerItem( 71, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    wsCategoryConditonLayout->addItem( spacer149, 0, 2 );
    wsQunCondition->addWidget( wsCategoryConditon, 0 );

    wsAlumniCondition = new TQWidget( wsQunCondition, "wsAlumniCondition" );
    wsAlumniConditionLayout = new TQGridLayout( wsAlumniCondition, 1, 1, 11, 6, "wsAlumniConditionLayout"); 

    lblAlumniTip = new TQLabel( wsAlumniCondition, "lblAlumniTip" );
    lblAlumniTip->setAlignment( int( TQLabel::WordBreak | TQLabel::AlignCenter ) );

    wsAlumniConditionLayout->addWidget( lblAlumniTip, 0, 0 );
    wsQunCondition->addWidget( wsAlumniCondition, 1 );

    wsAccurateCondition = new TQWidget( wsQunCondition, "wsAccurateCondition" );
    wsAccurateConditionLayout = new TQGridLayout( wsAccurateCondition, 1, 1, 11, 6, "wsAccurateConditionLayout"); 

    layout306 = new TQHBoxLayout( 0, 0, 6, "layout306"); 

    lblQunNum = new TQLabel( wsAccurateCondition, "lblQunNum" );
    layout306->addWidget( lblQunNum );

    leQunNum = new TQLineEdit( wsAccurateCondition, "leQunNum" );
    leQunNum->setFrameShape( TQLineEdit::Box );
    leQunNum->setFrameShadow( TQLineEdit::Plain );
    leQunNum->setLineWidth( 1 );
    layout306->addWidget( leQunNum );

    wsAccurateConditionLayout->addLayout( layout306, 0, 0 );
    spacer151 = new TQSpacerItem( 111, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    wsAccurateConditionLayout->addItem( spacer151, 0, 1 );
    spacer152 = new TQSpacerItem( 20, 21, TQSizePolicy::Minimum, TQSizePolicy::Expanding );
    wsAccurateConditionLayout->addItem( spacer152, 1, 0 );
    wsQunCondition->addWidget( wsAccurateCondition, 2 );

    gbTQConditionLayout->addWidget( wsQunCondition, 0, 0 );
    layout203->addWidget( gbTQCondition );

    wsTQSPageLayout->addLayout( layout203, 0, 0 );
    wsQunSearch->addWidget( wsTQSPage, 0 );

    wsTQSResultPage = new TQWidget( wsQunSearch, "wsTQSResultPage" );
    wsTQSResultPageLayout = new TQGridLayout( wsTQSResultPage, 1, 1, 11, 6, "wsTQSResultPageLayout"); 

    layout49 = new TQVBoxLayout( 0, 0, 6, "layout49"); 

    layout96_3 = new TQHBoxLayout( 0, 0, 6, "layout96_3"); 

    lblTQSResultTip = new TQLabel( wsTQSResultPage, "lblTQSResultTip" );
    layout96_3->addWidget( lblTQSResultTip );
    spacer46_2 = new TQSpacerItem( 71, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout96_3->addItem( spacer46_2 );
    layout49->addLayout( layout96_3 );

    tbTQSResult = new TQTable( wsTQSResultPage, "tbTQSResult" );
    tbTQSResult->setNumCols( tbTQSResult->numCols() + 1 );
    tbTQSResult->horizontalHeader()->setLabel( tbTQSResult->numCols() - 1, i18n( "Qun Num" ) );
    tbTQSResult->setNumCols( tbTQSResult->numCols() + 1 );
    tbTQSResult->horizontalHeader()->setLabel( tbTQSResult->numCols() - 1, i18n( "Qun Name" ) );
    tbTQSResult->setNumCols( tbTQSResult->numCols() + 1 );
    tbTQSResult->horizontalHeader()->setLabel( tbTQSResult->numCols() - 1, i18n( "Creator" ) );
    tbTQSResult->setFrameShape( TQTable::Box );
    tbTQSResult->setFrameShadow( TQTable::Plain );
    tbTQSResult->setLineWidth( 1 );
    tbTQSResult->setHScrollBarMode( TQTable::Auto );
    tbTQSResult->setNumRows( 0 );
    tbTQSResult->setNumCols( 3 );
    tbTQSResult->setShowGrid( TRUE );
    tbTQSResult->setReadOnly( TRUE );
    tbTQSResult->setSelectionMode( TQTable::SingleRow );
    tbTQSResult->setFocusStyle( TQTable::FollowStyle );
    layout49->addWidget( tbTQSResult );

    layout46_3 = new TQHBoxLayout( 0, 0, 6, "layout46_3"); 

    lblTQSResultPage = new TQLabel( wsTQSResultPage, "lblTQSResultPage" );
    layout46_3->addWidget( lblTQSResultPage );
    spacer51 = new TQSpacerItem( 59, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout46_3->addItem( spacer51 );

    tbTQSAll = new TQToolButton( wsTQSResultPage, "tbTQSAll" );
    tbTQSAll->setCursor( TQCursor( 13 ) );
    tbTQSAll->setAutoRaise( TRUE );
    layout46_3->addWidget( tbTQSAll );

    tbTQSDetails = new TQToolButton( wsTQSResultPage, "tbTQSDetails" );
    tbTQSDetails->setCursor( TQCursor( 13 ) );
    tbTQSDetails->setAutoRaise( TRUE );
    layout46_3->addWidget( tbTQSDetails );

    tbTQSPrev = new TQToolButton( wsTQSResultPage, "tbTQSPrev" );
    tbTQSPrev->setCursor( TQCursor( 13 ) );
    tbTQSPrev->setAutoRaise( TRUE );
    layout46_3->addWidget( tbTQSPrev );

    tbTQSNext = new TQToolButton( wsTQSResultPage, "tbTQSNext" );
    tbTQSNext->setCursor( TQCursor( 13 ) );
    tbTQSNext->setAutoRaise( TRUE );
    layout46_3->addWidget( tbTQSNext );
    layout49->addLayout( layout46_3 );

    wsTQSResultPageLayout->addLayout( layout49, 0, 0 );
    wsQunSearch->addWidget( wsTQSResultPage, 1 );

    tabQunSearchLayout->addWidget( wsQunSearch, 0, 0 );
    twSearchMain->insertTab( tabQunSearch, TQString::fromLatin1("") );

    layout127->addWidget( twSearchMain, 0, 1 );

    layout195 = new TQHBoxLayout( 0, 0, 6, "layout195"); 
    spacer38 = new TQSpacerItem( 140, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout195->addItem( spacer38 );

    pbLastStep = new TQPushButton( this, "pbLastStep" );
    layout195->addWidget( pbLastStep );

    pbSearch = new TQPushButton( this, "pbSearch" );
    layout195->addWidget( pbSearch );

    pbClose = new TQPushButton( this, "pbClose" );
    layout195->addWidget( pbClose );
    spacer40 = new TQSpacerItem( 21, 20, TQSizePolicy::Fixed, TQSizePolicy::Minimum );
    layout195->addItem( spacer40 );

    layout127->addMultiCellLayout( layout195, 1, 1, 0, 1 );

    lblLogo = new TQLabel( this, "lblLogo" );
    lblLogo->setMinimumSize( TQSize( 120, 300 ) );
    lblLogo->setMaximumSize( TQSize( 120, 300 ) );

    layout127->addWidget( lblLogo, 0, 0 );

    EvaSearchUIBaseLayout->addLayout( layout127, 0, 0 );
    languageChange();
    resize( TQSize(535, 360).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

/*
 *  Destroys the object and frees any allocated resources
 */
EvaSearchUIBase::~EvaSearchUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaSearchUIBase::languageChange()
{
    setCaption( i18n( "Search - Eva" ) );
    lblSearchOptionTip->setText( i18n( "Please select one of the following options:" ) );
    bgBSType->setTitle( TQString::null );
    rbCustomSearch->setText( i18n( "accurate search" ) );
    rbSearchFrdCenter->setText( i18n( "search in QQ friend center" ) );
    rbSearchOnline->setText( i18n( "search online users" ) );
    gbCustomCondition->setTitle( i18n( "accurate conditions" ) );
    lblTQQNum->setText( i18n( "QQ Num:" ) );
    lblNickName->setText( i18n( "Nick Name:" ) );
    //lblEmail->setText( i18n( "--Email:" ) );
    gbFrdCenterCondition->setTitle( i18n( "accurate conditions" ) );
    lblTQQFrdTip->setText( i18n( "click the search button to go to the QQ friend homepage for Searching" ) );
    lblOnlineNumbers->setText( i18n( "number of online users :" ) );
    lblOnlineNum->setText( i18n( "unknown" ) );
    lblBSResultTip->setText( i18n( "the following users is found for you by Eva." ) );
    tbBSResult->horizontalHeader()->setLabel( 0, i18n( "QQ Num" ) );
    tbBSResult->horizontalHeader()->setLabel( 1, i18n( "Nick Name" ) );
    tbBSResult->horizontalHeader()->setLabel( 2, i18n( "From" ) );
    lblBSResultPage->setText( TQString::null );
    tbBSAll->setText( i18n( "All pages" ) );
    tbBSDetails->setText( i18n( "Details" ) );
    tbBSPrev->setText( i18n( "Prev" ) );
    tbBSNext->setText( i18n( "Next" ) );
    twSearchMain->changeTab( tabBasicSearch, i18n( "&Basic Search" ) );
    lblASTip->setText( i18n( "you may set one condition or more to search friend here" ) );
    chbOnlineUsers->setText( i18n( "online users" ) );
    chbHaveCamera->setText( i18n( "has camera" ) );
    gbBasicCondition->setTitle( i18n( "basic conditions" ) );
    lblASProvince->setText( i18n( "Province" ) );
    lblASCity->setText( i18n( "City" ) );
    lblASAge->setText( i18n( "Age" ) );
    lblASGender->setText( i18n( "Gender" ) );
    cbASAge->clear();
    cbASAge->insertItem( i18n( "any" ) );
    cbASAge->insertItem( i18n( "0-15" ) );
    cbASAge->insertItem( i18n( "16-22" ) );
    cbASAge->insertItem( i18n( "23-30" ) );
    cbASAge->insertItem( i18n( "31-40" ) );
    cbASAge->insertItem( i18n( "above 40" ) );
    cbASSex->clear();
    cbASSex->insertItem( i18n( "any" ) );
    cbASSex->insertItem( i18n( "male" ) );
    cbASSex->insertItem( i18n( "female" ) );
    lblASResultTip->setText( i18n( "the following users is found for you by Eva." ) );
    tbASResult->horizontalHeader()->setLabel( 0, i18n( "QQ Num" ) );
    tbASResult->horizontalHeader()->setLabel( 1, i18n( "Nick Name" ) );
    tbASResult->horizontalHeader()->setLabel( 2, i18n( "Gender" ) );
    tbASResult->horizontalHeader()->setLabel( 3, i18n( "Age" ) );
    tbASResult->horizontalHeader()->setLabel( 4, i18n( "Province" ) );
    tbASResult->horizontalHeader()->setLabel( 5, i18n( "City" ) );
    tbASResult->horizontalHeader()->setLabel( 6, i18n( "Status" ) );
    lblASResultPage->setText( TQString::null );
    tbASAll->setText( i18n( "All pages" ) );
    tbASDetails->setText( i18n( "Details" ) );
    tbASPrev->setText( i18n( "Prev" ) );
    tbASNext->setText( i18n( "Next" ) );
    twSearchMain->changeTab( tabAdvancedSearch, i18n( "&Advanced Search" ) );
    lblTQSTip->setText( i18n( "Please select one of the following Qun options:" ) );
    bgTQSType->setTitle( TQString::null );
    rbSearchAlumni->setText( i18n( "search alumni" ) );
    rbAccuratelySearch->setText( i18n( "accurate search" ) );
    rbSearchByCategory->setText( i18n( "search by category" ) );
    gbTQCondition->setTitle( i18n( "search conditions" ) );
    lblCategory->setText( i18n( "category" ) );
    lblAlumniTip->setText( i18n( "click the search button to go to the Alumni homepage for Searching" ) );
    lblQunNum->setText( i18n( "Qun Num" ) );
    lblTQSResultTip->setText( TQString::null );
    tbTQSResult->horizontalHeader()->setLabel( 0, i18n( "Qun Num" ) );
    tbTQSResult->horizontalHeader()->setLabel( 1, i18n( "Qun Name" ) );
    tbTQSResult->horizontalHeader()->setLabel( 2, i18n( "Creator" ) );
    lblTQSResultPage->setText( TQString::null );
    tbTQSAll->setText( i18n( "All pages" ) );
    tbTQSDetails->setText( i18n( "Details" ) );
    tbTQSPrev->setText( i18n( "Prev" ) );
    tbTQSNext->setText( i18n( "Next" ) );
    twSearchMain->changeTab( tabQunSearch, i18n( "&Qun Search" ) );
    pbLastStep->setText( i18n( "Last Step" ) );
    pbSearch->setText( i18n( "Sea&rch" ) );
    pbClose->setText( i18n( "&Close" ) );
    lblLogo->setText( TQString::null );
}

