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

#ifndef EVALISTVIEW_H
#define EVALISTVIEW_H

#include <ntqlistview.h>
#include <ntqvaluestack.h>
#include <ntqtooltip.h>
#include <ntqcolor.h>
#include <ntqsize.h>
#include <string>
#include <list>
#include <map>

class TQTimer;
class TQPixmap;
class EvaListView;
class TQCustomEvent;
class TQPainter;
class TQColorGroup;
class TQSimpleRichText;
class TQTextCodec;


class EvaLVToolTip : public TQToolTip
{
public:
    EvaLVToolTip(EvaListView *lv, TQToolTipGroup *group = 0);
    virtual ~EvaLVToolTip();
protected:
    void maybeTip(const TQPoint &p);
private:
    EvaListView *m_lv;
};

// list view item types
enum LVIType { E_LVIBuddy, E_LVIGroup, E_LVIQun};

class EvaListViewItem :  public TQListViewItem
{
public:
	EvaListViewItem( TQListViewItem *parent, TQString label, TQPixmap *p = 0);
	EvaListViewItem( TQListView *parent);
	~EvaListViewItem();
	
	virtual void updateIcon(TQPixmap *p);
	// can be rich text
	void setText(const TQString &text);
	
	virtual TQString tip();
	
	virtual void paintCell( TQPainter * painter, const TQColorGroup & colourGroup, int column, int width, int align );
	virtual void paintBranches(TQPainter * p, const TQColorGroup & cg,int w, int y, int h);
	const LVIType type() const { return m_type; }

protected:
	LVIType m_type;
	TQTextCodec *codec;
	TQPixmap *m_icon;
private:
	TQSimpleRichText *m_richText;
	
	friend class EvaListView;
};

class EvaListView : public TQListView 
{
    Q_OBJECT
public:
    EvaListView( TQWidget *parent=0, const char *name =0, WFlags f= 0);
    ~EvaListView();

protected:	
    TQTextCodec *codec;

private:
    EvaLVToolTip *m_tooltip;

    friend class EvaListViewItem;
};

#endif

