#pragma once

#include "Communicator.h"
#include "codesAndDefines.h"

class Server
{
public:
	// cons and des
	Server();
	~Server();

	// runs the server
	void run();
private:
	// vars
	Communicator* m_communicator;
	RequestHandlerFactory* m_factoryHandler;
	IDatabase* m_db;
};