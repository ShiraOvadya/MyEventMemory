#include "server.h"
#include <iostream>
#include <winsock2.h>
#include <string>
#include <sstream>


#pragma comment(lib, "ws2_32")

Server::Server() {
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		exitWithError("WSAStartup failed");
	}
	listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (listeningSocket == INVALID_SOCKET) {
		exitWithError("Socket creation failed");
	}
}

Server::~Server() {
	closesocket(listeningSocket);
	WSACleanup();
}

int Server::start() {
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);
	serverAddr.sin_addr.s_addr = INADDR_ANY;

	if (bind(listeningSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
		exitWithError("Bind failed");
	}

	if (listen(listeningSocket, SOMAXCONN) == SOCKET_ERROR) {
		exitWithError("Listen failed");
	}

	SOCKET clientSocket = accept(listeningSocket, nullptr, nullptr);
	if (clientSocket == INVALID_SOCKET) {
		exitWithError("Accept failed");
	}

	handleClient(clientSocket);
	closesocket(clientSocket);

	return 0;
}

void Server::handleClient(SOCKET clientSocket) {
	char buffer[4096];
	int bytesReceived = recv(clientSocket, buffer, 4096, 0);
	if (bytesReceived > 0) {
		std::cout << "Received message: " << buffer << std::endl;

		std::string request(buffer, bytesReceived);
		std::istringstream requestStream(request);
		std::string method, url;
		requestStream >> method >> url;
		if (method == "POST" && url == "/submit") {
    std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nMessage received!";
    send(clientSocket, response.c_str(), response.length(), 0);
} else {
    std::string response = "HTTP/1.1 404 Not Found\r\n\r\nResource not found";
    send(clientSocket, response.c_str(), response.length(), 0);
}


		// if (method == "POST" && url == "/submit") {
		// 	std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nMessage received!";
		// 	send(clientSocket, response.c_str(), response.length(), 0);
		// } else if (method == "GET" && url == "/") {
		// 	std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nWelcome to the server!";
		// 	send(clientSocket, response.c_str(), response.length(), 0);
		// } else {
		// 	std::string response = "HTTP/1.1 404 Not Found\r\n\r\nResource not found";
		// 	send(clientSocket, response.c_str(), response.length(), 0);
		// }
	}
}

void Server::exitWithError(const std::string &errorMessage) {
	std::cerr << errorMessage << std::endl;
	WSACleanup();
	exit(EXIT_FAILURE);
}

// #include "server.h"
// #include <iostream>
// #include <winsock2.h>

// #pragma comment(lib, "ws2_32")

// Server::Server() {
//     if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
//         exitWithError("WSAStartup failed");
//     }
//     listeningSocket = socket(AF_INET, SOCK_STREAM, 0);
//     if (listeningSocket == INVALID_SOCKET) {
//         exitWithError("Socket creation failed");
//     }
// }

// Server::~Server() {
//     closesocket(listeningSocket);
//     WSACleanup();
// }

// int Server::start() {
//     sockaddr_in serverAddr;
//     serverAddr.sin_family = AF_INET;
//     serverAddr.sin_port = htons(8080);
//     serverAddr.sin_addr.s_addr = INADDR_ANY;

//     if (bind(listeningSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
//         exitWithError("Bind failed");
//     }

//     if (listen(listeningSocket, SOMAXCONN) == SOCKET_ERROR) {
//         exitWithError("Listen failed");
//     }

//     SOCKET clientSocket = accept(listeningSocket, nullptr, nullptr);
//     if (clientSocket == INVALID_SOCKET) {
//         exitWithError("Accept failed");
//     }

//     handleClient(clientSocket);
//     closesocket(clientSocket);

//     return 0;
// }

// void Server::handleClient(SOCKET clientSocket) {
//     char buffer[4096];
//     int bytesReceived = recv(clientSocket, buffer, 4096, 0);
//     if (bytesReceived > 0) {
//         send(clientSocket, buffer, bytesReceived, 0);
//     }
// }

// void Server::exitWithError(const std::string &errorMessage) {
//     std::cerr << errorMessage << std::endl;
//     WSACleanup();
//     exit(EXIT_FAILURE);
// }
