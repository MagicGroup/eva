/****************************************************************************
** CustomFacePanel meta object code from reading C++ file 'customfaceselector.h'
**
** Created: Tue Feb 8 23:52:02 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "customfaceselector.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *CustomFacePanel::className() const
{
    return "CustomFacePanel";
}

QMetaObject *CustomFacePanel::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CustomFacePanel( "CustomFacePanel", &CustomFacePanel::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CustomFacePanel::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CustomFacePanel", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CustomFacePanel::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CustomFacePanel", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CustomFacePanel::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QFrame::staticMetaObject();
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"selectSysFace", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"selectCustomFace", 2, param_signal_1 };
    static const QMetaData signal_tbl[] = {
	{ "selectSysFace(int)", &signal_0, QMetaData::Public },
	{ "selectCustomFace(QString,QString)", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CustomFacePanel", parentObject,
	0, 0,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CustomFacePanel.setMetaObject( metaObj );
    return metaObj;
}

void* CustomFacePanel::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CustomFacePanel" ) )
	return this;
    return QFrame::qt_cast( clname );
}

// SIGNAL selectSysFace
void CustomFacePanel::selectSysFace( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL selectCustomFace
void CustomFacePanel::selectCustomFace( QString t0, QString t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

bool CustomFacePanel::qt_invoke( int _id, QUObject* _o )
{
    return QFrame::qt_invoke(_id,_o);
}

bool CustomFacePanel::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: selectSysFace((int)static_QUType_int.get(_o+1)); break;
    case 1: selectCustomFace((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    default:
	return QFrame::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CustomFacePanel::qt_property( int id, int f, QVariant* v)
{
    return QFrame::qt_property( id, f, v);
}

bool CustomFacePanel::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES


const char *CustomFaceSelector::className() const
{
    return "CustomFaceSelector";
}

QMetaObject *CustomFaceSelector::metaObj = 0;
static QMetaObjectCleanUp cleanUp_CustomFaceSelector( "CustomFaceSelector", &CustomFaceSelector::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString CustomFaceSelector::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CustomFaceSelector", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString CustomFaceSelector::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "CustomFaceSelector", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* CustomFaceSelector::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = CustomFaceUIBase::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotSelectSysFace", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotSelectCustomFace", 2, param_slot_1 };
    static const QUMethod slot_2 = {"slotAddSmileyClicked", 0, 0 };
    static const QUMethod slot_3 = {"slotUseShortcutClicked", 0, 0 };
    static const QUMethod slot_4 = {"slotPrevClicked", 0, 0 };
    static const QUMethod slot_5 = {"slotNextClicked", 0, 0 };
    static const QUParameter param_slot_6[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_6 = {"slotPanelChanged", 1, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "slotSelectSysFace(int)", &slot_0, QMetaData::Private },
	{ "slotSelectCustomFace(QString,QString)", &slot_1, QMetaData::Private },
	{ "slotAddSmileyClicked()", &slot_2, QMetaData::Private },
	{ "slotUseShortcutClicked()", &slot_3, QMetaData::Private },
	{ "slotPrevClicked()", &slot_4, QMetaData::Private },
	{ "slotNextClicked()", &slot_5, QMetaData::Private },
	{ "slotPanelChanged(QWidget*)", &slot_6, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"selectSysFace", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"selectCustomFace", 1, param_signal_1 };
    static const QUMethod signal_2 = {"addSmileyClicked", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "selectSysFace(int)", &signal_0, QMetaData::Public },
	{ "selectCustomFace(const QString&)", &signal_1, QMetaData::Public },
	{ "addSmileyClicked()", &signal_2, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"CustomFaceSelector", parentObject,
	slot_tbl, 7,
	signal_tbl, 3,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_CustomFaceSelector.setMetaObject( metaObj );
    return metaObj;
}

void* CustomFaceSelector::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "CustomFaceSelector" ) )
	return this;
    return CustomFaceUIBase::qt_cast( clname );
}

// SIGNAL selectSysFace
void CustomFaceSelector::selectSysFace( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL selectCustomFace
void CustomFaceSelector::selectCustomFace( const QString& t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL addSmileyClicked
void CustomFaceSelector::addSmileyClicked()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

bool CustomFaceSelector::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotSelectSysFace((int)static_QUType_int.get(_o+1)); break;
    case 1: slotSelectCustomFace((QString)static_QUType_QString.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 2: slotAddSmileyClicked(); break;
    case 3: slotUseShortcutClicked(); break;
    case 4: slotPrevClicked(); break;
    case 5: slotNextClicked(); break;
    case 6: slotPanelChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    default:
	return CustomFaceUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool CustomFaceSelector::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: selectSysFace((int)static_QUType_int.get(_o+1)); break;
    case 1: selectCustomFace((const QString&)static_QUType_QString.get(_o+1)); break;
    case 2: addSmileyClicked(); break;
    default:
	return CustomFaceUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool CustomFaceSelector::qt_property( int id, int f, QVariant* v)
{
    return CustomFaceUIBase::qt_property( id, f, v);
}

bool CustomFaceSelector::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
