/****************************************************************************
** EvaScriptWidget meta object code from reading C++ file 'evascriptwidget.h'
**
** Created: Tue Feb 8 23:52:50 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evascriptwidget.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaScriptWidget::className() const
{
    return "EvaScriptWidget";
}

QMetaObject *EvaScriptWidget::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaScriptWidget( "EvaScriptWidget", &EvaScriptWidget::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaScriptWidget::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaScriptWidget", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaScriptWidget::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaScriptWidget", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaScriptWidget::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = KHTMLPart::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "url", &static_QUType_QString, 0, QUParameter::In },
	{ "point", &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotPopupMenu", 2, param_slot_0 };
    static const QUMethod slot_1 = {"slotSelectionChanged", 0, 0 };
    static const QUMethod slot_2 = {"slotOpenExternalBrower", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "urls", &static_QUType_ptr, "KURL", QUParameter::In },
	{ 0, &static_QUType_ptr, "KParts::URLArgs", QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotLinkClicked", 2, param_slot_3 };
    static const QUMethod slot_4 = {"slotCopy", 0, 0 };
    static const QUMethod slot_5 = {"slotCopyLinkLocation", 0, 0 };
    static const QUMethod slot_6 = {"slotCopyImage", 0, 0 };
    static const QUMethod slot_7 = {"slotSaveImageAs", 0, 0 };
    static const QUMethod slot_8 = {"slotSaveAsCustomSmiley", 0, 0 };
    static const QUMethod slot_9 = {"slotInstallRemoteScript", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "job", &static_QUType_ptr, "KIO::Job", QUParameter::In },
	{ "from", &static_QUType_ptr, "KURL", QUParameter::In },
	{ "to", &static_QUType_ptr, "KURL", QUParameter::In },
	{ "directory", &static_QUType_bool, 0, QUParameter::In },
	{ "renamed", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"slotDownloadScriptDone", 5, param_slot_10 };
    static const QMetaData slot_tbl[] = {
	{ "slotPopupMenu(const QString&,const QPoint&)", &slot_0, QMetaData::Private },
	{ "slotSelectionChanged()", &slot_1, QMetaData::Private },
	{ "slotOpenExternalBrower()", &slot_2, QMetaData::Private },
	{ "slotLinkClicked(const KURL&,const KParts::URLArgs&)", &slot_3, QMetaData::Private },
	{ "slotCopy()", &slot_4, QMetaData::Private },
	{ "slotCopyLinkLocation()", &slot_5, QMetaData::Private },
	{ "slotCopyImage()", &slot_6, QMetaData::Private },
	{ "slotSaveImageAs()", &slot_7, QMetaData::Private },
	{ "slotSaveAsCustomSmiley()", &slot_8, QMetaData::Private },
	{ "slotInstallRemoteScript()", &slot_9, QMetaData::Private },
	{ "slotDownloadScriptDone(KIO::Job*,const KURL&,const KURL&,bool,bool)", &slot_10, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaScriptWidget", parentObject,
	slot_tbl, 11,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaScriptWidget.setMetaObject( metaObj );
    return metaObj;
}

void* EvaScriptWidget::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaScriptWidget" ) )
	return this;
    return KHTMLPart::qt_cast( clname );
}

bool EvaScriptWidget::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotPopupMenu((const QString&)static_QUType_QString.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 1: slotSelectionChanged(); break;
    case 2: slotOpenExternalBrower(); break;
    case 3: slotLinkClicked((const KURL&)*((const KURL*)static_QUType_ptr.get(_o+1)),(const KParts::URLArgs&)*((const KParts::URLArgs*)static_QUType_ptr.get(_o+2))); break;
    case 4: slotCopy(); break;
    case 5: slotCopyLinkLocation(); break;
    case 6: slotCopyImage(); break;
    case 7: slotSaveImageAs(); break;
    case 8: slotSaveAsCustomSmiley(); break;
    case 9: slotInstallRemoteScript(); break;
    case 10: slotDownloadScriptDone((KIO::Job*)static_QUType_ptr.get(_o+1),(const KURL&)*((const KURL*)static_QUType_ptr.get(_o+2)),(const KURL&)*((const KURL*)static_QUType_ptr.get(_o+3)),(bool)static_QUType_bool.get(_o+4),(bool)static_QUType_bool.get(_o+5)); break;
    default:
	return KHTMLPart::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaScriptWidget::qt_emit( int _id, QUObject* _o )
{
    return KHTMLPart::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaScriptWidget::qt_property( int id, int f, QVariant* v)
{
    return KHTMLPart::qt_property( id, f, v);
}

bool EvaScriptWidget::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
