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
#ifndef EVAMAINBASEUI_H
#define EVAMAINBASEUI_H

#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQToolButton;
class TQLabel;
class EvaTabWidget;
class TQPushButton;
class EvaDisplayWidget;
class EvaStatusBar;

class EvaMainUIBase : public TQWidget
{
    Q_OBJECT

public:
    EvaMainUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaMainUIBase();

    TQToolButton* tbMyFace;
    TQLabel* tlNick;
    TQLabel* tlQQ;
    //EvaListView* listView;
    //EvaTabWidget *tab;
    EvaDisplayWidget *mainDisplay;
    EvaStatusBar *statusBar;
    //TQPushButton* pbSearch;
    //TQPushButton* pbMessages;
    //TQPushButton* pbSystem;
    //TQPushButton* pbStatus;

protected:
    TQGridLayout* EvaMainUIBaseLayout;
    TQVBoxLayout* layout1;
    TQHBoxLayout* layout2;
    TQSpacerItem* spacer1;
    //TQVBoxLayout* layout3;
    //TQHBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif
 
