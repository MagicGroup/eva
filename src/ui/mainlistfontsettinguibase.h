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

#ifndef MAINLISTFONTSETTINGUIBASE_H
#define MAINLISTFONTSETTINGUIBASE_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class KTabWidget;
class TQGroupBox;
class TQLabel;
class KColorCombo;
class TQCheckBox;

class MainListFontSettingUIBase : public TQWidget
{
	Q_OBJECT

public:
	MainListFontSettingUIBase( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
	~MainListFontSettingUIBase();
	
	KTabWidget* ktabMainListFont;
	TQWidget* TabPage;
	TQGroupBox* gbBuddyNick;
	TQLabel* lblBuddyNickColor;
	KColorCombo* kcbbBuddyNickColor;
	TQCheckBox* chbBuddyNickFontB;
	TQCheckBox* chbBuddyNickFontU;
	TQCheckBox* chbBuddyNickFontI;
	TQGroupBox* gbBuddyFlash;
	TQLabel* lblBuddyFlashColor;
	KColorCombo* kcbbBuddyFlashColor;
	TQCheckBox* chbBuddyFlashFontB;
	TQCheckBox* chbBuddyFlashFontU;
	TQCheckBox* chbBuddyFlashFontI;
	TQGroupBox* gbBuddySignature;
	TQLabel* lblBuddySigColor;
	KColorCombo* kcbbBuddySigColor;
	TQCheckBox* chbBuddySigFontB;
	TQCheckBox* chbBuddySigFontU;
	TQCheckBox* chbBuddySigFontI;
	TQWidget* TabPage_2;
	TQGroupBox* gbQunName;
	TQLabel* lblQunNameColor;
	KColorCombo* kcbbQunNameColor;
	TQCheckBox* chbQunNameFontB;
	TQCheckBox* chbQunNameFontU;
	TQCheckBox* chbQunNameFontI;
	TQGroupBox* gbQunFlash;
	TQLabel* lblQunFlashColor;
	KColorCombo* kcbbQunFlashColor;
	TQCheckBox* chbQunFlashFontB;
	TQCheckBox* chbQunFlashFontU;
	TQCheckBox* chbQunFlashFontI;
	TQWidget* TabPage_3;
	TQGroupBox* gbGroupName;
	TQLabel* lblGroupNameColor;
	KColorCombo* kcbbGroupNameColor;
	TQCheckBox* chbGroupNameFontB;
	TQCheckBox* chbGroupNameFontU;
	TQCheckBox* chbGroupNameFontI;
	TQGroupBox* gbGroupFlash;
	TQLabel* lblGroupFlashColor;
	KColorCombo* kcbbGroupFlashColor;
	TQCheckBox* chbGroupFlashFontB;
	TQCheckBox* chbGroupFlashFontU;
	TQCheckBox* chbGroupFlashFontI;
	TQGroupBox* gbGroupOnlineCount;
	TQLabel* lblGroupOnlineColor;
	KColorCombo* kcbbGroupOnlineColor;
	TQCheckBox* chbGroupOnlineFontB;
	TQCheckBox* chbGroupOnlineFontU;
	TQCheckBox* chbGroupOnlineFontI;

protected:
	TQGridLayout* MainListFontSettingUIBaseLayout;
	TQVBoxLayout* TabPageLayout;
	TQVBoxLayout* gbBuddyNickLayout;
	TQHBoxLayout* layout1;
	TQHBoxLayout* layout2;
	TQVBoxLayout* gbBuddyFlashLayout;
	TQHBoxLayout* layout3;
	TQHBoxLayout* layout4;
	TQVBoxLayout* gbBuddySignatureLayout;
	TQHBoxLayout* layout5;
	TQHBoxLayout* layout6;
	TQVBoxLayout* TabPageLayout_2;
	TQVBoxLayout* layout11;
	TQVBoxLayout* gbQunNameLayout;
	TQHBoxLayout* layout1_2;
	TQHBoxLayout* layout2_2;
	TQVBoxLayout* gbQunFlashLayout;
	TQHBoxLayout* layout3_2;
	TQHBoxLayout* layout4_2;
	TQVBoxLayout* TabPageLayout_3;
	TQVBoxLayout* gbGroupNameLayout;
	TQHBoxLayout* layout1_3;
	TQHBoxLayout* layout2_3;
	TQVBoxLayout* gbGroupFlashLayout;
	TQHBoxLayout* layout3_3;
	TQHBoxLayout* layout4_3;
	TQVBoxLayout* gbGroupOnlineCountLayout;
	TQHBoxLayout* layout5_2;
	TQHBoxLayout* layout6_2;

protected slots:
	virtual void languageChange();

};

#endif // MAINLISTFONTSETTINGUIBASE_H
