/****************************************************************************
** Form interface generated from reading ui file 'evauserinfowidget.ui'
**
** Created: 三 11月 23 19:45:10 2005
**      by: The User Interface Compiler ()
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EVAUSERINFOWIDGET_H
#define EVAUSERINFOWIDGET_H

#include <ntqvariant.h>
#include <ntqwidget.h>

class TQVBoxLayout;
class TQHBoxLayout;
class TQGridLayout;
class TQSpacerItem;
class TQLabel;
class TQLineEdit;
class TQTextEdit;

class EvaUserInfoWidget : public TQWidget
{
    Q_OBJECT

public:
    EvaUserInfoWidget( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaUserInfoWidget();

    TQLabel* lblBasicInfo;
    TQLabel* lblRealName;
    TQLabel* lblNickName;
    TQLabel* lblAge;
    TQLabel* lblArea;
    TQLineEdit* leRealName;
    TQLineEdit* leNickName;
    TQLineEdit* leAge;
    TQLineEdit* leArea;
    TQLabel* lblNumber;
    TQLabel* lblLevel;
    TQLabel* lblSex;
    TQLabel* lblProvince;
    TQLineEdit* leNumber;
    TQLabel* lblLevelDisplay;
    TQLineEdit* leSex;
    TQLabel* lblFace;
    TQLineEdit* leProvince;
    TQLabel* lblCity;
    TQLineEdit* leCity;
    TQTextEdit* teSignature;
    TQLabel* lblSignature;
    TQLineEdit* lePhone;
    TQLineEdit* leHomePage;
    TQLabel* lblMobile;
    TQLineEdit* leMobile;
    TQLineEdit* leOccupation;
    TQLineEdit* leBlood;
    TQLabel* lblBlood;
    TQLabel* lblOccupation;
    TQLineEdit* leZodiac;
    TQLineEdit* leHoroscape;
    TQLineEdit* leSchool;
    TQLineEdit* leEmail;
    TQLineEdit* leAddress;
    TQLineEdit* leZipCode;
    TQLabel* lblZodiac;
    TQLabel* lblHoroscape;
    TQLabel* lblSchool;
    TQLabel* lblEmail;
    TQLabel* lblAddress;
    TQLabel* lblZipCode;
    TQLabel* lblPhone;
    TQLabel* lblHomePage;
    TQLabel* lblDetails;
    TQLabel* lblDescription;
    TQTextEdit* teAboutMe;
    TQLabel* lblAboutMe;

protected:
    TQGridLayout* EvaUserInfoWidgetLayout;
    TQGridLayout* layout191;
    TQSpacerItem* spacer18;
    TQSpacerItem* spacer31;
    TQVBoxLayout* layout189;
    TQVBoxLayout* layout188;
    TQHBoxLayout* layout187;
    TQHBoxLayout* layout186;
    TQVBoxLayout* layout39;
    TQVBoxLayout* layout178;
    TQHBoxLayout* layout163;
    TQVBoxLayout* layout64;
    TQVBoxLayout* layout162;
    TQHBoxLayout* layout161;
    TQVBoxLayout* layout86;
    TQHBoxLayout* layout66;
    TQHBoxLayout* layout65;
    TQHBoxLayout* layout103;
    TQSpacerItem* spacer17;
    TQSpacerItem* spacer24;
    TQHBoxLayout* layout151;
    TQSpacerItem* spacer26;
    TQHBoxLayout* layout156;
    TQSpacerItem* spacer14_2;
    TQGridLayout* layout99;
    TQGridLayout* layout144;
    TQGridLayout* layout143;
    TQSpacerItem* spacer13_2;
    TQGridLayout* layout142;
    TQSpacerItem* spacer28;
    TQSpacerItem* spacer29;
    TQGridLayout* layout141;
    TQHBoxLayout* layout139;
    TQSpacerItem* spacer27;
    TQGridLayout* layout138;
    TQVBoxLayout* layout30;
    TQVBoxLayout* layout51;
    TQVBoxLayout* layout95;
    TQGridLayout* layout94;
    TQSpacerItem* spacer16;
    TQSpacerItem* spacer14_2_2;

protected slots:
    virtual void languageChange();

};

#endif // EVAUSERINFOWIDGET_H
