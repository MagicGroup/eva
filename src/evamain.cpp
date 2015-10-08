/***************************************************************************
 *   Copyright (C) 2004 by yunfan                                          *
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


#include "evamain.h"

#include "evautil.h"

#include "evaapi.h"

#include "evaui.h"

#include "evachatwindowmanager.h"
#include "evasystemtray.h"
#include "evaaddingmanager.h"
#include "evasysmsgmanager.h"
#include "evaloginmanager.h"
#include "evacontactmanager.h"
#include "evascriptmanager.h"

#include "evaidt.h"

#include <unistd.h>
#include <ntqimage.h>
#include <ntqtimer.h>
#include <ntqtextcodec.h>
#include <ntqdatetime.h>
#include <ntqhostaddress.h>
#include <ntqtabwidget.h>
#include <ntqcombobox.h>
#include <ntqlineedit.h>
#include <ntqcheckbox.h>
#include <ntqvaluelist.h>
#include <ntquuid.h>
#include <ntqdir.h>

#include <dcopclient.h>  ///DCOPClient
#include <tdeapplication.h>
#include <tdecmdlineargs.h>
#include <tdeaboutapplication.h>
#include <kglobalaccel.h>
#include <twin.h>
#include <tdemessagebox.h>
#include <khelpmenu.h>
#include <tdepopupmenu.h>
#include <kiconloader.h>
#include <kdebug.h>
#include <tdeconfig.h>
#include <assert.h>

#define MaxRetryTimes  5

EvaMain * g_eva = NULL;
		
		
EvaUser *EvaMain::user = NULL;
EvaGlobal *EvaMain::global = NULL;
EvaImageResource *EvaMain::images = NULL;
EvaHelper *EvaMain::helper = NULL;
EvaConnecter *EvaMain::connecter = NULL;
EvaPicManager *EvaMain::picManager = NULL;
EvaUHManager *EvaMain::uhManager = NULL;
EvaAddingManager *EvaMain::g_AddingManager = NULL;
EvaChatWindowManager *EvaMain::g_ChatWindowManager = NULL;
EvaMainWindow *EvaMain::g_mainWin = NULL;

EvaMain::EvaMain() :
	DCOPObject("Actions"),
	m_FileManager(NULL),
	packetManager(NULL),
	m_SysMsgManager(NULL),
	numOfLostKeepAlivePackets(0),
	sysMenu(NULL),
	statusMenu(NULL),
	autoMenu(NULL),
	accelKey(NULL)
{
	g_eva = this;
	
	//loggedIn=false;
	isClientSet=false;
	numLoginRetry = 0;
	deleteFromQQ = -1;
	m_IsShowingGroups = false;
	inIdleStatus = false;
	EvaUtil::initMap();
	codec = TQTextCodec::codecForName("GB18030");
	onlineFriendTimer = new TQTimer();
	initSettings();// load image first
	loginWin = new EvaLoginWindow(0);
	g_mainWin = new EvaMainWindow(0);
	tray = new EvaSystemTray(g_mainWin);
	helper = new EvaHelper();
	idt = new IdleTimeDetector(5);
	if(!doInitUI()){
		doQuit();
	}

	if( !kapp->dcopClient()->isRegistered()){
		kapp->dcopClient()->registerAs("evadcop");
		kapp->dcopClient()->setDefaultObject( objId() );
	}
	doSlotConnection();
	processCLIArgs();
}

EvaMain::~EvaMain()
{
	if(uhManager){
		uhManager->stop();
		uhManager->wait();
		delete uhManager;
		uhManager = 0;
	}
	if(picManager){
		delete picManager;
		picManager = 0;
	}
	if(g_AddingManager){
		delete g_AddingManager;
		g_AddingManager = 0;
	}
	if(onlineFriendTimer->isActive())
		onlineFriendTimer->stop();
	if(GetLoginManager()->isLoggedIn() || packetManager)
		packetManager->doLogout();

	GetScriptManager()->releaseScripts();
	
	delete loginWin;
	delete g_mainWin;
	delete packetManager;

	if(m_SysMsgManager){
		delete m_SysMsgManager;
	}
	
	if(global) delete global;
	if(helper->running())
		helper->terminate();
	delete helper;
	if(m_FileManager){
		m_FileManager->stopAll();
		delete m_FileManager;
	}
	if(idt) delete idt;

	if(user){
		user->getSetting()->setWinGeometry(g_mainWin->getPosition(), g_mainWin->getSize());
		user->getSetting()->saveSettings();
		delete user;
		user = 0;
	}
}

void EvaMain::processCLIArgs()
{
	TDECmdLineArgs *args = TDECmdLineArgs::parsedArgs();

	if(args->isSet("last"))
		loginWin->loginClickSlot();
	else{
		TQCString user, password;
		bool ok = false;
		user  = args->getOption("user");
		if(!user.isEmpty()) {
			//unsigned int id = user.toUInt(&ok);
			if(!ok){
				printf(I18N_NOOP("username must be in numeric format.\n"));
				TQTimer::singleShot(200, this, SLOT(doQuit()));
				return;
			}
			password = args->getOption("passwd");
			if(password.isEmpty()){
				printf(I18N_NOOP("password missing, type \"eva --help\" to see details.\n"));
				TQTimer::singleShot(200, this, SLOT(doQuit()));
				return;
			}
			loginWin->cbQQ->setCurrentText(TQString(user.data()));
			loginWin->lePwd->setText(TQString(password.data()));
			loginWin->slotPasswordChanged(TQString(password.data()));
			
			if(args->isSet("hide")) 
				loginWin->chbLoginMode->setChecked(true);
			else 
				loginWin->chbLoginMode->setChecked(false);

			if(args->isSet("remember")) 
				loginWin->chbRecordPwd->setChecked(true);
			else 
				loginWin->chbRecordPwd->setChecked(false);

			TQCString mode = args->getOption("mode");
			
			if(mode.isEmpty()) mode = "UDP";
			if(mode == "UDP")
				loginWin->cbbLoginType->setCurrentItem(0);
			else	if(mode == "TCP") 
						loginWin->cbbLoginType->setCurrentItem(1);
					else	if(mode == "HTTP_PROXY")
								loginWin->cbbLoginType->setCurrentItem(2);
							else {
								printf(I18N_NOOP("mode can only be one of UDP, TCP or HTTP_PROXY.\n"));
								TQTimer::singleShot(200, this, SLOT(doQuit()));
								return;
							}

			if(mode == "HTTP_PROXY"){
				TQCString ip, port;
				ip = args->getOption("pip");
				if(ip.isEmpty()) {
					printf(I18N_NOOP("http proxy server IP address missing.\n"));
					TQTimer::singleShot(200, this, SLOT(doQuit()));
					return;
				}
				port = args->getOption("pport");
				if(port.isEmpty()) {
					printf(I18N_NOOP("http proxy server port number missing.\n"));
					TQTimer::singleShot(200, this, SLOT(doQuit()));
					return;
				}
				TQHostAddress addr;
				if(!addr.setAddress(TQString(ip.data()))){
					printf(I18N_NOOP("http proxy server IP address is in wrong format.\n"));
					TQTimer::singleShot(200, this, SLOT(doQuit()));
					return;
				}
				bool ok = false;
			//	unsigned int pp = port.toUInt(&ok);
				if(!ok){
					printf(I18N_NOOP("http proxy server port number is in wrong format.\n"));
					TQTimer::singleShot(200, this, SLOT(doQuit()));
					return;
				}
				loginWin->leIP->setText(addr.toString());
				loginWin->lePort->setText(TQString(port.data()));
				TQCString puser, ppwd;
				puser = args->getOption("pu");
				if(!puser.isEmpty()) loginWin->slotProxyUserChanged(TQString(puser.data()));
				ppwd = args->getOption("ppw");
				if(!ppwd.isEmpty()) loginWin->slotProxyPasswordChanged(TQString(ppwd.data()));	
			}
			loginWin->loginClickSlot();
			//loginWin->show();
		} else
			loginWin->show();
	}	
	args->clear();
}

void EvaMain::initSettings()
{
	global = new EvaGlobal();
	if(!global->loadImage()) {
		KMessageBox::information(0, i18n("Sorry, image resource cannot be loaded properly, check image directory please."),
					i18n("Eva Initializing"));
		//exit(0);
		doQuit();
	}
	images = global->getImageResource();
	sysSetting = global->getEvaSetting();
	TQObject::connect(images, SIGNAL(qqShowReady(const unsigned int)), SLOT(slotTQQShowReady(const unsigned int)));
	
	// setup adding manager
	g_AddingManager = new EvaAddingManager();	

	m_SysMsgManager = new EvaSysMsgManager();
	//_wallet = 0;
}
/*
void EvaMain::slotLoadGroupedBuddiesReady()
{
	if(loggedIn) return;
	g_mainWin->updateBuddy(user->getQQ());
	g_ChatWindowManager->setMyName(nick, user->getQQ());

	g_mainWin->clearList();
	g_mainWin->updateContacts();
	
	tray->changeToolTip(user->getQQ(), nick, faceId);
}*/

void EvaMain::slotLoadQunListReady()
{
	g_mainWin->updateQuns();
	g_mainWin->updateRecentContacts();
}

// void EvaMain::doAbout()
// {
// 	TDEAboutApplication dlg(g_mainWin);
// 	dlg.exec();
// }

void EvaMain::doQuit()
{
	kdDebug() << "Quiting Eva..."<< endl;
	if(loginWin){
		loginWin->hide();
	}
	
	GetScriptManager()->releaseScripts();
	
	if(g_mainWin){
		g_mainWin->hide();
	}
	if(uhManager){
		uhManager->stop();
		uhManager->wait();
		delete uhManager;
		uhManager = 0;
	}
	if(picManager){
		delete picManager;
		picManager = 0;
	}
	if(g_AddingManager){
		delete g_AddingManager;
		g_AddingManager = 0;
	}
	if(m_SysMsgManager)
		delete m_SysMsgManager;

	if(onlineFriendTimer->isActive())
		onlineFriendTimer->stop();
	if(GetLoginManager()->isLoggedIn() || packetManager)
		packetManager->doLogout();

	
	if(user){
		user->getSetting()->setWinGeometry(g_mainWin->getPosition(), g_mainWin->getSize());
		user->getSetting()->saveSettings();
		delete user;
		user = 0;
	}
	
	kapp->quit();
	//TDEApplication::kApplication()->quit();
}

bool EvaMain::doInitUI()
{
	// login window	
	loginWin->setLogo(images->getIcon("EVALOGO"));
	loginWin->setIcon(*images->getIcon("EVA"));
	if(sysSetting){
		loginWin->setEvaSetting(sysSetting);
	}
	
	// main window
	initMenus();
	g_mainWin->setStatusMenu(statusMenu);
	g_mainWin->setSystemMenu(sysMenu);
	
	tray->setImagesResource(images);
	tray->setupMenus(sysMenu, statusMenu);
	
	EvaDetailsWindow::setImageResource(images);
	return true;
}

void EvaMain::initMenus()
{
	statusMenu = new TDEPopupMenu();
	statusMenu->insertItem(TQIconSet(*(images->getIcon("ONLINE"))), i18n("Online"), this,SLOT(slotDoOnline()), -1);
	statusMenu->insertItem(TQIconSet(*(images->getIcon("OFFLINE"))), i18n("Offline"), this,SLOT(slotDoOffline()), -1);
	statusMenu->insertItem(TQIconSet(*(images->getIcon("LEAVE"))), i18n("Leave"), this,SLOT(slotDoLeave()), -1);
	statusMenu->insertItem(TQIconSet(*(images->getIcon("INVISIBLE"))), i18n("Invisible"), this,SLOT(slotDoInvisible()), -1);
	
	sysMenu = new TDEPopupMenu();
	TDEPopupMenu *group = new TDEPopupMenu();

	group->insertItem(TQIconSet(*(images->getIcon("UPLOAD_GROUPS"))), i18n("Upload Group"),this, SLOT(slotDoUploadGroups()), -1);
	group->insertItem(TQIconSet(*(images->getIcon("DOWNLOAD_GROUPS"))), i18n("Download Group"),this, SLOT(slotDoDownloadGroups()), -1);
	
	sysMenu->insertItem(TQIconSet(*(images->getIcon("GROUP"))), i18n("Group"),group);
	sysMenu->insertItem(TQIconSet(*(images->getIcon("REFRESH_BUDDIES"))), i18n("Update Buddies"), this,SLOT(slotDoDownloadBuddies()), -1);
	sysMenu->insertSeparator(-1);
	sysMenu->insertItem(TQIconSet(*(images->getIcon("SYSTEM_OPTIONS"))), i18n("System Options"),this, SLOT(slotRequestSystemSettingWindow()));
	sysMenu->insertItem(TQIconSet(*(images->getIcon("SCRIPT"))), i18n("Script Manager"),this, SLOT(slotShowScriptManager()));
	sysMenu->insertItem(TQIconSet(*(images->getIcon("CHANGE_USER"))), i18n("Change User"), this,SLOT(slotDoChangeUser()), -1);
	sysMenu->insertSeparator(-1);
	//sysMenu->insertItem(TQIconSet(*(images->getIcon("EVA"))), i18n("About Eva"), this,SLOT(doAbout()), -1);
	m_helpMenu = new KHelpMenu(g_mainWin, TDEGlobal::instance()->aboutData(), 
				 false);
	sysMenu->insertItem(SmallIcon("help"),KStdGuiItem::help().text(), m_helpMenu->menu());
	sysMenu->insertSeparator(-1);
	sysMenu->insertItem(TQIconSet(*(images->getIcon("QUIT"))), i18n("Quit"), this,SLOT(doQuit()), -1);
}

void EvaMain::initUserLeaveMenu()
{
	if(!statusMenu) return;
	std::list<TQString>::iterator iter;
	std::list<TQString> autoList = user->getSetting()->getAutoReplyList();
	//if(!autoList.size()) return;
	
	statusMenu->removeItemAt(2);
	if(autoMenu) delete autoMenu;
	autoMenu = new TDEPopupMenu();
	autoMenu->setCheckable(true);
	autoMenu->insertItem(TQString(i18n("No Auto-Reply")), 0);
	int id=1;
	for(iter=autoList.begin(); iter!=autoList.end(); ++iter){
		autoMenu->insertItem(*iter, id++);
	}
	autoMenu->setItemChecked(user->getSetting()->getAutoReplySelectedIndex()+1, true);
	statusMenu->insertItem(TQIconSet(*(images->getIcon("LEAVE"))), i18n("Leave"), autoMenu, -1, 2);
	
	TQObject::connect(autoMenu, SIGNAL(activated(int)), this,  SLOT(slotAutoReplyMenuActivated(int)));
}

void EvaMain::slotAutoReplyMenuActivated(int id)
{
	if(id==0)
		user->getSetting()->setAutoReplyEnabled(false);
	else
		user->getSetting()->setAutoReplyEnabled(true);
	user->getSetting()->setAutoReplySelectedIndex(id - 1);
	for(uint i=0; i <= user->getSetting()->getAutoReplyList().size(); i++){
		if((int)i==id)
			autoMenu->setItemChecked(i, true);
		else
			autoMenu->setItemChecked(i, false);
	}
	if(user->getStatus() != EvaUser::Eva_Leave)
		slotDoLeave();
}

void EvaMain::doSlotConnection()
{
//	TQObject::connect(onlineFriendTimer, SIGNAL(timeout()), this, SLOT(slotGetOnlineStatus()));
	TQObject::connect(loginWin, SIGNAL(doLogin()), this, SLOT(slotDoLoginClick()));
	TQObject::connect(loginWin, SIGNAL(doCancel()), this, SLOT(slotDoCancel()));
	
	TQObject::connect(g_mainWin, SIGNAL(groupDeleted(const int)), this, SLOT(slotGroupDeleted(const int)));
	//TQObject::connect(g_mainWin, SIGNAL(groupAdded(TQString, int)), this, SLOT(slotGroupAdded(TQString, int)));
	TQObject::connect(g_mainWin, SIGNAL(groupRenamed(TQString, int)), this, SLOT(slotGroupRenamed(TQString, int)));
	TQObject::connect(g_mainWin, SIGNAL(deleteMeFrom(const unsigned int)), this, SLOT(slotDeleteMeFrom(const unsigned int)));
	TQObject::connect(g_mainWin, SIGNAL(groupChanged(const unsigned int, int)), this, SLOT(slotGroupChanged(const unsigned int, int)));
	//TQObject::connect(g_mainWin, SIGNAL(requestAddBuddy(const unsigned int)),g_AddingManager, SLOT(slotAddBuddy(const unsigned int)));
	
	
	TQObject::connect(g_mainWin, SIGNAL(requestDelete(const unsigned int)), this, SLOT(slotRequestDelete(const unsigned int)));
	TQObject::connect(g_mainWin, SIGNAL(requestDetails(const unsigned int)), this, SLOT(slotRequestDetails(const unsigned int)));
	TQObject::connect(g_mainWin, SIGNAL(requestChat(const unsigned int)), this, SLOT(slotRequestChat(const unsigned int)));
	TQObject::connect(g_mainWin, SIGNAL(requestSendFile(const unsigned int)), this, SLOT(slotRequestSendFile(const unsigned int)));

	TQObject::connect(g_mainWin, SIGNAL(requestLevel(const unsigned int)), this, SLOT(slotRequestLevel(const unsigned int)));
	TQObject::connect(g_mainWin, SIGNAL(requestSearch()), this, SLOT(slotRequestSearch()));
	TQObject::connect(g_mainWin, SIGNAL(requestSystemMessages()), this, SLOT(slotRequestSystemMessages()));
	TQObject::connect(g_mainWin, SIGNAL(requestHistory(const unsigned int)), this, SLOT(slotRequestHistory(const unsigned int)));
	TQObject::connect(g_mainWin, SIGNAL(requestQunChat(const unsigned int)), this, SLOT(slotRequestQunChat(const unsigned int)));
	TQObject::connect(g_mainWin, SIGNAL(requestQunDetails(const unsigned int)), this, SLOT(slotRequestQunDetails(const unsigned int)));
	TQObject::connect(g_mainWin, SIGNAL(requestQunExit(const unsigned int)), this, SLOT(slotDoQunExit( const unsigned int)));
	TQObject::connect(g_mainWin, SIGNAL(requestQunCreate()), this, SLOT(slotQunCreate()));
	TQObject::connect(g_mainWin, SIGNAL(requestQunHistory(const unsigned int)), this, SLOT(slotRequestQunHistory(const unsigned int)));
	
	TQObject::connect(tray, SIGNAL(requestChat(const unsigned int)), this, SLOT(slotRequestChat(const unsigned int)));
	TQObject::connect(tray, SIGNAL(requestQunChat(const unsigned int)), this, SLOT(slotRequestQunChat(const unsigned int)));
	TQObject::connect(tray, SIGNAL(requestSystemMessage()), m_SysMsgManager, SLOT(showSysMessage()));
	TQObject::connect(g_mainWin, SIGNAL(requestModifyMemo(const unsigned int)), this, SLOT(slotModifyMemo(const unsigned int)));

	TQObject::connect(g_AddingManager, SIGNAL(requestDetails(const unsigned int)), SLOT(slotRequestDetails(const unsigned int)));
	TQObject::connect(g_AddingManager, SIGNAL(buddyAdded(const unsigned int, const TQString, const unsigned short, const int)),
					SLOT(slotBuddyAdded(const unsigned int, const TQString, const unsigned short, const int)));

	TQObject::connect(m_SysMsgManager, SIGNAL(requestDetails(const unsigned int)), SLOT(slotRequestDetails(const unsigned int)));
	TQObject::connect(m_SysMsgManager, SIGNAL(requestQunDetails(const unsigned int)), SLOT(slotRequestQunDetails( const unsigned int)));
	TQObject::connect(m_SysMsgManager, SIGNAL(buddyAdded(const unsigned int, const TQString, const unsigned short, const int)),
					SLOT(slotBuddyAdded(const unsigned int, const TQString, const unsigned short, const int)));
	TQObject::connect(m_SysMsgManager, SIGNAL(sysMessage()), tray, SLOT(newSysMessage()));
	TQObject::connect(m_SysMsgManager, SIGNAL(requestAddBuddy(const unsigned int, const TQString, const unsigned short)),
			g_AddingManager, SLOT(slotAddBuddy(const unsigned int, const TQString, const unsigned short)));
	TQObject::connect(m_SysMsgManager, SIGNAL(qunListChanged()), SLOT(slotLoadQunListReady()));

	TQObject::connect(idt, SIGNAL(idleTimeUp()), this, SLOT(slotIdleTimeUp()));
	TQObject::connect(idt, SIGNAL(idleBack()), this, SLOT(slotIdleBack()));
}

void EvaMain::slotGetOnlineStatus()
{
//	printf("slotGetOnlineStatus() called!\n");
	std::map<unsigned int, TQQFriend>::iterator iter;
	std::map<unsigned int, TQQFriend> list = (user->getFriendList()).getAllFriendsMap();
	for(iter = list.begin(); iter != list.end(); ++iter){
		switch(iter->second.getStatus()){
		case TQQ_FRIEND_STATUS_ONLINE:
			g_mainWin->changeToOnline(iter->second.getQQ());
			break;
//		case TQQ_FRIEND_STATUS_OFFLINE:
//			g_mainWin->changeToOffline(iter->second.getQQ());
//			break;
		case TQQ_FRIEND_STATUS_LEAVE:
			g_mainWin->changeToLeave(iter->second.getQQ());
			break;
//		case TQQ_FRIEND_STATUS_INVISIBLE:
//			g_mainWin->changeToInvisible(iter->second.getQQ());
//			break;
		}	
	}	
}

void EvaMain::slotDoLoginClick()
{
	GetScriptManager()->releaseScripts();
	if(g_mainWin) g_mainWin->offline();
	
	if(tray) tray->reset();
	numLoginRetry = 0;
	isClientSet = false;
	g_mainWin->showInfoFrame(true);
	slotFetchTQQServer();
}

void EvaMain::slotFetchTQQServer()
{
	EvaServers *server = global->getEvaServers();
	TQObject::disconnect(server, 0, 0, 0);
	TQObject::connect(server, SIGNAL(isReady(TQHostAddress)), SLOT(slotGotServer(TQHostAddress)));
	server->fetchAddress(loginWin->getConnectionType() == EvaLoginWindow::UDP ? true: false);
}

void EvaMain::slotGotServer(TQHostAddress addr)
{
	//printf("Got server :%s\n", addr.toString().ascii());
	global->getEvaServers()->stopDns();
	TQQServer = addr;
	slotDoLogin();
}

void EvaMain::slotServerBusy()
{
	if(numLoginRetry > MaxRetryTimes){
		slotPacketException( TQQ_CMD_LOGIN);
	}else
		slotFetchTQQServer();
}

void EvaMain::slotSetupUser()
{
	if(user){
		TQObject::disconnect(user, 0, 0, 0);
	}
	//printf("EvaMain::slotSetupEvaClient\n");
	user = new EvaUser(loginWin->getQQ(),loginWin->getMd5Password());
	
	//TQObject::connect(user, SIGNAL(loadGroupedBuddiesReady()), SLOT(slotLoadGroupedBuddiesReady()));
	//TQObject::connect(user, SIGNAL(loadQunListReady()), SLOT(slotLoadQunListReady()));
	//TQObject::connect(user->loginManager(), SIGNAL(processReady()), SLOT(slotLoginProcessReady()));
	TQString qname, aname, bname;
	qname = i18n("Qun List");
	aname = i18n("Anonymous");
	bname = i18n("Black List");
	user->setQunGroupName(codec->fromUnicode(qname).data());
	user->setAnonymousGroupName(codec->fromUnicode(aname).data());
	user->setBlackGroupName(codec->fromUnicode(bname).data());
	user->getSetting()->loadSettings();
	images->setThemePath(user->getSetting()->getThemeDir());
	global->getSoundResource()->setSoundDir(user->getSetting()->getSoundDir());
	// when we set faee size, the face images will be reloaded as well
	global->setFaceSize(TQSize(user->getSetting()->getFaceSize()));
	
	slotUpdateShortcut();

	if(loginWin->isHiddenLoginMode())
		user->setStatus(EvaUser::Eva_Invisible);
	else
		user->setStatus(EvaUser::Eva_Online);
	
	//TQString name = i18n("Buddy");
	user->newGroup(codec->fromUnicode(i18n("Buddy List")).data()); // we must do this if cannot load from disk
	
	// save the tryin-to-login user's parameters anyway
	TQHostAddress addr(loginWin->getProxyIP());
	sysSetting->saveSetting(loginWin->getQQ(), loginWin->getMd5Password(),
							loginWin->isRememberChecked(), loginWin->isHiddenLoginMode(),  
							(int)loginWin->getConnectionType(),
							addr.toIPv4Address(), loginWin->getProxyPort(), loginWin->getProxyUserName(),
							loginWin->getProxyParam());

}

///NOTE: must call slotSetupUser before calling this method
void EvaMain::slotSetupNetwork( )
{
	if(GetLoginManager()->isLoggedIn()) slotDoLogout();
	if(packetManager) {
		delete packetManager;
	}

	if(picManager)
		delete picManager;
	picManager = NULL;
	if(uhManager){
		uhManager->stop();
		uhManager->wait();
		delete uhManager;
	}
	uhManager = new EvaUHManager(this, user->getSetting()->getUserHeadDir());
	uhManager->initiate(global->getFaceSize());// load user head pictures
	if(images){
		images->setUserHeadImage(uhManager->getOnList(), uhManager->getOffList());
	}

	if(m_FileManager){
		m_FileManager->stopAll();
		delete m_FileManager;
	}
	m_FileManager = new EvaFileManager(user->getQQ(), this);
	EvaNetwork *network = NULL;
	switch(loginWin->getConnectionType()){
	case EvaLoginWindow::UDP:
		network = new EvaNetwork(TQQServer, 8000, EvaNetwork::UDP);
		picManager = new EvaPicManager(user);
		break;
	case EvaLoginWindow::TCP:
		network = new EvaNetwork(TQQServer, 80, EvaNetwork::TCP);
		printf("connecting to \"%s\"\n", TQQServer.toString().ascii());
		picManager = new EvaPicManager(user);
		break;
	case EvaLoginWindow::HTTP_Proxy:
		network = new EvaNetwork(TQHostAddress(loginWin->getProxyIP()), loginWin->getProxyPort(), EvaNetwork::HTTP_Proxy);
		network->setDestinationServer(TQQServer.toString(), 443);
		network->setAuthParameter(loginWin->getProxyParam());
		
		picManager = new EvaPicManager(user, true);
		picManager->setProxyServer(loginWin->getProxyIP(), loginWin->getProxyPort(), loginWin->getProxyParam());

		m_FileManager->setMyProxyInfo(TQHostAddress(loginWin->getProxyIP()), loginWin->getProxyPort(), loginWin->getProxyParam());
		break;
	}

	connecter = new EvaConnecter(network);
	packetManager = new EvaPacketManager(user, connecter);

	// connect signals of m_FileManager
	TQObject::connect(m_FileManager, SIGNAL(notifyTransferStatus(const unsigned int, const unsigned int, const unsigned int, const unsigned int, const int )), 
					SLOT(slotNotifyTransferStatus(const unsigned int, const unsigned int, const unsigned int, const unsigned int, const int )));
	TQObject::connect(m_FileManager, SIGNAL(notifyAddressRequest(const unsigned int, const unsigned int, const unsigned int, 
							const unsigned int, const unsigned short,  const unsigned int, const unsigned short)), 
					SLOT(slotNotifyAddressRequest(const unsigned int, const unsigned int, const unsigned int, 
							const unsigned int, const unsigned short,  const unsigned int, const unsigned short)));

	// connet the signal of connecter so that I will know the network is ready
	//TQObject::connect(connecter, SIGNAL(isReady()), packetManager, SLOT(slotConnectReady()));

	// connect network events with packetManager
	TQObject::connect(packetManager, SIGNAL(networkException(int)), SLOT(slotNetworkException(int)));
	TQObject::connect(packetManager, SIGNAL(packetException(int)), SLOT(slotPacketException(int)));
	TQObject::connect(packetManager, SIGNAL(serverBusy()), SLOT(slotServerBusy()));

	// some Tencent server related signals
	//TQObject::connect(packetManager, SIGNAL(wrongPassword(TQString)), SLOT(slotWrongPassword(TQString)));
	TQObject::connect(packetManager, SIGNAL(kickedOut(const TQString)), SLOT(slotKickedOut(const TQString)));
	//TQObject::connect(packetManager, SIGNAL(loginOK()), SLOT(slotLoginOK()));
	//TQObject::connect(packetManager, SIGNAL(loginNeedVerification( )), 
	//				this, SLOT(slotLoginVerification( )));

	// user information signal
	//TQObject::connect(packetManager, SIGNAL(myInfoReady()), SLOT(slotMyInfoReady()));
	TQObject::connect(packetManager, SIGNAL(extraInfoReady()), this, SLOT(slotExtraInfoReady()));
	TQObject::connect(packetManager, SIGNAL(friendSignatureChanged(const unsigned int, const TQDateTime, const TQString)), 
			SLOT(slotFriendSignatureChanged(const unsigned int, const TQDateTime, const TQString)));

	// online status signals
	TQObject::connect(packetManager, SIGNAL(onlineReady()), SLOT(slotOnlineReady()));
	TQObject::connect(packetManager, SIGNAL(offlineReady()), SLOT(slotOfflineReady()));
	TQObject::connect(packetManager, SIGNAL(invisibleReady()), SLOT(slotInvisibleReady()));
	TQObject::connect(packetManager, SIGNAL(leaveReady()), SLOT(slotLeaveReady()));	
	TQObject::connect(packetManager, SIGNAL(friendStatusChanged(unsigned int)), SLOT(slotFriendStatusChanged(unsigned int)));
	TQObject::connect(packetManager, SIGNAL(friendListReady()), SLOT(slotGetOnlineStatus()));

	// friend list related signals
	//TQObject::connect(packetManager, SIGNAL(friendListReady()), SLOT(slotFriendListReady()));
	TQObject::connect(packetManager, SIGNAL(deleteMeReady(bool)), SLOT(slotDeleteMeReply( bool )));
	//TQObject::connect(packetManager, SIGNAL(friendGroupsReady()), SLOT(slotFriendGroupsReady()));
	TQObject::connect(packetManager, SIGNAL(friendGroupsUploadReady(bool)), SLOT(slotFriendGroupsUploadReady(bool)));
	TQObject::connect(packetManager, SIGNAL(deleteBuddyReady(unsigned int, bool)), SLOT(slotDeleteBuddyReady(unsigned int, bool)));

	// add friend
	//TQObject::connect(packetManager, SIGNAL(addBuddyReady()), SLOT(slotFriendListReady( )));
	TQObject::connect(packetManager, SIGNAL(addAnonymous(const unsigned int, const unsigned short)), SLOT(slotAddAnonymous(const unsigned int, const unsigned short)));

	// budy chatting signal
	TQObject::connect(packetManager, 
			SIGNAL(txtMessage(unsigned int, bool, TQString, TQDateTime, const char,const bool, const bool, const bool, 
				const char , const char, const char)), 
			SLOT(slotTxtMessage(unsigned int, bool, TQString, TQDateTime, const char,const bool, const bool, const bool, 
				const char , const char, const char)));

	// Qun chatting signal
	TQObject::connect(packetManager, SIGNAL(qunTxtMessage(unsigned int, unsigned int, TQString, TQDateTime, const char , 
			const bool, const bool, const bool, const char, const char, const char)), 
			SLOT(slotReceivedQunMessage( unsigned int, unsigned int, TQString, TQDateTime, const char, 
			const bool, const bool, const bool, const char, const char, const char)));

	// Qun related signals
	TQObject::connect(packetManager, SIGNAL(qunSystemMessageRequest(const unsigned int, TQString)), tray, SLOT(newSysMessage()));	
	TQObject::connect(packetManager, SIGNAL(qunInfomationReady(const unsigned int, const bool, TQString)), 
					SLOT(slotQunInfomationReady(const unsigned int, const bool, TQString)));
	TQObject::connect(packetManager, SIGNAL(qunSystemMessageRequest(const unsigned int, TQString)), 
					SLOT(slotQunSystemMessageRequest(const unsigned int, TQString)));
	TQObject::connect(packetManager, SIGNAL(qunRequestUpdateDisplay()), this, SLOT(slotLoadQunListReady()));
	TQObject::connect(packetManager, SIGNAL(qunRequestQunCardReply(const unsigned int, const bool,
									const unsigned int, TQString, const unsigned char, 
									TQString, TQString, TQString, TQString)),
				this,	SLOT(slotRequestQunCardReady(const unsigned int, const bool,
									const unsigned int, TQString, const unsigned char, 
									TQString, TQString, TQString, TQString)));
	TQObject::connect(packetManager, SIGNAL(qunExitReply(const unsigned int, const bool, TQString)), this, 
			SLOT(slotQunExitReply( const unsigned int , const bool, TQString)));

	// file transfer related signals
	TQObject::connect(packetManager, SIGNAL(receivedFileRequest(const unsigned int, const unsigned int,
								const TQString,  const int, 
								const unsigned char)),
					SLOT(slotReceivedFileRequest(const unsigned int, const unsigned int,
								const TQString,   const int, 
								const unsigned char)));
	TQObject::connect(packetManager, SIGNAL(receivedFileAccepted(const unsigned int,    const unsigned int,
								const unsigned int, const bool,
								const unsigned char)),
					SLOT(slotReceivedFileAccepted(const unsigned int,   const unsigned int,
								const unsigned int, const bool,
								const unsigned char)));
	TQObject::connect(packetManager, SIGNAL(receivedFileAgentInfo(const unsigned int,   const unsigned int ,
								const unsigned int, const unsigned int,
								const unsigned short, const unsigned char *)),
					SLOT(slotReceivedFileAgentInfo(const unsigned int, const unsigned int,
								const unsigned int, const unsigned int,
								const unsigned short, const unsigned char *)));
	TQObject::connect(packetManager, SIGNAL(receivedFileNotifyIpEx(const unsigned int, const bool, 
								const unsigned int , const unsigned char,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int )),
					SLOT(slotReceivedFileNotifyIpEx(const unsigned int , const bool , 
								const unsigned int , const unsigned char,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int , const unsigned short ,
								const unsigned int )));
	TQObject::connect(m_FileManager, SIGNAL(notifyAgentRequest(const unsigned int, const unsigned int, const unsigned int, 
							const unsigned int, const unsigned short, const unsigned char)),
			  packetManager, SLOT(doNotifyAgentTransfer(const unsigned int, const unsigned int, const unsigned int,
							const unsigned int, const unsigned short, const unsigned char)));

	// let Adding Manager know connection changed
	g_AddingManager->setPacketManager( packetManager);
	m_SysMsgManager->setPacketManager( packetManager);
	GetLoginManager()->setPacketManager( packetManager);
	GetContactManager()->setPacketManager( packetManager);
}

/**
 *  connect all necessary signals so that Chatting windows could show
 *  notifications in some ways.
 */
///NOTE: must call slotSetupNetwork before calling this method
void EvaMain::slotSetupWindowManager()
{

	if(g_ChatWindowManager) delete g_ChatWindowManager;

	// if user nickname does not exist, default "EVA" will be used	
	TQString nick = codec->toUnicode(user->getDetails().at(ContactInfo::Info_nick).c_str());
	g_ChatWindowManager = new EvaChatWindowManager(images, user->getSetting(), nick, user->getQQ());

	TQObject::connect(packetManager, SIGNAL(txtMessage(unsigned int, bool, TQString, TQDateTime, const char, 
			const bool, const bool, const bool, const char , const char, const char)), g_ChatWindowManager, 
			SLOT(slotReceivedMessage(unsigned int, bool, TQString, TQDateTime, const char,const bool, const bool, const bool, 
			const char , const char, const char)));

	TQObject::connect(packetManager, SIGNAL(sentMessageResult(unsigned int, bool)), g_ChatWindowManager, SLOT(slotSendResult(unsigned int, bool)));
	TQObject::connect(connecter, SIGNAL(sendMessage( unsigned int, bool)), g_ChatWindowManager, SLOT(slotSendResult(unsigned int, bool)));

	TQObject::connect(packetManager, SIGNAL(qunRequestUpdateDisplay()), g_ChatWindowManager, SLOT(slotQunListUpdated()) );
	TQObject::connect(g_ChatWindowManager, SIGNAL(requestQunCard(const unsigned int, const unsigned int)),
			packetManager, SLOT(doRequestQunCard( const unsigned int,  const unsigned int)));
	TQObject::connect(g_ChatWindowManager, SIGNAL(requestQunRealNames(const unsigned int)), packetManager, SLOT(doRequestQunRealNames(const unsigned int )));
	TQObject::connect(g_ChatWindowManager, SIGNAL(requestDetails(const unsigned int)), this, SLOT(slotRequestDetails(const unsigned int)));	
	TQObject::connect(g_ChatWindowManager, SIGNAL(sendMessage(const unsigned int , const bool , TQString &, const char , 
			const bool , const bool , const bool , 
			const char, const char , const char)), packetManager, 
			SLOT(doSendMessage(const unsigned int , const bool  , TQString &, const char, 
			const bool , const bool , const bool , 
			const char , const char, const char)));	
	TQObject::connect(g_ChatWindowManager, SIGNAL(requestHistory(const unsigned int)), this, SLOT(slotRequestHistory(const unsigned int)));	
	TQObject::connect(g_ChatWindowManager, SIGNAL(requestBuddyTQQShow(const unsigned int)), this, SLOT(slotRequestTQQShow(const unsigned int)));	
	TQObject::connect(g_ChatWindowManager, SIGNAL(requestMyTQQShow()), this, SLOT(slotRequestMyTQQShow()));

	TQObject::connect(g_ChatWindowManager, SIGNAL(fileTransferSend(const unsigned int, const unsigned int, const TQValueList<TQString>,
							const TQValueList<unsigned int>, const unsigned char)), 
				SLOT(slotFileTransferSend(const unsigned int, const unsigned int, const TQValueList<TQString>,
							const TQValueList<unsigned int>, const unsigned char)));
	TQObject::connect(g_ChatWindowManager, SIGNAL(fileTransferAccept(const unsigned int, const unsigned int,
							const TQString, const unsigned char)),
				SLOT(slotFileTransferAccept(const unsigned int, const unsigned int,
							const TQString, const unsigned char)));
	TQObject::connect(g_ChatWindowManager, SIGNAL(fileTransferCancel(const unsigned int, const unsigned int)),
				SLOT(slotFileTransferCancel(const unsigned int, const unsigned int)));
	
	// connect Qun stuff
	TQObject::connect(packetManager, SIGNAL(qunTxtMessage(unsigned int, unsigned int, TQString, TQDateTime, const char , 
			const bool, const bool, const bool, const char, const char, const char)), g_ChatWindowManager, 
			SLOT(slotReceivedQunMessage( unsigned int, unsigned int, TQString, TQDateTime, const char, 
				const bool, const bool, const bool, const char, const char, const char)));
	TQObject::connect(packetManager, SIGNAL(qunSentMessageResult(unsigned int, bool, TQString)), g_ChatWindowManager, SLOT(slotQunSendResult(unsigned int, bool, TQString)));
	TQObject::connect(packetManager, SIGNAL(qunJoinEvent(const unsigned int,
								const short,
								const unsigned int,
								const unsigned int)),
			g_ChatWindowManager, SLOT(slotQunJoinEvent(const unsigned int,
								const short,
								const unsigned int,
								const unsigned int)) );
	TQObject::connect(connecter, SIGNAL(sendQunMessage(unsigned int, bool, TQString)),
			g_ChatWindowManager, SLOT(slotQunSendResult(unsigned int, bool, TQString)));
	TQObject::connect(g_ChatWindowManager, SIGNAL(requestQunDetails(const unsigned int)), this, SLOT(slotRequestQunDetails(const unsigned int)));
	TQObject::connect(g_ChatWindowManager, SIGNAL(sendQunMessage(const unsigned int, TQString &, const char , 
			const bool, const bool, const bool, 
			const char, const char, const char)), packetManager, 
			SLOT(doSendQunMessage(const unsigned int, TQString &, const char, 
			const bool , const bool, const bool , const char , const char , const char )));
	TQObject::connect(g_ChatWindowManager, SIGNAL(requestQunHistory(const unsigned int)), this, SLOT(slotRequestQunHistory(const unsigned int)));
	TQObject::connect(g_ChatWindowManager, SIGNAL(requestQunOnlineList(const unsigned int)), packetManager, 
			SLOT(doRequestQunOnlineMembers(const unsigned int)));
	TQObject::connect(packetManager, SIGNAL(qunOnlineListReady(const unsigned int)), g_ChatWindowManager, SLOT(slotQunOnlineMembers(const unsigned int)));
	TQObject::connect(packetManager, SIGNAL(qunMemberInfoReady(const unsigned int)), g_ChatWindowManager, 
			SLOT(slotQunMemberInfoReady( const unsigned int)));
			
	TQObject::connect(picManager, SIGNAL(pictureReady(const unsigned int, const TQString, const TQString)), g_ChatWindowManager,
			SLOT(slotQunPicReady(const unsigned int, const TQString, const TQString)));
	TQObject::connect(picManager, SIGNAL(pictureSent(const unsigned int, const unsigned int, const unsigned int, const unsigned short)), g_ChatWindowManager, 
			SLOT(slotQunPicSent(const unsigned int, const unsigned int, const unsigned int, const unsigned short)));
	TQObject::connect(picManager, SIGNAL(sendErrorMessage(const unsigned int, const TQString)), g_ChatWindowManager, 
			SLOT(slotSendImageError(const unsigned int, const TQString)));

	TQObject::connect(m_FileManager, SIGNAL(notifyTransferSessionChanged(const unsigned int, const unsigned int, const unsigned int)), g_ChatWindowManager, 
			SLOT(slotChangeFileSessionTo(const unsigned int, const unsigned int, const unsigned int)));
	TQObject::connect(m_FileManager, SIGNAL(notifyTransferNormalInfo(const unsigned int, const unsigned int,
						EvaFileStatus, const TQString, const TQString,
						const unsigned int, const unsigned char)),
			g_ChatWindowManager, SLOT(slotFileNotifyNormalInfo(const unsigned int, const unsigned int,
						EvaFileStatus, const TQString, const TQString,
						const unsigned int, const unsigned char)));
	TQObject::connect(g_ChatWindowManager, SIGNAL(fileTransferResume(const unsigned int, const unsigned int, const bool)),
			m_FileManager, SLOT(slotFileTransferResume(const unsigned int, const unsigned int, const bool)));
}

void EvaMain::slotSetupEvaClient()
{	
	g_mainWin->clearList();
	loginWin->hide();

	// make sure that slotSetupUser and
	// slotSetupNetwork have been called.
	slotSetupUser();
	slotSetupNetwork();
	slotSetupWindowManager();

	user->loadGroupedBuddyList();
	user->loadQunList();
	tray->show();

	g_mainWin->updateMyInfo();
	g_mainWin->showInfoFrame(true);
	g_mainWin->resize(user->getSetting()->getWinSize());
	g_mainWin->move(user->getSetting()->getWinPoint());
	g_mainWin->show();
	isClientSet = true;
}

void EvaMain::slotDoLogin()
{
	if(!isClientSet)
		slotSetupEvaClient();
	tray->setLoginWaiting();
	//ServerDetectorPacket::setStep(0);
	//ServerDetectorPacket::setFromIP(0);
	//connecter->redirectTo(TQQServer.toIPv4Address(), -1);
	GetLoginManager()->login(TQQServer);
}

void EvaMain::slotDoCancel()
{
	if(loginWin->isVisible())
		loginWin->hide();
	if(!g_mainWin->isVisible() && !isClientSet )
		doQuit();
	else{
		if(!tray->isVisible())
		{
			tray->show();
		}
		if(!g_mainWin->isVisible())
			g_mainWin->show();
	}
}

// void EvaMain::slotConnectReady( )
// {
// 	kdDebug() << "[QQ: " << user->getQQ() << "] start logging in server \"" << connecter->getHostAddress().toString()  << "\" ..." << endl;
// 	packetManager->doLogin();
// }

void EvaMain::loginOK( )
{
	initUserLeaveMenu();
	switch(user->getStatus()){
	case EvaUser::Eva_Online:
		g_mainWin->online();
		tray->setOnline();
		break;
	case EvaUser::Eva_Offline:
		g_mainWin->offline();
		tray->setOffline();
		break;
	case EvaUser::Eva_Leave:
		g_mainWin->leave();
		tray->setLeave();
		break;
	case EvaUser::Eva_Invisible:
		g_mainWin->invisible();
		tray->setInvisible();
	}

	//packetManager->doGetUserInfo(user->getQQ());
	
	//loggedIn = true;
	//TQTimer::singleShot(5000,this, SLOT(slotGetOnlineStatus()));

	idt->setMaxIdle(user->getSetting()->getIdleMaxTime());
	printf("idt created %d minutes\n", user->getSetting()->getIdleMaxTime());
	idt->toggleOverAllIdleDetection(TRUE);
	idt->startIdleDetection();
}

void EvaMain::slotOfflineReady()
{ 
	g_mainWin->offline();
	tray->setOffline();
	//loggedIn = false;
	GetLoginManager()->setLoggedOut();
	//user->loginManager()->reset();
	//user->loginManager()->finishedCommand(TQQ_CMD_REQUEST_LOGIN_TOKEN);
	picManager->stop();
	if(onlineFriendTimer->isActive())
		onlineFriendTimer->stop();
	
	GetScriptManager()->notifyStatusChange(user->getQQ());
}

void EvaMain::slotOnlineReady( )
{
	g_mainWin->online();
	tray->setOnline();
	GetScriptManager()->notifyStatusChange(user->getQQ());
}

void EvaMain::slotInvisibleReady( )
{
	g_mainWin->invisible();
	tray->setInvisible();
	GetScriptManager()->notifyStatusChange(user->getQQ());
}

void EvaMain::slotLeaveReady( )
{
	g_mainWin->leave();
	tray->setLeave();
	GetScriptManager()->notifyStatusChange(user->getQQ());
}

void EvaMain::slotNetworkException( int/* exp*/)
{
	g_mainWin->offline();
	tray->setOffline();
	numOfLostKeepAlivePackets++; 
	if(onlineFriendTimer->isActive())
		onlineFriendTimer->stop();
	packetManager->doLogout();
	picManager->stop();
	//loggedIn = false;
	GetLoginManager()->setLoggedOut();
	
	//user->loginManager()->reset();
	KMessageBox::information(0, i18n("Network error occurred, check your network then try Eva later please."),
				i18n("Network"));
}

void EvaMain::slotPacketException( int cmd)
{
	printf("packet exception -- command code: 0x%4x\n", cmd);
	if(cmd == TQQ_CMD_SERVER_DETECT){
		slotServerBusy();
		return;
	}

	if(cmd == TQQ_CMD_KEEP_ALIVE){
		if(numOfLostKeepAlivePackets < 2)
			numOfLostKeepAlivePackets++; 
			
	}
	if(!GetLoginManager()->isLoggedIn() && cmd == TQQ_CMD_LOGIN || cmd == TQQ_CMD_REQUEST_LOGIN_TOKEN){
		g_mainWin->offline();
		tray->setOffline();
		packetManager->doLogout();
		
		if(onlineFriendTimer->isActive())
			onlineFriendTimer->stop();
		//loggedIn = false;
		GetLoginManager()->setLoggedOut();
		KMessageBox::information(0, i18n("Cannot login, try later please."), i18n("Eva Login"));
	}
	
	if(numOfLostKeepAlivePackets>=2){
		g_mainWin->offline();
		tray->setOffline();
		packetManager->doLogout();
		picManager->stop();
		numOfLostKeepAlivePackets = 0;
		if(onlineFriendTimer->isActive())
			onlineFriendTimer->stop();
		//user->loginManager()->reset();
		//loggedIn = false;
		GetLoginManager()->setLoggedOut();
		KMessageBox::information(0, i18n("Lost connection with server, try later please."), i18n("Eva Connection"));
	}
}

// void EvaMain::slotWrongPassword( TQString msg)
// {
// 	g_mainWin->offline();
// 	tray->setOffline();
// 	loggedIn = false;
// 	user->setStatus(EvaUser::Eva_Offline);
// 	numOfLostKeepAlivePackets = 0;
// 	//KMessageBox::information(g_mainWin, msg, i18n("Eva Login"));
// 	slotDoChangeUser();
// }

void EvaMain::slotKickedOut(const TQString msg)
{
	g_mainWin->offline();
	tray->setOffline();
	//loggedIn = false;
	GetLoginManager()->setLoggedOut();
	user->setStatus(EvaUser::Eva_Offline);
	numOfLostKeepAlivePackets = 0;
	KMessageBox::error(g_mainWin, msg, i18n("Eva Login"));
}

// void EvaMain::slotFriendListReady( )
// {
// 	if(!user->isBuddiesLoaded()){
// 		user->saveGroupedBuddyList();
// 		user->setBuddyLoadedEnabled(true);
// 		if(!m_IsShowingGroups) slotDoDownloadGroups();
// 	}
// 
// 	//user->loginManager()->finishedCommand(TQQ_CMD_GET_FRIEND_LIST);
// 	if(!onlineFriendTimer->isActive())
// 		onlineFriendTimer->start(60000, false);
// }

void EvaMain::slotFriendStatusChanged( unsigned int id )
{
	const TQQFriend *frd = (user->getFriendList()).getFriend(id);
	if(frd){
		printf("IP is %d\n", frd->getIP());
		switch(frd->getStatus()){
		case TQQ_FRIEND_STATUS_ONLINE:
			g_mainWin->changeToOnline(id);
			if(user->getSetting()->isShowBudyOnlineNotifyEnabled()){
				EvaTipWindow *tip = new EvaTipWindow(images, codec->toUnicode(frd->getNick().c_str()), 
									id, frd->getFace(), i18n("I am online."));
				TQObject::connect(tip, SIGNAL(requestChat(const unsigned int)), SLOT(slotRequestChat(const unsigned int)));
				tip->show();
				if(user->getSetting()->isSoundEnabled())
					global->getSoundResource()->playOnlineSound();
			}
			break;
		case TQQ_FRIEND_STATUS_OFFLINE:
			g_mainWin->changeToOffline(id);
			break;
		case TQQ_FRIEND_STATUS_LEAVE:
			g_mainWin->changeToLeave(id);
			if(user->getSetting()->isShowBudyOnlineNotifyEnabled()){
				EvaTipWindow *tip = new EvaTipWindow(images, codec->toUnicode(frd->getNick().c_str()), 
									id, frd->getFace(), i18n("I am busy ..."));
				TQObject::connect(tip, SIGNAL(requestChat(const unsigned int)), SLOT(slotRequestChat(const unsigned int)));
				tip->show();
			}
			break;
		case TQQ_FRIEND_STATUS_INVISIBLE:
			g_mainWin->changeToInvisible(id);
			break;
		}
	}else{
		printf("buddy %d not in list\n", id);
	}

	GetScriptManager()->notifyStatusChange(id);
}

void EvaMain::slotTxtMessage(unsigned int sender, bool, TQString message, TQDateTime, const char, 
			const bool, const bool, const bool, 
			const char, const char, const char)
{
	TQString reply="";
	if(sender != user->getQQ() &&
	   user->getStatus() == EvaUser::Eva_Leave && 
	   user->getSetting()->isAutoReplyEnabled()){
		reply = user->getSetting()->getSelectedAutoReply();
		packetManager->doSendMessage(sender, false, reply, 9, false, false, false, 0,0,0);
	}
	if(!(g_ChatWindowManager && g_ChatWindowManager->isChatWindowExisted(sender))){	
		g_mainWin->newMessage(sender);
		const TQQFriend *frd = (user->getFriendList()).getFriend(sender);
		short faceId = 0x0000;
		if(frd)
			faceId = frd->getFace();
		tray->newTxtMessage(sender, faceId);
		if(user->getSetting()->isShowMessageTipEnabled()){
			EvaTipWindow *tip = new EvaTipWindow(images, codec->toUnicode(frd->getNick().c_str()), sender, faceId, message);
			TQObject::connect(tip, SIGNAL(requestChat(const unsigned int)), SLOT(slotRequestChat(const unsigned int)));
			tip->show();
		}
	}
	if( g_ChatWindowManager && g_ChatWindowManager->isChatWindowExisted(sender)){
		g_mainWin->addBuddyToRecentList( sender, true);
	}
	if(user->getSetting()->isSoundEnabled() && !(g_ChatWindowManager && g_ChatWindowManager->isChatWindowExisted(sender)) )
		global->getSoundResource()->playNewMessage();
}

// void EvaMain::slotFriendGroupsReady( )
// {
// 	m_IsShowingGroups = true;
// 	//slotFriendListReady();
// 	m_IsShowingGroups = false;
// 
// 	g_mainWin->clearList();
// 	g_mainWin->updateContacts();
// 	g_mainWin->updateQuns();
// 	g_mainWin->updateRecentContacts();
// 	if(!user->isBuddiesLoaded()){
// 		user->saveGroupedBuddyList();
// 		user->setBuddyLoadedEnabled(true);
// 	}
// 	std::list<int>msgs = g_ChatWindowManager->getMessages();
// 	std::list<int>::iterator itr;
// 	for(itr = msgs.begin(); itr != msgs.end(); ++itr){
// 		g_mainWin->newMessage(*itr);
// 	}
// }

void EvaMain::slotDoOnline()
{
	if(user->getStatus() == EvaUser::Eva_Offline){
		user->setStatus(EvaUser::Eva_Online);
		//user->loginManager()->finishedCommand(TQQ_CMD_GET_FRIEND_LIST);
		slotDoLogin();
	}else
		packetManager->doChangeStatus(EvaUser::Eva_Online);
}

void EvaMain::slotDoOffline()
{
	packetManager->doChangeStatus(EvaUser::Eva_Offline);
}

void EvaMain::slotDoLeave()
{
	if(user->getStatus() == EvaUser::Eva_Offline){
		user->setStatus(EvaUser::Eva_Leave);
		//user->loginManager()->finishedCommand(TQQ_CMD_GET_FRIEND_LIST);
		slotDoLogin();
	}else
		packetManager->doChangeStatus(EvaUser::Eva_Leave);
}

void EvaMain::slotDoInvisible()
{
	if(user->getStatus() == EvaUser::Eva_Offline){
		user->setStatus(EvaUser::Eva_Invisible);
		//user->loginManager()->finishedCommand(TQQ_CMD_GET_FRIEND_LIST);
		slotDoLogin();
	}else
		packetManager->doChangeStatus(EvaUser::Eva_Invisible);
}

void EvaMain::slotDoLogout()
{
	//user->loginManager()->reset();
	user->getSetting()->setWinGeometry(g_mainWin->pos(), g_mainWin->size());
	user->getSetting()->saveSettings();
	if(onlineFriendTimer->isActive())
		onlineFriendTimer->stop();
	packetManager->doLogout();
	//loggedIn = false;
	GetLoginManager()->setLoggedOut();
}

void EvaMain::slotDoDownloadGroups()
{
	user->setBuddyLoadedEnabled(false);
	packetManager->doGetGroups();
}

void EvaMain::slotDoUploadGroups()
{
	packetManager->doUploadGroups();
}

void EvaMain::slotFriendGroupsUploadReady(bool ok)
{
	if(ok)
		KMessageBox::information(g_mainWin, i18n("Uploading grouped friends successfully."), i18n("Eva Upload Groups"));
	else
		KMessageBox::information(g_mainWin, i18n("Uploading grouped friends failed."), i18n("Eva Upload Groups"));
}

void EvaMain::slotDoDownloadBuddies()
{
	user->setBuddyLoadedEnabled(false);
	//user->loginManager()->clearCommandFlag(TQQ_CMD_GET_FRIEND_LIST);
	packetManager->doGetAllFriends();
}

void EvaMain::slotDoChangeUser()
{
	if(g_mainWin->isVisible())
		g_mainWin->hide();
//	if(tray->isVisible())
//		tray->hide();
	if(!loginWin->isVisible())
		loginWin->show();
}

void EvaMain::slotGroupDeleted( const int index)
{
	user->removeGroupName(index);
	user->saveGroupedBuddyList();
}

// void EvaMain::slotGroupAdded( TQString gn, int index)
// {
// 	std::string name = (codec->fromUnicode(gn)).data();
// 	user->newGroup(name);
// 	int newIndex = user->getGroupIndexOf(name);
// 	g_mainWin->listView->findGroup(index)->setGroupIndex(newIndex);
// 	user->saveGroupedBuddyList();
// }

void EvaMain::slotGroupRenamed( TQString gn, int index)
{
	std::string name = (codec->fromUnicode(gn)).data();
	user->updateGroupName(name, index);
	user->saveGroupedBuddyList();
}

void EvaMain::slotGroupChanged(const unsigned int id, int index)
{
	user->getFriendList().updateFriendGroupIndex(id, index);
	user->saveGroupedBuddyList();
}

void EvaMain::slotRequestDetails(const unsigned int id)
{
	TQStringList details;
	details.append(TQString::number(id));
	
	const TQQFriend *frd = (user->getFriendList()).getFriend(id); 
	if(frd){
		std::string qq = frd->getUserInformation().at(0);
		if(qq!="-"){
			details = packetManager->convertDetails(frd->getUserInformation());
		}
	}
		
	if(id == user->getQQ()){
		slotRequestSystemSettingWindow();
		
	}else{
		EvaDetailsWindow *detailWin;
		detailWin = new EvaDetailsWindow(details);
		
		TQObject::connect(detailWin, SIGNAL(requestUpdate(const unsigned int)), packetManager, SLOT(doGetUserInfo(const unsigned int)));
		TQObject::connect(detailWin, SIGNAL(requestTQQShow(const unsigned int)), this, SLOT(slotRequestTQQShow(const unsigned int)));
	
		TQObject::connect(packetManager, SIGNAL(userInfoReady(TQStringList)), detailWin, SLOT(slotDetailsUpdated(TQStringList)));
		TQObject::connect(images, SIGNAL(qqShowReady(const unsigned int)), detailWin, SLOT(slotBuddyTQQShowReady(const unsigned int)));
	
		TQObject::connect(detailWin, SIGNAL(requestDownloadMemo(const unsigned int )), packetManager, SLOT(doDownloadMemo(const unsigned int )));
		TQObject::connect(packetManager, SIGNAL(memoDownloadReply(const MemoItem& )), detailWin, SLOT(slotUpdateMemo(const MemoItem& )));
		TQObject::connect(packetManager, SIGNAL(memoNoMemoFound()), detailWin, SLOT(slotNoMemoFound()));
	
		TQObject::connect(detailWin, SIGNAL(requestUploadMemo(const unsigned int, const MemoItem&)), packetManager, SLOT(doUploadMemo(const unsigned int, const MemoItem&)));
		TQObject::connect(packetManager, SIGNAL( memoUploadReply(const bool)), detailWin, SLOT(slotUploadMemoReply(const bool)));
		
		TQObject::connect(detailWin, SIGNAL(memoChanged(const unsigned int, const MemoItem &)), this, SLOT(slotUserMemoChanged(const unsigned int, const MemoItem &)));
	        
		detailWin->show();
	}
}

void EvaMain::slotRequestChat(const unsigned int id)
{
	TQQFriend *frd = user->getFriendList().getFriend(id);
	g_mainWin->gotMessage(id);
	tray->gotTxtMessage(id);
	g_ChatWindowManager->openChatWindow(frd);
}

void EvaMain::slotRequestSendFile(const unsigned int id)
{
	TQQFriend *frd = user->getFriendList().getFriend(id);
	g_mainWin->gotMessage(id);
	tray->gotTxtMessage(id);
	g_ChatWindowManager->openChatWindow(frd, true);
}

void EvaMain::slotRequestLevel(const unsigned int id)
{
	if(GetLoginManager()->isLoggedIn())
		packetManager->requestFriendLevel(id);
}

void EvaMain::slotRequestHistory(const unsigned int id)
{
	TQQFriend *frd = user->getFriendList().getFriend(id);
	TQString nick = codec->toUnicode(frd->getNick().c_str());
	
	EvaChatWindow *win = g_ChatWindowManager->getWindow(id);
	EvaHistoryViewer *viewer = new EvaHistoryViewer(id, nick, user->getSetting());
	
	//int faceId = atoi(user->getDetails().at(ContactInfo::Info_face).c_str());
	unsigned short faceId = frd->getFace();
	TQPixmap *face = images->getFaceByID(faceId);
	viewer->setIcon(*face);
	
	if(win){
		TQObject::connect(viewer, SIGNAL(historyDoubleClicked(unsigned int, TQString, unsigned int, TQString, bool,
					 TQString, TQDateTime, const char, 
					const bool, const bool, const bool, 
					const char, const char, const char)), 
				win, 
				SLOT(slotAddMessage(unsigned int, TQString, unsigned int, TQString, bool,
					 TQString, TQDateTime, const char, 
					const bool, const bool, const bool, 
					const char, const char, const char)));
		viewer->move(win->x(), win->y() + win->height() + 25);
	}else{
		TQRect scr = TDEApplication::desktop()->screenGeometry();    
		viewer->move(scr.center() - viewer->rect().center());
	}
	viewer->show();

}

void EvaMain::slotRequestTQQShow(const unsigned int id)
{
	images->requestTQQShow(id);
}

void EvaMain::slotRequestMyTQQShow()
{
	slotRequestTQQShow(user->getQQ());
}

void EvaMain::slotTQQShowReady( const unsigned int id)
{
	if(id == user->getQQ())
		g_ChatWindowManager->slotMyTQQShowReady();
	else
		g_ChatWindowManager->slotBuddyTQQShowReady(id);
}

void EvaMain::slotRequestSearch( )
{
	EvaSearchWindow *win = new EvaSearchWindow(images, packetManager->getNumOnlineUsers(), 0, "Searching");

	TQObject::connect(win, SIGNAL(requestUserInfo(const unsigned int)), this, SLOT(slotRequestDetails(const unsigned int)));
	
	TQObject::connect(win, SIGNAL(requestSearchUsers(const bool, const TQString, const TQString, const TQString, const TQString, const bool)),
			packetManager, SLOT(doSearchUsers(const bool, const TQString, const TQString, const TQString, const TQString, const bool)));
	
//	TQObject::connect(win, SIGNAL(requestBuddyAuthStatus(const int, const short, const TQString&)), 
//				SLOT(slotRequestBuddyAuthStatus(const int, const short, const TQString&)));
// 	TQObject::connect(win, SIGNAL(requestAddBuddy(const unsigned int, const TQString, const unsigned short)),
// 			g_AddingManager, SLOT(slotAddBuddy(const unsigned int, const TQString, const unsigned short)) );

	TQObject::connect(win, SIGNAL(requestAdvancedSearch(const int, const bool, const bool, const int, const int, const int, const int)),
			packetManager, SLOT(doAdvancedSearch(const int, const bool, const bool, const int, const int, const int, const int)));
	
	TQObject::connect(packetManager, SIGNAL(searchUsersReady(const bool, const std::list<OnlineUser>)),
			win, SLOT(slotSearchUsersReady(const bool, const std::list<OnlineUser>)));
			
	TQObject::connect(packetManager, SIGNAL(advancedSearchReady(const int, const bool, const std::list<AdvancedUser>)),
			win, SLOT(slotAdvancedSearchReady(const int, const bool, const std::list<AdvancedUser>)));
	
	TQObject::connect(win, SIGNAL(requestQunSearch(const unsigned int)), packetManager, SLOT(doSearchQun(const unsigned int)));
	TQObject::connect(packetManager, SIGNAL(qunSearchReady(const std::list<QunInfo>, TQString)),
			win, SLOT(slotQunSearchReady(const std::list<QunInfo>, TQString)));
	
	//TQObject::connect(win, SIGNAL(requestQunInfo(const unsigned int)), this, SLOT(slotRequestQunDetails(const unsigned int)));
	
	/*TQObject::connect(win, SIGNAL(requestUserInfo(const int)), this, SLOT(slotRequestDetails(const int)));
	TQObject::connect(win, SIGNAL(requestAddAuthBuddy(const int, const TQString &)), 
			packetManager, 
			SLOT(doAddAuthBuddy(const int , const TQString &)));
	TQObject::connect(win, SIGNAL(requestAddBuddy(const int)), packetManager, SLOT(doAddBuddy(const int)));
	TQObject::connect(win, SIGNAL(requestSearchQun(const int)), packetManager, SLOT(doSearchQun(const int)));
	TQObject::connect(win, SIGNAL(requestJoinQun(const int)), packetManager, SLOT(doJoinQun(const int)));
	TQObject::connect(win, SIGNAL(requestJoinQunAuth(const int, const TQString &)), packetManager, SLOT(doJoinQunAuth(const int, const TQString &)));
	
	
	TQObject::connect(packetManager, SIGNAL(addBuddyReady()), win, SLOT(slotAddBuddyReady()));
	TQObject::connect(packetManager, SIGNAL(addBuddyRejected()), win, SLOT(slotAddBuddyRejected()));
	TQObject::connect(packetManager, SIGNAL(addBuddyNeedAuth()), win, SLOT(slotBuddyNeedAuth()));
	TQObject::connect(packetManager, SIGNAL(addBuddySentToServer(bool)), win, SLOT(slotAddBuddySentToServer(bool)));
	TQObject::connect(packetManager, SIGNAL(qunSearchReady(const std::list<QunInfo>, TQString)), 
			win, SLOT(slotQunSearchReady(const std::list<QunInfo>, TQString)));
	TQObject::connect(packetManager, SIGNAL(qunJoinReplyOK(const int)), win, SLOT(slotQunJoinReplyOK(const int)));
	TQObject::connect(packetManager, SIGNAL(qunJoinReplyNeedAuth(const int)), win, SLOT(slotQunJoinReplyNeedAuth(const int)));
	TQObject::connect(packetManager, SIGNAL(qunJoinReplyDenied(const int)), win, SLOT(slotQunJoinReplyDenied(const int)));
	TQObject::connect(packetManager, SIGNAL(qunJoinAuthReply(const int)), win, SLOT(slotQunJoinAuthReply(const int)));*/
	
	TQRect scr = TDEApplication::desktop()->screenGeometry();    
	win->move(scr.center() - win->rect().center());	
	win->show();
}

// void EvaMain::slotSystemMeBeenAdded(unsigned int)
// {
// 	if(user->getSetting()->isSoundEnabled())
// 		global->getSoundResource()->playSysMessage();
// }

// void EvaMain::slotSystemAddMeRequest(unsigned int, TQString)
// {
// 	if(user->getSetting()->isSoundEnabled())
// 		global->getSoundResource()->playSysMessage();
// }

// void EvaMain::slotSystemAddRequestApproved(unsigned int)
// {
// 	if(user->getSetting()->isSoundEnabled())
// 		global->getSoundResource()->playSysMessage();
// }

// void EvaMain::slotSystemAddRequestRejected(unsigned int, TQString)
// {
// 	if(user->getSetting()->isSoundEnabled())
// 		global->getSoundResource()->playSysMessage();
// }

/*
// void EvaMain::slotRequestSystemMessage( )
// {
// 	EvaUserSetting::sysMessage m = user->getSetting()->getLastSysMessage();
// 	if(m.type == 0 && m.from == 0) return;
// 	slotShowSystemMessage( m.messageType, m.type, m.from, m.to, m.message, m.internalQunID);
// }

void EvaMain::slotShowSystemMessage(const short msgType, const uint8_t type, const unsigned int from, const unsigned int to, 
					const TQString message, const unsigned int internalQunID)
{	
	EvaNotifyWindow *win = new EvaNotifyWindow(0);
	if(msgType == SYSTEM_MESSAGE_NORMAL){
		switch(type){
		case 200:
			win->slotAddBuddy(from);
		case TQQ_MSG_SYS_BEING_ADDED:
			win->slotMeBeenAdded( from);
			break;       
		case TQQ_MSG_SYS_ADD_FRIEND_REQUEST:
			win->slotAddMeRequest(from, message);
			break;
		case TQQ_MSG_SYS_ADD_FRIEND_APPROVED:
			win->slotAddRequestApproved(from);
			break;
		case TQQ_MSG_SYS_ADD_FRIEND_REJECTED:
			win->slotAddRequestRejected(from, message);
			break;
		default:
			if(user->getSetting()->isShowSystemBroadcastEnabled())
				win->slotOtherNotification(from, message);
		}
		TQObject::connect(win, SIGNAL(requestUserInfo(const unsigned int)), this, SLOT(slotRequestDetails(const unsigned int)));
		TQObject::connect(win, SIGNAL(requestAddAuthBuddy(const unsigned int, const TQString &)), 
				packetManager, SLOT(doAddAuthBuddy(const unsigned int, const TQString &)));
		TQObject::connect(win, SIGNAL(requestAddBuddy(const unsigned int)), packetManager, SLOT(doAddBuddy(const unsigned int)));
		TQObject::connect(win, SIGNAL(requestApproveBuddy(const unsigned int)), packetManager, SLOT(doApproveBuddy(const unsigned int)));
		TQObject::connect(win, SIGNAL(requestRejectBuddy(const unsigned int, const TQString &)), 
				packetManager, SLOT(doRejectBuddy(const unsigned int, const TQString &)));
		
		TQObject::connect(packetManager, SIGNAL(addBuddyReady()), win, SLOT(slotAddBuddyReady()));
		TQObject::connect(packetManager, SIGNAL(addBuddyRejected()), win, SLOT(slotAddBuddyRejected()));
		TQObject::connect(packetManager, SIGNAL(addBuddyNeedAuth()), win, SLOT(slotBuddyNeedAuth()));
		TQObject::connect(packetManager, SIGNAL(addBuddySentToServer(bool)), win, SLOT(slotAddBuddySentToServer(bool)));
		
		TQObject::connect(packetManager, SIGNAL(systemMeBeenAdded(unsigned int)), win, SLOT(slotMeBeenAdded(unsigned int)));
		TQObject::connect(packetManager, SIGNAL(systemAddMeRequest(unsigned int, TQString)), win, SLOT(slotAddMeRequest(unsigned int, TQString)));
		TQObject::connect(packetManager, SIGNAL(systemAddRequestApproved(unsigned int)), win, SLOT(slotAddRequestApproved(unsigned int)));
		TQObject::connect(packetManager, SIGNAL(systemAddRequestRejected(unsigned int, TQString)), win, SLOT(slotAddRequestRejected(unsigned int, TQString)));
	}else{ // now should be Qun messages
		switch(msgType){
		case TQQ_RECV_IM_CREATE_QUN:
			win->slotQunCreated(from, to, internalQunID);
			break;
		case TQQ_RECV_IM_ADDED_TO_QUN:
			win->slotQunAdded(from, to, internalQunID);
			break;       
		case TQQ_RECV_IM_DELETED_FROM_QUN:
			win->slotQunRemoved(from, to, internalQunID);
			break;
		case TQQ_RECV_IM_REQUEST_JOIN_QUN:
			win->slotQunJoinRequest(from, to, message, internalQunID);
			break;
		case TQQ_RECV_IM_APPROVE_JOIN_QUN:
			win->slotQunRequestApproved(from, to, message, internalQunID);
			break;
		case TQQ_RECV_IM_REJECT_JOIN_QUN:
			win->slotQunRequestRejected(from, to, message, internalQunID);
			break;
		}
		TQObject::connect(win, SIGNAL(requestUserInfo(const unsigned int)), this, SLOT(slotRequestDetails(const unsigned int)));
		TQObject::connect(win, SIGNAL(requestApproveQun(const unsigned int, const unsigned int)), packetManager, SLOT(doApproveQun(const unsigned int, const unsigned int)));
		TQObject::connect(win, SIGNAL(requestRejectQun(const unsigned int, const unsigned int, const TQString &)), 
				packetManager, SLOT(doRejectQun(const unsigned int,const unsigned int, const TQString &)));
		TQObject::connect(packetManager, SIGNAL(qunJoinAuthReply(const unsigned int)), win, SLOT(slotQunJoinAuthReply(const unsigned int)));
	}
	if(user->getSetting()->isShowSystemBroadcastEnabled())
		TQObject::connect(packetManager, SIGNAL(systemNotification(int, TQString)), win, SLOT(slotOtherNotification(int, TQString)));
	TQRect scr = TDEApplication::desktop()->screenGeometry();    
	win->move(scr.center() - win->rect().center());
	win->show();
}
*/

void EvaMain::slotRequestSystemMessages( )
{
	EvaSysHistoryViewer *viewer = new EvaSysHistoryViewer( user->getSetting());
	TQObject::connect(viewer, SIGNAL(historyDoubleClicked( const unsigned short,
								const unsigned char,
								const unsigned int,
								const unsigned int,
								const TQString,
								const unsigned int,
								const unsigned int,
								const unsigned char * , const unsigned short,
								const unsigned char *, const unsigned short)),
			m_SysMsgManager, SLOT(showSysMessage(  const unsigned short,
								const unsigned char,
								const unsigned int,
								const unsigned int,
								const TQString,
								const unsigned int,
								const unsigned int,
								const unsigned char *, const unsigned short ,
								const unsigned char *, const unsigned short)));
	
	TQRect scr = TDEApplication::desktop()->screenGeometry();    
	viewer->move(scr.center() - viewer->rect().center());
	viewer->show();
}

void EvaMain::slotRequestDelete( const unsigned int id)
{
	packetManager->doDeleteBuddy(id);
}

void EvaMain::slotDeleteBuddyReady( unsigned int id, bool ok)
{
	if(ok)
		g_mainWin->deleteBuddy(id);
	else{
		KMessageBox::information(g_mainWin, TQString(i18n("Delete buddy \"%1\" failed.")).arg(id), i18n("Eva Delete Buddy"));
	}
}

void EvaMain::slotRequestSystemSettingWindow( )
{
	TQStringList details;
	if(user->getDetails().at(0)!="-"){
		details = packetManager->convertDetails(user->getDetails());
	
		EvaSysSettingWindow *win = new EvaSysSettingWindow(details, images, user->getSetting(), g_mainWin);
	
		TQObject::connect(win, SIGNAL(requestUpdate(const unsigned int)), packetManager, SLOT(doGetUserInfo(const unsigned int)));
		TQObject::connect(win, SIGNAL(settingChanged()), SLOT(slotUserSettingChanged()));
		TQObject::connect(win, SIGNAL(faceSizeChanged()), SLOT(slotFaceSizeChanged()));
		TQObject::connect(packetManager, SIGNAL(userInfoReady(TQStringList)), win, SLOT(slotDetailsUpdated(TQStringList)));
	
		TQObject::connect(win, SIGNAL(requestUpdateSignature(const TQString)), packetManager, SLOT(doModifySignature( const TQString))); 
		TQObject::connect(win, SIGNAL(requestDeleteSignature()), packetManager,SLOT(doDeleteSignature()));

		TQObject::connect(win, SIGNAL(requestMyAuthQuestionSetting()),
				packetManager, SLOT(doRequestMyAuthQuestionSetting()));
		TQObject::connect(win, SIGNAL(requestMyUpdateQuestion(const TQString &, const TQString &)),
				packetManager, SLOT(doSetMyAuthQuestion(const TQString &, const TQString &)));

		TQObject::connect(packetManager, SIGNAL(receivedMyAuthSettings(const unsigned char,
							const TQString&, const TQString&)), 
				win, SLOT(slotReceivedMyAuthSettings(const unsigned char,
								const TQString&,const TQString &)));
		TQObject::connect(packetManager, SIGNAL(updateAuthSettingResult(const unsigned char, 
								const unsigned char)),
				win, SLOT(slotUpdateAuthSettingResult(const unsigned char,
								const unsigned char)));
	
		TQObject::connect(win, SIGNAL(requestModify(TQStringList, TQString, TQString)),
				packetManager, SLOT(doModifyDetails(TQStringList, TQString, TQString)));	
		TQObject::connect(packetManager, SIGNAL(modifyInfo(bool)), win, SLOT(slotUpdateResult(bool)));
	
		TQObject::connect(packetManager, SIGNAL(signatureModifyReply(const bool)), win, SLOT(slotSignatureReply(const bool)));
		TQObject::connect(packetManager, SIGNAL(signatureDeleteReply(const bool)), win, SLOT(slotSignatureReply(const bool)));
	
		TQObject::connect(win, SIGNAL(requestTQQShow(const unsigned int)), this, SLOT(slotRequestTQQShow(const unsigned int)));
		TQObject::connect(images, SIGNAL(qqShowReady(const unsigned int)), win, SLOT(slotBuddyTQQShowReady(const unsigned int)));
	
	
		packetManager->doGetUserInfo(user->getQQ());
		TQRect scr = TDEApplication::desktop()->screenGeometry();
	
		win->move(scr.center() - win->rect().center());	
		win->show();
		printf("sys setting shown now\n");
	}
	else{
		printf("get user details ERROR,stop init setting window\n!");
	}
}

void EvaMain::slotDeleteMeFrom( const unsigned int id)
{
	if(deleteFromQQ != -1) return;  // make sure we only delete from one friend's list at a moment
	const TQQFriend *frd = user->getFriendList().getFriend(id);
	if(!frd) return;
	TQString nick = codec->toUnicode(frd->getNick().c_str());
	if(KMessageBox::warningYesNo( g_mainWin, TQString(i18n("put \"%1\" into Blacklist, are you sure?")).arg(nick),
			i18n( "Eva Blacklist")) == KMessageBox::No)
		return;
	deleteFromQQ = id;
	packetManager->doDeleteMeFrom(id);
}

void EvaMain::slotDeleteMeReply( bool ok)
{
	if(ok){
		g_mainWin->changeGroupTo(deleteFromQQ, user->getBlackIndex());
		slotGroupChanged(deleteFromQQ, user->getBlackIndex());
		
		deleteFromQQ = -1;
	}else
		KMessageBox::information(g_mainWin, TQString(i18n("Blacklist operation on \"%1\" failed.")).arg(deleteFromQQ),
				i18n("Eva Blacklist"));
}

void EvaMain::slotRequestAddBuddy(const unsigned int id)
{
	//NOTE: this method is no longer used, use adding manager to add buddy instead
	if(KMessageBox::warningYesNo( g_mainWin,
		TQString(i18n("add \"%1\" into your Buddy list?")).arg(id), i18n( "Eva Add Buddy")) == KMessageBox::No)
		return;
		
	//slotShowSystemMessage(SYSTEM_MESSAGE_NORMAL, 200, id, id,"");
}

/*
void EvaMain::slotMyInfoReady( )
{	
// 	TQString myNick = codec->toUnicode(user->getDetails().at(ContactInfo::Info_nick).c_str());
// 	if(myNick.isNull()) myNick = "";
// 	g_mainWin->setCaption(myNick + " - Eva");
// 	int myFaceId = atoi(user->getDetails().at(ContactInfo::Info_face).c_str());
// 	TQPixmap *face = images->getFaceByID(myFaceId);
// 	if(user->hasUserHead()){
// 		TQPixmap *uhPic = images->getUserHeadPixmap(user->getQQ()); // color pixmap
// 		if(uhPic) face = uhPic;
// 	}
// 	g_mainWin->setIcon(*face);
// 	g_mainWin->setMainInfo(user->getQQ(), myNick, face?face:images->getFace(0));
	g_mainWin->updateBuddy(user->getQQ());
	g_ChatWindowManager->setMyName(myNick, user->getQQ());
	
	if(!user->isBuddiesLoaded())
		slotDoDownloadBuddies();
}
*/
void EvaMain::slotQunInfomationReady(unsigned int id, const bool /*ok*/, TQString /*errorMsg*/)
{
	const Qun *qun = user->getQunList()->getQun(id);
	user->saveQunList();
	if(qun){
		g_mainWin->updateQun(id);
	}
}

void EvaMain::slotRequestQunDetails( const unsigned int id)
{
	Qun *qun = user->getQunList()->getQun(id);
	QunDetailsWindow *win;
	if(!qun){
		qun = new Qun(id);
		win = new QunDetailsWindow(qun, false);
		delete qun;
		qun = NULL;
	} else
		win = new QunDetailsWindow(qun);
	
	TQObject::connect(win, SIGNAL(requestQunInfo(const unsigned int)), 
			packetManager, SLOT(doRequestQunInfo(const unsigned int)));
	if(!qun) packetManager->doRequestQunInfo( id);

	TQObject::connect(packetManager, SIGNAL(qunInfomationReady(const unsigned int, const bool, TQString)), 
			win, SLOT(slotQunInfomationReady(const unsigned int, const bool, TQString)));

	TQObject::connect(win, SIGNAL(requestQunCard(const unsigned int, const unsigned int)), packetManager, 
			SLOT(doRequestQunCard( const unsigned int,  const unsigned int)));
	TQObject::connect(win, SIGNAL(requestModifyQunInfo(const unsigned int, unsigned char, unsigned short, TQString, TQString, TQString)), 
			packetManager, SLOT(doModifyQunInfo(const unsigned int, unsigned char, unsigned short, TQString, TQString, TQString)));
	TQObject::connect(packetManager, SIGNAL(qunModifyInfoReply(const unsigned int, const bool, TQString)), 
					win, SLOT(slotModifyQunInfo(const unsigned int, const bool, TQString)));
					
	TQObject::connect(win, SIGNAL(requestModifyQunCard(const unsigned int, const unsigned int, TQString, unsigned char, TQString, TQString, TQString)), 
			packetManager, SLOT(doModifyQunCard(const unsigned int,  const unsigned int, TQString, unsigned char, TQString, TQString, TQString)));
	TQObject::connect(packetManager, SIGNAL(qunModifyQunCardReply(const unsigned int, const bool, const unsigned int, TQString)), 
			win, SLOT(slotModifyQunCardReply( const unsigned int, const bool, const unsigned int, TQString)));
			
	TQObject::connect(win, SIGNAL(requestQunSetAdmin(const unsigned int, const unsigned int, const bool)), 
			packetManager, SLOT(doQunSetAdmin(const unsigned int, const unsigned int, const bool)));
	TQObject::connect(packetManager, SIGNAL(qunSetAdminReply(const unsigned int , const bool , const unsigned int, const bool , TQString)), 
			win, SLOT(slotSetAdmin(const unsigned int, const bool, const unsigned int, const bool, TQString)));

	TQObject::connect(win, SIGNAL(requestQunTransfer(const unsigned int, const unsigned int)), 
			packetManager, SLOT(doQunTransfer(const unsigned int, const unsigned int)));
	TQObject::connect(packetManager, SIGNAL(qunTransferReply(const unsigned int , const bool, const unsigned int, TQString)), 
			win, SLOT(slotTransferQun(const unsigned int, const bool, const unsigned int, TQString)));
			
	TQObject::connect(win, SIGNAL(requestModifyQunMembers(const unsigned int, const std::list<unsigned int>, const bool)), 
			packetManager, SLOT(doModifyQunMembers(const unsigned int, const std::list<unsigned int>, const bool)));
	TQObject::connect(packetManager, SIGNAL(qunModifyQunMembersReply(const unsigned int, const bool, TQString)), 
			win, SLOT(slotModifyQunMembers(const unsigned int, const bool, TQString)));

	TQObject::connect(win, SIGNAL(requestAddBuddy(const unsigned int , const TQString, const unsigned short )),
			g_AddingManager, SLOT(slotAddBuddy(const unsigned int , const TQString, const unsigned short )));
	
	TQObject::connect(packetManager, SIGNAL(qunMemberInfoReady(const unsigned int)), 
			win, SLOT(slotMembersUpdated(const unsigned int)));
			
	TQObject::connect(win, SIGNAL(requestUpdateQunMessageSettings(const unsigned int, const signed char)), 
				SLOT(slotUpdateQunMessageSettings(const unsigned int, const signed char)));
	TQRect scr = TDEApplication::desktop()->screenGeometry();    
	win->move(scr.center() - win->rect().center());
	win->show();
}

void EvaMain::slotRequestQunCardReady(const unsigned int id, const bool ok, const unsigned int qq, TQString realName, const unsigned char gender, 
					TQString phone, TQString email, TQString memo, TQString msg)
{
	Qun *qun = user->getQunList()->getQun(id);
	QunDetailsWindow *win = new QunDetailsWindow(qun);
	win->slotReceivedQunCard(id, ok, qq, realName, gender, phone, email, memo, msg);
	
	TQObject::connect(win, SIGNAL(requestQunInfo(const unsigned int)), 
			packetManager, SLOT(doRequestQunInfo(const unsigned int)));
	TQObject::connect(packetManager, SIGNAL(qunInfomationReady(const unsigned int, const bool, TQString)), 
			win, SLOT(slotQunInfomationReady(const unsigned int, const bool, TQString)));
	
	TQObject::connect(win, SIGNAL(requestModifyQunInfo(const unsigned int, unsigned char, unsigned short, TQString, TQString, TQString)), 
			packetManager, SLOT(doModifyQunInfo(const unsigned int, unsigned char, unsigned short, TQString, TQString, TQString)));
	TQObject::connect(packetManager, SIGNAL(qunModifyInfoReply(const unsigned int, const bool, TQString)), 
					win, SLOT(slotModifyQunInfo(const unsigned int, const bool, TQString)));
					
	TQObject::connect(win, SIGNAL(requestModifyQunCard(const unsigned int, const unsigned int, TQString, unsigned char, TQString, TQString, TQString)), 
			packetManager, SLOT(doModifyQunCard(const unsigned int,  const unsigned int, TQString, unsigned char, TQString, TQString, TQString)));
	TQObject::connect(packetManager, SIGNAL(qunModifyQunCardReply(const unsigned int, const bool, const unsigned int, TQString)), 
			win, SLOT(slotModifyQunCardReply( const unsigned int, const bool, const unsigned int, TQString)));
			
	TQObject::connect(win, SIGNAL(requestQunSetAdmin(const unsigned int, const unsigned int, const bool)), 
			packetManager, SLOT(doQunSetAdmin(const unsigned int, const unsigned int, const bool)));
	TQObject::connect(packetManager, SIGNAL(qunSetAdminReply(const unsigned int , const bool , const unsigned int, const bool , TQString)), 
			win, SLOT(slotSetAdmin(const unsigned int, const bool, const unsigned int, const bool, TQString)));

	TQObject::connect(win, SIGNAL(requestQunTransfer(const unsigned int, const unsigned int)), 
			packetManager, SLOT(doQunTransfer(const unsigned int, const unsigned int)));
	TQObject::connect(packetManager, SIGNAL(qunTransferReply(const unsigned int , const bool, const unsigned int, TQString)), 
			win, SLOT(slotTransferQun(const unsigned int, const bool, const unsigned int, TQString)));
			
	TQObject::connect(win, SIGNAL(requestModifyQunMembers(const unsigned int, const std::list<unsigned int>, const bool)), 
			packetManager, SLOT(doModifyQunMembers(const unsigned int, const std::list<unsigned int>, const bool)));
	TQObject::connect(packetManager, SIGNAL(qunModifyQunMembersReply(const unsigned int, const bool, TQString)), 
			win, SLOT(slotModifyQunMembers(const unsigned int, const bool, TQString)));
	
	TQObject::connect(win, SIGNAL(requestAddBuddy(const unsigned int , const TQString, const unsigned short )),
			g_AddingManager, SLOT(slotAddBuddy(const unsigned int , const TQString, const unsigned short )));

	TQObject::connect(packetManager, SIGNAL(qunMemberInfoReady(const unsigned int)), 
			win, SLOT(slotMembersUpdated(const unsigned int)));
	
	TQObject::connect(win, SIGNAL(requestUpdateQunMessageSettings(const unsigned int, const signed char)), 
				SLOT(slotUpdateQunMessageSettings( const unsigned int, const signed char)));
	TQRect scr = TDEApplication::desktop()->screenGeometry();    
	win->move(scr.center() - win->rect().center());
	win->show();
}

void EvaMain::slotRequestQunHistory( const unsigned int id)
{
	Qun *qun = user->getQunList()->getQun(id);
	TQString qName = i18n("Qun");
	if(qun){
		QunInfo info = qun->getDetails();
		qName = codec->toUnicode(info.getName().c_str());
	}
	
	EvaQunChatWindow *win = g_ChatWindowManager->getQunWindow(id);
	EvaHistoryViewer *viewer = new EvaHistoryViewer(id, qName, user->getSetting(), true);
	
	int faceId = atoi(user->getDetails().at(ContactInfo::Info_face).c_str());
	TQPixmap *face = images->getFaceByID(faceId);
	viewer->setIcon(*face);
	
	if(win){
		TQObject::connect(viewer, SIGNAL(historyDoubleClicked(unsigned int, TQString, unsigned int, TQString, bool,
					 TQString, TQDateTime, const char, 
					const bool, const bool, const bool, 
					const char, const char, const char)), 
				win, 
				SLOT(slotAddMessage(unsigned int, TQString, unsigned int, TQString, bool,
					 TQString, TQDateTime, const char, 
					const bool, const bool, const bool, 
					const char, const char, const char)));
		viewer->move(win->x(), win->y() + win->height() + 25);
	}else{
		TQRect scr = TDEApplication::desktop()->screenGeometry();    
		viewer->move(scr.center() - viewer->rect().center());
	}
	viewer->show();
}

void EvaMain::slotRequestQunChat( const unsigned int id)
{
	Qun *qun = user->getQunList()->getQun(id);
	if(!qun) return;
	g_mainWin->gotQunMessage(id);
	tray->gotTxtMessage(id);
	g_ChatWindowManager->openQunChatWindow(qun);
}

void EvaMain::slotReceivedQunMessage( unsigned int qunID, unsigned int senderQQ, TQString /*msg*/, TQDateTime /*time*/, const char /*fontSize*/, 
				const bool /*u*/, const bool /*i*/, const bool /*b*/, const char /*blue*/, const char /*green*/, const char /*red*/)
{
	//note that: Qun never show tip
	Qun *qun = user->getQunList()->getQun(qunID);
	if(!qun) return;
	if(senderQQ == user->getQQ()) return;
	if(!(g_ChatWindowManager && g_ChatWindowManager->isQunChatWindowExisted(qunID))){
		bool needSound = false;
		switch(qun->getMessageType()){
			case Qun::Popup:
				slotRequestQunChat(qunID);
				g_mainWin->addQunToRecentList( qunID);
				needSound = true;
				break;
			case Qun::Numbers:
				g_mainWin->newQunMessage(qunID); 
				break;
			default:
				g_mainWin->newQunMessage(qunID);
				tray->newTxtMessage(qunID, -2); // -2 means qun message;
				needSound = true;
		}
		if(user->getSetting()->isSoundEnabled() && needSound)
			global->getSoundResource()->playNewMessage();
	}
}

void EvaMain::slotQunSystemMessageRequest( const unsigned int /*sender*/, TQString /*message*/)
{
	if(user->getSetting()->isSoundEnabled())
		global->getSoundResource()->playSysMessage();
}

void EvaMain::slotQunPictureReady( const unsigned int id, const TQString fileName , const TQString tmpFileName)
{
	g_ChatWindowManager->slotQunPicReady(id, fileName, tmpFileName);
}

void EvaMain::slotShotcutKeyPressed( )
{
	if(!tray) return;
	int id = tray->getSenderID();
	
	TQQFriend *frd = user->getFriendList().getFriend(id);
	if(frd){
		g_mainWin->gotMessage(id);
		tray->gotTxtMessage(id);
		g_ChatWindowManager->openChatWindow(frd);
		return;
	}
	
	Qun *qun = user->getQunList()->getQun(id);
	if(qun){
		g_mainWin->gotQunMessage(id);
		tray->gotTxtMessage(id);
		g_ChatWindowManager->openQunChatWindow(qun);
		return;
	}
/*	EvaUserSetting::sysMessage m = user->getSetting()->getLastSysMessage();
	if(!(m.type == 0 && m.from == 0)){
		m_SysMsgManager->showSysMessage( m.messageType, m.type, m.from, m.to, m.message, m.internalQunID);
		return;
	}*/	
	m_SysMsgManager->showSysMessage();

	if(!g_mainWin->isVisible()) g_mainWin->show();
	else
		KWin::forceActiveWindow(g_mainWin->winId());
}

void EvaMain::slotQunExitReply( const unsigned int id, const bool ok, TQString msg)
{
	TQString qunName;
	Qun *qun = user->getQunList()->getQun(id);
	if(!qun) qunName = TQString::number(id);
	else
		qunName = codec->toUnicode(qun->getDetails().getName().c_str());
	
	TQString desc;
	if(ok)
		desc = TQString(i18n("You have exited the Qun \"%1\" successfully.")).arg(qunName);
	else
		desc = TQString(i18n("Exit Qun \"%1\" failed\n%2")).arg(qunName).arg(msg);
	
	KMessageBox::information( g_mainWin, desc, i18n("Qun Operation"));
}

void EvaMain::slotDoQunExit( const unsigned int id )
{
	TQString qunName;
	Qun *qun = user->getQunList()->getQun(id);
	if(!qun) qunName = TQString::number(id);
	else
		qunName = codec->toUnicode(qun->getDetails().getName().c_str());
	
	QunInfo info = qun->getDetails();
	TQString msg;
	if(info.getExtID() != 0 && info.getCreator() == user->getQQ()){
		msg = TQString(i18n("You are the creator of Qun \"%1\", if you exit this Qun this Qun will be deleted, are you sure?")).arg(qunName);
	}else{
		msg = TQString(i18n("Are you sure you want to exit Qun \"%1\"?")).arg(qunName);
	}
	if(KMessageBox::questionYesNo(g_mainWin, msg, i18n("Qun Operation")) != KMessageBox::No)
		packetManager->doQunExit(id);
}

void EvaMain::slotQunCreateFailed(TQString msg)
{
	KMessageBox::information(g_mainWin, msg, i18n("Qun Operation"));
}

void EvaMain::slotQunCreate( )
{
	EvaQunCreateWindow *win = new EvaQunCreateWindow();
	TQObject::connect(win, SIGNAL(doQunCreate(const TQString &, const unsigned short, const unsigned char, const TQString &, 
					const TQString &, const std::list<unsigned int> &)), 
		packetManager, SLOT(doQunCreate(const TQString &, const unsigned short, const unsigned char, const TQString &, 
					const TQString &, const std::list<unsigned int> &)));
	TQObject::connect(packetManager, SIGNAL(qunCreateDone(const unsigned int)), win, SLOT(slotQunCreateDone(const unsigned int)));
	TQObject::connect(packetManager, SIGNAL(qunCreateFailed(TQString)), win, SLOT(slotQunCreateFailed(TQString)));
	win->show();
}

void EvaMain::slotFriendSignatureChanged( const unsigned int qq, const TQDateTime /*time*/, const TQString signature )
{
	
	const TQQFriend *frd = (user->getFriendList()).getFriend(qq);
	if(frd){
		if(g_mainWin) g_mainWin->updateBuddy(qq);
		TQString nick = codec->toUnicode(frd->getNick().c_str());
		nick = nick + "(" + i18n("signature") + ")" ;
		EvaTipWindow *tip = new EvaTipWindow(images, nick, qq, frd->getFace(), signature);
		TQObject::connect(tip, SIGNAL(requestChat(const unsigned int)), SLOT(slotRequestChat(const unsigned int)));
		tip->show();
	}else{
		printf("buddy %d not in list\n", qq);
	}	
}

/** we simply request the qun information which will update all details */
// void EvaMain::slotRequestQunMembers( const unsigned int id)
// {
// 	packetManager->doRequestQunInfo(id);
// }

void EvaMain::slotUpdateQunMessageSettings( const unsigned int id, const signed char type )
{
	Qun *qun = user->getQunList()->getQun(id);
	if(!qun) return;
	qun->setMessageType((Qun::MessageType)type);
	printf("EvaMain::slotUpdateQunMessageSettings -- qun messageType: %d\n", 0xff&type);
	user->saveQunList();
}

void EvaMain::slotUpdateShortcut( )
{
	if(accelKey) delete accelKey;
	accelKey  = new TDEGlobalAccel(this, "Eva Short Key");
	accelKey->insert("Eva Global Key", i18n("Eva Global Key"), 
			i18n("This action allows you to read your new Eva message globally."),
			user->getSetting()->getMessageShortcut(), KKey::QtWIN+Key_F12, this, SLOT(slotShotcutKeyPressed( )));
	if(!accelKey->updateConnections())
		kdDebug() << "F12 Key registered failed!" << endl;
}

void EvaMain::slotFaceSizeChanged()
{
	g_mainWin->slotFaceSizeChanged();
}

void EvaMain::slotUserSettingChanged( )
{
	slotUpdateShortcut();
	user->getSetting()->setNeedRepaint(true);
	// set face size will reload all face images as well
	global->setFaceSize(TQSize(user->getSetting()->getFaceSize()));
	uhManager->initiate(user->getSetting()->getFaceSize());
	if(images){
		images->setUserHeadImage(uhManager->getOnList(), uhManager->getOffList());
	}	
	TQString newSoundDir=user->getSetting()->getSoundDir();
	if(!newSoundDir.isEmpty()){
		global->getSoundResource()->setSoundDir(newSoundDir);
	}
	g_mainWin->repaint();
	initUserLeaveMenu();
	idt->setMaxIdle(user->getSetting()->getIdleMaxTime());
	idt->stopIdleDetection();
	idt->startIdleDetection();
				
}
/*
void EvaMain::slotLoginProcessReady( )
{
	printf("user login process done!\n");
	packetManager->lastLoginStep();
	//TQTimer::singleShot( 500,  connecter, SLOT(slotClientReady()));
}*/

void EvaMain::slotAddAnonymous(const unsigned int id, const unsigned short/* face*/)
{
	if(g_mainWin){
// 		TQString nick = TQString::number(id);
// 		g_mainWin->addBuddy(nick, (int)id, TQString(""), EvaUser::getAnonymousIndex(),
// 				images->getFaceByID(face, true), images->getFaceByID(face, false));
		g_mainWin->addBuddy(id);
	}
}

void EvaMain::slotExtraInfoReady( )
{
	if(uhManager){
		uhManager->stop();
		uhManager->wait();
		delete uhManager;
		uhManager = NULL;
	}
	
	uhManager = new EvaUHManager(this, user->getSetting()->getUserHeadDir());
	uhManager->initiate(global->getFaceSize());
	
	std::list<unsigned int> list = user->getFriendList().getUserHeadList(user->getQQ(), user->hasUserHead());
	if(list.size()){
		uhManager->setTQQList(list);
		uhManager->start();
	}
	
}

void EvaMain::customEvent( TQCustomEvent * e )
{
// 	if(e->type() == EvaUserHeadReadyEvent){
// 		EvaUHReadyEvent *event = (EvaUHReadyEvent *)e;
// 		unsigned int id = event->getQQ();
// 		TQImage imgOn = event->getOnImage();
// 		TQImage imgOff = event->getOffImage();
// 		if(images){
// 			images->addUserHeadImage(id, imgOn, imgOff);
// 			if(id == user->getQQ()){
// 				slotMyInfoReady( );
// 			}
// 			g_mainWin->updateBuddy(id);
// 		}
// 	}
	switch(e->type()){
		case EvaUserHeadReadyEvent:
		{
			EvaUHReadyEvent *event = (EvaUHReadyEvent *)e;
			unsigned int id = event->getQQ();
			TQImage imgOn = event->getOnImage();
			TQImage imgOff = event->getOffImage();
			if(images){
				images->addUserHeadImage(id, imgOn, imgOff);
// 				if(id == user->getQQ()){
// 					slotMyInfoReady( );
// 				}
				g_mainWin->updateBuddy(id);
			}
			
		}
			break;
		case EvaEventNotify:
			dispatchEvaEvent((EvaNotifyEvent *)e);
			break;
		default:break;
	}
}

void EvaMain::slotUserMemoChanged(const unsigned int id ,const MemoItem &memo)
{
	TQString memoName = memo.name.c_str();
	user->getFriendList().setMemo(id, memo);
	user->saveGroupedBuddyList();
	g_mainWin->updateBuddy(id);
}

void EvaMain::slotModifyMemo(const unsigned int id )
{
	TQStringList details;
	details.append(TQString::number(id));
	
	const TQQFriend *frd = (user->getFriendList()).getFriend(id); 
	if(frd){
		std::string qq = frd->getUserInformation().at(0);
		if(qq!="-")
			details = packetManager->convertDetails(frd->getUserInformation());
	}
	
	EvaDetailsWindow *detailWin;
	detailWin = new EvaDetailsWindow(details);
	TQObject::connect(detailWin, SIGNAL(requestUpdate(const unsigned int)), packetManager, SLOT(doGetUserInfo(const unsigned int)));
	TQObject::connect(detailWin, SIGNAL(requestTQQShow(const unsigned int)), this, SLOT(slotRequestTQQShow(const unsigned int)));
	TQObject::connect(packetManager, SIGNAL(userInfoReady(TQStringList)), detailWin, SLOT(slotDetailsUpdated(TQStringList)));
	TQObject::connect(images, SIGNAL(qqShowReady(const unsigned int)), detailWin, SLOT(slotBuddyTQQShowReady(const unsigned int)));
	
	TQObject::connect(detailWin, SIGNAL(requestDownloadMemo(const unsigned int )), packetManager, SLOT(doDownloadMemo(const unsigned int )));
	TQObject::connect(packetManager, SIGNAL(memoDownloadReply(const MemoItem& )), detailWin, SLOT(slotUpdateMemo(const MemoItem& )));
	TQObject::connect(packetManager, SIGNAL(memoNoMemoFound()), detailWin, SLOT(slotNoMemoFound()));
	TQObject::connect(detailWin, SIGNAL(requestUploadMemo(const unsigned int, const MemoItem&)), 
				packetManager, SLOT(doUploadMemo(const unsigned int, const MemoItem&)));
	TQObject::connect(packetManager, SIGNAL( memoUploadReply(const bool)), detailWin, SLOT(slotUploadMemoReply(const bool)));
	TQObject::connect(detailWin, SIGNAL(memoChanged(const unsigned int, const MemoItem &)), 
				SLOT(slotUserMemoChanged(const unsigned int, const MemoItem &)));
	     
	detailWin->twTabMain->setCurrentPage(2);
	detailWin->show();
}

void EvaMain::slotFileTransferSend( const unsigned int receiver, const unsigned int session,
				const TQValueList<TQString> fileNameList,
				const TQValueList<unsigned int> sizeList, const unsigned char transferType)
{
	if(user->getFriendList().hasFriend(receiver)){
		TQValueListConstIterator<TQString> iter = fileNameList.begin();
		if(iter == fileNameList.end()) return;
		TQString fileName = *iter;
		TQString dir = fileName.left(fileName.findRev("/"));
		//printf("evamain::slotFileTransferSend -- dir:%s\n", dir.ascii());
		TQString file = fileName.right(fileName.length() - fileName.findRev("/") - 1);
		unsigned int size = sizeList.first();
		if(packetManager)
			packetManager->doSendFileUdpRequest(receiver, file, size, session, transferType);
		TQValueList<TQString> dirList;
		TQValueList<TQString> fileList;
		for(iter = fileNameList.begin(); iter != fileNameList.end(); ++iter){
			dir = (*iter).left((*iter).findRev("/"));
			file = (*iter).right((*iter).length() - (*iter).findRev("/") - 1);
			dirList.append(dir);
			fileList.append(file);
		}
		// create udp upload session
		if(m_FileManager){
			m_FileManager->newSession(receiver, session, dirList, fileList, sizeList, false, transferType);
		}
	}
}

void EvaMain::slotFileTransferAccept( const unsigned int receiver, const unsigned int session, const TQString dir,
					const unsigned char transferType)
{
	printf("EvaMain::slotFileTransferAccept -- session: %d\tdir:%s\n", session, dir.ascii());
	if(m_FileManager && !(dir.isEmpty()))
		m_FileManager->saveFileTo(receiver, session, dir);
	if(packetManager)
		packetManager->doAcceptFileRequest(receiver, session, user->getLoginWanIp(), transferType);
}

void EvaMain::slotFileTransferCancel( const unsigned int  receiver, const unsigned int session)
{
	if(packetManager){
		unsigned char type = m_FileManager->getTransferType(receiver, session);
		if(type == TQQ_TRANSFER_IMAGE) return;
		if(packetManager)
			packetManager->doCancelFileRequest(receiver, session, 
					m_FileManager->getTransferType(receiver, session));
	}
	if(m_FileManager)
		m_FileManager->stopThread(receiver, session);
}

void EvaMain::slotReceivedFileRequest( const unsigned int id,  const unsigned int session,
					const TQString file, const int size,
					const unsigned char transferType)
{
	TQQFriend *frd = user->getFriendList().getFriend(id);
	if(g_ChatWindowManager && frd){
		if(m_FileManager){
			printf("EvaMain::slotReceivedFileRequest: -- new session: %d\n", session);
			TQValueList<TQString> dirList;
			TQValueList<TQString> fileList;
			TQValueList<unsigned int> sizeList;
			switch(transferType){
			case TQQ_TRANSFER_IMAGE:
				dirList.append(user->getSetting()->getPictureCacheDir());
				tray->gotTxtMessage( id); // since the chat win will show very shortly,
							// we cancel the face flashing
				break;
			case TQQ_TRANSFER_FILE:
				dirList.append(sysSetting->defaultDownloadDir());
				break;
			default:
				dirList.append(sysSetting->defaultDownloadDir());
			}
			fileList.append(file);
			sizeList.append(size);
			// create udp download session, and wait for ip notification from your friend
			m_FileManager->newSession(id, session, dirList, fileList, sizeList, true, transferType);
			g_ChatWindowManager->slotReceivedFileRequest(frd, session, file, size, transferType);
		}
	}
}

void EvaMain::slotReceivedFileAccepted(const unsigned int id, const unsigned int session,
					const unsigned int /*ip*/, const bool isAccepted,
					const unsigned char transferType)
{
	if(g_ChatWindowManager){
		g_ChatWindowManager->slotReceivedFileAccepted(id, session, isAccepted, transferType);
	}
	if(!m_FileManager) return;
	if(isAccepted){
 		// here we start udp upload session while buddy is waiting your ip notification
		// if user is using proxy, we send ip notification directly
		if(loginWin->getConnectionType() == EvaLoginWindow::HTTP_Proxy)
			slotNotifyAddressRequest(id, session, 0, 0, 0, 0, 0);
		else
			m_FileManager->startSession(id, session);
	} else {
		m_FileManager->stopThread(id, session);
	}
}

void EvaMain::slotNotifyTransferStatus(const unsigned int id, const unsigned int session, const unsigned int size,
				const unsigned int bytesSent, const int time)
{
	printf("Buddy:%d\tsession:0x%8x size:%d\t sent:%d\ttime:%d secs\n", id, session, size, bytesSent, time);
	KURL url;
	url.setPath(m_FileManager->getFileName(id, session, true));
	if(g_ChatWindowManager) 
		g_ChatWindowManager->slotFileStatusNotification(id, session, url, size, bytesSent, time);
}

void EvaMain::slotReceivedFileAgentInfo( const unsigned int id, const unsigned int oldSession,
				const unsigned int newSession, const unsigned int ip, 
				const unsigned short port, const unsigned char * key)
{
	if(g_ChatWindowManager)
		g_ChatWindowManager->slotChangeFileSessionTo(id, oldSession, newSession);
	if(m_FileManager){
		// buddy ask you to download the file from relay server
		m_FileManager->changeToAgent(id, oldSession);printf("EvaMain::slotReceivedFileAgentInfo -- changeToAgent\n");
		m_FileManager->changeSessionTo(id, oldSession, newSession);printf("EvaMain::slotReceivedFileAgentInfo -- changeSessionTo\n");
		m_FileManager->setBuddyAgentKey(id, newSession, key);printf("EvaMain::slotReceivedFileAgentInfo -- setBuddyAgentKey\n");
		m_FileManager->setAgentServer(id, newSession, ip, port);printf("EvaMain::slotReceivedFileAgentInfo -- setAgentServer\n");
		m_FileManager->startSession(id, newSession); // we start agent download session
		printf("EvaMain::slotReceivedFileAgentInfo -- startSession\n");
		printf("EvaMain::slotReceivedFileAgentInfo: -- ip:%s\tport:%d\told:%d\tnew:%d\n", 
			TQHostAddress(ip).toString().ascii(), port, oldSession, newSession);
	}
}

void EvaMain::slotReceivedFileNotifyIpEx( const unsigned int id, const bool isSender,
				const unsigned int session,const unsigned char transferType,
				const unsigned int wanIp1, const unsigned short /*wanPort1*/,
				const unsigned int /*wanIp2*/, const unsigned short /*wanPort2*/,
				const unsigned int /*wanIp3*/, const unsigned short /*wanPort3*/,
				const unsigned int /*lanIp1*/, const unsigned short /*lanPort1*/,
				const unsigned int /*lanIp2*/, const unsigned short /*lanPort2*/,
				const unsigned int /*lanIp3*/, const unsigned short /*lanPort3*/,
				const unsigned int /*syncIp*/, const unsigned short /*syncPort*/,
				const unsigned int /*syncSession*/ )
{
	if(isSender) {  // true means buddy started udp upload session
		// we should start udp download session, but now
		// we simply ask buddy to use relay server :)
		packetManager->doNotifyIpEx(id, false, session, transferType, 0,0,  0,0,  0,0,  0,0,  0,0,  0,0,
					 0,0,0);
	}else{ // if I am the sender, I should start udp session connecting to buddy directly
		// but now I ask relay server to do the job
		m_FileManager->changeToAgent(id, session);
		m_FileManager->updateIp(id, session, wanIp1);
		m_FileManager->startSession(id, session); // here we start agent upload session
	}
}

void EvaMain::slotNotifyAddressRequest( const unsigned int id, const unsigned int session, const unsigned int /*synSession*/, 
				const unsigned int /*synIp*/, const unsigned short /*synPort*/,
				const unsigned int /*myIp*/, const unsigned short /*myPort*/)
{
	bool ok = false;
	if(m_FileManager){
		bool isSender = m_FileManager->isSender(id, session, &ok);
		if(!ok) return;
		unsigned char type = m_FileManager->getTransferType(id, session);
		// we send our ip information to buddy
// 		packetManager->doNotifyIpEx(id, isSender, session, 
// 					user->getLoginWanIp(), user->getLoginWanPort()+100,
// 					user->getLoginWanIp(), user->getLoginWanPort()+101,
// 					myIp, myPort,
// 					0x0a010113, user->getLoginLanPort()+15,
// 					0, 0, 0x0a010113, user->getLoginLanPort()+50, synIp, synPort, synSession);
		packetManager->doNotifyIpEx(id, isSender, session, type, 
					0, 0,
					0, 0,
					0, 0,
					0, 0,
					0, 0, 0, 0, 0, 0, 0);
	}
}

void EvaMain::slotIdleTimeUp()
{
	if ( (user->getStatus() == EvaUser::Eva_Online) && (!inIdleStatus)) {
		slotDoLeave();
		inIdleStatus = true;
	}

	return;
}

void EvaMain::slotIdleBack()
{
	if ( (user->getStatus() == EvaUser::Eva_Leave) && (inIdleStatus) ) {
		slotDoOnline();
		inIdleStatus = false;
	}

	return;
}

// void EvaMain::slotLoginVerification( )
// {
// 	EvaLoginVeriWindow *win = new EvaLoginVeriWindow();
// 	TQObject::connect(win, SIGNAL(changeImage()), packetManager, SLOT(doRequestLoginTokenEx()));
// 	TQObject::connect(win, SIGNAL(sendVerifyCode(const TQString &)), 
// 					packetManager, SLOT(doRequestLoginTokenEx( const TQString &) ) );
// 
// 	TQObject::disconnect(packetManager, SIGNAL(loginNeedVerification()), 
// 					this, SLOT(slotLoginVerification()));
// 	TQObject::connect(packetManager, SIGNAL(loginNeedVerification()), 
// 					win, SLOT(slotImageReady()));
// 	TQObject::connect(packetManager, SIGNAL(loginVerifyPassed()), 
// 					win, SLOT(slotVerifyPassed())); 
// 	
// 	TQRect scr = TDEApplication::desktop()->screenGeometry();
// 	//TQRect scr = g_mainWin->rect();
// 	win->move(scr.center() - win->rect().center());
// 	win->show();
// }

void EvaMain::slotBuddyAdded( const unsigned int id, const TQString /*nick*/, const unsigned short /*face*/, const int /*group*/)
{
	//g_mainWin->addBuddy(nick, id, TQString(""), group, images->getFaceByID(face, true), images->getFaceByID(face, false));
	g_mainWin->addBuddy(id);
	packetManager->doGetUserInfo(id);
}

void EvaMain::changeToOnline( )
{
	slotDoOnline();
}

void EvaMain::changeToOffline( )
{
	slotDoOffline();
}

void EvaMain::changeToLeave( )
{
	slotDoLeave();
}

void EvaMain::changeToInvisible( )
{
	slotDoInvisible();
}

void EvaMain::changeNick( TQString nick )
{
	TQStringList details = packetManager->convertDetails( user->getDetails() );
	details[ContactInfo::Info_nick] = nick;
	packetManager->doModifyDetails(details);
}

void EvaMain::changeSignature( TQString contents )
{
	packetManager->doModifySignature( contents );
}

void EvaMain::sendToContact( unsigned int id, TQString msg )
{
	packetManager->doSendMessage(id , true , msg);
}

void EvaMain::sendToQun( unsigned int ext, TQString msg)
{
	Qun *qun = user->getQunList()->getQunByExtID( ext);
	if(qun)
		packetManager->doSendQunMessage(qun->getQunID(), msg);
}

void EvaMain::textReady( unsigned int id, TQString text, bool isQun )
{
	if(isQun){
		Qun *qun = user->getQunList()->getQunByExtID( id);
		if(qun){
			EvaQunChatWindow *win = g_ChatWindowManager->getQunWindow(qun->getQunID());
			if(win)
				win->appendText(text);
		}
	} else {
		EvaChatWindow *win = g_ChatWindowManager->getWindow(id);
		if(win)
			win->appendText(text);
	}
}

void EvaMain::imageReady( unsigned int id, TQString path, bool isQun )
{
	TQString destDir = EvaMain::user->getSetting()->getPictureCacheDir();
	
	if(isQun){
		Qun *qun = user->getQunList()->getQunByExtID( id);
		if(qun){
			EvaQunChatWindow *win = g_ChatWindowManager->getQunWindow(qun->getQunID());
			if(win){
				TQString destFile = EvaHelper::generateCustomSmiley(path, destDir);
				if(destFile.isEmpty()) return;
				win->slotAddImageToInputEdit(destFile);
			}
		}
	} else {
		EvaChatWindow *win = g_ChatWindowManager->getWindow(id);
		if(win){			
			TQPixmap cache(path);
			if(cache.isNull()) return;
	
			TQString destFile = TQUuid::createUuid().toString().upper() + ".jpg";
			TQString destFullName = destDir + "/" + destFile ;
			cache.save(destFullName, "JPEG", 100);
			win->slotAddImageToInputEdit(destFile);
		}
	}
}

void EvaMain::openAddFriendDialog( unsigned int id )
{
	g_AddingManager->slotAddBuddy( id);
}

void EvaMain::dispatchEvaEvent( EvaNotifyEvent * e )
{
	assert(e);
	switch(e->m_id){
		case E_Err:
			g_mainWin->UpdateLoginInfo(E_Err + 1, s_ENotify[E_Err]);
			break;
		case E_SvrConnected:
			g_mainWin->UpdateLoginInfo(E_SvrConnected + 1, s_ENotify[E_SvrConnected]);
			break;
		case E_SvrRedirect:
			g_mainWin->UpdateLoginInfo(E_SvrRedirect + 1, s_ENotify[E_SvrRedirect]);
			break;
		case E_SvrLoginFailed:
			g_mainWin->UpdateLoginInfo(E_SvrLoginFailed + 1, s_ENotify[E_SvrLoginFailed]);
			break;
		case E_PwWrong:
			g_mainWin->UpdateLoginInfo(E_PwWrong + 1, s_ENotify[E_PwWrong]);
			g_mainWin->offline();
			tray->setOffline();
			//loggedIn = false;
			GetLoginManager()->setLoggedOut();
			user->setStatus(EvaUser::Eva_Offline);
			numOfLostKeepAlivePackets = 0;
			KMessageBox::information(g_mainWin, e->m_desc, i18n("Eva Login"));
			slotDoChangeUser();
			break;
		case E_LoggedIn:
		{
			g_mainWin->UpdateLoginInfo(E_LoggedIn + 1, s_ENotify[E_LoggedIn]);			
			TDEConfig* config = new TDEConfig( TQDir::homeDirPath() + "/.eva/eva.cfg" );
			config->setGroup("General");
			config->writeEntry("Last Login IP", TQQServer.toString());
			switch(loginWin->getConnectionType()){
				case EvaLoginWindow::UDP:
					config->writeEntry("Server Type", "UDP");
					break;
				case EvaLoginWindow::TCP:
				case EvaLoginWindow::HTTP_Proxy:
					config->writeEntry("Server Type", "TCP");
					break;
				default: break;
			}
			config->sync();
			delete config;
			global->getEvaServers()->resetDefaultIP();
			loginOK();
		}
			break;
		case E_MyInfo:
			g_mainWin->UpdateLoginInfo(E_MyInfo + 1, s_ENotify[E_MyInfo]);
			g_mainWin->updateMyInfo();
			g_ChatWindowManager->setMyName(codec->toUnicode(user->getDetails().at(ContactInfo::Info_nick).c_str()), 
					user->getQQ());
			break;
		case E_KeyFileAgent:
			g_mainWin->UpdateLoginInfo(E_KeyFileAgent + 1, s_ENotify[E_KeyFileAgent]);
			break;
		case E_LoginFinished:
			g_mainWin->UpdateLoginInfo(E_LoginFinished + 1, s_ENotify[E_LoginFinished]);
			//EvaScriptManager::instance();// very urgly way to ensure dcop category Tools registered
			// we should start getting buddy list
			GetContactManager()->fetchContacts();
			break;
		case E_ContactsDownloading:
			g_mainWin->UpdateLoginInfo(E_ContactsDownloading + 1, s_ENotify[E_ContactsDownloading]);
			break;
		case E_ContactsDone:
			g_mainWin->UpdateLoginInfo(E_ContactsDone + 1, s_ENotify[E_ContactsDone]);
			//GetContactManager()->fetchGroupNames();
			break;
		case E_GroupNameDownloadDone:
			g_mainWin->UpdateLoginInfo(E_GroupNameDownloadDone + 1, s_ENotify[E_GroupNameDownloadDone]);
			//GetContactManager()->fetchGroupedFriends();
			break;
		case E_GroupContactsReceived:
			g_mainWin->UpdateLoginInfo(E_GroupContactsReceived + 1, s_ENotify[E_GroupContactsReceived]);
			break;
		case E_GroupContactsDone:
			g_mainWin->UpdateLoginInfo(E_GroupContactsDone + 1, s_ENotify[E_GroupContactsDone]);
			break;
		case E_QunInfoFinished:
		{	
			kdDebug() << "[EvaMain] Qun Info ready" << endl;
			g_mainWin->UpdateLoginInfo(E_QunInfoFinished + 1, s_ENotify[E_QunInfoFinished]);
			const Qun *qun = user->getQunList()->getQun((unsigned int)(e->m_param));
			if(qun){
				g_mainWin->updateQun((unsigned int)(e->m_param));
			}
			//GetContactManager()->fetchQunMembersInfo( (unsigned int)(e->m_param));
		}
			break;
		case E_QunMemberFinished:
			kdDebug() << "[EvaMain] Qun Member ready" << endl;
			g_mainWin->UpdateLoginInfo(E_QunMemberFinished + 1, s_ENotify[E_QunMemberFinished]);
			g_ChatWindowManager->slotQunMemberInfoReady((unsigned int)(e->m_param));
			break;
		case E_ContactDetailDone:
			break;
		case E_SignatureDone:
			break;
		case E_AllSignatureDone:
			break;
		case E_LevelDone:
			break;
		case E_LoginProcessDone:
		{
// 			std::list<int>msgs = g_ChatWindowManager->getMessages();
// 			std::list<int>::iterator itr;
// 			for(itr = msgs.begin(); itr != msgs.end(); ++itr){
// 				g_mainWin->newMessage(*itr);
// 			}
			g_mainWin->UpdateLoginInfo(E_LoginProcessDone + 1, s_ENotify[E_LoginProcessDone]);
			// should be everyting ready(contacts, groups, Quns)
			TQString nick = codec->toUnicode(user->getDetails().at(ContactInfo::Info_nick).c_str());
			int faceId = atoi(user->getDetails().at(ContactInfo::Info_face).c_str());
			
//			g_mainWin->clearList();
			g_mainWin->updateMyInfo();//update my info first
			g_ChatWindowManager->setMyName(nick, user->getQQ());

	
			tray->changeToolTip(user->getQQ(), nick, faceId);			
			g_mainWin->showInfoFrame(false);

			g_mainWin->ShowTab(g_mainWin->m_buddyTabKey);
			
			g_mainWin->updateContacts();
			g_mainWin->updateQuns();
			g_mainWin->updateRecentContacts();

			connecter->slotClientReady();
			packetManager->doRequestExtraInfo();
			packetManager->doGetWeatherForecast(user->getLoginWanIp()); /// get local weather
			
			GetContactManager()->fetchAllLevels();
			GetContactManager()->fetchAllSignatures();

			GetScriptManager()->findScripts();

			packetManager->doGetOnlineFriends();
			if(!onlineFriendTimer->isActive())
				onlineFriendTimer->start(60000, false);
		}
			break;
		default:break;
	}
}

void EvaMain::slotShowScriptManager( )
{
	GetScriptManager()->show();
}
