/****************************************************************************
** CreateSmileyWindow meta object code from reading C++ file 'createsmileywindow.h'
**
** Created: Tue Feb 8 23:52:23 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "createsmileywindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CreateSmileyWindow::className() const
{
    return "CreateSmileyWindow";
}

QMetaObject *CreateSmileyWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CreateSmileyWindow( "CreateSmileyWindow", &CreateSmileyWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CreateSmileyWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CreateSmileyWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CreateSmileyWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CreateSmileyWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CreateSmileyWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CreateSmileyUI::staticMetaObject();
    static const QUMethod slot_0 = {"slotSelectImagesClicked", 0, 0 };
    static const QUMethod slot_1 = {"slotOKClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotSelectImagesClicked()", &slot_0, QMetaData::Private },
	{ "slotOKClicked()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"addCustomSmileyReady", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "addCustomSmileyReady(bool)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CreateSmileyWindow", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CreateSmileyWindow.setMetaObject( metaObj );
    return metaObj;
}

void* CreateSmileyWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CreateSmileyWindow" ) )
	return this;
    return CreateSmileyUI::qt_cast( clname );
}

// SIGNAL addCustomSmileyReady
void CreateSmileyWindow::addCustomSmileyReady( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 0, t0 );
}

bool CreateSmileyWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotSelectImagesClicked(); break;
    case 1: slotOKClicked(); break;
    default:
	return CreateSmileyUI::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CreateSmileyWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: addCustomSmileyReady((bool)static_QUType_bool.get(_o+1)); break;
    default:
	return CreateSmileyUI::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CreateSmileyWindow::qt_property( int id, int f, QVariant* v)
{
    return CreateSmileyUI::qt_property( id, f, v);
}

bool CreateSmileyWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *RmSmileyGroupDialog::className() const
{
    return "RmSmileyGroupDialog";
}

QMetaObject *RmSmileyGroupDialog::metaObj = 0;
static QMetaObjectCleanUp cleanUp_RmSmileyGroupDialog( "RmSmileyGroupDialog", &RmSmileyGroupDialog::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString RmSmileyGroupDialog::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RmSmileyGroupDialog", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString RmSmileyGroupDialog::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "RmSmileyGroupDialog", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* RmSmileyGroupDialog::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QUMethod slot_1 = {"slotRmAllClicked", 0, 0 };
    static const QUMethod slot_2 = {"slotRmMvClicked", 0, 0 };
    static const QUMethod slot_3 = {"slotOKClicked", 0, 0 };
    static const QUMethod slot_4 = {"slotCancelClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected },
	{ "slotRmAllClicked()", &slot_1, QMetaData::Private },
	{ "slotRmMvClicked()", &slot_2, QMetaData::Private },
	{ "slotOKClicked()", &slot_3, QMetaData::Private },
	{ "slotCancelClicked()", &slot_4, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"RmSmileyGroupDialog", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_RmSmileyGroupDialog.setMetaObject( metaObj );
    return metaObj;
}

void* RmSmileyGroupDialog::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "RmSmileyGroupDialog" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool RmSmileyGroupDialog::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    case 1: slotRmAllClicked(); break;
    case 2: slotRmMvClicked(); break;
    case 3: slotOKClicked(); break;
    case 4: slotCancelClicked(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool RmSmileyGroupDialog::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool RmSmileyGroupDialog::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool RmSmileyGroupDialog::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *CustomSmileyManager::className() const
{
    return "CustomSmileyManager";
}

QMetaObject *CustomSmileyManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CustomSmileyManager( "CustomSmileyManager", &CustomSmileyManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CustomSmileyManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CustomSmileyManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CustomSmileyManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CustomSmileyManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CustomSmileyManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CustomFaceManagerUI::staticMetaObject();
    static const QUMethod slot_0 = {"slotOKClicked", 0, 0 };
    static const QUMethod slot_1 = {"slotAddGroupClicked", 0, 0 };
    static const QUMethod slot_2 = {"slotEditGroupClicked", 0, 0 };
    static const QUMethod slot_3 = {"slotRemoveGroupClicked", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"slotGroupRenamed", 3, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ 0, &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_5 = {"slotGroupSelectionChanged", 1, param_slot_5 };
    static const QUMethod slot_6 = {"slotFaceSelectionChanged", 0, 0 };
    static const QUParameter param_slot_7[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"slotFaceValueChanged", 2, param_slot_7 };
    static const QUMethod slot_8 = {"slotAddSmiley", 0, 0 };
    static const QUParameter param_slot_9[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"slotAddCustomSmileyReady", 1, param_slot_9 };
    static const QUMethod slot_10 = {"slotRemoveSmiley", 0, 0 };
    static const QUMethod slot_11 = {"slotEditSmiley", 0, 0 };
    static const QUMethod slot_12 = {"slotUpSmiley", 0, 0 };
    static const QUMethod slot_13 = {"slotDownSmiley", 0, 0 };
    static const QUMethod slot_14 = {"slotMoveToSmiley", 0, 0 };
    static const QUParameter param_slot_15[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"slotMoveSmileyTo", 1, param_slot_15 };
    static const QMetaData slot_tbl[] = {
	{ "slotOKClicked()", &slot_0, QMetaData::Private },
	{ "slotAddGroupClicked()", &slot_1, QMetaData::Private },
	{ "slotEditGroupClicked()", &slot_2, QMetaData::Private },
	{ "slotRemoveGroupClicked()", &slot_3, QMetaData::Private },
	{ "slotGroupRenamed(QListViewItem*,int,const QString&)", &slot_4, QMetaData::Private },
	{ "slotGroupSelectionChanged(QListViewItem*)", &slot_5, QMetaData::Private },
	{ "slotFaceSelectionChanged()", &slot_6, QMetaData::Private },
	{ "slotFaceValueChanged(int,int)", &slot_7, QMetaData::Private },
	{ "slotAddSmiley()", &slot_8, QMetaData::Private },
	{ "slotAddCustomSmileyReady(bool)", &slot_9, QMetaData::Private },
	{ "slotRemoveSmiley()", &slot_10, QMetaData::Private },
	{ "slotEditSmiley()", &slot_11, QMetaData::Private },
	{ "slotUpSmiley()", &slot_12, QMetaData::Private },
	{ "slotDownSmiley()", &slot_13, QMetaData::Private },
	{ "slotMoveToSmiley()", &slot_14, QMetaData::Private },
	{ "slotMoveSmileyTo(int)", &slot_15, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"customSmileyChanged", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "customSmileyChanged()", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CustomSmileyManager", parentObject,
	slot_tbl, 16,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CustomSmileyManager.setMetaObject( metaObj );
    return metaObj;
}

void* CustomSmileyManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CustomSmileyManager" ) )
	return this;
    return CustomFaceManagerUI::qt_cast( clname );
}

// SIGNAL customSmileyChanged
void CustomSmileyManager::customSmileyChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

bool CustomSmileyManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotOKClicked(); break;
    case 1: slotAddGroupClicked(); break;
    case 2: slotEditGroupClicked(); break;
    case 3: slotRemoveGroupClicked(); break;
    case 4: slotGroupRenamed((QListViewItem*)static_QUType_ptr.get(_o+1),(int)static_QUType_int.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 5: slotGroupSelectionChanged((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 6: slotFaceSelectionChanged(); break;
    case 7: slotFaceValueChanged((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 8: slotAddSmiley(); break;
    case 9: slotAddCustomSmileyReady((bool)static_QUType_bool.get(_o+1)); break;
    case 10: slotRemoveSmiley(); break;
    case 11: slotEditSmiley(); break;
    case 12: slotUpSmiley(); break;
    case 13: slotDownSmiley(); break;
    case 14: slotMoveToSmiley(); break;
    case 15: slotMoveSmileyTo((int)static_QUType_int.get(_o+1)); break;
    default:
	return CustomFaceManagerUI::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CustomSmileyManager::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: customSmileyChanged(); break;
    default:
	return CustomFaceManagerUI::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CustomSmileyManager::qt_property( int id, int f, QVariant* v)
{
    return CustomFaceManagerUI::qt_property( id, f, v);
}

bool CustomSmileyManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
