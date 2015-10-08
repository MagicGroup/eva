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

#include "evaaddqunwindow.h"

#include <ntqlabel.h>
#include <ntqlineedit.h>
#include <ntqtoolbutton.h>
#include <ntqpushbutton.h>
#include <ntqtextcodec.h>
#include <ntqevent.h>
#include <ntqiconset.h>
#include <ntqgroupbox.h>

#include <tdemessagebox.h>
#include <tdelocale.h>

#include <list>
#include <string>

#include "../evamain.h"
#include "evaresource.h"
#include "evauser.h" 


EvaAddingQunWindow::EvaAddingQunWindow( )
	: m_Qun()
{
	initWindow();
	TQObject::connect(tbQunDetails, SIGNAL(clicked()), SLOT(slotQunDetailsClicked( )));
	TQObject::connect(tbCreatorDetails, SIGNAL(clicked()), SLOT(slotCreatorDetailsClicked( )));
	TQObject::connect(tbRefresh, SIGNAL(clicked()), SIGNAL(refreshGraphic()));
	TQObject::connect(btnSend, SIGNAL(clicked()), SLOT(slotSendClicked()));
	TQObject::connect(btnCancel, SIGNAL(clicked()), SLOT(close()));	
}

void EvaAddingQunWindow::setQun(const QunInfo &qun)
{
	m_Qun = qun;

	TQPixmap *facePic = EvaMain::images->getFaceByID( 0 );
	TQIconSet faceIcon;
	faceIcon.setPixmap(*facePic,TQIconSet::Large);
	tbQunDetails->setIconSet(faceIcon);

	lblQunExtID->setText(TQString::number(m_Qun.getExtID()));
	lblCreator->setText(TQString::number(m_Qun.getCreator()));
	TQTextCodec *codec=TQTextCodec::codecForName("GB18030");
	lblQunName->setText(codec->toUnicode(m_Qun.getName().c_str()));

	fraAuthGraphic->setHidden(true);
	gbMessage->setHidden(true);
	

	btnSend->setEnabled(false);
	btnCancel->setEnabled( true);

	adjustSize();
}

void EvaAddingQunWindow::initWindow( )
{
	lblQunExtID->setText("");
	lblCreator->setText("");
	lblQunName->setText( "" );

	lblDescription->setText( i18n("Retrieving information from server..."));
	lblGraphic->setPixmap( TQPixmap());
	leCode->setText("");
	leMessage->setText("");
}

void EvaAddingQunWindow::closeEvent( TQCloseEvent * e )
{
	emit requestCancel();
	initWindow();
	e->accept();
}

void EvaAddingQunWindow::slotQunDetailsClicked( )
{
	emit requestQunDetails(m_Qun.getQunID());
}

void EvaAddingQunWindow::slotCreatorDetailsClicked( )
{
	emit requestDetails(m_Qun.getCreator());
}

void EvaAddingQunWindow::slotSendClicked( )
{	
	if( !fraAuthGraphic->isHidden() ){
		if(leCode->text().isEmpty()){
			KMessageBox::information(0, i18n("Enter the right verification code please."),
				i18n("Eva Search/Add Friend"));
			leCode->setFocus();
			return;
		}
	}

	emit requestAdd();
}

void EvaAddingQunWindow::AddingRejected( )
{
	fraAuthGraphic->setHidden(true);
	gbMessage->setHidden(true);
	lblDescription->setText( i18n("Join request rejected by server"));
	
	btnCancel->setText(i18n("&Close"));
	btnSend->setEnabled(true);
	btnCancel->setEnabled( true);
}

void EvaAddingQunWindow::AddingNeedAuth( )
{
	gbMessage->setHidden(false);
	lblDescription->setText( i18n("Authentication needed, please leave your message below."));

	btnSend->setEnabled(true);
	btnCancel->setEnabled( true);
	adjustSize();
}

void EvaAddingQunWindow::updateGraphic( TQPixmap & p )
{
	lblGraphic->setPixmap( p);
	fraAuthGraphic->setHidden(false);
}

/// this method probably will never be executed
/// as No Auth setting still need Authentication
/// for new members. 
void EvaAddingQunWindow::AddingNoAuthReady( )
{
	fraAuthGraphic->setHidden( true);
	gbMessage->setHidden( true);

	TQTextCodec *codec = TQTextCodec::codecForName("GB18030");
	lblDescription->setText( TQString(i18n("You have joined Qun %1(%2)")).arg(codec->toUnicode(m_Qun.getName().c_str())).arg(m_Qun.getExtID()));
	btnSend->setEnabled(false);
	btnCancel->setText(i18n("&Close"));
}

