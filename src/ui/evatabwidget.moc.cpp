/****************************************************************************
** EvaTabBar meta object code from reading C++ file 'evatabwidget.h'
**
** Created: Tue Feb 8 23:51:56 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evatabwidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaTabBar::className() const
{
    return "EvaTabBar";
}

QMetaObject *EvaTabBar::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaTabBar( "EvaTabBar", &EvaTabBar::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaTabBar::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaTabBar", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaTabBar::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaTabBar", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaTabBar::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ "key", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"clicked", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "clicked(int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaTabBar", parentObject,
	0, 0,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaTabBar.setMetaObject( metaObj );
    return metaObj;
}

void* EvaTabBar::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaTabBar" ) )
	return this;
    return QWidget::qt_cast( clname );
}

// SIGNAL clicked
void EvaTabBar::clicked( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

bool EvaTabBar::qt_invoke( int _id, QUObject* _o )
{
    return QWidget::qt_invoke(_id,_o);
}

bool EvaTabBar::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: clicked((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaTabBar::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool EvaTabBar::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaWidgetStack::className() const
{
    return "EvaWidgetStack";
}

QMetaObject *EvaWidgetStack::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaWidgetStack( "EvaWidgetStack", &EvaWidgetStack::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaWidgetStack::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaWidgetStack", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaWidgetStack::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaWidgetStack", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaWidgetStack::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidgetStack::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In },
	{ "seq", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"raiseWidget", 2, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "raiseWidget(int,int)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaWidgetStack", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaWidgetStack.setMetaObject( metaObj );
    return metaObj;
}

void* EvaWidgetStack::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaWidgetStack" ) )
	return this;
    return QWidgetStack::qt_cast( clname );
}

bool EvaWidgetStack::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: raiseWidget((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QWidgetStack::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaWidgetStack::qt_emit( int _id, QUObject* _o )
{
    return QWidgetStack::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaWidgetStack::qt_property( int id, int f, QVariant* v)
{
    return QWidgetStack::qt_property( id, f, v);
}

bool EvaWidgetStack::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaTabWidget::className() const
{
    return "EvaTabWidget";
}

QMetaObject *EvaTabWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaTabWidget( "EvaTabWidget", &EvaTabWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaTabWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaTabWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaTabWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaTabWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaTabWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "key", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"changeTabTo", 1, param_slot_0 };
    static const QMetaData slot_tbl[] = {
	{ "changeTabTo(int)", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaTabWidget", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaTabWidget.setMetaObject( metaObj );
    return metaObj;
}

void* EvaTabWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaTabWidget" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool EvaTabWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: changeTabTo((int)static_QUType_int.get(_o+1)); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaTabWidget::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaTabWidget::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool EvaTabWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
