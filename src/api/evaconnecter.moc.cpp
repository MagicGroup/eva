/****************************************************************************
** EvaConnecter meta object code from reading C++ file 'evaconnecter.h'
**
** Created: Tue Feb 8 23:56:13 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaconnecter.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaConnecter::className() const
{
    return "EvaConnecter";
}

QMetaObject *EvaConnecter::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaConnecter( "EvaConnecter", &EvaConnecter::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaConnecter::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaConnecter", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaConnecter::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaConnecter", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaConnecter::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"slotClientReady", 0, 0 };
    static const QUMethod slot_1 = {"isReadySlot", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "data", &static_QUType_charstar, 0, QUParameter::In },
	{ "len", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"processPacket", 2, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "len", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"dataCommingSlot", 1, param_slot_3 };
    static const QUMethod slot_4 = {"packetMonitor", 0, 0 };
    static const QUMethod slot_5 = {"clearAllPools", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "num", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"slotNetworkException", 1, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "slotClientReady()", &slot_0, QMetaData::Public },
	{ "isReadySlot()", &slot_1, QMetaData::Private },
	{ "processPacket(char*,int)", &slot_2, QMetaData::Private },
	{ "dataCommingSlot(int)", &slot_3, QMetaData::Private },
	{ "packetMonitor()", &slot_4, QMetaData::Private },
	{ "clearAllPools()", &slot_5, QMetaData::Private },
	{ "slotNetworkException(int)", &slot_6, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"isReady", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"networkException", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"packetException", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_3 = {"sendMessage", 2, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"sendQunMessage", 3, param_signal_4 };
    static const QUMethod signal_5 = {"newPacket", 0, 0 };
    static const QUMethod signal_6 = {"clientNotReady", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "isReady()", &signal_0, QMetaData::Public },
	{ "networkException(int)", &signal_1, QMetaData::Public },
	{ "packetException(int)", &signal_2, QMetaData::Public },
	{ "sendMessage(unsigned int,bool)", &signal_3, QMetaData::Public },
	{ "sendQunMessage(unsigned int,bool,QString)", &signal_4, QMetaData::Public },
	{ "newPacket()", &signal_5, QMetaData::Public },
	{ "clientNotReady()", &signal_6, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaConnecter", parentObject,
	slot_tbl, 7,
	signal_tbl, 7,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaConnecter.setMetaObject( metaObj );
    return metaObj;
}

void* EvaConnecter::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaConnecter" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL isReady
void EvaConnecter::isReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL networkException
void EvaConnecter::networkException( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL packetException
void EvaConnecter::packetException( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 2, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL sendMessage
void EvaConnecter::sendMessage( unsigned int t0, bool t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL sendQunMessage
void EvaConnecter::sendQunMessage( unsigned int t0, bool t1, QString t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL newPacket
void EvaConnecter::newPacket()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL clientNotReady
void EvaConnecter::clientNotReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 6 );
}

bool EvaConnecter::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotClientReady(); break;
    case 1: isReadySlot(); break;
    case 2: processPacket((char*)static_QUType_charstar.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 3: dataCommingSlot((int)static_QUType_int.get(_o+1)); break;
    case 4: packetMonitor(); break;
    case 5: clearAllPools(); break;
    case 6: slotNetworkException((int)static_QUType_int.get(_o+1)); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaConnecter::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: isReady(); break;
    case 1: networkException((int)static_QUType_int.get(_o+1)); break;
    case 2: packetException((int)static_QUType_int.get(_o+1)); break;
    case 3: sendMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 4: sendQunMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 5: newPacket(); break;
    case 6: clientNotReady(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaConnecter::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaConnecter::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
