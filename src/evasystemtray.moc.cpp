/****************************************************************************
** EvaSystemTray meta object code from reading C++ file 'evasystemtray.h'
**
** Created: Tue Feb 8 23:56:31 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evasystemtray.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaSystemTray::className() const
{
    return "EvaSystemTray";
}

QMetaObject *EvaSystemTray::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaSystemTray( "EvaSystemTray", &EvaSystemTray::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaSystemTray::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSystemTray", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaSystemTray::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSystemTray", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaSystemTray::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = KSystemTray::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "face", &static_QUType_ptr, "short", QUParameter::In }
    };
    static const QUMethod slot_0 = {"changeToolTip", 3, param_slot_0 };
    static const QUMethod slot_1 = {"setOnline", 0, 0 };
    static const QUMethod slot_2 = {"setOffline", 0, 0 };
    static const QUMethod slot_3 = {"setLeave", 0, 0 };
    static const QUMethod slot_4 = {"setInvisible", 0, 0 };
    static const QUMethod slot_5 = {"setLoginWaiting", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_6 = {"newTxtMessage", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "face", &static_QUType_ptr, "short", QUParameter::In }
    };
    static const QUMethod slot_7 = {"newTxtMessage", 2, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_8 = {"gotTxtMessage", 1, param_slot_8 };
    static const QUMethod slot_9 = {"newSysMessage", 0, 0 };
    static const QUMethod slot_10 = {"gotSysMessage", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_11 = {"getSenderID", 1, param_slot_11 };
    static const QUMethod slot_12 = {"slotTimeout", 0, 0 };
    static const QUMethod slot_13 = {"slotClickTimeout", 0, 0 };
    static const QUMethod slot_14 = {"minMaxAction", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "changeToolTip(const unsigned int,const QString&,const short)", &slot_0, QMetaData::Public },
	{ "setOnline()", &slot_1, QMetaData::Public },
	{ "setOffline()", &slot_2, QMetaData::Public },
	{ "setLeave()", &slot_3, QMetaData::Public },
	{ "setInvisible()", &slot_4, QMetaData::Public },
	{ "setLoginWaiting()", &slot_5, QMetaData::Public },
	{ "newTxtMessage(const unsigned int)", &slot_6, QMetaData::Public },
	{ "newTxtMessage(const unsigned int,short)", &slot_7, QMetaData::Public },
	{ "gotTxtMessage(const unsigned int)", &slot_8, QMetaData::Public },
	{ "newSysMessage()", &slot_9, QMetaData::Public },
	{ "gotSysMessage()", &slot_10, QMetaData::Public },
	{ "getSenderID()", &slot_11, QMetaData::Public },
	{ "slotTimeout()", &slot_12, QMetaData::Private },
	{ "slotClickTimeout()", &slot_13, QMetaData::Private },
	{ "minMaxAction()", &slot_14, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestChat", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestQunChat", 1, param_signal_1 };
    static const QUMethod signal_2 = {"requestSystemMessage", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "requestChat(const unsigned int)", &signal_0, QMetaData::Public },
	{ "requestQunChat(const unsigned int)", &signal_1, QMetaData::Public },
	{ "requestSystemMessage()", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaSystemTray", parentObject,
	slot_tbl, 15,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaSystemTray.setMetaObject( metaObj );
    return metaObj;
}

void* EvaSystemTray::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaSystemTray" ) )
	return this;
    return KSystemTray::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestChat
void EvaSystemTray::requestChat( const unsigned int t0 )
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

// SIGNAL requestQunChat
void EvaSystemTray::requestQunChat( const unsigned int t0 )
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

// SIGNAL requestSystemMessage
void EvaSystemTray::requestSystemMessage()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

bool EvaSystemTray::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: changeToolTip((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString&)static_QUType_QString.get(_o+2),(const short)(*((const short*)static_QUType_ptr.get(_o+3)))); break;
    case 1: setOnline(); break;
    case 2: setOffline(); break;
    case 3: setLeave(); break;
    case 4: setInvisible(); break;
    case 5: setLoginWaiting(); break;
    case 6: newTxtMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 7: newTxtMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(short)(*((short*)static_QUType_ptr.get(_o+2)))); break;
    case 8: gotTxtMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 9: newSysMessage(); break;
    case 10: gotSysMessage(); break;
    case 11: static_QUType_int.set(_o,getSenderID()); break;
    case 12: slotTimeout(); break;
    case 13: slotClickTimeout(); break;
    case 14: minMaxAction(); break;
    default:
	return KSystemTray::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaSystemTray::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: requestQunChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: requestSystemMessage(); break;
    default:
	return KSystemTray::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaSystemTray::qt_property( int id, int f, QVariant* v)
{
    return KSystemTray::qt_property( id, f, v);
}

bool EvaSystemTray::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
