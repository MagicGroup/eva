/****************************************************************************
** EvaContactListView meta object code from reading C++ file 'evacontactlistview.h'
**
** Created: Tue Feb 8 23:53:03 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evacontactlistview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaContactListView::className() const
{
    return "EvaContactListView";
}

QMetaObject *EvaContactListView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaContactListView( "EvaContactListView", &EvaContactListView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaContactListView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaContactListView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaContactListView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaContactListView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaContactListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaListView::staticMetaObject();
    static const QUMethod slot_0 = {"showAll", 0, 0 };
    static const QUMethod slot_1 = {"showOnlineOnly", 0, 0 };
    static const QUMethod slot_2 = {"closeAllGroups", 0, 0 };
    static const QUMethod slot_3 = {"openAllGroups", 0, 0 };
    static const QUMethod slot_4 = {"updateAllGroups", 0, 0 };
    static const QUMethod slot_5 = {"slotRenameGroup", 0, 0 };
    static const QUMethod slot_6 = {"slotNewGroup", 0, 0 };
    static const QUMethod slot_7 = {"slotDelGroup", 0, 0 };
    static const QUMethod slot_8 = {"slotIMChat", 0, 0 };
    static const QUMethod slot_9 = {"slotSendFile", 0, 0 };
    static const QUMethod slot_10 = {"slotUpdataLevel", 0, 0 };
    static const QUMethod slot_11 = {"slotDetails", 0, 0 };
    static const QUMethod slot_12 = {"slotHistory", 0, 0 };
    static const QUMethod slot_13 = {"slotDelBuddy", 0, 0 };
    static const QUMethod slot_14 = {"slotModifyMemo", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"slotItemRenamed", 2, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"slotContextMenu", 3, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"slotBuddyDoubleClick", 3, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_18 = {"slotListViewClicked", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"friendStatusChanged", 1, param_slot_19 };
    static const QUMethod slot_20 = {"slotFaceSizeChanged", 0, 0 };
    static const QUParameter param_slot_21[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_21 = {"buddyAdded", 1, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_22 = {"newMessage", 1, param_slot_22 };
    static const QUParameter param_slot_23[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_23 = {"getMessage", 1, param_slot_23 };
    static const QMetaData slot_tbl[] = {
	{ "showAll()", &slot_0, QMetaData::Private },
	{ "showOnlineOnly()", &slot_1, QMetaData::Private },
	{ "closeAllGroups()", &slot_2, QMetaData::Private },
	{ "openAllGroups()", &slot_3, QMetaData::Private },
	{ "updateAllGroups()", &slot_4, QMetaData::Private },
	{ "slotRenameGroup()", &slot_5, QMetaData::Private },
	{ "slotNewGroup()", &slot_6, QMetaData::Private },
	{ "slotDelGroup()", &slot_7, QMetaData::Private },
	{ "slotIMChat()", &slot_8, QMetaData::Private },
	{ "slotSendFile()", &slot_9, QMetaData::Private },
	{ "slotUpdataLevel()", &slot_10, QMetaData::Private },
	{ "slotDetails()", &slot_11, QMetaData::Private },
	{ "slotHistory()", &slot_12, QMetaData::Private },
	{ "slotDelBuddy()", &slot_13, QMetaData::Private },
	{ "slotModifyMemo()", &slot_14, QMetaData::Private },
	{ "slotItemRenamed(QListViewItem*,int)", &slot_15, QMetaData::Private },
	{ "slotContextMenu(QListViewItem*,const QPoint&,int)", &slot_16, QMetaData::Private },
	{ "slotBuddyDoubleClick(QListViewItem*,const QPoint&,int)", &slot_17, QMetaData::Private },
	{ "slotListViewClicked(QListViewItem*)", &slot_18, QMetaData::Private },
	{ "friendStatusChanged(const int)", &slot_19, QMetaData::Public },
	{ "slotFaceSizeChanged()", &slot_20, QMetaData::Public },
	{ "buddyAdded(const unsigned int)", &slot_21, QMetaData::Public },
	{ "newMessage(const unsigned int)", &slot_22, QMetaData::Public },
	{ "getMessage(const unsigned int)", &slot_23, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"groupDeleted", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"groupRenamed", 2, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"groupChanged", 2, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_3 = {"deleteMeFrom", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_4 = {"requestChat", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_5 = {"requestSendFile", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_6 = {"requestLevel", 1, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_7 = {"requestDetails", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_8 = {"requestHistory", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_9 = {"requestModifyMemo", 1, param_signal_9 };
    static const QUParameter param_signal_10[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_10 = {"requestDelete", 1, param_signal_10 };
    static const QMetaData signal_tbl[] = {
	{ "groupDeleted(const int)", &signal_0, QMetaData::Public },
	{ "groupRenamed(QString,int)", &signal_1, QMetaData::Public },
	{ "groupChanged(const unsigned int,int)", &signal_2, QMetaData::Public },
	{ "deleteMeFrom(const unsigned int)", &signal_3, QMetaData::Public },
	{ "requestChat(const unsigned int)", &signal_4, QMetaData::Public },
	{ "requestSendFile(const unsigned int)", &signal_5, QMetaData::Public },
	{ "requestLevel(const unsigned int)", &signal_6, QMetaData::Public },
	{ "requestDetails(const unsigned int)", &signal_7, QMetaData::Public },
	{ "requestHistory(const unsigned int)", &signal_8, QMetaData::Public },
	{ "requestModifyMemo(const unsigned int)", &signal_9, QMetaData::Public },
	{ "requestDelete(const unsigned int)", &signal_10, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaContactListView", parentObject,
	slot_tbl, 24,
	signal_tbl, 11,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaContactListView.setMetaObject( metaObj );
    return metaObj;
}

void* EvaContactListView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaContactListView" ) )
	return this;
    return EvaListView::qt_cast( clname );
}

// SIGNAL groupDeleted
void EvaContactListView::groupDeleted( const int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL groupRenamed
void EvaContactListView::groupRenamed( QString t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL groupChanged
void EvaContactListView::groupChanged( const unsigned int t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL deleteMeFrom
void EvaContactListView::deleteMeFrom( const unsigned int t0 )
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

// SIGNAL requestChat
void EvaContactListView::requestChat( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestSendFile
void EvaContactListView::requestSendFile( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestLevel
void EvaContactListView::requestLevel( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestDetails
void EvaContactListView::requestDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestHistory
void EvaContactListView::requestHistory( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestModifyMemo
void EvaContactListView::requestModifyMemo( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestDelete
void EvaContactListView::requestDelete( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 10 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaContactListView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: showAll(); break;
    case 1: showOnlineOnly(); break;
    case 2: closeAllGroups(); break;
    case 3: openAllGroups(); break;
    case 4: updateAllGroups(); break;
    case 5: slotRenameGroup(); break;
    case 6: slotNewGroup(); break;
    case 7: slotDelGroup(); break;
    case 8: slotIMChat(); break;
    case 9: slotSendFile(); break;
    case 10: slotUpdataLevel(); break;
    case 11: slotDetails(); break;
    case 12: slotHistory(); break;
    case 13: slotDelBuddy(); break;
    case 14: slotModifyMemo(); break;
    case 15: slotItemRenamed((QListViewItem*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 16: slotContextMenu((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 17: slotBuddyDoubleClick((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 18: slotListViewClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 19: friendStatusChanged((const int)static_QUType_int.get(_o+1)); break;
    case 20: slotFaceSizeChanged(); break;
    case 21: buddyAdded((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 22: newMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 23: getMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaListView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaContactListView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: groupDeleted((const int)static_QUType_int.get(_o+1)); break;
    case 1: groupRenamed((QString)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 2: groupChanged((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(int)static_QUType_int.get(_o+2)); break;
    case 3: deleteMeFrom((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 4: requestChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 5: requestSendFile((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 6: requestLevel((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 7: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 8: requestHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 9: requestModifyMemo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 10: requestDelete((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaListView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaContactListView::qt_property( int id, int f, QVariant* v)
{
    return EvaListView::qt_property( id, f, v);
}

bool EvaContactListView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaQunsListView::className() const
{
    return "EvaQunsListView";
}

QMetaObject *EvaQunsListView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaQunsListView( "EvaQunsListView", &EvaQunsListView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaQunsListView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunsListView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaQunsListView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunsListView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaQunsListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaListView::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotContextMenu", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotQunDoubleClick", 3, param_slot_1 };
    static const QUMethod slot_2 = {"slotIMQunChat", 0, 0 };
    static const QUMethod slot_3 = {"slotQunDetails", 0, 0 };
    static const QUMethod slot_4 = {"slotQunHistory", 0, 0 };
    static const QUMethod slot_5 = {"slotQunExit", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_6 = {"newMessage", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_7 = {"getMessage", 1, param_slot_7 };
    static const QMetaData slot_tbl[] = {
	{ "slotContextMenu(QListViewItem*,const QPoint&,int)", &slot_0, QMetaData::Private },
	{ "slotQunDoubleClick(QListViewItem*,const QPoint&,int)", &slot_1, QMetaData::Private },
	{ "slotIMQunChat()", &slot_2, QMetaData::Private },
	{ "slotQunDetails()", &slot_3, QMetaData::Private },
	{ "slotQunHistory()", &slot_4, QMetaData::Private },
	{ "slotQunExit()", &slot_5, QMetaData::Private },
	{ "newMessage(const unsigned int)", &slot_6, QMetaData::Public },
	{ "getMessage(const unsigned int)", &slot_7, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestQunChat", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestQunDetails", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestQunExit", 1, param_signal_2 };
    static const QUMethod signal_3 = {"requestQunCreate", 0, 0 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_4 = {"requestQunHistory", 1, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "requestQunChat(const unsigned int)", &signal_0, QMetaData::Public },
	{ "requestQunDetails(const unsigned int)", &signal_1, QMetaData::Public },
	{ "requestQunExit(const unsigned int)", &signal_2, QMetaData::Public },
	{ "requestQunCreate()", &signal_3, QMetaData::Public },
	{ "requestQunHistory(const unsigned int)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaQunsListView", parentObject,
	slot_tbl, 8,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaQunsListView.setMetaObject( metaObj );
    return metaObj;
}

void* EvaQunsListView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaQunsListView" ) )
	return this;
    return EvaListView::qt_cast( clname );
}

// SIGNAL requestQunChat
void EvaQunsListView::requestQunChat( const unsigned int t0 )
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
void EvaQunsListView::requestQunDetails( const unsigned int t0 )
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

// SIGNAL requestQunExit
void EvaQunsListView::requestQunExit( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunCreate
void EvaQunsListView::requestQunCreate()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL requestQunHistory
void EvaQunsListView::requestQunHistory( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaQunsListView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotContextMenu((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 1: slotQunDoubleClick((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 2: slotIMQunChat(); break;
    case 3: slotQunDetails(); break;
    case 4: slotQunHistory(); break;
    case 5: slotQunExit(); break;
    case 6: newMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 7: getMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaListView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaQunsListView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestQunChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: requestQunDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: requestQunExit((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: requestQunCreate(); break;
    case 4: requestQunHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaListView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaQunsListView::qt_property( int id, int f, QVariant* v)
{
    return EvaListView::qt_property( id, f, v);
}

bool EvaQunsListView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *EvaRecentContactsListView::className() const
{
    return "EvaRecentContactsListView";
}

QMetaObject *EvaRecentContactsListView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaRecentContactsListView( "EvaRecentContactsListView", &EvaRecentContactsListView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaRecentContactsListView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaRecentContactsListView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaRecentContactsListView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaRecentContactsListView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaRecentContactsListView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaListView::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotContextMenu", 3, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotContactDoubleClick", 3, param_slot_1 };
    static const QUMethod slot_2 = {"slotIMChat", 0, 0 };
    static const QUMethod slot_3 = {"slotSendFile", 0, 0 };
    static const QUMethod slot_4 = {"slotUpdataLevel", 0, 0 };
    static const QUMethod slot_5 = {"slotDetails", 0, 0 };
    static const QUMethod slot_6 = {"slotHistory", 0, 0 };
    static const QUMethod slot_7 = {"slotDelBuddy", 0, 0 };
    static const QUMethod slot_8 = {"slotModifyMemo", 0, 0 };
    static const QUMethod slot_9 = {"slotIMQunChat", 0, 0 };
    static const QUMethod slot_10 = {"slotQunDetails", 0, 0 };
    static const QUMethod slot_11 = {"slotQunHistory", 0, 0 };
    static const QUMethod slot_12 = {"slotQunExit", 0, 0 };
    static const QUParameter param_slot_13[] = {
	{ 0, &static_QUType_ptr, "EvaRecentContactLVItem", QUParameter::Out },
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_13 = {"addBuddy", 2, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_ptr, "EvaRecentContactLVItem", QUParameter::Out },
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "time", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_14 = {"addBuddy", 3, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ 0, &static_QUType_ptr, "EvaRecentContactLVItem", QUParameter::Out },
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_15 = {"addQun", 2, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_ptr, "EvaRecentContactLVItem", QUParameter::Out },
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "time", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_16 = {"addQun", 3, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_17 = {"newMessage", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isMyWord", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"newMessage", 2, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isMyWord", &static_QUType_bool, 0, QUParameter::In },
	{ "time", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_19 = {"newMessage", 3, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_20 = {"newQunMessage", 1, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isMyWord", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"newQunMessage", 2, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isMyWord", &static_QUType_bool, 0, QUParameter::In },
	{ "time", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_22 = {"newQunMessage", 3, param_slot_22 };
    static const QUParameter param_slot_23[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_23 = {"getMessage", 1, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_24 = {"getQunMessage", 1, param_slot_24 };
    static const QMetaData slot_tbl[] = {
	{ "slotContextMenu(QListViewItem*,const QPoint&,int)", &slot_0, QMetaData::Private },
	{ "slotContactDoubleClick(QListViewItem*,const QPoint&,int)", &slot_1, QMetaData::Private },
	{ "slotIMChat()", &slot_2, QMetaData::Private },
	{ "slotSendFile()", &slot_3, QMetaData::Private },
	{ "slotUpdataLevel()", &slot_4, QMetaData::Private },
	{ "slotDetails()", &slot_5, QMetaData::Private },
	{ "slotHistory()", &slot_6, QMetaData::Private },
	{ "slotDelBuddy()", &slot_7, QMetaData::Private },
	{ "slotModifyMemo()", &slot_8, QMetaData::Private },
	{ "slotIMQunChat()", &slot_9, QMetaData::Private },
	{ "slotQunDetails()", &slot_10, QMetaData::Private },
	{ "slotQunHistory()", &slot_11, QMetaData::Private },
	{ "slotQunExit()", &slot_12, QMetaData::Private },
	{ "addBuddy(const unsigned int)", &slot_13, QMetaData::Public },
	{ "addBuddy(const unsigned int,const unsigned int)", &slot_14, QMetaData::Public },
	{ "addQun(const unsigned int)", &slot_15, QMetaData::Public },
	{ "addQun(const unsigned int,const unsigned int)", &slot_16, QMetaData::Public },
	{ "newMessage(const unsigned int)", &slot_17, QMetaData::Public },
	{ "newMessage(const unsigned int,bool)", &slot_18, QMetaData::Public },
	{ "newMessage(const unsigned int,bool,const unsigned int)", &slot_19, QMetaData::Public },
	{ "newQunMessage(const unsigned int)", &slot_20, QMetaData::Public },
	{ "newQunMessage(const unsigned int,bool)", &slot_21, QMetaData::Public },
	{ "newQunMessage(const unsigned int,bool,const unsigned int)", &slot_22, QMetaData::Public },
	{ "getMessage(const unsigned int)", &slot_23, QMetaData::Public },
	{ "getQunMessage(const unsigned int)", &slot_24, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestChat", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestSendFile", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestLevel", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_3 = {"requestDetails", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_4 = {"requestHistory", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_5 = {"requestModifyMemo", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_6 = {"requestDelete", 1, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_7 = {"requestQunChat", 1, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_8 = {"requestQunDetails", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_9 = {"requestQunExit", 1, param_signal_9 };
    static const QUMethod signal_10 = {"requestQunCreate", 0, 0 };
    static const QUParameter param_signal_11[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_11 = {"requestQunHistory", 1, param_signal_11 };
    static const QMetaData signal_tbl[] = {
	{ "requestChat(const unsigned int)", &signal_0, QMetaData::Public },
	{ "requestSendFile(const unsigned int)", &signal_1, QMetaData::Public },
	{ "requestLevel(const unsigned int)", &signal_2, QMetaData::Public },
	{ "requestDetails(const unsigned int)", &signal_3, QMetaData::Public },
	{ "requestHistory(const unsigned int)", &signal_4, QMetaData::Public },
	{ "requestModifyMemo(const unsigned int)", &signal_5, QMetaData::Public },
	{ "requestDelete(const unsigned int)", &signal_6, QMetaData::Public },
	{ "requestQunChat(const unsigned int)", &signal_7, QMetaData::Public },
	{ "requestQunDetails(const unsigned int)", &signal_8, QMetaData::Public },
	{ "requestQunExit(const unsigned int)", &signal_9, QMetaData::Public },
	{ "requestQunCreate()", &signal_10, QMetaData::Public },
	{ "requestQunHistory(const unsigned int)", &signal_11, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaRecentContactsListView", parentObject,
	slot_tbl, 25,
	signal_tbl, 12,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaRecentContactsListView.setMetaObject( metaObj );
    return metaObj;
}

void* EvaRecentContactsListView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaRecentContactsListView" ) )
	return this;
    return EvaListView::qt_cast( clname );
}

// SIGNAL requestChat
void EvaRecentContactsListView::requestChat( const unsigned int t0 )
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

// SIGNAL requestSendFile
void EvaRecentContactsListView::requestSendFile( const unsigned int t0 )
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

// SIGNAL requestLevel
void EvaRecentContactsListView::requestLevel( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestDetails
void EvaRecentContactsListView::requestDetails( const unsigned int t0 )
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

// SIGNAL requestHistory
void EvaRecentContactsListView::requestHistory( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestModifyMemo
void EvaRecentContactsListView::requestModifyMemo( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestDelete
void EvaRecentContactsListView::requestDelete( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunChat
void EvaRecentContactsListView::requestQunChat( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunDetails
void EvaRecentContactsListView::requestQunDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunExit
void EvaRecentContactsListView::requestQunExit( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunCreate
void EvaRecentContactsListView::requestQunCreate()
{
    activate_signal( staticMetaObject()->signalOffset() + 10 );
}

// SIGNAL requestQunHistory
void EvaRecentContactsListView::requestQunHistory( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 11 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaRecentContactsListView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotContextMenu((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 1: slotContactDoubleClick((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2)),(int)static_QUType_int.get(_o+3)); break;
    case 2: slotIMChat(); break;
    case 3: slotSendFile(); break;
    case 4: slotUpdataLevel(); break;
    case 5: slotDetails(); break;
    case 6: slotHistory(); break;
    case 7: slotDelBuddy(); break;
    case 8: slotModifyMemo(); break;
    case 9: slotIMQunChat(); break;
    case 10: slotQunDetails(); break;
    case 11: slotQunHistory(); break;
    case 12: slotQunExit(); break;
    case 13: static_QUType_ptr.set(_o,addBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))))); break;
    case 14: static_QUType_ptr.set(_o,addBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))))); break;
    case 15: static_QUType_ptr.set(_o,addQun((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))))); break;
    case 16: static_QUType_ptr.set(_o,addQun((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))))); break;
    case 17: newMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 18: newMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 19: newMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3)))); break;
    case 20: newQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 21: newQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 22: newQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3)))); break;
    case 23: getMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 24: getQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaListView::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaRecentContactsListView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: requestSendFile((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: requestLevel((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 4: requestHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 5: requestModifyMemo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 6: requestDelete((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 7: requestQunChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 8: requestQunDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 9: requestQunExit((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 10: requestQunCreate(); break;
    case 11: requestQunHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaListView::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaRecentContactsListView::qt_property( int id, int f, QVariant* v)
{
    return EvaListView::qt_property( id, f, v);
}

bool EvaRecentContactsListView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
