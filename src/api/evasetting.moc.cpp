/****************************************************************************
** EvaSetting meta object code from reading C++ file 'evasetting.h'
**
** Created: Tue Feb 8 23:56:02 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evasetting.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaSetting::className() const
{
    return "EvaSetting";
}

QMetaObject *EvaSetting::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaSetting( "EvaSetting", &EvaSetting::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaSetting::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSetting", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaSetting::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSetting", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaSetting::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"exceptionEvent", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "exceptionEvent(QString)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaSetting", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaSetting.setMetaObject( metaObj );
    return metaObj;
}

void* EvaSetting::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaSetting" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL exceptionEvent
void EvaSetting::exceptionEvent( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool EvaSetting::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool EvaSetting::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: exceptionEvent((QString)static_QUType_QString.get(_o+1)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaSetting::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaSetting::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
