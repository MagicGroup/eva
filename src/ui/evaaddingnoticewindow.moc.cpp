/****************************************************************************
** EvaAddingNoticeWindow meta object code from reading C++ file 'evaaddingnoticewindow.h'
**
** Created: Tue Feb 8 23:52:15 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaaddingnoticewindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaAddingNoticeWindow::className() const
{
    return "EvaAddingNoticeWindow";
}

QMetaObject *EvaAddingNoticeWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaAddingNoticeWindow( "EvaAddingNoticeWindow", &EvaAddingNoticeWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaAddingNoticeWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAddingNoticeWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaAddingNoticeWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAddingNoticeWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaAddingNoticeWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaAddingNoticeUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotFaceClicked", 0, 0 };
    static const QUMethod slot_1 = {"slotOkClicked", 0, 0 };
    static const QUMethod slot_2 = {"processAddingRequest", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "ok", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotAddAuthActionReply", 3, param_slot_3 };
    static const QUMethod slot_4 = {"slotRejectClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotFaceClicked()", &slot_0, QMetaData::Private },
	{ "slotOkClicked()", &slot_1, QMetaData::Private },
	{ "processAddingRequest()", &slot_2, QMetaData::Private },
	{ "slotAddAuthActionReply(const unsigned int,const unsigned char,const bool)", &slot_3, QMetaData::Private },
	{ "slotRejectClicked()", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestDetails", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "face", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestAddBuddy", 3, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "requestDetails(const unsigned int)", &signal_0, QMetaData::Public },
	{ "requestAddBuddy(const unsigned int,const QString,const unsigned short)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaAddingNoticeWindow", parentObject,
	slot_tbl, 5,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaAddingNoticeWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaAddingNoticeWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaAddingNoticeWindow" ) )
	return this;
    return EvaAddingNoticeUIBase::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestDetails
void EvaAddingNoticeWindow::requestDetails( const unsigned int t0 )
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

// SIGNAL requestAddBuddy
void EvaAddingNoticeWindow::requestAddBuddy( const unsigned int t0, const QString t1, const unsigned short t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    activate_signal( clist, o );
}

bool EvaAddingNoticeWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotFaceClicked(); break;
    case 1: slotOkClicked(); break;
    case 2: processAddingRequest(); break;
    case 3: slotAddAuthActionReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3)); break;
    case 4: slotRejectClicked(); break;
    default:
	return EvaAddingNoticeUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaAddingNoticeWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: requestAddBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+3)))); break;
    default:
	return EvaAddingNoticeUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaAddingNoticeWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaAddingNoticeUIBase::qt_property( id, f, v);
}

bool EvaAddingNoticeWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
