/****************************************************************************
**
** DCOP Skeleton generated by dcopidl2cpp from evadcoptools.kidl
**
** WARNING! All changes made in this file will be lost!
**
*****************************************************************************/

#include "./evadcoptools.h"

#include <kdatastream.h>


static const char* const EvaDCOPToolsInterface_ftable[6][3] = {
    { "bool", "stopScript(QString)", "stopScript(QString name)" },
    { "bool", "runScript(QString,bool)", "runScript(QString name,bool silent)" },
    { "QString", "scriptDir(bool)", "scriptDir(bool isSystem)" },
    { "int", "numScripts()", "numScripts()" },
    { "int", "numRunningScripts()", "numRunningScripts()" },
    { 0, 0, 0 }
};
static const int EvaDCOPToolsInterface_ftable_hiddens[5] = {
    0,
    0,
    0,
    0,
    0,
};

bool EvaDCOPToolsInterface::process(const QCString &fun, const QByteArray &data, QCString& replyType, QByteArray &replyData)
{
    if ( fun == EvaDCOPToolsInterface_ftable[0][1] ) { // bool stopScript(QString)
	QString arg0;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	replyType = EvaDCOPToolsInterface_ftable[0][0]; 
	QDataStream _replyStream( replyData, IO_WriteOnly );
	_replyStream << stopScript(arg0 );
    } else if ( fun == EvaDCOPToolsInterface_ftable[1][1] ) { // bool runScript(QString,bool)
	QString arg0;
	bool arg1;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	if (arg.atEnd()) return false;
	arg >> arg1;
	replyType = EvaDCOPToolsInterface_ftable[1][0]; 
	QDataStream _replyStream( replyData, IO_WriteOnly );
	_replyStream << runScript(arg0, arg1 );
    } else if ( fun == EvaDCOPToolsInterface_ftable[2][1] ) { // QString scriptDir(bool)
	bool arg0;
	QDataStream arg( data, IO_ReadOnly );
	if (arg.atEnd()) return false;
	arg >> arg0;
	replyType = EvaDCOPToolsInterface_ftable[2][0]; 
	QDataStream _replyStream( replyData, IO_WriteOnly );
	_replyStream << scriptDir(arg0 );
    } else if ( fun == EvaDCOPToolsInterface_ftable[3][1] ) { // int numScripts()
	replyType = EvaDCOPToolsInterface_ftable[3][0]; 
	QDataStream _replyStream( replyData, IO_WriteOnly );
	_replyStream << numScripts( );
    } else if ( fun == EvaDCOPToolsInterface_ftable[4][1] ) { // int numRunningScripts()
	replyType = EvaDCOPToolsInterface_ftable[4][0]; 
	QDataStream _replyStream( replyData, IO_WriteOnly );
	_replyStream << numRunningScripts( );
    } else {
	return DCOPObject::process( fun, data, replyType, replyData );
    }
    return true;
}

QCStringList EvaDCOPToolsInterface::interfaces()
{
    QCStringList ifaces = DCOPObject::interfaces();
    ifaces += "EvaDCOPToolsInterface";
    return ifaces;
}

QCStringList EvaDCOPToolsInterface::functions()
{
    QCStringList funcs = DCOPObject::functions();
    for ( int i = 0; EvaDCOPToolsInterface_ftable[i][2]; i++ ) {
	if (EvaDCOPToolsInterface_ftable_hiddens[i])
	    continue;
	QCString func = EvaDCOPToolsInterface_ftable[i][0];
	func += ' ';
	func += EvaDCOPToolsInterface_ftable[i][2];
	funcs << func;
    }
    return funcs;
}

