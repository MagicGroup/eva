/****************************************************************************
** EvaAddingQunWindow meta object code from reading C++ file 'evaaddqunwindow.h'
**
** Created: Tue Feb 8 23:52:53 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaaddqunwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaAddingQunWindow::className() const
{
    return "EvaAddingQunWindow";
}

QMetaObject *EvaAddingQunWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaAddingQunWindow( "EvaAddingQunWindow", &EvaAddingQunWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaAddingQunWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAddingQunWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaAddingQunWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaAddingQunWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaAddingQunWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaAddQunUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"slotQunDetailsClicked", 0, 0 };
    static const QUMethod slot_1 = {"slotCreatorDetailsClicked", 0, 0 };
    static const QUMethod slot_2 = {"slotSendClicked", 0, 0 };
    static const QUParameter param_slot_3[] = {
	{ "e", &static_QUType_ptr, "QCloseEvent", QUParameter::In }
    };
    static const QUMethod slot_3 = {"closeEvent", 1, param_slot_3 };
    static const QMetaData slot_tbl[] = {
	{ "slotQunDetailsClicked()", &slot_0, QMetaData::Private },
	{ "slotCreatorDetailsClicked()", &slot_1, QMetaData::Private },
	{ "slotSendClicked()", &slot_2, QMetaData::Private },
	{ "closeEvent(QCloseEvent*)", &slot_3, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"refreshGraphic", 0, 0 };
    static const QUParameter param_signal_1[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestDetails", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestQunDetails", 1, param_signal_2 };
    static const QUMethod signal_3 = {"requestAdd", 0, 0 };
    static const QUMethod signal_4 = {"requestCancel", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "refreshGraphic()", &signal_0, QMetaData::Public },
	{ "requestDetails(const unsigned int)", &signal_1, QMetaData::Public },
	{ "requestQunDetails(const unsigned int)", &signal_2, QMetaData::Public },
	{ "requestAdd()", &signal_3, QMetaData::Public },
	{ "requestCancel()", &signal_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaAddingQunWindow", parentObject,
	slot_tbl, 4,
	signal_tbl, 5,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaAddingQunWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaAddingQunWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaAddingQunWindow" ) )
	return this;
    return EvaAddQunUIBase::qt_cast( clname );
}

// SIGNAL refreshGraphic
void EvaAddingQunWindow::refreshGraphic()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestDetails
void EvaAddingQunWindow::requestDetails( const unsigned int t0 )
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

// SIGNAL requestQunDetails
void EvaAddingQunWindow::requestQunDetails( const unsigned int t0 )
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

// SIGNAL requestAdd
void EvaAddingQunWindow::requestAdd()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL requestCancel
void EvaAddingQunWindow::requestCancel()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

bool EvaAddingQunWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotQunDetailsClicked(); break;
    case 1: slotCreatorDetailsClicked(); break;
    case 2: slotSendClicked(); break;
    case 3: closeEvent((QCloseEvent*)static_QUType_ptr.get(_o+1)); break;
    default:
	return EvaAddQunUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaAddingQunWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: refreshGraphic(); break;
    case 1: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: requestQunDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: requestAdd(); break;
    case 4: requestCancel(); break;
    default:
	return EvaAddQunUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaAddingQunWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaAddQunUIBase::qt_property( id, f, v);
}

bool EvaAddingQunWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
