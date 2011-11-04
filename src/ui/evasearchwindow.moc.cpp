/****************************************************************************
** EvaSearchWindow meta object code from reading C++ file 'evasearchwindow.h'
**
** Created: Tue Feb 8 23:53:21 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evasearchwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaSearchWindow::className() const
{
    return "EvaSearchWindow";
}

QMetaObject *EvaSearchWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaSearchWindow( "EvaSearchWindow", &EvaSearchWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaSearchWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSearchWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaSearchWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSearchWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaSearchWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaSearchUIBase::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "std::list<OnlineUser>", QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotSearchUsersReady", 2, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "std::list<AdvancedUser>", QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotAdvancedSearchReady", 3, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_ptr, "std::list<QunInfo>", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotQunSearchReady", 2, param_slot_2 };
    static const QUMethod slot_3 = {"getCategoryCode", 0, 0 };
    static const QUMethod slot_4 = {"slotRbSearchOnlineClicked", 0, 0 };
    static const QUMethod slot_5 = {"slotRbCustomSearchClicked", 0, 0 };
    static const QUMethod slot_6 = {"slotRbSearchFrdCenterClicked", 0, 0 };
    static const QUMethod slot_7 = {"slotRbSearchAlumniClicked", 0, 0 };
    static const QUMethod slot_8 = {"slotRbSearchByCategoryClicked", 0, 0 };
    static const QUMethod slot_9 = {"slotRbAccuratelySearchClicked", 0, 0 };
    static const QUMethod slot_10 = {"slotPbSearchClicked", 0, 0 };
    static const QUMethod slot_11 = {"slotPbLastStepClicked", 0, 0 };
    static const QUMethod slot_12 = {"slotTbBSNextClicked", 0, 0 };
    static const QUMethod slot_13 = {"slotTbBSPrevClicked", 0, 0 };
    static const QUMethod slot_14 = {"slotTbBSAllClicked", 0, 0 };
    static const QUMethod slot_15 = {"slotTbBSDetailsClicked", 0, 0 };
    static const QUParameter param_slot_16[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_16 = {"slotBasicUserSelected", 1, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"slotBasicResultTableDBClicked", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_ptr, "QWidget", QUParameter::In }
    };
    static const QUMethod slot_18 = {"slotCurrentChanged", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"slotAdvancedResultTableDBClicked", 1, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_20 = {"slotAdvancedUserSelected", 1, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"slotCbASProvinceActive", 1, param_slot_21 };
    static const QUMethod slot_22 = {"slotTbASNextClicked", 0, 0 };
    static const QUMethod slot_23 = {"slotTbASPrevClicked", 0, 0 };
    static const QUMethod slot_24 = {"slotTbASAllClicked", 0, 0 };
    static const QUMethod slot_25 = {"slotTbASDetailsClicked", 0, 0 };
    static const QUParameter param_slot_26[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_26 = {"loadCityList", 1, param_slot_26 };
    static const QUMethod slot_27 = {"loadCategoryList", 0, 0 };
    static const QUParameter param_slot_28[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_28 = {"slotTopListChanged", 1, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"slotSecondListChanged", 1, param_slot_29 };
    static const QUParameter param_slot_30[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_30 = {"slotQunSelected", 1, param_slot_30 };
    static const QUParameter param_slot_31[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"slotQunResultTableDBClicked", 1, param_slot_31 };
    static const QUMethod slot_32 = {"slotTbQSDetailsClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotSearchUsersReady(const bool,const std::list<OnlineUser>)", &slot_0, QMetaData::Public },
	{ "slotAdvancedSearchReady(const int,const bool,const std::list<AdvancedUser>)", &slot_1, QMetaData::Public },
	{ "slotQunSearchReady(const std::list<QunInfo>,QString)", &slot_2, QMetaData::Public },
	{ "getCategoryCode()", &slot_3, QMetaData::Public },
	{ "slotRbSearchOnlineClicked()", &slot_4, QMetaData::Private },
	{ "slotRbCustomSearchClicked()", &slot_5, QMetaData::Private },
	{ "slotRbSearchFrdCenterClicked()", &slot_6, QMetaData::Private },
	{ "slotRbSearchAlumniClicked()", &slot_7, QMetaData::Private },
	{ "slotRbSearchByCategoryClicked()", &slot_8, QMetaData::Private },
	{ "slotRbAccuratelySearchClicked()", &slot_9, QMetaData::Private },
	{ "slotPbSearchClicked()", &slot_10, QMetaData::Private },
	{ "slotPbLastStepClicked()", &slot_11, QMetaData::Private },
	{ "slotTbBSNextClicked()", &slot_12, QMetaData::Private },
	{ "slotTbBSPrevClicked()", &slot_13, QMetaData::Private },
	{ "slotTbBSAllClicked()", &slot_14, QMetaData::Private },
	{ "slotTbBSDetailsClicked()", &slot_15, QMetaData::Private },
	{ "slotBasicUserSelected(int)", &slot_16, QMetaData::Private },
	{ "slotBasicResultTableDBClicked(int)", &slot_17, QMetaData::Private },
	{ "slotCurrentChanged(QWidget*)", &slot_18, QMetaData::Private },
	{ "slotAdvancedResultTableDBClicked(int)", &slot_19, QMetaData::Private },
	{ "slotAdvancedUserSelected(int)", &slot_20, QMetaData::Private },
	{ "slotCbASProvinceActive(int)", &slot_21, QMetaData::Private },
	{ "slotTbASNextClicked()", &slot_22, QMetaData::Private },
	{ "slotTbASPrevClicked()", &slot_23, QMetaData::Private },
	{ "slotTbASAllClicked()", &slot_24, QMetaData::Private },
	{ "slotTbASDetailsClicked()", &slot_25, QMetaData::Private },
	{ "loadCityList(unsigned int)", &slot_26, QMetaData::Private },
	{ "loadCategoryList()", &slot_27, QMetaData::Private },
	{ "slotTopListChanged(int)", &slot_28, QMetaData::Private },
	{ "slotSecondListChanged(int)", &slot_29, QMetaData::Private },
	{ "slotQunSelected(int)", &slot_30, QMetaData::Private },
	{ "slotQunResultTableDBClicked(int)", &slot_31, QMetaData::Private },
	{ "slotTbQSDetailsClicked()", &slot_32, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestSearchUsers", 6, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_1 = {"requestUserInfo", 1, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestAdvancedSearch", 7, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_3 = {"requestQunSearch", 1, param_signal_3 };
    static const QMetaData signal_tbl[] = {
	{ "requestSearchUsers(const bool,const QString,const QString,const QString,const QString,const bool)", &signal_0, QMetaData::Public },
	{ "requestUserInfo(const unsigned int)", &signal_1, QMetaData::Public },
	{ "requestAdvancedSearch(const int,const bool,const bool,const int,const int,const int,const int)", &signal_2, QMetaData::Public },
	{ "requestQunSearch(const unsigned int)", &signal_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaSearchWindow", parentObject,
	slot_tbl, 33,
	signal_tbl, 4,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaSearchWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaSearchWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaSearchWindow" ) )
	return this;
    return EvaSearchUIBase::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestSearchUsers
void EvaSearchWindow::requestSearchUsers( const bool t0, const QString t1, const QString t2, const QString t3, const QString t4, const bool t5 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[7];
    static_QUType_bool.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    static_QUType_QString.set(o+4,t3);
    static_QUType_QString.set(o+5,t4);
    static_QUType_bool.set(o+6,t5);
    activate_signal( clist, o );
}

// SIGNAL requestUserInfo
void EvaSearchWindow::requestUserInfo( const unsigned int t0 )
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

// SIGNAL requestAdvancedSearch
void EvaSearchWindow::requestAdvancedSearch( const int t0, const bool t1, const bool t2, const int t3, const int t4, const int t5, const int t6 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 2 );
    if ( !clist )
	return;
    QUObject o[8];
    static_QUType_int.set(o+1,t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_bool.set(o+3,t2);
    static_QUType_int.set(o+4,t3);
    static_QUType_int.set(o+5,t4);
    static_QUType_int.set(o+6,t5);
    static_QUType_int.set(o+7,t6);
    activate_signal( clist, o );
}

// SIGNAL requestQunSearch
void EvaSearchWindow::requestQunSearch( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 3 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaSearchWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotSearchUsersReady((const bool)static_QUType_bool.get(_o+1),(const std::list<OnlineUser>)(*((const std::list<OnlineUser>*)static_QUType_ptr.get(_o+2)))); break;
    case 1: slotAdvancedSearchReady((const int)static_QUType_int.get(_o+1),(const bool)static_QUType_bool.get(_o+2),(const std::list<AdvancedUser>)(*((const std::list<AdvancedUser>*)static_QUType_ptr.get(_o+3)))); break;
    case 2: slotQunSearchReady((const std::list<QunInfo>)(*((const std::list<QunInfo>*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2)); break;
    case 3: getCategoryCode(); break;
    case 4: slotRbSearchOnlineClicked(); break;
    case 5: slotRbCustomSearchClicked(); break;
    case 6: slotRbSearchFrdCenterClicked(); break;
    case 7: slotRbSearchAlumniClicked(); break;
    case 8: slotRbSearchByCategoryClicked(); break;
    case 9: slotRbAccuratelySearchClicked(); break;
    case 10: slotPbSearchClicked(); break;
    case 11: slotPbLastStepClicked(); break;
    case 12: slotTbBSNextClicked(); break;
    case 13: slotTbBSPrevClicked(); break;
    case 14: slotTbBSAllClicked(); break;
    case 15: slotTbBSDetailsClicked(); break;
    case 16: slotBasicUserSelected((int)static_QUType_int.get(_o+1)); break;
    case 17: slotBasicResultTableDBClicked((int)static_QUType_int.get(_o+1)); break;
    case 18: slotCurrentChanged((QWidget*)static_QUType_ptr.get(_o+1)); break;
    case 19: slotAdvancedResultTableDBClicked((int)static_QUType_int.get(_o+1)); break;
    case 20: slotAdvancedUserSelected((int)static_QUType_int.get(_o+1)); break;
    case 21: slotCbASProvinceActive((int)static_QUType_int.get(_o+1)); break;
    case 22: slotTbASNextClicked(); break;
    case 23: slotTbASPrevClicked(); break;
    case 24: slotTbASAllClicked(); break;
    case 25: slotTbASDetailsClicked(); break;
    case 26: loadCityList((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 27: loadCategoryList(); break;
    case 28: slotTopListChanged((int)static_QUType_int.get(_o+1)); break;
    case 29: slotSecondListChanged((int)static_QUType_int.get(_o+1)); break;
    case 30: slotQunSelected((int)static_QUType_int.get(_o+1)); break;
    case 31: slotQunResultTableDBClicked((int)static_QUType_int.get(_o+1)); break;
    case 32: slotTbQSDetailsClicked(); break;
    default:
	return EvaSearchUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaSearchWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestSearchUsers((const bool)static_QUType_bool.get(_o+1),(const QString)static_QUType_QString.get(_o+2),(const QString)static_QUType_QString.get(_o+3),(const QString)static_QUType_QString.get(_o+4),(const QString)static_QUType_QString.get(_o+5),(const bool)static_QUType_bool.get(_o+6)); break;
    case 1: requestUserInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 2: requestAdvancedSearch((const int)static_QUType_int.get(_o+1),(const bool)static_QUType_bool.get(_o+2),(const bool)static_QUType_bool.get(_o+3),(const int)static_QUType_int.get(_o+4),(const int)static_QUType_int.get(_o+5),(const int)static_QUType_int.get(_o+6),(const int)static_QUType_int.get(_o+7)); break;
    case 3: requestQunSearch((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaSearchUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaSearchWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaSearchUIBase::qt_property( id, f, v);
}

bool EvaSearchWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
