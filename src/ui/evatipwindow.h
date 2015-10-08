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

#ifndef EVATIPWINDOW_H
#define EVATIPWINDOW_H

#include "evatipuibase.h"

class EvaImageResource;
class TQTimer;

class EvaTipWindow : public EvaTipUIBase
{
	Q_OBJECT
public:
	EvaTipWindow(EvaImageResource *res, const TQString nick, const unsigned int id, const short face, const TQString &message);
	~EvaTipWindow();
signals:
	void requestChat(const unsigned int);
protected:
	//virtual void showEvent(TQShowEvent *);
	//virtual void paintEvent( TQPaintEvent *);
	virtual void mousePressEvent(TQMouseEvent *e);
private:
	EvaImageResource *images;
	TQPixmap *m_BgPixmap;
	unsigned int qqNum;
	int timelast;
	TQTimer *timer;
	TQRect scr;
private slots:
	void slotTimeout();
};

#endif

