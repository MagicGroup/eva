/****************************************************************************
** EvaChatWindow meta object code from reading C++ file 'evachatwindow.h'
**
** Created: Tue Feb 8 23:52:17 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evachatwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaChatWindow::className() const
{
    return "EvaChatWindow";
}

QMetaObject *EvaChatWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaChatWindow( "EvaChatWindow", &EvaChatWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaChatWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaChatWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaChatWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaChatWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaChatWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaChatUIBase::staticMetaObject();
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
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In }
    };
    static const QUMethod slot_9 = {"slotAddMessage", 7, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_10 = {"slotAddMessage", 8, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"slotAddMessage", 9, param_slot_11 };
    static const QUParameter param_slot_12[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_12 = {"slotAddMessage", 10, param_slot_12 };
    static const QUParameter param_slot_13[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_13 = {"slotAddMessage", 11, param_slot_13 };
    static const QUParameter param_slot_14[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In },
	{ "u", &static_QUType_bool, 0, QUParameter::In },
	{ "i", &static_QUType_bool, 0, QUParameter::In },
	{ "b", &static_QUType_bool, 0, QUParameter::In },
	{ "blue", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_14 = {"slotAddMessage", 12, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
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
    static const QUMethod slot_15 = {"slotAddMessage", 13, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
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
    static const QUMethod slot_16 = {"slotAddMessage", 14, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ "ok", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"slotSendResult", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_18 = {"slotBuddyQQShowReady", 1, param_slot_18 };
    static const QUMethod slot_19 = {"slotMyQQShowReady", 0, 0 };
    static const QUMethod slot_20 = {"slotFileClick", 0, 0 };
    static const QUParameter param_slot_21[] = {
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "file", &static_QUType_QString, 0, QUParameter::In },
	{ "size", &static_QUType_int, 0, QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_21 = {"slotReceivedFileRequest", 4, param_slot_21 };
    static const QUParameter param_slot_22[] = {
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "isAccepted", &static_QUType_bool, 0, QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_22 = {"slotReceivedFileAccepted", 3, param_slot_22 };
    static const QUParameter param_slot_23[] = {
	{ "oldSession", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "newSession", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_23 = {"slotSessionChangedTo", 2, param_slot_23 };
    static const QUParameter param_slot_24[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "EvaFileStatus", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod slot_24 = {"slotFileNotifyNormalInfo", 6, param_slot_24 };
    static const QUParameter param_slot_25[] = {
	{ "session", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "url", &static_QUType_ptr, "KURL", QUParameter::In },
	{ "size", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "bytes", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "time", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_25 = {"slotFileStatusNotification", 5, param_slot_25 };
    static const QUParameter param_slot_26[] = {
	{ "destFile", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"slotAddImageToInputEdit", 1, param_slot_26 };
    static const QUParameter param_slot_27[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_27 = {"slotSmileySelected", 1, param_slot_27 };
    static const QUMethod slot_28 = {"slotTbBuddyClick", 0, 0 };
    static const QUMethod slot_29 = {"slotSmileyClick", 0, 0 };
    static const QUMethod slot_30 = {"slotFontClick", 0, 0 };
    static const QUMethod slot_31 = {"slotQuickReplyClick", 0, 0 };
    static const QUParameter param_slot_32[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_32 = {"slotQuickReplyActivated", 1, param_slot_32 };
    static const QUMethod slot_33 = {"slotHideShowsClick", 0, 0 };
    static const QUMethod slot_34 = {"slotHistoryClick", 0, 0 };
    static const QUMethod slot_35 = {"slotHistoryWindowClosed", 0, 0 };
    static const QUMethod slot_36 = {"slotSendKeyClick", 0, 0 };
    static const QUMethod slot_37 = {"slotSend", 0, 0 };
    static const QUMethod slot_38 = {"slotTbShowBuddyClick", 0, 0 };
    static const QUMethod slot_39 = {"slotTbShowMeClick", 0, 0 };
    static const QUParameter param_slot_40[] = {
	{ "e", &static_QUType_ptr, "QKeyEvent", QUParameter::In }
    };
    static const QUMethod slot_40 = {"slotInputKeyPress", 1, param_slot_40 };
    static const QUParameter param_slot_41[] = {
	{ "color", &static_QUType_varptr, "\x0a", QUParameter::In },
	{ "size", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_41 = {"slotFontChanged", 2, param_slot_41 };
    static const QUMethod slot_42 = {"setEnterSend", 0, 0 };
    static const QUMethod slot_43 = {"setCtrlEnterSend", 0, 0 };
    static const QUMethod slot_44 = {"slotPbCloseClick", 0, 0 };
    static const QUParameter param_slot_45[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_45 = {"slotFileTransferAcceptClicked", 1, param_slot_45 };
    static const QUParameter param_slot_46[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_46 = {"slotFileTransferSaveAsClicked", 1, param_slot_46 };
    static const QUParameter param_slot_47[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_47 = {"slotFileTransferCancelClicked", 1, param_slot_47 };
    static const QUParameter param_slot_48[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_48 = {"slotFileTransferResume", 2, param_slot_48 };
    static const QUParameter param_slot_49[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_49 = {"slotFilePanelCloseClicked", 1, param_slot_49 };
    static const QUMethod slot_50 = {"slotAddImageClick", 0, 0 };
    static const QUMethod slot_51 = {"slotScreenShotClick", 0, 0 };
    static const QUParameter param_slot_52[] = {
	{ 0, &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_52 = {"slotRegionGrabbed", 1, param_slot_52 };
    static const QUMethod slot_53 = {"slotCustomBtnClick", 0, 0 };
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
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime)", &slot_9, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char)", &slot_10, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool)", &slot_11, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool)", &slot_12, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool,const bool)", &slot_13, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char)", &slot_14, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char)", &slot_15, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &slot_16, QMetaData::Public },
	{ "slotSendResult(bool)", &slot_17, QMetaData::Public },
	{ "slotBuddyQQShowReady(const unsigned int)", &slot_18, QMetaData::Public },
	{ "slotMyQQShowReady()", &slot_19, QMetaData::Public },
	{ "slotFileClick()", &slot_20, QMetaData::Public },
	{ "slotReceivedFileRequest(const unsigned int,const QString&,const int,const unsigned char)", &slot_21, QMetaData::Public },
	{ "slotReceivedFileAccepted(const unsigned int,const bool,const unsigned char)", &slot_22, QMetaData::Public },
	{ "slotSessionChangedTo(const unsigned int,const unsigned int)", &slot_23, QMetaData::Public },
	{ "slotFileNotifyNormalInfo(const unsigned int,EvaFileStatus,const QString,const QString,const unsigned int,const unsigned char)", &slot_24, QMetaData::Public },
	{ "slotFileStatusNotification(const unsigned int,const KURL&,const unsigned int,const unsigned int,const unsigned int)", &slot_25, QMetaData::Public },
	{ "slotAddImageToInputEdit(const QString&)", &slot_26, QMetaData::Public },
	{ "slotSmileySelected(int)", &slot_27, QMetaData::Private },
	{ "slotTbBuddyClick()", &slot_28, QMetaData::Private },
	{ "slotSmileyClick()", &slot_29, QMetaData::Private },
	{ "slotFontClick()", &slot_30, QMetaData::Private },
	{ "slotQuickReplyClick()", &slot_31, QMetaData::Private },
	{ "slotQuickReplyActivated(int)", &slot_32, QMetaData::Private },
	{ "slotHideShowsClick()", &slot_33, QMetaData::Private },
	{ "slotHistoryClick()", &slot_34, QMetaData::Private },
	{ "slotHistoryWindowClosed()", &slot_35, QMetaData::Private },
	{ "slotSendKeyClick()", &slot_36, QMetaData::Private },
	{ "slotSend()", &slot_37, QMetaData::Private },
	{ "slotTbShowBuddyClick()", &slot_38, QMetaData::Private },
	{ "slotTbShowMeClick()", &slot_39, QMetaData::Private },
	{ "slotInputKeyPress(QKeyEvent*)", &slot_40, QMetaData::Private },
	{ "slotFontChanged(QColor,int)", &slot_41, QMetaData::Private },
	{ "setEnterSend()", &slot_42, QMetaData::Private },
	{ "setCtrlEnterSend()", &slot_43, QMetaData::Private },
	{ "slotPbCloseClick()", &slot_44, QMetaData::Private },
	{ "slotFileTransferAcceptClicked(const unsigned int)", &slot_45, QMetaData::Private },
	{ "slotFileTransferSaveAsClicked(const unsigned int)", &slot_46, QMetaData::Private },
	{ "slotFileTransferCancelClicked(const unsigned int)", &slot_47, QMetaData::Private },
	{ "slotFileTransferResume(const unsigned int,const bool)", &slot_48, QMetaData::Private },
	{ "slotFilePanelCloseClicked(const unsigned int)", &slot_49, QMetaData::Private },
	{ "slotAddImageClick()", &slot_50, QMetaData::Private },
	{ "slotScreenShotClick()", &slot_51, QMetaData::Private },
	{ "slotRegionGrabbed(const QPixmap&)", &slot_52, QMetaData::Private },
	{ "slotCustomBtnClick()", &slot_53, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestDetails", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::InOut },
	{ 0, &static_QUType_ptr, "char", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In },
	{ 0, &static_QUType_ptr, "char", QUParameter::In }
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
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "QValueList<QString>", QUParameter::In },
	{ 0, &static_QUType_ptr, "QValueList<unsigned int>", QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_5 = {"fileTransferSend", 5, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_QString, 0, QUParameter::In },
	{ "transferType", &static_QUType_ptr, "unsigned char", QUParameter::In }
    };
    static const QUMethod signal_6 = {"fileTransferAccept", 4, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_7 = {"fileTransferCancel", 2, param_signal_7 };
    static const QUParameter param_signal_8[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod signal_8 = {"fileTransferResume", 3, param_signal_8 };
    static const QMetaData signal_tbl[] = {
	{ "requestDetails(const unsigned int)", &signal_0, QMetaData::Public },
	{ "sendMessage(const unsigned int,const bool,QString&,const char,const bool,const bool,const bool,const char,const char,const char)", &signal_1, QMetaData::Public },
	{ "requestHistory(const unsigned int)", &signal_2, QMetaData::Public },
	{ "requestBuddyQQShow(const unsigned int)", &signal_3, QMetaData::Public },
	{ "requestMyQQShow()", &signal_4, QMetaData::Public },
	{ "fileTransferSend(const unsigned int,const unsigned int,const QValueList<QString>,const QValueList<unsigned int>,const unsigned char)", &signal_5, QMetaData::Public },
	{ "fileTransferAccept(const unsigned int,const unsigned int,const QString,const unsigned char)", &signal_6, QMetaData::Public },
	{ "fileTransferCancel(const unsigned int,const unsigned int)", &signal_7, QMetaData::Public },
	{ "fileTransferResume(const unsigned int,const unsigned int,const bool)", &signal_8, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaChatWindow", parentObject,
	slot_tbl, 54,
	signal_tbl, 9,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaChatWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaChatWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaChatWindow" ) )
	return this;
    return EvaChatUIBase::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestDetails
void EvaChatWindow::requestDetails( const unsigned int t0 )
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
void EvaChatWindow::sendMessage( const unsigned int t0, const bool t1, QString& t2, const char t3, const bool t4, const bool t5, const bool t6, const char t7, const char t8, const char t9 )
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
void EvaChatWindow::requestHistory( const unsigned int t0 )
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
void EvaChatWindow::requestBuddyQQShow( const unsigned int t0 )
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
void EvaChatWindow::requestMyQQShow()
{
    activate_signal( staticMetaObject()->signalOffset() + 4 );
}

// SIGNAL fileTransferSend
void EvaChatWindow::fileTransferSend( const unsigned int t0, const unsigned int t1, const QValueList<QString> t2, const QValueList<unsigned int> t3, const unsigned char t4 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
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
void EvaChatWindow::fileTransferAccept( const unsigned int t0, const unsigned int t1, const QString t2, const unsigned char t3 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
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
void EvaChatWindow::fileTransferCancel( const unsigned int t0, const unsigned int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL fileTransferResume
void EvaChatWindow::fileTransferResume( const unsigned int t0, const unsigned int t1, const bool t2 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 8 );
    if ( !clist )
	return;
    QUObject o[4];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    static_QUType_bool.set(o+3,t2);
    activate_signal( clist, o );
}

bool EvaChatWindow::qt_invoke( int _id, QUObject* _o )
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
    case 9: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7)))); break;
    case 10: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8)))); break;
    case 11: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9)); break;
    case 12: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10)); break;
    case 13: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10),(const bool)static_QUType_bool.get(_o+11)); break;
    case 14: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10),(const bool)static_QUType_bool.get(_o+11),(const char)(*((const char*)static_QUType_ptr.get(_o+12)))); break;
    case 15: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10),(const bool)static_QUType_bool.get(_o+11),(const char)(*((const char*)static_QUType_ptr.get(_o+12))),(const char)(*((const char*)static_QUType_ptr.get(_o+13)))); break;
    case 16: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10),(const bool)static_QUType_bool.get(_o+11),(const char)(*((const char*)static_QUType_ptr.get(_o+12))),(const char)(*((const char*)static_QUType_ptr.get(_o+13))),(const char)(*((const char*)static_QUType_ptr.get(_o+14)))); break;
    case 17: slotSendResult((bool)static_QUType_bool.get(_o+1)); break;
    case 18: slotBuddyQQShowReady((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 19: slotMyQQShowReady(); break;
    case 20: slotFileClick(); break;
    case 21: slotReceivedFileRequest((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const QString&)static_QUType_QString.get(_o+2),(const int)static_QUType_int.get(_o+3),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4)))); break;
    case 22: slotReceivedFileAccepted((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+3)))); break;
    case 23: slotSessionChangedTo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2)))); break;
    case 24: slotFileNotifyNormalInfo((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(EvaFileStatus)(*((EvaFileStatus*)static_QUType_ptr.get(_o+2))),(const QString)static_QUType_QString.get(_o+3),(const QString)static_QUType_QString.get(_o+4),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+5))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+6)))); break;
    case 25: slotFileStatusNotification((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const KURL&)*((const KURL*)static_QUType_ptr.get(_o+2)),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+3))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+4))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+5)))); break;
    case 26: slotAddImageToInputEdit((const QString&)static_QUType_QString.get(_o+1)); break;
    case 27: slotSmileySelected((int)static_QUType_int.get(_o+1)); break;
    case 28: slotTbBuddyClick(); break;
    case 29: slotSmileyClick(); break;
    case 30: slotFontClick(); break;
    case 31: slotQuickReplyClick(); break;
    case 32: slotQuickReplyActivated((int)static_QUType_int.get(_o+1)); break;
    case 33: slotHideShowsClick(); break;
    case 34: slotHistoryClick(); break;
    case 35: slotHistoryWindowClosed(); break;
    case 36: slotSendKeyClick(); break;
    case 37: slotSend(); break;
    case 38: slotTbShowBuddyClick(); break;
    case 39: slotTbShowMeClick(); break;
    case 40: slotInputKeyPress((QKeyEvent*)static_QUType_ptr.get(_o+1)); break;
    case 41: slotFontChanged((QColor)(*((QColor*)static_QUType_ptr.get(_o+1))),(int)static_QUType_int.get(_o+2)); break;
    case 42: setEnterSend(); break;
    case 43: setCtrlEnterSend(); break;
    case 44: slotPbCloseClick(); break;
    case 45: slotFileTransferAcceptClicked((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 46: slotFileTransferSaveAsClicked((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 47: slotFileTransferCancelClicked((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 48: slotFileTransferResume((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2)); break;
    case 49: slotFilePanelCloseClicked((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 50: slotAddImageClick(); break;
    case 51: slotScreenShotClick(); break;
    case 52: slotRegionGrabbed((const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+1))); break;
    case 53: slotCustomBtnClick(); break;
    default:
	return EvaChatUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaChatWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: sendMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const bool)static_QUType_bool.get(_o+2),(QString&)static_QUType_QString.get(_o+3),(const char)(*((const char*)static_QUType_ptr.get(_o+4))),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10)))); break;
    case 2: requestHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: requestBuddyQQShow((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 4: requestMyQQShow(); break;
    case 5: fileTransferSend((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QValueList<QString>)(*((const QValueList<QString>*)static_QUType_ptr.get(_o+3))),(const QValueList<unsigned int>)(*((const QValueList<unsigned int>*)static_QUType_ptr.get(_o+4))),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+5)))); break;
    case 6: fileTransferAccept((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const QString)static_QUType_QString.get(_o+3),(const unsigned char)(*((const unsigned char*)static_QUType_ptr.get(_o+4)))); break;
    case 7: fileTransferCancel((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2)))); break;
    case 8: fileTransferResume((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const bool)static_QUType_bool.get(_o+3)); break;
    default:
	return EvaChatUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaChatWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaChatUIBase::qt_property( id, f, v);
}

bool EvaChatWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
