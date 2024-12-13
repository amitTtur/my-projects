#pragma once

#include <iostream>
#include <WinSock2.h>
#include <thread>
#include <Windows.h>
#include <map>
#include <string>

#include "LoginRequestHandler.h"
#include "MyException.h"
#include "RequestHandlerFactory.h"

// you can change the port accordingly
#define SERVER_LISTENING_PORT 8826

class Communicator
{

public:
	// constractor and des
	Communicator(IDatabase* db, RequestHandlerFactory* factoryHandler);
	~Communicator();

	void startHandleRequest();

	// socket handlers
	// get data from user socket usually 1024 bits
	static std::vector<unsigned char> getMSGFromSocket(const SOCKET sc, const int bytesNum);
	// sends data to the user socket
	static void sendMSGToSocket(const SOCKET sc, const std::vector<unsigned char>& message);


	// server closes all active connections
	void exitAll();

private:
	// vars
	std::map<SOCKET, IRequestHandler*> m_clients;
	SOCKET m_serverSocket;
	IDatabase* m_db;
	RequestHandlerFactory* m_factoryHandler;


	// private functions
	void bindAndListen();

	// client handler
	void handleNewClient(SOCKET clientSocket);
};