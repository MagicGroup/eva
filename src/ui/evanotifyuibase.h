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

#ifndef EVANOTIFYUIBASE_H
#define EVANOTIFYUIBASE_H
#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQGroupBox;
class TQLabel;
class TQToolButton;
class TQWidgetStack;
class TQTextEdit;
class TQPushButton;

class EvaNotifyUIBase : public TQWidget
{
    Q_OBJECT
public:
	EvaNotifyUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
	~EvaNotifyUIBase();
	
	TQGroupBox* gbFrom;
	TQLabel* textLabel1;
	TQLabel* tlQQ;
	TQLabel* textLabel2;
	TQLabel* tlNick;
	TQLabel* textLabel3;
	TQToolButton* tbDetails;
	TQGroupBox* gbMain;
	TQWidgetStack* wsMain;
	TQWidget* WStackPage;
	TQLabel* tlP0Tip;
	TQWidget* WStackPage_2;
	TQLabel* tlP1Tip;
	TQTextEdit* teP1Msg;
	TQPushButton* pbApprove;
	TQPushButton* pbReject;
	TQPushButton* pbAdd;
	TQPushButton* pbClose;

protected:
	TQGridLayout* EvaNotifyUIBaseLayout;
	TQVBoxLayout* layout62;
	TQGridLayout* gbFromLayout;
	TQHBoxLayout* layout49;
	TQSpacerItem* spacer14;
	TQSpacerItem* spacer13;
	TQGridLayout* gbMainLayout;
	TQGridLayout* WStackPageLayout;
	TQGridLayout* WStackPageLayout_2;
	TQHBoxLayout* layout54;
	TQHBoxLayout* layout52;
	TQSpacerItem* spacer15;

protected slots:
	virtual void languageChange();

};

#endif 
