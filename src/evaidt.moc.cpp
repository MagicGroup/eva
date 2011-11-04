/****************************************************************************
** IdleTimeDetector meta object code from reading C++ file 'evaidt.h'
**
** Created: Tue Feb 8 23:56:31 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaidt.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *IdleTimeDetector::className() const
{
    return "IdleTimeDetector";
}

QMetaObject *IdleTimeDetector::metaObj = 0;
static QMetaObjectCleanUp cleanUp_IdleTimeDetector( "IdleTimeDetector", &IdleTimeDetector::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString IdleTimeDetector::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "IdleTimeDetector", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString IdleTimeDetector::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "IdleTimeDetector", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* IdleTimeDetector::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "maxIdle", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"setMaxIdle", 1, param_slot_0 };
    static const QUMethod slot_1 = {"startIdleDetection", 0, 0 };
    static const QUMethod slot_2 = {"stopIdleDetection", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "on", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"toggleOverAllIdleDetection", 1, param_slot_3 };
    static const QUMethod slot_4 = {"check", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "setMaxIdle(int)", &slot_0, QMetaData::Public },
	{ "startIdleDetection()", &slot_1, QMetaData::Public },
	{ "stopIdleDetection()", &slot_2, QMetaData::Public },
	{ "toggleOverAllIdleDetection(bool)", &slot_3, QMetaData::Public },
	{ "check()", &slot_4, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ "minutes", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"extractTime", 1, param_signal_0 };
    static const QUMethod signal_1 = {"stopAllTimers", 0, 0 };
    static const QUMethod signal_2 = {"idleTimeUp", 0, 0 };
    static const QUMethod signal_3 = {"idleBack", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "extractTime(int)", &signal_0, QMetaData::Public },
	{ "stopAllTimers()", &signal_1, QMetaData::Public },
	{ "idleTimeUp()", &signal_2, QMetaData::Public },
	{ "idleBack()", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"IdleTimeDetector", parentObject,
	slot_tbl, 5,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_IdleTimeDetector.setMetaObject( metaObj );
    return metaObj;
}

void* IdleTimeDetector::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "IdleTimeDetector" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL extractTime
void IdleTimeDetector::extractTime( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL stopAllTimers
void IdleTimeDetector::stopAllTimers()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

// SIGNAL idleTimeUp
void IdleTimeDetector::idleTimeUp()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL idleBack
void IdleTimeDetector::idleBack()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

bool IdleTimeDetector::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: setMaxIdle((int)static_QUType_int.get(_o+1)); break;
    case 1: startIdleDetection(); break;
    case 2: stopIdleDetection(); break;
    case 3: toggleOverAllIdleDetection((bool)static_QUType_bool.get(_o+1)); break;
    case 4: check(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool IdleTimeDetector::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: extractTime((int)static_QUType_int.get(_o+1)); break;
    case 1: stopAllTimers(); break;
    case 2: idleTimeUp(); break;
    case 3: idleBack(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool IdleTimeDetector::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool IdleTimeDetector::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
