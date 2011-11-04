/****************************************************************************
** EvaQunChatWindow meta object code from reading C++ file 'evaqunchatwindow.h'
**
** Created: Tue Feb 8 23:52:07 2011
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.8   edited Feb 2 14:59 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "evaqunchatwindow.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.8b. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *EvaQunChatWindow::className() const
{
    return "EvaQunChatWindow";
}

QMetaObject *EvaQunChatWindow::metaObj = 0;
static QMetaObjectCleanUp cleanUp_EvaQunChatWindow( "EvaQunChatWindow", &EvaQunChatWindow::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString EvaQunChatWindow::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunChatWindow", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString EvaQunChatWindow::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "EvaQunChatWindow", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* EvaQunChatWindow::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = EvaQunChatUIBase::staticMetaObject();
    static const QUMethod slot_0 = {"graphicChanged", 0, 0 };
    static const QUParameter param_slot_1[] = {
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
    static const QUMethod slot_1 = {"slotReceivedMessage", 11, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In }
    };
    static const QUMethod slot_2 = {"slotAddMessage", 7, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "sender", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "sNick", &static_QUType_QString, 0, QUParameter::In },
	{ "receiver", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "rNick", &static_QUType_QString, 0, QUParameter::In },
	{ "isNormal", &static_QUType_bool, 0, QUParameter::In },
	{ "message", &static_QUType_QString, 0, QUParameter::In },
	{ "time", &static_QUType_varptr, "\x1c", QUParameter::In },
	{ "size", &static_QUType_ptr, "char", QUParameter::In }
    };
    static const QUMethod slot_3 = {"slotAddMessage", 8, param_slot_3 };
    static const QUParameter param_slot_4[] = {
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
    static const QUMethod slot_4 = {"slotAddMessage", 9, param_slot_4 };
    static const QUParameter param_slot_5[] = {
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
    static const QUMethod slot_5 = {"slotAddMessage", 10, param_slot_5 };
    static const QUParameter param_slot_6[] = {
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
    static const QUMethod slot_6 = {"slotAddMessage", 11, param_slot_6 };
    static const QUParameter param_slot_7[] = {
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
    static const QUMethod slot_7 = {"slotAddMessage", 12, param_slot_7 };
    static const QUParameter param_slot_8[] = {
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
    static const QUMethod slot_8 = {"slotAddMessage", 13, param_slot_8 };
    static const QUParameter param_slot_9[] = {
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
    static const QUMethod slot_9 = {"slotAddMessage", 14, param_slot_9 };
    static const QUParameter param_slot_10[] = {
	{ "info", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_10 = {"slotAddInformation", 1, param_slot_10 };
    static const QUParameter param_slot_11[] = {
	{ "ok", &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_11 = {"slotSendResult", 1, param_slot_11 };
    static const QUMethod slot_12 = {"slotDisplayMembers", 0, 0 };
    static const QUMethod slot_13 = {"slotUpdateOnlineMembers", 0, 0 };
    static const QUParameter param_slot_14[] = {
	{ "filename", &static_QUType_QString, 0, QUParameter::In },
	{ "tmpFileName", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_14 = {"slotPictureReady", 2, param_slot_14 };
    static const QUParameter param_slot_15[] = {
	{ "message", &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_15 = {"sendImageError", 1, param_slot_15 };
    static const QUParameter param_slot_16[] = {
	{ "sessionID", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "ip", &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ "port", &static_QUType_ptr, "unsigned short", QUParameter::In }
    };
    static const QUMethod slot_16 = {"slotSendImageDone", 3, param_slot_16 };
    static const QUParameter param_slot_17[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_17 = {"slotAddImageToInputEdit", 1, param_slot_17 };
    static const QUParameter param_slot_18[] = {
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_18 = {"slotSmileySelected", 1, param_slot_18 };
    static const QUMethod slot_19 = {"slotManageCustomSmileys", 0, 0 };
    static const QUMethod slot_20 = {"slotTbQunDetailsClick", 0, 0 };
    static const QUMethod slot_21 = {"slotSmileyClick", 0, 0 };
    static const QUMethod slot_22 = {"slotFontClick", 0, 0 };
    static const QUMethod slot_23 = {"slotImageFileClick", 0, 0 };
    static const QUMethod slot_24 = {"slotScreenShotClick", 0, 0 };
    static const QUMethod slot_25 = {"slotQuickReplyClick", 0, 0 };
    static const QUParameter param_slot_26[] = {
	{ "id", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_26 = {"slotQuickReplyActivated", 1, param_slot_26 };
    static const QUMethod slot_27 = {"slotHistoryClick", 0, 0 };
    static const QUMethod slot_28 = {"slotHistoryWindowClosed", 0, 0 };
    static const QUMethod slot_29 = {"slotSendKeyClick", 0, 0 };
    static const QUMethod slot_30 = {"slotSend", 0, 0 };
    static const QUMethod slot_31 = {"slotNoticeClick", 0, 0 };
    static const QUParameter param_slot_32[] = {
	{ "e", &static_QUType_ptr, "QKeyEvent", QUParameter::In }
    };
    static const QUMethod slot_32 = {"slotInputKeyPress", 1, param_slot_32 };
    static const QUParameter param_slot_33[] = {
	{ 0, &static_QUType_varptr, "\x0a", QUParameter::In },
	{ 0, &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_33 = {"slotFontChanged", 2, param_slot_33 };
    static const QUMethod slot_34 = {"setEnterSend", 0, 0 };
    static const QUMethod slot_35 = {"setCtrlEnterSend", 0, 0 };
    static const QUMethod slot_36 = {"slotPbCloseClick", 0, 0 };
    static const QUMethod slot_37 = {"slotTimeout", 0, 0 };
    static const QUMethod slot_38 = {"slotRequestQunMembers", 0, 0 };
    static const QUParameter param_slot_39[] = {
	{ 0, &static_QUType_varptr, "\x06", QUParameter::In }
    };
    static const QUMethod slot_39 = {"slotRegionGrabbed", 1, param_slot_39 };
    static const QUParameter param_slot_40[] = {
	{ "id", &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_40 = {"slotRequestQunCard", 1, param_slot_40 };
    static const QUMethod slot_41 = {"slotRequestQunRealNames", 0, 0 };
    static const QUParameter param_slot_42[] = {
	{ 0, &static_QUType_QString, 0, QUParameter::In }
    };
    static const QUMethod slot_42 = {"slotSaveAsCustomSmiley", 1, param_slot_42 };
    static const QUParameter param_slot_43[] = {
	{ 0, &static_QUType_bool, 0, QUParameter::In }
    };
    static const QUMethod slot_43 = {"slotAddCustomSmileyReady", 1, param_slot_43 };
    static const QUMethod slot_44 = {"slotCustomSmileyChanged", 0, 0 };
    static const QUMethod slot_45 = {"slotCustomBtnClick", 0, 0 };
    static const QUParameter param_slot_46[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod slot_46 = {"slotRequestChat", 1, param_slot_46 };
    static const QMetaData slot_tbl[] = {
	{ "graphicChanged()", &slot_0, QMetaData::Public },
	{ "slotReceivedMessage(unsigned int,unsigned int,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &slot_1, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime)", &slot_2, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char)", &slot_3, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool)", &slot_4, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool)", &slot_5, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool,const bool)", &slot_6, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char)", &slot_7, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char)", &slot_8, QMetaData::Public },
	{ "slotAddMessage(unsigned int,QString,unsigned int,QString,bool,QString,QDateTime,const char,const bool,const bool,const bool,const char,const char,const char)", &slot_9, QMetaData::Public },
	{ "slotAddInformation(const QString&)", &slot_10, QMetaData::Public },
	{ "slotSendResult(bool)", &slot_11, QMetaData::Public },
	{ "slotDisplayMembers()", &slot_12, QMetaData::Public },
	{ "slotUpdateOnlineMembers()", &slot_13, QMetaData::Public },
	{ "slotPictureReady(const QString,const QString)", &slot_14, QMetaData::Public },
	{ "sendImageError(const QString)", &slot_15, QMetaData::Public },
	{ "slotSendImageDone(const unsigned int,const unsigned int,const unsigned short)", &slot_16, QMetaData::Public },
	{ "slotAddImageToInputEdit(const QString&)", &slot_17, QMetaData::Public },
	{ "slotSmileySelected(int)", &slot_18, QMetaData::Private },
	{ "slotManageCustomSmileys()", &slot_19, QMetaData::Private },
	{ "slotTbQunDetailsClick()", &slot_20, QMetaData::Private },
	{ "slotSmileyClick()", &slot_21, QMetaData::Private },
	{ "slotFontClick()", &slot_22, QMetaData::Private },
	{ "slotImageFileClick()", &slot_23, QMetaData::Private },
	{ "slotScreenShotClick()", &slot_24, QMetaData::Private },
	{ "slotQuickReplyClick()", &slot_25, QMetaData::Private },
	{ "slotQuickReplyActivated(int)", &slot_26, QMetaData::Private },
	{ "slotHistoryClick()", &slot_27, QMetaData::Private },
	{ "slotHistoryWindowClosed()", &slot_28, QMetaData::Private },
	{ "slotSendKeyClick()", &slot_29, QMetaData::Private },
	{ "slotSend()", &slot_30, QMetaData::Private },
	{ "slotNoticeClick()", &slot_31, QMetaData::Private },
	{ "slotInputKeyPress(QKeyEvent*)", &slot_32, QMetaData::Private },
	{ "slotFontChanged(QColor,int)", &slot_33, QMetaData::Private },
	{ "setEnterSend()", &slot_34, QMetaData::Private },
	{ "setCtrlEnterSend()", &slot_35, QMetaData::Private },
	{ "slotPbCloseClick()", &slot_36, QMetaData::Private },
	{ "slotTimeout()", &slot_37, QMetaData::Private },
	{ "slotRequestQunMembers()", &slot_38, QMetaData::Private },
	{ "slotRegionGrabbed(const QPixmap&)", &slot_39, QMetaData::Private },
	{ "slotRequestQunCard(const unsigned int)", &slot_40, QMetaData::Private },
	{ "slotRequestQunRealNames()", &slot_41, QMetaData::Private },
	{ "slotSaveAsCustomSmiley(QString)", &slot_42, QMetaData::Private },
	{ "slotAddCustomSmileyReady(bool)", &slot_43, QMetaData::Private },
	{ "slotCustomSmileyChanged()", &slot_44, QMetaData::Private },
	{ "slotCustomBtnClick()", &slot_45, QMetaData::Private },
	{ "slotRequestChat(const unsigned int)", &slot_46, QMetaData::Private }
    };
    static const QUParameter param_signal_0[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_0 = {"requestQunDetails", 1, param_signal_0 };
    static const QUParameter param_signal_1[] = {
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
    static const QUMethod signal_1 = {"sendQunMessage", 9, param_signal_1 };
    static const QUParameter param_signal_2[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_2 = {"requestHistory", 1, param_signal_2 };
    static const QUParameter param_signal_3[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_3 = {"requestQunOnlineList", 1, param_signal_3 };
    static const QUParameter param_signal_4[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_4 = {"requestDetails", 1, param_signal_4 };
    static const QUParameter param_signal_5[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In },
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_5 = {"requestQunCard", 2, param_signal_5 };
    static const QUParameter param_signal_6[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_6 = {"requestQunRealNames", 1, param_signal_6 };
    static const QUParameter param_signal_7[] = {
	{ 0, &static_QUType_ptr, "unsigned int", QUParameter::In }
    };
    static const QUMethod signal_7 = {"reqeustChat", 1, param_signal_7 };
    static const QMetaData signal_tbl[] = {
	{ "requestQunDetails(const unsigned int)", &signal_0, QMetaData::Public },
	{ "sendQunMessage(const unsigned int,QString&,const char,const bool,const bool,const bool,const char,const char,const char)", &signal_1, QMetaData::Public },
	{ "requestHistory(const unsigned int)", &signal_2, QMetaData::Public },
	{ "requestQunOnlineList(const unsigned int)", &signal_3, QMetaData::Public },
	{ "requestDetails(const unsigned int)", &signal_4, QMetaData::Public },
	{ "requestQunCard(const unsigned int,const unsigned int)", &signal_5, QMetaData::Public },
	{ "requestQunRealNames(const unsigned int)", &signal_6, QMetaData::Public },
	{ "reqeustChat(const unsigned int)", &signal_7, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"EvaQunChatWindow", parentObject,
	slot_tbl, 47,
	signal_tbl, 8,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_EvaQunChatWindow.setMetaObject( metaObj );
    return metaObj;
}

void* EvaQunChatWindow::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "EvaQunChatWindow" ) )
	return this;
    return EvaQunChatUIBase::qt_cast( clname );
}

#include <qobjectdefs.h>
#include <qsignalslotimp.h>

// SIGNAL requestQunDetails
void EvaQunChatWindow::requestQunDetails( const unsigned int t0 )
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

// SIGNAL sendQunMessage
void EvaQunChatWindow::sendQunMessage( const unsigned int t0, QString& t1, const char t2, const bool t3, const bool t4, const bool t5, const char t6, const char t7, const char t8 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 1 );
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

// SIGNAL requestHistory
void EvaQunChatWindow::requestHistory( const unsigned int t0 )
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

// SIGNAL requestQunOnlineList
void EvaQunChatWindow::requestQunOnlineList( const unsigned int t0 )
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

// SIGNAL requestDetails
void EvaQunChatWindow::requestDetails( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 4 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL requestQunCard
void EvaQunChatWindow::requestQunCard( const unsigned int t0, const unsigned int t1 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 5 );
    if ( !clist )
	return;
    QUObject o[3];
    static_QUType_ptr.set(o+1,&t0);
    static_QUType_ptr.set(o+2,&t1);
    activate_signal( clist, o );
}

// SIGNAL requestQunRealNames
void EvaQunChatWindow::requestQunRealNames( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 6 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

// SIGNAL reqeustChat
void EvaQunChatWindow::reqeustChat( const unsigned int t0 )
{
    if ( signalsBlocked() )
	return;
    QConnectionList *clist = receivers( staticMetaObject()->signalOffset() + 7 );
    if ( !clist )
	return;
    QUObject o[2];
    static_QUType_ptr.set(o+1,&t0);
    activate_signal( clist, o );
}

bool EvaQunChatWindow::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: graphicChanged(); break;
    case 1: slotReceivedMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+2))),(QString)static_QUType_QString.get(_o+3),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+4))),(const char)(*((const char*)static_QUType_ptr.get(_o+5))),(const bool)static_QUType_bool.get(_o+6),(const bool)static_QUType_bool.get(_o+7),(const bool)static_QUType_bool.get(_o+8),(const char)(*((const char*)static_QUType_ptr.get(_o+9))),(const char)(*((const char*)static_QUType_ptr.get(_o+10))),(const char)(*((const char*)static_QUType_ptr.get(_o+11)))); break;
    case 2: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7)))); break;
    case 3: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8)))); break;
    case 4: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9)); break;
    case 5: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10)); break;
    case 6: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10),(const bool)static_QUType_bool.get(_o+11)); break;
    case 7: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10),(const bool)static_QUType_bool.get(_o+11),(const char)(*((const char*)static_QUType_ptr.get(_o+12)))); break;
    case 8: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10),(const bool)static_QUType_bool.get(_o+11),(const char)(*((const char*)static_QUType_ptr.get(_o+12))),(const char)(*((const char*)static_QUType_ptr.get(_o+13)))); break;
    case 9: slotAddMessage((unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+1))),(QString)static_QUType_QString.get(_o+2),(unsigned int)(*((unsigned int*)static_QUType_ptr.get(_o+3))),(QString)static_QUType_QString.get(_o+4),(bool)static_QUType_bool.get(_o+5),(QString)static_QUType_QString.get(_o+6),(QDateTime)(*((QDateTime*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const bool)static_QUType_bool.get(_o+9),(const bool)static_QUType_bool.get(_o+10),(const bool)static_QUType_bool.get(_o+11),(const char)(*((const char*)static_QUType_ptr.get(_o+12))),(const char)(*((const char*)static_QUType_ptr.get(_o+13))),(const char)(*((const char*)static_QUType_ptr.get(_o+14)))); break;
    case 10: slotAddInformation((const QString&)static_QUType_QString.get(_o+1)); break;
    case 11: slotSendResult((bool)static_QUType_bool.get(_o+1)); break;
    case 12: slotDisplayMembers(); break;
    case 13: slotUpdateOnlineMembers(); break;
    case 14: slotPictureReady((const QString)static_QUType_QString.get(_o+1),(const QString)static_QUType_QString.get(_o+2)); break;
    case 15: sendImageError((const QString)static_QUType_QString.get(_o+1)); break;
    case 16: slotSendImageDone((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2))),(const unsigned short)(*((const unsigned short*)static_QUType_ptr.get(_o+3)))); break;
    case 17: slotAddImageToInputEdit((const QString&)static_QUType_QString.get(_o+1)); break;
    case 18: slotSmileySelected((int)static_QUType_int.get(_o+1)); break;
    case 19: slotManageCustomSmileys(); break;
    case 20: slotTbQunDetailsClick(); break;
    case 21: slotSmileyClick(); break;
    case 22: slotFontClick(); break;
    case 23: slotImageFileClick(); break;
    case 24: slotScreenShotClick(); break;
    case 25: slotQuickReplyClick(); break;
    case 26: slotQuickReplyActivated((int)static_QUType_int.get(_o+1)); break;
    case 27: slotHistoryClick(); break;
    case 28: slotHistoryWindowClosed(); break;
    case 29: slotSendKeyClick(); break;
    case 30: slotSend(); break;
    case 31: slotNoticeClick(); break;
    case 32: slotInputKeyPress((QKeyEvent*)static_QUType_ptr.get(_o+1)); break;
    case 33: slotFontChanged((QColor)(*((QColor*)static_QUType_ptr.get(_o+1))),(int)static_QUType_int.get(_o+2)); break;
    case 34: setEnterSend(); break;
    case 35: setCtrlEnterSend(); break;
    case 36: slotPbCloseClick(); break;
    case 37: slotTimeout(); break;
    case 38: slotRequestQunMembers(); break;
    case 39: slotRegionGrabbed((const QPixmap&)*((const QPixmap*)static_QUType_ptr.get(_o+1))); break;
    case 40: slotRequestQunCard((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 41: slotRequestQunRealNames(); break;
    case 42: slotSaveAsCustomSmiley((QString)static_QUType_QString.get(_o+1)); break;
    case 43: slotAddCustomSmileyReady((bool)static_QUType_bool.get(_o+1)); break;
    case 44: slotCustomSmileyChanged(); break;
    case 45: slotCustomBtnClick(); break;
    case 46: slotRequestChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaQunChatUIBase::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool EvaQunChatWindow::qt_emit( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->signalOffset() ) {
    case 0: requestQunDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 1: sendQunMessage((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(QString&)static_QUType_QString.get(_o+2),(const char)(*((const char*)static_QUType_ptr.get(_o+3))),(const bool)static_QUType_bool.get(_o+4),(const bool)static_QUType_bool.get(_o+5),(const bool)static_QUType_bool.get(_o+6),(const char)(*((const char*)static_QUType_ptr.get(_o+7))),(const char)(*((const char*)static_QUType_ptr.get(_o+8))),(const char)(*((const char*)static_QUType_ptr.get(_o+9)))); break;
    case 2: requestHistory((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 3: requestQunOnlineList((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 4: requestDetails((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 5: requestQunCard((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1))),(const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+2)))); break;
    case 6: requestQunRealNames((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    case 7: reqeustChat((const unsigned int)(*((const unsigned int*)static_QUType_ptr.get(_o+1)))); break;
    default:
	return EvaQunChatUIBase::qt_emit(_id,_o);
    }
    return TRUE;
}
#ifndef QT_NO_PROPERTIES

bool EvaQunChatWindow::qt_property( int id, int f, QVariant* v)
{
    return EvaQunChatUIBase::qt_property( id, f, v);
}

bool EvaQunChatWindow::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
