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

#ifndef EVAADDTQUNUIBASE_H
#define EVAADDTQUNUIBASE_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQToolButton;
class TQLabel;
class TQFrame;
class TQLineEdit;
class TQGroupBox;
class TQPushButton;

class EvaAddQunUIBase : public TQWidget
{
    Q_OBJECT

public:
    EvaAddQunUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaAddQunUIBase();

    TQToolButton* tbQunDetails;
    TQLabel* lblQunIDTag;
    TQLabel* lblCreatorTag;
    TQLabel* lblQunExtID;
    TQLabel* lblCreator;
    TQLabel* lblQunNameTag;
    TQLabel* lblQunName;
    TQToolButton* tbCreatorDetails;
    TQFrame* fraAuthContents;
    TQLabel* lblDescription;
    TQFrame* fraAuthGraphic;
    TQLabel* lblCode;
    TQLineEdit* leCode;
    TQLabel* lblTip;
    TQLabel* lblGraphic;
    TQToolButton* tbRefresh;
    TQGroupBox* gbMessage;
    TQLineEdit* leMessage;
    TQPushButton* btnSend;
    TQPushButton* btnCancel;

protected:
    TQGridLayout* EvaAddQunUIBaseLayout;
    TQVBoxLayout* layout21;
    TQHBoxLayout* layout15;
    TQVBoxLayout* layout1;
    TQVBoxLayout* layout2;
    TQVBoxLayout* layout14;
    TQHBoxLayout* layout13;
    TQSpacerItem* spacer3;
    TQHBoxLayout* layout4;
    TQSpacerItem* spacer1;
    TQVBoxLayout* fraAuthContentsLayout;
    TQVBoxLayout* layout20;
    TQVBoxLayout* fraAuthGraphicLayout;
    TQVBoxLayout* layout19;
    TQHBoxLayout* layout18;
    TQSpacerItem* spacer4;
    TQHBoxLayout* layout17;
    TQSpacerItem* spacer5;
    TQVBoxLayout* gbMessageLayout;
    TQHBoxLayout* layout11;
    TQSpacerItem* spacer2;

protected slots:
    virtual void languageChange();

};

#endif // EVAADDTQUNUIBASE_H
