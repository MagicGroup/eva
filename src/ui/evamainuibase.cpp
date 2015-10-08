 
#include "evamainuibase.h"

//#include <ntqvariant.h>
#include <ntqpushbutton.h>
#include <ntqtoolbutton.h>
#include <ntqlabel.h>
#include <ntqheader.h>
#include <ntqlayout.h>
#include <ntqtooltip.h>
#include <ntqwhatsthis.h>
#include <ntqimage.h>
#include <ntqpixmap.h>
#include <tdelocale.h>
#include "evadisplaywidget.h"
#include "evastatusbar.h"
//#include "evalistview.h"

EvaMainUIBase::EvaMainUIBase( TQWidget* parent, const char* name, WFlags fl )
    : TQWidget( parent, name, fl )
{
    if ( !name )
	setName( "EvaMainUIBase" );
    EvaMainUIBaseLayout = new TQGridLayout( this, 1, 1, 0, 0, "EvaMainUIBaseLayout"); 

    layout1 = new TQVBoxLayout( 0, 0, 0, "layout1"); 

    layout2 = new TQHBoxLayout( 0, 0, 0, "layout2"); 

    tbMyFace = new TQToolButton( this, "tbMyFace" );
    tbMyFace->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0, tbMyFace->sizePolicy().hasHeightForWidth() ) );
    tbMyFace->setMinimumSize( TQSize( 40, 39 ) );
    tbMyFace->setAutoRaise( TRUE );
    layout2->addWidget( tbMyFace );

    tlNick = new TQLabel( this, "tlNick" );
    layout2->addWidget( tlNick );

    tlQQ = new TQLabel( this, "tlQQ" );
    layout2->addWidget( tlQQ );
    spacer1 = new TQSpacerItem( 50, 20, TQSizePolicy::Expanding, TQSizePolicy::Minimum );
    layout2->addItem( spacer1 );
    layout1->addLayout( layout2 );

    mainDisplay = new EvaDisplayWidget(this, "mainDisplay");
    mainDisplay->showInfoFrame();
    mainDisplay->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)7, (TQSizePolicy::SizeType)5, 0, 0, mainDisplay->sizePolicy().hasHeightForWidth() ) );
    layout1->addWidget( mainDisplay );

    statusBar = new EvaStatusBar(this, "status bar");
    layout1->addWidget(statusBar);
    
//    layout3 = new TQVBoxLayout( 0, 0, 0, "layout3"); 

//     pbSearch = new TQPushButton( this, "pbSearch" );
//     layout3->addWidget( pbSearch );
// 
//     pbMessages = new TQPushButton( this, "pbMessages" );
//     layout3->addWidget( pbMessages );
//     layout1->addLayout( layout3 );

//     layout4 = new TQHBoxLayout( 0, 0, 6, "layout4"); 
// 
//     pbSystem = new TQPushButton( this, "pbSystem" );
//     pbSystem->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)0, 0, 0, pbSystem->sizePolicy().hasHeightForWidth() ) );
//     layout4->addWidget( pbSystem );
// 
//     pbStatus = new TQPushButton( this, "pbStatus" );
//     pbStatus->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)5, (TQSizePolicy::SizeType)0, 0, 0, pbStatus->sizePolicy().hasHeightForWidth() ) );
//     layout4->addWidget( pbStatus );
//     layout1->addLayout( layout4 );

    EvaMainUIBaseLayout->addLayout( layout1, 0, 0 );
    languageChange();
    resize( TQSize(195, 376).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );
}

EvaMainUIBase::~EvaMainUIBase()
{
    // no need to delete child widgets, TQt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void EvaMainUIBase::languageChange()
{
    setCaption( i18n( "Eva" ) );
    tbMyFace->setText( "..." );
    tlNick->setText( i18n( "Nick" ) );
    tlQQ->setText( i18n( "QQ" ) );
    //listView->header()->setLabel( 0, i18n( "Column 1" ) );
    //listView->clear();
    //TQListViewItem * item = new TQListViewItem( listView, 0 );
    //item->setText( 0, i18n( "New Item" ) );

    //pbSearch->setText( i18n( "Search" ) );
    //pbMessages->setText( i18n( "Messages" ) );
    //pbSystem->setText( i18n( "System" ) );
    //pbStatus->setText( i18n( "Online" ) );
}
