#pragma once

#include <map>

#include "Question.h" 
#include "LoginManager.h"
#include "Room.h"
#include "RoomManager.h"
#include "Response.h"

// data
struct GameData
{
	Question currentQuestion;
	unsigned int correctAnsCount;
	unsigned int wrongAnsCount;
	unsigned int avgAnsTime;
};

class Game
{
public:
	// constructor
	Game(const Room& room,IDatabase* db,RoomManager* roomManager);

	// returns invalid if there isn't any more questions.
	Question getQuestionForUser(const LoggedUser& user);

	// submits the possible answer, returns the correct answer
	std::string submitAnswer(const LoggedUser& player, const std::string& posAns,const int& time_to_answer);

	// removes player from the room he is currently connected to
	void removePlayer(const LoggedUser& player);

	// getter for game id
	size_t getGameId();

	// return true if player is in game otherwise return false
	bool isUserInGame(const LoggedUser& user) const;

	// removes all players from the game
	void endGame();

	// first is the players name then their score
	std::vector<PlayerResults> getPlayersScores() const;

	// true if all users submited their answer for their last question else false
	bool allPlayersFinished() const;

	// if all players left the game returns true
	bool allPlayerLeft() const;

private:
	IDatabase* m_db;
	RoomManager* m_roomManager;
	std::vector<Question> m_questions;
	std::vector<std::pair<LoggedUser,GameData>> m_players;
	unsigned long int m_gameId;
	unsigned int m_gameMaxTime;
	int m_playerLeftCount;

	// submits a valid answer to the database
	void submitQuestionAnswerToDb(size_t playerId, size_t gameId, size_t questionNumber,bool correct,size_t time_to_answer,size_t game_max_time ) const;

	// searches and returns the user game data
	GameData& getUserGameData(const LoggedUser& user);
};