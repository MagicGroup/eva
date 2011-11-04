/****************************************************************************
** EvaQunBuddyItem meta object code from reading C++ file 'evaqunlistview.h'
**
** Created: Tue Feb 8 23:53:32 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaqunlistview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaQunBuddyItem::className() const
{
    return "EvaQunBuddyItem";
}

QMetaObject *EvaQunBuddyItem::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaQunBuddyItem( "EvaQunBuddyItem", &EvaQunBuddyItem::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaQunBuddyItem::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunBuddyItem", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaQunBuddyItem::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunBuddyItem", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaQunBuddyItem::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"EvaQunBuddyItem", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaQunBuddyItem.setMetaObject( metaObj );
    return metaObj;
}

void* EvaQunBuddyItem::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaQunBuddyItem" ) )
	return this;
    if ( !qstrcmp( clname, "QListViewItem" ) )
	return (QListViewItem*)this;
    return QObject::qt_cast( clname );
}

bool EvaQunBuddyItem::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool EvaQunBuddyItem::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaQunBuddyItem::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaQunBuddyItem::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaQunListView::className() const
{
    return "EvaQunListView";
}

QMetaObject *EvaQunListView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaQunListView( "EvaQunListView", &EvaQunListView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaQunListView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunListView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaQunListView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunListView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaQunListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QListView::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotContextMenu", 3, param_slot_0 };
    static const QUMethod slot_1 = {"slotDetails", 0, 0 };
    static const QUMethod slot_2 = {"slotDoRefreshMembers", 0, 0 };
    static const QUMethod slot_3 = {"slotQunCard", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"slotBuddyDoubleClick", 3, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "slotContextMenu(QListViewItem*,const QPoint&,int)", &slot_0, QMetaData::Private },
	{ "slotDetails()", &slot_1, QMetaData::Private },
	{ "slotDoRefreshMembers()", &slot_2, QMetaData::Private },
	{ "slotQunCard()", &slot_3, QMetaData::Private },
	{ "slotBuddyDoubleClick(QListViewItem*,const QPoint&,int)", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestBuddyInfo", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestQunCard", 1, param_signal_1 };
    static const QUMethod signal_2 = {"requestQunMembers", 0, 0 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_3 = {"requestChat", 1, param_signal_3 };
    static const QMetaData signal_tbl[] = {
	{ "requestBuddyInfo(const unsigned int)", &signal_0, QMetaData::Public },
	{ "requestQunCard(const unsigned int)", &signal_1, QMetaData::Public },
	{ "requestQunMembers()", &signal_2, QMetaData::Public },
	{ "requestChat(const unsigned int)", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaQunListView", parentObject,
	slot_tbl, 5,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaQunListView.setMetaObject( metaObj );
    return metaObj;
}

void* EvaQunListView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaQunListView" ) )
	return this;
    return QListView::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestBuddyInfo
void EvaQunListView::requestBuddyInfo( const unsigned int t0 )
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

// SIGNAL requestQunCard
void EvaQunListView::requestQunCard( const unsigned int t0 )
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

// SIGNAL requestQunMembers
void EvaQunListView::requestQunMembers()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL requestChat
void EvaQunListView::requestChat( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaQunListView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotContextMenu((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 1: slotDetails(); break;
    case 2: slotDoRefreshMembers(); break;
    case 3: slotQunCard(); break;
    case 4: slotBuddyDoubleClick((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    default:
	return QListView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaQunListView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestBuddyInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: requestQunCard((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: requestQunMembers(); break;
    case 3: requestChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QListView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaQunListView::qt_property( int id, int f, QVariant* v)
{
    return QListView::qt_property( id, f, v);
}

bool EvaQunListView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
