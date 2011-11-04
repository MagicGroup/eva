/****************************************************************************
** EvaFileManager meta object code from reading C++ file 'evafilemanager.h'
**
** Created: Tue Feb 8 23:55:12 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evafilemanager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaFileManager::className() const
{
    return "EvaFileManager";
}

QMetaObject *EvaFileManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaFileManager( "EvaFileManager", &EvaFileManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaFileManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaFileManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaFileManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaFileManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaFileManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isResume", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotFileTransferResume", 3, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "slotFileTransferResume(const unsigned int,const unsigned int,const bool)", &slot_0, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"notifyTransferStatus", 5, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_1 = {"notifyAgentRequest", 6, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"notifyTransferSessionChanged", 3, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "EvaFileStatus", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_3 = {"notifyTransferNormalInfo", 7, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod signal_4 = {"notifyAddressRequest", 7, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "notifyTransferStatus(const unsigned int,const unsigned int,const unsigned int,const unsigned int,const int)", &signal_0, QMetaData::Public },
	{ "notifyAgentRequest(const unsigned int,const unsigned int,const unsigned int,const unsigned int,const unsigned short,const unsigned char)", &signal_1, QMetaData::Public },
	{ "notifyTransferSessionChanged(const unsigned int,const unsigned int,const unsigned int)", &signal_2, QMetaData::Public },
	{ "notifyTransferNormalInfo(const unsigned int,const unsigned int,EvaFileStatus,const QString,const QString,const unsigned int,const unsigned char)", &signal_3, QMetaData::Public },
	{ "notifyAddressRequest(const unsigned int,const unsigned int,const unsigned int,const unsigned int,const unsigned short,const unsigned int,const unsigned short)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaFileManager", parentObject,
	slot_tbl, 1,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaFileManager.setMetaObject( metaObj );
    return metaObj;
}

void* EvaFileManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaFileManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL notifyTransferStatus
void EvaFileManager::notifyTransferStatus( const unsigned int t0, const unsigned int t1, const unsigned int t2, const unsigned int t3, const int t4 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[6];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    static_QUType_int.set(o+5,t4);
    activate_signal( clist, o );
}

// SIGNAL notifyAgentRequest
void EvaFileManager::notifyAgentRequest( const unsigned int t0, const unsigned int t1, const unsigned int t2, const unsigned int t3, const unsigned short t4, const unsigned char t5 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[7];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    static_QUType_ptr.set(o+5,&t4);
    static_QUType_ptr.set(o+6,&t5);
    activate_signal( clist, o );
}

// SIGNAL notifyTransferSessionChanged
void EvaFileManager::notifyTransferSessionChanged( const unsigned int t0, const unsigned int t1, const unsigned int t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL notifyTransferNormalInfo
void EvaFileManager::notifyTransferNormalInfo( const unsigned int t0, const unsigned int t1, EvaFileStatus t2, const QString t3, const QString t4, const unsigned int t5, const unsigned char t6 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[8];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_QString.set(o+4,t3);
    static_QUType_QString.set(o+5,t4);
    static_QUType_ptr.set(o+6,&t5);
    static_QUType_ptr.set(o+7,&t6);
    activate_signal( clist, o );
}

// SIGNAL notifyAddressRequest
void EvaFileManager::notifyAddressRequest( const unsigned int t0, const unsigned int t1, const unsigned int t2, const unsigned int t3, const unsigned short t4, const unsigned int t5, const unsigned short t6 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[8];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    static_QUType_ptr.set(o+5,&t4);
    static_QUType_ptr.set(o+6,&t5);
    static_QUType_ptr.set(o+7,&t6);
    activate_signal( clist, o );
}

bool EvaFileManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotFileTransferResume((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaFileManager::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: notifyTransferStatus((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const int)static_QUType_int.get(_o+5)); break;
    case 1: notifyAgentRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+6)))); break;
    case 2: notifyTransferSessionChanged((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3)))); break;
    case 3: notifyTransferNormalInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(EvaFileStatus)(*((EvaFileStatus*)static_QUType_ptr.get(_o+3))),(const QString)static_QUType_QString.get(_o+4),(const QString)static_QUType_QString.get(_o+5),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+6))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+7)))); break;
    case 4: notifyAddressRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+6))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+7)))); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaFileManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaFileManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
