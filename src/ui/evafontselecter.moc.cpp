/****************************************************************************
** EvaFontSelecter meta object code from reading C++ file 'evafontselecter.h'
**
** Created: Tue Feb 8 23:53:40 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evafontselecter.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaFontSelecter::className() const
{
    return "EvaFontSelecter";
}

QMetaObject *EvaFontSelecter::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaFontSelecter( "EvaFontSelecter", &EvaFontSelecter::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaFontSelecter::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaFontSelecter", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaFontSelecter::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaFontSelecter", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaFontSelecter::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"languageChange", 0, 0 };
    static const QUMethod slot_1 = {"slotClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "languageChange()", &slot_0, QMetaData::Protected },
	{ "slotClicked()", &slot_1, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_varptr, "\x0a", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"fontChanged", 2, param_signal_0 };
    static const QMetaData signal_tbl[] = {
	{ "fontChanged(QColor,int)", &signal_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaFontSelecter", parentObject,
	slot_tbl, 2,
	signal_tbl, 1,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaFontSelecter.setMetaObject( metaObj );
    return metaObj;
}

void* EvaFontSelecter::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaFontSelecter" ) )
	return this;
    return QWidget::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL fontChanged
void EvaFontSelecter::fontChanged( QColor t0, int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_varptr.set(o+1,&t0);
    static_QUType_int.set(o+2,t1);
    activate_signal( clist, o );
}

bool EvaFontSelecter::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: languageChange(); break;
    case 1: slotClicked(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaFontSelecter::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: fontChanged((QColor)(*((QColor*)static_QUType_ptr.get(_o+1))),(int)static_QUType_int.get(_o+2)); break;
    default:
	return QWidget::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaFontSelecter::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool EvaFontSelecter::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
