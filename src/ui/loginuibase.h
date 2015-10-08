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

#ifndef FRMLOGIN_H
#define FRMLOGIN_H

#include <ntqvariant.h>
#include <ntqdialog.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQPushButton;
class TQToolButton;
class TQGroupBox;
class TQLabel;
class TQComboBox;
class TQLineEdit;
class TQCheckBox;
class TQFrame;

class LoginUIBase : public TQDialog
{
    Q_OBJECT

public:
    LoginUIBase( TQWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~LoginUIBase();

    TQPushButton* cancelBtn;
    TQToolButton* tbNetSetup;
    TQGroupBox* groupBox1;
    TQLabel* textLabel1;
    TQLabel* textLabel2;
    TQComboBox* cbQQ;
    TQLineEdit* lePwd;
    TQCheckBox* chbRecordPwd;
    TQCheckBox* chbLoginMode;
    TQFrame* line1;
    TQLabel* lblType;
    TQComboBox* cbbLoginType;
    TQPushButton* loginBtn;
    TQFrame* fraNetSetup;
    TQLabel* tlProxyServer;
    TQLineEdit* leIP;
    TQLabel* tlProxyPort;
    TQLineEdit* lePort;
    TQLabel* tlUserName;
    TQLineEdit* leUserName;
    TQLabel* tlPassword;
    TQLineEdit* lePassword;
    TQLabel* lblLogo;

public slots:
    virtual void loginClickSlot();
    virtual void cancelClickSlot();

protected:
    TQGridLayout* groupBox1Layout;
    TQHBoxLayout* layout14;
    TQSpacerItem* spacer3;
    TQSpacerItem* spacer2;
    TQVBoxLayout* layout9;
    TQHBoxLayout* layout8;
    TQVBoxLayout* layout7;
    TQVBoxLayout* layout6;
    TQHBoxLayout* layout1;
    TQSpacerItem* spacer1;
    TQGridLayout* fraNetSetupLayout;
    TQVBoxLayout* layout13;
    TQHBoxLayout* layout12;
    TQHBoxLayout* layout11;

protected slots:
    virtual void languageChange();

};

#endif // FRMLOGIN_H
