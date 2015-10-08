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

#include "evachatview.h"
#include "evahtmlparser.h"
#include "evaresource.h"
#include "evamain.h"
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
#include <tdepopupmenu.h>
#include <tdeapplication.h>
#include <tdelocale.h>

/// defines come from tdehtml/misc/htmltags.h
//#define ATTR_HREF 54
//#define ATTR_TARGET 133
#define ID_IMG    48
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

const TQString EvaChatView::protocolAccept = "cmd://accept";
const TQString EvaChatView::protocolSaveAs = "cmd://saveas";
const TQString EvaChatView::protocolCancel = "cmd://cancel";
const TQString EvaChatView::protocolResume = "cmd://resume";
const TQString EvaChatView::protocolNewOne = "cmd://newone";

EvaChatView::EvaChatView( TQWidget * parent, const char * name )
	: TDEHTMLPart(parent, name), menu(NULL), d(0), buffer(""), m_isScrollAtBottom(true)
{
	//setOnlyLocalReferences(true);
	menu = new TDEPopupMenu(0, "popup");
	copyAction = KStdAction::copy( this, SLOT(copy()), actionCollection());
	copyAction->setText(i18n("&Copy Text"));
	copyAction->setShortcut( TDEShortcut("Ctrl+C"));

	setDNDEnabled(true);
	setAutoloadImages(true);
	view()->setHScrollBarMode(TQScrollView::AlwaysOff);
	
	//setStandardFont("Helvetica");
	//buffer += "<body style=\"font-size:9pt;font-family:Helvetica\">";
	
	TQObject::connect(view(), SIGNAL(finishedLayout()), SLOT(slotScrollToBottom()));
	TQObject::connect(this, SIGNAL(selectionChanged()), SLOT(slotSelectionChanged()));
	TQObject::connect(this, SIGNAL(popupMenu(const TQString &, const TQPoint &)), 
			SLOT(slotPopupMenu(const TQString &, const TQPoint &)));
	TQObject::connect(browserExtension(), SIGNAL(openURLRequest(const KURL &, const KParts::URLArgs &)), 
			SLOT(slotLinkClicked( const KURL &, const KParts::URLArgs &)));
}

EvaChatView::~EvaChatView()
{
	if(menu) delete menu;
	if(d) delete d;
}

TQString EvaChatView::wrapFontAttributes(TQColor color, TQ_UINT8 size,
                                            bool underline, bool italic, bool bold,
                                            TQString contents)
{
	TQString fontHead = "<span style=\"";
	TQString fontSize = "font-size: "+TQString::number((size<=MIN_FONT_SIZE)?MIN_FONT_SIZE:((size>MAX_FONT_SIZE)?MAX_FONT_SIZE:size))+"pt; ";

	TQString fontColor = TQString("color: ") + color.name() + TQString("\" >");
	
	TQString fontStye = "", fontStyeEnd="";
	if(bold){
		fontStye+="<b>";
		fontStyeEnd+="</b>";
	}
	if(italic){
		fontStye+="<i>";
		fontStyeEnd="</i>" + fontStyeEnd;
	}
	if(underline){
		fontStye+="<u>";
		fontStyeEnd="</u>" + fontStyeEnd;
	}
	TQString fontEnd = "</span>";
	TQString ret = fontHead + fontSize + fontColor + fontStye + contents + fontStyeEnd + fontEnd;
	return ret;
}

TQString EvaChatView::wrapNickName(TQString &nick, TQDateTime time, TQColor color, bool isNormal)
{	
	TQString htmlName = nick;
	EvaHtmlParser parser;
	parser.setAbsImagePath(EvaMain::images->getSmileyPath());
	parser.convertToHtml(htmlName, false, true);
	TQString msg = "<span style=\"font-size: 9pt; color: " + color.name() +"\">" + htmlName + " ";
	if(!isNormal)
		msg+=i18n("(Auto-Reply)");

	TQDateTime current = TQDateTime::currentDateTime();
	TQString dateFormat = "hh:mm:ss";
	if(current.date() != time.date())
		dateFormat = "yyyy-MM-dd hh:mm:ss";
	msg+="  "+time.toString(dateFormat) + "</span><br>";
	return msg;
}

void EvaChatView::append( TQString & nick, TQDateTime time, TQColor nameColor, bool isNormal, 
				TQColor msgColor, TQ_UINT8 size, 
				bool underline, bool italic, bool bold, TQString contents )
{
	TQString msg = wrapNickName(nick, time, nameColor, isNormal) + 
			wrapFontAttributes(msgColor, size, underline, italic, bold, contents);
	updateContents(msg);
}

void EvaChatView::updatePicture( const TQString filename , const TQString tmpFileName)
{
	m_isScrollAtBottom =  ( view()->contentsHeight() == (view()->contentsY() +view()->visibleHeight()) );
	buffer.replace(tmpFileName, filename);
	begin();
	write(buffer);
	write("</body>");
	end();
}

void EvaChatView::slotScrollToBottom()
{
	if(m_isScrollAtBottom){
		view()->setContentsPos(view()->contentsX(), view()->contentsHeight() - view()->visibleHeight() );
	}
}

void EvaChatView::slotLinkClicked( const KURL & url, const KParts::URLArgs &/*args*/)
{
	TQString cmd = url.url();
	TQString strSession = cmd.mid(13,cmd.length() - 13);
	bool ok;
	unsigned int session = strSession.toUInt(&ok);
	if(ok){
		if(cmd.startsWith(protocolAccept) ){
			emit fileTransferAcceptRequest(session);
			return;
		}
		if(cmd.startsWith(protocolSaveAs) ){
			emit fileTransferSaveAsRequest(session);
			return;
		}
		if(cmd.startsWith(protocolCancel) ){
			emit fileTransferCancelRequest(session);
			return;
		}
		if(cmd.startsWith(protocolResume) ){
			emit fileTransferResume(session, true);
			return;
		}
		if(cmd.startsWith(protocolNewOne) ){
			emit fileTransferResume(session, false);
			return;
		}
	}

	TQStringList args;
	if(url.isLocalFile()){
		args<<"exec"<< TQString::fromLocal8Bit(url.path().ascii());
	}else{
		args<<"exec" <<cmd;
	}
	kapp->tdeinitExec("kfmclient",args);
}

/*
   we just simplify the process. if we use KParts::BrowserExtension, we have to do
   lots extra work, adding so much classes. so just hack like following.

   grab useful code from TDEHTMLPopupGUIClient(tdehtml_ext.cpp),
   and change a little bit to fit our needs

*/
void EvaChatView::slotPopupMenu( const TQString & _url, const TQPoint & point )
{
	menu->clear();

	bool isImage = false;
	bool hasSelection = TDEHTMLPart::hasSelection();
	KURL url = KURL(_url);

	if(d) delete d;
	d = new MenuPrivateData;
	d->m_url = url;


	DOM::Element e = nodeUnderMouse();
	if ( !e.isNull() && (e.elementId() == ID_IMG) ){
		DOM::HTMLImageElement ie = static_cast<DOM::HTMLImageElement>(e);
		TQString src = ie.src().string();
		d->m_imageURL = KURL(src);
		d->m_suggestedFilename = src.right(src.length() - src.findRev("/") -1);
		isImage=true;
	}

	
	TDEAction *action = 0L;

	if(hasSelection){
		//action =  new TDEAction( i18n( "&Copy Text" ), TDEShortcut("Ctrl+C"), this, SLOT( copy() ),
		//			actionCollection(), "copy" );
		//action = KStdAction::copy( browserExtension(), SLOT(copy()), actionCollection(), "copy");
		//action->setText(i18n("&Copy Text"));
		//action->setEnabled(true);
		copyAction->plug(menu);
		
		// search text
		TQString selectedText = TDEHTMLPart::selectedText();
		if ( selectedText.length()>18 ) {
			selectedText.truncate(15);
			selectedText+="...";
		}
#ifdef HAS_KONTQUEROR
		// Fill search provider entries
		TDEConfig config("kuriikwsfilterrc");
		config.setGroup("General");
		const TQString defaultEngine = config.readEntry("DefaultSearchEngine", "google");
		const char keywordDelimiter = config.readNumEntry("KeywordDelimiter", ':');
		

		// default search provider
		KService::Ptr service = KService::serviceByDesktopPath(TQString("searchproviders/%1.desktop").arg(defaultEngine));
		
		// search provider icon
		TQPixmap icon;
		KURIFilterData data;
		TQStringList list;
		const TQString defaultSearchProviderPrefix = *(service->property("Keys").toStringList().begin()) + keywordDelimiter;
		data.setData( defaultSearchProviderPrefix + TQString("some keyword") );
		list << "kurisearchfilter" << "kuriikwsfilter";
		
		TQString name;
		if ( KURIFilter::self()->filterURI(data, list) ){
			TQString iconPath = locate("cache", KMimeType::favIconForURL(data.uri()) + ".png");
			if ( iconPath.isEmpty() )
				icon = SmallIcon("edit-find");
			else
				icon = TQPixmap( iconPath );
	
			name = service->name();
		} else {
			icon = SmallIcon("google");
			name = "Google";
		}
		
		action = new TDEAction( i18n( "Search '%1' at %2" ).arg( selectedText ).arg( name ), icon, 0, this,
				SLOT( searchProvider() ), actionCollection(), "searchProvider" );
		action->plug(menu);

		// favorite search providers
		TQStringList favoriteEngines;
		favoriteEngines = config.readListEntry("FavoriteSearchEngines"); // for KDE 3.2 API compatibility
		if(favoriteEngines.isEmpty())
			favoriteEngines << "google" << "google_groups" << "google_news" << "webster" << "dmoz" << "wikipedia";
		
		if ( !favoriteEngines.isEmpty()) {
			TDEActionMenu* providerList = new TDEActionMenu( i18n( "Search '%1' At" ).arg( selectedText ), actionCollection(), "searchProviderList" );
			bool hasSubMenus = false;
			TQStringList::ConstIterator it = favoriteEngines.begin();
			for ( ; it != favoriteEngines.end(); ++it ) {
				if (*it==defaultEngine)
					continue;
				service = KService::serviceByDesktopPath(TQString("searchproviders/%1.desktop").arg(*it));
				if (!service)
					continue;
				const TQString searchProviderPrefix = *(service->property("Keys").toStringList().begin()) + keywordDelimiter;
				data.setData( searchProviderPrefix + "some keyword" );
			
				if ( KURIFilter::self()->filterURI(data, list) ) {
					TQString iconPath = locate("cache", KMimeType::favIconForURL(data.uri()) + ".png");
					if ( iconPath.isEmpty() )
						icon = SmallIcon("edit-find");
					else
						icon = TQPixmap( iconPath );
					name = service->name();
			
					providerList->insert( new TDEAction( name, icon, 0, this,
							SLOT( searchProvider() ), actionCollection(), TQString( "searchProvider" + searchProviderPrefix ).latin1() ) );
					hasSubMenus = true;
				}
			}
			if(hasSubMenus) providerList->plug(menu);
		}
#endif // HAS_KONTQUEROR
		if ( selectedText.contains("://") && KURL(selectedText).isValid() ) {
			action = new TDEAction( i18n( "Open '%1'" ).arg( selectedText ), "window_new", 0,
							this, SLOT( openSelection() ), actionCollection(), "openSelection" );
			action->plug(menu);
		}
	}
	if ( !url.isEmpty() ) {
		if (url.protocol() == "mailto")	{
			action = new TDEAction( i18n( "Copy Email Address" ), 0, this, SLOT( slotCopyLinkLocation() ),
					actionCollection(), "copylinklocation" );
			action->plug(menu);
		} else {
			action = new TDEAction( i18n( "Copy &Link Address" ), 0, this, SLOT( slotCopyLinkLocation() ),
					actionCollection(), "copylinklocation" );
			action->plug(menu);
		}
	}

	if (isImage)	{
#ifndef QT_NO_MIMECLIPBOARD
		action = (new TDEAction( i18n( "Copy Image" ), 0, this, SLOT( slotCopyImage() ),
				actionCollection(), "copyimage" ));
		action->plug(menu);
#endif
		action = new TDEAction( i18n( "Save Image As..." ), 0, this, SLOT( slotSaveImageAs() ),
				actionCollection(), "saveimageas" );
		action->plug(menu);

		action = new TDEAction( i18n( "Save As Custom Smiley"), 0, this, SLOT( slotSaveAsCustomSmiley() ),
				actionCollection(), "saveascustomsmiley" );
		action->plug(menu);
	}
	
	if(menu->count()) menu->popup(point);
}

void EvaChatView::copy( )
{
	if(hasSelection()){
		TQString text = selectedText();
		text.replace(TQChar(0xa0), ' ');
		TQApplication::clipboard()->setText( text, TQClipboard::Clipboard );
		TQApplication::clipboard()->setText( text, TQClipboard::Selection );
	}
}

void EvaChatView::searchProvider()
{
	// action name is of form "previewProvider[<searchproviderprefix>:]"
	const TQString searchProviderPrefix = TQString( sender()->name() ).mid( 14 );
	
	KURIFilterData data;
	TQStringList list;
	data.setData( searchProviderPrefix + this->selectedText() );
	list << "kurisearchfilter" << "kuriikwsfilter";
	
	if( !KURIFilter::self()->filterURI(data, list) )
	{
	KDesktopFile file("searchproviders/google.desktop", true, "services");
	data.setData(file.readEntry("Query").replace("\\{@}", this->selectedText()));
	}
	
	KParts::URLArgs args;
	args.frameName = "_blank";
	
	emit slotLinkClicked( data.uri(), args );
}

void EvaChatView::openSelection()
{
	KParts::URLArgs args;
	args.frameName = "_blank";
	
	emit slotLinkClicked( d->m_url, args );
}

void EvaChatView::slotCopyLinkLocation()
{
	KURL safeURL(d->m_url);
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

void EvaChatView::slotCopyImage()
{
#ifndef QT_NO_MIMECLIPBOARD
	KURL safeURL(d->m_imageURL);
	safeURL.setPass(TQString::null);
	
	KURL::List lst;
	lst.append( safeURL );
	KMultipleDrag *drag = new KMultipleDrag(view(), "Image");

	drag->addDragObject( new TQImageDrag(d->m_imageURL.path()) );
	drag->addDragObject( new KURLDrag(lst, view(), "Image URL") );
	
	// Set it in both the mouse selection and in the clipboard
	TQApplication::clipboard()->setData( drag, TQClipboard::Clipboard );
	TQApplication::clipboard()->setData( new KURLDrag(lst), TQClipboard::Selection );
#else
	// do nothing
#endif
}

void EvaChatView::slotSaveImageAs()
{
	TQString name = TQString::fromLatin1("index.html");;
	if ( !d->m_suggestedFilename.isEmpty() )
		name = d->m_suggestedFilename;
	else if ( !d->m_imageURL.fileName().isEmpty() )
		name = d->m_imageURL.fileName();

	KURL destURL;
	int query;
	do {
		query = KMessageBox::Yes;
		destURL = KFileDialog::getSaveURL( TQDir::homeDirPath() + "/" + name, TQString::null, 0, i18n( "Save Image As" ) );
		if( destURL.isLocalFile() ) {
			TQFileInfo info( destURL.path() );
			if( info.exists() ) {
				// TODO: use TDEIO::RenameDlg (shows more information)
				query = KMessageBox::warningContinueCancel( 0, i18n( "A file named \"%1\" already exists. " "Are you sure you want to overwrite it?" ).arg( info.fileName() ), i18n( "Overwrite File?" ), i18n( "Overwrite" ) );
			}
		}
	} while ( query == KMessageBox::Cancel );
	
	if ( destURL.isValid() )
		TDEIO::file_copy(d->m_imageURL, destURL, -1, true /*overwrite*/);
}

void EvaChatView::slotSaveAsCustomSmiley()
{
	emit saveAsCustomSmiley(d->m_imageURL.path());
}

// it seems this method doesn't do the job
void EvaChatView::startDrag( )
{
	TQDragObject *d = new TQTextDrag(selectedText(), view());
	d->dragCopy();
}

void EvaChatView::slotSelectionChanged( )
{
	copyAction->setEnabled( hasSelection() );
}

void EvaChatView::showInfomation( const TQString & info )
{
	TQString picPath = "<img src = \"" + EvaMain::images->getIconFullPath("MSG_INFO") + "\">";
	TQString msg = wrapFontAttributes(TQt::gray, 9, false, false, false, info);
	updateContents("&nbsp;" + picPath + "&nbsp;" + msg );
	showContents();
}

void EvaChatView::showFileNotification( const TQString & who, const TQString & filename, 
			const int size, const unsigned int session, const bool isSend )
{
	TQString strSession = TQString::number(session);
	TQString picPath = "<img src = \"" + EvaMain::images->getIconFullPath("MSG_INFO") + "\">";
	TQString acceptLink = "<a href=\""+ protocolAccept + "_" + strSession + "\">" + i18n("Accept") + "</a>";
	TQString saveAsLink = "<a href=\""+ protocolSaveAs + "_" + strSession + "\">" + i18n("Save As") + "</a>";
        TQString rejectLink = "<a href=\""+ protocolCancel + "_" + strSession + "\">" + i18n("Reject") + "</a>";
	TQString cancelLink = "<a href=\""+ protocolCancel + "_" + strSession + "\">" + i18n("Cancel") + "</a>";
	TQString fileSize = (size<0x400)?(TQString::number(size) + "B"):
			((size<0x100000)?(TQString::number(size/0x400) + "KB") :
			((size<0x40000000)?(TQString::number(size/0x100000) + "MB"):
			(TQString::number(size/0x40000000) + "GB") ) );
	TQString fileInfo = filename + "(" + fileSize + ")";
        TQString txt;
	if(isSend){
		txt = i18n("Waiting for %1 accepting file \"%2\". Please wait or %3.")
				.arg(who).arg(fileInfo).arg(cancelLink);
	}else{
		txt = i18n("%1 wants to send you a file \"%2\", you can %3, %4 or %5.")
				.arg(who).arg(fileInfo).arg(acceptLink).arg(saveAsLink).arg(rejectLink);
	}
	TQString msg = wrapFontAttributes(TQt::gray, 9, false, false, false, txt);
	updateContents("&nbsp;" + picPath + "&nbsp;" + msg );
	showContents();
}

void EvaChatView::updateContents( const TQString & contents )
{
	//TQString newMsg = contents;
	//Wonder why the following line was added, it does nothing other than extra mess spaces.
	//newMsg.replace("&nbsp;", "&nbsp; ");
	buffer += (contents + "<br>");
}

void EvaChatView::showContents()
{
	m_isScrollAtBottom =  ( view()->contentsHeight() == (view()->contentsY() +view()->visibleHeight()) );

	begin();
	write(buffer);
	write("</body>");
	end();
}

void EvaChatView::askResumeMode( const TQString filename, const unsigned int session )
{
	TQString strSession = TQString::number(session);
	TQString picPath = "<img src = \"" + EvaMain::images->getIconFullPath("MSG_INFO") + "\">";
	TQString resumeLink = "<a href=\""+ protocolResume + "_" + strSession + "\">" + 
			i18n("resume") + "</a>";
	TQString restartLink = "<a href=\""+ protocolNewOne + "_" + strSession + "\">" + 
			i18n("start") + "</a>";
	TQString txt = i18n("Cached information of \"%1\" has been found, you can %2 the last download or ignore the last cached download information and %3 a new download.").arg(filename).arg(resumeLink).arg(restartLink);

	TQString msg = wrapFontAttributes(TQt::gray, 9, false, false, false, txt);
	updateContents("&nbsp;" + picPath + "&nbsp;" + msg );
	showContents();
}



