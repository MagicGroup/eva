/****************************************************************************
** Form interface generated from reading ui file 'createsmileyui.ui'
**
** Created: 五  9月 1 00:01:38 2006
**      by: The User Interface Compiler ($Id: createsmileyui.h,v 1.1 2006/08/31 13:10:37 yunfan Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CREATESMILEYUI_H
#define CREATESMILEYUI_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQLabel;
class TQPushButton;
class TQLineEdit;
class TQComboBox;

class CreateSmileyUI : public TQWidget
{
    Q_OBJECT

public:
    CreateSmileyUI( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CreateSmileyUI();

    TQLabel* lblTop;
    TQLabel* lblStep1;
    TQLabel* lblSelect;
    TQPushButton* btnSelect;
    TQLabel* lblStep2;
    TQLineEdit* leShortcut;
    TQLabel* lblStep2_2;
    TQComboBox* cbbGroup;
    TQLabel* lblStep3;
    TQLineEdit* leTip;
    TQLabel* lblCommends;
    TQPushButton* btnOK;
    TQPushButton* btnCancel;

protected:
    TQGridLayout* CreateSmileyUILayout;
    TQVBoxLayout* layout21;
    TQHBoxLayout* layout16;
    TQSpacerItem* spacer6;
    TQHBoxLayout* layout19;
    TQSpacerItem* spacer6_3;
    TQSpacerItem* spacer9;
    TQHBoxLayout* layout17;
    TQSpacerItem* spacer6_2;
    TQHBoxLayout* layout20;
    TQSpacerItem* spacer6_2_2;
    TQHBoxLayout* layout14;
    TQSpacerItem* spacer5;

protected slots:
    virtual void languageChange();

};

#endif // CREATESMILEYUI_H
