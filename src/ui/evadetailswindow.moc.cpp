/****************************************************************************
** EvaDetailsWindow meta object code from reading C++ file 'evadetailswindow.h'
**
** Created: Tue Feb 8 23:52:13 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evadetailswindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaDetailsWindow::className() const
{
    return "EvaDetailsWindow";
}

QMetaObject *EvaDetailsWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaDetailsWindow( "EvaDetailsWindow", &EvaDetailsWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaDetailsWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaDetailsWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaDetailsWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaDetailsWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaDetailsWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaUserUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotUpdateClick", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "list", &static_QUType_varptr, "\x04", QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotDetailsUpdated", 1, param_slot_1 };
    static const QUMethod slot_2 = {"slotUpdateQQShow", 0, 0 };
    static const QUMethod slot_3 = {"slotFirstUpdate", 0, 0 };
    static const QUMethod slot_4 = {"slotShopClicked", 0, 0 };
    static const QUMethod slot_5 = {"slotAlbumClicked", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ "url", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"slotLinkClicked", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_7 = {"slotBuddyQQShowReady", 1, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "wCurrentPage", &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_8 = {"slotCurrentChanged", 1, param_slot_8 };
    static const QUMethod slot_9 = {"slotDownloadMemo", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "memo", &static_QUType_ptr, "MemoItem", QUParameter::In }
    };
    static const QUMethod slot_10 = {"slotUpdateMemo", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"slotUploadMemoReply", 1, param_slot_11 };
    static const QUMethod slot_12 = {"slotNoMemoFound", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotUpdateClick()", &slot_0, QMetaData::Public },
	{ "slotDetailsUpdated(QStringList)", &slot_1, QMetaData::Public },
	{ "slotUpdateQQShow()", &slot_2, QMetaData::Public },
	{ "slotFirstUpdate()", &slot_3, QMetaData::Public },
	{ "slotShopClicked()", &slot_4, QMetaData::Public },
	{ "slotAlbumClicked()", &slot_5, QMetaData::Public },
	{ "slotLinkClicked(const QString&)", &slot_6, QMetaData::Public },
	{ "slotBuddyQQShowReady(const unsigned int)", &slot_7, QMetaData::Public },
	{ "slotCurrentChanged(QWidget*)", &slot_8, QMetaData::Public },
	{ "slotDownloadMemo()", &slot_9, QMetaData::Public },
	{ "slotUpdateMemo(const MemoItem&)", &slot_10, QMetaData::Public },
	{ "slotUploadMemoReply(const bool)", &slot_11, QMetaData::Public },
	{ "slotNoMemoFound()", &slot_12, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestUpdate", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestQQShow", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestDownloadMemo", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "MemoItem", QUParameter::In }
    };
    static const QUMethod signal_3 = {"requestUploadMemo", 2, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "MemoItem", QUParameter::In }
    };
    static const QUMethod signal_4 = {"memoChanged", 2, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "requestUpdate(const unsigned int)", &signal_0, QMetaData::Private },
	{ "requestQQShow(const unsigned int)", &signal_1, QMetaData::Private },
	{ "requestDownloadMemo(const unsigned int)", &signal_2, QMetaData::Private },
	{ "requestUploadMemo(const unsigned int,const MemoItem&)", &signal_3, QMetaData::Private },
	{ "memoChanged(const unsigned int,const MemoItem&)", &signal_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaDetailsWindow", parentObject,
	slot_tbl, 13,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaDetailsWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaDetailsWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaDetailsWindow" ) )
	return this;
    return EvaUserUIBase::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestUpdate
void EvaDetailsWindow::requestUpdate( const unsigned int t0 )
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

// SIGNAL requestQQShow
void EvaDetailsWindow::requestQQShow( const unsigned int t0 )
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

// SIGNAL requestDownloadMemo
void EvaDetailsWindow::requestDownloadMemo( const unsigned int t0 )
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

// SIGNAL requestUploadMemo
void EvaDetailsWindow::requestUploadMemo( const unsigned int t0, const MemoItem& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL memoChanged
void EvaDetailsWindow::memoChanged( const unsigned int t0, const MemoItem& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

bool EvaDetailsWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotUpdateClick(); break;
    case 1: slotDetailsUpdated((QStringList)(*((QStringList*)static_QUType_ptr.get(_o+1)))); break;
    case 2: slotUpdateQQShow(); break;
    case 3: slotFirstUpdate(); break;
    case 4: slotShopClicked(); break;
    case 5: slotAlbumClicked(); break;
    case 6: slotLinkClicked((const QString&)static_QUType_QString.get(_o+1)); break;
    case 7: slotBuddyQQShowReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 8: slotCurrentChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 9: slotDownloadMemo(); break;
    case 10: slotUpdateMemo((const MemoItem&)*((const MemoItem*)static_QUType_ptr.get(_o+1))); break;
    case 11: slotUploadMemoReply((const bool)static_QUType_bool.get(_o+1)); break;
    case 12: slotNoMemoFound(); break;
    default:
	return EvaUserUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaDetailsWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestUpdate((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: requestQQShow((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: requestDownloadMemo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: requestUploadMemo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const MemoItem&)*((const MemoItem*)static_QUType_ptr.get(_o+2))); break;
    case 4: memoChanged((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const MemoItem&)*((const MemoItem*)static_QUType_ptr.get(_o+2))); break;
    default:
	return EvaUserUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaDetailsWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaUserUIBase::qt_property( id, f, v);
}

bool EvaDetailsWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
