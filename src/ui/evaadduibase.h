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

#ifndef EVAADDUIBASE_H
#define EVAADDUIBASE_H

#include <ntqvariant.h>
#include <ntqwidget.h>


class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQLabel;
class TQFrame;
class TQToolButton;
class TQComboBox;
class TQLineEdit;
class TQCheckBox;
class TQPushButton;

class EvaAddUIBase : public TQWidget
{
    Q_OBJECT

public:
    EvaAddUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaAddUIBase();

    TQLabel* lblTip;
    TQFrame* frame3;
    TQLabel* lblTopic;
    TQToolButton* tbtnFace;
    TQLabel* lblGroup;
    TQComboBox* cbbGroups;
    TQFrame* fraVeriGraphic;
    TQLabel* lblVeriCode;
    TQLineEdit* leCode;
    TQLabel* lblCodeGraphic;
    TQToolButton* btnRefreshCode;
    TQFrame* fraQuestion;
    TQLabel* lblQuestion;
    TQLabel* lblAnswer;
    TQLabel* lblQuesContents;
    TQLineEdit* leAnswer;
    TQLineEdit* leMessage;
    TQCheckBox* chbReverse;
    TQPushButton* btnOk;
    TQPushButton* btnCancel;

protected:
    TQVBoxLayout* EvaAddUIBaseLayout;
    TQVBoxLayout* frame3Layout;
    TQHBoxLayout* layout17;
    TQHBoxLayout* layout13;
    TQSpacerItem* spacer1;
    TQGridLayout* fraVeriGraphicLayout;
    TQHBoxLayout* layout14;
    TQHBoxLayout* fraQuestionLayout;
    TQVBoxLayout* layout12;
    TQVBoxLayout* layout13_2;
    TQHBoxLayout* layout13_3;
    TQSpacerItem* spacer2;

protected slots:
    virtual void languageChange();

};
#endif // EVAADDUIBASE_H
