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

#ifndef EVASYSBROADCASTUIBASE_H
#define EVASYSBROADCASTUIBASE_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQFrame;
class TQLabel;
class KURLLabel;
class TQPushButton;

class EvaSysBroadcastUIBase : public TQWidget
{
    Q_OBJECT

public:
    EvaSysBroadcastUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaSysBroadcastUIBase();

    TQFrame* fraContents;
    TQLabel* lblTitle;
    TQLabel* lblContents;
    KURLLabel* kurllblUrl;
    TQPushButton* btnDetails;
    TQPushButton* btnClose;

protected:
    TQGridLayout* EvaSysBroadcastUIBaseLayout;
    TQVBoxLayout* layout7;
    TQGridLayout* fraContentsLayout;
    TQVBoxLayout* layout6;
    TQHBoxLayout* layout5;
    TQSpacerItem* spacer2;
    TQHBoxLayout* layout3;
    TQSpacerItem* spacer1;

protected slots:
    virtual void languageChange();

};

#endif // EVASYSBROADCASTUIBASE_H
