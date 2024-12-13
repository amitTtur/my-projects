#include "Game.h"

Game::Game(const Room& room,IDatabase* db, RoomManager* roomManager)
{

	std::vector<LoggedUser> usersInRoom = room.getAllUsers(); // users to users ,copy

	GameData tmpOverAllData; // empty game data
	tmpOverAllData.avgAnsTime = 0.0;
	tmpOverAllData.correctAnsCount = 0.0;
	tmpOverAllData.currentQuestion = Question(); // empty question
	tmpOverAllData.wrongAnsCount = 0;

	// db to db
	this->m_db = db;

	for (LoggedUser user : usersInRoom) // for every user create a copy of an empty data instance
	{
		this->m_players.push_back(std::make_pair(user, tmpOverAllData));
	}

	// generating a unique game id
	this->m_gameId = room.getRoomData().id + 1 + this->m_db->getHighestGameID();

	this->m_questions = this->m_db->getQuestions(room.getRoomData().numOfQuestions); // get a randomized questions from database

	this->m_gameMaxTime = room.getRoomData().timePerQuestions;

	this->m_roomManager = roomManager;

	this->m_playerLeftCount = 0;
}

Question Game::getQuestionForUser(const LoggedUser& user)
{
	GameData& tmpData = getUserGameData(user); // get user data

	if (tmpData.currentQuestion.getValid()) // if it isn't valid it means it is the empty constructor question
	{
		for (int qIndex = 0; qIndex < this->m_questions.size(); qIndex++)
		{
			if (this->m_questions[qIndex].getQuestion() == tmpData.currentQuestion.getQuestion()) // look for the current question in the list
			{
				if ((qIndex+1) == this->m_questions.size()) // if the question list reached the end return an empty
				{                                           // question which indicates the end of availible questions.
					std::vector<std::string> t;
					t.push_back("END");
					t.push_back("END");
					t.push_back("END");
					tmpData.currentQuestion = Question("END", "END", t, -1);
					return tmpData.currentQuestion;
				}
				else // if it didnt return the next question
				{
					tmpData.currentQuestion = this->m_questions[qIndex + 1];
					return tmpData.currentQuestion;
				}
			}
		}

	}
	else // if its the contructor question, return the first question in the question vector.
	{
		return tmpData.currentQuestion = this->m_questions[0];
	}
	// if somthing unexpected happened return a end question indicator
	std::vector<std::string> t;
	t.push_back("END");
	t.push_back("END");
	t.push_back("END");
	tmpData.currentQuestion = Question("END", "END", t, -1);
	return tmpData.currentQuestion;
}

std::string Game::submitAnswer(const LoggedUser& player, const std::string& posAns, const int& time_to_answer)
{
	GameData& tmpData = this->getUserGameData(player);

	// add the given question time to the average 
	tmpData.avgAnsTime = (tmpData.avgAnsTime + time_to_answer) / (tmpData.correctAnsCount + tmpData.wrongAnsCount + 1);
	try
	{
		bool isCorrect = (tmpData.currentQuestion.getCorrectAnswer() == posAns); // checks if the user answered correctly 
		if (isCorrect)
		{
			tmpData.correctAnsCount++;
		}
		else
		{
			tmpData.wrongAnsCount++;
		}
		// submit the question result the the database
		this->submitQuestionAnswerToDb(this->m_db->getPlayerId(player.getUserName()), this->m_gameId,
			this->getUserGameData(player).currentQuestion.getId(), isCorrect,
			time_to_answer, this->m_gameMaxTime);
	}
	catch (...)
	{
		throw MyException("Error submitting answer");
	}
	// return the correct answer
	return tmpData.currentQuestion.getCorrectAnswer();
}

void Game::removePlayer(const LoggedUser& player)
{
	for (auto it = this->m_players.begin(); it != this->m_players.end(); it++) // search for the players
	{
		if (it->first.getUserName() == player.getUserName())
		{
			// filling the missing questions
			while (this->getUserGameData(player).currentQuestion.getId() != -1)
			{
				submitAnswer(player, "", 999);
				this->getUserGameData(player).currentQuestion.setAllCopy(this->getQuestionForUser(player));
			}
			
			// we do not remove the player in order to get his end result
			this->m_playerLeftCount++;
			// but we do remove him from the room
			this->m_roomManager->removePlayer(player);
			break;
		}
	}
}

size_t Game::getGameId()
{
	return this->m_gameId;
}

bool Game::isUserInGame(const LoggedUser& user) const
{
	for (auto it : this->m_players)
	{
		if (it.first.getUserName() == user.getUserName())
		{
			return true;
		}
	}
}

void Game::endGame() // removes all players from the game
{
	for (auto it : this->m_players) 
	{
		this->removePlayer(it.first);
	}
}

std::vector<PlayerResults> Game::getPlayersScores() const
{
	std::vector<PlayerResults> ret;

	for (auto it : this->m_players) // for every player
	{
		PlayerResults tmp;
		tmp.username = it.first.getUserName();
		tmp.score = this->m_db->getPlayerGameScore(tmp.username,this->m_gameId); // gets the player score in this game
		ret.push_back(tmp);
	}
	return ret;
}

bool Game::allPlayersFinished() const
{
	for (auto it : this->m_players)
	{
		if (it.second.currentQuestion.getId() != -1) // if the question id is -1 it means he finished answering the questions
		{
			return false;
		}
	}
	return true;
}

bool Game::allPlayerLeft() const
{
	return (this->m_playerLeftCount == this->m_players.size());
}

void Game::submitQuestionAnswerToDb(size_t playerId, size_t gameId, size_t questionNumber, bool correct, size_t time_to_answer, size_t game_max_time) const
{
	// imagine building this sql line. pfft couln't be me
	std::string strSQL = "INSERT INTO STATISTICS (" + std::string(TSTAT_PLAYERID) + "," + std::string(TSTAT_GAMEID) +
		"," + std::string(TSTAT_QNUM) + "," + std::string(TSTAT_CORRECTANS) + "," + std::string(TSTAT_TIME_TO_ANSWER) + "," +
		std::string(TSTAT_MAX_TIME) + ") VALUES (" + std::to_string(playerId) + "," + std::to_string(gameId) + "," +
		std::to_string(questionNumber) + "," + std::to_string(int(correct)) + "," + std::to_string(time_to_answer) + "," +
		std::to_string(game_max_time) + ");";

	// i use simple execute for the INSERT INTO sql lines
	this->m_db->simple_exec(strSQL);
}

GameData& Game::getUserGameData(const LoggedUser& user)
{
	for (size_t i = 0; i < this->m_players.size(); i++)
	{
		if (this->m_players[i].first.getUserName() == user.getUserName())
		{
			return this->m_players[i].second;
		}
	}
}
