/****************************************************************************
** EvaQunSysMsgWindow meta object code from reading C++ file 'evaqunsysmsgwindow.h'
**
** Created: Tue Feb 8 23:52:28 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaqunsysmsgwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaQunSysMsgWindow::className() const
{
    return "EvaQunSysMsgWindow";
}

QMetaObject *EvaQunSysMsgWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaQunSysMsgWindow( "EvaQunSysMsgWindow", &EvaQunSysMsgWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaQunSysMsgWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunSysMsgWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaQunSysMsgWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunSysMsgWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaQunSysMsgWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaQunSysMsgUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotQQClicked", 0, 0 };
    static const QUMethod slot_1 = {"slotQunClicked", 0, 0 };
    static const QUMethod slot_2 = {"slotOkClicked", 0, 0 };
    static const QUMethod slot_3 = {"slotRejectClicked", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_4 = {"slotJoinQunAuthReply", 2, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "slotQQClicked()", &slot_0, QMetaData::Private },
	{ "slotQunClicked()", &slot_1, QMetaData::Private },
	{ "slotOkClicked()", &slot_2, QMetaData::Private },
	{ "slotRejectClicked()", &slot_3, QMetaData::Private },
	{ "slotJoinQunAuthReply(const unsigned int,const unsigned char)", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestDetails", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestQunDetails", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "requestDetails(const unsigned int)", &signal_0, QMetaData::Public },
	{ "requestQunDetails(const unsigned int)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaQunSysMsgWindow", parentObject,
	slot_tbl, 5,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaQunSysMsgWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaQunSysMsgWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaQunSysMsgWindow" ) )
	return this;
    return EvaQunSysMsgUIBase::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestDetails
void EvaQunSysMsgWindow::requestDetails( const unsigned int t0 )
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

// SIGNAL requestQunDetails
void EvaQunSysMsgWindow::requestQunDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaQunSysMsgWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotQQClicked(); break;
    case 1: slotQunClicked(); break;
    case 2: slotOkClicked(); break;
    case 3: slotRejectClicked(); break;
    case 4: slotJoinQunAuthReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2)))); break;
    default:
	return EvaQunSysMsgUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaQunSysMsgWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: requestQunDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaQunSysMsgUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaQunSysMsgWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaQunSysMsgUIBase::qt_property( id, f, v);
}

bool EvaQunSysMsgWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
