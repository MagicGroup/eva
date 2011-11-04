/****************************************************************************
** EvaChatWindowManager meta object code from reading C++ file 'evachatwindowmanager.h'
**
** Created: Tue Feb 8 23:56:30 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evachatwindowmanager.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaChatWindowManager::className() const
{
    return "EvaChatWindowManager";
}

QMetaObject *EvaChatWindowManager::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaChatWindowManager( "EvaChatWindowManager", &EvaChatWindowManager::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaChatWindowManager::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaChatWindowManager", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaChatWindowManager::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaChatWindowManager", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaChatWindowManager::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QObject::staticMetaObject();
    static const QUMethod slot_0 = {"graphicChanged", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In }
    };
    static const QUMethod slot_1 = {"slotReceivedMessage", 4, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotReceivedMessage", 5, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotReceivedMessage", 6, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_4 = {"slotReceivedMessage", 7, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"slotReceivedMessage", 8, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_6 = {"slotReceivedMessage", 9, param_slot_6 };
    static const QUParameter param_slot_7[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_7 = {"slotReceivedMessage", 10, param_slot_7 };
    static const QUParameter param_slot_8[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In },
	{ "red", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_8 = {"slotReceivedMessage", 11, param_slot_8 };
    static const QUParameter param_slot_9[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "ok", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_9 = {"slotSendResult", 2, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_10 = {"slotBuddyQQShowReady", 1, param_slot_10 };
    static const QUMethod slot_11 = {"slotMyQQShowReady", 0, 0 };
    static const QUParameter param_slot_12[] = {
	{ 0, &static_QUType_ptr, "EvaChatWindow", QUParameter::Out },
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_12 = {"getWindow", 2, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "myName", &static_QUType_QString, 0, QUParameter::In },
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_13 = {"setMyName", 2, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "qunID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "senderQQ", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In },
	{ "red", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_14 = {"slotReceivedQunMessage", 11, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "ok", &static_QUType_bool, 0, QUParameter::In },
	{ "msg", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"slotQunSendResult", 3, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "qunID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "imType", &static_QUType_ptr, "short", QUParameter::In },
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "commander", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_16 = {"slotQunJoinEvent", 4, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_ptr, "EvaQunChatWindow", QUParameter::Out },
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_17 = {"getQunWindow", 2, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_18 = {"slotQunOnlineMembers", 1, param_slot_18 };
    static const QUParameter param_slot_19[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "fileName", &static_QUType_QString, 0, QUParameter::In },
	{ "tmpFileName", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_19 = {"slotQunPicReady", 3, param_slot_19 };
    static const QUParameter param_slot_20[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_20 = {"slotQunPicSent", 4, param_slot_20 };
    static const QUParameter param_slot_21[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_21 = {"slotSendImageError", 2, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_22 = {"slotQunMemberInfoReady", 1, param_slot_22 };
    static const QUMethod slot_23 = {"slotQunListUpdated", 0, 0 };
    static const QUParameter param_slot_24[] = {
	{ "frd", &static_QUType_ptr, "QQFriend", QUParameter::In },
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "fileName", &static_QUType_QString, 0, QUParameter::In },
	{ "size", &static_QUType_int, 0, QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_24 = {"slotReceivedFileRequest", 5, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isAccepted", &static_QUType_bool, 0, QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_25 = {"slotReceivedFileAccepted", 4, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "oldSession", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "newSession", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_26 = {"slotChangeFileSessionTo", 3, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "EvaFileStatus", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_27 = {"slotFileNotifyNormalInfo", 7, param_slot_27 };
    static const QUParameter param_slot_28[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "url", &static_QUType_ptr, "KURL", QUParameter::In },
	{ "size", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "bytes", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "time", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_28 = {"slotFileStatusNotification", 6, param_slot_28 };
    static const QMetaData slot_tbl[] = {
	{ "graphicChanged()", &slot_0, QMetaData::Public },
	{ "slotReceivedMessage(unsigned int,bool,QString,QDateTime)", &slot_1, QMetaData::Public },
	{ "slotReceivedMessage(unsigned int,bool,QString,QDateTime,const char)", &slot_2, QMetaData::Public },
	{ "slotReceivedMessage(unsigned int,bool,QString,QDateTime,const char,const bool)", &slot_3, QMetaData::Public },
	{ "slotReceivedMessage(unsigned int,bool,QString,QDateTime,const char,const bool,const bool)", &slot_4, QMetaData::Public },
	{ "slotReceivedMessage(unsigned int,bool,QString,QDateTime,const char,const bool,const bool,const bool)", &slot_5, QMetaData::Public },
	{ "slotReceivedMessage(unsigned int,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char)", &slot_6, QMetaData::Public },
	{ "slotReceivedMessage(unsigned int,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char)", &slot_7, QMetaData::Public },
	{ "slotReceivedMessage(unsigned int,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &slot_8, QMetaData::Public },
	{ "slotSendResult(unsigned int,bool)", &slot_9, QMetaData::Public },
	{ "slotBuddyQQShowReady(const unsigned int)", &slot_10, QMetaData::Public },
	{ "slotMyQQShowReady()", &slot_11, QMetaData::Public },
	{ "getWindow(const unsigned int)", &slot_12, QMetaData::Public },
	{ "setMyName(QString,const unsigned int)", &slot_13, QMetaData::Public },
	{ "slotReceivedQunMessage(unsigned int,unsigned int,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &slot_14, QMetaData::Public },
	{ "slotQunSendResult(unsigned int,bool,QString)", &slot_15, QMetaData::Public },
	{ "slotQunJoinEvent(const unsigned int,const short,const unsigned int,const unsigned int)", &slot_16, QMetaData::Public },
	{ "getQunWindow(const unsigned int)", &slot_17, QMetaData::Public },
	{ "slotQunOnlineMembers(const unsigned int)", &slot_18, QMetaData::Public },
	{ "slotQunPicReady(const unsigned int,const QString,const QString)", &slot_19, QMetaData::Public },
	{ "slotQunPicSent(const unsigned int,const unsigned int,const unsigned int,const unsigned short)", &slot_20, QMetaData::Public },
	{ "slotSendImageError(const unsigned int,const QString)", &slot_21, QMetaData::Public },
	{ "slotQunMemberInfoReady(const unsigned int)", &slot_22, QMetaData::Public },
	{ "slotQunListUpdated()", &slot_23, QMetaData::Public },
	{ "slotReceivedFileRequest(QQFriend*,const unsigned int,const QString,const int,const unsigned char)", &slot_24, QMetaData::Public },
	{ "slotReceivedFileAccepted(const unsigned int,const unsigned int,const bool,const unsigned char)", &slot_25, QMetaData::Public },
	{ "slotChangeFileSessionTo(const unsigned int,const unsigned int,const unsigned int)", &slot_26, QMetaData::Public },
	{ "slotFileNotifyNormalInfo(const unsigned int,const unsigned int,EvaFileStatus,const QString,const QString,const unsigned int,const unsigned char)", &slot_27, QMetaData::Public },
	{ "slotFileStatusNotification(const unsigned int,const unsigned int,const KURL&,const unsigned int,const unsigned int,const unsigned int)", &slot_28, QMetaData::Public }
    };
    static const QUParameter param_signal_0[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestDetails", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::InOut },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In },
	{ "green", &static_QUType_ptr, "char", QUParameter::In },
	{ "red", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod signal_1 = {"sendMessage", 10, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestHistory", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_3 = {"requestBuddyQQShow", 1, param_signal_3 };
    static const QUMethod signal_4 = {"requestMyQQShow", 0, 0 };
    static const QUParameter param_signal_5[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_5 = {"requestQunDetails", 1, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "qq", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_6 = {"requestQunCard", 2, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_ptr, "char", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod signal_7 = {"sendQunMessage", 9, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_8 = {"requestQunHistory", 1, param_signal_8 };
    static const QUParameter param_signal_9[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_9 = {"requestQunOnlineList", 1, param_signal_9 };
    static const QUParameter param_signal_10[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_10 = {"requestQunRealNames", 1, param_signal_10 };
    static const QUParameter param_signal_11[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "QValueList<QString>", QUParameter::In },
	{ 0, &static_QUType_ptr, "QValueList<unsigned int>", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_11 = {"fileTransferSend", 5, param_signal_11 };
    static const QUParameter param_signal_12[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_12 = {"fileTransferAccept", 4, param_signal_12 };
    static const QUParameter param_signal_13[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_13 = {"fileTransferCancel", 2, param_signal_13 };
    static const QUParameter param_signal_14[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_14 = {"fileTransferResume", 3, param_signal_14 };
    static const QMetaData signal_tbl[] = {
	{ "requestDetails(const unsigned int)", &signal_0, QMetaData::Public },
	{ "sendMessage(const unsigned int,const bool,QString&,const char,const bool,const bool,const bool,const char,const char,const char)", &signal_1, QMetaData::Public },
	{ "requestHistory(const unsigned int)", &signal_2, QMetaData::Public },
	{ "requestBuddyQQShow(const unsigned int)", &signal_3, QMetaData::Public },
	{ "requestMyQQShow()", &signal_4, QMetaData::Public },
	{ "requestQunDetails(const unsigned int)", &signal_5, QMetaData::Public },
	{ "requestQunCard(const unsigned int,const unsigned int)", &signal_6, QMetaData::Public },
	{ "sendQunMessage(const unsigned int,QString&,const char,const bool,const bool,const bool,const char,const char,const char)", &signal_7, QMetaData::Public },
	{ "requestQunHistory(const unsigned int)", &signal_8, QMetaData::Public },
	{ "requestQunOnlineList(const unsigned int)", &signal_9, QMetaData::Public },
	{ "requestQunRealNames(const unsigned int)", &signal_10, QMetaData::Public },
	{ "fileTransferSend(const unsigned int,const unsigned int,const QValueList<QString>,const QValueList<unsigned int>,const unsigned char)", &signal_11, QMetaData::Public },
	{ "fileTransferAccept(const unsigned int,const unsigned int,const QString,const unsigned char)", &signal_12, QMetaData::Public },
	{ "fileTransferCancel(const unsigned int,const unsigned int)", &signal_13, QMetaData::Public },
	{ "fileTransferResume(const unsigned int,const unsigned int,const bool)", &signal_14, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaChatWindowManager", parentObject,
	slot_tbl, 29,
	signal_tbl, 15,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaChatWindowManager.setMetaObject( metaObj );
    return metaObj;
}

void* EvaChatWindowManager::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaChatWindowManager" ) )
	return this;
    return QObject::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestDetails
void EvaChatWindowManager::requestDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 0 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL sendMessage
void EvaChatWindowManager::sendMessage( const unsigned int t0, const bool t1, QString& t2, const char t3, const bool t4, const bool t5, const bool t6, const char t7, const char t8, const char t9 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
    if ( !clist )
	return;
    QUObject o[11];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_bool.set(o+2,t1);
    static_QUType_QString.set(o+3,t2);
    static_QUType_ptr.set(o+4,&t3);
    static_QUType_bool.set(o+5,t4);
    static_QUType_bool.set(o+6,t5);
    static_QUType_bool.set(o+7,t6);
    static_QUType_ptr.set(o+8,&t7);
    static_QUType_ptr.set(o+9,&t8);
    static_QUType_ptr.set(o+10,&t9);
    activate_signal( clist, o );
    t2 = static_QUType_QString.get(o+3);
}

// SIGNAL requestHistory
void EvaChatWindowManager::requestHistory( const unsigned int t0 )
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

// SIGNAL requestBuddyQQShow
void EvaChatWindowManager::requestBuddyQQShow( const unsigned int t0 )
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

// SIGNAL requestMyQQShow
void EvaChatWindowManager::requestMyQQShow()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL requestQunDetails
void EvaChatWindowManager::requestQunDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunCard
void EvaChatWindowManager::requestQunCard( const unsigned int t0, const unsigned int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL sendQunMessage
void EvaChatWindowManager::sendQunMessage( const unsigned int t0, QString& t1, const char t2, const bool t3, const bool t4, const bool t5, const char t6, const char t7, const char t8 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[10];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_QString.set(o+2,t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_bool.set(o+4,t3);
    static_QUType_bool.set(o+5,t4);
    static_QUType_bool.set(o+6,t5);
    static_QUType_ptr.set(o+7,&t6);
    static_QUType_ptr.set(o+8,&t7);
    static_QUType_ptr.set(o+9,&t8);
    activate_signal( clist, o );
    t1 = static_QUType_QString.get(o+2);
}

// SIGNAL requestQunHistory
void EvaChatWindowManager::requestQunHistory( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunOnlineList
void EvaChatWindowManager::requestQunOnlineList( const unsigned int t0 )
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

// SIGNAL requestQunRealNames
void EvaChatWindowManager::requestQunRealNames( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 10 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL fileTransferSend
void EvaChatWindowManager::fileTransferSend( const unsigned int t0, const unsigned int t1, const QValueList<QString> t2, const QValueList<unsigned int> t3, const unsigned char t4 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 11 );
    if ( !clist )
	return;
    QUObject o[6];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_ptr.set(o+3,&t2);
    static_QUType_ptr.set(o+4,&t3);
    static_QUType_ptr.set(o+5,&t4);
    activate_signal( clist, o );
}

// SIGNAL fileTransferAccept
void EvaChatWindowManager::fileTransferAccept( const unsigned int t0, const unsigned int t1, const QString t2, const unsigned char t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 12 );
    if ( !clist )
	return;
    QUObject o[5];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_QString.set(o+3,t2);
    static_QUType_ptr.set(o+4,&t3);
    activate_signal( clist, o );
}

// SIGNAL fileTransferCancel
void EvaChatWindowManager::fileTransferCancel( const unsigned int t0, const unsigned int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 13 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL fileTransferResume
void EvaChatWindowManager::fileTransferResume( const unsigned int t0, const unsigned int t1, const bool t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 14 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_bool.set(o+3,t2);
    activate_signal( clist, o );
}

bool EvaChatWindowManager::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: graphicChanged(); break;
    case 1: slotReceivedMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4)))); break;
    case 2: slotReceivedMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5)))); break;
    case 3: slotReceivedMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6)); break;
    case 4: slotReceivedMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7)); break;
    case 5: slotReceivedMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8)); break;
    case 6: slotReceivedMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8),(const char)(*((const char*)static_QUType_ptr.get(_o+9)))); break;
    case 7: slotReceivedMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10)))); break;
    case 8: slotReceivedMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10))),(const char)(*((const char*)static_QUType_ptr.get(_o+11)))); break;
    case 9: slotSendResult((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2)); break;
    case 10: slotBuddyQQShowReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 11: slotMyQQShowReady(); break;
    case 12: static_QUType_ptr.set(_o,getWindow((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))))); break;
    case 13: setMyName((QString)static_QUType_QString.get(_o+1),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2)))); break;
    case 14: slotReceivedQunMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+2))),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10))),(const char)(*((const char*)static_QUType_ptr.get(_o+11)))); break;
    case 15: slotQunSendResult((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(bool)static_QUType_bool.get(_o+2),(QString)static_QUType_QString.get(_o+3)); break;
    case 16: slotQunJoinEvent((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const short)(*((const short*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4)))); break;
    case 17: static_QUType_ptr.set(_o,getQunWindow((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))))); break;
    case 18: slotQunOnlineMembers((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 19: slotQunPicReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2),(const QString)static_QUType_QString.get(_o+3)); break;
    case 20: slotQunPicSent((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+4)))); break;
    case 21: slotSendImageError((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString)static_QUType_QString.get(_o+2)); break;
    case 22: slotQunMemberInfoReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 23: slotQunListUpdated(); break;
    case 24: slotReceivedFileRequest((QQFriend*)static_QUType_ptr.get(_o+1),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QString)static_QUType_QString.get(_o+3),(const int)static_QUType_int.get(_o+4),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5)))); break;
    case 25: slotReceivedFileAccepted((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4)))); break;
    case 26: slotChangeFileSessionTo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3)))); break;
    case 27: slotFileNotifyNormalInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(EvaFileStatus)(*((EvaFileStatus*)static_QUType_ptr.get(_o+3))),(const QString)static_QUType_QString.get(_o+4),(const QString)static_QUType_QString.get(_o+5),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+6))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+7)))); break;
    case 28: slotFileStatusNotification((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const KURL&)*((const KURL*)static_QUType_ptr.get(_o+3)),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+5))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+6)))); break;
    default:
	return QObject::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaChatWindowManager::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: sendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(const char)(*((const char*)static_QUType_ptr.get(_o+4))),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10)))); break;
    case 2: requestHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: requestBuddyQQShow((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 4: requestMyQQShow(); break;
    case 5: requestQunDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 6: requestQunCard((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2)))); break;
    case 7: sendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2),(const char)(*((const char*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const char)(*((const char*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const char)(*((const char*)static_QUType_ptr.get(_o+9)))); break;
    case 8: requestQunHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 9: requestQunOnlineList((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 10: requestQunRealNames((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 11: fileTransferSend((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QValueList<QString>)(*((const QValueList<QString>*)static_QUType_ptr.get(_o+3))),(const QValueList<unsigned int>)(*((const QValueList<unsigned int>*)static_QUType_ptr.get(_o+4))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5)))); break;
    case 12: fileTransferAccept((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QString)static_QUType_QString.get(_o+3),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4)))); break;
    case 13: fileTransferCancel((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2)))); break;
    case 14: fileTransferResume((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3)); break;
    default:
	return QObject::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaChatWindowManager::qt_property( int id, int f, QVariant* v)
{
    return QObject::qt_property( id, f, v);
}

bool EvaChatWindowManager::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
