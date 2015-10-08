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
 
#ifndef EVASYSTEMTRAY_H
#define EVASYSTEMTRAY_H

#include <ksystemtray.h>
#include <ntqvaluestack.h>

class EvaImageResource;
class TDEPopupMenu;
class TQMouseEvent;
class TQTimer;
class TQPixmap;

class EvaSystemTray : public KSystemTray
{
	Q_OBJECT
public:
	EvaSystemTray(TQWidget* parent = 0, const char* name = 0);
	EvaSystemTray():KSystemTray() {}
	~EvaSystemTray();
	
	void setImagesResource(EvaImageResource *res = 0);
	void setupMenus(TDEPopupMenu *sys, TDEPopupMenu *status);
	void reset();
public slots:	
	void changeToolTip(const unsigned int id, const TQString &nick, const short face);
	void setOnline();
	void setOffline();
	void setLeave();
	void setInvisible();
	void setLoginWaiting();
	
	void newTxtMessage(const unsigned int id, short face = 0);
	void gotTxtMessage(const unsigned int id);
	void newSysMessage();
	void gotSysMessage();
	int getSenderID();
signals:
	void requestChat(const unsigned int id);
	void requestQunChat(const unsigned int id);
	void requestSystemMessage();
protected:
	virtual void mousePressEvent(TQMouseEvent *e);
	virtual void mouseDoubleClickEvent( TQMouseEvent *me );
private:
	EvaImageResource *images;
	TDEPopupMenu *sysMenu;
	TDEPopupMenu *statusMenu;
	TQTimer *blinkTimer;
	TQTimer *clickTimer;
	TQPixmap *statusPix;
	bool isBlinkOn;
	
	TQValueStack<int> messageStack; // store user qq id or -1 for system message
	TQValueStack<int> iconStack; // store the corresponding face number or -1 for system message icon
	
	void setIconTo(TQPixmap *pix);
private slots:
	void slotTimeout();
	void slotClickTimeout();
	void minMaxAction();
};

#endif

