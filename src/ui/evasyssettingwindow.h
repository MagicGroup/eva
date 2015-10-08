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
 /*
	revised by tlmcasper 2005
	tlmcasper@163.com
*/
#ifndef EVASYSSETTINGWINDOW_H
#define EVASYSSETTINGWINDOW_H

#include "evasyssettinguibase.h"

#include <kkeybutton.h>
#include <list>


#define EVA_SETTINGWINDOW_HEAD_ICON_WIDTH 32

class EvaImageResource;
class EvaUserSetting;
class TQIconViewItem;
class TQCloseEvent;

class EvaSysSettingWindow : public EvaSysSettingUIBase
{
	Q_OBJECT
public:
	EvaSysSettingWindow(TQStringList &user, EvaImageResource *res, EvaUserSetting *seting, TQWidget *parent = 0);
	~EvaSysSettingWindow();
signals:
	void settingChanged();
	void faceSizeChanged();
	void requestUpdate(const unsigned int);
	void requestTQQShow(const unsigned int);
	void requestUpdateSignature(const TQString contents);
	void requestDeleteSignature();
	void requestModify(TQStringList, TQString, TQString); // qq id, all details, old password, new password

	void requestMyAuthQuestionSetting();
	void requestMyUpdateQuestion( const TQString &quest, const TQString &answer);
public slots:
	void slotDetailsUpdated(TQStringList);
	void slotSignatureReply(const bool);
	void slotUpdateResult(bool, bool isSignature = false);
	void slotBuddyTQQShowReady(const unsigned int id);
	void slotReceivedMyAuthSettings(const unsigned char auth, const TQString& question, const TQString &answer);
	void slotUpdateAuthSettingResult(const unsigned char auth, const unsigned char reply);
private:
	void saveSetting();
	void loadSetting(const bool isLoadDefault = false);
	
	void setupFaces();
	bool UpdateData(bool);
	const TQString getClientKeyString();
	
	EvaUserSetting *userSetting;
	std::list<TQString> autoList;
	std::list<TQString> tquickList;
	
	static EvaImageResource *faces;
	TQStringList details;
	int selectedFaceIndex;
	bool isSignatureChanged;
	bool isFaceSizeChanged;
	
	bool isUserInfoChanged;
	bool isSysSettingChanged;
	bool m_IsAuthQuestionChanged;
	
private slots:
	void slotPbFaceDefaultClicked();
	void slotPbApplyClicked();
	void slotPbOKClicked();
	void slotFaceSizeChanged(int value);
	void slotCapturedShortcut(const TDEShortcut &key);
	
	void slotPbThemeClicked();
	void slotPbSoundClicked();
	
	void slotCbbAutoNoActivated(int);
	void slotPbAutoNewClicked();
	void slotPbAutoDeleteClicked();
	void slotTeAutoTextChanged();
	
	void slotCbbQuickNoActivated(int);
	void slotPbQuickNewClicked();
	void slotPbQuickDeleteClicked();
	void slotTeQuickTextChanged();
	
	void slotSettingListItemClicked(TQListViewItem* item);
	
	void slotPbFaceClicked();
	void FaceChoose( TQIconViewItem * item );
	void slotFirstUpdate();
	void slotSignatureChanged();
	
	void slotShopClicked();
	void slotAlbumClicked();
	void slotHomeClicked();
	void slotUpdateTQQShow();
	
	void slotLinkClicked( const TQString & url);
	
	void  slotChangePwdClicked();
	
	/////////for test only////////////
	void slotUserInfoChanged();
	void slotSysSettingChanged(); 

	void closeEvent(TQCloseEvent *e);

	void slotAuthChanged();

	void slotChangePasswordClicked();
	void slotProtectPasswordClicked();
};

#endif

