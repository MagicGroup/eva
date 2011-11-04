/****************************************************************************
** EvaUser meta object code from reading C++ file 'evauser.h'
**
** Created: Tue Feb 8 23:56:11 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evauser.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaUser::className() const
{
    return "EvaUser";
}

QMetaObject *EvaUser::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaUser( "EvaUser", &EvaUser::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaUser::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaUser", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaUser::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaUser", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaUser::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod signal_0 = {"loadGroupedBuddiesReady", 0, 0 };
    static const QUMethod signal_1 = {"loadQunListReady", 0, 0 };
    static const QMetaData signal_tbl[] = {
	{ "loadGroupedBuddiesReady()", &signal_0, QMetaData::Public },
	{ "loadQunListReady()", &signal_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaUser", parentObject,
	0, 0,
	signal_tbl, 2,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaUser.setMetaObject( metaObj );
    return metaObj;
}

void* EvaUser::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaUser" ) )
	return this;
    if ( !qstrcmp( clname, "EvaDCOPContactsInterface" ) )
	return (EvaDCOPContactsInterface*)this;
    return QObject::qt_cast( clname );
}

// SIGNAL loadGroupedBuddiesReady
void EvaUser::loadGroupedBuddiesReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL loadQunListReady
void EvaUser::loadQunListReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

bool EvaUser::qt_invoke( int _id, QUObject* _o )
{
    return QObject::qt_invoke(_id,_o);
}

bool EvaUser::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: loadGroupedBuddiesReady(); break;
    case 1: loadQunListReady(); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaUser::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaUser::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
