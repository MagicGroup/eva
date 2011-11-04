/****************************************************************************
** EvaQunCreateWindow meta object code from reading C++ file 'evaquncreatewindow.h'
**
** Created: Tue Feb 8 23:52:25 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaquncreatewindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaQunCreateWindow::className() const
{
    return "EvaQunCreateWindow";
}

QMetaObject *EvaQunCreateWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaQunCreateWindow( "EvaQunCreateWindow", &EvaQunCreateWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaQunCreateWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunCreateWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaQunCreateWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunCreateWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaQunCreateWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QunCreateUI::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotQunCreateDone", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "msg", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotQunCreateFailed", 1, param_slot_1 };
    static const QUMethod slot_2 = {"slotNextClicked", 0, 0 };
    static const QUMethod slot_3 = {"slotPrevClicked", 0, 0 };
    static const QUMethod slot_4 = {"slotCancel", 0, 0 };
    static const QUMethod slot_5 = {"slotLoadMembers", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In },
	{ "button", &static_QUType_int, 0, QUParameter::In },
	{ "mousePos", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_6 = {"slotTableClicked", 4, param_slot_6 };
    static const QUMethod slot_7 = {"slotSetMembersClicked", 0, 0 };
    static const QUMethod slot_8 = {"slotDelMembersClicked", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isChecked", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"slotPickerMemberClicked", 2, param_slot_9 };
    static const QUMethod slot_10 = {"slotCategoryClicked", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_11 = {"slotCategorySelected", 1, param_slot_11 };
    static const QMetaData slot_tbl[] = {
	{ "slotQunCreateDone(const unsigned int)", &slot_0, QMetaData::Public },
	{ "slotQunCreateFailed(QString)", &slot_1, QMetaData::Public },
	{ "slotNextClicked()", &slot_2, QMetaData::Private },
	{ "slotPrevClicked()", &slot_3, QMetaData::Private },
	{ "slotCancel()", &slot_4, QMetaData::Private },
	{ "slotLoadMembers()", &slot_5, QMetaData::Private },
	{ "slotTableClicked(int,int,int,const QPoint&)", &slot_6, QMetaData::Private },
	{ "slotSetMembersClicked()", &slot_7, QMetaData::Private },
	{ "slotDelMembersClicked()", &slot_8, QMetaData::Private },
	{ "slotPickerMemberClicked(const unsigned int,const bool)", &slot_9, QMetaData::Private },
	{ "slotCategoryClicked()", &slot_10, QMetaData::Private },
	{ "slotCategorySelected(const unsigned short)", &slot_11, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "name", &static_QUType_QString, 0, QUParameter::In },
	{ "category", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "notice", &static_QUType_QString, 0, QUParameter::In },
	{ "description", &static_QUType_QString, 0, QUParameter::In },
	{ "members", &static_QUType_ptr, "std::list<unsigned int>", QUParameter::In }
    };
    static const QUMethod signal_0 = {"doQunCreate", 6, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"removeMember", 1, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "doQunCreate(const QString&,const unsigned short,const unsigned char,const QString&,const QString&,const std::list<unsigned int>&)", &signal_0, QMetaData::Public },
	{ "removeMember(const unsigned int)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaQunCreateWindow", parentObject,
	slot_tbl, 12,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaQunCreateWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaQunCreateWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaQunCreateWindow" ) )
	return this;
    return QunCreateUI::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL doQunCreate
void EvaQunCreateWindow::doQunCreate( const QString& t0, const unsigned short t1, const unsigned char t2, const QString& t3, const QString& t4, const std::list<unsigned int>& t5 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[7];
    static_QUType_QString.set(o+1,t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_QString.set(o+4,t3);
    static_QUType_QString.set(o+5,t4);
    static_QUType_ptr.set(o+6,&t5);
    activate_signal( clist, o );
}

// SIGNAL removeMember
void EvaQunCreateWindow::removeMember( const unsigned int t0 )
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

bool EvaQunCreateWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotQunCreateDone((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: slotQunCreateFailed((QString)static_QUType_QString.get(_o+1)); break;
    case 2: slotNextClicked(); break;
    case 3: slotPrevClicked(); break;
    case 4: slotCancel(); break;
    case 5: slotLoadMembers(); break;
    case 6: slotTableClicked((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2),(int)static_QUType_int.get(_o+3),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+4))); break;
    case 7: slotSetMembersClicked(); break;
    case 8: slotDelMembersClicked(); break;
    case 9: slotPickerMemberClicked((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2)); break;
    case 10: slotCategoryClicked(); break;
    case 11: slotCategorySelected((const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QunCreateUI::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaQunCreateWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: doQunCreate((const QString&)static_QUType_QString.get(_o+1),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+2))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+3))),(const QString&)static_QUType_QString.get(_o+4),(const QString&)static_QUType_QString.get(_o+5),(const std::list<unsigned int>&)*((const std::list<unsigned int>*)static_QUType_ptr.get(_o+6))); break;
    case 1: removeMember((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QunCreateUI::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaQunCreateWindow::qt_property( int id, int f, QVariant* v)
{
    return QunCreateUI::qt_property( id, f, v);
}

bool EvaQunCreateWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
