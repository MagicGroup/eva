/****************************************************************************
**
** DCOP Skeleton generated by dcopidl2cpp from evadcopactions.kidl
**
** WARNING! All changes made in this file will be lost!
**
*****************************************************************************/

#include "./evadcopactions.h"

#include <kdatastream.h>
#include <qasciidict.h>


static const int EvaDCOPActionsInterface_fhash = 13;
static const char* const EvaDCOPActionsInterface_ftable[12][3] = {
    { "void", "changeToOnline()", "changeToOnline()" },
    { "void", "changeToOffline()", "changeToOffline()" },
    { "void", "changeToLeave()", "changeToLeave()" },
    { "void", "changeToInvisible()", "changeToInvisible()" },
    { "void", "changeNick(QString)", "changeNick(QString nick)" },
    { "void", "changeSignature(QString)", "changeSignature(QString contents)" },
    { "void", "sendToContact(unsigned int,QString)", "sendToContact(unsigned int id,QString msg)" },
    { "void", "sendToQun(unsigned int,QString)", "sendToQun(unsigned int ext,QString)" },
    { "void", "textReady(unsigned int,QString,bool)", "textReady(unsigned int id,QString text,bool isQun)" },
    { "void", "imageReady(unsigned int,QString,bool)", "imageReady(unsigned int id,QString path,bool isQun)" },
    { "void", "openAddFriendDialog(unsigned int)", "openAddFriendDialog(unsigned int id)" },
    { 0, 0, 0 }
};
static const int EvaDCOPActionsInterface_ftable_hiddens[11] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
};

bool EvaDCOPActionsInterface::process(const QCString &fun, const QByteArray &data, QCString& replyType, QByteArray &replyData)
{
    static QAsciiDict<int>* fdict = 0;
    if ( !fdict ) {
	fdict = new QAsciiDict<int>( EvaDCOPActionsInterface_fhash, true, false );
	for ( int i = 0; EvaDCOPActionsInterface_ftable[i][1]; i++ )
	    fdict->insert( EvaDCOPActionsInterface_ftable[i][1],  new int( i ) );
    }
    int* fp = fdict->find( fun );
    switch ( fp?*fp:-1) {
    case 0: { // void changeToOnline()
	replyType = EvaDCOPActionsInterface_ftable[0][0]; 
	changeToOnline( );
    } break;
    case 1: { // void changeToOffline()
	replyType = EvaDCOPActionsInterface_ftable[1][0]; 
	changeToOffline( );
    } break;
    case 2: { // void changeToLeave()
	replyType = EvaDCOPActionsInterface_ftable[2][0]; 
	changeToLeave( );
    } break;
    case 3: { // void changeToInvisible()
	replyType = EvaDCOPActionsInterface_ftable[3][0]; 
	changeToInvisible( );
    } break;
    case 4: { // void changeNick(QString)
	QString arg0;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	replyType = EvaDCOPActionsInterface_ftable[4][0]; 
	changeNick(arg0 );
    } break;
    case 5: { // void changeSignature(QString)
	QString arg0;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	replyType = EvaDCOPActionsInterface_ftable[5][0]; 
	changeSignature(arg0 );
    } break;
    case 6: { // void sendToContact(unsigned int,QString)
	unsigned int arg0;
	QString arg1;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	if (arg.atEnd()) return false;
	arg >> arg1;
	replyType = EvaDCOPActionsInterface_ftable[6][0]; 
	sendToContact(arg0, arg1 );
    } break;
    case 7: { // void sendToQun(unsigned int,QString)
	unsigned int arg0;
	QString arg1;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	if (arg.atEnd()) return false;
	arg >> arg1;
	replyType = EvaDCOPActionsInterface_ftable[7][0]; 
	sendToQun(arg0, arg1 );
    } break;
    case 8: { // void textReady(unsigned int,QString,bool)
	unsigned int arg0;
	QString arg1;
	bool arg2;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	if (arg.atEnd()) return false;
	arg >> arg1;
	if (arg.atEnd()) return false;
	arg >> arg2;
	replyType = EvaDCOPActionsInterface_ftable[8][0]; 
	textReady(arg0, arg1, arg2 );
    } break;
    case 9: { // void imageReady(unsigned int,QString,bool)
	unsigned int arg0;
	QString arg1;
	bool arg2;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	if (arg.atEnd()) return false;
	arg >> arg1;
	if (arg.atEnd()) return false;
	arg >> arg2;
	replyType = EvaDCOPActionsInterface_ftable[9][0]; 
	imageReady(arg0, arg1, arg2 );
    } break;
    case 10: { // void openAddFriendDialog(unsigned int)
	unsigned int arg0;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	replyType = EvaDCOPActionsInterface_ftable[10][0]; 
	openAddFriendDialog(arg0 );
    } break;
    default: 
	return DCOPObject::process( fun, data, replyType, replyData );
    }
    return true;
}

QCStringList EvaDCOPActionsInterface::interfaces()
{
    QCStringList ifaces = DCOPObject::interfaces();
    ifaces += "EvaDCOPActionsInterface";
    return ifaces;
}

QCStringList EvaDCOPActionsInterface::functions()
{
    QCStringList funcs = DCOPObject::functions();
    for ( int i = 0; EvaDCOPActionsInterface_ftable[i][2]; i++ ) {
	if (EvaDCOPActionsInterface_ftable_hiddens[i])
	    continue;
	QCString func = EvaDCOPActionsInterface_ftable[i][0];
	func += ' ';
	func += EvaDCOPActionsInterface_ftable[i][2];
	funcs << func;
    }
    return funcs;
}


