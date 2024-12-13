#pragma comment (lib, "ws2_32.lib")

#include "Server.h"
#include "WSAInitializer.h"

// drive link
//https://drive.google.com/drive/folders/1Fq-Y6lMlkXrCovQTbV0PgAJ-lzkmTgV2

#include "SqliteDataBase.h"

int main()
{
	{
		WSAInitializer wsaInit;
		Server server;
		server.run(); // run the server
	}
	
	return 0;
}