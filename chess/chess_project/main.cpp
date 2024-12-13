#include "Point.h"
#include "Game.h"
#include <iostream>
#include <string>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Pipe.h"
#include <thread>

using std::cout;
using std::endl;
using std::string;

int main()
{
	Game* s1 = new Game(0);
	std::cout << s1->getBoardView() << std::endl;
	srand(time_t(NULL));

	//DONT REMOVE THE OFFSETERS IT CAUSES A MEM LEAK
	{
		Pipe p;
		bool isConnect = p.connect();

		string ans;
		while (!isConnect)
		{
			cout << "cant connect to graphics" << endl;
			cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
			std::cin >> ans;

			if (ans == "0")
			{
				cout << "trying connect again.." << endl;
				Sleep(500);
				isConnect = p.connect();
			}
			else
			{
				p.close();
				delete s1;
				std::cout << "Leaks: " << _CrtDumpMemoryLeaks() << std::endl;
				return 1;
			}
		}


		char msgToGraphics[1024];
		// msgToGraphics should contain the board string accord the protocol

		strcpy_s(msgToGraphics, s1->translateBoardToString().c_str());
		p.sendMessageToGraphics(msgToGraphics);// send the board string


		// get message from graphics
		string msgFromGraphics = p.getMessageFromGraphics();


		while (msgFromGraphics != "quit")
		{

			s1->convertTextToPoint(msgFromGraphics);

			std::cout << s1->getBoardView() << std::endl;

			strcpy_s(msgToGraphics, std::to_string(s1->turn()).c_str());

			// return result to graphics		
			p.sendMessageToGraphics(msgToGraphics);

			// get message from graphics
			msgFromGraphics = p.getMessageFromGraphics();
		}

		p.close();
	}


	delete s1;
	std::cout << "Leaks: " << _CrtDumpMemoryLeaks() << std::endl;
	return 0;
}