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

#ifndef EVATIPUIBASE_H
#define EVATIPUIBASE_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQFrame;
class TQLabel;

class EvaTipUIBase : public TQWidget
{
    Q_OBJECT

public:
    EvaTipUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaTipUIBase();

    TQFrame* fraMain;
    TQLabel* lblPixmap;
    TQLabel* lblNick;
    TQLabel* lblMessage;

protected:
    TQGridLayout* EvaTipUIBaseLayout;
    TQGridLayout* fraMainLayout;
    TQHBoxLayout* layout2;
    TQVBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // EVATIPUIBASE_H
