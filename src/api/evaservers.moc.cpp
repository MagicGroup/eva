/****************************************************************************
** EvaServers meta object code from reading C++ file 'evaservers.h'
**
** Created: Tue Feb 8 23:56:16 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaservers.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaServers::className() const
{
    return "EvaServers";
}

QMetaObject *EvaServers::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaServers( "EvaServers", &EvaServers::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaServers::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaServers", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaServers::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaServers", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaServers::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"getResultsSlot", 0, 0 };
    static const QUMethod slot_1 = {"slotTimeout", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "getResultsSlot()", &slot_0, QMetaData::Private },
	{ "slotTimeout()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "ip", &static_QUType_ptr, "QHostAddress", QUParameter::In }
    };
    static const QUMethod signal_0 = {"isReady", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "isReady(QHostAddress)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaServers", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaServers.setMetaObject( metaObj );
    return metaObj;
}

void* EvaServers::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaServers" ) )
	return this;
    return QObject::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL isReady
void EvaServers::isReady( QHostAddress t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaServers::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: getResultsSlot(); break;
    case 1: slotTimeout(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaServers::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: isReady((QHostAddress)(*((QHostAddress*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaServers::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaServers::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
