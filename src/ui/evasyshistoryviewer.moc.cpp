/****************************************************************************
** EvaSysHistoryViewer meta object code from reading C++ file 'evasyshistoryviewer.h'
**
** Created: Tue Feb 8 23:52:05 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evasyshistoryviewer.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaSysHistoryViewer::className() const
{
    return "EvaSysHistoryViewer";
}

QMetaObject *EvaSysHistoryViewer::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaSysHistoryViewer( "EvaSysHistoryViewer", &EvaSysHistoryViewer::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaSysHistoryViewer::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSysHistoryViewer", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaSysHistoryViewer::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSysHistoryViewer", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaSysHistoryViewer::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaHistoryUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotPbPrevClick", 0, 0 };
    static const QUMethod slot_1 = {"slotPbNextClick", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotTblDisplayDoubleClick", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "slotPbPrevClick()", &slot_0, QMetaData::Private },
	{ "slotPbNextClick()", &slot_1, QMetaData::Private },
	{ "slotTblDisplayDoubleClick(int)", &slot_2, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "imType", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "type", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "fromQQ", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "toQQ", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "qunID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "commander", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "codeLen", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "token", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "tokenLen", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod signal_0 = {"historyDoubleClicked", 11, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "historyDoubleClicked(const unsigned short,const unsigned char,const unsigned int,const unsigned int,const QString,const unsigned int,const unsigned int,const unsigned char*,const unsigned short,const unsigned char*,const unsigned short)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaSysHistoryViewer", parentObject,
	slot_tbl, 3,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaSysHistoryViewer.setMetaObject( metaObj );
    return metaObj;
}

void* EvaSysHistoryViewer::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaSysHistoryViewer" ) )
	return this;
    return EvaHistoryUIBase::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL historyDoubleClicked
void EvaSysHistoryViewer::historyDoubleClicked( const unsigned short t0, const unsigned char t1, const unsigned int t2, const unsigned int t3, const QString t4, const unsigned int t5, const unsigned int t6, const unsigned char* t7, const unsigned short t8, const unsigned char* t9, const unsigned short t10 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[12];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    static_QUType_QString.set(o+5,t4);
    static_QUType_ptr.set(o+6,&t5);
    static_QUType_ptr.set(o+7,&t6);
    static_QUType_ptr.set(o+8,t7);
    static_QUType_ptr.set(o+9,&t8);
    static_QUType_ptr.set(o+10,t9);
    static_QUType_ptr.set(o+11,&t10);
    activate_signal( clist, o );
}

bool EvaSysHistoryViewer::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotPbPrevClick(); break;
    case 1: slotPbNextClick(); break;
    case 2: slotTblDisplayDoubleClick((int)static_QUType_int.get(_o+1)); break;
    default:
	return EvaHistoryUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaSysHistoryViewer::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: historyDoubleClicked((const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const QString)static_QUType_QString.get(_o+5),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+6))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+7))),(const unsigned char*)static_QUType_ptr.get(_o+8),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+9))),(const unsigned char*)static_QUType_ptr.get(_o+10),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+11)))); break;
    default:
	return EvaHistoryUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaSysHistoryViewer::qt_property( int id, int f, QVariant* v)
{
    return EvaHistoryUIBase::qt_property( id, f, v);
}

bool EvaSysHistoryViewer::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
