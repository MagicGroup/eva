/***************************************************************************
 *   Copyright (C) 2004 by yunfan                                          *
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

#ifndef EVATQUNSYSMSGUIBASE_H
#define EVATQUNSYSMSGUIBASE_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQFrame;
class TQToolButton;
class TQLabel;
class TQButtonGroup;
class TQRadioButton;
class TQLineEdit;
class TQCheckBox;
class TQPushButton;

class EvaQunSysMsgUIBase : public TQWidget
{
    Q_OBJECT

public:
    EvaQunSysMsgUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaQunSysMsgUIBase();

    TQFrame* fraMain;
    TQToolButton* tbQQ;
    TQLabel* lblAction;
    TQToolButton* tbQun;
    TQLabel* lblMessage;
    TQButtonGroup* bgActions;
    TQRadioButton* rbtnAccept;
    TQRadioButton* rbtnReject;
    TQFrame* fraMessage;
    TQLineEdit* leMessage;
    TQCheckBox* chbRejectForever;
    TQPushButton* btnOk;
    TQPushButton* btnClose;

protected:
    TQGridLayout* EvaQunSysMsgUIBaseLayout;
    TQVBoxLayout* layout12;
    TQVBoxLayout* fraMainLayout;
    TQVBoxLayout* layout6;
    TQHBoxLayout* layout5;
    TQSpacerItem* spacer3;
    TQVBoxLayout* bgActionsLayout;
    TQHBoxLayout* layout1;
    TQSpacerItem* spacer1;
    TQVBoxLayout* fraMessageLayout;
    TQHBoxLayout* layout10;
    TQSpacerItem* spacer2;

protected slots:
    virtual void languageChange();

};

#endif // EVATQUNSYSMSGUIBASE_H
