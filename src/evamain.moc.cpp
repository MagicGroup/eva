/****************************************************************************
** EvaMain meta object code from reading C++ file 'evamain.h'
**
** Created: Tue Feb 8 23:56:32 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evamain.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaMain::className() const
{
    return "EvaMain";
}

QMetaObject *EvaMain::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaMain( "EvaMain", &EvaMain::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaMain::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaMain", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaMain::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaMain", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaMain::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"slotIdleTimeUp", 0, 0 };
    static const QUMethod slot_1 = {"slotIdleBack", 0, 0 };
    static const QUMethod slot_2 = {"slotLoadQunListReady", 0, 0 };
    static const QUMethod slot_3 = {"doQuit", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out }
    };
    static const QUMethod slot_4 = {"doInitUI", 1, param_slot_4 };
    static const QUMethod slot_5 = {"initMenus", 0, 0 };
    static const QUMethod slot_6 = {"doSlotConnection", 0, 0 };
    static const QUMethod slot_7 = {"slotGetOnlineStatus", 0, 0 };
    static const QUMethod slot_8 = {"slotSetupUser", 0, 0 };
    static const QUMethod slot_9 = {"slotSetupNetwork", 0, 0 };
    static const QUMethod slot_10 = {"slotSetupWindowManager", 0, 0 };
    static const QUParameter param_slot_11[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"slotNetworkException", 1, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"slotPacketException", 1, param_slot_12 };
    static const QUMethod slot_13 = {"slotDoLoginClick", 0, 0 };
    static const QUMethod slot_14 = {"slotServerBusy", 0, 0 };
    static const QUMethod slot_15 = {"slotSetupEvaClient", 0, 0 };
    static const QUMethod slot_16 = {"slotFetchQQServer", 0, 0 };
    static const QUParameter param_slot_17[] = {
	{ "addr", &static_QUType_ptr, "QHostAddress", QUParameter::In }
    };
    static const QUMethod slot_17 = {"slotGotServer", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ "msg", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"slotKickedOut", 1, param_slot_18 };
    static const QUMethod slot_19 = {"slotOnlineReady", 0, 0 };
    static const QUMethod slot_20 = {"slotInvisibleReady", 0, 0 };
    static const QUMethod slot_21 = {"slotLeaveReady", 0, 0 };
    static const QUMethod slot_22 = {"slotOfflineReady", 0, 0 };
    static const QUParameter param_slot_23[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_23 = {"slotFriendStatusChanged", 1, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In },
	{ "red", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_24 = {"slotTxtMessage", 11, param_slot_24 };
    static const QUMethod slot_25 = {"slotDoLogin", 0, 0 };
    static const QUMethod slot_26 = {"slotDoCancel", 0, 0 };
    static const QUMethod slot_27 = {"slotDoOnline", 0, 0 };
    static const QUMethod slot_28 = {"slotDoOffline", 0, 0 };
    static const QUMethod slot_29 = {"slotDoLeave", 0, 0 };
    static const QUParameter param_slot_30[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_30 = {"slotAutoReplyMenuActivated", 1, param_slot_30 };
    static const QUMethod slot_31 = {"slotDoInvisible", 0, 0 };
    static const QUMethod slot_32 = {"slotDoLogout", 0, 0 };
    static const QUMethod slot_33 = {"slotDoDownloadGroups", 0, 0 };
    static const QUMethod slot_34 = {"slotDoUploadGroups", 0, 0 };
    static const QUParameter param_slot_35[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"slotFriendGroupsUploadReady", 1, param_slot_35 };
    static const QUMethod slot_36 = {"slotDoDownloadBuddies", 0, 0 };
    static const QUMethod slot_37 = {"slotDoChangeUser", 0, 0 };
    static const QUParameter param_slot_38[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_38 = {"slotGroupDeleted", 1, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_39 = {"slotGroupRenamed", 2, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_40 = {"slotGroupChanged", 2, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_41 = {"slotRequestDetails", 1, param_slot_41 };
    static const QUParameter param_slot_42[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_42 = {"slotRequestLevel", 1, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_43 = {"slotRequestChat", 1, param_slot_43 };
    static const QUParameter param_slot_44[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_44 = {"slotRequestSendFile", 1, param_slot_44 };
    static const QUParameter param_slot_45[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_45 = {"slotRequestHistory", 1, param_slot_45 };
    static const QUParameter param_slot_46[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_46 = {"slotRequestQQShow", 1, param_slot_46 };
    static const QUMethod slot_47 = {"slotRequestMyQQShow", 0, 0 };
    static const QUParameter param_slot_48[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_48 = {"slotQQShowReady", 1, param_slot_48 };
    static const QUMethod slot_49 = {"slotRequestSearch", 0, 0 };
    static const QUMethod slot_50 = {"slotRequestSystemMessages", 0, 0 };
    static const QUParameter param_slot_51[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_51 = {"slotRequestDelete", 1, param_slot_51 };
    static const QUParameter param_slot_52[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_52 = {"slotDeleteBuddyReady", 2, param_slot_52 };
    static const QUMethod slot_53 = {"slotRequestSystemSettingWindow", 0, 0 };
    static const QUParameter param_slot_54[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_54 = {"slotDeleteMeFrom", 1, param_slot_54 };
    static const QUParameter param_slot_55[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_55 = {"slotDeleteMeReply", 1, param_slot_55 };
    static const QUParameter param_slot_56[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_56 = {"slotRequestAddBuddy", 1, param_slot_56 };
    static const QUParameter param_slot_57[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_57 = {"slotQunInfomationReady", 3, param_slot_57 };
    static const QUParameter param_slot_58[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_58 = {"slotRequestQunDetails", 1, param_slot_58 };
    static const QUParameter param_slot_59[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_59 = {"slotRequestQunHistory", 1, param_slot_59 };
    static const QUParameter param_slot_60[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_60 = {"slotRequestQunChat", 1, param_slot_60 };
    static const QUParameter param_slot_61[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_varptr, "\x1c", QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_61 = {"slotReceivedQunMessage", 11, param_slot_61 };
    static const QUParameter param_slot_62[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_62 = {"slotQunSystemMessageRequest", 2, param_slot_62 };
    static const QUParameter param_slot_63[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "fileName", &static_QUType_QString, 0, QUParameter::In },
	{ "tmpFileName", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_63 = {"slotQunPictureReady", 3, param_slot_63 };
    static const QUParameter param_slot_64[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "ok", &static_QUType_bool, 0, QUParameter::In },
	{ "qq", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "realName", &static_QUType_QString, 0, QUParameter::In },
	{ "gender", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "phone", &static_QUType_QString, 0, QUParameter::In },
	{ "email", &static_QUType_QString, 0, QUParameter::In },
	{ "memo", &static_QUType_QString, 0, QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_64 = {"slotRequestQunCardReady", 9, param_slot_64 };
    static const QUParameter param_slot_65[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_65 = {"slotDoQunExit", 1, param_slot_65 };
    static const QUParameter param_slot_66[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_66 = {"slotQunExitReply", 3, param_slot_66 };
    static const QUParameter param_slot_67[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_67 = {"slotQunCreateFailed", 1, param_slot_67 };
    static const QUMethod slot_68 = {"slotQunCreate", 0, 0 };
    static const QUParameter param_slot_69[] = {
	{ "qq", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "signature", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_69 = {"slotFriendSignatureChanged", 3, param_slot_69 };
    static const QUParameter param_slot_70[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "type", &static_QUType_ptr, "signed char", QUParameter::In }
    };
    static const QUMethod slot_70 = {"slotUpdateQunMessageSettings", 2, param_slot_70 };
    static const QUMethod slot_71 = {"slotUserSettingChanged", 0, 0 };
    static const QUMethod slot_72 = {"slotFaceSizeChanged", 0, 0 };
    static const QUMethod slot_73 = {"slotUpdateShortcut", 0, 0 };
    static const QUMethod slot_74 = {"slotShotcutKeyPressed", 0, 0 };
    static const QUParameter param_slot_75[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "face", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_75 = {"slotAddAnonymous", 2, param_slot_75 };
    static const QUMethod slot_76 = {"slotExtraInfoReady", 0, 0 };
    static const QUParameter param_slot_77[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "memo", &static_QUType_ptr, "MemoItem", QUParameter::In }
    };
    static const QUMethod slot_77 = {"slotUserMemoChanged", 2, param_slot_77 };
    static const QUParameter param_slot_78[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_78 = {"slotModifyMemo", 1, param_slot_78 };
    static const QUParameter param_slot_79[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "QValueList<QString>", QUParameter::In },
	{ 0, &static_QUType_ptr, "QValueList<unsigned int>", QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_79 = {"slotFileTransferSend", 5, param_slot_79 };
    static const QUParameter param_slot_80[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_80 = {"slotFileTransferAccept", 4, param_slot_80 };
    static const QUParameter param_slot_81[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_81 = {"slotFileTransferCancel", 2, param_slot_81 };
    static const QUParameter param_slot_82[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_82 = {"slotReceivedFileRequest", 5, param_slot_82 };
    static const QUParameter param_slot_83[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_83 = {"slotReceivedFileAccepted", 5, param_slot_83 };
    static const QUParameter param_slot_84[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_84 = {"slotNotifyTransferStatus", 5, param_slot_84 };
    static const QUParameter param_slot_85[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_85 = {"slotReceivedFileAgentInfo", 6, param_slot_85 };
    static const QUParameter param_slot_86[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isSender", &static_QUType_bool, 0, QUParameter::In },
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "wanIp1", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "wanPort1", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "wanIp2", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "wanPort2", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "wanIp3", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "wanPort3", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "lanIp1", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "lanPort1", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "lanIp2", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "lanPort2", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "lanIp3", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "lanPort3", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "syncIp", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "syncPort", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "syncSession", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_86 = {"slotReceivedFileNotifyIpEx", 19, param_slot_86 };
    static const QUParameter param_slot_87[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_87 = {"slotNotifyAddressRequest", 7, param_slot_87 };
    static const QUParameter param_slot_88[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "face", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "group", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_88 = {"slotBuddyAdded", 4, param_slot_88 };
    static const QUMethod slot_89 = {"slotShowScriptManager", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "slotIdleTimeUp()", &slot_0, QMetaData::Private },
	{ "slotIdleBack()", &slot_1, QMetaData::Private },
	{ "slotLoadQunListReady()", &slot_2, QMetaData::Private },
	{ "doQuit()", &slot_3, QMetaData::Private },
	{ "doInitUI()", &slot_4, QMetaData::Private },
	{ "initMenus()", &slot_5, QMetaData::Private },
	{ "doSlotConnection()", &slot_6, QMetaData::Private },
	{ "slotGetOnlineStatus()", &slot_7, QMetaData::Private },
	{ "slotSetupUser()", &slot_8, QMetaData::Private },
	{ "slotSetupNetwork()", &slot_9, QMetaData::Private },
	{ "slotSetupWindowManager()", &slot_10, QMetaData::Private },
	{ "slotNetworkException(int)", &slot_11, QMetaData::Private },
	{ "slotPacketException(int)", &slot_12, QMetaData::Private },
	{ "slotDoLoginClick()", &slot_13, QMetaData::Private },
	{ "slotServerBusy()", &slot_14, QMetaData::Private },
	{ "slotSetupEvaClient()", &slot_15, QMetaData::Private },
	{ "slotFetchQQServer()", &slot_16, QMetaData::Private },
	{ "slotGotServer(QHostAddress)", &slot_17, QMetaData::Private },
	{ "slotKickedOut(const QString)", &slot_18, QMetaData::Private },
	{ "slotOnlineReady()", &slot_19, QMetaData::Private },
	{ "slotInvisibleReady()", &slot_20, QMetaData::Private },
	{ "slotLeaveReady()", &slot_21, QMetaData::Private },
	{ "slotOfflineReady()", &slot_22, QMetaData::Private },
	{ "slotFriendStatusChanged(unsigned int)", &slot_23, QMetaData::Private },
	{ "slotTxtMessage(unsigned int,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &slot_24, QMetaData::Private },
	{ "slotDoLogin()", &slot_25, QMetaData::Private },
	{ "slotDoCancel()", &slot_26, QMetaData::Private },
	{ "slotDoOnline()", &slot_27, QMetaData::Private },
	{ "slotDoOffline()", &slot_28, QMetaData::Private },
	{ "slotDoLeave()", &slot_29, QMetaData::Private },
	{ "slotAutoReplyMenuActivated(int)", &slot_30, QMetaData::Private },
	{ "slotDoInvisible()", &slot_31, QMetaData::Private },
	{ "slotDoLogout()", &slot_32, QMetaData::Private },
	{ "slotDoDownloadGroups()", &slot_33, QMetaData::Private },
	{ "slotDoUploadGroups()", &slot_34, QMetaData::Private },
	{ "slotFriendGroupsUploadReady(bool)", &slot_35, QMetaData::Private },
	{ "slotDoDownloadBuddies()", &slot_36, QMetaData::Private },
	{ "slotDoChangeUser()", &slot_37, QMetaData::Private },
	{ "slotGroupDeleted(const int)", &slot_38, QMetaData::Private },
	{ "slotGroupRenamed(QString,int)", &slot_39, QMetaData::Private },
	{ "slotGroupChanged(const unsigned int,int)", &slot_40, QMetaData::Private },
	{ "slotRequestDetails(const unsigned int)", &slot_41, QMetaData::Private },
	{ "slotRequestLevel(const unsigned int)", &slot_42, QMetaData::Private },
	{ "slotRequestChat(const unsigned int)", &slot_43, QMetaData::Private },
	{ "slotRequestSendFile(const unsigned int)", &slot_44, QMetaData::Private },
	{ "slotRequestHistory(const unsigned int)", &slot_45, QMetaData::Private },
	{ "slotRequestQQShow(const unsigned int)", &slot_46, QMetaData::Private },
	{ "slotRequestMyQQShow()", &slot_47, QMetaData::Private },
	{ "slotQQShowReady(const unsigned int)", &slot_48, QMetaData::Private },
	{ "slotRequestSearch()", &slot_49, QMetaData::Private },
	{ "slotRequestSystemMessages()", &slot_50, QMetaData::Private },
	{ "slotRequestDelete(const unsigned int)", &slot_51, QMetaData::Private },
	{ "slotDeleteBuddyReady(unsigned int,bool)", &slot_52, QMetaData::Private },
	{ "slotRequestSystemSettingWindow()", &slot_53, QMetaData::Private },
	{ "slotDeleteMeFrom(const unsigned int)", &slot_54, QMetaData::Private },
	{ "slotDeleteMeReply(bool)", &slot_55, QMetaData::Private },
	{ "slotRequestAddBuddy(const unsigned int)", &slot_56, QMetaData::Private },
	{ "slotQunInfomationReady(const unsigned int,const bool,QString)", &slot_57, QMetaData::Private },
	{ "slotRequestQunDetails(const unsigned int)", &slot_58, QMetaData::Private },
	{ "slotRequestQunHistory(const unsigned int)", &slot_59, QMetaData::Private },
	{ "slotRequestQunChat(const unsigned int)", &slot_60, QMetaData::Private },
	{ "slotReceivedQunMessage(unsigned int,unsigned int,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &slot_61, QMetaData::Private },
	{ "slotQunSystemMessageRequest(const unsigned int,QString)", &slot_62, QMetaData::Private },
	{ "slotQunPictureReady(const unsigned int,const QString,const QString)", &slot_63, QMetaData::Private },
	{ "slotRequestQunCardReady(const unsigned int,const bool,const unsigned int,QString,const unsigned char,QString,QString,QString,QString)", &slot_64, QMetaData::Private },
	{ "slotDoQunExit(const unsigned int)", &slot_65, QMetaData::Private },
	{ "slotQunExitReply(const unsigned int,const bool,QString)", &slot_66, QMetaData::Private },
	{ "slotQunCreateFailed(QString)", &slot_67, QMetaData::Private },
	{ "slotQunCreate()", &slot_68, QMetaData::Private },
	{ "slotFriendSignatureChanged(const unsigned int,const QDateTime,const QString)", &slot_69, QMetaData::Private },
	{ "slotUpdateQunMessageSettings(const unsigned int,const signed char)", &slot_70, QMetaData::Private },
	{ "slotUserSettingChanged()", &slot_71, QMetaData::Private },
	{ "slotFaceSizeChanged()", &slot_72, QMetaData::Private },
	{ "slotUpdateShortcut()", &slot_73, QMetaData::Private },
	{ "slotShotcutKeyPressed()", &slot_74, QMetaData::Private },
	{ "slotAddAnonymous(const unsigned int,const unsigned short)", &slot_75, QMetaData::Private },
	{ "slotExtraInfoReady()", &slot_76, QMetaData::Private },
	{ "slotUserMemoChanged(const unsigned int,const MemoItem&)", &slot_77, QMetaData::Private },
	{ "slotModifyMemo(const unsigned int)", &slot_78, QMetaData::Private },
	{ "slotFileTransferSend(const unsigned int,const unsigned int,const QValueList<QString>,const QValueList<unsigned int>,const unsigned char)", &slot_79, QMetaData::Private },
	{ "slotFileTransferAccept(const unsigned int,const unsigned int,const QString,const unsigned char)", &slot_80, QMetaData::Private },
	{ "slotFileTransferCancel(const unsigned int,const unsigned int)", &slot_81, QMetaData::Private },
	{ "slotReceivedFileRequest(const unsigned int,const unsigned int,const QString,const int,const unsigned char)", &slot_82, QMetaData::Private },
	{ "slotReceivedFileAccepted(const unsigned int,const unsigned int,const unsigned int,const bool,const unsigned char)", &slot_83, QMetaData::Private },
	{ "slotNotifyTransferStatus(const unsigned int,const unsigned int,const unsigned int,const unsigned int,const int)", &slot_84, QMetaData::Private },
	{ "slotReceivedFileAgentInfo(const unsigned int,const unsigned int,const unsigned int,const unsigned int,const unsigned short,const unsigned char*)", &slot_85, QMetaData::Private },
	{ "slotReceivedFileNotifyIpEx(const unsigned int,const bool,const unsigned int,const unsigned char,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int)", &slot_86, QMetaData::Private },
	{ "slotNotifyAddressRequest(const unsigned int,const unsigned int,const unsigned int,const unsigned int,const unsigned short,const unsigned int,const unsigned short)", &slot_87, QMetaData::Private },
	{ "slotBuddyAdded(const unsigned int,const QString,const unsigned short,const int)", &slot_88, QMetaData::Private },
	{ "slotShowScriptManager()", &slot_89, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaMain", parentObject,
	slot_tbl, 90,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaMain.setMetaObject( metaObj );
    return metaObj;
}

void* EvaMain::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaMain" ) )
	return this;
    if ( !qstrcmp( clname, "EvaDCOPActionsInterface" ) )
	return (EvaDCOPActionsInterface*)this;
    return QObject::qt_cast( clname );
}

bool EvaMain::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: slotIdleTimeUp(); break;
    case 1: slotIdleBack(); break;
    case 2: slotLoadQunListReady(); break;
    case 3: doQuit(); break;
    case 4: static_QUType_bool.set(_o,doInitUI()); break;
    case 5: initMenus(); break;
    case 6: doSlotConnection(); break;
    case 7: slotGetOnlineStatus(); break;
    case 8: slotSetupUser(); break;
    case 9: slotSetupNetwork(); break;
    case 10: slotSetupWindowManager(); break;
    case 11: slotNetworkException((int)static_QUType_int.get(_o+1)); break;
    case 12: slotPacketException((int)static_QUType_int.get(_o+1)); break;
    case 13: slotDoLoginClick(); break;
    case 14: slotServerBusy(); break;
    case 15: slotSetupEvaClient(); break;
    case 16: slotFetchQQServer(); break;
    case 17: slotGotServer((QHostAddress)(*((QHostAddress*)static_QUType_ptr.get(_o+1)))); break;
    case 18: slotKickedOut((const QString)static_QUType_QString.get(_o+1)); break;
    case 19: slotOnlineReady(); break;
    case 20: slotInvisibleReady(); break;
    case 21: slotLeaveReady(); break;
    case 22: slotOfflineReady(); break;
    case 23: slotFriendStatusChanged((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 24: slotTxtMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10))),(const char)(*((const char*)static_QUType_ptr.get(_o+11)))); break;
    case 25: slotDoLogin(); break;
    case 26: slotDoCancel(); break;
    case 27: slotDoOnline(); break;
    case 28: slotDoOffline(); break;
    case 29: slotDoLeave(); break;
    case 30: slotAutoReplyMenuActivated((int)static_QUType_int.get(_o+1)); break;
    case 31: slotDoInvisible(); break;
    case 32: slotDoLogout(); break;
    case 33: slotDoDownloadGroups(); break;
    case 34: slotDoUploadGroups(); break;
    case 35: slotFriendGroupsUploadReady((bool)static_QUType_bool.get(_o+1)); break;
    case 36: slotDoDownloadBuddies(); break;
    case 37: slotDoChangeUser(); break;
    case 38: slotGroupDeleted((const int)static_QUType_int.get(_o+1)); break;
    case 39: slotGroupRenamed((QString)static_QUType_QString.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 40: slotGroupChanged((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(int)static_QUType_int.get(_o+2)); break;
    case 41: slotRequestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 42: slotRequestLevel((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 43: slotRequestChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 44: slotRequestSendFile((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 45: slotRequestHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 46: slotRequestQQShow((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 47: slotRequestMyQQShow(); break;
    case 48: slotQQShowReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 49: slotRequestSearch(); break;
    case 50: slotRequestSystemMessages(); break;
    case 51: slotRequestDelete((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 52: slotDeleteBuddyReady((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 53: slotRequestSystemSettingWindow(); break;
    case 54: slotDeleteMeFrom((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 55: slotDeleteMeReply((bool)static_QUType_bool.get(_o+1)); break;
    case 56: slotRequestAddBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 57: slotQunInfomationReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 58: slotRequestQunDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 59: slotRequestQunHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 60: slotRequestQunChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 61: slotReceivedQunMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+2))),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10))),(const char)(*((const char*)static_QUType_ptr.get(_o+11)))); break;
    case 62: slotQunSystemMessageRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2)); break;
    case 63: slotQunPictureReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const QString)static_QUType_QString.get(_o+3)); break;
    case 64: slotRequestQunCardReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5))),(QString)static_QUType_QString.get(_o+6),(QString)static_QUType_QString.get(_o+7),(QString)static_QUType_QString.get(_o+8),(QString)static_QUType_QString.get(_o+9)); break;
    case 65: slotDoQunExit((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 66: slotQunExitReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 67: slotQunCreateFailed((QString)static_QUType_QString.get(_o+1)); break;
    case 68: slotQunCreate(); break;
    case 69: slotFriendSignatureChanged((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QDateTime)(*((const QDateTime*)static_QUType_ptr.get(_o+2))),(const QString)static_QUType_QString.get(_o+3)); break;
    case 70: slotUpdateQunMessageSettings((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const signed char)(*((const signed char*)static_QUType_ptr.get(_o+2)))); break;
    case 71: slotUserSettingChanged(); break;
    case 72: slotFaceSizeChanged(); break;
    case 73: slotUpdateShortcut(); break;
    case 74: slotShotcutKeyPressed(); break;
    case 75: slotAddAnonymous((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+2)))); break;
    case 76: slotExtraInfoReady(); break;
    case 77: slotUserMemoChanged((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const MemoItem&)*((const MemoItem*)static_QUType_ptr.get(_o+2))); break;
    case 78: slotModifyMemo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 79: slotFileTransferSend((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QValueList<QString>)(*((const QValueList<QString>*)static_QUType_ptr.get(_o+3))),(const QValueList<unsigned int>)(*((const QValueList<unsigned int>*)static_QUType_ptr.get(_o+4))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5)))); break;
    case 80: slotFileTransferAccept((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QString)static_QUType_QString.get(_o+3),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4)))); break;
    case 81: slotFileTransferCancel((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2)))); break;
    case 82: slotReceivedFileRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QString)static_QUType_QString.get(_o+3),(const int)static_QUType_int.get(_o+4),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5)))); break;
    case 83: slotReceivedFileAccepted((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5)))); break;
    case 84: slotNotifyTransferStatus((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const int)static_QUType_int.get(_o+5)); break;
    case 85: slotReceivedFileAgentInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned char*)static_QUType_ptr.get(_o+6)); break;
    case 86: slotReceivedFileNotifyIpEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+5))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+6))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+7))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+8))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+9))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+10))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+11))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+12))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+13))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+14))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+15))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+16))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+17))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+18))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+19)))); break;
    case 87: slotNotifyAddressRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+6))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+7)))); break;
    case 88: slotBuddyAdded((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+3))),(const int)static_QUType_int.get(_o+4)); break;
    case 89: slotShowScriptManager(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaMain::qt_emit( int _id, QUObject* _o )
{
    return QObject::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool EvaMain::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaMain::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
