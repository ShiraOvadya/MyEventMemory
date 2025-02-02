#pragma once
//#ifndef INCLUDED_HTTP_TCPSERVER_LINUX
//#define INCLUDED_HTTP_TCPSERVER_LINUX
//namespace http
//{
//    class TcpServer
//    {
//    public:
//        TcpServer();
//        ~TcpServer();
//    private:
//
//    };
#ifndef HTTP_TCPSERVER_WINDOWS_H
#define HTTP_TCPSERVER_WINDOWS_H

#include <iostream>
#include <string>
#include <winsock2.h>  // ספריית Winsock עבור סוקטות ב-Windows

namespace http
{
    class TcpServer
    {
    public:
        TcpServer();
        ~TcpServer();
        int startServer(); // הכרזה על הפונקציה

    private:
        SOCKET m_socket;
        sockaddr_in m_serverAddr;
        void exitWithError(const std::string& errorMessage);
    };
}

#endif // HTTP_TCPSERVER_WINDOWS_H
