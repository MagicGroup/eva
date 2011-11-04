/****************************************************************************
** CustomFaceManagerUI meta object code from reading C++ file 'customfacemanagerui.h'
**
** Created: Tue Feb 8 23:53:10 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "customfacemanagerui.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CustomFaceManagerUI::className() const
{
    return "CustomFaceManagerUI";
}

QMetaObject *CustomFaceManagerUI::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CustomFaceManagerUI( "CustomFaceManagerUI", &CustomFaceManagerUI::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CustomFaceManagerUI::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CustomFaceManagerUI", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CustomFaceManagerUI::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CustomFaceManagerUI", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CustomFaceManagerUI::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"CustomFaceManagerUI", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CustomFaceManagerUI.setMetaObject( metaObj );
    return metaObj;
}

void* CustomFaceManagerUI::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CustomFaceManagerUI" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool CustomFaceManagerUI::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CustomFaceManagerUI::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool CustomFaceManagerUI::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool CustomFaceManagerUI::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
