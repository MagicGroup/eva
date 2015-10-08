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
#ifndef EVATEXTEDIT_H
#define EVATEXTEDIT_H

#include <ktextedit.h>
class TQKeyEvent;
class EvaTextEdit : public KTextEdit
{
	Q_OBJECT
public: 
	EvaTextEdit(const TQString &text, const TQString &context=TQString::null, TQWidget *parent=0, const char *name=0);
	EvaTextEdit(TQWidget *parent=0, const char * name=0);
	void setEnterSendEnabled(const bool ok) { isEnterSend = ok; }
signals:
	void keyPressed(TQKeyEvent *);
protected:
	virtual void keyPressEvent(TQKeyEvent *);
private:
	bool isEnterSend;
};

#endif
