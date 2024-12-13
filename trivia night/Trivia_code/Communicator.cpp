#include "Communicator.h"

Communicator::Communicator(IDatabase* db, RequestHandlerFactory* factoryHandler)
{

	this->m_db = db;
	this->m_factoryHandler = factoryHandler;
	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Communicator::~Communicator()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(m_serverSocket);
	}
	catch (...) {}
}

void Communicator::startHandleRequest()
{
	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(SERVER_LISTENING_PORT); // port that server will listen for
	sa.sin_family = AF_INET;   // must be AF_INET
	sa.sin_addr.s_addr = INADDR_ANY;    // when there are few ip's for the machine. We will use always "INADDR_ANY"

	// Connects between the socket and the configuration (port and etc..)
	if (bind(m_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");

	// Start listening for incoming requests of clients
	if (listen(m_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "Listening on port " << SERVER_LISTENING_PORT << std::endl;

	while (true)
	{
		// the main thread is only accepting clients 
		// and add then to the list of handlers
		std::cout << "Waiting for client connection request" << std::endl;
		bindAndListen();
	}
}

std::vector<unsigned char> Communicator::getMSGFromSocket(const SOCKET sc, const int bytesNum)
{
	// if socket is empty return an empty vector
	if (bytesNum == 0)
	{
		return std::vector<unsigned char>();
	}

	// reciving data from sockey
	char* data = new char[bytesNum + 1];
	int res = recv(sc, data, bytesNum, 0);
	if (res == INVALID_SOCKET)
	{
		std::string s = "Error while receiving from socket: ";
		s += std::to_string(sc);
		throw std::exception(s.c_str());
	}
	// putting the end node to '\0' so the str will have an end
	data[bytesNum] = 0;

	// replace '\0' with data filler and delete the empty socket nodes
	std::vector<unsigned char> tmp;
	for (int i = 0 ; i < strlen(data);i++)
	{
		if (data[i] == DATA_FILLER)
		{
			tmp.push_back('\0');
		}
		else if (data[i] != char(-51))
		{
			tmp.push_back(data[i]);
		}	
	}
	// deleting the data
	delete[] data;

	// returning the checked socket data
	return tmp;
}

void Communicator::sendMSGToSocket(const SOCKET sc, const std::vector<unsigned char>& message)
{
	char* data = new char[message.size()];

	for (size_t i = 0; i < message.size(); i++)
	{
		data[i] = message[i];
	}

	for (size_t i = 0; i < strlen(data); i++)
	{
		std::cout << data[i];
	}
	std::cout << std::endl;

	// if data failed to send throw an exeption
	if (send(sc, data, message.size(), 0) == INVALID_SOCKET)
	{
		throw std::exception("Error while sending message to client");
	}
}

void Communicator::exitAll()
{
	// closing all active connction to the server
	for (auto s : m_clients)
	{
		try
		{
			shutdown(s.first, SD_BOTH);
			std::cout << "connection forcibly  finished with socket: " << s.first;
			closesocket(s.first);
		}
		catch(...){}
	}
}

void Communicator::bindAndListen()
{
	// this accepts the client and create a specific socket from server to this client
	// the process will not continue until a client connects to the server
	SOCKET client_socket = accept(m_serverSocket, NULL, NULL);
	if (client_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__);

	std::cout << "Client accepted. Server and client can speak" << std::endl;
	// the function that handle the conversation with the client
	std::thread t1(&Communicator::handleNewClient, this, client_socket);
	t1.detach();
}

void Communicator::handleNewClient(SOCKET clientSocket)
{
	// local vars
	bool still_connected = true;
	RequestInfo reqI;
	RequestResult rr;

	// so the client will start with login
	rr.newHandler = this->m_factoryHandler->createLoginRequestHandler();
	RequestResult tmp;
	try
	{
		// adding the client and his socket into the server clients.
		m_clients.insert(std::make_pair(clientSocket,rr.newHandler));

		while (still_connected) // as long as client doesn't disconnect
		{
			// recive the message from the client
			reqI.data = getMSGFromSocket(clientSocket, 1024);
			reqI.receivalTime = std::time(nullptr);

			if (reqI.data.size() == 0) // means client has crashed
			{
				reqI.codeId = EXIT;
			}
			else
			{
				reqI.codeId = JsonRequestPacketDeserializer::getMSGCode(reqI.data); // if he didn't crash get the msg code
			}

			if (reqI.codeId == EXIT) // if he exited
			{
				try
				{
					try // try to exit the room he is in
					{
						reqI.codeId = EXIT_ROOM;
						tmp = rr.newHandler->handleRequest(reqI);
						delete rr.newHandler;
						rr.newHandler = tmp.newHandler;
					}
					catch(...) {}
					try // logout the user
					{
						reqI.codeId = LOGOUT;
						tmp = rr.newHandler->handleRequest(reqI);
						delete rr.newHandler;
						rr.newHandler = tmp.newHandler;
					}
					catch (...) {}

				}
				catch (...) {}
				delete rr.newHandler; // delete the handler
				rr.newHandler = this->m_factoryHandler->createExitRequestHandler(); // begin the exit handler
			}

			try
			{
				tmp = rr.newHandler->handleRequest(reqI); // deal with the current request
				rr.buffer = tmp.buffer; // replace buffer
				delete rr.newHandler; // delete the old handler
				rr.newHandler = tmp.newHandler; // update current handler
			}
			catch (MyException& e) // if an error apeared send a error response
			{
				rr.buffer = this->m_factoryHandler->createErrorHandler(std::string(e.what()), 1)->handleRequest(reqI).buffer;
			}
			catch (...) // geeral error response
			{
				rr.buffer = this->m_factoryHandler->createErrorHandler("", 0)->handleRequest(reqI).buffer;
			}
			

			if (rr.newHandler == nullptr) // means exit was called
			{
				break; // exit the service loop
			}

			// delete any inactive room or game that exist in the server
			this->m_factoryHandler->getRoomManager()->deleteInactiveRooms(); 
			this->m_factoryHandler->getGameManager()->deleteFinishedGame();

			// send to the client the reponse that was recived from the handlers
			sendMSGToSocket(clientSocket, rr.buffer);
		}
		if (rr.newHandler != nullptr) // to avoid the "can't delete nullptr" error
		{
			delete rr.newHandler;
		}
		m_clients.erase(clientSocket); // erase the client from service list
		closesocket(clientSocket); // close the socket
	}
	catch (const std::exception& e) // case an unexpected error occurs
	{
		try // try to logout 
		{
			reqI.codeId = LOGOUT;
			rr.newHandler->handleRequest(reqI);
		}
		catch (...) {}
		
		// erasing and closing connetion and deleting any dynamicly allocatedmemory and variables
		std::cout << "ERROR!!! communicator side: " << e.what();
		m_clients.erase(clientSocket);
		if (rr.newHandler != nullptr)
		{
			delete rr.newHandler;
		}
		closesocket(clientSocket);
	}
}
