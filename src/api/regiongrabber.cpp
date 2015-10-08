/*
  Copyright (C) 2003 Nadeem Hasan <nhasan@kde.org>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or ( at your option ) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Library General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this library; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
  Boston, MA 02111-1307, USA.
*/

#include "regiongrabber.h"

#include <ntqpainter.h>
#include <ntqpalette.h>
#include <ntqstyle.h>
#include <ntqtimer.h>
#include <ntqtooltip.h>

#include <tdeglobalsettings.h>
#include <tdelocale.h>

SizeTip::SizeTip( TQWidget *parent, const char *name )
    : TQLabel( parent, name, WStyle_Customize | WX11BypassWM |
      WStyle_StaysOnTop | WStyle_NoBorder | WStyle_Tool )
{
  setMargin( 10 );
  setIndent( 5 );
  setFrameStyle( TQFrame::Plain | TQFrame::Box );

  //setPalette( TQToolTip::palette() );
  setPalette( TQPalette(TQt::yellow, TQColor(20,190,255)));
  TQRect deskR = TDEGlobalSettings::desktopGeometry( TQPoint( 0, 0 ) );
  move(deskR.topLeft());
}

void SizeTip::setTip( const TQRect &rect )
{
  TQString des = "<font color=red>" + i18n("Press mouse left button<br>to grab screenshot.") + "</font><p>" + i18n("Size (W x H):");
  TQString tip = "<qt>" + des + TQString("<b><font color=yellow>%1</font></b> x <b><font color=yellow>%2</font></b>").arg( rect.width() )
      .arg( rect.height() ) + "</qt>";

  setText( tip );
  adjustSize();

  positionTip( rect );
}

void SizeTip::positionTip( const TQRect &rect )
{
  TQRect tipRect = geometry();
  tipRect.moveTopLeft( TQPoint( 0, 0 ) );

  if ( rect.intersects( tipRect ) )
  {
    TQRect deskR = TDEGlobalSettings::desktopGeometry( TQPoint( 0, 0 ) );

    tipRect.moveCenter( TQPoint( deskR.width()/2, deskR.height()/2 ) );
    if ( !rect.contains( tipRect, true ) && rect.intersects( tipRect ) )
      tipRect.moveBottomRight( geometry().bottomRight() );
  }

  move( tipRect.topLeft() );
}

RegionGrabber::RegionGrabber()
  : TQWidget( 0, 0 ),
    mouseDown( false ), sizeTip( 0L )
{
  sizeTip = new SizeTip( ( TQWidget * )0L );

//   tipTimer = new TQTimer( this );
//   connect( tipTimer, SIGNAL( timeout() ), SLOT( updateSizeTip() ) );

  TQTimer::singleShot( 200, this, SLOT( initGrabber() ) );
}

RegionGrabber::~RegionGrabber()
{
  delete sizeTip;
}

void RegionGrabber::initGrabber()
{
  pixmap = TQPixmap::grabWindow( tqt_xrootwin() );
  setPaletteBackgroundPixmap( pixmap );

  showFullScreen();

  grabMouse( crossCursor );
  sizeTip->setTip(TQRect(0,0,0,0));
  sizeTip->show();
}

void RegionGrabber::mousePressEvent( TQMouseEvent *e )
{
  if ( e->button() == LeftButton )
  {
    mouseDown = true;
    grabRect = TQRect( e->pos(), e->pos() );
  }
}

void RegionGrabber::mouseMoveEvent( TQMouseEvent *e )
{
  if ( mouseDown )
  {    
    drawRubber();
    grabRect.setBottomRight( e->pos() );
    drawRubber();
    updateSizeTip();
  }
}

void RegionGrabber::mouseReleaseEvent( TQMouseEvent *e )
{
  mouseDown = false;
  drawRubber();
  sizeTip->hide();

  grabRect.setBottomRight( e->pos() );
  grabRect = grabRect.normalize();

  TQPixmap region = TQPixmap::grabWindow( winId(), grabRect.x(), grabRect.y(),
      grabRect.width(), grabRect.height() );

  releaseMouse();

  emit regionGrabbed( region );
}

void RegionGrabber::keyPressEvent( TQKeyEvent *e )
{
  if ( e->key() == Key_Escape )
  {
    releaseMouse();
    emit regionGrabbed( TQPixmap() );
  }
  else
    e->ignore();
}

void RegionGrabber::updateSizeTip()
{
  TQRect rect = grabRect.normalize();

  sizeTip->setTip( rect );
  //sizeTip->show();
}

void RegionGrabber::drawRubber()
{
  TQPainter p;
  p.begin( this );
  p.setRasterOp( NotROP );
  p.setPen( TQPen( color0, 1 ) );
  p.setBrush( NoBrush );

  style().drawPrimitive( TQStyle::PE_FocusRect, &p, grabRect, colorGroup(),
      TQStyle::Style_Default, TQStyleOption( colorGroup().base() ) );

  p.end();
}

#include "regiongrabber.moc"
