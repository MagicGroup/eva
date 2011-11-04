/****************************************************************************
** EvaLoginVeriWindow meta object code from reading C++ file 'evaloginveriwindow.h'
**
** Created: Tue Feb 8 23:52:35 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaloginveriwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaLoginVeriWindow::className() const
{
    return "EvaLoginVeriWindow";
}

QMetaObject *EvaLoginVeriWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaLoginVeriWindow( "EvaLoginVeriWindow", &EvaLoginVeriWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaLoginVeriWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaLoginVeriWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaLoginVeriWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaLoginVeriWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaLoginVeriWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaLoginVeriUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotImageReady", 0, 0 };
    static const QUMethod slot_1 = {"slotVerifyPassed", 0, 0 };
    static const QUMethod slot_2 = {"slotBtnChangeImageClicked", 0, 0 };
    static const QUMethod slot_3 = {"slotBtnOKClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotImageReady()", &slot_0, QMetaData::Public },
	{ "slotVerifyPassed()", &slot_1, QMetaData::Public },
	{ "slotBtnChangeImageClicked()", &slot_2, QMetaData::Private },
	{ "slotBtnOKClicked()", &slot_3, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"changeImage", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ "code", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"sendVerifyCode", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "changeImage()", &signal_0, QMetaData::Public },
	{ "sendVerifyCode(const QString&)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaLoginVeriWindow", parentObject,
	slot_tbl, 4,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaLoginVeriWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaLoginVeriWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaLoginVeriWindow" ) )
	return this;
    return EvaLoginVeriUIBase::qt_cast( clname );
}

// SIGNAL changeImage
void EvaLoginVeriWindow::changeImage()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL sendVerifyCode
void EvaLoginVeriWindow::sendVerifyCode( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

bool EvaLoginVeriWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotImageReady(); break;
    case 1: slotVerifyPassed(); break;
    case 2: slotBtnChangeImageClicked(); break;
    case 3: slotBtnOKClicked(); break;
    default:
	return EvaLoginVeriUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaLoginVeriWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: changeImage(); break;
    case 1: sendVerifyCode((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return EvaLoginVeriUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaLoginVeriWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaLoginVeriUIBase::qt_property( id, f, v);
}

bool EvaLoginVeriWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
