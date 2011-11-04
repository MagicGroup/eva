/****************************************************************************
** EvaAddingManager meta object code from reading C++ file 'evaaddingmanager.h'
**
** Created: Tue Feb 8 23:56:30 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaaddingmanager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaAddingManager::className() const
{
    return "EvaAddingManager";
}

QMetaObject *EvaAddingManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaAddingManager( "EvaAddingManager", &EvaAddingManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaAddingManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAddingManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaAddingManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAddingManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaAddingManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "face", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotAddBuddy", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotAddBuddy", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "face", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_2 = {"acceptAndAdd", 3, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "info", &static_QUType_ptr, "QunInfo", QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotAddQun", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_4 = {"slotAddBuddyExReply", 3, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "cmd", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"slotAuthInfoReply", 4, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"slotRequestQuestionReply", 4, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "ok", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"slotAddFriendAuthExReply", 3, param_slot_7 };
    static const QUMethod slot_8 = {"requestGraphic", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "error", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"slotGraphicDone", 1, param_slot_9 };
    static const QUMethod slot_10 = {"slotFinalAdd", 0, 0 };
    static const QUMethod slot_11 = {"addingFinished", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"slotAccepAndAdd", 1, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authType", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"slotJoinQunReply", 3, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_14 = {"slotJoinQunAuthReply", 2, param_slot_14 };
    static const QMetaData slot_tbl[] = {
	{ "slotAddBuddy(const unsigned int,const QString,const unsigned short)", &slot_0, QMetaData::Public },
	{ "slotAddBuddy(const unsigned int)", &slot_1, QMetaData::Public },
	{ "acceptAndAdd(const unsigned int,const QString&,const unsigned short)", &slot_2, QMetaData::Public },
	{ "slotAddQun(const QunInfo&)", &slot_3, QMetaData::Public },
	{ "slotAddBuddyExReply(const unsigned int,const unsigned char,const unsigned char)", &slot_4, QMetaData::Private },
	{ "slotAuthInfoReply(const unsigned char,const unsigned char,const unsigned char*,const int)", &slot_5, QMetaData::Private },
	{ "slotRequestQuestionReply(const unsigned char,const unsigned char,const unsigned char*,const int)", &slot_6, QMetaData::Private },
	{ "slotAddFriendAuthExReply(const unsigned int,const unsigned char,const bool)", &slot_7, QMetaData::Private },
	{ "requestGraphic()", &slot_8, QMetaData::Private },
	{ "slotGraphicDone(bool)", &slot_9, QMetaData::Private },
	{ "slotFinalAdd()", &slot_10, QMetaData::Private },
	{ "addingFinished()", &slot_11, QMetaData::Private },
	{ "slotAccepAndAdd(const int)", &slot_12, QMetaData::Private },
	{ "slotJoinQunReply(const unsigned int,const unsigned char,const QString&)", &slot_13, QMetaData::Private },
	{ "slotJoinQunAuthReply(const unsigned int,const unsigned char)", &slot_14, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "face", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "group", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"buddyAdded", 4, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestDetails", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "ok", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"addAuthActionReply", 3, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_3 = {"joinQunAuthReply", 2, param_signal_3 };
    static const QMetaData signal_tbl[] = {
	{ "buddyAdded(const unsigned int,const QString,const unsigned short,const int)", &signal_0, QMetaData::Public },
	{ "requestDetails(const unsigned int)", &signal_1, QMetaData::Public },
	{ "addAuthActionReply(const unsigned int,const unsigned char,const bool)", &signal_2, QMetaData::Public },
	{ "joinQunAuthReply(const unsigned int,const unsigned char)", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaAddingManager", parentObject,
	slot_tbl, 15,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaAddingManager.setMetaObject( metaObj );
    return metaObj;
}

void* EvaAddingManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaAddingManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL buddyAdded
void EvaAddingManager::buddyAdded( const unsigned int t0, const QString t1, const unsigned short t2, const int t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_int.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL requestDetails
void EvaAddingManager::requestDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL addAuthActionReply
void EvaAddingManager::addAuthActionReply( const unsigned int t0, const unsigned char t1, const bool t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_bool.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL joinQunAuthReply
void EvaAddingManager::joinQunAuthReply( const unsigned int t0, const unsigned char t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

bool EvaAddingManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotAddBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+3)))); break;
    case 1: slotAddBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: acceptAndAdd((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString&)static_QUType_QString.get(_o+2),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+3)))); break;
    case 3: slotAddQun((const QunInfo&)*((const QunInfo*)static_QUType_ptr.get(_o+1))); break;
    case 4: slotAddBuddyExReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+3)))); break;
    case 5: slotAuthInfoReply((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned char*)static_QUType_ptr.get(_o+3),(const int)static_QUType_int.get(_o+4)); break;
    case 6: slotRequestQuestionReply((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned char*)static_QUType_ptr.get(_o+3),(const int)static_QUType_int.get(_o+4)); break;
    case 7: slotAddFriendAuthExReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3)); break;
    case 8: requestGraphic(); break;
    case 9: slotGraphicDone((bool)static_QUType_bool.get(_o+1)); break;
    case 10: slotFinalAdd(); break;
    case 11: addingFinished(); break;
    case 12: slotAccepAndAdd((const int)static_QUType_int.get(_o+1)); break;
    case 13: slotJoinQunReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 14: slotJoinQunAuthReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2)))); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaAddingManager::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: buddyAdded((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+3))),(const int)static_QUType_int.get(_o+4)); break;
    case 1: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: addAuthActionReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3)); break;
    case 3: joinQunAuthReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2)))); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaAddingManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaAddingManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
