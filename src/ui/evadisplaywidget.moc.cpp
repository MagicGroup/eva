/****************************************************************************
** EvaLoginPageFrame meta object code from reading C++ file 'evadisplaywidget.h'
**
** Created: Tue Feb 8 23:53:05 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evadisplaywidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaLoginPageFrame::className() const
{
    return "EvaLoginPageFrame";
}

QMetaObject *EvaLoginPageFrame::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaLoginPageFrame( "EvaLoginPageFrame", &EvaLoginPageFrame::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaLoginPageFrame::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaLoginPageFrame", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaLoginPageFrame::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaLoginPageFrame", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaLoginPageFrame::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"EvaLoginPageFrame", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaLoginPageFrame.setMetaObject( metaObj );
    return metaObj;
}

void* EvaLoginPageFrame::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaLoginPageFrame" ) )
	return this;
    return QFrame::qt_cast( clname );
}

bool EvaLoginPageFrame::qt_invoke( int _id, QUObject* _o )
{
    return QFrame::qt_invoke(_id,_o);
}

bool EvaLoginPageFrame::qt_emit( int _id, QUObject* _o )
{
    return QFrame::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaLoginPageFrame::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool EvaLoginPageFrame::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaDisplayWidget::className() const
{
    return "EvaDisplayWidget";
}

QMetaObject *EvaDisplayWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaDisplayWidget( "EvaDisplayWidget", &EvaDisplayWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaDisplayWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaDisplayWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaDisplayWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaDisplayWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaDisplayWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidgetStack::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"EvaDisplayWidget", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaDisplayWidget.setMetaObject( metaObj );
    return metaObj;
}

void* EvaDisplayWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaDisplayWidget" ) )
	return this;
    return QWidgetStack::qt_cast( clname );
}

bool EvaDisplayWidget::qt_invoke( int _id, QUObject* _o )
{
    return QWidgetStack::qt_invoke(_id,_o);
}

bool EvaDisplayWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidgetStack::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaDisplayWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidgetStack::qt_property( id, f, v);
}

bool EvaDisplayWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
