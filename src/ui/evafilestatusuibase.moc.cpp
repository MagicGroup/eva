/****************************************************************************
** EvaFileStatusUIBase meta object code from reading C++ file 'evafilestatusuibase.h'
**
** Created: Tue Feb 8 23:53:15 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evafilestatusuibase.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaFileStatusUIBase::className() const
{
    return "EvaFileStatusUIBase";
}

QMetaObject *EvaFileStatusUIBase::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaFileStatusUIBase( "EvaFileStatusUIBase", &EvaFileStatusUIBase::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaFileStatusUIBase::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaFileStatusUIBase", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaFileStatusUIBase::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaFileStatusUIBase", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaFileStatusUIBase::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QUMethod slot_1 = {"slotCloseClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected },
	{ "slotCloseClicked()", &slot_1, QMetaData::Protected }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod signal_0 = {"closeRequest", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "closeRequest(const unsigned int,QWidget*)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaFileStatusUIBase", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaFileStatusUIBase.setMetaObject( metaObj );
    return metaObj;
}

void* EvaFileStatusUIBase::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaFileStatusUIBase" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL closeRequest
void EvaFileStatusUIBase::closeRequest( const unsigned int t0, QWidget* t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,t1);
    activate_signal( clist, o );
}

bool EvaFileStatusUIBase::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    case 1: slotCloseClicked(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaFileStatusUIBase::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: closeRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QWidget*)static_QUType_ptr.get(_o+2)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaFileStatusUIBase::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool EvaFileStatusUIBase::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
