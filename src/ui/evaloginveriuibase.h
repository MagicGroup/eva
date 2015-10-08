/***************************************************************************
 *   Copyright (C) 2007 by yunfan                                          *
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

#ifndef EVALOGINVERIUIBASE_H
#define EVALOGINVERIUIBASE_H

#include <ntqvariant.h>
#include <ntqdialog.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQLabel;
class TQToolButton;
class TQLineEdit;
class TQFrame;
class TQPushButton;

class EvaLoginVeriUIBase : public TQDialog
{
    Q_OBJECT

public:
    EvaLoginVeriUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaLoginVeriUIBase();

    TQLabel* lblTopTip;
    TQLabel* lblGraphicCode;
    TQLabel* lblVeriCode;
    TQLabel* lblGraphic;
    TQToolButton* tbnChangeGraphic;
    TQLineEdit* leCode;
    TQFrame* line1;
    TQPushButton* btnOK;
    TQPushButton* btnCancel;

protected:
    TQGridLayout* EvaLoginVeriUIBaseLayout;
    TQVBoxLayout* layout8;
    TQHBoxLayout* layout1;
    TQSpacerItem* spacer1;
    TQHBoxLayout* layout5;
    TQVBoxLayout* layout2;
    TQVBoxLayout* layout4;
    TQHBoxLayout* layout3;
    TQHBoxLayout* layout6;
    TQSpacerItem* spacer2;

protected slots:
    virtual void languageChange();

};

#endif // EVALOGINVERIUIBASE_H
