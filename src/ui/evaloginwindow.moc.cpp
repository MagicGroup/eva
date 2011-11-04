/****************************************************************************
** EvaLoginWindow meta object code from reading C++ file 'evaloginwindow.h'
**
** Created: Tue Feb 8 23:52:09 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaloginwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaLoginWindow::className() const
{
    return "EvaLoginWindow";
}

QMetaObject *EvaLoginWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaLoginWindow( "EvaLoginWindow", &EvaLoginWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaLoginWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaLoginWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaLoginWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaLoginWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaLoginWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = LoginUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"cancelClickSlot", 0, 0 };
    static const QUMethod slot_1 = {"loginClickSlot", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "on", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"showNetSetup", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotSelectChanged", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"slotLoginTypeChanged", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"slotIDChanged", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"slotPasswordChanged", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"slotProxyUserChanged", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"slotProxyPasswordChanged", 1, param_slot_8 };
    static const QMetaData slot_tbl[] = {
	{ "cancelClickSlot()", &slot_0, QMetaData::Public },
	{ "loginClickSlot()", &slot_1, QMetaData::Public },
	{ "showNetSetup(bool)", &slot_2, QMetaData::Protected },
	{ "slotSelectChanged(int)", &slot_3, QMetaData::Protected },
	{ "slotLoginTypeChanged(int)", &slot_4, QMetaData::Protected },
	{ "slotIDChanged(const QString&)", &slot_5, QMetaData::Protected },
	{ "slotPasswordChanged(const QString&)", &slot_6, QMetaData::Protected },
	{ "slotProxyUserChanged(const QString&)", &slot_7, QMetaData::Protected },
	{ "slotProxyPasswordChanged(const QString&)", &slot_8, QMetaData::Protected }
    };
    static const QUMethod signal_0 = {"doLogin", 0, 0 };
    static const QUMethod signal_1 = {"doCancel", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "doLogin()", &signal_0, QMetaData::Public },
	{ "doCancel()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaLoginWindow", parentObject,
	slot_tbl, 9,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaLoginWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaLoginWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaLoginWindow" ) )
	return this;
    return LoginUIBase::qt_cast( clname );
}

// SIGNAL doLogin
void EvaLoginWindow::doLogin()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL doCancel
void EvaLoginWindow::doCancel()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool EvaLoginWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: cancelClickSlot(); break;
    case 1: loginClickSlot(); break;
    case 2: showNetSetup((bool)static_QUType_bool.get(_o+1)); break;
    case 3: slotSelectChanged((int)static_QUType_int.get(_o+1)); break;
    case 4: slotLoginTypeChanged((int)static_QUType_int.get(_o+1)); break;
    case 5: slotIDChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 6: slotPasswordChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: slotProxyUserChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    case 8: slotProxyPasswordChanged((const QString&)static_QUType_QString.get(_o+1)); break;
    default:
	return LoginUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaLoginWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: doLogin(); break;
    case 1: doCancel(); break;
    default:
	return LoginUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaLoginWindow::qt_property( int id, int f, QVariant* v)
{
    return LoginUIBase::qt_property( id, f, v);
}

bool EvaLoginWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
