/***************************************************************************
 *   Copyright (C) 2006 by casper                                          *
 *   tlmcasper@163.com                                                     *
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



#ifndef EVASEARCHUIBASE_H
#define EVASEARCHUIBASE_H

#include <ntqvariant.h>
#include <ntqdialog.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQTabWidget;
class TQWidget;
class TQWidgetStack;
class TQLabel;
class TQButtonGroup;
class TQRadioButton;
class TQGroupBox;
class TQLineEdit;
class TQTable;
class TQToolButton;
class TQCheckBox;
class TQComboBox;
class TQPushButton;

class EvaSearchUIBase : public TQDialog
{
    Q_OBJECT

public:
    EvaSearchUIBase( TQWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~EvaSearchUIBase();

    TQTabWidget* twSearchMain;
    TQWidget* tabBasicSearch;
    TQWidgetStack* wsBasicSearch;
    TQWidget* wsBSPage;
    TQLabel* lblSearchOptionTip;
    TQButtonGroup* bgBSType;
    TQRadioButton* rbCustomSearch;
    TQRadioButton* rbSearchFrdCenter;
    TQRadioButton* rbSearchOnline;
    TQWidgetStack* wsBasicCondtion;
    TQWidget* wsCustomSearchCondition;
    TQGroupBox* gbCustomCondition;
    TQLabel* lblTQQNum;
    TQLabel* lblNickName;
    TQLineEdit* leTQQNum;
    TQLineEdit* leNickName;
    TQWidget* wsFrdCenterSearchCondition;
    TQGroupBox* gbFrdCenterCondition;
    TQLabel* lblTQQFrdTip;
    TQLabel* lblOnlineNumbers;
    TQLabel* lblOnlineNum;
    TQWidget* wsBSResultPage;
    TQLabel* lblBSResultTip;
    TQTable* tbBSResult;
    TQLabel* lblBSResultPage;
    TQToolButton* tbBSAll;
    TQToolButton* tbBSDetails;
    TQToolButton* tbBSPrev;
    TQToolButton* tbBSNext;
    TQWidget* tabAdvancedSearch;
    TQWidgetStack* wsAdvancedSearch;
    TQWidget* wsASPage;
    TQLabel* lblASTip;
    TQCheckBox* chbOnlineUsers;
    TQCheckBox* chbHaveCamera;
    TQGroupBox* gbBasicCondition;
    TQLabel* lblASProvince;
    TQLabel* lblASCity;
    TQLabel* lblASAge;
    TQLabel* lblASGender;
    TQComboBox* cbASProvince;
    TQComboBox* cbASCity;
    TQComboBox* cbASAge;
    TQComboBox* cbASSex;
    TQWidget* wsASResultPage;
    TQLabel* lblASResultTip;
    TQTable* tbASResult;
    TQLabel* lblASResultPage;
    TQToolButton* tbASAll;
    TQToolButton* tbASDetails;
    TQToolButton* tbASPrev;
    TQToolButton* tbASNext;
    TQWidget* tabQunSearch;
    TQWidgetStack* wsQunSearch;
    TQWidget* wsTQSPage;
    TQLabel* lblTQSTip;
    TQButtonGroup* bgTQSType;
    TQRadioButton* rbSearchAlumni;
    TQRadioButton* rbAccuratelySearch;
    TQRadioButton* rbSearchByCategory;
    TQGroupBox* gbTQCondition;
    TQWidgetStack* wsQunCondition;
    TQWidget* wsCategoryConditon;
    TQLabel* lblCategory;
    TQComboBox* cbCategory1;
    TQComboBox* cbCategory2;
    TQComboBox* cbCategory3;
    TQWidget* wsAlumniCondition;
    TQLabel* lblAlumniTip;
    TQWidget* wsAccurateCondition;
    TQLabel* lblQunNum;
    TQLineEdit* leQunNum;
    TQWidget* wsTQSResultPage;
    TQLabel* lblTQSResultTip;
    TQTable* tbTQSResult;
    TQLabel* lblTQSResultPage;
    TQToolButton* tbTQSAll;
    TQToolButton* tbTQSDetails;
    TQToolButton* tbTQSPrev;
    TQToolButton* tbTQSNext;
    TQPushButton* pbLastStep;
    TQPushButton* pbSearch;
    TQPushButton* pbClose;
    TQLabel* lblLogo;

protected:
    TQGridLayout* EvaSearchUIBaseLayout;
    TQGridLayout* layout127;
    TQGridLayout* tabBasicSearchLayout;
    TQGridLayout* wsBSPageLayout;
    TQVBoxLayout* layout135;
    TQVBoxLayout* layout105;
    TQHBoxLayout* layout100;
    TQSpacerItem* spacer54;
    TQGridLayout* bgBSTypeLayout;
    TQGridLayout* wsCustomSearchConditionLayout;
    TQGridLayout* gbCustomConditionLayout;
    TQSpacerItem* spacer119_2;
    TQHBoxLayout* layout204_2;
    TQVBoxLayout* layout188_2;
    TQVBoxLayout* layout203_2;
    TQGridLayout* wsFrdCenterSearchConditionLayout;
    TQGridLayout* gbFrdCenterConditionLayout;
    TQVBoxLayout* layout46;
    TQSpacerItem* spacer27;
    TQSpacerItem* spacer28;
    TQHBoxLayout* layout316_2;
    TQSpacerItem* spacer111;
    TQGridLayout* wsBSResultPageLayout;
    TQVBoxLayout* layout47;
    TQHBoxLayout* layout96;
    TQSpacerItem* spacer46;
    TQHBoxLayout* layout46_2;
    TQSpacerItem* spacer47;
    TQGridLayout* tabAdvancedSearchLayout;
    TQGridLayout* wsASPageLayout;
    TQVBoxLayout* layout91;
    TQSpacerItem* spacer40_2;
    TQVBoxLayout* layout371;
    TQHBoxLayout* layout370;
    TQSpacerItem* spacer156;
    TQSpacerItem* spacer157;
    TQHBoxLayout* layout369;
    TQSpacerItem* spacer155;
    TQGridLayout* gbBasicConditionLayout;
    TQSpacerItem* spacer159;
    TQHBoxLayout* layout376;
    TQVBoxLayout* layout372;
    TQVBoxLayout* layout375;
    TQHBoxLayout* layout373;
    TQSpacerItem* spacer158;
    TQVBoxLayout* wsASResultPageLayout;
    TQVBoxLayout* layout47_2;
    TQHBoxLayout* layout96_2;
    TQSpacerItem* spacer48;
    TQHBoxLayout* layout46_2_2;
    TQSpacerItem* spacer50;
    TQGridLayout* tabQunSearchLayout;
    TQGridLayout* wsTQSPageLayout;
    TQVBoxLayout* layout203;
    TQHBoxLayout* layout92;
    TQSpacerItem* spacer173_2;
    TQSpacerItem* spacer174_2;
    TQVBoxLayout* layout400_2;
    TQHBoxLayout* layout399_2;
    TQSpacerItem* spacer172_2;
    TQGridLayout* bgTQSTypeLayout;
    TQGridLayout* gbTQConditionLayout;
    TQGridLayout* wsCategoryConditonLayout;
    TQSpacerItem* spacer148;
    TQSpacerItem* spacer149;
    TQVBoxLayout* layout402_2;
    TQHBoxLayout* layout388_2;
    TQHBoxLayout* layout394_2;
    TQSpacerItem* spacer168_2;
    TQVBoxLayout* layout390_2;
    TQGridLayout* wsAlumniConditionLayout;
    TQGridLayout* wsAccurateConditionLayout;
    TQSpacerItem* spacer151;
    TQSpacerItem* spacer152;
    TQHBoxLayout* layout306;
    TQGridLayout* wsTQSResultPageLayout;
    TQVBoxLayout* layout49;
    TQHBoxLayout* layout96_3;
    TQSpacerItem* spacer46_2;
    TQHBoxLayout* layout46_3;
    TQSpacerItem* spacer51;
    TQHBoxLayout* layout195;
    TQSpacerItem* spacer38;
    TQSpacerItem* spacer40;

protected slots:
    virtual void languageChange();

};

#endif // EVASEARCHUIBASE_H
