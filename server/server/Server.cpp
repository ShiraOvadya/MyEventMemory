#include "http_tcpServer.h"
#include <winsock2.h>  // הוספת הספריה הזו ב-Windows

int main()
{
    // אתחול של Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

    using namespace http;
    TcpServer server = TcpServer();

    // הפעלת השרת
    if (server.startServer() != 0)
    {
        std::cerr << "Server failed to start" << std::endl;
        WSACleanup();  // נקי את Winsock במקרה של שגיאה
        return 1;
    }

    std::cout << "Server started successfully!" << std::endl;

    // סיים את העבודה עם Winsock
    WSACleanup();

    return 0;
}
