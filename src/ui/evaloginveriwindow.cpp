/***************************************************************************
 *   Copyright (C) 2007 by yunfan                                          *
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

#include "evaloginveriwindow.h"
#include "evamain.h"
#include "evauser.h"

#include <ntqlabel.h>
#include <ntqpixmap.h>
#include <ntqpushbutton.h>
#include <ntqtoolbutton.h>
#include <ntqlineedit.h>

EvaLoginVeriWindow::EvaLoginVeriWindow(TQWidget *p)
	: EvaLoginVeriUIBase(p, "Verify Window", WType_Dialog)
				//TQt::WStyle_Customize | TQt::WStyle_Title | TQt::WStyle_SysMenu
				 //| TQt::WStyle_NormalBorder | TQt::WDestructiveClose)
{
	slotImageReady();
	TQObject::connect(tbnChangeGraphic, SIGNAL(clicked()), SLOT(slotBtnChangeImageClicked()));
	TQObject::connect(btnOK, SIGNAL(clicked()), SLOT(slotBtnOKClicked()));
	TQObject::connect(btnCancel, SIGNAL(clicked()), SLOT(close()));
}

void EvaLoginVeriWindow::slotImageReady( )
{
	GraphicVerifyCode code = EvaMain::user->getLoginVerifyInfo();
	if(!code.m_Data || !code.m_DataLen) return;
	TQPixmap pix;
	pix.loadFromData(code.m_Data, code.m_DataLen);
	lblGraphic->setPixmap( pix);
	btnOK->setEnabled( true);
	btnOK->setDefault( true);
}

void EvaLoginVeriWindow::slotBtnChangeImageClicked()
{
	GraphicVerifyCode code = EvaMain::user->getNextLoginVerifyInfo();
	if( code.m_SessionTokenLen == 0 || code.m_DataLen == 0){
		emit changeImage();
	} else
		slotImageReady();
}


void EvaLoginVeriWindow::slotBtnOKClicked()
{
	emit sendVerifyCode(leCode->text());
	btnOK->setEnabled( false);
}

void EvaLoginVeriWindow::slotVerifyPassed( )
{
	close();
}






