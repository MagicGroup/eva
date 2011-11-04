/****************************************************************************
** EvaPicManager meta object code from reading C++ file 'evapicmanager.h'
**
** Created: Tue Feb 8 23:56:09 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evapicmanager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaPicManager::className() const
{
    return "EvaPicManager";
}

QMetaObject *EvaPicManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaPicManager( "EvaPicManager", &EvaPicManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaPicManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaPicManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaPicManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaPicManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaPicManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"slotReady", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotDataComming", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotException", 1, param_slot_2 };
    static const QUMethod slot_3 = {"packetMonitor", 0, 0 };
    static const QUMethod slot_4 = {"slotProcessBuffer", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "in", &static_QUType_ptr, "EvaPicInPacket", QUParameter::In }
    };
    static const QUMethod slot_5 = {"processRequestAgentReply", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "in", &static_QUType_ptr, "EvaPicInPacket", QUParameter::In }
    };
    static const QUMethod slot_6 = {"processRequestFaceReply", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "in", &static_QUType_ptr, "EvaPicInPacket", QUParameter::In }
    };
    static const QUMethod slot_7 = {"processTransferReply", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "in", &static_QUType_ptr, "EvaPicInPacket", QUParameter::In }
    };
    static const QUMethod slot_8 = {"processRequestStartReply", 1, param_slot_8 };
    static const QUMethod slot_9 = {"doSaveFile", 0, 0 };
    static const QUMethod slot_10 = {"doRequestNextPic", 0, 0 };
    static const QUMethod slot_11 = {"doProcessOutEvent", 0, 0 };
    static const QUMethod slot_12 = {"doRequestStart", 0, 0 };
    static const QUMethod slot_13 = {"doSendFileInfo", 0, 0 };
    static const QUMethod slot_14 = {"doRequestAgent", 0, 0 };
    static const QUMethod slot_15 = {"doSendNextFragment", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotReady()", &slot_0, QMetaData::Private },
	{ "slotDataComming(int)", &slot_1, QMetaData::Private },
	{ "slotException(int)", &slot_2, QMetaData::Private },
	{ "packetMonitor()", &slot_3, QMetaData::Private },
	{ "slotProcessBuffer()", &slot_4, QMetaData::Private },
	{ "processRequestAgentReply(const EvaPicInPacket*)", &slot_5, QMetaData::Private },
	{ "processRequestFaceReply(const EvaPicInPacket*)", &slot_6, QMetaData::Private },
	{ "processTransferReply(const EvaPicInPacket*)", &slot_7, QMetaData::Private },
	{ "processRequestStartReply(const EvaPicInPacket*)", &slot_8, QMetaData::Private },
	{ "doSaveFile()", &slot_9, QMetaData::Private },
	{ "doRequestNextPic()", &slot_10, QMetaData::Private },
	{ "doProcessOutEvent()", &slot_11, QMetaData::Private },
	{ "doRequestStart()", &slot_12, QMetaData::Private },
	{ "doSendFileInfo()", &slot_13, QMetaData::Private },
	{ "doRequestAgent()", &slot_14, QMetaData::Private },
	{ "doSendNextFragment()", &slot_15, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "fileName", &static_QUType_QString, 0, QUParameter::In },
	{ "tmpFileName", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"pictureReady", 3, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sessionID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "ip", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "port", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod signal_1 = {"pictureSent", 4, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"sendErrorMessage", 2, param_signal_2 };
    static const QMetaData signal_tbl[] = {
	{ "pictureReady(const unsigned int,const QString,const QString)", &signal_0, QMetaData::Public },
	{ "pictureSent(const unsigned int,const unsigned int,const unsigned int,const unsigned short)", &signal_1, QMetaData::Public },
	{ "sendErrorMessage(const unsigned int,const QString)", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaPicManager", parentObject,
	slot_tbl, 16,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaPicManager.setMetaObject( metaObj );
    return metaObj;
}

void* EvaPicManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaPicManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL pictureReady
void EvaPicManager::pictureReady( const unsigned int t0, const QString t1, const QString t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL pictureSent
void EvaPicManager::pictureSent( const unsigned int t0, const unsigned int t1, const unsigned int t2, const unsigned short t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    activate_signal( clist, o );
}

// SIGNAL sendErrorMessage
void EvaPicManager::sendErrorMessage( const unsigned int t0, const QString t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

bool EvaPicManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotReady(); break;
    case 1: slotDataComming((int)static_QUType_int.get(_o+1)); break;
    case 2: slotException((int)static_QUType_int.get(_o+1)); break;
    case 3: packetMonitor(); break;
    case 4: slotProcessBuffer(); break;
    case 5: processRequestAgentReply((const EvaPicInPacket*)static_QUType_ptr.get(_o+1)); break;
    case 6: processRequestFaceReply((const EvaPicInPacket*)static_QUType_ptr.get(_o+1)); break;
    case 7: processTransferReply((const EvaPicInPacket*)static_QUType_ptr.get(_o+1)); break;
    case 8: processRequestStartReply((const EvaPicInPacket*)static_QUType_ptr.get(_o+1)); break;
    case 9: doSaveFile(); break;
    case 10: doRequestNextPic(); break;
    case 11: doProcessOutEvent(); break;
    case 12: doRequestStart(); break;
    case 13: doSendFileInfo(); break;
    case 14: doRequestAgent(); break;
    case 15: doSendNextFragment(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaPicManager::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: pictureReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const QString)static_QUType_QString.get(_o+3)); break;
    case 1: pictureSent((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+4)))); break;
    case 2: sendErrorMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaPicManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaPicManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
