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

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "loginuibase.h"
class TQPixmap;
class EvaSetting;

class EvaLoginWindow : public LoginUIBase
{
	Q_OBJECT
	friend class EvaMain;
public:
	EvaLoginWindow(TQWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
	~EvaLoginWindow();
	enum Type{UDP, TCP, HTTP_Proxy};
	void setLogo(const TQPixmap *);
	void setEvaSetting(EvaSetting *setting);
	const int getQQ() const;
	const TQString getPassword() const;
	const char * getMd5Password() const;
	const bool isHiddenLoginMode() const;
	const bool isRememberChecked() const;
	
	const Type getConnectionType() const;
	const TQString getProxyIP() const;
	const int getProxyPort() const;
	const TQString getProxyUserName() const;
	const TQString getProxyPassword() const;
	
	const TQCString getProxyParam();
public slots:
	virtual void cancelClickSlot();
	virtual void loginClickSlot();
signals:
	void doLogin();
	void doCancel();
protected slots:
	void showNetSetup(bool on);
	void slotSelectChanged(int);
	void slotLoginTypeChanged(int);
	void slotIDChanged(const TQString &);
	void slotPasswordChanged(const TQString &);
	void slotProxyUserChanged(const TQString &);
	void slotProxyPasswordChanged(const TQString &);
private:
	int qqNum;
	char md5Pwd[16];
	int port;
	TQCString proxyParam;
	
	bool pwdChanged;
	bool proxyPwdChanged;
	TQString proxyUsername;
	TQString proxyPassword;
	int currentIndex;
	EvaSetting *setting;
	void iniRecords();
	void setupOtherSetings(int index);
	void updateProxyLoginParam();
};

#endif

