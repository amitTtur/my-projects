#include "GameManager.h"

GameManager::GameManager(RoomManager* roomManager, IDatabase* db) 
{
	this->m_db = db;
	this->m_roomManager = roomManager;
}

Game& GameManager::createGame(const Room& room)
{
	Game tmp(room, this->m_db, this->m_roomManager); // create an instance of a game
	this->m_games.push_back(tmp); // add it to the game list
	for (Game& it : this->m_games) // return the newly created game referance
	{
		if (it.getGameId() == tmp.getGameId())
		{
			return it;
		}
	}
}

void GameManager::deleteGame(const size_t gameId)
{
	for (Game& it : this->m_games)
	{
		if (it.getGameId() == gameId) // the automatic games deletor in communicator deletes the game itself
		{
			it.endGame();
			break;
		}
	}
}

Game& GameManager::returnTheRoomUserIsIn(const LoggedUser& user)
{
	for (Game& it : this->m_games)
	{
		if (it.isUserInGame(user))
		{
			return it;
		}
	}
	throw MyException("User isn't in any game...");
}

void GameManager::deleteFinishedGame()
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (auto it = this->m_games.begin(); it != this->m_games.end(); it++)
		{
			if (it->allPlayerLeft()) // if all players left the game delete it.
			{
				this->m_games.erase(it);
				flag = true;
				break; // 'it' increacement will throw an error if an itedor is deleted in the middle 
			}
		}
	}
	
}
