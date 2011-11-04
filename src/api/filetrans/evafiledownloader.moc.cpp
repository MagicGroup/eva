/****************************************************************************
** EvaFileThread meta object code from reading C++ file 'evafiledownloader.h'
**
** Created: Tue Feb 8 23:55:14 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evafiledownloader.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaFileThread::className() const
{
    return "EvaFileThread";
}

QMetaObject *EvaFileThread::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaFileThread( "EvaFileThread", &EvaFileThread::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaFileThread::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaFileThread", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaFileThread::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaFileThread", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaFileThread::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"EvaFileThread", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaFileThread.setMetaObject( metaObj );
    return metaObj;
}

void* EvaFileThread::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaFileThread" ) )
	return this;
    if ( !qstrcmp( clname, "QThread" ) )
	return (QThread*)this;
    return QObject::qt_cast( clname );
}

bool EvaFileThread::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool EvaFileThread::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaFileThread::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaFileThread::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaAgentThread::className() const
{
    return "EvaAgentThread";
}

QMetaObject *EvaAgentThread::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaAgentThread( "EvaAgentThread", &EvaAgentThread::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaAgentThread::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAgentThread", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaAgentThread::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAgentThread", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaAgentThread::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaFileThread::staticMetaObject();
    static const QUMethod slot_0 = {"slotNetworkReady", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotDataComming", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotNetworkException", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "slotNetworkReady()", &slot_0, QMetaData::Private },
	{ "slotDataComming(int)", &slot_1, QMetaData::Private },
	{ "slotNetworkException(int)", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaAgentThread", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaAgentThread.setMetaObject( metaObj );
    return metaObj;
}

void* EvaAgentThread::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaAgentThread" ) )
	return this;
    return EvaFileThread::qt_cast( clname );
}

bool EvaAgentThread::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotNetworkReady(); break;
    case 1: slotDataComming((int)static_QUType_int.get(_o+1)); break;
    case 2: slotNetworkException((int)static_QUType_int.get(_o+1)); break;
    default:
	return EvaFileThread::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaAgentThread::qt_emit( int _id, QUObject* _o )
{
    return EvaFileThread::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaAgentThread::qt_property( int id, int f, QVariant* v)
{
    return EvaFileThread::qt_property( id, f, v);
}

bool EvaAgentThread::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaAgentUploader::className() const
{
    return "EvaAgentUploader";
}

QMetaObject *EvaAgentUploader::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaAgentUploader( "EvaAgentUploader", &EvaAgentUploader::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaAgentUploader::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAgentUploader", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaAgentUploader::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAgentUploader", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaAgentUploader::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaAgentThread::staticMetaObject();
    static const QUMethod slot_0 = {"slotDnsReady", 0, 0 };
    static const QUMethod slot_1 = {"slotWriteReady", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotDnsReady()", &slot_0, QMetaData::Private },
	{ "slotWriteReady()", &slot_1, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaAgentUploader", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaAgentUploader.setMetaObject( metaObj );
    return metaObj;
}

void* EvaAgentUploader::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaAgentUploader" ) )
	return this;
    return EvaAgentThread::qt_cast( clname );
}

bool EvaAgentUploader::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotDnsReady(); break;
    case 1: slotWriteReady(); break;
    default:
	return EvaAgentThread::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaAgentUploader::qt_emit( int _id, QUObject* _o )
{
    return EvaAgentThread::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaAgentUploader::qt_property( int id, int f, QVariant* v)
{
    return EvaAgentThread::qt_property( id, f, v);
}

bool EvaAgentUploader::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaAgentDownloader::className() const
{
    return "EvaAgentDownloader";
}

QMetaObject *EvaAgentDownloader::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaAgentDownloader( "EvaAgentDownloader", &EvaAgentDownloader::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaAgentDownloader::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAgentDownloader", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaAgentDownloader::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAgentDownloader", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaAgentDownloader::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaAgentThread::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"EvaAgentDownloader", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaAgentDownloader.setMetaObject( metaObj );
    return metaObj;
}

void* EvaAgentDownloader::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaAgentDownloader" ) )
	return this;
    return EvaAgentThread::qt_cast( clname );
}

bool EvaAgentDownloader::qt_invoke( int _id, QUObject* _o )
{
    return EvaAgentThread::qt_invoke(_id,_o);
}

bool EvaAgentDownloader::qt_emit( int _id, QUObject* _o )
{
    return EvaAgentThread::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaAgentDownloader::qt_property( int id, int f, QVariant* v)
{
    return EvaAgentThread::qt_property( id, f, v);
}

bool EvaAgentDownloader::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaUDPThread::className() const
{
    return "EvaUDPThread";
}

QMetaObject *EvaUDPThread::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaUDPThread( "EvaUDPThread", &EvaUDPThread::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaUDPThread::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaUDPThread", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaUDPThread::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaUDPThread", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaUDPThread::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaFileThread::staticMetaObject();
    static const QUMethod slot_0 = {"slotNetworkReady", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotDataComming", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotNetworkException", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "slotNetworkReady()", &slot_0, QMetaData::Private },
	{ "slotDataComming(int)", &slot_1, QMetaData::Private },
	{ "slotNetworkException(int)", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaUDPThread", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaUDPThread.setMetaObject( metaObj );
    return metaObj;
}

void* EvaUDPThread::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaUDPThread" ) )
	return this;
    return EvaFileThread::qt_cast( clname );
}

bool EvaUDPThread::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotNetworkReady(); break;
    case 1: slotDataComming((int)static_QUType_int.get(_o+1)); break;
    case 2: slotNetworkException((int)static_QUType_int.get(_o+1)); break;
    default:
	return EvaFileThread::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaUDPThread::qt_emit( int _id, QUObject* _o )
{
    return EvaFileThread::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaUDPThread::qt_property( int id, int f, QVariant* v)
{
    return EvaFileThread::qt_property( id, f, v);
}

bool EvaUDPThread::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaUdpUploader::className() const
{
    return "EvaUdpUploader";
}

QMetaObject *EvaUdpUploader::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaUdpUploader( "EvaUdpUploader", &EvaUdpUploader::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaUdpUploader::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaUdpUploader", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaUdpUploader::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaUdpUploader", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaUdpUploader::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaUDPThread::staticMetaObject();
    static const QUMethod slot_0 = {"slotDnsReady", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotDnsReady()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaUdpUploader", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaUdpUploader.setMetaObject( metaObj );
    return metaObj;
}

void* EvaUdpUploader::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaUdpUploader" ) )
	return this;
    return EvaUDPThread::qt_cast( clname );
}

bool EvaUdpUploader::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotDnsReady(); break;
    default:
	return EvaUDPThread::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaUdpUploader::qt_emit( int _id, QUObject* _o )
{
    return EvaUDPThread::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaUdpUploader::qt_property( int id, int f, QVariant* v)
{
    return EvaUDPThread::qt_property( id, f, v);
}

bool EvaUdpUploader::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaUdpDownloader::className() const
{
    return "EvaUdpDownloader";
}

QMetaObject *EvaUdpDownloader::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaUdpDownloader( "EvaUdpDownloader", &EvaUdpDownloader::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaUdpDownloader::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaUdpDownloader", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaUdpDownloader::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaUdpDownloader", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaUdpDownloader::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaUDPThread::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"EvaUdpDownloader", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaUdpDownloader.setMetaObject( metaObj );
    return metaObj;
}

void* EvaUdpDownloader::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaUdpDownloader" ) )
	return this;
    return EvaUDPThread::qt_cast( clname );
}

bool EvaUdpDownloader::qt_invoke( int _id, QUObject* _o )
{
    return EvaUDPThread::qt_invoke(_id,_o);
}

bool EvaUdpDownloader::qt_emit( int _id, QUObject* _o )
{
    return EvaUDPThread::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaUdpDownloader::qt_property( int id, int f, QVariant* v)
{
    return EvaUDPThread::qt_property( id, f, v);
}

bool EvaUdpDownloader::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
