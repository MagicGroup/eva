/****************************************************************************
** EvaSysBroadcastWindow meta object code from reading C++ file 'evasysbroadcastwindow.h'
**
** Created: Tue Feb 8 23:52:19 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evasysbroadcastwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaSysBroadcastWindow::className() const
{
    return "EvaSysBroadcastWindow";
}

QMetaObject *EvaSysBroadcastWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaSysBroadcastWindow( "EvaSysBroadcastWindow", &EvaSysBroadcastWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaSysBroadcastWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSysBroadcastWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaSysBroadcastWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSysBroadcastWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaSysBroadcastWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaSysBroadcastUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotOpenURL", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotOpenURL()", &slot_0, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaSysBroadcastWindow", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaSysBroadcastWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaSysBroadcastWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaSysBroadcastWindow" ) )
	return this;
    return EvaSysBroadcastUIBase::qt_cast( clname );
}

bool EvaSysBroadcastWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotOpenURL(); break;
    default:
	return EvaSysBroadcastUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaSysBroadcastWindow::qt_emit( int _id, QUObject* _o )
{
    return EvaSysBroadcastUIBase::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaSysBroadcastWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaSysBroadcastUIBase::qt_property( id, f, v);
}

bool EvaSysBroadcastWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
