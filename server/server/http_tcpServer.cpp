//#include "http_tcpServer.h"
//#include <iostream>


   /* TcpServer::~TcpServer()
    {
    }*/


//} // namespace http
#include "http_tcpServer.h"
#include <iostream>
#include <winsock2.h>  // ������ Winsock ���� ������ �-Windows

namespace http
{
    TcpServer::TcpServer() : m_socket(INVALID_SOCKET)
    {
        // ����� �� ���� ������ �-0
        memset(&m_serverAddr, 0, sizeof(m_serverAddr));
        m_serverAddr.sin_family = AF_INET;    // �������� IPv4
        m_serverAddr.sin_addr.s_addr = INADDR_ANY; // �� ����� IP
        m_serverAddr.sin_port = htons(8080);  // ���� 8080
    }

    TcpServer::~TcpServer()
    {
        if (m_socket != INVALID_SOCKET)
        {
            closesocket(m_socket);  // ����� �����
        }
        WSACleanup();  // ����� �� Winsock
    }

    int TcpServer::startServer()
    {
        // ����� Winsock
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
        {
            exitWithError("WSAStartup failed");
            return 1;
        }

        // ����� �����
        m_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (m_socket == INVALID_SOCKET)
        {
            exitWithError("Cannot create socket");
            return 1;
        }

        // ����� ����� ������ ������
        if (bind(m_socket, (struct sockaddr*)&m_serverAddr, sizeof(m_serverAddr)) == SOCKET_ERROR)
        {
            exitWithError("Bind failed");
            return 1;
        }

        // ����� �������� ������
        if (listen(m_socket, 3) == SOCKET_ERROR)
        {
            exitWithError("Listen failed");
            return 1;
        }

        std::cout << "Server listening on port 8080..." << std::endl;

        // ���� ����� ����
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

        // ��� ���� ������ ��� ���� ������ (����� ����� ������)

        return 0;
    }

    void TcpServer::exitWithError(const std::string& errorMessage)
    {
        std::cerr << errorMessage << std::endl;
        if (m_socket != INVALID_SOCKET)
        {
            closesocket(m_socket);  // ����� ���� ����� �� �����
        }
        WSACleanup();  // ����� �� Winsock
        exit(EXIT_FAILURE);
    }
}
