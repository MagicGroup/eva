/****************************************************************************
** EvaPacketManager meta object code from reading C++ file 'evapacketmanager.h'
**
** Created: Tue Feb 8 23:56:06 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evapacketmanager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaPacketManager::className() const
{
    return "EvaPacketManager";
}

QMetaObject *EvaPacketManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaPacketManager( "EvaPacketManager", &EvaPacketManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaPacketManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaPacketManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaPacketManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaPacketManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaPacketManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"doRequestLoginToken", 0, 0 };
    static const QUMethod slot_1 = {"doRequestLoginTokenEx", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "code", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"doRequestLoginTokenEx", 1, param_slot_2 };
    static const QUMethod slot_3 = {"doLogin", 0, 0 };
    static const QUMethod slot_4 = {"doLogout", 0, 0 };
    static const QUParameter param_slot_5[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_5 = {"doGetUserInfo", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "info", &static_QUType_varptr, "\x04", QUParameter::In }
    };
    static const QUMethod slot_6 = {"doModifyDetails", 1, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "info", &static_QUType_varptr, "\x04", QUParameter::In },
	{ "oldPwd", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_7 = {"doModifyDetails", 2, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "info", &static_QUType_varptr, "\x04", QUParameter::In },
	{ "oldPwd", &static_QUType_QString, 0, QUParameter::In },
	{ "newPwd", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_8 = {"doModifyDetails", 3, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "newStatus", &static_QUType_ptr, "EvaUser::UserStatus", QUParameter::In }
    };
    static const QUMethod slot_9 = {"doChangeStatus", 1, param_slot_9 };
    static const QUMethod slot_10 = {"doRequestFileAgentKey", 0, 0 };
    static const QUMethod slot_11 = {"doGetOnlineFriends", 0, 0 };
    static const QUMethod slot_12 = {"doGetAllFriends", 0, 0 };
    static const QUMethod slot_13 = {"doGetAllLevels", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_14 = {"requestFriendLevel", 1, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_15 = {"doSendMessage", 3, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_16 = {"doSendMessage", 4, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"doSendMessage", 5, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"doSendMessage", 6, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"doSendMessage", 7, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_20 = {"doSendMessage", 8, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_21 = {"doSendMessage", 9, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In },
	{ "red", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_22 = {"doSendMessage", 10, param_slot_22 };
    static const QUMethod slot_23 = {"doGetGroups", 0, 0 };
    static const QUMethod slot_24 = {"doUploadGroups", 0, 0 };
    static const QUParameter param_slot_25[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_25 = {"doDeleteBuddy", 1, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_26 = {"doAddBuddy", 1, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"doAddAuthBuddy", 2, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_28 = {"doApproveBuddy", 1, param_slot_28 };
    static const QUParameter param_slot_29[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_29 = {"doRejectBuddy", 2, param_slot_29 };
    static const QUMethod slot_30 = {"doSearchUsers", 0, 0 };
    static const QUParameter param_slot_31[] = {
	{ "isSearchAll", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_31 = {"doSearchUsers", 1, param_slot_31 };
    static const QUParameter param_slot_32[] = {
	{ "isSearchAll", &static_QUType_bool, 0, QUParameter::In },
	{ "page", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"doSearchUsers", 2, param_slot_32 };
    static const QUParameter param_slot_33[] = {
	{ "isSearchAll", &static_QUType_bool, 0, QUParameter::In },
	{ "page", &static_QUType_QString, 0, QUParameter::In },
	{ "id", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_33 = {"doSearchUsers", 3, param_slot_33 };
    static const QUParameter param_slot_34[] = {
	{ "isSearchAll", &static_QUType_bool, 0, QUParameter::In },
	{ "page", &static_QUType_QString, 0, QUParameter::In },
	{ "id", &static_QUType_QString, 0, QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_34 = {"doSearchUsers", 4, param_slot_34 };
    static const QUParameter param_slot_35[] = {
	{ "isSearchAll", &static_QUType_bool, 0, QUParameter::In },
	{ "page", &static_QUType_QString, 0, QUParameter::In },
	{ "id", &static_QUType_QString, 0, QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "email", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_35 = {"doSearchUsers", 5, param_slot_35 };
    static const QUParameter param_slot_36[] = {
	{ "isSearchAll", &static_QUType_bool, 0, QUParameter::In },
	{ "page", &static_QUType_QString, 0, QUParameter::In },
	{ "id", &static_QUType_QString, 0, QUParameter::In },
	{ "nick", &static_QUType_QString, 0, QUParameter::In },
	{ "email", &static_QUType_QString, 0, QUParameter::In },
	{ "match", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_36 = {"doSearchUsers", 6, param_slot_36 };
    static const QUParameter param_slot_37[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_37 = {"doDeleteMeFrom", 1, param_slot_37 };
    static const QUParameter param_slot_38[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_38 = {"doRequestQunInfo", 1, param_slot_38 };
    static const QUParameter param_slot_39[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "l", &static_QUType_ptr, "std::list<unsigned int>", QUParameter::In }
    };
    static const QUMethod slot_39 = {"doRequestQunMemberInfo", 2, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_40 = {"doRequestQunOnlineMembers", 1, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut }
    };
    static const QUMethod slot_41 = {"doSendQunMessage", 2, param_slot_41 };
    static const QUParameter param_slot_42[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_42 = {"doSendQunMessage", 3, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_43 = {"doSendQunMessage", 4, param_slot_43 };
    static const QUParameter param_slot_44[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_44 = {"doSendQunMessage", 5, param_slot_44 };
    static const QUParameter param_slot_45[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_45 = {"doSendQunMessage", 6, param_slot_45 };
    static const QUParameter param_slot_46[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_46 = {"doSendQunMessage", 7, param_slot_46 };
    static const QUParameter param_slot_47[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_47 = {"doSendQunMessage", 8, param_slot_47 };
    static const QUParameter param_slot_48[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "fontSize", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In },
	{ "red", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_48 = {"doSendQunMessage", 9, param_slot_48 };
    static const QUParameter param_slot_49[] = {
	{ "extID", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_49 = {"doSearchQun", 1, param_slot_49 };
    static const QUParameter param_slot_50[] = {
	{ "qunID", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_50 = {"doJoinQun", 1, param_slot_50 };
    static const QUParameter param_slot_51[] = {
	{ "qunID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_51 = {"doJoinQunAuth", 4, param_slot_51 };
    static const QUParameter param_slot_52[] = {
	{ "qq", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "token", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_52 = {"doApproveQun", 4, param_slot_52 };
    static const QUParameter param_slot_53[] = {
	{ "qq", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In },
	{ "token", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_53 = {"doRejectQun", 5, param_slot_53 };
    static const QUParameter param_slot_54[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "cate", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "name", &static_QUType_QString, 0, QUParameter::In },
	{ "notice", &static_QUType_QString, 0, QUParameter::In },
	{ "description", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_54 = {"doModifyQunInfo", 6, param_slot_54 };
    static const QUParameter param_slot_55[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "qqID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "name", &static_QUType_QString, 0, QUParameter::In },
	{ "gender", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "phone", &static_QUType_QString, 0, QUParameter::In },
	{ "email", &static_QUType_QString, 0, QUParameter::In },
	{ "memo", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_55 = {"doModifyQunCard", 7, param_slot_55 };
    static const QUParameter param_slot_56[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "qq", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isSetAdmin", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_56 = {"doQunSetAdmin", 3, param_slot_56 };
    static const QUParameter param_slot_57[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "qq", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_57 = {"doQunTransfer", 2, param_slot_57 };
    static const QUParameter param_slot_58[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "members", &static_QUType_ptr, "std::list<unsigned int>", QUParameter::In },
	{ "isAdd", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_58 = {"doModifyQunMembers", 3, param_slot_58 };
    static const QUParameter param_slot_59[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "qq", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_59 = {"doRequestQunCard", 2, param_slot_59 };
    static const QUParameter param_slot_60[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_60 = {"doQunExit", 1, param_slot_60 };
    static const QUParameter param_slot_61[] = {
	{ "name", &static_QUType_QString, 0, QUParameter::In },
	{ "category", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "notice", &static_QUType_QString, 0, QUParameter::In },
	{ "description", &static_QUType_QString, 0, QUParameter::In },
	{ "members", &static_QUType_ptr, "std::list<unsigned int>", QUParameter::In }
    };
    static const QUMethod slot_61 = {"doQunCreate", 6, param_slot_61 };
    static const QUParameter param_slot_62[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_62 = {"doRequestQunRealNames", 1, param_slot_62 };
    static const QUMethod slot_63 = {"doRequestExtraInfo", 0, 0 };
    static const QUParameter param_slot_64[] = {
	{ "signature", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_64 = {"doModifySignature", 1, param_slot_64 };
    static const QUMethod slot_65 = {"doDeleteSignature", 0, 0 };
    static const QUParameter param_slot_66[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out }
    };
    static const QUMethod slot_66 = {"doRequestSignature", 1, param_slot_66 };
    static const QUParameter param_slot_67[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "start", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_67 = {"doRequestSignature", 2, param_slot_67 };
    static const QUParameter param_slot_68[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::Out },
	{ "start", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isSingleContact", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_68 = {"doRequestSignature", 3, param_slot_68 };
    static const QUParameter param_slot_69[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "memo", &static_QUType_ptr, "MemoItem", QUParameter::In }
    };
    static const QUMethod slot_69 = {"doUploadMemo", 2, param_slot_69 };
    static const QUParameter param_slot_70[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_70 = {"doRemoveMemo", 1, param_slot_70 };
    static const QUParameter param_slot_71[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_71 = {"doDownloadMemo", 1, param_slot_71 };
    static const QUParameter param_slot_72[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "fileName", &static_QUType_QString, 0, QUParameter::In },
	{ "fileSize", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "short", QUParameter::In }
    };
    static const QUMethod slot_72 = {"doSendFileUdpRequest", 4, param_slot_72 };
    static const QUParameter param_slot_73[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "fileName", &static_QUType_QString, 0, QUParameter::In },
	{ "fileSize", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "short", QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_73 = {"doSendFileUdpRequest", 5, param_slot_73 };
    static const QUParameter param_slot_74[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "short", QUParameter::In },
	{ "wanIp", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_74 = {"doAcceptFileRequest", 3, param_slot_74 };
    static const QUParameter param_slot_75[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "short", QUParameter::In },
	{ "wanIp", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_75 = {"doAcceptFileRequest", 4, param_slot_75 };
    static const QUParameter param_slot_76[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "short", QUParameter::In }
    };
    static const QUMethod slot_76 = {"doCancelFileRequest", 2, param_slot_76 };
    static const QUParameter param_slot_77[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "short", QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_77 = {"doCancelFileRequest", 3, param_slot_77 };
    static const QUParameter param_slot_78[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "oldSession", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "agentSession", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "ip", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "port", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_78 = {"doNotifyAgentTransfer", 5, param_slot_78 };
    static const QUParameter param_slot_79[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "oldSession", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "agentSession", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "ip", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "port", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_79 = {"doNotifyAgentTransfer", 6, param_slot_79 };
    static const QUParameter param_slot_80[] = {
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
    static const QUMethod slot_80 = {"doNotifyIpEx", 19, param_slot_80 };
    static const QUMethod slot_81 = {"doAdvancedSearch", 0, 0 };
    static const QUParameter param_slot_82[] = {
	{ "page", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_82 = {"doAdvancedSearch", 1, param_slot_82 };
    static const QUParameter param_slot_83[] = {
	{ "page", &static_QUType_int, 0, QUParameter::In },
	{ "onlineUser", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_83 = {"doAdvancedSearch", 2, param_slot_83 };
    static const QUParameter param_slot_84[] = {
	{ "page", &static_QUType_int, 0, QUParameter::In },
	{ "onlineUser", &static_QUType_bool, 0, QUParameter::In },
	{ "hasCam", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_84 = {"doAdvancedSearch", 3, param_slot_84 };
    static const QUParameter param_slot_85[] = {
	{ "page", &static_QUType_int, 0, QUParameter::In },
	{ "onlineUser", &static_QUType_bool, 0, QUParameter::In },
	{ "hasCam", &static_QUType_bool, 0, QUParameter::In },
	{ "province", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_85 = {"doAdvancedSearch", 4, param_slot_85 };
    static const QUParameter param_slot_86[] = {
	{ "page", &static_QUType_int, 0, QUParameter::In },
	{ "onlineUser", &static_QUType_bool, 0, QUParameter::In },
	{ "hasCam", &static_QUType_bool, 0, QUParameter::In },
	{ "province", &static_QUType_int, 0, QUParameter::In },
	{ "city", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_86 = {"doAdvancedSearch", 5, param_slot_86 };
    static const QUParameter param_slot_87[] = {
	{ "page", &static_QUType_int, 0, QUParameter::In },
	{ "onlineUser", &static_QUType_bool, 0, QUParameter::In },
	{ "hasCam", &static_QUType_bool, 0, QUParameter::In },
	{ "province", &static_QUType_int, 0, QUParameter::In },
	{ "city", &static_QUType_int, 0, QUParameter::In },
	{ "age", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_87 = {"doAdvancedSearch", 6, param_slot_87 };
    static const QUParameter param_slot_88[] = {
	{ "page", &static_QUType_int, 0, QUParameter::In },
	{ "onlineUser", &static_QUType_bool, 0, QUParameter::In },
	{ "hasCam", &static_QUType_bool, 0, QUParameter::In },
	{ "province", &static_QUType_int, 0, QUParameter::In },
	{ "city", &static_QUType_int, 0, QUParameter::In },
	{ "age", &static_QUType_int, 0, QUParameter::In },
	{ "gender", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_88 = {"doAdvancedSearch", 7, param_slot_88 };
    static const QUParameter param_slot_89[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_89 = {"doAddBuddyEx", 1, param_slot_89 };
    static const QUParameter param_slot_90[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_90 = {"doRequestAuthInfo", 1, param_slot_90 };
    static const QUParameter param_slot_91[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "cmd", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_91 = {"doRequestAuthInfo", 2, param_slot_91 };
    static const QUParameter param_slot_92[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "cmd", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "veri", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_92 = {"doRequestAuthInfo", 3, param_slot_92 };
    static const QUParameter param_slot_93[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "cmd", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "veri", &static_QUType_QString, 0, QUParameter::In },
	{ "session", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_93 = {"doRequestAuthInfo", 4, param_slot_93 };
    static const QUParameter param_slot_94[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "cmd", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "veri", &static_QUType_QString, 0, QUParameter::In },
	{ "session", &static_QUType_QString, 0, QUParameter::In },
	{ "isQun", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_94 = {"doRequestAuthInfo", 5, param_slot_94 };
    static const QUParameter param_slot_95[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_95 = {"doRequestAuthQuestion", 1, param_slot_95 };
    static const QUParameter param_slot_96[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isQuestion", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_96 = {"doRequestAuthQuestion", 2, param_slot_96 };
    static const QUParameter param_slot_97[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isQuestion", &static_QUType_bool, 0, QUParameter::In },
	{ "answer", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_97 = {"doRequestAuthQuestion", 3, param_slot_97 };
    static const QUMethod slot_98 = {"doSetMyAuthQuestion", 0, 0 };
    static const QUParameter param_slot_99[] = {
	{ "quest", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_99 = {"doSetMyAuthQuestion", 1, param_slot_99 };
    static const QUParameter param_slot_100[] = {
	{ "quest", &static_QUType_QString, 0, QUParameter::In },
	{ "answer", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_100 = {"doSetMyAuthQuestion", 2, param_slot_100 };
    static const QUMethod slot_101 = {"doRequestMyAuthQuestionSetting", 0, 0 };
    static const QUParameter param_slot_102[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authStatus", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_102 = {"doAddBuddyAuthEx", 2, param_slot_102 };
    static const QUParameter param_slot_103[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authStatus", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "destGroup", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_103 = {"doAddBuddyAuthEx", 3, param_slot_103 };
    static const QUParameter param_slot_104[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authStatus", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "destGroup", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_104 = {"doAddBuddyAuthEx", 4, param_slot_104 };
    static const QUParameter param_slot_105[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authStatus", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "destGroup", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_105 = {"doAddBuddyAuthEx", 5, param_slot_105 };
    static const QUParameter param_slot_106[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authStatus", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "destGroup", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "qcode", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_106 = {"doAddBuddyAuthEx", 6, param_slot_106 };
    static const QUParameter param_slot_107[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authStatus", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "destGroup", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "qcode", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "qlen", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_107 = {"doAddBuddyAuthEx", 7, param_slot_107 };
    static const QUParameter param_slot_108[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authStatus", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "destGroup", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "qcode", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "qlen", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_108 = {"doAddBuddyAuthEx", 8, param_slot_108 };
    static const QUParameter param_slot_109[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authStatus", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "destGroup", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "qcode", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "qlen", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In },
	{ "allowReverse", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_109 = {"doAddBuddyAuthEx", 9, param_slot_109 };
    static const QUParameter param_slot_110[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "len", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_110 = {"doVerifyAddingMessage", 3, param_slot_110 };
    static const QUParameter param_slot_111[] = {
	{ "ip", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_111 = {"doGetWeatherForecast", 1, param_slot_111 };
    static const QUMethod slot_112 = {"doGetContacts", 0, 0 };
    static const QUParameter param_slot_113[] = {
	{ "pos", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_113 = {"doGetContacts", 1, param_slot_113 };
    static const QUMethod slot_114 = {"slotConnectReady", 0, 0 };
    static const QUMethod slot_115 = {"newPacketSlot", 0, 0 };
    static const QUParameter param_slot_116[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_116 = {"networkExceptionSlot", 1, param_slot_116 };
    static const QUParameter param_slot_117[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_117 = {"packetExceptionSlot", 1, param_slot_117 };
    static const QUMethod slot_118 = {"timerSlot", 0, 0 };
    static const QUMethod slot_119 = {"slotClientNotReady", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "doRequestLoginToken()", &slot_0, QMetaData::Public },
	{ "doRequestLoginTokenEx()", &slot_1, QMetaData::Public },
	{ "doRequestLoginTokenEx(const QString&)", &slot_2, QMetaData::Public },
	{ "doLogin()", &slot_3, QMetaData::Public },
	{ "doLogout()", &slot_4, QMetaData::Public },
	{ "doGetUserInfo(const unsigned int)", &slot_5, QMetaData::Public },
	{ "doModifyDetails(QStringList)", &slot_6, QMetaData::Public },
	{ "doModifyDetails(QStringList,QString)", &slot_7, QMetaData::Public },
	{ "doModifyDetails(QStringList,QString,QString)", &slot_8, QMetaData::Public },
	{ "doChangeStatus(EvaUser::UserStatus)", &slot_9, QMetaData::Public },
	{ "doRequestFileAgentKey()", &slot_10, QMetaData::Public },
	{ "doGetOnlineFriends()", &slot_11, QMetaData::Public },
	{ "doGetAllFriends()", &slot_12, QMetaData::Public },
	{ "doGetAllLevels()", &slot_13, QMetaData::Public },
	{ "requestFriendLevel(const unsigned int)", &slot_14, QMetaData::Public },
	{ "doSendMessage(const unsigned int,const bool,QString&)", &slot_15, QMetaData::Public },
	{ "doSendMessage(const unsigned int,const bool,QString&,const char)", &slot_16, QMetaData::Public },
	{ "doSendMessage(const unsigned int,const bool,QString&,const char,const bool)", &slot_17, QMetaData::Public },
	{ "doSendMessage(const unsigned int,const bool,QString&,const char,const bool,const bool)", &slot_18, QMetaData::Public },
	{ "doSendMessage(const unsigned int,const bool,QString&,const char,const bool,const bool,const bool)", &slot_19, QMetaData::Public },
	{ "doSendMessage(const unsigned int,const bool,QString&,const char,const bool,const bool,const bool,const char)", &slot_20, QMetaData::Public },
	{ "doSendMessage(const unsigned int,const bool,QString&,const char,const bool,const bool,const bool,const char,const char)", &slot_21, QMetaData::Public },
	{ "doSendMessage(const unsigned int,const bool,QString&,const char,const bool,const bool,const bool,const char,const char,const char)", &slot_22, QMetaData::Public },
	{ "doGetGroups()", &slot_23, QMetaData::Public },
	{ "doUploadGroups()", &slot_24, QMetaData::Public },
	{ "doDeleteBuddy(const unsigned int)", &slot_25, QMetaData::Public },
	{ "doAddBuddy(const unsigned int)", &slot_26, QMetaData::Public },
	{ "doAddAuthBuddy(const unsigned int,const QString&)", &slot_27, QMetaData::Public },
	{ "doApproveBuddy(const unsigned int)", &slot_28, QMetaData::Public },
	{ "doRejectBuddy(const unsigned int,const QString&)", &slot_29, QMetaData::Public },
	{ "doSearchUsers()", &slot_30, QMetaData::Public },
	{ "doSearchUsers(const bool)", &slot_31, QMetaData::Public },
	{ "doSearchUsers(const bool,const QString)", &slot_32, QMetaData::Public },
	{ "doSearchUsers(const bool,const QString,const QString)", &slot_33, QMetaData::Public },
	{ "doSearchUsers(const bool,const QString,const QString,const QString)", &slot_34, QMetaData::Public },
	{ "doSearchUsers(const bool,const QString,const QString,const QString,const QString)", &slot_35, QMetaData::Public },
	{ "doSearchUsers(const bool,const QString,const QString,const QString,const QString,const bool)", &slot_36, QMetaData::Public },
	{ "doDeleteMeFrom(const unsigned int)", &slot_37, QMetaData::Public },
	{ "doRequestQunInfo(const unsigned int)", &slot_38, QMetaData::Public },
	{ "doRequestQunMemberInfo(const unsigned int,const std::list<unsigned int>&)", &slot_39, QMetaData::Public },
	{ "doRequestQunOnlineMembers(const unsigned int)", &slot_40, QMetaData::Public },
	{ "doSendQunMessage(const unsigned int,QString&)", &slot_41, QMetaData::Public },
	{ "doSendQunMessage(const unsigned int,QString&,const char)", &slot_42, QMetaData::Public },
	{ "doSendQunMessage(const unsigned int,QString&,const char,const bool)", &slot_43, QMetaData::Public },
	{ "doSendQunMessage(const unsigned int,QString&,const char,const bool,const bool)", &slot_44, QMetaData::Public },
	{ "doSendQunMessage(const unsigned int,QString&,const char,const bool,const bool,const bool)", &slot_45, QMetaData::Public },
	{ "doSendQunMessage(const unsigned int,QString&,const char,const bool,const bool,const bool,const char)", &slot_46, QMetaData::Public },
	{ "doSendQunMessage(const unsigned int,QString&,const char,const bool,const bool,const bool,const char,const char)", &slot_47, QMetaData::Public },
	{ "doSendQunMessage(const unsigned int,QString&,const char,const bool,const bool,const bool,const char,const char,const char)", &slot_48, QMetaData::Public },
	{ "doSearchQun(const unsigned int)", &slot_49, QMetaData::Public },
	{ "doJoinQun(const unsigned int)", &slot_50, QMetaData::Public },
	{ "doJoinQunAuth(const unsigned int,const unsigned char*,const unsigned short,const QString&)", &slot_51, QMetaData::Public },
	{ "doApproveQun(const unsigned int,const unsigned int,const unsigned char*,const unsigned short)", &slot_52, QMetaData::Public },
	{ "doRejectQun(const unsigned int,const unsigned int,const QString&,const unsigned char*,const unsigned short)", &slot_53, QMetaData::Public },
	{ "doModifyQunInfo(const unsigned int,unsigned char,unsigned short,QString,QString,QString)", &slot_54, QMetaData::Public },
	{ "doModifyQunCard(const unsigned int,const unsigned int,QString,unsigned char,QString,QString,QString)", &slot_55, QMetaData::Public },
	{ "doQunSetAdmin(const unsigned int,const unsigned int,const bool)", &slot_56, QMetaData::Public },
	{ "doQunTransfer(const unsigned int,const unsigned int)", &slot_57, QMetaData::Public },
	{ "doModifyQunMembers(const unsigned int,const std::list<unsigned int>,const bool)", &slot_58, QMetaData::Public },
	{ "doRequestQunCard(const unsigned int,const unsigned int)", &slot_59, QMetaData::Public },
	{ "doQunExit(const unsigned int)", &slot_60, QMetaData::Public },
	{ "doQunCreate(const QString&,const unsigned short,const unsigned char,const QString&,const QString&,const std::list<unsigned int>&)", &slot_61, QMetaData::Public },
	{ "doRequestQunRealNames(const unsigned int)", &slot_62, QMetaData::Public },
	{ "doRequestExtraInfo()", &slot_63, QMetaData::Public },
	{ "doModifySignature(const QString)", &slot_64, QMetaData::Public },
	{ "doDeleteSignature()", &slot_65, QMetaData::Public },
	{ "doRequestSignature()", &slot_66, QMetaData::Public },
	{ "doRequestSignature(const unsigned int)", &slot_67, QMetaData::Public },
	{ "doRequestSignature(const unsigned int,const bool)", &slot_68, QMetaData::Public },
	{ "doUploadMemo(const unsigned int,const MemoItem&)", &slot_69, QMetaData::Public },
	{ "doRemoveMemo(const unsigned int)", &slot_70, QMetaData::Public },
	{ "doDownloadMemo(const unsigned int)", &slot_71, QMetaData::Public },
	{ "doSendFileUdpRequest(const unsigned int,const QString,const unsigned int,const short)", &slot_72, QMetaData::Public },
	{ "doSendFileUdpRequest(const unsigned int,const QString,const unsigned int,const short,const unsigned char)", &slot_73, QMetaData::Public },
	{ "doAcceptFileRequest(const unsigned int,const short,const unsigned int)", &slot_74, QMetaData::Public },
	{ "doAcceptFileRequest(const unsigned int,const short,const unsigned int,const unsigned char)", &slot_75, QMetaData::Public },
	{ "doCancelFileRequest(const unsigned int,const short)", &slot_76, QMetaData::Public },
	{ "doCancelFileRequest(const unsigned int,const short,const unsigned char)", &slot_77, QMetaData::Public },
	{ "doNotifyAgentTransfer(const unsigned int,const unsigned int,const unsigned int,const unsigned int,const unsigned short)", &slot_78, QMetaData::Public },
	{ "doNotifyAgentTransfer(const unsigned int,const unsigned int,const unsigned int,const unsigned int,const unsigned short,const unsigned char)", &slot_79, QMetaData::Public },
	{ "doNotifyIpEx(const unsigned int,const bool,const unsigned int,const unsigned char,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int)", &slot_80, QMetaData::Public },
	{ "doAdvancedSearch()", &slot_81, QMetaData::Public },
	{ "doAdvancedSearch(const int)", &slot_82, QMetaData::Public },
	{ "doAdvancedSearch(const int,const bool)", &slot_83, QMetaData::Public },
	{ "doAdvancedSearch(const int,const bool,const bool)", &slot_84, QMetaData::Public },
	{ "doAdvancedSearch(const int,const bool,const bool,const int)", &slot_85, QMetaData::Public },
	{ "doAdvancedSearch(const int,const bool,const bool,const int,const int)", &slot_86, QMetaData::Public },
	{ "doAdvancedSearch(const int,const bool,const bool,const int,const int,const int)", &slot_87, QMetaData::Public },
	{ "doAdvancedSearch(const int,const bool,const bool,const int,const int,const int,const int)", &slot_88, QMetaData::Public },
	{ "doAddBuddyEx(const unsigned int)", &slot_89, QMetaData::Public },
	{ "doRequestAuthInfo(const unsigned int)", &slot_90, QMetaData::Public },
	{ "doRequestAuthInfo(const unsigned int,const unsigned char)", &slot_91, QMetaData::Public },
	{ "doRequestAuthInfo(const unsigned int,const unsigned char,const QString&)", &slot_92, QMetaData::Public },
	{ "doRequestAuthInfo(const unsigned int,const unsigned char,const QString&,const QString&)", &slot_93, QMetaData::Public },
	{ "doRequestAuthInfo(const unsigned int,const unsigned char,const QString&,const QString&,const bool)", &slot_94, QMetaData::Public },
	{ "doRequestAuthQuestion(const unsigned int)", &slot_95, QMetaData::Public },
	{ "doRequestAuthQuestion(const unsigned int,const bool)", &slot_96, QMetaData::Public },
	{ "doRequestAuthQuestion(const unsigned int,const bool,const QString&)", &slot_97, QMetaData::Public },
	{ "doSetMyAuthQuestion()", &slot_98, QMetaData::Public },
	{ "doSetMyAuthQuestion(const QString&)", &slot_99, QMetaData::Public },
	{ "doSetMyAuthQuestion(const QString&,const QString&)", &slot_100, QMetaData::Public },
	{ "doRequestMyAuthQuestionSetting()", &slot_101, QMetaData::Public },
	{ "doAddBuddyAuthEx(const unsigned int,const unsigned char)", &slot_102, QMetaData::Public },
	{ "doAddBuddyAuthEx(const unsigned int,const unsigned char,const unsigned int)", &slot_103, QMetaData::Public },
	{ "doAddBuddyAuthEx(const unsigned int,const unsigned char,const unsigned int,const unsigned char*)", &slot_104, QMetaData::Public },
	{ "doAddBuddyAuthEx(const unsigned int,const unsigned char,const unsigned int,const unsigned char*,const unsigned short)", &slot_105, QMetaData::Public },
	{ "doAddBuddyAuthEx(const unsigned int,const unsigned char,const unsigned int,const unsigned char*,const unsigned short,const unsigned char*)", &slot_106, QMetaData::Public },
	{ "doAddBuddyAuthEx(const unsigned int,const unsigned char,const unsigned int,const unsigned char*,const unsigned short,const unsigned char*,const unsigned short)", &slot_107, QMetaData::Public },
	{ "doAddBuddyAuthEx(const unsigned int,const unsigned char,const unsigned int,const unsigned char*,const unsigned short,const unsigned char*,const unsigned short,const QString&)", &slot_108, QMetaData::Public },
	{ "doAddBuddyAuthEx(const unsigned int,const unsigned char,const unsigned int,const unsigned char*,const unsigned short,const unsigned char*,const unsigned short,const QString&,const bool)", &slot_109, QMetaData::Public },
	{ "doVerifyAddingMessage(const unsigned int,const unsigned char*,const unsigned int)", &slot_110, QMetaData::Public },
	{ "doGetWeatherForecast(const unsigned int)", &slot_111, QMetaData::Public },
	{ "doGetContacts()", &slot_112, QMetaData::Public },
	{ "doGetContacts(int)", &slot_113, QMetaData::Public },
	{ "slotConnectReady()", &slot_114, QMetaData::Private },
	{ "newPacketSlot()", &slot_115, QMetaData::Private },
	{ "networkExceptionSlot(int)", &slot_116, QMetaData::Private },
	{ "packetExceptionSlot(int)", &slot_117, QMetaData::Private },
	{ "timerSlot()", &slot_118, QMetaData::Private },
	{ "slotClientNotReady()", &slot_119, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_0 = {"networkException", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_1 = {"packetException", 1, param_signal_1 };
    static const QUMethod signal_2 = {"serverBusy", 0, 0 };
    static const QUMethod signal_3 = {"logoutOK", 0, 0 };
    static const QUMethod signal_4 = {"onlineReady", 0, 0 };
    static const QUMethod signal_5 = {"offlineReady", 0, 0 };
    static const QUMethod signal_6 = {"invisibleReady", 0, 0 };
    static const QUMethod signal_7 = {"leaveReady", 0, 0 };
    static const QUParameter param_signal_8[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_8 = {"kickedOut", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_9 = {"friendStatusChanged", 1, param_signal_9 };
    static const QUMethod signal_10 = {"friendListReady", 0, 0 };
    static const QUParameter param_signal_11[] = {
	{ "info", &static_QUType_varptr, "\x04", QUParameter::In }
    };
    static const QUMethod signal_11 = {"userInfoReady", 1, param_signal_11 };
    static const QUMethod signal_12 = {"extraInfoReady", 0, 0 };
    static const QUParameter param_signal_13[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_13 = {"modifyInfo", 1, param_signal_13 };
    static const QUParameter param_signal_14[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_14 = {"sentMessageResult", 2, param_signal_14 };
    static const QUParameter param_signal_15[] = {
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
    static const QUMethod signal_15 = {"txtMessage", 11, param_signal_15 };
    static const QUParameter param_signal_16[] = {
	{ "type", &static_QUType_int, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_16 = {"sysMessage", 2, param_signal_16 };
    static const QUParameter param_signal_17[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_17 = {"friendGroupsUploadReady", 1, param_signal_17 };
    static const QUParameter param_signal_18[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_18 = {"deleteBuddyReady", 2, param_signal_18 };
    static const QUParameter param_signal_19[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_19 = {"addingBuddy", 1, param_signal_19 };
    static const QUMethod signal_20 = {"addBuddyReady", 0, 0 };
    static const QUMethod signal_21 = {"addBuddyRejected", 0, 0 };
    static const QUMethod signal_22 = {"addBuddyNeedAuth", 0, 0 };
    static const QUParameter param_signal_23[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod signal_23 = {"addAnonymous", 2, param_signal_23 };
    static const QUParameter param_signal_24[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_24 = {"addBuddySentToServer", 1, param_signal_24 };
    static const QUParameter param_signal_25[] = {
	{ "finished", &static_QUType_bool, 0, QUParameter::In },
	{ "list", &static_QUType_ptr, "std::list<OnlineUser>", QUParameter::In }
    };
    static const QUMethod signal_25 = {"searchUsersReady", 2, param_signal_25 };
    static const QUParameter param_signal_26[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_26 = {"deleteMeReady", 1, param_signal_26 };
    static const QUParameter param_signal_27[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_varptr, "\x1c", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_27 = {"friendSignatureChanged", 3, param_signal_27 };
    static const QUParameter param_signal_28[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_28 = {"qunSentMessageResult", 3, param_signal_28 };
    static const QUParameter param_signal_29[] = {
	{ "qunID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "senderQQ", &static_QUType_ptr, "unsigned int", QUParameter::In },
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
    static const QUMethod signal_29 = {"qunTxtMessage", 11, param_signal_29 };
    static const QUParameter param_signal_30[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_30 = {"qunInfomationReady", 3, param_signal_30 };
    static const QUParameter param_signal_31[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_31 = {"qunMemberInfoReady", 1, param_signal_31 };
    static const QUParameter param_signal_32[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_32 = {"qunOnlineListReady", 1, param_signal_32 };
    static const QUParameter param_signal_33[] = {
	{ 0, &static_QUType_ptr, "std::list<QunInfo>", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_33 = {"qunSearchReady", 2, param_signal_33 };
    static const QUParameter param_signal_34[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "authType", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_34 = {"joinQunReply", 3, param_signal_34 };
    static const QUParameter param_signal_35[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_35 = {"joinQunAuthReply", 2, param_signal_35 };
    static const QUParameter param_signal_36[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_36 = {"qunSystemMessageRequest", 2, param_signal_36 };
    static const QUParameter param_signal_37[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "short", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_37 = {"qunJoinEvent", 4, param_signal_37 };
    static const QUMethod signal_38 = {"qunRequestUpdateDisplay", 0, 0 };
    static const QUParameter param_signal_39[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_39 = {"qunModifyInfoReply", 3, param_signal_39 };
    static const QUParameter param_signal_40[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_40 = {"qunModifyQunCardReply", 4, param_signal_40 };
    static const QUParameter param_signal_41[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_41 = {"qunSetAdminReply", 5, param_signal_41 };
    static const QUParameter param_signal_42[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_42 = {"qunTransferReply", 4, param_signal_42 };
    static const QUParameter param_signal_43[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_43 = {"qunModifyQunMembersReply", 3, param_signal_43 };
    static const QUParameter param_signal_44[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_44 = {"qunRequestQunCardReply", 9, param_signal_44 };
    static const QUParameter param_signal_45[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_45 = {"qunExitReply", 3, param_signal_45 };
    static const QUParameter param_signal_46[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_46 = {"qunCreateDone", 1, param_signal_46 };
    static const QUParameter param_signal_47[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_47 = {"qunCreateFailed", 1, param_signal_47 };
    static const QUParameter param_signal_48[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_48 = {"qunActiveQunFailed", 1, param_signal_48 };
    static const QUParameter param_signal_49[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_49 = {"signatureModifyReply", 1, param_signal_49 };
    static const QUParameter param_signal_50[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_50 = {"signatureDeleteReply", 1, param_signal_50 };
    static const QUParameter param_signal_51[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_51 = {"memoUploadReply", 1, param_signal_51 };
    static const QUParameter param_signal_52[] = {
	{ 0, &static_QUType_ptr, "MemoItem", QUParameter::In }
    };
    static const QUMethod signal_52 = {"memoDownloadReply", 1, param_signal_52 };
    static const QUMethod signal_53 = {"memoNoMemoFound", 0, 0 };
    static const QUParameter param_signal_54[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "fileName", &static_QUType_QString, 0, QUParameter::In },
	{ "size", &static_QUType_int, 0, QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_54 = {"receivedFileRequest", 5, param_signal_54 };
    static const QUParameter param_signal_55[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "ip", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isAccepted", &static_QUType_bool, 0, QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_55 = {"receivedFileAccepted", 5, param_signal_55 };
    static const QUParameter param_signal_56[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "oldSession", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "newSession", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "ip", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "port", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "key", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_56 = {"receivedFileAgentInfo", 6, param_signal_56 };
    static const QUParameter param_signal_57[] = {
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
    static const QUMethod signal_57 = {"receivedFileNotifyIpEx", 19, param_signal_57 };
    static const QUParameter param_signal_58[] = {
	{ "page", &static_QUType_int, 0, QUParameter::In },
	{ "finished", &static_QUType_bool, 0, QUParameter::In },
	{ "list", &static_QUType_ptr, "std::list<AdvancedUser>", QUParameter::In }
    };
    static const QUMethod signal_58 = {"advancedSearchReady", 3, param_signal_58 };
    static const QUParameter param_signal_59[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_59 = {"addBuddyExReply", 3, param_signal_59 };
    static const QUParameter param_signal_60[] = {
	{ "cmd", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "replyCode", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "codeLen", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_60 = {"requestAuthInfoReply", 4, param_signal_60 };
    static const QUParameter param_signal_61[] = {
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "question", &static_QUType_QString, 0, QUParameter::In },
	{ "anwser", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_61 = {"receivedMyAuthSettings", 3, param_signal_61 };
    static const QUParameter param_signal_62[] = {
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "replyCode", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_62 = {"updateAuthSettingResult", 2, param_signal_62 };
    static const QUParameter param_signal_63[] = {
	{ "auth", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "replyCode", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "codeLen", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod signal_63 = {"requestQuestionReply", 4, param_signal_63 };
    static const QUParameter param_signal_64[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "ok", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_64 = {"addFriendAuthExReply", 3, param_signal_64 };
    static const QUParameter param_signal_65[] = {
	{ "type", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "myID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "fromID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In },
	{ "allowReverse", &static_QUType_bool, 0, QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "codeLen", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_65 = {"receivedSysMessage", 7, param_signal_65 };
    static const QUParameter param_signal_66[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "reply", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "flag1", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "flag2", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_66 = {"receivedVerifyAddingMessageReply", 4, param_signal_66 };
    static const QUParameter param_signal_67[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "imType", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "ext", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "qunType", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "commander", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In },
	{ "code", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "codeLen", &static_QUType_ptr, "unsigned short", QUParameter::In },
	{ "token", &static_QUType_ptr, "unsigned char", QUParameter::In },
	{ "tokenLen", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod signal_67 = {"qunSysMessage", 11, param_signal_67 };
    static const QUParameter param_signal_68[] = {
	{ "title", &static_QUType_QString, 0, QUParameter::In },
	{ "brief", &static_QUType_QString, 0, QUParameter::In },
	{ "url", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod signal_68 = {"receivedQQNews", 3, param_signal_68 };
    static const QMetaData signal_tbl[] = {
	{ "networkException(int)", &signal_0, QMetaData::Public },
	{ "packetException(int)", &signal_1, QMetaData::Public },
	{ "serverBusy()", &signal_2, QMetaData::Public },
	{ "logoutOK()", &signal_3, QMetaData::Public },
	{ "onlineReady()", &signal_4, QMetaData::Public },
	{ "offlineReady()", &signal_5, QMetaData::Public },
	{ "invisibleReady()", &signal_6, QMetaData::Public },
	{ "leaveReady()", &signal_7, QMetaData::Public },
	{ "kickedOut(const QString)", &signal_8, QMetaData::Public },
	{ "friendStatusChanged(unsigned int)", &signal_9, QMetaData::Public },
	{ "friendListReady()", &signal_10, QMetaData::Public },
	{ "userInfoReady(QStringList)", &signal_11, QMetaData::Public },
	{ "extraInfoReady()", &signal_12, QMetaData::Public },
	{ "modifyInfo(bool)", &signal_13, QMetaData::Public },
	{ "sentMessageResult(unsigned int,bool)", &signal_14, QMetaData::Public },
	{ "txtMessage(unsigned int,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &signal_15, QMetaData::Public },
	{ "sysMessage(int,QString)", &signal_16, QMetaData::Public },
	{ "friendGroupsUploadReady(bool)", &signal_17, QMetaData::Public },
	{ "deleteBuddyReady(unsigned int,bool)", &signal_18, QMetaData::Public },
	{ "addingBuddy(int)", &signal_19, QMetaData::Public },
	{ "addBuddyReady()", &signal_20, QMetaData::Public },
	{ "addBuddyRejected()", &signal_21, QMetaData::Public },
	{ "addBuddyNeedAuth()", &signal_22, QMetaData::Public },
	{ "addAnonymous(const unsigned int,const unsigned short)", &signal_23, QMetaData::Public },
	{ "addBuddySentToServer(bool)", &signal_24, QMetaData::Public },
	{ "searchUsersReady(const bool,const std::list<OnlineUser>)", &signal_25, QMetaData::Public },
	{ "deleteMeReady(bool)", &signal_26, QMetaData::Public },
	{ "friendSignatureChanged(const unsigned int,const QDateTime,const QString)", &signal_27, QMetaData::Public },
	{ "qunSentMessageResult(unsigned int,bool,QString)", &signal_28, QMetaData::Public },
	{ "qunTxtMessage(unsigned int,unsigned int,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &signal_29, QMetaData::Public },
	{ "qunInfomationReady(const unsigned int,const bool,QString)", &signal_30, QMetaData::Public },
	{ "qunMemberInfoReady(const unsigned int)", &signal_31, QMetaData::Public },
	{ "qunOnlineListReady(const unsigned int)", &signal_32, QMetaData::Public },
	{ "qunSearchReady(const std::list<QunInfo>,QString)", &signal_33, QMetaData::Public },
	{ "joinQunReply(const unsigned int,const unsigned char,const QString&)", &signal_34, QMetaData::Public },
	{ "joinQunAuthReply(const unsigned int,const unsigned char)", &signal_35, QMetaData::Public },
	{ "qunSystemMessageRequest(const unsigned int,QString)", &signal_36, QMetaData::Public },
	{ "qunJoinEvent(const unsigned int,const short,const unsigned int,const unsigned int)", &signal_37, QMetaData::Public },
	{ "qunRequestUpdateDisplay()", &signal_38, QMetaData::Public },
	{ "qunModifyInfoReply(const unsigned int,const bool,QString)", &signal_39, QMetaData::Public },
	{ "qunModifyQunCardReply(const unsigned int,const bool,const unsigned int,QString)", &signal_40, QMetaData::Public },
	{ "qunSetAdminReply(const unsigned int,const bool,const unsigned int,const bool,QString)", &signal_41, QMetaData::Public },
	{ "qunTransferReply(const unsigned int,const bool,const unsigned int,QString)", &signal_42, QMetaData::Public },
	{ "qunModifyQunMembersReply(const unsigned int,const bool,QString)", &signal_43, QMetaData::Public },
	{ "qunRequestQunCardReply(const unsigned int,const bool,const unsigned int,QString,const unsigned char,QString,QString,QString,QString)", &signal_44, QMetaData::Public },
	{ "qunExitReply(const unsigned int,const bool,QString)", &signal_45, QMetaData::Public },
	{ "qunCreateDone(const unsigned int)", &signal_46, QMetaData::Public },
	{ "qunCreateFailed(QString)", &signal_47, QMetaData::Public },
	{ "qunActiveQunFailed(QString)", &signal_48, QMetaData::Public },
	{ "signatureModifyReply(const bool)", &signal_49, QMetaData::Public },
	{ "signatureDeleteReply(const bool)", &signal_50, QMetaData::Public },
	{ "memoUploadReply(const bool)", &signal_51, QMetaData::Public },
	{ "memoDownloadReply(const MemoItem&)", &signal_52, QMetaData::Public },
	{ "memoNoMemoFound()", &signal_53, QMetaData::Public },
	{ "receivedFileRequest(const unsigned int,const unsigned int,const QString,const int,const unsigned char)", &signal_54, QMetaData::Public },
	{ "receivedFileAccepted(const unsigned int,const unsigned int,const unsigned int,const bool,const unsigned char)", &signal_55, QMetaData::Public },
	{ "receivedFileAgentInfo(const unsigned int,const unsigned int,const unsigned int,const unsigned int,const unsigned short,const unsigned char*)", &signal_56, QMetaData::Public },
	{ "receivedFileNotifyIpEx(const unsigned int,const bool,const unsigned int,const unsigned char,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int,const unsigned short,const unsigned int)", &signal_57, QMetaData::Public },
	{ "advancedSearchReady(const int,const bool,const std::list<AdvancedUser>)", &signal_58, QMetaData::Public },
	{ "addBuddyExReply(const unsigned int,const unsigned char,const unsigned char)", &signal_59, QMetaData::Public },
	{ "requestAuthInfoReply(const unsigned char,const unsigned char,const unsigned char*,const int)", &signal_60, QMetaData::Public },
	{ "receivedMyAuthSettings(const unsigned char,const QString&,const QString&)", &signal_61, QMetaData::Public },
	{ "updateAuthSettingResult(const unsigned char,const unsigned char)", &signal_62, QMetaData::Public },
	{ "requestQuestionReply(const unsigned char,const unsigned char,const unsigned char*,const int)", &signal_63, QMetaData::Public },
	{ "addFriendAuthExReply(const unsigned int,const unsigned char,const bool)", &signal_64, QMetaData::Public },
	{ "receivedSysMessage(const unsigned char,const unsigned int,const unsigned int,const QString&,const bool,const unsigned char*,const unsigned int)", &signal_65, QMetaData::Public },
	{ "receivedVerifyAddingMessageReply(const unsigned int,const unsigned char,const unsigned char,const unsigned char)", &signal_66, QMetaData::Public },
	{ "qunSysMessage(const unsigned int,const unsigned short,const unsigned int,const unsigned char,const unsigned int,const unsigned int,const QString&,const unsigned char*,const unsigned short,const unsigned char*,const unsigned short)", &signal_67, QMetaData::Public },
	{ "receivedQQNews(const QString&,const QString&,const QString&)", &signal_68, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaPacketManager", parentObject,
	slot_tbl, 120,
	signal_tbl, 69,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaPacketManager.setMetaObject( metaObj );
    return metaObj;
}

void* EvaPacketManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaPacketManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

// SIGNAL networkException
void EvaPacketManager::networkException( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 0, t0 );
}

// SIGNAL packetException
void EvaPacketManager::packetException( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 1, t0 );
}

// SIGNAL serverBusy
void EvaPacketManager::serverBusy()
{
    activate_signal( staticMetaObject()->signalOffset() + 2 );
}

// SIGNAL logoutOK
void EvaPacketManager::logoutOK()
{
    activate_signal( staticMetaObject()->signalOffset() + 3 );
}

// SIGNAL onlineReady
void EvaPacketManager::onlineReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL offlineReady
void EvaPacketManager::offlineReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 5 );
}

// SIGNAL invisibleReady
void EvaPacketManager::invisibleReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 6 );
}

// SIGNAL leaveReady
void EvaPacketManager::leaveReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 7 );
}

// SIGNAL kickedOut
void EvaPacketManager::kickedOut( const QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 8, t0 );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL friendStatusChanged
void EvaPacketManager::friendStatusChanged( unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 9 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL friendListReady
void EvaPacketManager::friendListReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 10 );
}

// SIGNAL userInfoReady
void EvaPacketManager::userInfoReady( QStringList t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 11 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_varptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL extraInfoReady
void EvaPacketManager::extraInfoReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 12 );
}

// SIGNAL modifyInfo
void EvaPacketManager::modifyInfo( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 13, t0 );
}

// SIGNAL sentMessageResult
void EvaPacketManager::sentMessageResult( unsigned int t0, bool t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 14 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL txtMessage
void EvaPacketManager::txtMessage( unsigned int t0, bool t1, QString t2, QDateTime t3, const char t4, const bool t5, const bool t6, const bool t7, const char t8, const char t9, const char t10 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 15 );
    if ( !clist )
	return;
    QUObject o[12];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    static_QUType_varptr.set(o+4,&t3);
    static_QUType_ptr.set(o+5,&t4);
    static_QUType_bool.set(o+6,t5);
    static_QUType_bool.set(o+7,t6);
    static_QUType_bool.set(o+8,t7);
    static_QUType_ptr.set(o+9,&t8);
    static_QUType_ptr.set(o+10,&t9);
    static_QUType_ptr.set(o+11,&t10);
    activate_signal( clist, o );
}

// SIGNAL sysMessage
void EvaPacketManager::sysMessage( int t0, QString t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 16 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_int.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL friendGroupsUploadReady
void EvaPacketManager::friendGroupsUploadReady( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 17, t0 );
}

// SIGNAL deleteBuddyReady
void EvaPacketManager::deleteBuddyReady( unsigned int t0, bool t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 18 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL addingBuddy
void EvaPacketManager::addingBuddy( int t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 19, t0 );
}

// SIGNAL addBuddyReady
void EvaPacketManager::addBuddyReady()
{
    activate_signal( staticMetaObject()->signalOffset() + 20 );
}

// SIGNAL addBuddyRejected
void EvaPacketManager::addBuddyRejected()
{
    activate_signal( staticMetaObject()->signalOffset() + 21 );
}

// SIGNAL addBuddyNeedAuth
void EvaPacketManager::addBuddyNeedAuth()
{
    activate_signal( staticMetaObject()->signalOffset() + 22 );
}

// SIGNAL addAnonymous
void EvaPacketManager::addAnonymous( const unsigned int t0, const unsigned short t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 23 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL addBuddySentToServer
void EvaPacketManager::addBuddySentToServer( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 24, t0 );
}

// SIGNAL searchUsersReady
void EvaPacketManager::searchUsersReady( const bool t0, const std::list<OnlineUser> t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 25 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_bool.set(o+1,t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL deleteMeReady
void EvaPacketManager::deleteMeReady( bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 26, t0 );
}

// SIGNAL friendSignatureChanged
void EvaPacketManager::friendSignatureChanged( const unsigned int t0, const QDateTime t1, const QString t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 27 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_varptr.set(o+2,&t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL qunSentMessageResult
void EvaPacketManager::qunSentMessageResult( unsigned int t0, bool t1, QString t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 28 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL qunTxtMessage
void EvaPacketManager::qunTxtMessage( unsigned int t0, unsigned int t1, QString t2, QDateTime t3, const char t4, const bool t5, const bool t6, const bool t7, const char t8, const char t9, const char t10 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 29 );
    if ( !clist )
	return;
    QUObject o[12];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_QString.set(o+3,t2);
    static_QUType_varptr.set(o+4,&t3);
    static_QUType_ptr.set(o+5,&t4);
    static_QUType_bool.set(o+6,t5);
    static_QUType_bool.set(o+7,t6);
    static_QUType_bool.set(o+8,t7);
    static_QUType_ptr.set(o+9,&t8);
    static_QUType_ptr.set(o+10,&t9);
    static_QUType_ptr.set(o+11,&t10);
    activate_signal( clist, o );
}

// SIGNAL qunInfomationReady
void EvaPacketManager::qunInfomationReady( const unsigned int t0, const bool t1, QString t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 30 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL qunMemberInfoReady
void EvaPacketManager::qunMemberInfoReady( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 31 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL qunOnlineListReady
void EvaPacketManager::qunOnlineListReady( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 32 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL qunSearchReady
void EvaPacketManager::qunSearchReady( const std::list<QunInfo> t0, QString t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 33 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL joinQunReply
void EvaPacketManager::joinQunReply( const unsigned int t0, const unsigned char t1, const QString& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 34 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL joinQunAuthReply
void EvaPacketManager::joinQunAuthReply( const unsigned int t0, const unsigned char t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 35 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL qunSystemMessageRequest
void EvaPacketManager::qunSystemMessageRequest( const unsigned int t0, QString t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 36 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    activate_signal( clist, o );
}

// SIGNAL qunJoinEvent
void EvaPacketManager::qunJoinEvent( const unsigned int t0, const short t1, const unsigned int t2, const unsigned int t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 37 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    activate_signal( clist, o );
}

// SIGNAL qunRequestUpdateDisplay
void EvaPacketManager::qunRequestUpdateDisplay()
{
    activate_signal( staticMetaObject()->signalOffset() + 38 );
}

// SIGNAL qunModifyInfoReply
void EvaPacketManager::qunModifyInfoReply( const unsigned int t0, const bool t1, QString t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 39 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL qunModifyQunCardReply
void EvaPacketManager::qunModifyQunCardReply( const unsigned int t0, const bool t1, const unsigned int t2, QString t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 40 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_QString.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL qunSetAdminReply
void EvaPacketManager::qunSetAdminReply( const unsigned int t0, const bool t1, const unsigned int t2, const bool t3, QString t4 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 41 );
    if ( !clist )
	return;
    QUObject o[6];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_bool.set(o+4,t3);
    static_QUType_QString.set(o+5,t4);
    activate_signal( clist, o );
}

// SIGNAL qunTransferReply
void EvaPacketManager::qunTransferReply( const unsigned int t0, const bool t1, const unsigned int t2, QString t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 42 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_QString.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL qunModifyQunMembersReply
void EvaPacketManager::qunModifyQunMembersReply( const unsigned int t0, const bool t1, QString t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 43 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL qunRequestQunCardReply
void EvaPacketManager::qunRequestQunCardReply( const unsigned int t0, const bool t1, const unsigned int t2, QString t3, const unsigned char t4, QString t5, QString t6, QString t7, QString t8 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 44 );
    if ( !clist )
	return;
    QUObject o[10];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_QString.set(o+4,t3);
    static_QUType_ptr.set(o+5,&t4);
    static_QUType_QString.set(o+6,t5);
    static_QUType_QString.set(o+7,t6);
    static_QUType_QString.set(o+8,t7);
    static_QUType_QString.set(o+9,t8);
    activate_signal( clist, o );
}

// SIGNAL qunExitReply
void EvaPacketManager::qunExitReply( const unsigned int t0, const bool t1, QString t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 45 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL qunCreateDone
void EvaPacketManager::qunCreateDone( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 46 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL qunCreateFailed
void EvaPacketManager::qunCreateFailed( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 47, t0 );
}

// SIGNAL qunActiveQunFailed
void EvaPacketManager::qunActiveQunFailed( QString t0 )
{
    activate_signal( staticMetaObject()->signalOffset() + 48, t0 );
}

// SIGNAL signatureModifyReply
void EvaPacketManager::signatureModifyReply( const bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 49, t0 );
}

// SIGNAL signatureDeleteReply
void EvaPacketManager::signatureDeleteReply( const bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 50, t0 );
}

// SIGNAL memoUploadReply
void EvaPacketManager::memoUploadReply( const bool t0 )
{
    activate_signal_bool( staticMetaObject()->signalOffset() + 51, t0 );
}

// SIGNAL memoDownloadReply
void EvaPacketManager::memoDownloadReply( const MemoItem& t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 52 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL memoNoMemoFound
void EvaPacketManager::memoNoMemoFound()
{
    activate_signal( staticMetaObject()->signalOffset() + 53 );
}

// SIGNAL receivedFileRequest
void EvaPacketManager::receivedFileRequest( const unsigned int t0, const unsigned int t1, const QString t2, const int t3, const unsigned char t4 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 54 );
    if ( !clist )
	return;
    QUObject o[6];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_QString.set(o+3,t2);
    static_QUType_int.set(o+4,t3);
    static_QUType_ptr.set(o+5,&t4);
    activate_signal( clist, o );
}

// SIGNAL receivedFileAccepted
void EvaPacketManager::receivedFileAccepted( const unsigned int t0, const unsigned int t1, const unsigned int t2, const bool t3, const unsigned char t4 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 55 );
    if ( !clist )
	return;
    QUObject o[6];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_bool.set(o+4,t3);
    static_QUType_ptr.set(o+5,&t4);
    activate_signal( clist, o );
}

// SIGNAL receivedFileAgentInfo
void EvaPacketManager::receivedFileAgentInfo( const unsigned int t0, const unsigned int t1, const unsigned int t2, const unsigned int t3, const unsigned short t4, const unsigned char* t5 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 56 );
    if ( !clist )
	return;
    QUObject o[7];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    static_QUType_ptr.set(o+5,&t4);
    static_QUType_ptr.set(o+6,t5);
    activate_signal( clist, o );
}

// SIGNAL receivedFileNotifyIpEx
void EvaPacketManager::receivedFileNotifyIpEx( const unsigned int t0, const bool t1, const unsigned int t2, const unsigned char t3, const unsigned int t4, const unsigned short t5, const unsigned int t6, const unsigned short t7, const unsigned int t8, const unsigned short t9, const unsigned int t10, const unsigned short t11, const unsigned int t12, const unsigned short t13, const unsigned int t14, const unsigned short t15, const unsigned int t16, const unsigned short t17, const unsigned int t18 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 57 );
    if ( !clist )
	return;
    QUObject o[20];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    static_QUType_ptr.set(o+5,&t4);
    static_QUType_ptr.set(o+6,&t5);
    static_QUType_ptr.set(o+7,&t6);
    static_QUType_ptr.set(o+8,&t7);
    static_QUType_ptr.set(o+9,&t8);
    static_QUType_ptr.set(o+10,&t9);
    static_QUType_ptr.set(o+11,&t10);
    static_QUType_ptr.set(o+12,&t11);
    static_QUType_ptr.set(o+13,&t12);
    static_QUType_ptr.set(o+14,&t13);
    static_QUType_ptr.set(o+15,&t14);
    static_QUType_ptr.set(o+16,&t15);
    static_QUType_ptr.set(o+17,&t16);
    static_QUType_ptr.set(o+18,&t17);
    static_QUType_ptr.set(o+19,&t18);
    activate_signal( clist, o );
}

// SIGNAL advancedSearchReady
void EvaPacketManager::advancedSearchReady( const int t0, const bool t1, const std::list<AdvancedUser> t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 58 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_int.set(o+1,t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL addBuddyExReply
void EvaPacketManager::addBuddyExReply( const unsigned int t0, const unsigned char t1, const unsigned char t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 59 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    activate_signal( clist, o );
}

// SIGNAL requestAuthInfoReply
void EvaPacketManager::requestAuthInfoReply( const unsigned char t0, const unsigned char t1, const unsigned char* t2, const int t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 60 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,t2);
    static_QUType_int.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL receivedMyAuthSettings
void EvaPacketManager::receivedMyAuthSettings( const unsigned char t0, const QString& t1, const QString& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 61 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL updateAuthSettingResult
void EvaPacketManager::updateAuthSettingResult( const unsigned char t0, const unsigned char t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 62 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL requestQuestionReply
void EvaPacketManager::requestQuestionReply( const unsigned char t0, const unsigned char t1, const unsigned char* t2, const int t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 63 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,t2);
    static_QUType_int.set(o+4,t3);
    activate_signal( clist, o );
}

// SIGNAL addFriendAuthExReply
void EvaPacketManager::addFriendAuthExReply( const unsigned int t0, const unsigned char t1, const bool t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 64 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_bool.set(o+3,t2);
    activate_signal( clist, o );
}

// SIGNAL receivedSysMessage
void EvaPacketManager::receivedSysMessage( const unsigned char t0, const unsigned int t1, const unsigned int t2, const QString& t3, const bool t4, const unsigned char* t5, const unsigned int t6 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 65 );
    if ( !clist )
	return;
    QUObject o[8];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_QString.set(o+4,t3);
    static_QUType_bool.set(o+5,t4);
    static_QUType_ptr.set(o+6,t5);
    static_QUType_ptr.set(o+7,&t6);
    activate_signal( clist, o );
}

// SIGNAL receivedVerifyAddingMessageReply
void EvaPacketManager::receivedVerifyAddingMessageReply( const unsigned int t0, const unsigned char t1, const unsigned char t2, const unsigned char t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 66 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    activate_signal( clist, o );
}

// SIGNAL qunSysMessage
void EvaPacketManager::qunSysMessage( const unsigned int t0, const unsigned short t1, const unsigned int t2, const unsigned char t3, const unsigned int t4, const unsigned int t5, const QString& t6, const unsigned char* t7, const unsigned short t8, const unsigned char* t9, const unsigned short t10 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 67 );
    if ( !clist )
	return;
    QUObject o[12];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    static_QUType_ptr.set(o+5,&t4);
    static_QUType_ptr.set(o+6,&t5);
    static_QUType_QString.set(o+7,t6);
    static_QUType_ptr.set(o+8,t7);
    static_QUType_ptr.set(o+9,&t8);
    static_QUType_ptr.set(o+10,t9);
    static_QUType_ptr.set(o+11,&t10);
    activate_signal( clist, o );
}

// SIGNAL receivedQQNews
void EvaPacketManager::receivedQQNews( const QString& t0, const QString& t1, const QString& t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 68 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_QString.set(o+1,t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    activate_signal( clist, o );
}

bool EvaPacketManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: doRequestLoginToken(); break;
    case 1: doRequestLoginTokenEx(); break;
    case 2: doRequestLoginTokenEx((const QString&)static_QUType_QString.get(_o+1)); break;
    case 3: doLogin(); break;
    case 4: doLogout(); break;
    case 5: doGetUserInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 6: doModifyDetails((QStringList)(*((QStringList*)static_QUType_ptr.get(_o+1)))); break;
    case 7: doModifyDetails((QStringList)(*((QStringList*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2)); break;
    case 8: doModifyDetails((QStringList)(*((QStringList*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 9: doChangeStatus((EvaUser::UserStatus)(*((EvaUser::UserStatus*)static_QUType_ptr.get(_o+1)))); break;
    case 10: doRequestFileAgentKey(); break;
    case 11: doGetOnlineFriends(); break;
    case 12: doGetAllFriends(); break;
    case 13: doGetAllLevels(); break;
    case 14: requestFriendLevel((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 15: doSendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3)); break;
    case 16: doSendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(const char)(*((const char*)static_QUType_ptr.get(_o+4)))); break;
    case 17: doSendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(const char)(*((const char*)static_QUType_ptr.get(_o+4))),(const bool)static_QUType_bool.get(_o+5)); break;
    case 18: doSendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(const char)(*((const char*)static_QUType_ptr.get(_o+4))),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6)); break;
    case 19: doSendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(const char)(*((const char*)static_QUType_ptr.get(_o+4))),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7)); break;
    case 20: doSendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(const char)(*((const char*)static_QUType_ptr.get(_o+4))),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const char)(*((const char*)static_QUType_ptr.get(_o+8)))); break;
    case 21: doSendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(const char)(*((const char*)static_QUType_ptr.get(_o+4))),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const char)(*((const char*)static_QUType_ptr.get(_o+9)))); break;
    case 22: doSendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(const char)(*((const char*)static_QUType_ptr.get(_o+4))),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10)))); break;
    case 23: doGetGroups(); break;
    case 24: doUploadGroups(); break;
    case 25: doDeleteBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 26: doAddBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 27: doAddAuthBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 28: doApproveBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 29: doRejectBuddy((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 30: doSearchUsers(); break;
    case 31: doSearchUsers((const bool)static_QUType_bool.get(_o+1)); break;
    case 32: doSearchUsers((const bool)static_QUType_bool.get(_o+1),(const QString)static_QUType_QString.get(_o+2)); break;
    case 33: doSearchUsers((const bool)static_QUType_bool.get(_o+1),(const QString)static_QUType_QString.get(_o+2),(const QString)static_QUType_QString.get(_o+3)); break;
    case 34: doSearchUsers((const bool)static_QUType_bool.get(_o+1),(const QString)static_QUType_QString.get(_o+2),(const QString)static_QUType_QString.get(_o+3),(const QString)static_QUType_QString.get(_o+4)); break;
    case 35: doSearchUsers((const bool)static_QUType_bool.get(_o+1),(const QString)static_QUType_QString.get(_o+2),(const QString)static_QUType_QString.get(_o+3),(const QString)static_QUType_QString.get(_o+4),(const QString)static_QUType_QString.get(_o+5)); break;
    case 36: doSearchUsers((const bool)static_QUType_bool.get(_o+1),(const QString)static_QUType_QString.get(_o+2),(const QString)static_QUType_QString.get(_o+3),(const QString)static_QUType_QString.get(_o+4),(const QString)static_QUType_QString.get(_o+5),(const bool)static_QUType_bool.get(_o+6)); break;
    case 37: doDeleteMeFrom((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 38: doRequestQunInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 39: doRequestQunMemberInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const std::list<unsigned int>&)*((const std::list<unsigned int>*)static_QUType_ptr.get(_o+2))); break;
    case 40: doRequestQunOnlineMembers((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 41: doSendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2)); break;
    case 42: doSendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2),(const char)(*((const char*)static_QUType_ptr.get(_o+3)))); break;
    case 43: doSendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2),(const char)(*((const char*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4)); break;
    case 44: doSendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2),(const char)(*((const char*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(const bool)static_QUType_bool.get(_o+5)); break;
    case 45: doSendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2),(const char)(*((const char*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6)); break;
    case 46: doSendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2),(const char)(*((const char*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const char)(*((const char*)static_QUType_ptr.get(_o+7)))); break;
    case 47: doSendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2),(const char)(*((const char*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const char)(*((const char*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8)))); break;
    case 48: doSendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2),(const char)(*((const char*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const char)(*((const char*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const char)(*((const char*)static_QUType_ptr.get(_o+9)))); break;
    case 49: doSearchQun((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 50: doJoinQun((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 51: doJoinQunAuth((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char*)static_QUType_ptr.get(_o+2),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+3))),(const QString&)static_QUType_QString.get(_o+4)); break;
    case 52: doApproveQun((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned char*)static_QUType_ptr.get(_o+3),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+4)))); break;
    case 53: doRejectQun((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QString&)static_QUType_QString.get(_o+3),(const unsigned char*)static_QUType_ptr.get(_o+4),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5)))); break;
    case 54: doModifyQunInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(unsigned char)(*((unsigned char*)static_QUType_ptr.get(_o+2))),(unsigned short)(*((unsigned short*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(QString)static_QUType_QString.get(_o+5),(QString)static_QUType_QString.get(_o+6)); break;
    case 55: doModifyQunCard((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(QString)static_QUType_QString.get(_o+3),(unsigned char)(*((unsigned char*)static_QUType_ptr.get(_o+4))),(QString)static_QUType_QString.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QString)static_QUType_QString.get(_o+7)); break;
    case 56: doQunSetAdmin((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3)); break;
    case 57: doQunTransfer((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2)))); break;
    case 58: doModifyQunMembers((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const std::list<unsigned int>)(*((const std::list<unsigned int>*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3)); break;
    case 59: doRequestQunCard((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2)))); break;
    case 60: doQunExit((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 61: doQunCreate((const QString&)static_QUType_QString.get(_o+1),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+2))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+3))),(const QString&)static_QUType_QString.get(_o+4),(const QString&)static_QUType_QString.get(_o+5),(const std::list<unsigned int>&)*((const std::list<unsigned int>*)static_QUType_ptr.get(_o+6))); break;
    case 62: doRequestQunRealNames((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 63: doRequestExtraInfo(); break;
    case 64: doModifySignature((const QString)static_QUType_QString.get(_o+1)); break;
    case 65: doDeleteSignature(); break;
    case 66: static_QUType_bool.set(_o,doRequestSignature()); break;
    case 67: static_QUType_bool.set(_o,doRequestSignature((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))))); break;
    case 68: static_QUType_bool.set(_o,doRequestSignature((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2))); break;
    case 69: doUploadMemo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const MemoItem&)*((const MemoItem*)static_QUType_ptr.get(_o+2))); break;
    case 70: doRemoveMemo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 71: doDownloadMemo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 72: doSendFileUdpRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const short)(*((const short*)static_QUType_ptr.get(_o+4)))); break;
    case 73: doSendFileUdpRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const short)(*((const short*)static_QUType_ptr.get(_o+4))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5)))); break;
    case 74: doAcceptFileRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const short)(*((const short*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3)))); break;
    case 75: doAcceptFileRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const short)(*((const short*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4)))); break;
    case 76: doCancelFileRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const short)(*((const short*)static_QUType_ptr.get(_o+2)))); break;
    case 77: doCancelFileRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const short)(*((const short*)static_QUType_ptr.get(_o+2))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+3)))); break;
    case 78: doNotifyAgentTransfer((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5)))); break;
    case 79: doNotifyAgentTransfer((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+6)))); break;
    case 80: doNotifyIpEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+5))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+6))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+7))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+8))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+9))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+10))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+11))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+12))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+13))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+14))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+15))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+16))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+17))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+18))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+19)))); break;
    case 81: doAdvancedSearch(); break;
    case 82: doAdvancedSearch((const int)static_QUType_int.get(_o+1)); break;
    case 83: doAdvancedSearch((const int)static_QUType_int.get(_o+1),(const bool)static_QUType_bool.get(_o+2)); break;
    case 84: doAdvancedSearch((const int)static_QUType_int.get(_o+1),(const bool)static_QUType_bool.get(_o+2),(const bool)static_QUType_bool.get(_o+3)); break;
    case 85: doAdvancedSearch((const int)static_QUType_int.get(_o+1),(const bool)static_QUType_bool.get(_o+2),(const bool)static_QUType_bool.get(_o+3),(const int)static_QUType_int.get(_o+4)); break;
    case 86: doAdvancedSearch((const int)static_QUType_int.get(_o+1),(const bool)static_QUType_bool.get(_o+2),(const bool)static_QUType_bool.get(_o+3),(const int)static_QUType_int.get(_o+4),(const int)static_QUType_int.get(_o+5)); break;
    case 87: doAdvancedSearch((const int)static_QUType_int.get(_o+1),(const bool)static_QUType_bool.get(_o+2),(const bool)static_QUType_bool.get(_o+3),(const int)static_QUType_int.get(_o+4),(const int)static_QUType_int.get(_o+5),(const int)static_QUType_int.get(_o+6)); break;
    case 88: doAdvancedSearch((const int)static_QUType_int.get(_o+1),(const bool)static_QUType_bool.get(_o+2),(const bool)static_QUType_bool.get(_o+3),(const int)static_QUType_int.get(_o+4),(const int)static_QUType_int.get(_o+5),(const int)static_QUType_int.get(_o+6),(const int)static_QUType_int.get(_o+7)); break;
    case 89: doAddBuddyEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 90: doRequestAuthInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 91: doRequestAuthInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2)))); break;
    case 92: doRequestAuthInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 93: doRequestAuthInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const QString&)static_QUType_QString.get(_o+3),(const QString&)static_QUType_QString.get(_o+4)); break;
    case 94: doRequestAuthInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const QString&)static_QUType_QString.get(_o+3),(const QString&)static_QUType_QString.get(_o+4),(const bool)static_QUType_bool.get(_o+5)); break;
    case 95: doRequestAuthQuestion((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 96: doRequestAuthQuestion((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2)); break;
    case 97: doRequestAuthQuestion((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 98: doSetMyAuthQuestion(); break;
    case 99: doSetMyAuthQuestion((const QString&)static_QUType_QString.get(_o+1)); break;
    case 100: doSetMyAuthQuestion((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2)); break;
    case 101: doRequestMyAuthQuestionSetting(); break;
    case 102: doAddBuddyAuthEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2)))); break;
    case 103: doAddBuddyAuthEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3)))); break;
    case 104: doAddBuddyAuthEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char*)static_QUType_ptr.get(_o+4)); break;
    case 105: doAddBuddyAuthEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char*)static_QUType_ptr.get(_o+4),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5)))); break;
    case 106: doAddBuddyAuthEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char*)static_QUType_ptr.get(_o+4),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned char*)static_QUType_ptr.get(_o+6)); break;
    case 107: doAddBuddyAuthEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char*)static_QUType_ptr.get(_o+4),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned char*)static_QUType_ptr.get(_o+6),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+7)))); break;
    case 108: doAddBuddyAuthEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char*)static_QUType_ptr.get(_o+4),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned char*)static_QUType_ptr.get(_o+6),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+7))),(const QString&)static_QUType_QString.get(_o+8)); break;
    case 109: doAddBuddyAuthEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char*)static_QUType_ptr.get(_o+4),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned char*)static_QUType_ptr.get(_o+6),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+7))),(const QString&)static_QUType_QString.get(_o+8),(const bool)static_QUType_bool.get(_o+9)); break;
    case 110: doVerifyAddingMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char*)static_QUType_ptr.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3)))); break;
    case 111: doGetWeatherForecast((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 112: doGetContacts(); break;
    case 113: doGetContacts((int)static_QUType_int.get(_o+1)); break;
    case 114: slotConnectReady(); break;
    case 115: newPacketSlot(); break;
    case 116: networkExceptionSlot((int)static_QUType_int.get(_o+1)); break;
    case 117: packetExceptionSlot((int)static_QUType_int.get(_o+1)); break;
    case 118: timerSlot(); break;
    case 119: slotClientNotReady(); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaPacketManager::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: networkException((int)static_QUType_int.get(_o+1)); break;
    case 1: packetException((int)static_QUType_int.get(_o+1)); break;
    case 2: serverBusy(); break;
    case 3: logoutOK(); break;
    case 4: onlineReady(); break;
    case 5: offlineReady(); break;
    case 6: invisibleReady(); break;
    case 7: leaveReady(); break;
    case 8: kickedOut((const QString)static_QUType_QString.get(_o+1)); break;
    case 9: friendStatusChanged((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 10: friendListReady(); break;
    case 11: userInfoReady((QStringList)(*((QStringList*)static_QUType_ptr.get(_o+1)))); break;
    case 12: extraInfoReady(); break;
    case 13: modifyInfo((bool)static_QUType_bool.get(_o+1)); break;
    case 14: sentMessageResult((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 15: txtMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10))),(const char)(*((const char*)static_QUType_ptr.get(_o+11)))); break;
    case 16: sysMessage((int)static_QUType_int.get(_o+1),(QString)static_QUType_QString.get(_o+2)); break;
    case 17: friendGroupsUploadReady((bool)static_QUType_bool.get(_o+1)); break;
    case 18: deleteBuddyReady((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 19: addingBuddy((int)static_QUType_int.get(_o+1)); break;
    case 20: addBuddyReady(); break;
    case 21: addBuddyRejected(); break;
    case 22: addBuddyNeedAuth(); break;
    case 23: addAnonymous((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+2)))); break;
    case 24: addBuddySentToServer((bool)static_QUType_bool.get(_o+1)); break;
    case 25: searchUsersReady((const bool)static_QUType_bool.get(_o+1),(const std::list<OnlineUser>)(*((const std::list<OnlineUser>*)static_QUType_ptr.get(_o+2)))); break;
    case 26: deleteMeReady((bool)static_QUType_bool.get(_o+1)); break;
    case 27: friendSignatureChanged((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QDateTime)(*((const QDateTime*)static_QUType_ptr.get(_o+2))),(const QString)static_QUType_QString.get(_o+3)); break;
    case 28: qunSentMessageResult((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 29: qunTxtMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+2))),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10))),(const char)(*((const char*)static_QUType_ptr.get(_o+11)))); break;
    case 30: qunInfomationReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 31: qunMemberInfoReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 32: qunOnlineListReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 33: qunSearchReady((const std::list<QunInfo>)(*((const std::list<QunInfo>*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2)); break;
    case 34: joinQunReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 35: joinQunAuthReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2)))); break;
    case 36: qunSystemMessageRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2)); break;
    case 37: qunJoinEvent((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const short)(*((const short*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4)))); break;
    case 38: qunRequestUpdateDisplay(); break;
    case 39: qunModifyInfoReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 40: qunModifyQunCardReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4)); break;
    case 41: qunSetAdminReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(QString)static_QUType_QString.get(_o+5)); break;
    case 42: qunTransferReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4)); break;
    case 43: qunModifyQunMembersReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 44: qunRequestQunCardReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5))),(QString)static_QUType_QString.get(_o+6),(QString)static_QUType_QString.get(_o+7),(QString)static_QUType_QString.get(_o+8),(QString)static_QUType_QString.get(_o+9)); break;
    case 45: qunExitReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 46: qunCreateDone((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 47: qunCreateFailed((QString)static_QUType_QString.get(_o+1)); break;
    case 48: qunActiveQunFailed((QString)static_QUType_QString.get(_o+1)); break;
    case 49: signatureModifyReply((const bool)static_QUType_bool.get(_o+1)); break;
    case 50: signatureDeleteReply((const bool)static_QUType_bool.get(_o+1)); break;
    case 51: memoUploadReply((const bool)static_QUType_bool.get(_o+1)); break;
    case 52: memoDownloadReply((const MemoItem&)*((const MemoItem*)static_QUType_ptr.get(_o+1))); break;
    case 53: memoNoMemoFound(); break;
    case 54: receivedFileRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QString)static_QUType_QString.get(_o+3),(const int)static_QUType_int.get(_o+4),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5)))); break;
    case 55: receivedFileAccepted((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5)))); break;
    case 56: receivedFileAgentInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+5))),(const unsigned char*)static_QUType_ptr.get(_o+6)); break;
    case 57: receivedFileNotifyIpEx((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+5))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+6))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+7))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+8))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+9))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+10))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+11))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+12))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+13))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+14))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+15))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+16))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+17))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+18))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+19)))); break;
    case 58: advancedSearchReady((const int)static_QUType_int.get(_o+1),(const bool)static_QUType_bool.get(_o+2),(const std::list<AdvancedUser>)(*((const std::list<AdvancedUser>*)static_QUType_ptr.get(_o+3)))); break;
    case 59: addBuddyExReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+3)))); break;
    case 60: requestAuthInfoReply((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned char*)static_QUType_ptr.get(_o+3),(const int)static_QUType_int.get(_o+4)); break;
    case 61: receivedMyAuthSettings((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const QString&)static_QUType_QString.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    case 62: updateAuthSettingResult((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2)))); break;
    case 63: requestQuestionReply((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned char*)static_QUType_ptr.get(_o+3),(const int)static_QUType_int.get(_o+4)); break;
    case 64: addFriendAuthExReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3)); break;
    case 65: receivedSysMessage((const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const QString&)static_QUType_QString.get(_o+4),(const bool)static_QUType_bool.get(_o+5),(const unsigned char*)static_QUType_ptr.get(_o+6),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+7)))); break;
    case 66: receivedVerifyAddingMessageReply((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+2))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+3))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4)))); break;
    case 67: qunSysMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+5))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+6))),(const QString&)static_QUType_QString.get(_o+7),(const unsigned char*)static_QUType_ptr.get(_o+8),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+9))),(const unsigned char*)static_QUType_ptr.get(_o+10),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+11)))); break;
    case 68: receivedQQNews((const QString&)static_QUType_QString.get(_o+1),(const QString&)static_QUType_QString.get(_o+2),(const QString&)static_QUType_QString.get(_o+3)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaPacketManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaPacketManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
