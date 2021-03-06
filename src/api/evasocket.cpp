/***************************************************************************
 *   Copyright (C) 2004-2005 by yunfan                                     *
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
#include "evasocket.h"
#include "qmdcodec.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <ntqsocketdevice.h> 
#include <ntqsocketnotifier.h>
#include <ntqapplication.h>
#include <ntqmutex.h>
#include <ntqtimer.h>
#include <ntqstringlist.h>
#include <ntqurl.h>
#include <ntqiodevice.h>
#include <ntqtextstream.h>
#include <ntqdns.h>
#include <ntqcstring.h>
#include <kdebug.h>



/*!
	\class EvaSocket evasocket.h
	\brief The EvaSocket class provides a UDP or TCP connection
	
	It provides a very simple non-blocking socket connection.
	socketWriteNotifier is only used once to notify that the connection is ready
 	to write, after isReady() emited, socketWriteNotifier is disabled unless 
	setHost() is called.
 */
EvaSocket::EvaSocket(const  TQHostAddress &host, const short port, const Type type)
	: socketReadNotifier(NULL), socketWriteNotifier(NULL)
{
	connectionStatus = None;
	receivedLength = 0;
	receivedBuffer = NULL;
	connectionType = type;
        server = host;
	serverPort = port;
	if(connectionType == UDP){
		connectSocket = new TQSocketDevice(TQSocketDevice::Datagram); 
	}else{
		connectSocket = new TQSocketDevice(TQSocketDevice::Stream);
		connectSocket->setBlocking(false);
        	socketWriteNotifier =  new TQSocketNotifier(connectSocket->socket(),
							TQSocketNotifier::Write,0,"writeNotifier");
		TQObject::connect(socketWriteNotifier,SIGNAL(activated(int)),SLOT(slotWriteReady(int)));
		socketWriteNotifier->setEnabled(false);
	}
	socketReadNotifier = new TQSocketNotifier(connectSocket->socket(),
						TQSocketNotifier::Read,0,"readNotifier");
	connectionStatus = Init;
	TQObject::connect(socketReadNotifier,SIGNAL(activated(int)),SLOT(slotReceiveReady(int)));
	socketReadNotifier->setEnabled(false);
}

EvaSocket::~EvaSocket()
{
	delete connectSocket;
	if(socketReadNotifier) {
		socketReadNotifier->setEnabled(false);
		delete socketReadNotifier;
	}
	if(socketWriteNotifier) {
		socketWriteNotifier->setEnabled(false);
		delete socketWriteNotifier;
	}
}

const TQHostAddress EvaSocket::getSocketAddress( )
{
	if(connectSocket) return connectSocket->address();
	return TQHostAddress();
}

const unsigned short EvaSocket::getSocketPort( )
{
	if(connectSocket) return connectSocket->port();
	return 0;
}

void EvaSocket::setHost(const TQHostAddress &address, const short port)
{
	server = address;
	serverPort = port;  
	connectionStatus = None;
	if(connectSocket->isValid()){
		delete connectSocket;
		if(socketReadNotifier) {
			socketReadNotifier->setEnabled(false);
			delete socketReadNotifier;
		}
		if(socketWriteNotifier) {
			socketWriteNotifier->setEnabled(false);
			delete socketWriteNotifier;
		}
		if(connectionType == UDP){
			connectSocket = new TQSocketDevice(TQSocketDevice::Datagram); 
		}else{
			connectSocket = new TQSocketDevice(TQSocketDevice::Stream); 
			connectSocket->setBlocking(false);
			socketWriteNotifier =  new TQSocketNotifier(connectSocket->socket(),
								TQSocketNotifier::Write,0,"writeNotifier");
			TQObject::connect(socketWriteNotifier,SIGNAL(activated(int)),SLOT(slotWriteReady(int)));
			socketWriteNotifier->setEnabled(false);
		}
		socketReadNotifier = new TQSocketNotifier(connectSocket->socket(),
							TQSocketNotifier::Read,0,"SocketNotifier");
		TQObject::connect(socketReadNotifier,SIGNAL(activated(int)),SLOT(slotReceiveReady(int)));
		if(connectionType == TCP)
			socketReadNotifier->setEnabled(false);
	}
	connectionStatus = Init;
}

void EvaSocket::closeConnection()
{
	if(connectSocket->isOpen()) connectSocket->close();
	connectionStatus = None;
	receivedLength = 0;
}

void EvaSocket::startConnecting()
{
	if(connectionStatus != Init) {
		emit exceptionEvent(connectionStatus);
		return;
	}
	connectionStatus = Connecting;
	if(connectionType == TCP){
		if(!connectSocket->connect(server, serverPort)){
			fprintf(stderr,"connecting server failed\nError type: ");
			connectionStatus = Failed;
			switch(connectSocket->error()){
				case TQSocketDevice::NoError:
					fprintf(stderr,"NoError\n");
					break;
				case TQSocketDevice::AlreadyBound:
					fprintf(stderr,"AlreadyBound\n");
					break; 
				case TQSocketDevice::Inaccessible:
					fprintf(stderr,"Inaccessible\n");
					break;
				case TQSocketDevice::NoResources:
					fprintf(stderr,"NoResources\n");
					break;
				case TQSocketDevice::InternalError:
					fprintf(stderr,"InternalError\n");
					break;
				case TQSocketDevice::Impossible:
					fprintf(stderr,"Impossible\n");
					break;
				case TQSocketDevice::NoFiles:
					fprintf(stderr,"NoFiles\n");
					break;
				case TQSocketDevice::ConnectionRefused:
					fprintf(stderr,"ConnectionRefused\n");
					break;
				case TQSocketDevice::NetworkFailure:
					fprintf(stderr,"NetworkFailure\n");
					break;
				case TQSocketDevice::UnknownError:
					fprintf(stderr,"UnknownError\n");
					break;
				default:
					printf("not listed error\n");
			}
			emit exceptionEvent(connectionStatus);
			return;
		}
	}
	if(socketReadNotifier) socketReadNotifier->setEnabled(true);
	if(connectionType == TCP && socketWriteNotifier) {
		socketWriteNotifier->setEnabled(true);
	}else{
		connectionStatus = Ready;
		emit isReady();
	}
}

bool EvaSocket::write(const char *buf, const int len)
{
	if(connectionStatus != Ready || !buf ) return false;
	if(!connectSocket->isValid()){
		if(connectionType == TCP && socketReadNotifier && socketWriteNotifier){
			socketReadNotifier->setEnabled(false);
			socketWriteNotifier->setEnabled(false);
		}
		emit exceptionEvent(Failed);
		return false;
	}
	TQMutex mutex;
	mutex.lock();
	int BytesSent = 0;
	if(socketWriteNotifier) socketWriteNotifier->setEnabled(false);
	if(connectionType == UDP){
		BytesSent =connectSocket->writeBlock(buf, len, server, serverPort);
	}else{
		int bytes = 0;
		int times = 0;
		while(BytesSent < len){
			bytes =connectSocket->writeBlock(buf + BytesSent, len - BytesSent);
			if(bytes == -1) {
				printf("EvaSocket::write retry :%d\n", times);
				if(!connectSocket->error()){
					if(times>20){
						fprintf(stderr, "EvaSocket::write -- error : retried %d times\n", times);
						mutex.unlock();
						return false;
					}
					usleep(10000);
					//tqApp->processEvents();
					times++;
					continue;
				}else
					break;
			}
			BytesSent += bytes;
		}
	}
	mutex.unlock();
	if(len != BytesSent){
		printf("EvaSocket::write -- error code: %d\n", connectSocket->error());
		return false;
	}
	return true;
}

bool EvaSocket::read(char *buf, int len)
{
	if(connectionStatus != Ready || receivedLength != len || !buf ){
		printf("EvaSocket::read -- receivedLength: %d, len: %d\n", receivedLength, len);
		return false;
	}
	memcpy(buf, receivedBuffer, receivedLength);
	if(socketReadNotifier) socketReadNotifier->setEnabled(true);
	return true;
}

void EvaSocket::setWriteNotifierEnabled( bool enabled )
{
	if(socketWriteNotifier) socketWriteNotifier->setEnabled(enabled);
}

void EvaSocket::slotWriteReady(int /*socket */)
{
	if(socketWriteNotifier) socketWriteNotifier->setEnabled(false);
	if(connectionStatus == Connecting){
		connectionStatus = Ready;
		emit isReady();
	} else{
		emit writeReady();
	}
}

void EvaSocket::slotReceiveReady(int /*socket*/)
{
	if( (socketReadNotifier->type() != TQSocketNotifier::Read) || (!connectSocket->isValid()) ){
		socketReadNotifier->setEnabled(false);
		printf("EvaSocket::slotReceiveReady -- socket not valid or notifier not set to Read \n");
		emit exceptionEvent(Failed);
		return;
	}
		
	int ByteCount = 0;
	ByteCount = connectSocket->bytesAvailable();
	
	if(receivedBuffer!=NULL) delete receivedBuffer;
	receivedBuffer = new char[ByteCount * 2];  
	
	receivedLength = connectSocket->readBlock(receivedBuffer,ByteCount*2);
	if(!receivedLength){
		printf("EvaSocket::slotReceiveReady -- connection closed due to ZERO byte\n");
		socketReadNotifier->setEnabled(false);
		emit exceptionEvent(Failed);
		return;
	}
	
	if(receivedLength == -1){
		printf("EvaSocket::slotReceiveReady -- readBlock return -1\n");
		emit exceptionEvent(Failed);
		return;
	}
	if(socketReadNotifier) socketReadNotifier->setEnabled(false);
	emit receivedData(receivedLength);
	if(receivedLength != ByteCount)
		printf("EvaSocket::slotReceiveReady -- bytesAvailable() might not be accurate.\n");
}


/* =========================================================== */
EvaHttpProxy::EvaHttpProxy(const TQHostAddress &proxyHost, const short proxyPort, const TQString username, const TQString password)
	: EvaSocket(proxyHost, proxyPort, EvaSocket::TCP),
	status(Proxy_None),
	destinationAddress(""),
	base64AuthParam(""),
	readBuffer(NULL)
{
	if(username!=TQString::null && password!= TQString::null){
		setAuthParameter(username, password);
	}
	TQObject::connect(this, SIGNAL(isReady()), SLOT(tcpReady()));
	TQObject::connect(this, SIGNAL(writeReady()), SLOT(slotWriteReady()));
	TQObject::connect(this, SIGNAL(receivedData(int)), SLOT(parseData(int)));
	TQObject::connect(this, SIGNAL(exceptionEvent(int)), SIGNAL(socketException(int)));
}

void EvaHttpProxy::setDestinationServer(const TQString &server, const int port) // server could be IP or URL
{
	destinationAddress = server + ':' + TQString::number(port);// qq http proxy server port: 443
	status = Proxy_None;
}

void EvaHttpProxy::setAuthParameter(const TQString &username, const TQString &password)
{
	TQCString para = (username + ':' + password).local8Bit();
	base64AuthParam = TQCodecs::base64Encode(para);
	status = Proxy_None;
}

bool EvaHttpProxy::doInitConnecting()
{
	if(getStatus() != EvaSocket::Ready) return false;
	if(destinationAddress == "") return false;
	sentBuffer = "CONNECT " + destinationAddress.local8Bit() + " HTTP/1.1\r\n" +
		"Accept: */*\r\n" + "Content-Type: text/html\r\nProxy-Connection: Keep-Alive\r\n" +
		"Content-length: 0\r\n\r\n";
	status = Proxy_Connecting;
	return write(sentBuffer.data(), sentBuffer.length());
}

bool EvaHttpProxy::doAuthConnecting()
{
	if(getStatus() != EvaSocket::Ready) return false;
	if(destinationAddress == "") return false;
	if(base64AuthParam == "") return false;
	
	sentBuffer = "CONNECT " + destinationAddress.local8Bit() + " HTTP/1.1\r\n" +
		"Proxy-Authorization: Basic " + base64AuthParam + "\r\n" +
		"Accept: */*\r\nContent-Type: text/html\r\nProxy-Connection: Keep-Alive\r\n" +
		"Content-length: 0\r\n\r\n";
	status = Proxy_Connecting;
	return write(sentBuffer.data(), sentBuffer.length());
}

void EvaHttpProxy::tcpReady()
{
	printf("EvaHttpProxy::tcpReady -- TCP connection ready\n");
	if(destinationAddress == "") {
		emit proxyEvent(Proxy_TCP_Ready);
		return;
	}
	
	if(base64AuthParam != "")
		doAuthConnecting();
	else 
		doInitConnecting();
}

void EvaHttpProxy::slotWriteReady()
{
	if ( status == Proxy_Ready )
		emit proxyWriteReady();
}

void EvaHttpProxy::parseData(int len)
{	
	if(readBuffer!=NULL) free(readBuffer);
	readBuffer = (char *)malloc((len+1) * sizeof(char));
	if(!read(readBuffer, len)){ 
		emit proxyEvent(Proxy_Read_Error);
		return;
	}
	readBuffer[len]=0x00;
	TQString replyBuffer(readBuffer);
	if(replyBuffer.startsWith("HTTP/1.")){ // this is for RedHat 9, the old TQt dosen't support TQString::startsWith(const TQString &str, bool cs) const
		int replyCode = replyBuffer.mid(9, 3).toInt();
		fprintf(stderr, "Proxy Server Reply Code: %d\n",replyCode);
		switch(replyCode){
		case 200:
			status = Proxy_Ready;
			emit proxyEvent(Proxy_Ready);
			break;
		case 407:  //Proxy Authentication Required
			status = Proxy_Need_Auth;
			emit proxyEvent(Proxy_Need_Auth);
			break;
		case 501:  // "Not Support"
		case 502:  // "Proxy Error"
		default:
			status = Proxy_Error;
			emit proxyEvent(Proxy_Error);
			break;
		}
		return;
	}
	if(status == Proxy_Ready)
		dataArrived(len);
}



/** ============================================================== **/



HttpHeader::HttpHeader()
	: m_HeaderLen(0),
	m_ContentLen(0),
	m_Username(""),
	m_Password(""),
	m_Base64AuthParam("")
{
}

HttpHeader::HttpHeader(const TQByteArray &data)
	: m_HeaderLen(0),
	m_ContentLen(0),
	m_Username(""),
	m_Password(""),
	m_Base64AuthParam("")
{
	parseHeader(data);
}

bool HttpHeader::parseHeader(const TQByteArray &data)
{
	TQCString buf(data);
	if (buf.left(strlen(HTTP_VERSION)) != HTTP_VERSION){
		//kdDebug() << "[HttpHeader] Not a HTTP command return, but might be data packet" << endl;
		return false;
	}
	int index = buf.find(HTTP_HEADER_END);
	if(index == -1) return false;


	m_HeaderLen = index + 1 + 3;// index + 1 + strlen("\r\n\r\n")
	/* NOTE:we use TQString here for easy parsing */
	TQString header = buf.left(index + 1);
	TQStringList lines = TQStringList::split(HTTP_NEW_LINE, header);
	TQStringList::Iterator lineIt = lines.begin();
	/* first line should be the return code */
	TQString ret = *(lineIt++);
	TQStringList items = TQStringList::split(" ", ret);
	if(items.count() != 3){
		kdDebug() << "[HttpHeader] Http header unknown: " << ret << endl;
		return false;
	}
	TQStringList::Iterator itemIt = items.begin();
	setMetaData(HTTP_REPLY_CODE, *(++itemIt));
	
	for( ; lineIt != lines.end(); ++lineIt){
		ret = *lineIt;
		TQStringList items = TQStringList::split(": ", ret);
		if(items.count() == 2){
			if(items[0] == HTTP_SET_COOKIE){
				TQStringList cookies = TQStringList::split(":", items[1]);
				m_Cookies[cookies[0]] = cookies[1];
			} else {
				setMetaData(items[0], items[1]);
				}
		} else {
			kdDebug() << "[HttpHeader] line contains different parts" << ret << endl;
		}
	}
	return true;
}

const TQCString HttpHeader::toCString()
{
	return "GET /forum/ HTTP/1.1\r\nHost: www.myswear.net\r\nUser-Agent: Eva 0.4.2\r\nAccept: */*\r\nConnection: Keep-Alive\r\n\r\n";
}

TQCString HttpHeader::getProxyConnectHeader( const TQString &destHost, const unsigned short port, const bool needAuth)
{
	TQCString buf;
	TQTextStream stream(buf, IO_WriteOnly);
	stream << HTTP_CONNECT << " " << (destHost + ":" + TQString::number(port)) << " " << HTTP_VERSION << HTTP_NEW_LINE;
	if(needAuth){
		stream << HTTP_PROXY_BASIC;
		
		if(m_Base64AuthParam.isEmpty()){
			stream << (TQCodecs::base64Encode( (m_Username + ":" + m_Password).local8Bit()));
		} else
			stream << m_Base64AuthParam;
		
		stream << HTTP_NEW_LINE;
	}
	stream << HTTP_ACCEPT_ALL << HTTP_NEW_LINE;
	stream << HTTP_CONTENT_TYPE << ": text/html" << HTTP_NEW_LINE;
	stream << HTTP_PROXY_CONNECTION << ":" << HTTP_KEEP_ALIVE << HTTP_NEW_LINE;
	stream << HTTP_CONTENT_LENGTH << ": 0" << HTTP_NEW_LINE;
	stream << HTTP_NEW_LINE;
	return buf;
}

TQCString HttpHeader::getCmdGetHeader(const bool useProxy, const bool needAuth)
{
	TQString buf;
	TQTextStream stream(buf, IO_WriteOnly);
	stream << HTTP_CMD_GET << " ";
	if(useProxy){
		stream << "http://" << getMetaData(HTTP_HOST);
	}
	stream << getMetaData(HTTP_CMD_GET) << " " << HTTP_VERSION << HTTP_NEW_LINE;
	
	stream << HTTP_HOST << ": " << getMetaData(HTTP_HOST) << HTTP_NEW_LINE;
	if(needAuth){
		stream << HTTP_PROXY_BASIC;
		
		if(m_Base64AuthParam.isEmpty()){
			stream << (TQCodecs::base64Encode( (m_Username + ":" + m_Password).local8Bit()));
		} else
			stream << m_Base64AuthParam;

		stream << HTTP_NEW_LINE;
	}
	stream << HTTP_USER_AGENT << ": " << HTTP_DEFAULT_AGENT << HTTP_NEW_LINE;
	stream << HTTP_ACCEPT_ALL << HTTP_NEW_LINE;
	stream << HTTP_ACCEPT_LANGUAGE << ": " << HTTP_ACCEPT_DEFAULT_LANG << HTTP_NEW_LINE;
	stream << HTTP_ACCEPT_ENCODING << ": " <<  HTTP_ACCEPT_DEFAULT_ENCODE << HTTP_NEW_LINE;
	stream << HTTP_ACCEPT_CHARSET << ": " <<  HTTP_ACCEPT_DEFAULT_CHARSET << HTTP_NEW_LINE;
	stream << HTTP_KEEP_ALIVE << ": 300" << HTTP_NEW_LINE;
	
	if(useProxy)
		stream << HTTP_PROXY_CONNECTION << ": " << TQString(HTTP_KEEP_ALIVE).lower() << HTTP_NEW_LINE;
	else
		stream << HTTP_CONNECTION << ": " << TQString(HTTP_KEEP_ALIVE).lower() << HTTP_NEW_LINE;
		
	if(m_Cookies.count()){
		stream << HTTP_COOKIE << ": ";
		TQMap<TQString, TQString>::Iterator it;
		for( it = m_Cookies.begin(); it != m_Cookies.end(); ++it){
			if(it != m_Cookies.begin()){
				stream << "; ";
			}
			stream << it.key() << "=" << it.data();
		}
		stream << HTTP_NEW_LINE;
	}
	stream << HTTP_NEW_LINE;
	return buf.latin1();
}

void HttpHeader::setCookie(const TQString &name, const TQString &value)
{
	m_Cookies[name] = value;
}

void HttpHeader::setGetURI(const TQString &uri)
{
	setMetaData(HTTP_CMD_GET, uri);
}

void HttpHeader::setHost(const TQString &host)
{
	setMetaData(HTTP_HOST, host);
}

void HttpHeader::setAuthInfo(const TQString &user, const TQString &password)
{
	m_Username = user;
	m_Password = password;
}

void HttpHeader::setBase64AuthParam( const TQCString & param )
{
	m_Base64AuthParam = param;
}

const TQString HttpHeader::getReplyCode() const
{
	return getMetaData(HTTP_REPLY_CODE);
}

const TQMap<TQString, TQString> &HttpHeader::getCookies() const
{
	return m_Cookies;
}

const TQString HttpHeader::getCookie(const TQString &name) const
{
	return m_Cookies[name];
}

const unsigned int HttpHeader::getContentLength() 
{
	TQString strLen = getMetaData(HTTP_CONTENT_LENGTH);
	bool ok = false;
	int len = strLen.toUInt(&ok);
	if(ok) return len;
	else
		return 0;
}

const unsigned int HttpHeader::getHeaderLength() const
{
	return m_HeaderLen;
}

const unsigned int HttpHeader::getContentsOffset() const
{
	return m_HeaderLen;
}

void HttpHeader::setMetaData(const TQString &field, const TQString &value)
{
	m_Fields[field.lower()] = value;
}

const TQString HttpHeader::getMetaData(const TQString &field) const
{
	return m_Fields[field.lower()];
}



/** ============================================================== **/



EvaHttp::EvaHttp( const TQString & host, const unsigned short port )
	: EvaSocket(host, port, EvaSocket::TCP),
	m_UseProxy(false),
	m_NeedAuth(false),
	m_IsProxyReady(false),
	m_ProxyHost(""),
	m_ProxyPort(8080),
	m_Host(host),
	m_Port(port),
	m_IODevice(0),
	m_BytesReceived(0)
{
	m_Header.setHost(m_Host);

	TQObject::connect(this, SIGNAL(isReady()), SLOT(tcpReady()));
	TQObject::connect(this, SIGNAL(writeReady()), SLOT(slotWriteReady()));
	TQObject::connect(this, SIGNAL(receivedData(int)), SLOT(parseData(int)));

}

void EvaHttp::setHost(const TQString &host, const unsigned short port)
{
	m_Host = host;
	m_Port = port;
	m_Header.setHost(m_Host);
}

void EvaHttp::setProxyServer( const TQString & host, unsigned short port )
{
	if(host.isEmpty()) return;
	m_IsProxyReady = false;
	m_UseProxy = true;
	m_ProxyHost = host;
	m_ProxyPort = port;
}

void EvaHttp::setProxyAuthInfo( const TQString & username, const TQString & password )
{
	if(username.isEmpty() || password.isEmpty()) return;
	//kdDebug() << "[EvaHttp] u:" << username << ", p" << password << endl;
	m_IsProxyReady = false;
	m_NeedAuth = true;
	m_Header.setAuthInfo(username, password);
}

void EvaHttp::setBase64AuthParam( const TQCString & param )
{
	if(param.isEmpty()) return;
	m_IsProxyReady = false;
	m_NeedAuth = true;
	m_Header.setBase64AuthParam( param);
}

void EvaHttp::get( const TQString & path, TQIODevice * to )
{
	m_BytesReceived = 0;
	m_IODevice = to;
	if(path.startsWith("/")){
		m_Header.setGetURI(path);
	} else{
		TQUrl url(path);
		if(!url.isValid()){
			kdDebug() << "[EvaHttp] uri of get is malformed" << endl;
			emit requestFinished(true);
			return;
		} else {
			//kdDebug() << "[EvaHttp] set host " << url.host() << endl;
			TQString p;
			if(path.startsWith("http://"))
				p = path.right( path.length() - 7); //get rid of "http://"
			setHost( url.host());
			TQString rest = p.right( p.length() - p.find("/"));
			m_Header.setGetURI(rest);
		}
	}
	if(!m_UseProxy)
		startDnsLookup(m_Host);
	else{
		EvaSocket::setHost(TQHostAddress(m_ProxyHost), m_ProxyPort);
		startConnecting();
	}
}

void EvaHttp::tcpReady( )
{
	TQCString toSend;
	if(m_UseProxy){
		toSend = m_Header.getCmdGetHeader(true, m_NeedAuth);
		//kdDebug() << "[EvaHttp] ("<< toSend.length() << ") connecting to proxy:\r\n" << endl;
		
	}else{
		toSend = m_Header.getCmdGetHeader();
		//kdDebug() << ("[EvaHttp] sending GET command:\r\n" + toSend) << endl;
	}
	write(toSend.data(), toSend.length());
}

void EvaHttp::slotWriteReady( )
{
}

void EvaHttp::parseData( int len )
{
	//kdDebug() << "[EvaHttp] data comes (" << len << ")" << endl;
	
	char *readBuffer = new char[len];
	if(!read(readBuffer, len)){
		kdDebug() << "[EvaHttp] read data error" << endl;
		closeConnection();
		emit requestFinished(true);
		return;
	}
	if(m_BytesReceived && (m_BytesReceived >= m_Header.getContentLength())) return;

	TQByteArray buf;
	buf.setRawData(readBuffer, len);
	//kdDebug() << "[EvaHttp] raw data:\n" << buf << endl;
	if(m_Header.parseHeader(buf)){
		bool ok = false;
		int replyCode = m_Header.getReplyCode().toInt(&ok);
		if(!ok){
			kdDebug() << "[EvaHttp] Http reply code error" << endl;
			closeConnection();
			emit requestFinished(true);
			return;
		}
		switch(replyCode){
		case 200:
			if(m_UseProxy && !m_IsProxyReady){
				m_IsProxyReady = true;
				TQCString toSend = m_Header.getCmdGetHeader();
				write(toSend.data(), toSend.length());
			}else{ 
				// do nothing, just wait for the contents
			}
			break;
		case 407:  //Proxy Authentication Required
			kdDebug() << "[EvaHttp] Http reply code 407 (Proxy Authentication Required)" << endl;
			closeConnection();
			emit requestFinished(true);
			break;
		case 501:  // "Not Support"
		case 502:  // "Proxy Error"
		default:
			kdDebug() << "[EvaHttp] Http reply code error" << endl;
			closeConnection();
			emit requestFinished(true);
			break;
		}
		//kdDebug() << "[EvaHttp] Received:\n" << buf.data() << endl;
		//kdDebug() << "[EvaHttp] " << len << " bytes, reply:"<< replyCode <<",HeaderLen:"<< m_Header.getHeaderLength() 
		//		<< ", contentsLength:"<<m_Header.getContentLength() << endl;
		if(len > (int)(m_Header.getHeaderLength())){
			m_BytesReceived = len - m_Header.getHeaderLength();
			int ret = m_IODevice->writeBlock(buf.data() + m_Header.getContentsOffset(), m_BytesReceived);
			if(ret == -1 || ret !=  m_BytesReceived ){
				kdDebug() << "[EvaHttp] write error" << endl;
				closeConnection();
				emit requestFinished(true);
				return;
			}
			if(m_BytesReceived == m_Header.getContentLength())
				emit requestFinished(false); // now we done!!!
		}
	}else{
		int bytesToWrite = len;
		if( (m_Header.getContentLength() - m_BytesReceived) < len){
			bytesToWrite = m_Header.getContentLength() - m_BytesReceived;
			m_BytesReceived = m_Header.getContentLength();
		}else
			m_BytesReceived += len;

		if(!m_IODevice){
			emit readReady();
		}else{
			int ret = m_IODevice->writeBlock(buf.data(), bytesToWrite);
			if(ret == -1){
				kdDebug() << "[EvaHttp] write error" << endl;
				closeConnection();
				emit requestFinished(true);
				return;
			}

			if(m_BytesReceived == m_Header.getContentLength()){
				//kdDebug() << "[EvaHttp] request Done!" << endl;
				emit requestFinished(false); // now we done!!!
			}
		}
	}
}

void EvaHttp::startDnsLookup( const TQString & host )
{
	//kdDebug() << "{EvaHttp} looking for IP of " << host << endl;
	// host should be a URL string
	TQDns * dns =  new TQDns(host, TQDns::A);
	TQObject::connect(dns, SIGNAL(resultsReady()), this, SLOT(getResultsSlot()));
}

void EvaHttp::getResultsSlot( )
{
	TQDns *dns = (TQDns *)(TQObject::sender());
	if(dns == 0 ){
        	kdDebug() << "[EvaHttp] Dns lookup error" << endl;
		emit requestFinished(true);
        	return;
	}
	TQValueList<TQHostAddress> list = dns->addresses();
	if(list.count() == 0 ){
        	kdDebug() << "[EvaHttp] Dns lookup error - no address" << endl;
		emit requestFinished(true);
        	return;
	}
	
	TQHostAddress addr = list[0];
	EvaSocket::setHost(addr, m_Port);
	//kdDebug() << "{EvaHttp] DNS ready" << endl;	
	startConnecting();
}








