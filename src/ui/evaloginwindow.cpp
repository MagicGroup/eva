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
#include "evaloginwindow.h"

#include "evasetting.h"
#include "evautil.h"
#include "qmdcodec.h"

#include <cstring>
#include <ntqpixmap.h>
#include <ntqlineedit.h>
#include <ntqcombobox.h>
#include <ntqpushbutton.h>
#include <ntqtoolbutton.h>
#include <ntqcheckbox.h>
#include <ntqmessagebox.h>
#include <ntqlabel.h>
#include <ntqhostaddress.h>
#include <tdelocale.h>

EvaLoginWindow::EvaLoginWindow(TQWidget* parent, const char* name, bool modal, WFlags fl)
    : LoginUIBase(parent,name, modal,fl), qqNum(0), port(0)
{
	TQObject::connect(tbNetSetup,SIGNAL(toggled(bool)),SLOT(showNetSetup(bool)));
	TQObject::connect(cbQQ,SIGNAL(activated(int)),SLOT(slotSelectChanged(int)));
	TQObject::connect(lePwd,SIGNAL(textChanged(const TQString &)),SLOT(slotPasswordChanged(const TQString &)));
	TQObject::connect(cbbLoginType,SIGNAL(activated(int)),SLOT(slotLoginTypeChanged(int)));
	TQObject::connect(leUserName,SIGNAL(textChanged(const TQString &)),SLOT(slotProxyUserChanged(const TQString &)));
	TQObject::connect(lePassword,SIGNAL(textChanged(const TQString &)),SLOT(slotProxyPasswordChanged(const TQString &)));
	
	md5Pwd[0] = 0x00;
	setting=NULL;
	showNetSetup(false);
	proxyPwdChanged = false;
	pwdChanged = false;
	slotLoginTypeChanged(0);
}

EvaLoginWindow::~EvaLoginWindow()
{
}

void EvaLoginWindow::setLogo(const TQPixmap *logo)
{
	if(!logo) return;
	lblLogo->setPixmap(*logo);
}

void EvaLoginWindow::setEvaSetting(EvaSetting *s)
{
	setting = s;
	iniRecords( );
}

const int EvaLoginWindow::getQQ() const
{
	return qqNum;
}

const TQString EvaLoginWindow::getPassword() const
{
	return lePwd->text();
}

const bool EvaLoginWindow::isHiddenLoginMode() const
{
	return chbLoginMode->isOn();
}

const bool EvaLoginWindow::isRememberChecked() const
{
	return chbRecordPwd->isOn();
}

const char * EvaLoginWindow::getMd5Password() const
{	
	return md5Pwd;
}

const EvaLoginWindow::Type EvaLoginWindow::getConnectionType() const
{
	int index = cbbLoginType->currentItem();
	if(index == 0) return UDP;
	if(index == 1) return TCP;
	if(index == 2) return HTTP_Proxy;
	return UDP;
}

const TQString EvaLoginWindow::getProxyIP() const
{
	return leIP->text();
}

const int EvaLoginWindow::getProxyPort() const
{
	return port;
}

const TQString EvaLoginWindow::getProxyUserName() const
{
	return leUserName->text();
}

const TQString EvaLoginWindow::getProxyPassword() const
{
	return lePassword->text();
}

const TQCString EvaLoginWindow::getProxyParam()
{
	return proxyParam;
}

void EvaLoginWindow::cancelClickSlot()
{
	emit doCancel();
}

void EvaLoginWindow::loginClickSlot()
{
	bool qqok, portok;
	qqNum = cbQQ->currentText().toInt(&qqok, 10);
	if(!qqok){
		TQMessageBox::information(this, i18n( "Eva Login"), 
			i18n( "Sorry, account is not an integer number."));
		cbQQ->setFocus();
		return;
	}
	if(getConnectionType() == HTTP_Proxy){
		port = lePort->text().toInt(&portok, 10);
		if(!portok){
			TQMessageBox::information(this, i18n( "Eva Login"), 
				i18n( "Sorry, proxy server port is not an integer number."));
			lePort->setFocus();
			return;
		}
	}
	proxyPwdChanged = false;
	pwdChanged = false;
	emit doLogin();
}

void EvaLoginWindow::showNetSetup(bool on)
{
	if(on){
		setMinimumHeight (330);
		setMaximumHeight (330);
	}else{
		setMinimumHeight (205);
		setMaximumHeight (205);
	}
}

void EvaLoginWindow::iniRecords( )
{
	proxyPwdChanged = false;
	pwdChanged = false;
	if(!setting) return;
	if(!setting->loadSetting())
		return;
	cbQQ->clear();
	for(uint i=0; i<setting->getRecordedList().count();i++){
		int id = setting->getRecordedList().at(i)->id;
		cbQQ->insertItem(TQString::number(id));
	}
	cbQQ->setCurrentItem(setting->getLastUserIndex());

	currentIndex = setting->getLastUserIndex();
	setupOtherSetings(currentIndex);
}


void EvaLoginWindow::slotIDChanged( const TQString &)
{
}


void EvaLoginWindow::slotSelectChanged( int index)
{
	if((uint)(index) >= setting->getRecordedList().count()) return;
	currentIndex = index;	
 	setupOtherSetings( currentIndex);
	proxyPwdChanged = false;
	pwdChanged = false;
}


void EvaLoginWindow::slotPasswordChanged( const TQString &newPwd)
{
	if(newPwd.isEmpty()) return;
	int pwdLen = strlen(newPwd.ascii());
	char *pwd = new char[pwdLen+1];
	memcpy(pwd, newPwd.ascii(), pwdLen);
	pwd[pwdLen]=0x00;
	memcpy(md5Pwd, EvaUtil::doMd5Md5(pwd, pwdLen), 16);	
	delete pwd;
}

void EvaLoginWindow::slotProxyUserChanged(const TQString &)
{
	updateProxyLoginParam();
	lePassword->setText("");
}

void EvaLoginWindow::slotProxyPasswordChanged(const TQString &)
{
	if(proxyPwdChanged){
		proxyPwdChanged = false;
		return;
	}
	updateProxyLoginParam();
}

void EvaLoginWindow::updateProxyLoginParam()
{
	TQCString para = (leUserName->text() + ':' + lePassword->text()).local8Bit();
	proxyParam = TQCodecs::base64Encode(para);
}

void EvaLoginWindow::setupOtherSetings( int index )
{
	if(!setting) return;
	if((uint)(index) >= setting->getRecordedList().count()) return;
		
	TQString sid = cbQQ->text(index);
	bool ok;
	int id = sid.toInt(&ok);
	if(!ok) return;
		
	if(setting->isHiddenChecked(id))
		chbLoginMode->setChecked(true);
	else
		chbLoginMode->setChecked(false);

	cbQQ->setFocus();		
	
	if(setting->isRememberChecked(id)){ 
		chbRecordPwd->setChecked(true);
		lePwd->setText("@@@@@@@@");
		memcpy(md5Pwd, setting->getPassword(id), 16);
		pwdChanged = true;
	}else{
		chbRecordPwd->setChecked(false);
		lePwd->setText("");
		md5Pwd[0]=0;
		
		cbbLoginType->setCurrentItem(0);		
		leIP->setText("");
		lePort->setText("");
		leUserName->setText("");
		lePassword->setText("");
		proxyParam="";
		return;
	}
	
	switch(setting->getConnectType(id)){
	case 0:
		cbbLoginType->setCurrentItem(0);
		break;
	case 1:
		cbbLoginType->setCurrentItem(1);
		break;
	case 2:
		cbbLoginType->setCurrentItem(2);
		break;
	default:
		cbbLoginType->setCurrentItem(0);
		
	}
	
	if(setting->getConnectType(id) == 2){
		leIP->setText(TQHostAddress(setting->getServer(id)).toString());
		lePort->setText(TQString::number(setting->getPort(id)) );
		leUserName->setText(setting->getProxyUsername(id));		
		lePassword->setText("@@@@@@@@");
		proxyParam = setting->getProxyParam(id);
		proxyPwdChanged = true;
	}
	
	//lePwd->setFocus(); // finally, set focus in the password item
	cbQQ->setFocus();  // set focus in the QQ number item
}

void EvaLoginWindow::slotLoginTypeChanged( int index)
{
	switch(index){
	case 0:
	case 1:
		fraNetSetup->setEnabled(false);
		break;
	case 2:
		fraNetSetup->setEnabled(true);
		break;
	default:
		fraNetSetup->setEnabled(false);
	}
}


