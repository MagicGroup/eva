/****************************************************************************
** EvaTipWindow meta object code from reading C++ file 'evatipwindow.h'
**
** Created: Tue Feb 8 23:53:34 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evatipwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaTipWindow::className() const
{
    return "EvaTipWindow";
}

QMetaObject *EvaTipWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaTipWindow( "EvaTipWindow", &EvaTipWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaTipWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaTipWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaTipWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaTipWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaTipWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaTipUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotTimeout", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotTimeout()", &slot_0, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestChat", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "requestChat(const unsigned int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaTipWindow", parentObject,
	slot_tbl, 1,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaTipWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaTipWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaTipWindow" ) )
	return this;
    return EvaTipUIBase::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestChat
void EvaTipWindow::requestChat( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaTipWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotTimeout(); break;
    default:
	return EvaTipUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaTipWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaTipUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaTipWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaTipUIBase::qt_property( id, f, v);
}

bool EvaTipWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
