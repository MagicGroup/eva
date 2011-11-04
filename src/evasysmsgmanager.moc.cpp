/****************************************************************************
** EvaSysMsgManager meta object code from reading C++ file 'evasysmsgmanager.h'
**
** Created: Tue Feb 8 23:56:31 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evasysmsgmanager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaSysMsgManager::className() const
{
    return "EvaSysMsgManager";
}

QMetaObject *EvaSysMsgManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaSysMsgManager( "EvaSysMsgManager", &EvaSysMsgManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaSysMsgManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSysMsgManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaSysMsgManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSysMsgManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaSysMsgManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "title", &static_QUType_QString, 0, QUParameter::In },
	{ "brief", &static_QUType_QString, 0, QUParameter::In },
	{ "url", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotReceivedQQNews", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "type", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "myID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "fromID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In },
	{ "allowReverse", &static_QUType_bool, 0, QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "codeLen", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotReceivedSysMessage", 7, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "flag1", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "flag2", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotReceivedVerifyAddingMessageReply", 4, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "imType", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "ext", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "qunType", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "commander", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "codeLen", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "token", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "tokenLen", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotQunSysMessage", 11, param_slot_3 };
    static const QUMethod slot_4 = {"showSysMessage", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "msgType", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "type", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "from", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "to", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "internalQunID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "commander", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "codeLen", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "token", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "tokenLen", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_5 = {"showSysMessage", 11, param_slot_5 };
    static const QMetaData slot_tbl[] = {
	{ "slotReceivedQQNews(const QString&,const QString&,const QString&)", &slot_0, QMetaData::Private },
	{ "slotReceivedSysMessage(const unsigned char,const unsigned int,const unsigned int,const QString&,const bool,const unsigned char*,const unsigned int)", &slot_1, QMetaData::Private },
	{ "slotReceivedVerifyAddingMessageReply(const unsigned int,const unsigned char,const unsigned char,const unsigned char)", &slot_2, QMetaData::Private },
	{ "slotQunSysMessage(const unsigned int,const unsigned short,const unsigned int,const unsigned char,const unsigned int,const unsigned int,const QString&,const unsigned char*,const unsigned short,const unsigned char*,const unsigned short)", &slot_3, QMetaData::Private },
	{ "showSysMessage()", &slot_4, QMetaData::Public },
	{ "showSysMessage(const unsigned short,const unsigned char,const unsigned int,const unsigned int,const QString,const unsigned int,const unsigned int,const unsigned char*,const unsigned short,const unsigned char*,const unsigned short)", &slot_5, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "face", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestAddBuddy", 3, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "face", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "group", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"buddyAdded", 4, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestDetails", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_3 = {"requestQunDetails", 1, param_signal_3 };
    static const QUMethod signal_4 = {"sysMessage", 0, 0 };
    static const QUMethod signal_5 = {"qunListChanged", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "requestAddBuddy(const unsigned int,const QString,const unsigned short)", &signal_0, QMetaData::Public },
	{ "buddyAdded(const unsigned int,const QString,const unsigned short,const int)", &signal_1, QMetaData::Public },
	{ "requestDetails(const unsigned int)", &signal_2, QMetaData::Public },
	{ "requestQunDetails(const unsigned int)", &signal_3, QMetaData::Public },
	{ "sysMessage()", &signal_4, QMetaData::Public },
	{ "qunListChanged()", &signal_5, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaSysMsgManager", parentObject,
	slot_tbl, 6,
	signal_tbl, 6,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaSysMsgManager.setMetaObject( metaObj );
    return metaObj;
}

void* EvaSysMsgManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaSysMsgManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestAddBuddy
void EvaSysMsgManager::requestAddBuddy( const unsigned int t0, const QString t1, const unsigned short t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL buddyAdded
void EvaSysMsgManager::buddyAdded( const unsigned int t0, const QString t1, const unsigned short t2, const int t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
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
void EvaSysMsgManager::requestDetails( const unsigned int t0 )
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

// SIGNAL requestQunDetails
void EvaSysMsgManager::requestQunDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL sysMessage
void EvaSysMsgManager::sysMessage()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL qunListChanged
void EvaSysMsgManager::qunListChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

bool EvaSysMsgManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotReceivedQQNews((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 1: slotReceivedSysMessage((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const QString&)static_QUType_QString.get(_o+4),(const bool)static_QUType_bool.get(_o+5),(const unsigned char*)static_QUType_ptr.get(_o+6),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+7)))); break;
    case 2: slotReceivedVerifyAddingMessageReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+3))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4)))); break;
    case 3: slotQunSysMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+5))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+6))),(const QString&)static_QUType_QString.get(_o+7),(const unsigned char*)static_QUType_ptr.get(_o+8),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+9))),(const unsigned char*)static_QUType_ptr.get(_o+10),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+11)))); break;
    case 4: showSysMessage(); break;
    case 5: showSysMessage((const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const QString)static_QUType_QString.get(_o+5),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+6))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+7))),(const unsigned char*)static_QUType_ptr.get(_o+8),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+9))),(const unsigned char*)static_QUType_ptr.get(_o+10),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+11)))); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaSysMsgManager::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestAddBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+3)))); break;
    case 1: buddyAdded((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+3))),(const int)static_QUType_int.get(_o+4)); break;
    case 2: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: requestQunDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 4: sysMessage(); break;
    case 5: qunListChanged(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaSysMsgManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaSysMsgManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
