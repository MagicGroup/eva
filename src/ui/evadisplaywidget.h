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
#ifndef EVADISPLAYWIDGET_H
#define EVADISPLAYWIDGET_H

#include <ntqwidget.h>
#include <ntqframe.h>
#include <ntqwidgetstack.h>
#include "evamainwindow.h"

class TQLabel;
class KProgress;
class TQSpacerItem;
class TQVBoxLayout;
class TQGridLayout;
class TQWidgetStack;
class EvaTabWidget;

class EvaLoginPageFrame : public TQFrame
{
	Q_OBJECT
public:
	EvaLoginPageFrame(TQWidget* parent = 0, const char* name = 0, WFlags fl = 0);
	virtual ~EvaLoginPageFrame();

	void setTotalSteps(int max);
	void update(int value, const TQString &msg);
private:
	TQLabel* lblDesc;
	KProgress* kpgProgress;
	TQVBoxLayout* layout1;
	TQSpacerItem* spacer1;
	TQSpacerItem* spacer2;
};

class EvaDisplayWidget : public TQWidgetStack
{
	Q_OBJECT
public:
	EvaDisplayWidget(TQWidget* parent = 0, const char* name = 0, WFlags fl = 0);
	virtual ~EvaDisplayWidget();

	/** 
	 * show login information page or contacts page
	 *
	 * @param showInfo display information page if true, false otherwise
	 */
	void showInfoFrame(bool showInfo = false);

private:
	//TQGridLayout* wspageLoginLayout;
	TQGridLayout * layoutLogin;
	TQWidget     * wLogin;
	TQGridLayout * layoutTab;
	TQWidget     * wTab;
	EvaLoginPageFrame * loginPage;
	EvaTabWidget      *tab;
	//TQWidgetStack      * wsMainDisplay;
	
	friend class EvaMainWindow;
};

#endif //EVADISPLAYWIDGET_H

