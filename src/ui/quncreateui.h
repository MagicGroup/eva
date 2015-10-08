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
#ifndef TQUNCREATEUI_H
#define TQUNCREATEUI_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQLabel;
class TQFrame;
class TQWidgetStack;
class TQLineEdit;
class TQToolButton;
class TQGroupBox;
class TQTextEdit;
class TQButtonGroup;
class TQRadioButton;
class TQTable;
class TQPushButton;

class QunCreateUI : public TQWidget
{
    Q_OBJECT

public:
    QunCreateUI( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QunCreateUI();

    TQLabel* lblTip;
    TQFrame* line1;
    TQWidgetStack* wsMain;
    TQWidget* wsDetails;
    TQLabel* lblName;
    TQLineEdit* leQunName;
    TQLabel* lblCategory;
    TQToolButton* tbCategory;
    TQGroupBox* gbNotice;
    TQTextEdit* teNotice;
    TQGroupBox* gbDescription;
    TQTextEdit* teDescription;
    TQButtonGroup* bgAuthen;
    TQRadioButton* rbNoAuthenNeed;
    TQRadioButton* rbNeedAuthen;
    TQRadioButton* rbRejectAnyone;
    TQWidget* wsMembers;
    TQTable* tblMembers;
    TQPushButton* pbSetMembers;
    TQPushButton* pbDelMembers;
    TQPushButton* pbPrev;
    TQPushButton* pbNext;
    TQPushButton* pbCancel;

protected:
    TQVBoxLayout* QunCreateUILayout;
    TQGridLayout* wsDetailsLayout;
    TQVBoxLayout* layout44;
    TQHBoxLayout* layout40;
    TQSpacerItem* spacer15;
    TQHBoxLayout* layout41;
    TQSpacerItem* spacer16;
    TQGridLayout* gbNoticeLayout;
    TQGridLayout* gbDescriptionLayout;
    TQVBoxLayout* bgAuthenLayout;
    TQGridLayout* wsMembersLayout;
    TQHBoxLayout* layout43;
    TQVBoxLayout* layout42;
    TQSpacerItem* spacer17;
    TQHBoxLayout* layout7;
    TQSpacerItem* spacer18;

protected slots:
    virtual void languageChange();

};

#endif // TQUNCREATEUI_H
