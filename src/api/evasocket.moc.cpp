/****************************************************************************
** EvaSocket meta object code from reading C++ file 'evasocket.h'
**
** Created: Tue Feb 8 23:56:04 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evasocket.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaSocket::className() const
{
    return "EvaSocket";
}

QMetaObject *EvaSocket::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaSocket( "EvaSocket", &EvaSocket::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaSocket::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSocket", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaSocket::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSocket", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaSocket::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"closeConnection", 0, 0 };
    static const QUMethod slot_1 = {"startConnecting", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotWriteReady", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotReceiveReady", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "closeConnection()", &slot_0, QMetaData::Public },
	{ "startConnecting()", &slot_1, QMetaData::Public },
	{ "slotWriteReady(int)", &slot_2, QMetaData::Private },
	{ "slotReceiveReady(int)", &slot_3, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"isReady", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"receivedData", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"exceptionEvent", 1, param_signal_2 };
    static const QUMethod signal_3 = {"writeReady", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "isReady()", &signal_0, QMetaData::Public },
	{ "receivedData(int)", &signal_1, QMetaData::Public },
	{ "exceptionEvent(int)", &signal_2, QMetaData::Public },
	{ "writeReady()", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaSocket", parentObject,
	slot_tbl, 4,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaSocket.setMetaObject( metaObj );
    return metaObj;
}

void* EvaSocket::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaSocket" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL isReady
void EvaSocket::isReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL receivedData
void EvaSocket::receivedData( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL exceptionEvent
void EvaSocket::exceptionEvent( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL writeReady
void EvaSocket::writeReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool EvaSocket::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: closeConnection(); break;
    case 1: startConnecting(); break;
    case 2: slotWriteReady((int)static_QUType_int.get(_o+1)); break;
    case 3: slotReceiveReady((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaSocket::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: isReady(); break;
    case 1: receivedData((int)static_QUType_int.get(_o+1)); break;
    case 2: exceptionEvent((int)static_QUType_int.get(_o+1)); break;
    case 3: writeReady(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaSocket::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaSocket::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaHttpProxy::className() const
{
    return "EvaHttpProxy";
}

QMetaObject *EvaHttpProxy::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaHttpProxy( "EvaHttpProxy", &EvaHttpProxy::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaHttpProxy::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaHttpProxy", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaHttpProxy::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaHttpProxy", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaHttpProxy::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaSocket::staticMetaObject();
    static const QUMethod slot_0 = {"tcpReady", 0, 0 };
    static const QUMethod slot_1 = {"slotWriteReady", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "len", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"parseData", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "tcpReady()", &slot_0, QMetaData::Public },
	{ "slotWriteReady()", &slot_1, QMetaData::Public },
	{ "parseData(int)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"dataArrived", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"proxyEvent", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"socketException", 1, param_signal_2 };
    static const QUMethod signal_3 = {"proxyWriteReady", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "dataArrived(int)", &signal_0, QMetaData::Public },
	{ "proxyEvent(int)", &signal_1, QMetaData::Public },
	{ "socketException(int)", &signal_2, QMetaData::Public },
	{ "proxyWriteReady()", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaHttpProxy", parentObject,
	slot_tbl, 3,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaHttpProxy.setMetaObject( metaObj );
    return metaObj;
}

void* EvaHttpProxy::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaHttpProxy" ) )
	return this;
    return EvaSocket::qt_cast( clname );
}

// SIGNAL dataArrived
void EvaHttpProxy::dataArrived( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL proxyEvent
void EvaHttpProxy::proxyEvent( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL socketException
void EvaHttpProxy::socketException( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL proxyWriteReady
void EvaHttpProxy::proxyWriteReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool EvaHttpProxy::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: tcpReady(); break;
    case 1: slotWriteReady(); break;
    case 2: parseData((int)static_QUType_int.get(_o+1)); break;
    default:
	return EvaSocket::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaHttpProxy::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: dataArrived((int)static_QUType_int.get(_o+1)); break;
    case 1: proxyEvent((int)static_QUType_int.get(_o+1)); break;
    case 2: socketException((int)static_QUType_int.get(_o+1)); break;
    case 3: proxyWriteReady(); break;
    default:
	return EvaSocket::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaHttpProxy::qt_property( int id, int f, QVariant* v)
{
    return EvaSocket::qt_property( id, f, v);
}

bool EvaHttpProxy::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaHttp::className() const
{
    return "EvaHttp";
}

QMetaObject *EvaHttp::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaHttp( "EvaHttp", &EvaHttp::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaHttp::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaHttp", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaHttp::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaHttp", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaHttp::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaSocket::staticMetaObject();
    static const QUMethod slot_0 = {"tcpReady", 0, 0 };
    static const QUMethod slot_1 = {"slotWriteReady", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "len", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"parseData", 1, param_slot_2 };
    static const QUMethod slot_3 = {"getResultsSlot", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "tcpReady()", &slot_0, QMetaData::Private },
	{ "slotWriteReady()", &slot_1, QMetaData::Private },
	{ "parseData(int)", &slot_2, QMetaData::Private },
	{ "getResultsSlot()", &slot_3, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"readReady", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ "error", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestFinished", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "readReady()", &signal_0, QMetaData::Public },
	{ "requestFinished(bool)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaHttp", parentObject,
	slot_tbl, 4,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaHttp.setMetaObject( metaObj );
    return metaObj;
}

void* EvaHttp::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaHttp" ) )
	return this;
    return EvaSocket::qt_cast( clname );
}

// SIGNAL readReady
void EvaHttp::readReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL requestFinished
void EvaHttp::requestFinished( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 1, t0 );
}

bool EvaHttp::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: tcpReady(); break;
    case 1: slotWriteReady(); break;
    case 2: parseData((int)static_QUType_int.get(_o+1)); break;
    case 3: getResultsSlot(); break;
    default:
	return EvaSocket::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaHttp::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: readReady(); break;
    case 1: requestFinished((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return EvaSocket::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaHttp::qt_property( int id, int f, QVariant* v)
{
    return EvaSocket::qt_property( id, f, v);
}

bool EvaHttp::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
