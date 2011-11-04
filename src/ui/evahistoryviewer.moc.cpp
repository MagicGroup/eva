/****************************************************************************
** EvaHistoryViewer meta object code from reading C++ file 'evahistoryviewer.h'
**
** Created: Tue Feb 8 23:52:58 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evahistoryviewer.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaHistoryViewer::className() const
{
    return "EvaHistoryViewer";
}

QMetaObject *EvaHistoryViewer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaHistoryViewer( "EvaHistoryViewer", &EvaHistoryViewer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaHistoryViewer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaHistoryViewer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaHistoryViewer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaHistoryViewer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaHistoryViewer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaHistoryUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotChbSelectClick", 0, 0 };
    static const QUMethod slot_1 = {"slotPbShowClick", 0, 0 };
    static const QUMethod slot_2 = {"slotPbPrevClick", 0, 0 };
    static const QUMethod slot_3 = {"slotPbNextClick", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"slotTblDisplayDoubleClick", 1, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "slotChbSelectClick()", &slot_0, QMetaData::Private },
	{ "slotPbShowClick()", &slot_1, QMetaData::Private },
	{ "slotPbPrevClick()", &slot_2, QMetaData::Private },
	{ "slotPbNextClick()", &slot_3, QMetaData::Private },
	{ "slotTblDisplayDoubleClick(int)", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In },
	{ "red", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod signal_0 = {"historyDoubleClicked", 14, param_signal_0 };
    static const QUMethod signal_1 = {"windowClosed", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "historyDoubleClicked(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &signal_0, QMetaData::Public },
	{ "windowClosed()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaHistoryViewer", parentObject,
	slot_tbl, 5,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaHistoryViewer.setMetaObject( metaObj );
    return metaObj;
}

void* EvaHistoryViewer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaHistoryViewer" ) )
	return this;
    return EvaHistoryUIBase::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL historyDoubleClicked
void EvaHistoryViewer::historyDoubleClicked( unsigned int t0, QString t1, unsigned int t2, QString t3, bool t4, QString t5, QDateTime t6, const char t7, const bool t8, const bool t9, const bool t10, const char t11, const char t12, const char t13 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[15];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_QString.set(o+4,t3);
    static_QUType_bool.set(o+5,t4);
    static_QUType_QString.set(o+6,t5);
    static_QUType_varptr.set(o+7,&t6);
    static_QUType_ptr.set(o+8,&t7);
    static_QUType_bool.set(o+9,t8);
    static_QUType_bool.set(o+10,t9);
    static_QUType_bool.set(o+11,t10);
    static_QUType_ptr.set(o+12,&t11);
    static_QUType_ptr.set(o+13,&t12);
    static_QUType_ptr.set(o+14,&t13);
    activate_signal( clist, o );
}

// SIGNAL windowClosed
void EvaHistoryViewer::windowClosed()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool EvaHistoryViewer::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotChbSelectClick(); break;
    case 1: slotPbShowClick(); break;
    case 2: slotPbPrevClick(); break;
    case 3: slotPbNextClick(); break;
    case 4: slotTblDisplayDoubleClick((int)static_QUType_int.get(_o+1)); break;
    default:
	return EvaHistoryUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaHistoryViewer::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: historyDoubleClicked((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10),(const bool)static_QUType_bool.get(_o+11),(const char)(*((const char*)static_QUType_ptr.get(_o+12))),(const char)(*((const char*)static_QUType_ptr.get(_o+13))),(const char)(*((const char*)static_QUType_ptr.get(_o+14)))); break;
    case 1: windowClosed(); break;
    default:
	return EvaHistoryUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaHistoryViewer::qt_property( int id, int f, QVariant* v)
{
    return EvaHistoryUIBase::qt_property( id, f, v);
}

bool EvaHistoryViewer::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
