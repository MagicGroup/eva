/****************************************************************************
** EvaListView meta object code from reading C++ file 'evalistview.h'
**
** Created: Tue Feb 8 23:53:08 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evalistview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaListView::className() const
{
    return "EvaListView";
}

QMetaObject *EvaListView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaListView( "EvaListView", &EvaListView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaListView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaListView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaListView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaListView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QListView::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"EvaListView", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaListView.setMetaObject( metaObj );
    return metaObj;
}

void* EvaListView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaListView" ) )
	return this;
    return QListView::qt_cast( clname );
}

bool EvaListView::qt_invoke( int _id, QUObject* _o )
{
    return QListView::qt_invoke(_id,_o);
}

bool EvaListView::qt_emit( int _id, QUObject* _o )
{
    return QListView::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaListView::qt_property( int id, int f, QVariant* v)
{
    return QListView::qt_property( id, f, v);
}

bool EvaListView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
