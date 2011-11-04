/****************************************************************************
** LoginUIBase meta object code from reading C++ file 'loginuibase.h'
**
** Created: Tue Feb 8 23:52:11 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "loginuibase.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *LoginUIBase::className() const
{
    return "LoginUIBase";
}

QMetaObject *LoginUIBase::metaObj = 0;
static QMetaObjectCleanUp cleanUp_LoginUIBase( "LoginUIBase", &LoginUIBase::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString LoginUIBase::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "LoginUIBase", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString LoginUIBase::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "LoginUIBase", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* LoginUIBase::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"loginClickSlot", 0, 0 };
    static const QUMethod slot_1 = {"cancelClickSlot", 0, 0 };
    static const QUMethod slot_2 = {"languageChange", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "loginClickSlot()", &slot_0, QMetaData::Public },
	{ "cancelClickSlot()", &slot_1, QMetaData::Public },
	{ "languageChange()", &slot_2, QMetaData::Protected }
    };
    metaObj = QMetaObject::new_metaobject(
	"LoginUIBase", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_LoginUIBase.setMetaObject( metaObj );
    return metaObj;
}

void* LoginUIBase::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "LoginUIBase" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool LoginUIBase::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: loginClickSlot(); break;
    case 1: cancelClickSlot(); break;
    case 2: languageChange(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool LoginUIBase::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool LoginUIBase::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool LoginUIBase::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
