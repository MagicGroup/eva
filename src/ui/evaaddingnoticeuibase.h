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

#ifndef EVAADDINGNOTICEUIBASE_H
#define EVAADDINGNOTICEUIBASE_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQFrame;
class TQLabel;
class TQToolButton;
class TQButtonGroup;
class TQRadioButton;
class TQLineEdit;
class TQCheckBox;
class TQPushButton;

class EvaAddingNoticeUIBase : public TQWidget
{
    Q_OBJECT

public:
    EvaAddingNoticeUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaAddingNoticeUIBase();

    TQFrame* fraMain;
    TQLabel* lblTitle;
    TQLabel* lblMessageTag;
    TQToolButton* tbFace;
    TQLabel* lblMessage;
    TQButtonGroup* btngrpActions;
    TQRadioButton* rbtnAcceptAdd;
    TQRadioButton* rbtnAccept;
    TQRadioButton* rbtnReject;
    TQFrame* fraRejectContents;
    TQLineEdit* leRejectMessage;
    TQCheckBox* chbRejectForever;
    TQToolButton* tbtnAuthSettings;
    TQPushButton* btnOk;
    TQPushButton* btnCancel;

protected:
    TQGridLayout* EvaAddingNoticeUIBaseLayout;
    TQVBoxLayout* layout15;
    TQSpacerItem* spacer1;
    TQGridLayout* fraMainLayout;
    TQVBoxLayout* layout10;
    TQHBoxLayout* layout9;
    TQSpacerItem* spacer3;
    TQVBoxLayout* layout4;
    TQGridLayout* btngrpActionsLayout;
    TQHBoxLayout* layout14;
    TQGridLayout* fraRejectContentsLayout;
    TQVBoxLayout* layout2;
    TQHBoxLayout* layout3;
    TQSpacerItem* spacer2;

protected slots:
    virtual void languageChange();

};

#endif // EVAADDINGNOTICEUIBASE_H
