/***************************************************************************
 *   Copyright (C) 2004 by zsyddl                                          *
 *   morrowren@sina.com                                                     *
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
	revised by yunfan  2005
	           tlmcasper 2005
	yunfan_zg@163.com
	tlmcasper@163.com
*/

#include "evadetailswindow.h"

#include "evaresource.h"
#include "../evamain.h"
#include "evapacket.h"
#include "evauser.h"
#include "evautil.h"
#include <ntqvariant.h>
#include <ntqlabel.h>
#include <ntqpushbutton.h>
#include <ntqlineedit.h>
#include <ntqiconview.h>
#include <ntqradiobutton.h>
#include <ntqtextedit.h>
#include <ntqpixmap.h>
#include <ntqgroupbox.h>
#include <ntqmessagebox.h>
#include <ntqtimer.h>
#include <ntqstringlist.h>
#include <ntqtoolbutton.h>
#include <ntqtextcodec.h>
#include <kpushbutton.h>
#include <krun.h>
#include <tdelocale.h>
#include <tdeapplication.h>
#include <ntqtabwidget.h>
#include <ntqcheckbox.h>

//#include "../usermsg.ui.h"
/*
 *  Constructs a EvaDetailsWindow as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
 
EvaImageResource *EvaDetailsWindow::faces = NULL;
EvaDetailsWindow::EvaDetailsWindow(  TQStringList &user, TQWidget* parent, const char* name, bool modal, WFlags fl)
	: EvaUserUIBase( parent, name, modal, fl ),
	details( user ),selectedFaceIndex( 0 )
{
  
        
	TQObject::connect( pbUpdate, SIGNAL( clicked() ), this, SLOT( slotUpdateClick() ) );	//Click the update button
	TQObject::connect( pbClose, SIGNAL( clicked() ), this, SLOT( close() ) );	//Click the close button
	
	TQObject::connect( tbtnShop, SIGNAL( clicked() ), this, SLOT( slotShopClicked() ) );
	TQObject::connect( tbtnAlbum, SIGNAL( clicked() ), this, SLOT( slotAlbumClicked() ) );
	
	TQObject::connect( kpbUpdateShow, SIGNAL( clicked() ), this, SLOT( slotUpdateTQQShow() ) );
	TQObject::connect( twTabMain, SIGNAL(currentChanged(TQWidget*)), this, SLOT( slotCurrentChanged(TQWidget*)));
	
	TQObject::connect( pbDownloadMemo, SIGNAL( clicked() ), this, SLOT( slotDownloadMemo() ));
	//TQObject::connect( tabWidget, SIGNAL(currentChanged(TQWidget*)), this, SLOT(currentChanged(TQWidget*)) );
	
	m_IsModifyMemo = false;
	codec = TQTextCodec::codecForName("GB18030");
	
	bool ok;
	id = details[0].toUInt(&ok, 10);
	if(!ok) return;
	frd = (EvaMain::user->getFriendList()).getFriend(id); //get the user qq of this details window
	
	setCaption( i18n( "View User Info") );//set the title of this dialog

	qwUserInfo->lblBasicInfo->setPixmap(*faces->getIcon("DETAILS_BASIC_INFO"));
	qwUserInfo->lblDetails->setPixmap(*faces->getIcon("DETAILS_DETAILS"));
	qwUserInfo->lblDescription->setPixmap(*faces->getIcon("DETAILS_DESCRIPTION"));
	
	chbAutoUploadMemo->setChecked(true);
	if(!frd){ // He/She is not in your buddy list
		twTabMain->setTabEnabled(twTabMain->page(2), false);
	}
	if(faces){
		TQPixmap *icon = faces->getIcon("TQQ_SHOP");
		if(icon)
			tbtnShop->setIconSet(TQIconSet(*icon));// add Icon to TQQShow shop button
	} 
	if(faces){
		TQPixmap *icon = faces->getIcon("TQQ_ALBUM");
		if(icon)
			tbtnAlbum->setIconSet(TQIconSet(*icon));
	}
	
	UpdateData(true);
	if(details.size()!=37) {
		TQTimer::singleShot(500, this, SLOT(slotFirstUpdate()));
	}
	
	
}

EvaDetailsWindow::~EvaDetailsWindow()
{
    // no need to delete child widgets, TQt does it all for us
}

void EvaDetailsWindow::slotFirstUpdate()
{
	emit requestUpdate(id);
}

//slot of the update button click envent
void EvaDetailsWindow::slotUpdateClick()
{
	if(!frd) return;
	if( m_IsMemoPage ){		//if the user is in Memo page and the id is set
		//if the auto uplad checkbutton selected
		m_Memo.name = codec->fromUnicode(leMemoName->text()).data();
		m_Memo.mobile = codec->fromUnicode(leMemoMobile->text()).data();
		m_Memo.telephone = codec->fromUnicode(leMemoTelephone->text()).data();
		m_Memo.address = codec->fromUnicode(leMemoAddress->text()).data();
		m_Memo.email = codec->fromUnicode(leMemoEmail->text()).data();
		m_Memo.zipcode = codec->fromUnicode(leMemoZipCode->text()).data();
		m_Memo.note = codec->fromUnicode(teMemoNote->text()).data();
		if(chbAutoUploadMemo->isChecked()){
			emit memoChanged(frd->getQQ(), m_Memo);
			emit requestUploadMemo(frd->getQQ(), m_Memo);
		}
		else{
			//save memo to local file
			
			emit memoChanged(frd->getQQ(), m_Memo);
			TQMessageBox::information(this, i18n( "Store Memo"), i18n( "Store memo successfully"));
		}	
		
	}
	else{
		emit requestUpdate(id);
	}
}

void EvaDetailsWindow::slotDetailsUpdated( TQStringList list)
{
	if(details[0] != list[0] ) return;
	details = list;
	UpdateData(true);
}	
	
const bool EvaDetailsWindow::UpdateData(const bool toShow)
{
	qwUserInfo->leNumber->setText( details[0] );
	
	if(details.size()!=37) return false;
	
	slotBuddyTQQShowReady(id);
	
	int level = 0;
	TQString signature = "";
	if(id == EvaMain::user->getQQ() ){
		level = EvaMain::user->getLevel();
		signature = codec->toUnicode(EvaMain::user->getSignature().c_str());
	}else{
		if(frd){
			level = frd->getLevel();
			signature = codec->toUnicode(frd->getSignature().c_str());
			m_Memo = frd->getMemo();
			slotUpdateMemo(m_Memo);
		}
	}
	int suns, moons, stars;
	EvaUtil::calcSuns(level, &suns, &moons, &stars);
	TQString strSun =  "<img src=\"" + faces->getIconFullPath("TIME_SUN") + "\"></img>";
	TQString strMoon = "<img src=\"" + faces->getIconFullPath("TIME_MOON") + "\"></img>";
	TQString strStar = "<img src=\"" + faces->getIconFullPath("TIME_STAR") + "\"></img>";
	TQString strLevel;
	for(int i=0; i<suns; i++){
		strLevel += strSun;
	}
	for(int i=0; i<moons; i++){
		strLevel += strMoon;
	}
	for(int i=0; i<stars; i++){
		strLevel += strStar;
	}
	qwUserInfo->lblLevelDisplay->setText("(" + TQString::number(level) + ")" + strLevel);
	qwUserInfo->lblLevelDisplay->adjustSize();
	//lE_Num->setReadOnly(true);
	if (toShow)
	{
		qwUserInfo->leNumber->setText( details[0] );			
		qwUserInfo->leNickName->setText( details[1]);
		qwUserInfo->leAge->setText( details[7] );
		qwUserInfo->leSex->setText( details[8] );
		qwUserInfo->leArea->setText( details[2] );
		qwUserInfo->leProvince->setText( details[3] ); 
		qwUserInfo->leCity->setText( details[25] );
		
		bool ok;
		int faceId = details[21].toInt(&ok, 10);
		if(ok){
			selectedFaceIndex = faceId;
			TQPixmap *pix = faces->getUserHeadPixmap(id);
			if(!pix) pix = faces->getFace(faces->getFaceFileIndex(faceId));
			if(pix) qwUserInfo->lblFace->setPixmap( *pix );
		}else
			selectedFaceIndex = 0;

		qwUserInfo->leEmail->setText( details[10] );
		qwUserInfo->leAddress->setText( details[5] );
		qwUserInfo->leZipCode->setText( details[4] );
        	qwUserInfo->lePhone->setText( details[6] );
		qwUserInfo->leMobile->setText( details[22]);
		
		qwUserInfo->leRealName->setText( details[9]);
        	qwUserInfo->leSchool->setText( details[31] );
		qwUserInfo->leOccupation->setText( details[16] );
		qwUserInfo->leHomePage->setText( details[17] );
		qwUserInfo->teAboutMe->setText( details[24] );
		qwUserInfo->teSignature->setText(signature);
		
		
		TQStringList ZodiacList( TQString::null );
		TQStringList BloodList( TQString::null );
		TQStringList HoroscapeList( TQString::null );
		
		
		ZodiacList += ( i18n( "Rat" ) );
		ZodiacList += ( i18n( "Ox" ) );
		ZodiacList += ( i18n("Tiger" ) );
		ZodiacList += ( i18n("Rabbit" ) );
		ZodiacList += ( i18n("Dragon" ) );
		ZodiacList += ( i18n("Snake" ) );
		ZodiacList += ( i18n("Horse" ) );
		ZodiacList += ( i18n("Sheep" ) );
		ZodiacList += ( i18n("Monkey" ) );
		ZodiacList += ( i18n("Rooster" ) );
		ZodiacList += ( i18n("Dog" ) );
		ZodiacList += ( i18n("Pig" ) );
		
		BloodList += ( i18n("A" ) );
		BloodList += ( i18n("B" ) );
		BloodList += ( i18n("O" ) );
		BloodList += ( i18n("AB" ) );
		BloodList += ( i18n("Other" ) );
		
		HoroscapeList += ( i18n("Aquarius" ) );
		HoroscapeList += ( i18n("Pisces" ) );
		HoroscapeList += ( i18n("Aries" ) );
		HoroscapeList += ( i18n("Taurus" ) );
		HoroscapeList += ( i18n("Gemini" ) );
		HoroscapeList += ( i18n("Cancer" ) );
		HoroscapeList += ( i18n("Leo" ) );
		HoroscapeList += ( i18n("Virgo" ) );
		HoroscapeList += ( i18n("Libra" ) );
		HoroscapeList += ( i18n("Scoripio" ) );
		HoroscapeList += ( i18n("Sagittarius" ) );
		HoroscapeList += ( i18n("Capricorn" ) );

		qwUserInfo->leZodiac->setText( ZodiacList[ details[33].toInt()<0 ? 0: details[33].toInt()  ] ); 
		qwUserInfo->leBlood->setText( BloodList[ details[34].toInt() <0 ? 0: details[34].toInt() ] );
		qwUserInfo->leHoroscape->setText( HoroscapeList[ details[32].toInt() <0 ? 0: details[32].toInt() ] );
	}
	return true;
}

void EvaDetailsWindow::slotLinkClicked( const TQString & url )
{
	TQStringList args;
	args<<"exec"<< url;
	//kapp->tdeinitExec("kfmclient",args);
	KRun::runCommand("konqueror \""+url+"\"");
}

void EvaDetailsWindow::slotShopClicked( )
{
	TQString url = "http://jump.qq.com/clienturl_simp_17?clientuin=" + TQString::number(EvaMain::user->getQQ());
	url+="&clientkey=";
	url+=getClientKeyString();
	slotLinkClicked(url);
}

void EvaDetailsWindow::slotAlbumClicked( )
{
	TQString url = "http://ptlogin.qq.com/qqshowalbum?clientuin=" + TQString::number(EvaMain::user->getQQ());
	url+="&clientkey=";
	url+=getClientKeyString();
	slotLinkClicked(url);
}

const TQString EvaDetailsWindow::getClientKeyString()
{
	TQString key="";
	int len = Packet::getClientKeyLength();
	for(int i=0; i<len; i++){
		TQString tmp = TQString::number((unsigned char)(Packet::getClientKey()[i]), 16);
		if(tmp.length()==1)
			tmp = "0" + tmp;
		key+=tmp;
	}
	return key.upper();
}

void EvaDetailsWindow::slotUpdateTQQShow()
{
	emit requestTQQShow(id);
}

void EvaDetailsWindow::slotBuddyTQQShowReady(const unsigned int id)
{
	bool ok;
	unsigned int qq = details[0].toUInt(&ok, 10);
	if(!ok) return;
	if(id != qq) return;
	TQPixmap *pix = faces->getTQQShow(id);
	if(pix){
		lblTQQShow->setPixmap( *pix);
	}
}

void EvaDetailsWindow::slotCurrentChanged( TQWidget *wCurrentPage)
{
	if(!strcmp(wCurrentPage->name(), "TabMemo")){
		m_IsMemoPage = true;
		if(!frd) return;
		slotUpdateMemo( frd->getMemo() );
		pbUpdate->setText( i18n("Modify") );
	}
	else{
		m_IsMemoPage = false;
		pbUpdate->setText( i18n("Update"));
	}
}

void EvaDetailsWindow::slotDownloadMemo()
{
	if(!frd) return;
	emit requestDownloadMemo(frd->getQQ());
}

void EvaDetailsWindow::slotUpdateMemo(const MemoItem &memo)
{
	leMemoName->setText( codec->toUnicode(memo.name.c_str()) );
	leMemoMobile->setText( codec->toUnicode(memo.mobile.c_str()) );
	leMemoTelephone->setText( codec->toUnicode(memo.telephone.c_str()) );
	leMemoAddress->setText( codec->toUnicode(memo.address.c_str()) );
	leMemoEmail->setText( codec->toUnicode(memo.email.c_str()) );
	leMemoZipCode->setText( codec->toUnicode(memo.zipcode.c_str()) );
	teMemoNote->setText( codec->toUnicode(memo.note.c_str()) );
}

void EvaDetailsWindow::slotUploadMemoReply(const bool flag)
{
	if(flag)
		TQMessageBox::information(this, i18n( "Upload Memo"), i18n( "upload memo successfully"));
	else
		TQMessageBox::information(this, i18n( "Upload Memo"), i18n( "failed to upload memo."));
	
}

void EvaDetailsWindow::slotNoMemoFound()
{
	TQMessageBox::information(this, i18n( "Downlad Memo"), i18n( "no memo found on the server"));
}

void EvaDetailsWindow::closeEvent( TQCloseEvent * /*e*/ )
{
	deleteLater();
}

