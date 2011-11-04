/****************************************************************************
** EvaNotifyWindow meta object code from reading C++ file 'evanotifywindow.h'
**
** Created: Tue Feb 8 23:52:04 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evanotifywindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaNotifyWindow::className() const
{
    return "EvaNotifyWindow";
}

QMetaObject *EvaNotifyWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaNotifyWindow( "EvaNotifyWindow", &EvaNotifyWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaNotifyWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaNotifyWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaNotifyWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaNotifyWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaNotifyWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaNotifyUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotAddBuddyReady", 0, 0 };
    static const QUMethod slot_1 = {"slotAddBuddyRejected", 0, 0 };
    static const QUMethod slot_2 = {"slotBuddyNeedAuth", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "ok", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotAddBuddySentToServer", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"slotMeBeenAdded", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"slotAddMeRequest", 2, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"slotAddRequestApproved", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"slotAddRequestRejected", 2, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"slotOtherNotification", 2, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"slotAddBuddy", 1, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "internalQunID", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"slotQunJoinAuthReply", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "from", &static_QUType_int, 0, QUParameter::In },
	{ "extQunID", &static_QUType_int, 0, QUParameter::In },
	{ "internalQunID", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"slotQunCreated", 3, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "from", &static_QUType_int, 0, QUParameter::In },
	{ "extQunID", &static_QUType_int, 0, QUParameter::In },
	{ "internalQunID", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"slotQunAdded", 3, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "from", &static_QUType_int, 0, QUParameter::In },
	{ "extQunID", &static_QUType_int, 0, QUParameter::In },
	{ "internalQunID", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"slotQunRemoved", 3, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "from", &static_QUType_int, 0, QUParameter::In },
	{ "extQunID", &static_QUType_int, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "internalQunID", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"slotQunJoinRequest", 4, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "from", &static_QUType_int, 0, QUParameter::In },
	{ "extQunID", &static_QUType_int, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "internalQunID", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"slotQunRequestApproved", 4, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "from", &static_QUType_int, 0, QUParameter::In },
	{ "extQunID", &static_QUType_int, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "internalQunID", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"slotQunRequestRejected", 4, param_slot_16 };
    static const QUMethod slot_17 = {"slotPbAddClicked", 0, 0 };
    static const QUMethod slot_18 = {"slotPbRejectClicked", 0, 0 };
    static const QUMethod slot_19 = {"slotPbApproveClicked", 0, 0 };
    static const QUMethod slot_20 = {"slotTbDetailsClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotAddBuddyReady()", &slot_0, QMetaData::Public },
	{ "slotAddBuddyRejected()", &slot_1, QMetaData::Public },
	{ "slotBuddyNeedAuth()", &slot_2, QMetaData::Public },
	{ "slotAddBuddySentToServer(bool)", &slot_3, QMetaData::Public },
	{ "slotMeBeenAdded(int)", &slot_4, QMetaData::Public },
	{ "slotAddMeRequest(int,QString)", &slot_5, QMetaData::Public },
	{ "slotAddRequestApproved(int)", &slot_6, QMetaData::Public },
	{ "slotAddRequestRejected(int,QString)", &slot_7, QMetaData::Public },
	{ "slotOtherNotification(int,QString)", &slot_8, QMetaData::Public },
	{ "slotAddBuddy(int)", &slot_9, QMetaData::Public },
	{ "slotQunJoinAuthReply(const int)", &slot_10, QMetaData::Public },
	{ "slotQunCreated(const int,const int,const int)", &slot_11, QMetaData::Public },
	{ "slotQunAdded(const int,const int,const int)", &slot_12, QMetaData::Public },
	{ "slotQunRemoved(const int,const int,const int)", &slot_13, QMetaData::Public },
	{ "slotQunJoinRequest(const int,const int,QString,const int)", &slot_14, QMetaData::Public },
	{ "slotQunRequestApproved(const int,const int,QString,const int)", &slot_15, QMetaData::Public },
	{ "slotQunRequestRejected(const int,const int,QString,const int)", &slot_16, QMetaData::Public },
	{ "slotPbAddClicked()", &slot_17, QMetaData::Private },
	{ "slotPbRejectClicked()", &slot_18, QMetaData::Private },
	{ "slotPbApproveClicked()", &slot_19, QMetaData::Private },
	{ "slotTbDetailsClicked()", &slot_20, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestUserInfo", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestAddAuthBuddy", 2, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestAddBuddy", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"requestApproveBuddy", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"requestRejectBuddy", 2, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_5 = {"requestQunInfo", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_6 = {"requestApproveQun", 2, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_7 = {"requestRejectQun", 3, param_signal_7 };
    static const QMetaData signal_tbl[] = {
	{ "requestUserInfo(const int)", &signal_0, QMetaData::Public },
	{ "requestAddAuthBuddy(const int,const QString&)", &signal_1, QMetaData::Public },
	{ "requestAddBuddy(const int)", &signal_2, QMetaData::Public },
	{ "requestApproveBuddy(const int)", &signal_3, QMetaData::Public },
	{ "requestRejectBuddy(const int,const QString&)", &signal_4, QMetaData::Public },
	{ "requestQunInfo(const int)", &signal_5, QMetaData::Public },
	{ "requestApproveQun(const int,const int)", &signal_6, QMetaData::Public },
	{ "requestRejectQun(const int,const int,const QString&)", &signal_7, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaNotifyWindow", parentObject,
	slot_tbl, 21,
	signal_tbl, 8,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaNotifyWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaNotifyWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaNotifyWindow" ) )
	return this;
    return EvaNotifyUIBase::qt_cast( clname );
}

// SIGNAL requestUserInfo
void EvaNotifyWindow::requestUserInfo( const int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestAddAuthBuddy
void EvaNotifyWindow::requestAddAuthBuddy( const int t0, const QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL requestAddBuddy
void EvaNotifyWindow::requestAddBuddy( const int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL requestApproveBuddy
void EvaNotifyWindow::requestApproveBuddy( const int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 3, t0 );
}

// SIGNAL requestRejectBuddy
void EvaNotifyWindow::requestRejectBuddy( const int t0, const QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL requestQunInfo
void EvaNotifyWindow::requestQunInfo( const int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 5, t0 );
}

// SIGNAL requestApproveQun
void EvaNotifyWindow::requestApproveQun( const int t0, const int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL requestRejectQun
void EvaNotifyWindow::requestRejectQun( const int t0, const int t1, const QString& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

bool EvaNotifyWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotAddBuddyReady(); break;
    case 1: slotAddBuddyRejected(); break;
    case 2: slotBuddyNeedAuth(); break;
    case 3: slotAddBuddySentToServer((bool)static_QUType_bool.get(_o+1)); break;
    case 4: slotMeBeenAdded((int)static_QUType_int.get(_o+1)); break;
    case 5: slotAddMeRequest((int)static_QUType_int.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 6: slotAddRequestApproved((int)static_QUType_int.get(_o+1)); break;
    case 7: slotAddRequestRejected((int)static_QUType_int.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 8: slotOtherNotification((int)static_QUType_int.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 9: slotAddBuddy((int)static_QUType_int.get(_o+1)); break;
    case 10: slotQunJoinAuthReply((const int)static_QUType_int.get(_o+1)); break;
    case 11: slotQunCreated((const int)static_QUType_int.get(_o+1),(const int)static_QUType_int.get(_o+2),(const int)static_QUType_int.get(_o+3)); break;
    case 12: slotQunAdded((const int)static_QUType_int.get(_o+1),(const int)static_QUType_int.get(_o+2),(const int)static_QUType_int.get(_o+3)); break;
    case 13: slotQunRemoved((const int)static_QUType_int.get(_o+1),(const int)static_QUType_int.get(_o+2),(const int)static_QUType_int.get(_o+3)); break;
    case 14: slotQunJoinRequest((const int)static_QUType_int.get(_o+1),(const int)static_QUType_int.get(_o+2),(QString)static_QUType_QString.get(_o+3),(const int)static_QUType_int.get(_o+4)); break;
    case 15: slotQunRequestApproved((const int)static_QUType_int.get(_o+1),(const int)static_QUType_int.get(_o+2),(QString)static_QUType_QString.get(_o+3),(const int)static_QUType_int.get(_o+4)); break;
    case 16: slotQunRequestRejected((const int)static_QUType_int.get(_o+1),(const int)static_QUType_int.get(_o+2),(QString)static_QUType_QString.get(_o+3),(const int)static_QUType_int.get(_o+4)); break;
    case 17: slotPbAddClicked(); break;
    case 18: slotPbRejectClicked(); break;
    case 19: slotPbApproveClicked(); break;
    case 20: slotTbDetailsClicked(); break;
    default:
	return EvaNotifyUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaNotifyWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestUserInfo((const int)static_QUType_int.get(_o+1)); break;
    case 1: requestAddAuthBuddy((const int)static_QUType_int.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 2: requestAddBuddy((const int)static_QUType_int.get(_o+1)); break;
    case 3: requestApproveBuddy((const int)static_QUType_int.get(_o+1)); break;
    case 4: requestRejectBuddy((const int)static_QUType_int.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 5: requestQunInfo((const int)static_QUType_int.get(_o+1)); break;
    case 6: requestApproveQun((const int)static_QUType_int.get(_o+1),(const int)static_QUType_int.get(_o+2)); break;
    case 7: requestRejectQun((const int)static_QUType_int.get(_o+1),(const int)static_QUType_int.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    default:
	return EvaNotifyUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaNotifyWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaNotifyUIBase::qt_property( id, f, v);
}

bool EvaNotifyWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
