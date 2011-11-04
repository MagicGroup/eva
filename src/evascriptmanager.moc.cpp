/****************************************************************************
** EvaScriptManager meta object code from reading C++ file 'evascriptmanager.h'
**
** Created: Tue Feb 8 23:56:31 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evascriptmanager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaScriptManager::className() const
{
    return "EvaScriptManager";
}

QMetaObject *EvaScriptManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaScriptManager( "EvaScriptManager", &EvaScriptManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaScriptManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaScriptManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaScriptManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaScriptManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaScriptManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = KDialogBase::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotCurrentChanged", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out }
    };
    static const QUMethod slot_1 = {"slotInstallScript", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "path", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotInstallScript", 2, param_slot_2 };
    static const QUMethod slot_3 = {"slotUninstallScript", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out }
    };
    static const QUMethod slot_4 = {"slotRunScript", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "silent", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"slotRunScript", 2, param_slot_5 };
    static const QUMethod slot_6 = {"slotStopScript", 0, 0 };
    static const QUMethod slot_7 = {"slotConfigureScript", 0, 0 };
    static const QUMethod slot_8 = {"slotAboutScript", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x0e", QUParameter::In }
    };
    static const QUMethod slot_9 = {"slotShowContextMenu", 2, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ 0, &static_QUType_ptr, "KProcess", QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"slotReceivedStdout", 3, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_ptr, "KProcess", QUParameter::In },
	{ 0, &static_QUType_charstar, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"slotReceivedStderr", 3, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "process", &static_QUType_ptr, "KProcess", QUParameter::In }
    };
    static const QUMethod slot_12 = {"scriptFinished", 1, param_slot_12 };
    static const QMetaData slot_tbl[] = {
	{ "slotCurrentChanged(QListViewItem*)", &slot_0, QMetaData::Private },
	{ "slotInstallScript()", &slot_1, QMetaData::Private },
	{ "slotInstallScript(const QString&)", &slot_2, QMetaData::Private },
	{ "slotUninstallScript()", &slot_3, QMetaData::Private },
	{ "slotRunScript()", &slot_4, QMetaData::Private },
	{ "slotRunScript(bool)", &slot_5, QMetaData::Private },
	{ "slotStopScript()", &slot_6, QMetaData::Private },
	{ "slotConfigureScript()", &slot_7, QMetaData::Private },
	{ "slotAboutScript()", &slot_8, QMetaData::Private },
	{ "slotShowContextMenu(QListViewItem*,const QPoint&)", &slot_9, QMetaData::Private },
	{ "slotReceivedStdout(KProcess*,char*,int)", &slot_10, QMetaData::Private },
	{ "slotReceivedStderr(KProcess*,char*,int)", &slot_11, QMetaData::Private },
	{ "scriptFinished(KProcess*)", &slot_12, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaScriptManager", parentObject,
	slot_tbl, 13,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaScriptManager.setMetaObject( metaObj );
    return metaObj;
}

void* EvaScriptManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaScriptManager" ) )
	return this;
    if ( !qstrcmp( clname, "EvaDCOPToolsInterface" ) )
	return (EvaDCOPToolsInterface*)this;
    return KDialogBase::qt_cast( clname );
}

bool EvaScriptManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotCurrentChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 1: static_QUType_bool.set(_o,slotInstallScript()); break;
    case 2: static_QUType_bool.set(_o,slotInstallScript((const QString&)static_QUType_QString.get(_o+1))); break;
    case 3: slotUninstallScript(); break;
    case 4: static_QUType_bool.set(_o,slotRunScript()); break;
    case 5: static_QUType_bool.set(_o,slotRunScript((bool)static_QUType_bool.get(_o+1))); break;
    case 6: slotStopScript(); break;
    case 7: slotConfigureScript(); break;
    case 8: slotAboutScript(); break;
    case 9: slotShowContextMenu((QListViewItem*)static_QUType_ptr.get(_o+1),(const QPoint&)*((const QPoint*)static_QUType_ptr.get(_o+2))); break;
    case 10: slotReceivedStdout((KProcess*)static_QUType_ptr.get(_o+1),(char*)static_QUType_charstar.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 11: slotReceivedStderr((KProcess*)static_QUType_ptr.get(_o+1),(char*)static_QUType_charstar.get(_o+2),(int)static_QUType_int.get(_o+3)); break;
    case 12: scriptFinished((KProcess*)static_QUType_ptr.get(_o+1)); break;
    default:
	return KDialogBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaScriptManager::qt_emit( int _id, QUObject* _o )
{
    return KDialogBase::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaScriptManager::qt_property( int id, int f, QVariant* v)
{
    return KDialogBase::qt_property( id, f, v);
}

bool EvaScriptManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
