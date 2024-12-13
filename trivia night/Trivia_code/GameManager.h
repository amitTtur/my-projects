#pragma once

#include "Game.h"

class GameManager
{
public:
	// constructor
	GameManager(RoomManager* roomManager, IDatabase* db);

	// adds a game based on the giveen room and it's propeties
	Game& createGame(const Room& room);

	// delets game from the list based on his id
	void deleteGame(const size_t gameId);

	// self explanitory
	Game& returnTheRoomUserIsIn(const LoggedUser& user);

	// if all players left the game deletes the room
	// checks condition on every existing active game
	void deleteFinishedGame();

private:
	// vars
	RoomManager* m_roomManager;
	IDatabase* m_db;
	std::vector<Game> m_games;
};