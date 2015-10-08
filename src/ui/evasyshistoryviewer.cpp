/***************************************************************************
 *   Copyright (C) 2005 by yunfan                                          *
 *   yunfan_zg@163.com                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "evasyshistoryviewer.h"
#include "evadefines.h"

#include <ntqpushbutton.h>
#include <ntqtable.h>
#include <tdelocale.h>
#include <ntqcheckbox.h>
#include <ntqdatetimeedit.h>

EvaSysHistoryViewer::EvaSysHistoryViewer(EvaUserSetting *userSetting)
	: EvaHistoryUIBase(0,0,TQt::WStyle_Customize  | TQt::WStyle_Title | TQt::WStyle_SysMenu | TQt::WStyle_NormalBorder 
				| TQt::WStyle_Tool | TQt::WDestructiveClose), 
	setting(userSetting)
{
	page = 0;
	setCaption(i18n("System Messages"));
	tblDisplay->horizontalHeader()->setLabel( 0, i18n( "From" ) );
	tblDisplay->horizontalHeader()->setLabel( 1, i18n( "Type" ) );
	tblDisplay->horizontalHeader()->setLabel( 2, i18n( "Contents" ) );
	chbSelect->setEnabled(false);
	deFrom->setEnabled(false);
	deTo->setEnabled(false);
	pbShow->setEnabled(false);
	pbPrev->setEnabled(false);
	display();
	
	TQObject::connect( pbPrev, SIGNAL( clicked() ), this, SLOT( slotPbPrevClick() ) );
	TQObject::connect( pbNext, SIGNAL( clicked() ), this, SLOT( slotPbNextClick() ) );
	TQObject::connect(tblDisplay, SIGNAL(doubleClicked( int,int, int, const TQPoint &)), 
					this, SLOT( slotTblDisplayDoubleClick(int)));				
}

EvaSysHistoryViewer::~EvaSysHistoryViewer()
{
}

void EvaSysHistoryViewer::display()
{
	list = setting->getSysMessages(page);

	int numRows = list.size();
	tblDisplay->setNumRows(numRows);
	
	std::list<EvaUserSetting::sysMessage>::iterator iter;
	int i=0;
	TQString strType;
	for(iter = list.begin(); iter!=list.end(); iter++){
		tblDisplay->setText(i,0, TQString::number(iter->from));
		if(iter->messageType == SYSTEM_MESSAGE_NORMAL){
			switch(iter->type){
			case TQQ_MSG_SYS_BEING_ADDED:
			case TQQ_MSG_SYS_BEING_ADDED_EX:
			case TQQ_MSG_SYS_ADDED_BY_CORRECT_ANSWER:
				strType = i18n("added");
				break;
			case TQQ_MSG_SYS_ADD_FRIEND_APPROVED_AND_ADD:
				strType = i18n("approved and added");
				break;
			case TQQ_MSG_SYS_ADD_FRIEND_REQUEST:
			case TQQ_MSG_SYS_ADD_FRIEND_REQUEST_EX:
				strType = i18n("request");
				break;
			case TQQ_MSG_SYS_ADD_FRIEND_APPROVED:
				strType = i18n("approved");
				break;
			case TQQ_MSG_SYS_ADD_FRIEND_REJECTED:
				strType = i18n("rejected");
				break;
			case Q_MSG_SYS_EVA_QQ_NEWS:
				strType = i18n("News");
				tblDisplay->setText(i,0, i18n("Tencent"));
				break;
			default:
				strType = i18n("system");
			}
		}else{
			strType = i18n("Qun") + "(" + TQString::number(iter->to) + ") ";
			switch(iter->messageType){
			case TQQ_RECV_IM_CREATE_QUN:
				strType += i18n("created");
				break;
			case TQQ_RECV_IM_ADDED_TO_QUN:
				strType += i18n("joined");
				break;       
			case TQQ_RECV_IM_DELETED_FROM_QUN:
				strType += i18n("removed");
				break;
			case TQQ_RECV_IM_REQUEST_JOIN_QUN:
				strType += i18n("request");
				break;
			case TQQ_RECV_IM_APPROVE_JOIN_QUN:
				strType += i18n("approved");
				tblDisplay->setText(i,0, TQString::number(iter->commander));
				break;
			case TQQ_RECV_IM_REJECT_JOIN_QUN:
				strType += i18n("rejected");
				tblDisplay->setText(i,0, TQString::number(iter->commander));
				break;
			case TQQ_RECV_IM_SET_QUN_ADMIN:
				if(iter->commander == 0x01)
					strType += i18n("set admin");
				else
					strType += i18n("unset admin");
				break;
			}
		}
		tblDisplay->setText(i,1,strType);
		tblDisplay->setText(i,2, iter->message);
		tblDisplay->adjustRow(i);
		//tblDisplay->adjustRow(numRows-i-1);	
		i++;
	}
		
	tblDisplay->adjustColumn(0);
	tblDisplay->adjustColumn(1);
	tblDisplay->adjustColumn(2);
}

void EvaSysHistoryViewer::slotPbPrevClick()
{
	if(page==0)   return;
	pbNext->setEnabled(true);	
	page--;
	display();
	if(page==0) {
		pbPrev->setEnabled(false);
		pbNext->setEnabled(true);
	}
}

void EvaSysHistoryViewer::slotPbNextClick()
{
	pbPrev->setEnabled(true);
	page++;
	display();
	if(!list.size()){
		pbPrev->setEnabled(true);
		pbNext->setEnabled(false);
	}
}

void EvaSysHistoryViewer::slotTblDisplayDoubleClick(int row)
{
	std::list<EvaUserSetting::sysMessage>::iterator iter;
	int i= 0;	
	for(iter = list.begin(); iter!=list.end(); iter++){
		if(i==row) break;
		i++;
	}
	printf("list.size: %d\n", list.size());
	if(iter == list.end()) return;
	printf("[EvaSysHistoryViewer]im type:%d, id: %d, code len:%d, token len:%d\n",
				iter->messageType, iter->from, iter->codeLen, iter->tokenLen);
	emit historyDoubleClicked(iter->messageType, iter->type, iter->from, iter->to, iter->message,
				iter->internalQunID, iter->commander, iter->code, iter->codeLen,
				iter->token, iter->tokenLen);
	close();
}

