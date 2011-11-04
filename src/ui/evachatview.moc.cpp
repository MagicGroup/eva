/****************************************************************************
** EvaChatView meta object code from reading C++ file 'evachatview.h'
**
** Created: Tue Feb 8 23:51:30 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evachatview.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaChatView::className() const
{
    return "EvaChatView";
}

QMetaObject *EvaChatView::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaChatView( "EvaChatView", &EvaChatView::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaChatView::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaChatView", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaChatView::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaChatView", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaChatView::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = KHTMLPart::staticMetaObject();
    static const QUMethod slot_0 = {"slotScrollToBottom", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "url", &static_QUType_QString, 0, QUParameter::In },
	{ "point", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotPopupMenu", 2, param_slot_1 };
    static const QUMethod slot_2 = {"slotSelectionChanged", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "urls", &static_QUType_ptr, "KURL", QUParameter::In },
	{ 0, &static_QUType_ptr, "KParts::URLArgs", QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotLinkClicked", 2, param_slot_3 };
    static const QUMethod slot_4 = {"copy", 0, 0 };
    static const QUMethod slot_5 = {"searchProvider", 0, 0 };
    static const QUMethod slot_6 = {"openSelection", 0, 0 };
    static const QUMethod slot_7 = {"slotCopyLinkLocation", 0, 0 };
    static const QUMethod slot_8 = {"slotCopyImage", 0, 0 };
    static const QUMethod slot_9 = {"slotSaveImageAs", 0, 0 };
    static const QUMethod slot_10 = {"slotSaveAsCustomSmiley", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotScrollToBottom()", &slot_0, QMetaData::Private },
	{ "slotPopupMenu(const QString&,const QPoint&)", &slot_1, QMetaData::Private },
	{ "slotSelectionChanged()", &slot_2, QMetaData::Private },
	{ "slotLinkClicked(const KURL&,const KParts::URLArgs&)", &slot_3, QMetaData::Private },
	{ "copy()", &slot_4, QMetaData::Private },
	{ "searchProvider()", &slot_5, QMetaData::Private },
	{ "openSelection()", &slot_6, QMetaData::Private },
	{ "slotCopyLinkLocation()", &slot_7, QMetaData::Private },
	{ "slotCopyImage()", &slot_8, QMetaData::Private },
	{ "slotSaveImageAs()", &slot_9, QMetaData::Private },
	{ "slotSaveAsCustomSmiley()", &slot_10, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"saveAsCustomSmiley", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"fileTransferAcceptRequest", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"fileTransferSaveAsRequest", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_3 = {"fileTransferCancelRequest", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isResume", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"fileTransferResume", 2, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "saveAsCustomSmiley(QString)", &signal_0, QMetaData::Public },
	{ "fileTransferAcceptRequest(const unsigned int)", &signal_1, QMetaData::Public },
	{ "fileTransferSaveAsRequest(const unsigned int)", &signal_2, QMetaData::Public },
	{ "fileTransferCancelRequest(const unsigned int)", &signal_3, QMetaData::Public },
	{ "fileTransferResume(const unsigned int,const bool)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaChatView", parentObject,
	slot_tbl, 11,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaChatView.setMetaObject( metaObj );
    return metaObj;
}

void* EvaChatView::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaChatView" ) )
	return this;
    return KHTMLPart::qt_cast( clname );
}

// SIGNAL saveAsCustomSmiley
void EvaChatView::saveAsCustomSmiley( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL fileTransferAcceptRequest
void EvaChatView::fileTransferAcceptRequest( const unsigned int t0 )
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

// SIGNAL fileTransferSaveAsRequest
void EvaChatView::fileTransferSaveAsRequest( const unsigned int t0 )
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

// SIGNAL fileTransferCancelRequest
void EvaChatView::fileTransferCancelRequest( const unsigned int t0 )
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

// SIGNAL fileTransferResume
void EvaChatView::fileTransferResume( const unsigned int t0, const bool t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
}

bool EvaChatView::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotScrollToBottom(); break;
    case 1: slotPopupMenu((const QString&)static_QUType_QString.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 2: slotSelectionChanged(); break;
    case 3: slotLinkClicked((const KURL&)*((const KURL*)static_QUType_ptr.get(_o+1)),(const KParts::URLArgs&)*((const KParts::URLArgs*)static_QUType_ptr.get(_o+2))); break;
    case 4: copy(); break;
    case 5: searchProvider(); break;
    case 6: openSelection(); break;
    case 7: slotCopyLinkLocation(); break;
    case 8: slotCopyImage(); break;
    case 9: slotSaveImageAs(); break;
    case 10: slotSaveAsCustomSmiley(); break;
    default:
	return KHTMLPart::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaChatView::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: saveAsCustomSmiley((QString)static_QUType_QString.get(_o+1)); break;
    case 1: fileTransferAcceptRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: fileTransferSaveAsRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: fileTransferCancelRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 4: fileTransferResume((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2)); break;
    default:
	return KHTMLPart::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaChatView::qt_property( int id, int f, QVariant* v)
{
    return KHTMLPart::qt_property( id, f, v);
}

bool EvaChatView::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
