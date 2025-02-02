//#include "http_tcpServer.h"
//#include <iostream>


   /* TcpServer::~TcpServer()
    {
    }*/


//} // namespace http
#include "http_tcpServer.h"
#include <iostream>
#include <winsock2.h>  // ספריית Winsock עבור סוקטות ב-Windows

namespace http
{
    TcpServer::TcpServer() : m_socket(INVALID_SOCKET)
    {
        // אתחול של מבנה הכתובת ל-0
        memset(&m_serverAddr, 0, sizeof(m_serverAddr));
        m_serverAddr.sin_family = AF_INET;    // פרוטוקול IPv4
        m_serverAddr.sin_addr.s_addr = INADDR_ANY; // כל כתובת IP
        m_serverAddr.sin_port = htons(8080);  // פורט 8080
    }

    TcpServer::~TcpServer()
    {
        if (m_socket != INVALID_SOCKET)
        {
            closesocket(m_socket);  // סגירת הסוקט
        }
        WSACleanup();  // ניקוי של Winsock
    }

    int TcpServer::startServer()
    {
        // אתחול Winsock
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        {
            exitWithError("WSAStartup failed");
            return 1;
        }

        // יצירת הסוקט
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket == INVALID_SOCKET)
        {
            exitWithError("Cannot create socket");
            return 1;
        }

        // קישור הסוקט לכתובת ולפורט
        if (bind(m_socket, (struct sockaddr*)&m_serverAddr, sizeof(m_serverAddr)) == SOCKET_ERROR)
        {
            exitWithError("Bind failed");
            return 1;
        }

        // האזנה לחיבורים נכנסים
        if (listen(m_socket, 3) == SOCKET_ERROR)
        {
            exitWithError("Listen failed");
            return 1;
        }

        std::cout << "Server listening on port 8080..." << std::endl;

        // קבלת חיבור נכנס
        SOCKET clientSocket;
        sockaddr_in clientAddr;
        int clientAddrLen = sizeof(clientAddr);
        clientSocket = accept(m_socket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (clientSocket == INVALID_SOCKET)
        {
            exitWithError("Accept failed");
            return 1;
        }

        std::cout << "Connection accepted from client." << std::endl;

        // כאן תוכל להוסיף קוד לטפל בחיבור (לשלוח ולקבל נתונים)

        return 0;
    }

    void TcpServer::exitWithError(const std::string& errorMessage)
    {
        std::cerr << errorMessage << std::endl;
        if (m_socket != INVALID_SOCKET)
        {
            closesocket(m_socket);  // סגירת סוקט במקרה של שגיאה
        }
        WSACleanup();  // ניקוי של Winsock
        exit(EXIT_FAILURE);
    }
}
