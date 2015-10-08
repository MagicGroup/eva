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

#ifndef EVAADDINGNOTICEWINDOW_H 
#define EVAADDINGNOTICEWINDOW_H

#include "evaaddingnoticeuibase.h"
#include <ntqmemarray.h>

class EvaPacketManager;
class TQCloseEvent;

class EvaAddingNoticeWindow : public EvaAddingNoticeUIBase
{
	Q_OBJECT
public:
	EvaAddingNoticeWindow(EvaPacketManager *connecter);

	void setMessage(const unsigned char type, const unsigned int fromID,
			const TQString &msg, const bool allowReverse);

	//void startVerifying(const unsigned char *code, const unsigned int codeLen);
signals:
	void requestDetails(const unsigned int id);
	void requestAddBuddy(const unsigned int id, const TQString nick, const unsigned short face);
private:
	EvaPacketManager *m_PacketManager;
	unsigned int m_ID;
	TQString m_Nick;
	unsigned short m_Face;
	unsigned char m_Type;
	TQString m_Message;
	bool m_AllowReverse;
	TQByteArray m_Code;
	bool m_HasVerified;

	void init();
	void processSettings();

	virtual void closeEvent( TQCloseEvent *e);

private slots:
	void slotFaceClicked();
	void slotOkClicked();
	void processAddingRequest();

	void slotAddAuthActionReply(const unsigned int id, const unsigned char auth, const bool ok);
	void slotRejectClicked();

};


#endif
