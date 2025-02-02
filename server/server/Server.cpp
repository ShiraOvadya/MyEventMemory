#include "http_tcpServer.h"
#include <winsock2.h>  // ����� ������ ��� �-Windows

int main()
{
    // ����� �� Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        std::cerr << "WSAStartup failed" << std::endl;
        return 1;
    }

    using namespace http;
    TcpServer server = TcpServer();

    // ����� ����
    if (server.startServer() != 0)
    {
        std::cerr << "Server failed to start" << std::endl;
        WSACleanup();  // ��� �� Winsock ����� �� �����
        return 1;
    }

    std::cout << "Server started successfully!" << std::endl;

    // ���� �� ������ �� Winsock
    WSACleanup();

    return 0;
}
