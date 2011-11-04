/****************************************************************************
** EvaNetwork meta object code from reading C++ file 'evanetwork.h'
**
** Created: Tue Feb 8 23:56:15 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evanetwork.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaNetwork::className() const
{
    return "EvaNetwork";
}

QMetaObject *EvaNetwork::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaNetwork( "EvaNetwork", &EvaNetwork::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaNetwork::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaNetwork", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaNetwork::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaNetwork", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaNetwork::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"processProxyEvent", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "processProxyEvent(int)", &slot_0, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"isReady", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"dataComming", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"exceptionEvent", 1, param_signal_2 };
    static const QUMethod signal_3 = {"writeReady", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "isReady()", &signal_0, QMetaData::Public },
	{ "dataComming(int)", &signal_1, QMetaData::Public },
	{ "exceptionEvent(int)", &signal_2, QMetaData::Public },
	{ "writeReady()", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaNetwork", parentObject,
	slot_tbl, 1,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaNetwork.setMetaObject( metaObj );
    return metaObj;
}

void* EvaNetwork::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaNetwork" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL isReady
void EvaNetwork::isReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL dataComming
void EvaNetwork::dataComming( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL exceptionEvent
void EvaNetwork::exceptionEvent( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

// SIGNAL writeReady
void EvaNetwork::writeReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool EvaNetwork::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: processProxyEvent((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaNetwork::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: isReady(); break;
    case 1: dataComming((int)static_QUType_int.get(_o+1)); break;
    case 2: exceptionEvent((int)static_QUType_int.get(_o+1)); break;
    case 3: writeReady(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaNetwork::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaNetwork::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
