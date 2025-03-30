#pragma once
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <winsock2.h>
#include <string>
#include <unordered_map>

class Server {
public:
	Server();
	~Server();
	int start();
	void handleClient(SOCKET clientSocket);
    void exitWithError(const std::string &errorMessage);

private:
    WSADATA wsaData;
    SOCKET listeningSocket;
	// SOCKET serverSocket;
	// sockaddr_in serverAddr;
	// std::unordered_map<std::string, std::string> users; // Store user data
	// void exitWithError(const std::string& errorMessage);
	// void handleClient(SOCKET clientSocket);
	// std::string processRequest(const std::string& request);
};

#endif // SERVER_H
// #ifndef SERVER_H
// #define SERVER_H

// #include <winsock2.h>
// #include <string>

// class Server {
// public:
//     Server();
//     ~Server();
//     int start();
// private:
//     void handleClient(SOCKET clientSocket);
//     void exitWithError(const std::string &errorMessage);
//     SOCKET listeningSocket;
//     WSADATA wsaData;
// };

// #endif // SERVER_H