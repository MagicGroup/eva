/****************************************************************************
** EvaLoginManager meta object code from reading C++ file 'evaloginmanager.h'
**
** Created: Tue Feb 8 23:56:31 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaloginmanager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaLoginManager::className() const
{
    return "EvaLoginManager";
}

QMetaObject *EvaLoginManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaLoginManager( "EvaLoginManager", &EvaLoginManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaLoginManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaLoginManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaLoginManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaLoginManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaLoginManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"EvaLoginManager", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaLoginManager.setMetaObject( metaObj );
    return metaObj;
}

void* EvaLoginManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaLoginManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

bool EvaLoginManager::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool EvaLoginManager::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaLoginManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaLoginManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
