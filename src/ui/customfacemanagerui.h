/****************************************************************************
** Form interface generated from reading ui file 'customfacemanagerui.ui'
**
** Created: 五  9月 1 00:01:38 2006
**      by: The User Interface Compiler ($Id: customfacemanagerui.h,v 1.2 2006/09/05 12:18:48 yunfan Exp $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CUSTOMFACEMANAGERUI_H
#define CUSTOMFACEMANAGERUI_H

#include <ntqvariant.h>
#include <ntqpixmap.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQFrame;
class TQToolButton;
class TQListView;
class TQListViewItem;
class TQTable;
class TQPushButton;
class TQLabel;

class CustomFaceManagerUI : public TQWidget
{
    Q_OBJECT

public:
    CustomFaceManagerUI( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CustomFaceManagerUI();

    TQFrame* frame7;
    TQToolButton* tbtnImport;
    TQToolButton* tbtnExport;
    TQToolButton* tbtnAddGroup;
    TQToolButton* tbtnEditGroup;
    TQToolButton* tbtnRemoveGroup;
    TQFrame* frame6;
    TQListView* lvGroups;
    TQFrame* frmMain;
    TQTable* tblFaceList;
    TQPushButton* btnAdd;
    TQPushButton* btnRemove;
    TQPushButton* btnEdit;
    TQPushButton* btnUp;
    TQPushButton* btnDown;
    TQPushButton* btnMoveTo;
    TQLabel* lblPreview;
    TQPushButton* btnOK;
    TQPushButton* btnCancel;

protected:
    TQGridLayout* CustomFaceManagerUILayout;
    TQVBoxLayout* layout9;
    TQGridLayout* frame7Layout;
    TQHBoxLayout* layout1;
    TQHBoxLayout* layout7;
    TQGridLayout* frame6Layout;
    TQGridLayout* frmMainLayout;
    TQHBoxLayout* layout6;
    TQVBoxLayout* layout5;
    TQSpacerItem* spacer1;
    TQHBoxLayout* layout8;
    TQSpacerItem* spacer2;

protected slots:
    virtual void languageChange();

private:
    TQPixmap image0;
    TQPixmap image1;
    TQPixmap image2;

};

#endif // CUSTOMFACEMANAGERUI_H
