#include "Server.h"

Server::Server()
{
	// create in this order
	this->m_db = new SqliteDataBase();
	this->m_factoryHandler = new RequestHandlerFactory(this->m_db);
	this->m_communicator = new Communicator(m_db, m_factoryHandler);
}

Server::~Server()
{
	// delete in this order
	delete this->m_communicator;
	delete this->m_factoryHandler;
	delete this->m_db;
}

void Server::run()
{
	try
	{
		std::thread userT(&Communicator::startHandleRequest, this->m_communicator);
		userT.detach();
		std::string input;
		while (strcmp(input.c_str(), EXIT_STR)) // continualy check if a exit message was called
		{
			std::cout << "Do you want to stop the run of the server (" << (EXIT_STR) << " if yes): ";
			std::cin >> input;
		}
		this->m_communicator->exitAll();
	}
	catch (std::exception& e)
	{
		std::cout << "Error occurred: " << e.what() << std::endl;
	}
}
