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
 
#ifndef EVATQUNMEMBERPICKER_H 
#define EVATQUNMEMBERPICKER_H 

#include "evaqunmemberpickerui.h"
#include <map>
#include <ntqpixmap.h>

class Qun;
class TQListViewItem;
class TQCheckListItem;
class EvaQunMemberPicker : public EvaQunMemberPickerUI
{
	Q_OBJECT
public:
	EvaQunMemberPicker(TQWidget* parent = 0, const char* name = 0, WFlags fl = 0, Qun *qun = NULL);
	~EvaQunMemberPicker() {};
	
	void updateBuddyListView();
signals:
	void memberClicked(const unsigned int id, const bool isChecked);
public slots:
	void slotSetMemberOff(const unsigned int id);
private:
	Qun *mQun;
	std::map<int, TQCheckListItem*> groups;  // key is group index
	std::map<int, TQCheckListItem*> buddyList; // key is buddy QQ
	void initListView();
private slots:
	void slotClicked(TQListViewItem *item);
};

#endif
