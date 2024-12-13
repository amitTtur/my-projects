#pragma once
#include "sqlite3.h"
#include <string>
#include <list>
#include "Question.h"
#include <set>

class IDatabase
{
public:
	// opens the database
	virtual void open() = 0;
	// closes the data base
	virtual void close() = 0;

	// returns the id of the user, -1 if user doesn't exist
	virtual int doesUserExist(const std::string& username) const = 0;
	// returns the id of the user, return -1 if user doesn't exist ,-2 if the password doesn't match
	virtual int doesPasswordMatch(const std::string& username, const std::string& password) const = 0;
	// returns the id of the new user, -1 a user already exist with that name
	virtual int addNewUser(const std::string& username, const std::string& password, const std::string& email) const = 0;

	// returns the user username based of his id
	virtual std::string getUserName(const int id) const = 0;

	// adds a question to the database
	virtual void addQuestion(const std::string& q, const std::string& ca, const std::string& ia,
		const std::string& ia2, const std::string& ia3) const = 0;

	/// <summary>
	/// gives the number of question the function is asked for, if the nu,ber asked is higher then the existing questions
	/// return the maximum amount of available questions.
	/// </summary>
	/// <param name="numToGive"></param> number of questions to give
	/// <returns></returns> a vector with the returned question
	virtual std::vector<Question> getQuestions(int numToGive) const = 0;

	// checks and returns the player avrage answer time based on his stats
	virtual double getPlayerAverageAnswerTime(const std::string& playerName) const = 0;

	// returns player overall correct answers
	virtual int getNumOfCorrectAnswers(const std::string& playerName) const = 0;

	// returns player overall number of answers, whether it is correct or not
	virtual int getNumOfTotalAnswers(const std::string& playerName) const = 0;

	// returns the number of played games of a user
	virtual int getNumOfPlayerGames(const std::string& playerName) const = 0;

	// calculates and checks the highest score the player had achived in a game and returns it.
	virtual int getHighestScoreOfPlayer(const std::string& playerName) const = 0;

	// returns the id if the game with the highest id there is
	virtual int getHighestGameID() const = 0;

	// returns the username and the score of the top 5 ranking users
	virtual std::vector<std::pair<std::string, size_t>> getTop5scores() const = 0;

	/// <summary>
	/// executes a sql line. Basically for INSERT DELETE DROP ect...
	/// </summary>
	/// <param name="strSQL"></param> the sql to execute.
	virtual void simple_exec(const std::string& strSQL) const = 0;

	// returns user id based on his username
	virtual size_t getPlayerId(const std::string& username) const = 0;

	// returns the player score in the given game
	virtual size_t getPlayerGameScore(const std::string& username,const int gameId) const = 0;

	// returns the number of avalible questions in the database.
	virtual int getNumberOfAvailableQuestions() const = 0;

private:
};