/****************************************************************************
** EvaMainWindow meta object code from reading C++ file 'evamainwindow.h'
**
** Created: Tue Feb 8 23:51:23 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evamainwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaMainWindow::className() const
{
    return "EvaMainWindow";
}

QMetaObject *EvaMainWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaMainWindow( "EvaMainWindow", &EvaMainWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaMainWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaMainWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaMainWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaMainWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaMainWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaMainUIBase::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_0 = {"changeToOnline", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_1 = {"changeToOffline", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_2 = {"changeToLeave", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_3 = {"changeToInvisible", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_4 = {"newMessage", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_5 = {"gotMessage", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_6 = {"newQunMessage", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_7 = {"gotQunMessage", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_8 = {"addBuddyToRecentList", 1, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isMyWord", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"addBuddyToRecentList", 2, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_10 = {"addQunToRecentList", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isMyWord", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"addQunToRecentList", 2, param_slot_11 };
    static const QUMethod slot_12 = {"slotFaceSizeChanged", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_13 = {"deleteBuddy", 1, param_slot_13 };
    static const QUMethod slot_14 = {"online", 0, 0 };
    static const QUMethod slot_15 = {"offline", 0, 0 };
    static const QUMethod slot_16 = {"leave", 0, 0 };
    static const QUMethod slot_17 = {"invisible", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"removeTab", 2, param_slot_18 };
    static const QUMethod slot_19 = {"slotUpdateBuddyStat", 0, 0 };
    static const QUMethod slot_20 = {"slotTbMyFace", 0, 0 };
    static const QUMethod slot_21 = {"slotSearch", 0, 0 };
    static const QUMethod slot_22 = {"slotSystemMessages", 0, 0 };
    static const QUMethod slot_23 = {"slotSystemClicked", 0, 0 };
    static const QUMethod slot_24 = {"slotStatusClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "changeToOnline(unsigned int)", &slot_0, QMetaData::Public },
	{ "changeToOffline(unsigned int)", &slot_1, QMetaData::Public },
	{ "changeToLeave(unsigned int)", &slot_2, QMetaData::Public },
	{ "changeToInvisible(unsigned int)", &slot_3, QMetaData::Public },
	{ "newMessage(unsigned int)", &slot_4, QMetaData::Public },
	{ "gotMessage(unsigned int)", &slot_5, QMetaData::Public },
	{ "newQunMessage(unsigned int)", &slot_6, QMetaData::Public },
	{ "gotQunMessage(unsigned int)", &slot_7, QMetaData::Public },
	{ "addBuddyToRecentList(const unsigned int)", &slot_8, QMetaData::Public },
	{ "addBuddyToRecentList(const unsigned int,bool)", &slot_9, QMetaData::Public },
	{ "addQunToRecentList(const unsigned int)", &slot_10, QMetaData::Public },
	{ "addQunToRecentList(const unsigned int,bool)", &slot_11, QMetaData::Public },
	{ "slotFaceSizeChanged()", &slot_12, QMetaData::Public },
	{ "deleteBuddy(unsigned int)", &slot_13, QMetaData::Public },
	{ "online()", &slot_14, QMetaData::Public },
	{ "offline()", &slot_15, QMetaData::Public },
	{ "leave()", &slot_16, QMetaData::Public },
	{ "invisible()", &slot_17, QMetaData::Public },
	{ "removeTab(int)", &slot_18, QMetaData::Public },
	{ "slotUpdateBuddyStat()", &slot_19, QMetaData::Private },
	{ "slotTbMyFace()", &slot_20, QMetaData::Private },
	{ "slotSearch()", &slot_21, QMetaData::Private },
	{ "slotSystemMessages()", &slot_22, QMetaData::Private },
	{ "slotSystemClicked()", &slot_23, QMetaData::Private },
	{ "slotStatusClicked()", &slot_24, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"groupDeleted", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"groupRenamed", 2, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"deleteMeFrom", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"groupChanged", 2, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_4 = {"requestChat", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_5 = {"requestSendFile", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_6 = {"requestLevel", 1, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_7 = {"requestDetails", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_8 = {"requestModifyMemo", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_9 = {"requestHistory", 1, param_signal_9 };
    static const QUParameter param_signal_10[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_10 = {"requestDelete", 1, param_signal_10 };
    static const QUMethod signal_11 = {"requestSearch", 0, 0 };
    static const QUMethod signal_12 = {"requestSystemMessages", 0, 0 };
    static const QUParameter param_signal_13[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_13 = {"requestQunChat", 1, param_signal_13 };
    static const QUParameter param_signal_14[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_14 = {"requestQunDetails", 1, param_signal_14 };
    static const QUParameter param_signal_15[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_15 = {"requestQunExit", 1, param_signal_15 };
    static const QUMethod signal_16 = {"requestQunCreate", 0, 0 };
    static const QUParameter param_signal_17[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_17 = {"requestQunHistory", 1, param_signal_17 };
    static const QMetaData signal_tbl[] = {
	{ "groupDeleted(const int)", &signal_0, QMetaData::Public },
	{ "groupRenamed(QString,int)", &signal_1, QMetaData::Public },
	{ "deleteMeFrom(const unsigned int)", &signal_2, QMetaData::Public },
	{ "groupChanged(const unsigned int,int)", &signal_3, QMetaData::Public },
	{ "requestChat(const unsigned int)", &signal_4, QMetaData::Public },
	{ "requestSendFile(const unsigned int)", &signal_5, QMetaData::Public },
	{ "requestLevel(const unsigned int)", &signal_6, QMetaData::Public },
	{ "requestDetails(const unsigned int)", &signal_7, QMetaData::Public },
	{ "requestModifyMemo(const unsigned int)", &signal_8, QMetaData::Public },
	{ "requestHistory(const unsigned int)", &signal_9, QMetaData::Public },
	{ "requestDelete(const unsigned int)", &signal_10, QMetaData::Public },
	{ "requestSearch()", &signal_11, QMetaData::Public },
	{ "requestSystemMessages()", &signal_12, QMetaData::Public },
	{ "requestQunChat(const unsigned int)", &signal_13, QMetaData::Public },
	{ "requestQunDetails(const unsigned int)", &signal_14, QMetaData::Public },
	{ "requestQunExit(const unsigned int)", &signal_15, QMetaData::Public },
	{ "requestQunCreate()", &signal_16, QMetaData::Public },
	{ "requestQunHistory(const unsigned int)", &signal_17, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaMainWindow", parentObject,
	slot_tbl, 25,
	signal_tbl, 18,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaMainWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaMainWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaMainWindow" ) )
	return this;
    if ( !qstrcmp( clname, "EvaDCOPViewInterface" ) )
	return (EvaDCOPViewInterface*)this;
    return EvaMainUIBase::qt_cast( clname );
}

// SIGNAL groupDeleted
void EvaMainWindow::groupDeleted( const int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL groupRenamed
void EvaMainWindow::groupRenamed( QString t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL deleteMeFrom
void EvaMainWindow::deleteMeFrom( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL groupChanged
void EvaMainWindow::groupChanged( const unsigned int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL requestChat
void EvaMainWindow::requestChat( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestSendFile
void EvaMainWindow::requestSendFile( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestLevel
void EvaMainWindow::requestLevel( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestDetails
void EvaMainWindow::requestDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestModifyMemo
void EvaMainWindow::requestModifyMemo( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestHistory
void EvaMainWindow::requestHistory( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestDelete
void EvaMainWindow::requestDelete( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 10 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestSearch
void EvaMainWindow::requestSearch()
{
    activate_signal( staticMetaObject()->signalOffset() + 11 );
}

// SIGNAL requestSystemMessages
void EvaMainWindow::requestSystemMessages()
{
    activate_signal( staticMetaObject()->signalOffset() + 12 );
}

// SIGNAL requestQunChat
void EvaMainWindow::requestQunChat( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 13 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunDetails
void EvaMainWindow::requestQunDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 14 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunExit
void EvaMainWindow::requestQunExit( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 15 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunCreate
void EvaMainWindow::requestQunCreate()
{
    activate_signal( staticMetaObject()->signalOffset() + 16 );
}

// SIGNAL requestQunHistory
void EvaMainWindow::requestQunHistory( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 17 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaMainWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: changeToOnline((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: changeToOffline((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: changeToLeave((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: changeToInvisible((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 4: newMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 5: gotMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 6: newQunMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 7: gotQunMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 8: addBuddyToRecentList((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 9: addBuddyToRecentList((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 10: addQunToRecentList((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 11: addQunToRecentList((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 12: slotFaceSizeChanged(); break;
    case 13: deleteBuddy((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 14: online(); break;
    case 15: offline(); break;
    case 16: leave(); break;
    case 17: invisible(); break;
    case 18: static_QUType_bool.set(_o,removeTab((int)static_QUType_int.get(_o+1))); break;
    case 19: slotUpdateBuddyStat(); break;
    case 20: slotTbMyFace(); break;
    case 21: slotSearch(); break;
    case 22: slotSystemMessages(); break;
    case 23: slotSystemClicked(); break;
    case 24: slotStatusClicked(); break;
    default:
	return EvaMainUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaMainWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: groupDeleted((const int)static_QUType_int.get(_o+1)); break;
    case 1: groupRenamed((QString)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 2: deleteMeFrom((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: groupChanged((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(int)static_QUType_int.get(_o+2)); break;
    case 4: requestChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 5: requestSendFile((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 6: requestLevel((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 7: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 8: requestModifyMemo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 9: requestHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 10: requestDelete((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 11: requestSearch(); break;
    case 12: requestSystemMessages(); break;
    case 13: requestQunChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 14: requestQunDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 15: requestQunExit((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 16: requestQunCreate(); break;
    case 17: requestQunHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaMainUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaMainWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaMainUIBase::qt_property( id, f, v);
}

bool EvaMainWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
