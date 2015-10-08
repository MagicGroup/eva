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
  
#include "evachatwindow.h"
#include "customfaceselector.h"
#include "evafontselecter.h"

#include "evaresource.h"
#include "evamain.h"
#include "evauser.h"
#include "evausersetting.h"
#include "evafriendlist.h"
#include "evatextedit.h"
#include "evahtmlparser.h"
#include "evachatview.h"
#include "evaipseeker.h"
#include "evafilepanel.h"
#include "evafilestatusuibase.h"
#include "regiongrabber.h"
#include "evamainwindow.h"
#include "evahistoryviewer.h"
#include "evascriptmanager.h"

#include <ntqtextcodec.h>
#include <ntqrect.h>
#include <ntqlabel.h>
#include <ntqlayout.h>
#include <ntqiconset.h>
#include <ntqpixmap.h>
#include <ntqhostaddress.h>
#include <ntqevent.h>
#include <ntqpushbutton.h>
#include <ntqtoolbutton.h>
#include <ntqlineedit.h>
#include <ntqpopupmenu.h>
#include <ntqtooltip.h>
#include <ntqregexp.h>
#include <ntqdir.h>
#include <ntqfileinfo.h>
#include <ntqimage.h>
#include <ntquuid.h>
#include <ntqtimer.h>
#include <tdelocale.h>
#include <kurl.h>
#include <tdefiledialog.h>
#include <tdemessagebox.h>
#include <tdeapplication.h>
#include <stdio.h>

#ifndef TQQ_MSG_IM_MAX
#define TQQ_MSG_IM_MAX 15000
#endif

int EvaChatWindow::myQQ=0;
TQString EvaChatWindow::myName ="";
EvaImageResource *EvaChatWindow::images = NULL;
bool EvaChatWindow::isSentByEnter = false;

std::list<TQString> EvaChatWindow::tquickList;
	
EvaChatWindow::EvaChatWindow(TQQFriend * frd, TQWidget* parent, const char* name, WFlags fl)
	: EvaChatUIBase(parent, name, fl), smileyPopup(NULL), tquickMenu(NULL), fontSelecter(NULL),
	m_NumImages(0), grabber(NULL), viewer(NULL)
{
	//buddy = new TQQFriend(*frd);
	buddy = frd;
	codec = TQTextCodec::codecForName("GB18030");
	initObjects();
	initInformation();
	initConnection();
	graphicChanged();
	kteInput->setFocus();
}

EvaChatWindow::~EvaChatWindow()
{
	//delete buddy;
}

void EvaChatWindow::setupImages(EvaImageResource *res)
{
	if(!res) return;
	images = res;
}

void EvaChatWindow::setQuickReplyMessages(const std::list<TQString> &list) 
{ 
	tquickList = list; 
}

const unsigned int EvaChatWindow::getBuddyQQ()
{
	return buddy->getQQ();
}

void EvaChatWindow::graphicChanged()
{
	TQStringList imageDirList;
	imageDirList.append(images->getSmileyPath());
	imageDirList.append(EvaMain::user->getSetting()->getPictureCacheDir());
	kteInput->mimeSourceFactory()->setFilePath(imageDirList);

	
	tbSmiley->setIconSet(*(images->getIcon("SMILEY")));
	tbFont->setIconSet(*(images->getIcon("FONT")));
	tbFile->setIconSet(*(images->getIcon("FILE_TRANSFER")));
	tbB->setIconSet(*(images->getIcon("FONT_B")));
	tbU->setIconSet(*(images->getIcon("FONT_U")));
	tbI->setIconSet(*(images->getIcon("FONT_I")));
	tbAddImage->setIconSet(*(images->getIcon("SEND_IMAGE")));
	tbScreenShot->setIconSet(*(images->getIcon("SCREEN_SHOT")));
	tbQuickReply->setIconSet(*(images->getIcon("QUICK_REPLY")));
	tbEnableSound->setIconSet(*(images->getIcon("SYSTEM_MSG")));
	tbHideShows->setIconSet(*(images->getIcon("HIDE_PORTRAIT")));
	slotBuddyTQQShowReady(getBuddyQQ());
	slotMyTQQShowReady();
}

void EvaChatWindow::initObjects()
{
	if(fontSelecter) delete fontSelecter;
	fontSelecter = new EvaFontSelecter(this);
	if(smileyPopup) delete smileyPopup;
	smileyPopup = new CustomFaceSelector();
	
	tquickMenu = new TQPopupMenu(tbQuickReply);
	if(tquickList.size()){	
		std::list<TQString>::iterator iter;
		int index = 0;
		for(iter=tquickList.begin(); iter!=tquickList.end(); ++iter)
			tquickMenu->insertItem(*iter, index++);
		tbQuickReply->setPopup(tquickMenu);
		tbQuickReply->setPopupDelay(10);
		TQObject::connect(tquickMenu, SIGNAL(activated(int)), this,  SLOT(slotQuickReplyActivated(int)));
	}
	
	sendKey = new TQPopupMenu();
	sendKey->setCheckable(true);
	sendKey->insertItem(i18n("Press \"Enter\" to Send"),this,SLOT(setEnterSend()),SHIFT+ALT+Key_Enter,1);  
	sendKey->insertItem(i18n("Press \"Ctrl+Enter\" to Send"),this, SLOT(setCtrlEnterSend()),SHIFT+CTRL+ALT+Key_Enter,2);
	if(isSentByEnter)
		sendKey->setItemChecked(1,true);
	else
		sendKey->setItemChecked(2,true);
	pbSendKey->setPopup(sendKey); 
	kteInput->setEnterSendEnabled(isSentByEnter);
}

void EvaChatWindow::initInformation()
{
	if(!buddy) return;
	TQString nick = codec->toUnicode(buddy->getNick().c_str());
	TQString title = TQString(i18n("Chatting with %1")).arg(nick);
	setCaption(title);
	TQString status =i18n("(offline)");
	TQIconSet face;
	int faceId = buddy->getFace();
	TQPixmap *faceOnPic=NULL, *faceOffPic=NULL;
	if(buddy->hasUserHead()){
		faceOnPic = images->getUserHeadPixmap(buddy->getQQ());
		faceOffPic = images->getUserHeadPixmap(buddy->getQQ(), true); // true means grayscale true
	}
	if(!faceOnPic || !faceOffPic){
		faceOnPic = images->getFace(images->getFaceFileIndex(faceId));
		faceOffPic = images->getFace(images->getFaceFileIndex(faceId), false); // false means on-line off
	}
	setIcon(*faceOnPic);
	
	face.setPixmap(*faceOffPic,TQIconSet::Large);
	tbBuddy->setIconSet(face);
	switch(buddy->getStatus()){
	case 10:
		status = i18n("(online)");
		face.setPixmap(*faceOnPic,TQIconSet::Large);
		tbBuddy->setIconSet(face);
		break;
	case 20:
		//status = i18n("(offline)");
		//face.setPixmap(*(images->getFace(images->getFaceFileIndex(faceId), false)),TQIconSet::Large);
		//tbBuddy->setIconSet(face);
		break;
	case 30:{
		status = i18n("(leave)");
		TQPixmap pixleave(*faceOnPic);
		TQPixmap pixna(*(images->getIcon("NA")));
		copyBlt(&pixleave, pixleave.width()-pixna.width(),pixleave.height()-pixna.height(), 
			&pixna,0,0, pixna.width(), pixna.height());
		face.setPixmap(pixleave, TQIconSet::Large);
		tbBuddy->setIconSet(face);
		}
		break;
	case 40:
		status = i18n("(invisible)");
		face.setPixmap(*faceOffPic, TQIconSet::Large);
		tbBuddy->setIconSet(face);
		break;
	}
	tbBuddy->setTextLabel(nick);
	TQToolTip::add(tbBuddy, nick + "("+TQString::number(buddy->getQQ()) +") " + status);
	
	TQString ip = TQHostAddress(buddy->getIP()).toString();
	EvaIPSeeker ipAddr(EvaGlobal::getDirPath().latin1());
	TQString addr = codec->toUnicode(ipAddr.getIPLocation(ip.latin1()).c_str());
	leIP->setText(addr);
	
	TQString sig = codec->toUnicode(buddy->getSignature().c_str());
	lblSignature->setText("  " + sig);
	
	//TQString port = TQString::number(((int)(buddy->getPort()))==-1?0:(unsigned int)(buddy->getPort()));
	TQToolTip::add(leIP, ip + " : " + TQString::number(buddy->getPort()));
	
}

void EvaChatWindow::initConnection()
{
	if(smileyPopup) {
		connect(smileyPopup, SIGNAL(selectSysFace(int)), this, SLOT(slotSmileySelected(int)));
		// we might need the following later on
		//connect(smileyPopup, SIGNAL(selectCustomFace(const TQString &)), this, SLOT(slotAddImageToInputEdit(const TQString &)));
	}

	TQObject::connect(tbBuddy, SIGNAL(clicked()), this, SLOT(slotTbBuddyClick()));
	TQObject::connect(tbSmiley, SIGNAL(clicked()), this, SLOT(slotSmileyClick()));
	TQObject::connect(tbFont, SIGNAL(clicked()), this, SLOT(slotFontClick()));
	TQObject::connect(tbFile, SIGNAL(clicked()), this, SLOT(slotFileClick()));
	TQObject::connect(tbAddImage, SIGNAL(clicked()), this, SLOT(slotAddImageClick()));
	TQObject::connect(tbScreenShot, SIGNAL(clicked()), this, SLOT(slotScreenShotClick()));
	TQObject::connect(tbQuickReply, SIGNAL(clicked()), this, SLOT(slotQuickReplyClick()));
	TQObject::connect(tbHideShows, SIGNAL(clicked()), this, SLOT(slotHideShowsClick()));
	TQObject::connect(pbHistory, SIGNAL(clicked()), this, SLOT(slotHistoryClick()));
	TQObject::connect(pbSendKey, SIGNAL(clicked()), this, SLOT(slotSendKeyClick()));
	TQObject::connect(pbSend, SIGNAL(clicked()), this, SLOT(slotSend()));
	TQObject::connect(tbShowBuddy, SIGNAL(clicked()), this, SLOT(slotTbShowBuddyClick()));
	TQObject::connect(tbShowMe, SIGNAL(clicked()), this, SLOT(slotTbShowMeClick()));
	TQObject::connect(kteInput, SIGNAL(keyPressed(TQKeyEvent *)), this, SLOT(slotInputKeyPress(TQKeyEvent *)));

	if(fontSelecter)
		TQObject::connect(fontSelecter, SIGNAL( fontChanged(TQColor, int)), this, SLOT(slotFontChanged( TQColor, int )));

	TQObject::connect(pbClose, SIGNAL(clicked()), this, SLOT(slotPbCloseClick()));

	TQObject::connect(chatDisplay, SIGNAL(fileTransferAcceptRequest(const unsigned int)), 
						SLOT(slotFileTransferAcceptClicked(const unsigned int)));
	TQObject::connect(chatDisplay, SIGNAL(fileTransferSaveAsRequest(const unsigned int)), 
						SLOT(slotFileTransferSaveAsClicked(const unsigned int)));
	TQObject::connect(chatDisplay, SIGNAL(fileTransferCancelRequest(const unsigned int)), 
						SLOT(slotFileTransferCancelClicked(const unsigned int)));
	TQObject::connect(chatDisplay, SIGNAL(fileTransferResume(const unsigned int, const bool)), 
						SLOT(slotFileTransferResume(const unsigned int, const bool)));

	TQObject::connect(m_FilePanel, SIGNAL(closeSession(const unsigned int)),
					SLOT(slotFilePanelCloseClicked( const unsigned int )));
}

void EvaChatWindow::displaySendingMessage()
{
	EvaHtmlParser parser;
	parser.setAbsImagePath(images->getSmileyPath());
	TQString text = kteInput->text();
	TQString tmp;
	parser.convertToPlainTxt(text, tmp);
	parser.convertToHtml(text,true, true);
	
	TQColor chatColor(buddy->getChatFontColor());
	int chatSize =  buddy->getChatFontSize();
	chatDisplay->append( myName, sendtime, TQt::darkCyan, true, chatColor, (char)chatSize, 
				tbU->isOn(), tbI->isOn(), tbB->isOn(), text);
	showMessages();
	//kteInput->setText("");
}

void EvaChatWindow::slotReceivedMessage(unsigned int sender, bool isNormal, TQString message, TQDateTime time, const char size, 
					const bool u, const bool i, const bool b, 
					const char blue, const char green, const char red)
{
	if(sender != buddy->getQQ()) return;
	TQString nick = codec->toUnicode(buddy->getNick().c_str());
	EvaHtmlParser parser;
	parser.setAbsImagePath(images->getSmileyPath());
	parser.convertToHtml(message, true, true);
	chatDisplay->append(nick, time, TQt::blue, isNormal,
				TQColor((TQ_UINT8)red, (TQ_UINT8)green,(TQ_UINT8)blue),
				size, u, i, b, message);
	if ( tbEnableSound->isOn() )
		EvaMain::global->getSoundResource()->playNewMessage();
}

void EvaChatWindow::showMessages()
{
	chatDisplay->showContents();
}

void EvaChatWindow::slotAddMessage(unsigned int , TQString sNick, unsigned int , TQString , bool isNormal, 
				TQString message, TQDateTime time, const char , 
				const bool , const bool , const bool , 
				const char , const char , const char )
{	
	if(!kteInput->isEnabled()) return;
	EvaHtmlParser parser;
	parser.convertToHtml(message, false, false, true);
	TQString msg = sNick + (isNormal?(""):i18n("(Auto-Reply)")) + "  " + time.toString("yyyy-MM-dd hh:mm:ss") + "<br />" + message;
	kteInput->append(msg);
}

void EvaChatWindow::slotSendResult(bool ok)
{
	if(!ok) {
		KMessageBox::information(this, i18n("message sent failed"), i18n("Message"));
	} else
		kteInput->setText("");
	pbSend->setEnabled(true);
	kteInput->setEnabled(true);
	//kteInput->setParagraphBackgroundColor(0, TQt::white);
	kteInput->setFocus();
}

void EvaChatWindow::slotBuddyTQQShowReady(const unsigned int id)
{
	if(id!= getBuddyQQ()) return;
	TQPixmap *pix = images->getTQQShow(id);
	if(pix){ 
		TQImage img = pix->convertToImage();
		tbShowBuddy->setIconSet(TQPixmap(img.smoothScale(tbShowBuddy->width()-8, tbShowBuddy->height() -2)));
	}
}

void EvaChatWindow::slotMyTQQShowReady()
{
	TQPixmap *pix = images->getTQQShow(myQQ);
	if(pix){
		TQImage img = pix->convertToImage();
		tbShowMe->setIconSet(TQPixmap(img.smoothScale(tbShowMe->width()-8, tbShowMe->height() -2)));
	}
}

void EvaChatWindow::slotSmileySelected(int fid)
{
	if(!kteInput->isEnabled()) return;
	TQString smiley = "<img src=\"" + TQString::number(fid) + ".gif\"> ";
	
	int para;
	int index;
	TQFont saveFont = kteInput->font();
	TQColor saveColor = kteInput->color();
	// determine the current position of the cursor
	kteInput->insert("\255", false, true, true);	
	kteInput->getCursorPosition(&para,&index);
	TQString txt = kteInput->text();
	txt.replace(TQRegExp("\255"),smiley);
	kteInput->setText(txt);
	kteInput->setCursorPosition(para, index);
	kteInput->setCurrentFont(saveFont);
	kteInput->setColor(saveColor);
}

void EvaChatWindow::slotTbBuddyClick()
{
	emit requestDetails(buddy->getQQ());
}

void EvaChatWindow::slotSmileyClick()
{
	if(smileyPopup){
		TQPoint p = kteInput->mapToGlobal(TQPoint(0,0));
		smileyPopup->setGeometry(p.x() + tbSmiley->x() , p.y(), smileyPopup->width(), smileyPopup->height());
		smileyPopup->show();
	}	
}

void EvaChatWindow::slotFontClick()
{
	if(!fontSelecter) return;
	if(fontSelecter->isVisible()) 
		fontSelecter->hide();
	else{
		TQPoint p = kteInput->mapToGlobal(TQPoint(0,0));
		fontSelecter->setColor( TQColor(buddy->getChatFontColor()));
		fontSelecter->setSize( buddy->getChatFontSize());
		fontSelecter->setGeometry(p.x() + tbFont->x() , p.y(), fontSelecter->width(), fontSelecter->height());
		fontSelecter->show();
 	}
}

void EvaChatWindow::slotQuickReplyClick()
{
	//tbQuickReply->openPopup();
	//tquickMenu->exec();
}

void EvaChatWindow::slotQuickReplyActivated(int id)
{
	if(!kteInput->isEnabled()) return;
	std::list<TQString>::iterator iter;
	int index = 0;
	for(iter=tquickList.begin(); iter!=tquickList.end(); ++iter){
		if(index == id) break;	
		index++;
	}
	TQString message = *iter;
	EvaHtmlParser parser;
	parser.convertToHtml(message, false);
	kteInput->append(message);	
	slotSend();
}

void EvaChatWindow::slotHideShowsClick()
{
	if(m_ShowFrame->isVisible()){
		//m_FilePanel->hide();
		m_FilePanelFrame->hide();
		m_ShowFrame->hide();
		//lblBuddyShow->hide();
		//tbShowBuddy->hide();
		//lblMeShow->hide();
		//tbShowMe->hide();
		EvaChatUIBaseLayout->removeItem(layout19);
		tbHideShows->setIconSet(*(images->getIcon("SHOW_PORTRAIT")));

		TQValueList<int> list;
		list.append(150);
		list.append(100);
		splitter->setSizes(list);
		resize( TQSize(320, 367).expandedTo(minimumSizeHint()) );
	}else{
		//m_FilePanel->show();
		m_FilePanelFrame->show();
		m_ShowFrame->show();
		//lblBuddyShow->show();
		//tbShowBuddy->show();
		//lblMeShow->show();
		//tbShowMe->show();
		EvaChatUIBaseLayout->addLayout(layout19);
		tbHideShows->setIconSet(*(images->getIcon("HIDE_PORTRAIT")));

		TQValueList<int> list;
		list.append(150);
		list.append(100);
		splitter->setSizes(list);
		resize( TQSize(450, 422).expandedTo(minimumSizeHint()) );
	}
}

void EvaChatWindow::slotHistoryClick()
{
//	emit requestHistory(getBuddyQQ());
	if ( !viewer )
	{
		TQString nick = codec->toUnicode(buddy->getNick().c_str());

		viewer = new EvaHistoryViewer(getBuddyQQ(), nick, EvaMain::user->getSetting());

		unsigned short faceId = buddy->getFace();
		TQPixmap *face = EvaMain::images->getFaceByID(faceId);
		viewer->setIcon(*face);

		connect(viewer, SIGNAL(historyDoubleClicked(unsigned int, TQString, unsigned int, TQString, bool,
						TQString, TQDateTime, const char,
						const bool, const bool, const bool,
						const char, const char, const char)),
				this,
				SLOT(slotAddMessage(unsigned int, TQString, unsigned int, TQString, bool,
						TQString, TQDateTime, const char,
						const bool, const bool, const bool,
						const char, const char, const char)));
		connect(viewer, SIGNAL(windowClosed()), this, SLOT(slotHistoryWindowClosed()));
	}
	if ( pbHistory->isOn() )
	{
		viewer->move(this->x(), this->y() + this->height() + 25);

		viewer->show();
	}
	else
	{
		viewer->hide();
	}
}

void EvaChatWindow::slotHistoryWindowClosed()
{
//	viewer->hide();
	pbHistory->setOn(FALSE);
}

void EvaChatWindow::slotSendKeyClick()
{
}

void EvaChatWindow::slotSend()
{
	if(!kteInput->isEnabled()) return;
	TQString msg = kteInput->text();
	EvaHtmlParser parser;
	parser.setAbsImagePath(images->getSmileyPath(), EvaMain::user->getSetting()->getPictureCacheDir());

	sendtime = TQDateTime::currentDateTime(TQt::LocalTime);

	TQString toSend = msg;
	TQString sendFileNameBase; 
	int numFiles = parser.convertToPlainTxt(toSend, sendFileNameBase);
	
	if(toSend == ""){
		KMessageBox::information(this, i18n("Cannot send empty message."), i18n("Message"));
		return;
	}
	if(strlen(toSend.ascii()) > TQQ_MSG_IM_MAX){
		KMessageBox::information(this, i18n("Message is too long, cannot send."), i18n("Message"));
		return;
	}

	pbSend->setEnabled(false);
	kteInput->setEnabled(false);

	TQColor chatColor(buddy->getChatFontColor());
	int chatSize =  buddy->getChatFontSize();
	if(numFiles){
		TQString strToShow = msg;
		parser.parseToAbsPath(strToShow, EvaMain::user->getSetting()->getPictureCacheDir());
		chatDisplay->append( myName, sendtime, TQt::darkCyan, true, chatColor, (char)chatSize, 
					tbU->isOn(), tbI->isOn(), tbB->isOn(), strToShow);
		showMessages();
		m_NumImages = numFiles;
		//kteInput->setText("");
	}else	
		displaySendingMessage();
	
	EvaMainWindow *mainWin = EvaMain::g_mainWin;
	if(mainWin)
		mainWin->addBuddyToRecentList( getBuddyQQ(), true);
	emit sendMessage(getBuddyQQ(), true, toSend, (char)chatSize, tbU->isOn(), tbI->isOn(), tbB->isOn(),
			(char)(chatColor.blue()) , (char)(chatColor.green()), (char)(chatColor.red()));

	if(numFiles){		
		TQValueList<TQString> nameList;
		TQValueList<unsigned int> sizeList;
		unsigned int session = buddy->getNextSequence();
		for(int i=0; i<numFiles; i++){
			TQString name = sendFileNameBase + TQString::number(i) + ".jpg";
			TQString fullname = EvaMain::user->getSetting()->getPictureCacheDir() + "/" + name;
					
			TQFileInfo info(fullname);
			nameList.append(fullname);
			sizeList.append(info.size());
		}
		
		emit fileTransferSend(buddy->getQQ(), session, nameList, sizeList, TQQ_TRANSFER_IMAGE);
	}
	//kteInput->setParagraphBackgroundColor(0, TQt::gray);
}

void EvaChatWindow::slotTbShowBuddyClick()
{
	emit requestBuddyTQQShow(getBuddyQQ());
}

void EvaChatWindow::slotTbShowMeClick()
{
	emit requestMyTQQShow();
}

void EvaChatWindow::slotInputKeyPress(TQKeyEvent *e)
{
	if(isSentByEnter && ((e->key() == TQt::Key_Enter) || (e->key() == TQt::Key_Return) ) && (e->state() == TQt::NoButton) ){
		e->accept();
		slotSend();
	}else{
		if( !(isSentByEnter) &&
			( (e->key() == TQt::Key_Enter) || (e->key() == TQt::Key_Return) ) && 
			( (e->state() & TQt::ControlButton)==TQt::ControlButton)    ){
		e->accept();
		slotSend();
		}
	}
}

void EvaChatWindow::slotFontChanged(TQColor color, int size)
{
// 	int fontSize = size;
// 	int fontColor = color;
	buddy->setChatFontSize(size);
	buddy->setChatFontColor(color.rgb());
	printf("setting color: %s size: %d\n", color.name().ascii(), size);
	//TQColor c=color;
	//TQString s=c.name();
	EvaMain::user->saveGroupedBuddyList();
}

void EvaChatWindow::setEnterSend()
{
	isSentByEnter = true;
	sendKey->setItemChecked(1,true);
	sendKey->setItemChecked(2,false);
	kteInput->setEnterSendEnabled(isSentByEnter);
}

void EvaChatWindow::setCtrlEnterSend()
{
	isSentByEnter = false;
	sendKey->setItemChecked(1,false);
	sendKey->setItemChecked(2,true);
	kteInput->setEnterSendEnabled(isSentByEnter);
}

void EvaChatWindow::slotPbCloseClick()
{
	close();
}

void EvaChatWindow::openSendFileDialog()
{
	slotFileClick();
}

void EvaChatWindow::slotFileClick( )
{
	if(!kteInput->isEnabled()) return;
	TQString destDir = TQDir::homeDirPath();
	TQString fullname = KFileDialog::getOpenFileName(destDir,
			"* *.png |" + i18n(" all files (*)"), this, 
			i18n("select a file"));	
	TQString name = fullname.right(fullname.length() - fullname.findRev("/") -1);
	TQFileInfo info(fullname);
	if(!fullname.isEmpty()){
		unsigned int session = buddy->getNextSequence();
		printf("EvaChatWindow::slotFileClick -- next seq: %d\n", session);
		chatDisplay->showFileNotification(codec->toUnicode(buddy->getNick().c_str()),
				name, info.size(), session, true);
		if(!addToFileList(session, name)) return ; // we've already got this request
		m_FileNoList[session] = session;
		TQValueList<TQString> nameList;
		nameList.append(fullname);
		TQValueList<unsigned int> sizeList;
		sizeList.append(info.size());

		EvaMainWindow *mainWin = EvaMain::g_mainWin;
		if(mainWin)
			mainWin->addBuddyToRecentList( buddy->getQQ(), true);
		emit fileTransferSend(buddy->getQQ(), session, nameList, sizeList, TQQ_TRANSFER_FILE);
	}
}

void EvaChatWindow::slotReceivedFileRequest( const unsigned int session, const TQString & file,
					const int size, const unsigned char transferType )
{	
	if(transferType == TQQ_TRANSFER_IMAGE){
		switch(EvaMain::user->getStatus()){
		case EvaUser::Eva_Online:
		case EvaUser::Eva_Leave:
			m_NumImages++;
			emit fileTransferAccept(buddy->getQQ(), session, "", TQQ_TRANSFER_IMAGE);
			break;
		case EvaUser::Eva_Offline: // impossible
		case EvaUser::Eva_Invisible:
			printf("EvaChatWindow::slotReceivedFileRequest --id:%d, seq: %d\n", buddy->getQQ(), buddy->getSequence());
			if(buddy->getSequence()){
				m_NumImages++;
				printf("now I accepted\n");
				emit fileTransferAccept(buddy->getQQ(), session, "", TQQ_TRANSFER_IMAGE);
			}
			break;
		default:
			emit fileTransferCancel(buddy->getQQ(), session);
		}
		return;
	}
	if(!addToFileList(session, file)) return ; // we've already got this request
	m_FileNoList[session] = session;
	if(transferType == TQQ_TRANSFER_FILE){
		EvaMainWindow *mainWin = EvaMain::g_mainWin;
		if(mainWin)
			mainWin->addBuddyToRecentList( getBuddyQQ(), true);
		chatDisplay->showFileNotification(codec->toUnicode(buddy->getNick().c_str()),
					file, size, session, false);
	}
}

void EvaChatWindow::slotFileTransferAcceptClicked( const unsigned int showSession)
{	
	TQString msg = i18n("You have accepted transferring \"%1\", network connecting start, please wait...").arg(getFileName(getSession(showSession)));
	chatDisplay->showInfomation(msg);
	emit fileTransferAccept(buddy->getQQ(), getSession(showSession), "", TQQ_TRANSFER_FILE);
}

void EvaChatWindow::slotFileTransferSaveAsClicked( const unsigned int showSession )
{
	unsigned int session = getSession(showSession);
	TQString name = getFileName(session);
	TQString destDir = TQDir::homeDirPath() + "/" + name;
	TQString fullname = KFileDialog::getSaveFileName(destDir,
			"* |" + i18n(" all files (*)"), this, 
			i18n("Save As"));
	TQString dir = fullname.left(fullname.findRev("/"));
	//TQFileInfo info(fullname);
	if(!dir.isEmpty()){
		TQString msg = i18n("You have accepted transferring \"%1\", network connecting start, please wait...").arg(getFileName(getSession(showSession)));
		chatDisplay->showInfomation(msg);
		emit fileTransferAccept(buddy->getQQ(), session, dir, TQQ_TRANSFER_FILE);
	}
}

void EvaChatWindow::slotFileTransferCancelClicked( const unsigned int showSession)
{
	printf("EvaChatWindow::slotFileTransferCancelClicked -- \n");
	TQString msg = i18n("You have cancelled transferring \"%1\".").arg(getFileName(getSession(showSession)));
	chatDisplay->showInfomation(msg);
	emit fileTransferCancel(buddy->getQQ(), getSession(showSession));
	removeFromFileList(getSession(showSession));
	m_FilePanel->closeTab( getSession( showSession));
}

void EvaChatWindow::slotReceivedFileAccepted(const unsigned int session, const bool isAccepted, 
					const unsigned char transferType )
{
	TQString filename = getFileName(session);
	if(filename.isEmpty()) return; // we haven't got the request

	if(!isAccepted) removeFromFileList(session);

	if(isAccepted && transferType == TQQ_TRANSFER_IMAGE)
		return;
	
	TQString name = codec->toUnicode(buddy->getNick().c_str());
	TQString action = isAccepted ? i18n("accepted") : i18n("stopped");
	TQString msg = i18n("%1 has %2 transferring \"%3\".").arg(name).arg(action).arg(filename);
	chatDisplay->showInfomation(msg);
}

TQString EvaChatWindow::getFileName( const unsigned int session )
{
	TQMap<unsigned int, TQString>::Iterator iter = m_FileList.find(session);
	if(iter == m_FileList.end()) return "";
	return iter.data();
}

const bool EvaChatWindow::addToFileList( const unsigned int session, const TQString filename )
{
	TQString file = getFileName(session);
	if(!file.isEmpty()) return false; // if exists  return false;
	m_FileList[session] = filename;
	return true;
}

const unsigned int EvaChatWindow::getSession(const unsigned int showSession)
{
	TQMap<unsigned int, unsigned int>::Iterator iter;
	for(iter = m_FileNoList.begin(); iter!=m_FileNoList.end(); ++iter){
		if(iter.data() == showSession ) return iter.key();
	}
	return 0;
}

void EvaChatWindow::removeFromFileList( const unsigned int session )
{
	m_FileList.remove(session);
	m_FileNoList.remove(session);
}

void EvaChatWindow::slotSessionChangedTo( const unsigned int oldSession, const unsigned int newSession )
{
	TQString file = getFileName(oldSession);
	if(file.isEmpty()) return; // if not existed, return
	removeFromFileList(oldSession);
	addToFileList(newSession, file);
	m_FileNoList[newSession] = oldSession;
}

void EvaChatWindow::slotFileNotifyNormalInfo( const unsigned int session, EvaFileStatus status, 
					const TQString dir, const TQString filename, const unsigned int /*size */,
					const unsigned char transferType)
{
	switch(status){
	case ESNone:
		break;
	case ESError:{
		TQString msg = i18n("network lost connection or your friend has stopped transferring \"%1\".").arg(filename);
		switch(transferType){
		case TQQ_TRANSFER_FILE:{
			if(getFileName(session).isEmpty()) break;
			chatDisplay->showInfomation(msg);
			removeFromFileList(session);
			emit fileTransferCancel(buddy->getQQ(), session);
			}
			break;
		case TQQ_TRANSFER_IMAGE:{
			m_NumImages--;
			TQString num = filename.mid(filename.length() - 5, 1);
			bool ok;
			unsigned int n = num.toUInt(&ok);
			if(!ok) break;
			TQString file = getFileName(session * 100 + n);
			if(file.isEmpty()) break;
			chatDisplay->showInfomation(msg);
			emit fileTransferCancel(buddy->getQQ(), session);
			}
			break;
		default:
			break; // impossible, compiler would like this
		}
		}
		m_FilePanel->closeTab( session);
		break;
	case ESResume:
		chatDisplay->askResumeMode(filename, session);
		break;
	case ESSendFinished:{
		TQString msg = i18n("sending \"%1\" finished.").arg(filename);
		switch(transferType){
		case TQQ_TRANSFER_FILE:
			chatDisplay->showInfomation(msg);
			removeFromFileList(session);
			break;
		case TQQ_TRANSFER_IMAGE:{
			m_NumImages--;
			}
			break;
		default:
			removeFromFileList(session);
		}
		}
		break;
	case ESReceiveFinished:{
		TQString fullname = dir + "/" + filename;
		TQString msg = "";
		switch(transferType){
		case TQQ_TRANSFER_FILE:{
			removeFromFileList(session);
			TQString fileLink = "<a href = \"file://" + fullname + "\">" + fullname + "</a>";
			msg = i18n("receiving file \"%1\" has been finished and saved in %2").arg(filename).arg(fileLink);
			}
			break;
		case TQQ_TRANSFER_IMAGE:{
			m_NumImages--;
			chatDisplay->updatePicture(fullname, "/t_" + filename);
			return;
			}
			break; // make compiler happy
		default:
			return;
		}
		chatDisplay->showInfomation(msg);
		removeFromFileList(session);
		}
		break;
	default:
		break;
	}
}

void EvaChatWindow::slotFileTransferResume( const unsigned int session, const bool isResume)
{
	emit fileTransferResume(buddy->getQQ(), session, isResume);
}

void EvaChatWindow::slotFileStatusNotification( const unsigned int session, const KURL & url, 
						const unsigned int size, const unsigned int bytes, 
						const unsigned int time )
{
	if(!m_ShowFrame->isVisible()) slotHideShowsClick();
	m_FilePanel->updateStatus(session, url, size, bytes, time);
}

void EvaChatWindow::slotFilePanelCloseClicked( const unsigned int session)
{
	printf("EvaChatWindow::slotFilePanelCloseClicked\n");
	removeFromFileList(session);
	emit fileTransferCancel(buddy->getQQ(), session);
}

void EvaChatWindow::closeEvent( TQCloseEvent * e )
{
	if(m_FileList.size() && m_NumImages && KMessageBox::questionYesNo(this,
			i18n("File transfer is still in process (%1 file(s) left). Closing this window "
				"will also stop those transfer processes. "
				"Do you want to close this window?").arg(m_FileList.size()),
			i18n("Close Window?")) == KMessageBox::No){
		e->ignore();
	} else{
		TQMap<unsigned int, TQString>::Iterator iter;
		for(iter = m_FileList.begin(); iter!=m_FileList.end(); ++iter){
			emit fileTransferCancel(buddy->getQQ(), iter.key());
		}
		if (viewer)
			delete viewer;
		e->accept();
	}
}

void EvaChatWindow::slotAddImageClick( )
{
	if(!kteInput->isEnabled()) return;
	TQString destDir = TQDir::homeDirPath();
	TQString srcFullName = KFileDialog::getOpenFileName(destDir,
			"*.png *.bmp *.jpg *.jpeg *.gif |" + i18n(" all images (*.png *.bmp *.jpg *.jpeg *.gif)"), this, 
			i18n("select an image file"));
	if(!srcFullName.isEmpty()){
// 		if(!m_NumImages){
// 			m_ImageFileName = TQUuid::createUuid().toString().upper();
// 		}
		//TQString destFile = m_ImageFileName + TQString::number(m_NumImages) + ".jpg";
		TQString destFile = TQUuid::createUuid().toString().upper() + ".jpg";
		TQString destFullName = EvaMain::user->getSetting()->getPictureCacheDir() + "/" + destFile ;
		TQPixmap pix(srcFullName);
		pix.save(destFullName, "JPEG", 100);
		slotAddImageToInputEdit(destFile);
		//m_NumImages++;
	}
}

void EvaChatWindow::slotAddImageToInputEdit( const TQString & destFile)
{
	if(!kteInput->isEnabled()) return;
	if(destFile.isEmpty()) return;
	
	TQString smiley = "<img src=\"" + destFile + "\">";
	int para;
	int index;
	TQFont saveFont = kteInput->font();
	TQColor saveColor = kteInput->color();
	// determine the current position of the cursor
	kteInput->insert("\255", false, true, true);
	kteInput->getCursorPosition(&para,&index);
	TQString txt = kteInput->text();
	txt.replace(TQRegExp("\255"),smiley);
	kteInput->setText(txt);
	kteInput->setCursorPosition(para, index);
	kteInput->setCurrentFont(saveFont);
	kteInput->setColor(saveColor);
}

void EvaChatWindow::slotScreenShotClick( )
{
	if(!kteInput->isEnabled()) return;
	if(grabber) delete grabber;
	grabber = new RegionGrabber();
	connect( grabber, SIGNAL( regionGrabbed( const TQPixmap & ) ),
		SLOT( slotRegionGrabbed( const TQPixmap & ) ) );
}

void EvaChatWindow::slotRegionGrabbed( const TQPixmap & pix )
{
	if ( !pix.isNull() ){
// 		if(!m_NumImages){
// 			m_ImageFileName = TQUuid::createUuid().toString().upper();
// 		}
		
		//TQString destFile = m_ImageFileName + TQString::number(m_NumImages) + ".jpg";
		TQString destFile = TQUuid::createUuid().toString().upper() + ".jpg";
		TQString destFullName = EvaMain::user->getSetting()->getPictureCacheDir() + "/" + destFile ;
		pix.save(destFullName, "JPEG", 100);
		slotAddImageToInputEdit(destFile);
		//m_NumImages++;
	}
	
	if(grabber) delete grabber;
	grabber = NULL;
	TQApplication::restoreOverrideCursor();
}

void EvaChatWindow::appendText( const TQString & txt )
{
	if(!kteInput->isEnabled()) return;
	kteInput->append(  txt );
}

void EvaChatWindow::addToolButton( TQString & scriptName, TQString buttonName, TQString & pixmap, TQString & tip )
{
	printf("EvaChatWindow::addToolButton\n");
	if(m_btnMap.find(buttonName) != m_btnMap.end()) return;
	
	printf("EvaChatWindow::addToolButton ------- \n");
	
	TQPixmap p(pixmap);
	if(p.isNull()){
		TQPixmap *icon = images->getIcon("SCRIPT");
		if(icon)
			p = *icon;
	}
	TQToolButton *btn = new TQToolButton( lowerLayoutWidget, buttonName.local8Bit().data() );
	btn->setSizePolicy( TQSizePolicy( (TQSizePolicy::SizeType)0, (TQSizePolicy::SizeType)0, 0, 0,
											btn->sizePolicy().hasHeightForWidth() ) );
	btn->setMinimumSize( TQSize( 24, 24 ) );
	btn->setMaximumSize( TQSize( 24, 24 ) );
	btn->setAutoRaise( true );
	btn->setIconSet(p);
	TQToolTip::add( btn, tip );
	layout3->addWidget( btn );
	TQObject::connect(btn, SIGNAL(clicked()), SLOT(slotCustomBtnClick()));
	m_btnMap[buttonName] = btn;
	m_scriptMap[buttonName] = scriptName;
}

void EvaChatWindow::removeToolButton( TQString & /*scriptName*/, TQString buttonName )
{
	TQMap<TQString, TQToolButton*>::Iterator it = m_btnMap.find(buttonName);
	if( it == m_btnMap.end()) return;
	layout3->remove(it.data());
	delete it.data();
	m_btnMap.erase(it);
	
	TQMap<TQString, TQString>::Iterator itr = m_scriptMap.find(buttonName);
	if( itr == m_scriptMap.end()) return;
	m_scriptMap.erase(itr);
}

void EvaChatWindow::slotCustomBtnClick( )
{
	const TQObject *obj = TQObject::sender();
	TQString name = TQString::fromLocal8Bit( obj->name());
	printf("sender : %s\n", name.local8Bit().data());
	if(m_scriptMap.find(name) == m_scriptMap.end()) return;
	printf("slotCustomBtnClick : %s\n", name.local8Bit().data());
	GetScriptManager()->customMenuClicked(false, buddy->getQQ(), m_scriptMap[name], name); // script name, button name
}


