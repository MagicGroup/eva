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
#ifndef EVASOCKET_H
#define EVASOCKET_H


#define HTTP_HEADER        "HTTP"
#define HTTP_VERSION       "HTTP/1.1"
#define HTTP_NEW_LINE      "\r\n"
#define HTTP_HEADER_END    "\r\n\r\n"

#define HTTP_CMD_GET       "GET"
#define HTTP_CONNECT       "CONNECT"
#define HTTP_HOST          "Host"
#define HTTP_CONNECTION    "Connection"
#define HTTP_KEEP_ALIVE    "Keep-Alive"

#define HTTP_USER_AGENT    "User-Agent"
#define HTTP_DEFAULT_AGENT "Eva/0.4.2"

#define HTTP_ACCEPT                 "Accept"
#define HTTP_ACCEPT_LANGUAGE        (HTTP_ACCEPT "-Language")
#define HTTP_ACCEPT_DEFAULT_LANG    "zh-cn,zh;q=0.5"
#define HTTP_ACCEPT_ENCODING        (HTTP_ACCEPT "-Encoding")
#define HTTP_ACCEPT_DEFAULT_ENCODE  "gzip,deflate"
#define HTTP_ACCEPT_CHARSET         (HTTP_ACCEPT "-Charset")
#define HTTP_ACCEPT_DEFAULT_CHARSET "gb2312,utf-8;q=0.7,*;q=0.7"
#define HTTP_ACCEPT_ALL             (HTTP_ACCEPT ": */*")
#define HTTP_ACCEPT_DEFAULT         (HTTP_ACCEPT ": text/xml,application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5")

#define HTTP_CONTENT_TYPE     "Content-Type"
#define HTTP_CONTENT_LENGTH   "Content-length"

#define HTTP_PROXY_TYPE       "Proxy-Authorization"
#define HTTP_PROXY_BASIC      (HTTP_PROXY_TYPE ": Basic ")
#define HTTP_PROXY_CONNECTION "Proxy-Connection"

#define HTTP_COOKIE         "Cookie"
#define HTTP_SET_COOKIE      "Set-Cookie"
#define HTTP_REPLY_CODE     "Reply-Code"




#include <ntqhostaddress.h>
#include <ntqcstring.h>
#include <ntqobject.h>
#include <ntqmap.h>

// Implementing UDP & TCP connections to Tencent Server

class TQSocketDevice;
class TQSocketNotifier;
 
class EvaSocket : public TQObject {
	Q_OBJECT
public:
	enum Type { TCP, UDP};
	enum Status { Init, Connecting, Ready, Failed, None, BytesReadWrong};
	EvaSocket(const TQHostAddress &host, const short port, const Type type = UDP);
	~EvaSocket();
	
	const Type getConnectType() const { return connectionType; }
		
	void setHost( const TQHostAddress &address, const short port);
	const TQHostAddress &getHostAddress() const { return server; }
	const short getHostPort() const { return serverPort; }
	const Status getStatus() const { return connectionStatus; }
	
	bool write(const char *buf, const int len);
	bool read(char *buf, int len);
	const TQHostAddress getSocketAddress();
	const unsigned short getSocketPort();
	void setWriteNotifierEnabled(bool enabled);

public slots:	
	void closeConnection();
	void startConnecting();
signals:
	void isReady(); // emit when socket is connected
	void receivedData(int);     // emit after receiving data from server
	void exceptionEvent(int);      // emit whenever exception happens
	void writeReady();
protected:
	TQSocketDevice *connectSocket;
	TQSocketNotifier *socketReadNotifier; 
	TQSocketNotifier *socketWriteNotifier;
	
	int receivedLength;
	char *receivedBuffer;
private:
	Type connectionType;
	TQHostAddress server;
	short serverPort;
	
	Status connectionStatus;  //  connected or not
private slots:
	void slotWriteReady(int);
	void slotReceiveReady(int);
};

// call read after receiving proxyEvent(Proxy_Ready) SIGNAL
class EvaHttpProxy : public EvaSocket {
	Q_OBJECT
public:
	enum ProxyStatus { Proxy_None, Proxy_TCP_Ready, Proxy_Connecting, Proxy_Ready, 
				Proxy_Need_Auth, Proxy_Read_Error, Proxy_Error};
	EvaHttpProxy(const TQHostAddress &proxyHost, const short proxyPort, const TQString username = TQString::null, 
								const TQString password = TQString::null);
	void setDestinationServer(const TQString &server, const int port); // server could be IP or URL
	const TQString &getDestinationServer() const { return destinationAddress; }
	void setAuthParameter(const TQString &username, const TQString &password);
	const TQCString &getBase64AuthParam() const { return base64AuthParam;}
	void setBase64AuthParam(const TQCString &param) { base64AuthParam = param;  status = Proxy_None; }
	bool doInitConnecting();
	bool doAuthConnecting();
	
	const ProxyStatus getProxyStatus() const { return status; }
signals:
	void dataArrived(int);
	void proxyEvent( int );
	void socketException(int);
	void proxyWriteReady();
public slots:
	void tcpReady();
	void slotWriteReady();
private:
	ProxyStatus status;
	TQString destinationAddress;
	TQCString base64AuthParam;
	TQCString sentBuffer;
	char *readBuffer;
	void received(int len);
private slots:
	void parseData(int len);
};



/**
 * \brief A simple Http header implemantation \n
 *         used for generating Http header data \n
 *         or parsing the header data received from server.
 * \author yunfan
 * \date   11th Feb. 2007
 */

class HttpHeader {
public:
	/** TODO exactly same as defined in EvaHttpProxy. we should really put
	   these into EvaSocket
	*/
	enum ProxyStatus { Proxy_None, Proxy_TCP_Ready, Proxy_Connecting, Proxy_Ready, 
				Proxy_Need_Auth, Proxy_Read_Error, Proxy_Error};
	HttpHeader();
	/** used for parsing the HTTP header 
	 *  \see parseHeader
	 */
	HttpHeader(const TQByteArray &data);

	/** parse http header
	 *  \see HttpHeader(const TQCString &data)
	 */
	bool parseHeader(const TQByteArray &data);

	/** get the ready-to-send string for sending
	 *  or the string we got for receiving
	 */
	const TQCString toCString();

	TQCString getProxyConnectHeader( const TQString &destHost, const unsigned short port, const bool needAuth = false);
	TQCString getCmdGetHeader(const bool useProxy = false, const bool needAuth = false);

	/** Also, provides some easy to use methods for sending/receiving header */
	void setCookie(const TQString &name, const TQString &value);
	void setGetURI(const TQString &uri);
	void setHost(const TQString &host);
	void setAuthInfo(const TQString &user, const TQString &password);
	void setBase64AuthParam(const TQCString &param);

	const TQString &getUsername() const { return m_Username; }
	const TQString &getPassword() const { return m_Password; }
	const TQString getReplyCode() const;
	const TQMap<TQString, TQString> &getCookies() const;
	const TQString getCookie(const TQString &name) const;
	const unsigned int getContentLength() ;

	/** 
	 *  return the length of the header including the last
	 *  empty row("\r\n")
	 *  \NOTE: only used for parsing header information
	 *         this will always return 0 when construct
         *         a HTTP header
         */
	const unsigned int getHeaderLength() const;
	/** It behaves essentially like the above function.*/
	const unsigned int getContentsOffset() const;
protected:
	/** set one field of the header */
	void setMetaData(const TQString &field, const TQString &value);
	/** get value of a specifed field */
	const TQString getMetaData(const TQString &field) const;
private:
	unsigned int m_HeaderLen;
	unsigned int m_ContentLen;
	TQMap<TQString, TQString> m_Fields;
	TQMap<TQString, TQString> m_Cookies;
	TQString m_Username, m_Password;
	TQCString m_Base64AuthParam;
};


class TQIODevice;
/**
 * \brief A simple Http connection implemantation \n
 *         used for retrieve data by http connection \n
 * \author yunfan
 * \date   13th Feb. 2007
 */

class EvaHttp : public EvaSocket {
	Q_OBJECT
public:
	EvaHttp(const TQString &host = "", const unsigned short port=80);

	/** NOTE: parent EvaSocket has the same method */
	void setHost(const TQString &host, const unsigned short port=80);
	/** if use proxy, call the following two */
	void setProxyServer(const TQString &host, unsigned short port);
	void setProxyAuthInfo(const TQString &username, const TQString &password);
	void setBase64AuthParam(const TQCString &param);

	/** path can be the relative path like /index.html or /data/123.png. the path can also be the 
	    absolute URI like www.myswear.net/forum/index.php
	    if TQIODevice to is 0, when data arrived, the raw data will write to this device directly.
	    if to is not 0, the signal readReady() will be emitted
	*/
	void get(const TQString & path, TQIODevice * to = 0 );

	/** return true if the received data contains a HTTP header,
	    otherwise, false.
	*/
	const bool hasHeader() const { return m_Header.getHeaderLength() != 0; }
	
	const HttpHeader getHeader() const { return m_Header; }

signals:
	/** if there is no IODevice used, this signal will be emitted 
	    when response data received
	*/
	void readReady();
	/** emitted when the request has been completely finished if ok is true
	    or, ok is false if an error occurred during the processing
	*/
	void requestFinished(bool error);
// 
private:
	bool m_UseProxy;
	bool m_NeedAuth;
	bool m_IsProxyReady;
	TQString m_ProxyHost;
	unsigned short m_ProxyPort;
	//TQString m_ProxyUsername;
	//TQString m_ProxyPassword;
	//TQCString m_Base64AuthParam;

	TQString m_Host;
	unsigned short m_Port;
	HttpHeader m_Header;
	TQIODevice *m_IODevice;
	long long m_BytesReceived;

	void startDnsLookup(const TQString &host);
private slots:
	void tcpReady();
	void slotWriteReady();
	void parseData(int len);
	void getResultsSlot();
};
#endif
