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
#include "evatextedit.h"
#include <ntqevent.h>

EvaTextEdit::EvaTextEdit(const TQString &text, const TQString &context, TQWidget *parent, const char *name):
		KTextEdit(text, context, parent, name), isEnterSend(false)
{
	setAutoFormatting(TQTextEdit::AutoNone);
	setWrapPolicy(TQTextEdit::AtWordOrDocumentBoundary);
}

EvaTextEdit::EvaTextEdit(TQWidget *parent, const char * name):
		KTextEdit(parent, name), isEnterSend(false)
{
	setAutoFormatting(TQTextEdit::AutoNone);
	setWrapPolicy(TQTextEdit::AtWordOrDocumentBoundary);
}

void EvaTextEdit::keyPressEvent(TQKeyEvent *e)
{

    int para;
    int index;	
    getCursorPosition(&para,&index);
    if ( (e->key() == TQt::Key_Enter) || (e->key() == TQt::Key_Return) ) {
	if ( (e->state() & TQt::ControlButton)==TQt::ControlButton)
        {
    	    if ( !isEnterSend )
    	    {
        	emit keyPressed(e);
        	return;
    	    }
    	}
	else if ( (e->state() | TQt::KeyButtonMask) ) {
    	    if (isEnterSend )
    	    {
        	emit keyPressed(e);
        	return;
    	    }
	}
    }
    KTextEdit::keyPressEvent(e);
    if((e->key() == TQt::Key_Enter) || (e->key() == TQt::Key_Return) ){	
        TQString txt = text();
        txt.replace("</p>\n<p>", "<br />");
        setText(txt);
        setCursorPosition(para, index + 1);
    }
    emit keyPressed(e);
}
