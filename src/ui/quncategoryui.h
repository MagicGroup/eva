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
#ifndef TQUNCATEGORYUI_H
#define TQUNCATEGORYUI_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQFrame;
class TQComboBox;
class TQPushButton;

class QunCategoryUI : public TQWidget
{
    Q_OBJECT

public:
    QunCategoryUI( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QunCategoryUI();

    TQFrame* frame3;
    TQComboBox* cbbTop;
    TQComboBox* cbbSecond;
    TQComboBox* cbbThird;
    TQPushButton* pbCancel;
    TQPushButton* pbOK;

protected:
    TQGridLayout* QunCategoryUILayout;
    TQVBoxLayout* layout5;
    TQGridLayout* frame3Layout;
    TQVBoxLayout* layout3;
    TQHBoxLayout* layout4;
    TQSpacerItem* spacer2;

protected slots:
    virtual void languageChange();

};

#endif // TQUNCATEGORYUI_H
