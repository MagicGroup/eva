/***************************************************************************
 *   Copyright (C) 2005 by casper                                          *
 *   tlmcasper@163.com                                                     *
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

#ifndef EVAUSERUIBASE_H
#define EVAUSERUIBASE_H

#include <ntqvariant.h>
#include <ntqdialog.h>
#include <ntqscrollview.h>
#include <ntqtoolbutton.h>

#include <kpushbutton.h>

#include "evauserinfowidget.h"

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQPushButton;
class TQLabel;
class TQTabWidget;
class TQWidget;
class TQPushButton;
class TQLineEdit;
class TQTextEdit;
class TQCheckBox;

class EvaUserUIBase : public TQDialog
{
    Q_OBJECT

public:
    EvaUserUIBase( TQWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~EvaUserUIBase();

    TQPushButton* pbUpdate;
    TQPushButton* pbClose;
    TQLabel* lblText;
    TQTabWidget* twTabMain;
    
    TQWidget* tabTQQShow;
   // TQLabel* lblTQQShowBar;   
    TQLabel* lblTQQShow;
    //TQToolButton* tbtnHome;
    TQToolButton* tbtnAlbum;
    KPushButton* kpbUpdateShow;
    TQToolButton* tbtnShop;

    //UserInfo ScrollView 
    TQScrollView* svMain;
    EvaUserInfoWidget* qwUserInfo;
    
    //Memo
    TQWidget* TabMemo;
    TQLabel* lblMemoName;
    TQLabel* lblMemoMobile;
    TQLabel* lblMemoAddress;
    TQLabel* lblMemoEmail;
    TQLineEdit* leMemoName;
    TQLineEdit* leMemoMobile;
    TQLabel* lblMemoTelephone;
    TQLabel* lblMemoZipCode;
    TQLineEdit* leMemoTelephone;
    TQLineEdit* leMemoZipCode;
    TQLineEdit* leMemoAddress;
    TQLineEdit* leMemoEmail;
    TQLabel* lblMemoNote;
    TQTextEdit* teMemoNote;
    TQCheckBox* chbAutoUploadMemo;
    TQPushButton* pbDownloadMemo;


protected:
    TQGridLayout* layout13;
    TQSpacerItem* spacer6;
    TQGridLayout* layout12;
    TQSpacerItem* spacer5;
    TQSpacerItem* spacer7;
    TQSpacerItem* spacer8;
    
    TQGridLayout* TabMemoLayout;
    TQSpacerItem* spacer30;
    TQSpacerItem* spacer29;
    TQVBoxLayout* layout117;
    TQSpacerItem* spacer38;
    TQHBoxLayout* layout100;
    TQVBoxLayout* layout97;
    TQVBoxLayout* layout99;
    TQHBoxLayout* layout98;
    TQVBoxLayout* layout80;
    TQVBoxLayout* layout81;
    TQVBoxLayout* layout82;
    TQVBoxLayout* layout86;
    TQHBoxLayout* layout112;
    TQVBoxLayout* layout111;
    TQSpacerItem* spacer32;
    TQHBoxLayout* layout116;
    TQSpacerItem* spacer34;
    TQSpacerItem* spacer33;


protected slots:
    virtual void languageChange();

};

#endif // EVAUSERUIBASE_H
