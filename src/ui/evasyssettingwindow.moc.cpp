/****************************************************************************
** EvaSysSettingWindow meta object code from reading C++ file 'evasyssettingwindow.h'
**
** Created: Tue Feb 8 23:52:55 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evasyssettingwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaSysSettingWindow::className() const
{
    return "EvaSysSettingWindow";
}

QMetaObject *EvaSysSettingWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaSysSettingWindow( "EvaSysSettingWindow", &EvaSysSettingWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaSysSettingWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSysSettingWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaSysSettingWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaSysSettingWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaSysSettingWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaSysSettingUIBase::staticMetaObject();
    static const QUParameter param_slot_0[] = {
	{ 0, &static_QUType_varptr, "\x04", QUParameter::In }
    };
    static const QUMethod slot_0 = {"slotDetailsUpdated", 1, param_slot_0 };
    static const QUParameter param_slot_1[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotSignatureReply", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotUpdateResult", 1, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ "isSignature", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotUpdateResult", 2, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_4 = {"slotBuddyQQShowReady", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "question", &static_QUType_QString, 0, QUParameter::In },
	{ "answer", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"slotReceivedMyAuthSettings", 3, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_6 = {"slotUpdateAuthSettingResult", 2, param_slot_6 };
    static const QUMethod slot_7 = {"slotPbFaceDefaultClicked", 0, 0 };
    static const QUMethod slot_8 = {"slotPbApplyClicked", 0, 0 };
    static const QUMethod slot_9 = {"slotPbOKClicked", 0, 0 };
    static const QUParameter param_slot_10[] = {
	{ "value", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"slotFaceSizeChanged", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "key", &static_QUType_ptr, "KShortcut", QUParameter::In }
    };
    static const QUMethod slot_11 = {"slotCapturedShortcut", 1, param_slot_11 };
    static const QUMethod slot_12 = {"slotPbThemeClicked", 0, 0 };
    static const QUMethod slot_13 = {"slotPbSoundClicked", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"slotCbbAutoNoActivated", 1, param_slot_14 };
    static const QUMethod slot_15 = {"slotPbAutoNewClicked", 0, 0 };
    static const QUMethod slot_16 = {"slotPbAutoDeleteClicked", 0, 0 };
    static const QUMethod slot_17 = {"slotTeAutoTextChanged", 0, 0 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"slotCbbQuickNoActivated", 1, param_slot_18 };
    static const QUMethod slot_19 = {"slotPbQuickNewClicked", 0, 0 };
    static const QUMethod slot_20 = {"slotPbQuickDeleteClicked", 0, 0 };
    static const QUMethod slot_21 = {"slotTeQuickTextChanged", 0, 0 };
    static const QUParameter param_slot_22[] = {
	{ "item", &static_QUType_ptr, "QListViewItem", QUParameter::In }
    };
    static const QUMethod slot_22 = {"slotSettingListItemClicked", 1, param_slot_22 };
    static const QUMethod slot_23 = {"slotPbFaceClicked", 0, 0 };
    static const QUParameter param_slot_24[] = {
	{ "item", &static_QUType_ptr, "QIconViewItem", QUParameter::In }
    };
    static const QUMethod slot_24 = {"FaceChoose", 1, param_slot_24 };
    static const QUMethod slot_25 = {"slotFirstUpdate", 0, 0 };
    static const QUMethod slot_26 = {"slotSignatureChanged", 0, 0 };
    static const QUMethod slot_27 = {"slotShopClicked", 0, 0 };
    static const QUMethod slot_28 = {"slotAlbumClicked", 0, 0 };
    static const QUMethod slot_29 = {"slotHomeClicked", 0, 0 };
    static const QUMethod slot_30 = {"slotUpdateQQShow", 0, 0 };
    static const QUParameter param_slot_31[] = {
	{ "url", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"slotLinkClicked", 1, param_slot_31 };
    static const QUMethod slot_32 = {"slotChangePwdClicked", 0, 0 };
    static const QUMethod slot_33 = {"slotUserInfoChanged", 0, 0 };
    static const QUMethod slot_34 = {"slotSysSettingChanged", 0, 0 };
    static const QUParameter param_slot_35[] = {
	{ "e", &static_QUType_ptr, "QCloseEvent", QUParameter::In }
    };
    static const QUMethod slot_35 = {"closeEvent", 1, param_slot_35 };
    static const QUMethod slot_36 = {"slotAuthChanged", 0, 0 };
    static const QUMethod slot_37 = {"slotChangePasswordClicked", 0, 0 };
    static const QUMethod slot_38 = {"slotProtectPasswordClicked", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotDetailsUpdated(QStringList)", &slot_0, QMetaData::Public },
	{ "slotSignatureReply(const bool)", &slot_1, QMetaData::Public },
	{ "slotUpdateResult(bool)", &slot_2, QMetaData::Public },
	{ "slotUpdateResult(bool,bool)", &slot_3, QMetaData::Public },
	{ "slotBuddyQQShowReady(const unsigned int)", &slot_4, QMetaData::Public },
	{ "slotReceivedMyAuthSettings(const unsigned char,const QString&,const QString&)", &slot_5, QMetaData::Public },
	{ "slotUpdateAuthSettingResult(const unsigned char,const unsigned char)", &slot_6, QMetaData::Public },
	{ "slotPbFaceDefaultClicked()", &slot_7, QMetaData::Private },
	{ "slotPbApplyClicked()", &slot_8, QMetaData::Private },
	{ "slotPbOKClicked()", &slot_9, QMetaData::Private },
	{ "slotFaceSizeChanged(int)", &slot_10, QMetaData::Private },
	{ "slotCapturedShortcut(const KShortcut&)", &slot_11, QMetaData::Private },
	{ "slotPbThemeClicked()", &slot_12, QMetaData::Private },
	{ "slotPbSoundClicked()", &slot_13, QMetaData::Private },
	{ "slotCbbAutoNoActivated(int)", &slot_14, QMetaData::Private },
	{ "slotPbAutoNewClicked()", &slot_15, QMetaData::Private },
	{ "slotPbAutoDeleteClicked()", &slot_16, QMetaData::Private },
	{ "slotTeAutoTextChanged()", &slot_17, QMetaData::Private },
	{ "slotCbbQuickNoActivated(int)", &slot_18, QMetaData::Private },
	{ "slotPbQuickNewClicked()", &slot_19, QMetaData::Private },
	{ "slotPbQuickDeleteClicked()", &slot_20, QMetaData::Private },
	{ "slotTeQuickTextChanged()", &slot_21, QMetaData::Private },
	{ "slotSettingListItemClicked(QListViewItem*)", &slot_22, QMetaData::Private },
	{ "slotPbFaceClicked()", &slot_23, QMetaData::Private },
	{ "FaceChoose(QIconViewItem*)", &slot_24, QMetaData::Private },
	{ "slotFirstUpdate()", &slot_25, QMetaData::Private },
	{ "slotSignatureChanged()", &slot_26, QMetaData::Private },
	{ "slotShopClicked()", &slot_27, QMetaData::Private },
	{ "slotAlbumClicked()", &slot_28, QMetaData::Private },
	{ "slotHomeClicked()", &slot_29, QMetaData::Private },
	{ "slotUpdateQQShow()", &slot_30, QMetaData::Private },
	{ "slotLinkClicked(const QString&)", &slot_31, QMetaData::Private },
	{ "slotChangePwdClicked()", &slot_32, QMetaData::Private },
	{ "slotUserInfoChanged()", &slot_33, QMetaData::Private },
	{ "slotSysSettingChanged()", &slot_34, QMetaData::Private },
	{ "closeEvent(QCloseEvent*)", &slot_35, QMetaData::Private },
	{ "slotAuthChanged()", &slot_36, QMetaData::Private },
	{ "slotChangePasswordClicked()", &slot_37, QMetaData::Private },
	{ "slotProtectPasswordClicked()", &slot_38, QMetaData::Private }
    };
    static const QUMethod signal_0 = {"settingChanged", 0, 0 };
    static const QUMethod signal_1 = {"faceSizeChanged", 0, 0 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestUpdate", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_3 = {"requestQQShow", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ "contents", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_4 = {"requestUpdateSignature", 1, param_signal_4 };
    static const QUMethod signal_5 = {"requestDeleteSignature", 0, 0 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_varptr, "\x04", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_6 = {"requestModify", 3, param_signal_6 };
    static const QUMethod signal_7 = {"requestMyAuthQuestionSetting", 0, 0 };
    static const QUParameter param_signal_8[] = {
	{ "quest", &static_QUType_QString, 0, QUParameter::In },
	{ "answer", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_8 = {"requestMyUpdateQuestion", 2, param_signal_8 };
    static const QMetaData signal_tbl[] = {
	{ "settingChanged()", &signal_0, QMetaData::Public },
	{ "faceSizeChanged()", &signal_1, QMetaData::Public },
	{ "requestUpdate(const unsigned int)", &signal_2, QMetaData::Public },
	{ "requestQQShow(const unsigned int)", &signal_3, QMetaData::Public },
	{ "requestUpdateSignature(const QString)", &signal_4, QMetaData::Public },
	{ "requestDeleteSignature()", &signal_5, QMetaData::Public },
	{ "requestModify(QStringList,QString,QString)", &signal_6, QMetaData::Public },
	{ "requestMyAuthQuestionSetting()", &signal_7, QMetaData::Public },
	{ "requestMyUpdateQuestion(const QString&,const QString&)", &signal_8, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaSysSettingWindow", parentObject,
	slot_tbl, 39,
	signal_tbl, 9,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaSysSettingWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaSysSettingWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaSysSettingWindow" ) )
	return this;
    return EvaSysSettingUIBase::qt_cast( clname );
}

// SIGNAL settingChanged
void EvaSysSettingWindow::settingChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 0 );
}

// SIGNAL faceSizeChanged
void EvaSysSettingWindow::faceSizeChanged()
{
    activate_signal( staticMetaObject()->signalOffset() + 1 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestUpdate
void EvaSysSettingWindow::requestUpdate( const unsigned int t0 )
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

// SIGNAL requestQQShow
void EvaSysSettingWindow::requestQQShow( const unsigned int t0 )
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

// SIGNAL requestUpdateSignature
void EvaSysSettingWindow::requestUpdateSignature( const QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 4, t0 );
}

// SIGNAL requestDeleteSignature
void EvaSysSettingWindow::requestDeleteSignature()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL requestModify
void EvaSysSettingWindow::requestModify( QStringList t0, QString t1, QString t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_varptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL requestMyAuthQuestionSetting
void EvaSysSettingWindow::requestMyAuthQuestionSetting()
{
    activate_signal( staticMetaObject()->signalOffset() + 7 );
}

// SIGNAL requestMyUpdateQuestion
void EvaSysSettingWindow::requestMyUpdateQuestion( const QString& t0, const QString& t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

bool EvaSysSettingWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotDetailsUpdated((QStringList)(*((QStringList*)static_QUType_ptr.get(_o+1)))); break;
    case 1: slotSignatureReply((const bool)static_QUType_bool.get(_o+1)); break;
    case 2: slotUpdateResult((bool)static_QUType_bool.get(_o+1)); break;
    case 3: slotUpdateResult((bool)static_QUType_bool.get(_o+1),(bool)static_QUType_bool.get(_o+2)); break;
    case 4: slotBuddyQQShowReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 5: slotReceivedMyAuthSettings((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const QString&)static_QUType_QString.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 6: slotUpdateAuthSettingResult((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2)))); break;
    case 7: slotPbFaceDefaultClicked(); break;
    case 8: slotPbApplyClicked(); break;
    case 9: slotPbOKClicked(); break;
    case 10: slotFaceSizeChanged((int)static_QUType_int.get(_o+1)); break;
    case 11: slotCapturedShortcut((const KShortcut&)*((const KShortcut*)static_QUType_ptr.get(_o+1))); break;
    case 12: slotPbThemeClicked(); break;
    case 13: slotPbSoundClicked(); break;
    case 14: slotCbbAutoNoActivated((int)static_QUType_int.get(_o+1)); break;
    case 15: slotPbAutoNewClicked(); break;
    case 16: slotPbAutoDeleteClicked(); break;
    case 17: slotTeAutoTextChanged(); break;
    case 18: slotCbbQuickNoActivated((int)static_QUType_int.get(_o+1)); break;
    case 19: slotPbQuickNewClicked(); break;
    case 20: slotPbQuickDeleteClicked(); break;
    case 21: slotTeQuickTextChanged(); break;
    case 22: slotSettingListItemClicked((QListViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 23: slotPbFaceClicked(); break;
    case 24: FaceChoose((QIconViewItem*)static_QUType_ptr.get(_o+1)); break;
    case 25: slotFirstUpdate(); break;
    case 26: slotSignatureChanged(); break;
    case 27: slotShopClicked(); break;
    case 28: slotAlbumClicked(); break;
    case 29: slotHomeClicked(); break;
    case 30: slotUpdateQQShow(); break;
    case 31: slotLinkClicked((const QString&)static_QUType_QString.get(_o+1)); break;
    case 32: slotChangePwdClicked(); break;
    case 33: slotUserInfoChanged(); break;
    case 34: slotSysSettingChanged(); break;
    case 35: closeEvent((QCloseEvent*)static_QUType_ptr.get(_o+1)); break;
    case 36: slotAuthChanged(); break;
    case 37: slotChangePasswordClicked(); break;
    case 38: slotProtectPasswordClicked(); break;
    default:
	return EvaSysSettingUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaSysSettingWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: settingChanged(); break;
    case 1: faceSizeChanged(); break;
    case 2: requestUpdate((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: requestQQShow((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 4: requestUpdateSignature((const QString)static_QUType_QString.get(_o+1)); break;
    case 5: requestDeleteSignature(); break;
    case 6: requestModify((QStringList)(*((QStringList*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 7: requestMyAuthQuestionSetting(); break;
    case 8: requestMyUpdateQuestion((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    default:
	return EvaSysSettingUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaSysSettingWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaSysSettingUIBase::qt_property( id, f, v);
}

bool EvaSysSettingWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
