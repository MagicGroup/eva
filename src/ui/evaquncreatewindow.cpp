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

#include "evaquncreatewindow.h"

#include <stdlib.h>
#include <ntqlineedit.h>
#include <ntqtextedit.h>
#include <ntqcombobox.h>
#include <ntqpushbutton.h>
#include <ntqradiobutton.h>
//#include <ntqiconset.h>
#include <ntqpixmap.h>
#include <ntqlabel.h>
#include <ntqwidgetstack.h>
#include <ntqbuttongroup.h>
#include <ntqtable.h>
#include <ntqimage.h>
#include <tdemessagebox.h>
#include <ntqtextcodec.h>
#include <ntqevent.h>
#include <ntqpoint.h>
#include <ntqtoolbutton.h>
#include "../evamain.h"
#include "evaresource.h"
#include "evauser.h"
#include "evaqunmemberpicker.h"
#include "quncategorypicker.h"
#include <tdeapplication.h>
#include <tdelocale.h>

EvaQunCreateWindow::EvaQunCreateWindow( TQWidget * parent, const char * name, WFlags fl )
	: QunCreateUI(parent,name,fl), picker(NULL), qunCategory(0), qunNotice(""), qunDescription("")
{
	codec = TQTextCodec::codecForName("GB18030");
	initTable( );
	slotLoadMembers();
	pbPrev->setEnabled(false);
	TQObject::connect(pbCancel, SIGNAL(clicked()), SLOT(slotCancel()));
	TQObject::connect(pbPrev, SIGNAL(clicked()), SLOT(slotPrevClicked()));
	TQObject::connect(pbNext, SIGNAL(clicked()), SLOT(slotNextClicked()));
	TQObject::connect(tbCategory, SIGNAL(clicked()), SLOT(slotCategoryClicked()));
	
	picker = new EvaQunMemberPicker(0, "memberpicker", WStyle_Customize | WStyle_NoBorder | 
								WStyle_StaysOnTop |  WStyle_Tool| WX11BypassWM);
	picker->resize(TQSize(240,frameGeometry().height()));
	TQObject::connect(picker, SIGNAL(memberClicked(const unsigned int, const bool)), 
				SLOT(slotPickerMemberClicked(const unsigned int, const bool)));
	TQObject::connect(this, SIGNAL(removeMember(const unsigned int)), picker, SLOT(slotSetMemberOff(const unsigned int)));
	
	TQRect scr = TDEApplication::desktop()->screenGeometry();
	move(scr.center() - rect().center());
}

void EvaQunCreateWindow::slotQunCreateDone(const unsigned int id)
{
	KMessageBox::information(this, TQString(i18n("Qun \"%1\" has been created.")).arg(id), i18n("Qun Operation"));
	pbNext->setEnabled(false);
	pbCancel->setText(i18n("&Close"));
}

void EvaQunCreateWindow::slotQunCreateFailed(TQString msg)
{
	KMessageBox::information(this, msg, i18n("Qun Operation"));
}

void EvaQunCreateWindow::closeEvent( TQCloseEvent * event)
{
	if(picker)
		delete picker;
	picker=NULL;
 	QunCreateUI::closeEvent(event);
	deleteLater();
}

void EvaQunCreateWindow::moveEvent( TQMoveEvent * event )
{
	if(picker)
		picker->move(x() + frameGeometry().width(), y());
	QunCreateUI::moveEvent(event);
}

void EvaQunCreateWindow::initTable()
{
	TQHeader *vheader = tblMembers->verticalHeader();
	vheader->hide();
	tblMembers->setLeftMargin(0);
	tblMembers->setNumRows( 0 );
	tblMembers->setNumCols( 4 );
	tblMembers->setColumnWidth(0, 16);
	tblMembers->setColumnWidth(1, 90);
	tblMembers->setColumnWidth(2, 110);
	tblMembers->setColumnWidth(3, 34);
	tblMembers->horizontalHeader()->setLabel( 0, i18n( " " ) );
	tblMembers->horizontalHeader()->setLabel( 1, i18n( "QQ" ) );
	tblMembers->horizontalHeader()->setLabel( 2, i18n( "Nick" ) );
	tblMembers->horizontalHeader()->setLabel( 3, i18n( "Gender" ) );
	tblMembers->setSelectionMode( TQTable::SingleRow );
	tblMembers->setFocusStyle( TQTable::FollowStyle );
	tblMembers->setReadOnly( true );
	TQObject::connect(tblMembers, SIGNAL(clicked(int,int,int,const TQPoint&)), SLOT(slotTableClicked(int,int,int,const TQPoint&)));
	
	pbSetMembers->setEnabled(true);
	
	pbDelMembers->setEnabled(false);
	
	TQObject::connect(pbSetMembers, SIGNAL(clicked()), SLOT(slotSetMembersClicked()));
	TQObject::connect(pbDelMembers, SIGNAL(clicked()), SLOT(slotDelMembersClicked()));
}

void EvaQunCreateWindow::slotPrevClicked()
{
	if(wsMain->id(wsMain->visibleWidget()) == 1){
		wsMain->raiseWidget(0);
		pbPrev->setEnabled(false);
		pbNext->setEnabled(true);
		pbNext->setText(i18n("&Next"));
		lblTip->setText(i18n("Please input Qun details below, then click \"Next\""));
	}
}

void EvaQunCreateWindow::slotNextClicked( )
{
	if(wsMain->id(wsMain->visibleWidget()) == 0){
		if(processQunDetailsChecking()){
			wsMain->raiseWidget(1);
			pbPrev->setEnabled(true);
			pbNext->setText(i18n("&Create"));
			lblTip->setText(i18n("Please select your Qun members, then click \"Create\" to finish."));
		}
	}else{
		if(processQunMemberChecking()){
			pbPrev->setEnabled(false);
			pbNext->setEnabled(false);
			lblTip->setText(i18n("Waiting for reply from server."));
			doSendCreateRequest();
		}
	}
}

void EvaQunCreateWindow::slotCancel( )
{
	close();
}

void EvaQunCreateWindow::slotLoadMembers( )
{
	for(int row=0; row<tblMembers->numRows(); row++){
		for(int col=0; col<tblMembers->numCols(); col++){
			tblMembers->clearCell(row, col);
		}
	}
	
	TQString nick = codec->toUnicode(EvaMain::user->getDetails().at(ContactInfo::Info_nick).c_str());
	int face = atoi(EvaMain::user->getDetails().at(ContactInfo::Info_face).c_str());
	int id = EvaMain::user->getQQ();
	
	tblMembers->setNumRows(1);
		
	tblMembers->setPixmap(0,0, *(EvaMain::images->getIcon("TQUN_CREATOR")));
	
	TQPixmap *bmpFace = EvaMain::images->getFace(EvaMain::images->getFaceFileIndex(face));
	
	if(bmpFace){
		TQImage img(bmpFace->convertToImage().smoothScale(16, 16));
		tblMembers->setPixmap(0, 1, TQPixmap(img));
	}
	tblMembers->setText(0,1,TQString::number(id));
	tblMembers->setText(0,2,nick);
	tblMembers->setText(0,3, i18n("-"));
}

void EvaQunCreateWindow::slotTableClicked( int row, int /*col*/, int /*button*/, const TQPoint &/* mousePos*/ )
{
	TQString num = tblMembers->text(row, 1);
	bool ok;
	int id = num.toInt(&ok);
	
	int myID = EvaMain::user->getQQ();
	if(ok){
		if(myID == id)
			pbDelMembers->setEnabled(false);
		else
			pbDelMembers->setEnabled(true);
		
	} else {
		pbDelMembers->setEnabled(false);
	}
}

void EvaQunCreateWindow::slotSetMembersClicked( )
{
	if(picker->isVisible()){
		pbSetMembers->setText(i18n("&Members >>"));
		picker->hide();
	}else{
		pbSetMembers->setText(i18n("&Members <<"));
		picker->move(x() + frameGeometry().width(), y());
		picker->show();
	}
}

void EvaQunCreateWindow::slotDelMembersClicked( )
{
	int row = tblMembers->currentRow();
	TQString txt = tblMembers->text(row, 1);
	bool ok;
	unsigned int id = txt.toUInt(&ok);
	if(!ok) return;
	
	if(id == EvaMain::user->getQQ()) return;
	
	tblMembers->removeRow(row);
	tblMembers->selectRow(0);
	slotTableClicked(0, 1, 0, TQPoint(0,0));
	emit removeMember(id);
}

void EvaQunCreateWindow::slotCategoryClicked( )
{
	QunCategoryPicker *picker = new QunCategoryPicker(this, "categoryPicker",WStyle_Customize | WStyle_Dialog |
										 WStyle_DialogBorder|WDestructiveClose);
	TQObject::connect(picker, SIGNAL(selectCategoryCode(const unsigned short )), SLOT(slotCategorySelected(const unsigned short )));
	picker->show();
}

void EvaQunCreateWindow::slotCategorySelected( const unsigned short code)
{
	qunCategory = code;
	QunCategory qunCate;
	TQString cateDescription = qunCate.getDescription(qunCategory);
	tbCategory->setText(cateDescription);
}

void EvaQunCreateWindow::slotPickerMemberClicked( const unsigned int id, const bool isChecked )
{
	int row;
	if(isChecked){
		short face;
		TQString nick;
		
		row = tblMembers->numRows(); // note: the index is start from 0
		tblMembers->setNumRows(tblMembers->numRows() + 1);
		
		const TQQFriend * frd = (EvaMain::user->getFriendList()).getFriend(id);
		
		face = frd->getFace();
		nick = codec->toUnicode(frd->getNick().c_str());
		
		TQPixmap *bmpFace = EvaMain::images->getFace(EvaMain::images->getFaceFileIndex(face));
		
		if(bmpFace){
			TQImage img(bmpFace->convertToImage().smoothScale(16, 16));
			tblMembers->setPixmap(row, 1, TQPixmap(img));
		}
		tblMembers->setText(row,1,TQString::number(id));
		tblMembers->setText(row,2,nick);
		tblMembers->setText(row,3, frd->isBoy()?i18n("Male"):i18n("Female"));
	}else {
		bool ok;
		TQString txt;
		unsigned int qq;
		for(row = 0; row < tblMembers->numRows(); row ++){
			txt = tblMembers->text(row, 1);
			qq = txt.toUInt(&ok);
			if(!ok) continue;
			if(qq == id){
				tblMembers->removeRow(row);
				return;
			}
		}
	}
}

bool EvaQunCreateWindow::processQunDetailsChecking( )
{
	qunName = leQunName->text().stripWhiteSpace();
	if(qunName.isEmpty()){
		KMessageBox::information(this, i18n("Please input Qun name properly."), i18n("Qun Operation"));
		leQunName->setFocus();
		return false;
	}
	
	if(!qunCategory){
		KMessageBox::information(this, i18n("Please select a Qun category."), i18n("Qun Operation"));
		tbCategory->setFocus();
		return false;
	}
	
	qunNotice = teNotice->text();
	qunDescription = teDescription->text();
	
	qunAuth = 0x02; // we set the defauls as NeedAuthen anyway
	
	if(rbNoAuthenNeed->isChecked())
		qunAuth = 0x01;
	else if(rbNeedAuthen->isChecked())
		qunAuth = 0x02;
	else if(rbRejectAnyone->isChecked())
		qunAuth = 0x03;
	
	return true;
}

bool EvaQunCreateWindow::processQunMemberChecking( )
{
	// nothing to check at the moment
	return true;
}

void EvaQunCreateWindow::doSendCreateRequest( )
{
	bool ok;
	TQString txt;
	int qq;
	std::list<unsigned int> members;
	for(int row = 0; row < tblMembers->numRows(); row ++){
		txt = tblMembers->text(row, 1);
		qq = txt.toInt(&ok);
		if(!ok) return;
		members.push_back(qq);printf("member: %d\n", qq);
	}
	
	emit doQunCreate(qunName, qunCategory, qunAuth, qunNotice, qunDescription, members);
}


