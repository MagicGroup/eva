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
#include "evascriptwidget.h"

#include <ntqstringlist.h>
#include <ntqtimer.h>
#include <ntqclipboard.h>
#include <ntqfileinfo.h>
#include <ntqdragobject.h>
#include <ntqapplication.h>

#include <tdeaction.h>
#include <tdeconfig.h>
#include <kservice.h>
#include <kurifilter.h>
#include <kmimetype.h>
#include <kstandarddirs.h> // function "locate"
#include <kiconloader.h>   // function "SmallIcon"
#include <kdesktopfile.h>
#include <kurldrag.h>
#include <tdemultipledrag.h>
#include <tdemessagebox.h>
#include <tdefiledialog.h>
#include <tdeio/job.h>
#include <tdeio/jobclasses.h>
#include <tdepopupmenu.h>
#include <tdeapplication.h>
#include <tdelocale.h>
#include <dom/dom_html.h>

#include "evaresource.h"
#include "evamain.h"
#include "createsmileywindow.h"
#include "evascriptmanager.h"
#include "evasetting.h"

/// defines come from tdehtml/misc/htmltags.h
//#define ATTR_HREF 54
//#define ATTR_TARGET 133
#define ID_A 1
#define ID_ABBR 2
#define ID_ACRONYM 3
#define ID_ADDRESS 4
#define ID_APPLET 5
#define ID_AREA 6
#define ID_B 7
#define ID_BASE 8
#define ID_BASEFONT 9
#define ID_BDO 10
#define ID_BIG 11
#define ID_BLOCKTQUOTE 12
#define ID_BODY 13
#define ID_BR 14
#define ID_BUTTON 15
#define ID_CAPTION 16
#define ID_CENTER 17
#define ID_CITE 18
#define ID_CODE 19
#define ID_COL 20
#define ID_COLGROUP 21
#define ID_DD 22
#define ID_DEL 23
#define ID_DFN 24
#define ID_DIR 25
#define ID_DIV 26
#define ID_DL 27
#define ID_DT 28
#define ID_EM 29
#define ID_EMBED 30
#define ID_FIELDSET 31
#define ID_FONT 32
#define ID_FORM 33
#define ID_FRAME 34
#define ID_FRAMESET 35
#define ID_H1 36
#define ID_H2 37
#define ID_H3 38
#define ID_H4 39
#define ID_H5 40
#define ID_H6 41
#define ID_HEAD 42
#define ID_HR 43
#define ID_HTML 44
#define ID_I 45
#define ID_IFRAME 46
#define ID_ILAYER 47
#define ID_IMG 48
#define ID_INPUT 49
#define ID_INS 50
#define ID_ISINDEX 51
#define ID_KBD 52
#define ID_KEYGEN 53
#define ID_LABEL 54
#define ID_LAYER 55
#define ID_LEGEND 56
#define ID_LI 57
#define ID_LINK 58
#define ID_MAP 59
#define ID_MARTQUEE 60
#define ID_MENU 61
#define ID_META 62
#define ID_NOBR 63
#define ID_NOEMBED 64
#define ID_NOFRAMES 65
#define ID_NOSCRIPT 66
#define ID_NOLAYER 67
#define ID_OBJECT 68
#define ID_OL 69
#define ID_OPTGROUP 70
#define ID_OPTION 71
#define ID_P 72
#define ID_PARAM 73
#define ID_PLAINTEXT 74
#define ID_PRE 75
#define ID_Q 76
#define ID_S 77
#define ID_SAMP 78
#define ID_SCRIPT 79
#define ID_SELECT 80
#define ID_SMALL 81
#define ID_SPAN 82
#define ID_STRIKE 83
#define ID_STRONG 84
#define ID_STYLE 85
#define ID_SUB 86
#define ID_SUP 87
#define ID_TABLE 88
#define ID_TBODY 89
#define ID_TD 90
#define ID_TEXTAREA 91
#define ID_TFOOT 92
#define ID_TH 93
#define ID_THEAD 94
#define ID_TITLE 95
#define ID_TR 96
#define ID_TT 97
#define ID_U 98
#define ID_UL 99
#define ID_VAR 100
#define ID_WBR 101
#define ID_XMP 102
#define ID_TEXT 103
#define ID_COMMENT 104
#define ID_CLOSE_TAG 104
#define ID_LAST_TAG 104

#include <dom/html_element.h>
#include <dom/html_image.h>

#define SCROLL_DELAY    200
#define MIN_FONT_SIZE   8
#define MAX_FONT_SIZE   20


class MenuPrivateData
{
	public:
		KURL m_url;
		KURL m_imageURL;
		TQPixmap m_pixmap;
		TQString m_suggestedFilename;
};

EvaScriptWidget::EvaScriptWidget( TQWidget * parent, const char * name )
	: TDEHTMLPart(parent, name), m_menu(NULL), m_d(0)
{
	//setOnlyLocalReferences(true);
	m_menu = new TDEPopupMenu(0, "popup");
	m_copyAction = KStdAction::copy( this, SLOT(slotCopy()), actionCollection());
	m_copyAction->setText(i18n("&Copy Text"));
	m_copyAction->setShortcut( TDEShortcut("Ctrl+C"));
	
	setJScriptEnabled( true);
	setJavaEnabled( true);
	setMetaRefreshEnabled( true);
	setPluginsEnabled( true);
	setDNDEnabled(true);
	setAutoloadImages(true);
	

	TQObject::connect(this, SIGNAL(selectionChanged()), SLOT(slotSelectionChanged()));
	TQObject::connect(this, SIGNAL(popupMenu(const TQString &, const TQPoint &)), 
									 SLOT(slotPopupMenu(const TQString &, const TQPoint &)));
	TQObject::connect(browserExtension(), SIGNAL(openURLRequest(const KURL &, const KParts::URLArgs &)), 
									 SLOT(slotLinkClicked( const KURL &, const KParts::URLArgs &)));
}

EvaScriptWidget::~EvaScriptWidget()
{
	if(m_menu) delete m_menu;
	if(m_d) delete m_d;
}

TQString EvaScriptWidget::getNodeText( DOM::Node & node )
{
	DOM::Node n = node;
	TQString text;
	while(!n.isNull()) {
		if(n.nodeType() == DOM::Node::TEXT_NODE) {
			TQString str = n.nodeValue().string();
			if(!str.isEmpty()) {
				return str;
			}
		}

		DOM::Node next = n.firstChild();
		if(next.isNull())
			next = n.nextSibling();
		n = next;
	}

	if(text.isEmpty())
		return TQString::null;

	int start = 0;
	int end = text.length();

    // Strip leading LFs
	while ((start < end) && (text[start] == '\n'))
		++start;

    // Strip excessive trailing LFs
	while ((start < (end-1)) && (text[end-1] == '\n') && (text[end-2] == '\n'))
		--end;

	return text.mid(start, end-start);
}

void EvaScriptWidget::slotPopupMenu( const TQString & _url, const TQPoint & point )
{	
	DOM::Element e = nodeUnderMouse();
	
	m_menu->clear();

	bool isImage = false;
	bool hasSelection = TDEHTMLPart::hasSelection();
	KURL url = KURL(_url);

	if(m_d) delete m_d;
	m_d = new MenuPrivateData;
	m_d->m_url = url;

	if ( !e.isNull() && (e.elementId() == ID_IMG) ){
		DOM::HTMLImageElement ie = static_cast<DOM::HTMLImageElement>(e);
		TQString src = ie.src().string();
		m_d->m_imageURL = KURL(src);
		m_d->m_suggestedFilename = src.right(src.length() - src.findRev("/") -1);
		isImage=true;
	}
	
	if(!e.isNull() && (e.elementId() == ID_A) ){
		DOM::HTMLAnchorElement ae = static_cast<DOM::HTMLAnchorElement>(e);
		m_d->m_url = KURL(ae.href().string());
	}
	TQString text = getNodeText(e);

	TDEAction *action = 0L;

	if(hasSelection)
		m_copyAction->plug(m_menu);

	if(!text.isEmpty()){
		if( text.endsWith( ".evascript.tar" )     ||
				text.endsWith( ".evascript.tar.bz2" ) ||
				text.endsWith( ".evascript.tar.gz")){
			action = new TDEAction( i18n("Install Eva script"), 0, this, SLOT(slotInstallRemoteScript()),
														actionCollection(), "installscript");
			action->plug(m_menu);
			m_d->m_suggestedFilename = text;
		}
	}
	
	if ( !url.isEmpty() ) {
			action = new TDEAction( i18n( "Open Link in External Browser"), 0, this, SLOT(slotOpenExternalBrower()),
														actionCollection(), "opennewwindow");
			action->plug(m_menu);
	
			if (url.protocol() == "mailto")	{
				action = new TDEAction( i18n( "Copy Email Address" ), 0, this, SLOT( slotCopyLinkLocation() ),
															actionCollection(), "copylinklocation" );
				action->plug(m_menu);
			} else {
				action = new TDEAction( i18n( "Copy &Link Address" ), 0, this, SLOT( slotCopyLinkLocation() ),
															actionCollection(), "copylinklocation" );
				action->plug(m_menu);
			}
	}

	if (isImage)	{
#ifndef QT_NO_MIMECLIPBOARD
		action = (new TDEAction( i18n( "Copy Image" ), 0, this, SLOT( slotCopyImage() ),
							actionCollection(), "copyimage" ));
		action->plug(m_menu);
#endif
		action = new TDEAction( i18n( "Save Image As..." ), 0, this, SLOT( slotSaveImageAs() ),
													actionCollection(), "saveimageas" );
		action->plug(m_menu);

		action = new TDEAction( i18n( "Save As Custom Smiley"), 0, this, SLOT( slotSaveAsCustomSmiley() ),
													actionCollection(), "saveascustomsmiley" );
		action->plug(m_menu);
	}
	
	if(m_menu->count()) m_menu->popup(point);
}

void EvaScriptWidget::slotSelectionChanged( )
{
	m_copyAction->setEnabled( hasSelection() );
}

void EvaScriptWidget::slotOpenExternalBrower()
{
	TQString cmd = m_d->m_url.url();
	TQStringList args;
	if(m_d->m_url.isLocalFile()){
		args<<"exec"<< TQString::fromLocal8Bit(m_d->m_url.path().ascii());
	}else{
		args<<"exec" <<cmd;
	}
	kapp->tdeinitExec("kfmclient",args);
}

void EvaScriptWidget::slotLinkClicked( const KURL & urls, const KParts::URLArgs & )
{
	TQString url = urls.url();
	DOM::Node node = nodeUnderMouse();
	TQString text = getNodeText(node);
	if( !text.isNull() && (
			text.endsWith( ".evascript.tar" ) || 
			text.endsWith( ".evascript.tar.bz2" ) ||
			text.endsWith( ".evascript.tar.gz")) )
	{
		if(m_d) delete m_d;
		m_d = new MenuPrivateData;
		m_d->m_url = url;
		
		if(!node.isNull() && (node.elementId() == ID_A) ){
			DOM::HTMLAnchorElement ae = static_cast<DOM::HTMLAnchorElement>(node);
			m_d->m_url = KURL(ae.href().string());
		}
		m_d->m_suggestedFilename = text;
		int query = KMessageBox::Continue;
		query = KMessageBox::warningContinueCancel(view(), i18n("%1 is an Eva script, \ndo your want to install it?").arg(text),
				i18n("Install Eva script?"), i18n("Install"));
		if(query == KMessageBox::Continue)
			slotInstallRemoteScript();
	} else
		openURL(urls);
}

void EvaScriptWidget::slotCopy( )
{
	if(hasSelection()){
		TQString text = selectedText();
		text.replace(TQChar(0xa0), ' ');
		TQApplication::clipboard()->setText( text, TQClipboard::Clipboard );
		TQApplication::clipboard()->setText( text, TQClipboard::Selection );
	}
}

void EvaScriptWidget::slotCopyLinkLocation( )
{
	KURL safeURL(m_d->m_url);
	safeURL.setPass(TQString::null);
#ifndef QT_NO_MIMECLIPBOARD
	// Set it in both the mouse selection and in the clipboard
	KURL::List lst;
	lst.append( safeURL );
	TQApplication::clipboard()->setData( new KURLDrag( lst ), TQClipboard::Clipboard );
	TQApplication::clipboard()->setData( new KURLDrag( lst ), TQClipboard::Selection );
#else
	TQApplication::clipboard()->setText( safeURL.url() );
#endif
}

void EvaScriptWidget::slotCopyImage( )
{
#ifndef QT_NO_MIMECLIPBOARD
	KURL safeURL(m_d->m_imageURL);
	safeURL.setPass(TQString::null);
	
	KURL::List lst;
	lst.append( safeURL );
	KMultipleDrag *drag = new KMultipleDrag(view(), "Image");

	drag->addDragObject( new TQImageDrag(m_d->m_imageURL.path()) );
	drag->addDragObject( new KURLDrag(lst, view(), "Image URL") );
	
	// Set it in both the mouse selection and in the clipboard
	TQApplication::clipboard()->setData( drag, TQClipboard::Clipboard );
	TQApplication::clipboard()->setData( new KURLDrag(lst), TQClipboard::Selection );
#else
	// do nothing
#endif
}

void EvaScriptWidget::slotSaveImageAs( )
{
	TQString name = TQString::fromLatin1("index.html");;
	if ( !m_d->m_suggestedFilename.isEmpty() )
		name = m_d->m_suggestedFilename;
	else if ( !m_d->m_imageURL.fileName().isEmpty() )
		name = m_d->m_imageURL.fileName();

	KURL destURL;
	int query;
	do {
		query = KMessageBox::Yes;
		destURL = KFileDialog::getSaveURL( TQDir::homeDirPath() + "/" + name, TQString::null, 0, i18n( "Save Image As" ) );
		if( destURL.isLocalFile() ) {
			TQFileInfo info( destURL.path() );
			if( info.exists() ) {
				// TODO: use TDEIO::RenameDlg (shows more information)
				query = KMessageBox::warningContinueCancel( view(), i18n( "A file named \"%1\" already exists. " "Are you sure you want to overwrite it?" ).arg( info.fileName() ), i18n( "Overwrite File?" ), i18n( "Overwrite" ) );
			}
		}
	} while ( query == KMessageBox::Cancel );
	
	if ( destURL.isValid() )
		TDEIO::file_copy(m_d->m_imageURL, destURL, -1, true /*overwrite*/);
}

void EvaScriptWidget::slotSaveAsCustomSmiley( )
{
	CreateSmileyWindow *win = new CreateSmileyWindow(m_d->m_imageURL.path());
	connect(win, SIGNAL(addCustomSmileyReady( bool )), this, SLOT(slotAddCustomSmileyReady( bool )));
	win->show();
}

void EvaScriptWidget::slotInstallRemoteScript( )
{
	KURL srcURL = m_d->m_url;
	
	KURL destURL((EvaMain::global->getEvaSetting()->defaultDownloadDir() + "/" + m_d->m_suggestedFilename));
	if(destURL.isValid()){
		TDEIO::CopyJob * job = TDEIO::copy(srcURL, destURL, false);
		TQObject::connect(job, SIGNAL(copyingDone (TDEIO::Job *, const KURL &, const KURL &, bool , bool )), 
										SLOT(slotDownloadScriptDone (TDEIO::Job *, const KURL &, const KURL &, bool, bool)));
	}
}

void EvaScriptWidget::slotDownloadScriptDone (TDEIO::Job */*job*/, 
			const KURL &/*from*/, 
			const KURL &to, 
			bool /*directory*/, 
			bool /*renamed*/)
{
	TQString message;
	TQString filename = to.url();
	filename = filename.right(filename.length() - strlen("file://"));
	
	GetScriptManager()->slotInstallScript(filename);
}
