/****************************************************************************
** QunCategoryPicker meta object code from reading C++ file 'quncategorypicker.h'
**
** Created: Tue Feb 8 23:53:30 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "quncategorypicker.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *QunCategoryPicker::className() const
{
    return "QunCategoryPicker";
}

QMetaObject *QunCategoryPicker::metaObj = 0;
static QMetaObjectCleanUp cleanUp_QunCategoryPicker( "QunCategoryPicker", &QunCategoryPicker::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString QunCategoryPicker::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QunCategoryPicker", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString QunCategoryPicker::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "QunCategoryPicker", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* QunCategoryPicker::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QunCategoryUI::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotTopListChanged", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotSecondListChanged", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotThirdListChanged", 1, param_slot_2 };
    static const QUMethod slot_3 = {"slotCancelClicked", 0, 0 };
    static const QUMethod slot_4 = {"slotOKClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotTopListChanged(int)", &slot_0, QMetaData::Private },
	{ "slotSecondListChanged(int)", &slot_1, QMetaData::Private },
	{ "slotThirdListChanged(int)", &slot_2, QMetaData::Private },
	{ "slotCancelClicked()", &slot_3, QMetaData::Private },
	{ "slotOKClicked()", &slot_4, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod signal_0 = {"selectCategoryCode", 1, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "selectCategoryCode(const unsigned short)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"QunCategoryPicker", parentObject,
	slot_tbl, 5,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_QunCategoryPicker.setMetaObject( metaObj );
    return metaObj;
}

void* QunCategoryPicker::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "QunCategoryPicker" ) )
	return this;
    return QunCategoryUI::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL selectCategoryCode
void QunCategoryPicker::selectCategoryCode( const unsigned short t0 )
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

bool QunCategoryPicker::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotTopListChanged((int)static_QUType_int.get(_o+1)); break;
    case 1: slotSecondListChanged((int)static_QUType_int.get(_o+1)); break;
    case 2: slotThirdListChanged((int)static_QUType_int.get(_o+1)); break;
    case 3: slotCancelClicked(); break;
    case 4: slotOKClicked(); break;
    default:
	return QunCategoryUI::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool QunCategoryPicker::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: selectCategoryCode((const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return QunCategoryUI::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool QunCategoryPicker::qt_property( int id, int f, QVariant* v)
{
    return QunCategoryUI::qt_property( id, f, v);
}

bool QunCategoryPicker::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
