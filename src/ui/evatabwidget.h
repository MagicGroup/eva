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

#ifndef EVA_TABWIDGET_H
#define EVA_TABWIDGET_H

#include <ntqwidget.h>
#include <ntqstring.h>
#include <ntqpoint.h>
#include <ntqrect.h>
#include <ntqmap.h>
#include <ntqpixmap.h>
#include <ntqcolor.h>
#include <ntqwidgetstack.h>

class EvaTabToolTip;
class TQMouseEvent;
class TQWheelEvent;
class TQPaintEvent;
class EvaTabWidget;

class EvaTabBar : public TQWidget
{
    Q_OBJECT
public:
    EvaTabBar( TQWidget *parent = 0, const char * name = 0, WFlags f = 0 );
    virtual ~EvaTabBar();

    // return the key of the just created tab
    int addTab(TQString &name, TQPixmap icon, TQString &tip);
    bool removeTab(int key);

    void changeTabTo(int key);
    const int numTabs() const { return m_d.size(); }

    void setGridColor(const TQColor &c) { m_gridColor = c; }
    void setSelectedColor(const TQColor &c) { m_selectedColor = c; }
signals:
    void clicked(int key);

protected:
    void mousePressEvent(TQMouseEvent *e);
    void mouseReleaseEvent( TQMouseEvent *e);
    void mouseMoveEvent( TQMouseEvent *e);
    void wheelEvent ( TQWheelEvent * e );
    void paintEvent( TQPaintEvent *e);
private:

    class TabData{
    public:
        TabData() : name(""), tip(""), icon(0L){}
        TabData(TQString &n, TQPixmap i, TQString t = TQString::null){
            name = n;
            tip = t;
            icon = i;
        }
        ~TabData(){
        }
        void setData(TQString &n, TQPixmap i, TQString t = TQString::null){
            name = n;
            tip = t;
            icon = i;
        }
        TabData operator=( const TabData &rhs){
            name = rhs.name;
            tip = rhs.tip;
            icon = rhs.icon;
            return *this;
        }
        TQString name;
        TQString tip;
        TQPixmap icon;
    };
    int m_CurrentTab;
    int m_Counter;
    TQMap<int, TabData> m_d;
    TQMap<int, int> m_index; // key: seq, data: the key of TabData
    EvaTabToolTip *m_toolTip;

    TQColor m_gridColor;
    TQColor m_selectedColor;
    TQPixmap m_Buffer;
    TQPixmap m_BasePixmap;

    void updateBasePixmap();
    // return the vertical sequence based on the tab key. return -1 if key doesn't exist
    int getTabSequence(int key);
    // return the veritical tab sequence of the point(x,y)
    int getTabSequence(int x, int y);
    // return the key of seq-th tab in vertical order
    int getTabKey(int seq);
    int getTabKey(int x, int y);

    void update();
    TQRect itemRect(const TQPoint &p);
    TQString tip(const TQPoint &p);

    friend class EvaTabWidget;
    friend class EvaTabToolTip;
};



// class EvaTabWidget : public TQWidget
// {
//     Q_OBJECT
// 
// };

class EvaWidgetStack : public TQWidgetStack
{
    Q_OBJECT
    friend class EvaTabWidget;
public:
    EvaWidgetStack( TQWidget *parent = 0, const char * name = 0, WFlags f = 0 );

protected:
    void paintEvent(TQPaintEvent *e);

private:
    int m_CurrentSeq;
    TQColor m_gridColor;
    TQColor m_tabSelectedColor;

public slots:
    void raiseWidget(int id, int seq);

};


class TQHBoxLayout;
class TQGridLayout;

class EvaTabWidget : public TQWidget
{
    Q_OBJECT

public:
    EvaTabWidget( TQWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~EvaTabWidget();

    EvaTabBar* evaTabBar;
    EvaWidgetStack* wsView;
    //TQWidget* WStackPage;

    int addTab(TQString &name, TQPixmap icon, TQString &tip, TQWidget *w);
		TQWidget *getWidget(int id);
    bool removeTab(int key);
    void setGridColor(const TQColor &c);
    void setSelectedColor(const TQColor &c);
protected:
    TQGridLayout* EvaTabWidgetLayout;
    TQHBoxLayout* layout;

public slots:
    void changeTabTo(int key);

};

#endif

