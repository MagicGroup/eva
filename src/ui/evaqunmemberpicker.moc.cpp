/****************************************************************************
** EvaQunMemberPicker meta object code from reading C++ file 'evaqunmemberpicker.h'
**
** Created: Tue Feb 8 23:52:26 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaqunmemberpicker.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaQunMemberPicker::className() const
{
    return "EvaQunMemberPicker";
}

QMetaObject *EvaQunMemberPicker::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaQunMemberPicker( "EvaQunMemberPicker", &EvaQunMemberPicker::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaQunMemberPicker::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunMemberPicker", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaQunMemberPicker::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunMemberPicker", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaQunMemberPicker::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaQunMemberPickerUI::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotSetMemberOff", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotClicked", 1, param_slot_1 };
    static const QMetaData slot_tbl[] = {
	{ "slotSetMemberOff(const unsigned int)", &slot_0, QMetaData::Public },
	{ "slotClicked(QListViewItem*)", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isChecked", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"memberClicked", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "memberClicked(const unsigned int,const bool)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaQunMemberPicker", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaQunMemberPicker.setMetaObject( metaObj );
    return metaObj;
}

void* EvaQunMemberPicker::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaQunMemberPicker" ) )
	return this;
    return EvaQunMemberPickerUI::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL memberClicked
void EvaQunMemberPicker::memberClicked( const unsigned int t0, const bool t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
}

bool EvaQunMemberPicker::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotSetMemberOff((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: slotClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    default:
	return EvaQunMemberPickerUI::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaQunMemberPicker::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: memberClicked((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2)); break;
    default:
	return EvaQunMemberPickerUI::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaQunMemberPicker::qt_property( int id, int f, QVariant* v)
{
    return EvaQunMemberPickerUI::qt_property( id, f, v);
}

bool EvaQunMemberPicker::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
