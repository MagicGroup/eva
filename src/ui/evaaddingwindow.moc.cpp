/****************************************************************************
** EvaAddingWindow meta object code from reading C++ file 'evaaddingwindow.h'
**
** Created: Tue Feb 8 23:51:26 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaaddingwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaAddingWindow::className() const
{
    return "EvaAddingWindow";
}

QMetaObject *EvaAddingWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaAddingWindow( "EvaAddingWindow", &EvaAddingWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaAddingWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAddingWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaAddingWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAddingWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaAddingWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaAddUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotFaceClicked", 0, 0 };
    static const QUMethod slot_1 = {"slotOkClicked", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "e", &static_QUType_ptr, "QCloseEvent", QUParameter::In }
    };
    static const QUMethod slot_2 = {"closeEvent", 1, param_slot_2 };
    static const QMetaData slot_tbl[] = {
	{ "slotFaceClicked()", &slot_0, QMetaData::Private },
	{ "slotOkClicked()", &slot_1, QMetaData::Private },
	{ "closeEvent(QCloseEvent*)", &slot_2, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"refreshGraphic", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestDetails", 1, param_signal_1 };
    static const QUMethod signal_2 = {"requestAdd", 0, 0 };
    static const QUMethod signal_3 = {"requestCancel", 0, 0 };
    static const QUParameter param_signal_4[] = {
	{ "index", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"groupSelected", 1, param_signal_4 };
    static const QMetaData signal_tbl[] = {
	{ "refreshGraphic()", &signal_0, QMetaData::Public },
	{ "requestDetails(const unsigned int)", &signal_1, QMetaData::Public },
	{ "requestAdd()", &signal_2, QMetaData::Public },
	{ "requestCancel()", &signal_3, QMetaData::Public },
	{ "groupSelected(const int)", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaAddingWindow", parentObject,
	slot_tbl, 3,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaAddingWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaAddingWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaAddingWindow" ) )
	return this;
    return EvaAddUIBase::qt_cast( clname );
}

// SIGNAL refreshGraphic
void EvaAddingWindow::refreshGraphic()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestDetails
void EvaAddingWindow::requestDetails( const unsigned int t0 )
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

// SIGNAL requestAdd
void EvaAddingWindow::requestAdd()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL requestCancel
void EvaAddingWindow::requestCancel()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL groupSelected
void EvaAddingWindow::groupSelected( const int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 4, t0 );
}

bool EvaAddingWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotFaceClicked(); break;
    case 1: slotOkClicked(); break;
    case 2: closeEvent((QCloseEvent*)static_QUType_ptr.get(_o+1)); break;
    default:
	return EvaAddUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaAddingWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: refreshGraphic(); break;
    case 1: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: requestAdd(); break;
    case 3: requestCancel(); break;
    case 4: groupSelected((const int)static_QUType_int.get(_o+1)); break;
    default:
	return EvaAddUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaAddingWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaAddUIBase::qt_property( id, f, v);
}

bool EvaAddingWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
