#pragma once
#include <io.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "IDatabase.h"
#include "MyException.h"
#include "DatabaseTableHolders.h"

#define DB_PATH "GallaryPRJCT.sqlite"

// COLUMNS NAMES
#define GENERAL_ID "ID"
#define TUSERS_USERNAME "USERNAME"
#define TUSERS_PASSWORD "PASSWORD"
#define TUSERS_EMAIL "EMAIL"

// questions table
#define TQ_QUESTION "QUESTION"
#define TQ_ANSWER "ANSWER"
#define TQ_IA "IA"
#define TQ_IA2 "IA2"
#define TQ_IA3  "IA3"

// statistics table
#define TSTAT_PLAYERID "PLAYER_ID"
#define TSTAT_GAMEID "GAME_ID"
#define TSTAT_QNUM "QUESTION_NUMBER"
#define TSTAT_CORRECTANS "CORRECT"
#define TSTAT_TIME_TO_ANSWER  "TIME_TO_ANSWER"
#define TSTAT_MAX_TIME  "GAME_MAX_TIME"


class SqliteDataBase : public IDatabase
{
public:
	// cons and des
	SqliteDataBase();
	virtual ~SqliteDataBase();

	/*
	* See all public functions comments in IDatabase class.
	*/ 
	
	virtual void open() override;
	virtual void close() override;

	virtual int doesUserExist(const std::string& username) const override;

	virtual int doesPasswordMatch(const std::string& username, const std::string& password) const override;

	virtual int addNewUser(const std::string& username, const std::string& password, const std::string& email) const override;

	virtual std::string getUserName(const int id) const override;

	/****      v2 functions       ****/

	virtual void addQuestion(const std::string& q, const std::string& ca, const std::string& ia,
		const std::string& ia2, const std::string& ia3) const override;

	virtual std::vector<Question> getQuestions(int numToGive) const override;

	virtual double getPlayerAverageAnswerTime(const std::string& playerName) const override;

	virtual int getNumOfCorrectAnswers(const std::string& playerName) const override;

	virtual int getNumOfTotalAnswers(const std::string& playerName) const override;

	virtual int getNumOfPlayerGames(const std::string& playerName) const override; 
	
	virtual int getHighestScoreOfPlayer(const std::string& playerName) const override;

	virtual int getHighestGameID() const override;

	virtual std::vector<std::pair<std::string, size_t>> getTop5scores() const override;

	static bool compareScores(const std::pair<std::string, size_t>& leftVar, const std::pair<std::string, size_t>& rightVar);

	virtual void simple_exec(const std::string& strSQL) const override;

	virtual size_t getPlayerId(const std::string& username) const override;

	virtual size_t getPlayerGameScore(const std::string& username, const int gameId) const override;

	virtual int getNumberOfAvailableQuestions() const override;

	////////////////////////////

private:
	// var
	sqlite3* _db;

	// private functions
	
	// creates the database tables if the do not exist
	void initdb() const;

	
	/*
	* GENERAL EXPLANATION
	* callback - a function that is necessary in order to read the sql response from the
	* database, the function basically adds a row into the given data
	* 
	* get*QueryRSP - the vector of the given type will have the given sql line results in
	* it assuming the vector is empty. the function basically runs a sql line and update the given
	* vector based on the results
	*/

	static int user_callback(void* data, int argc, char** argv, char** azColName);

	void getUserQueryRSP(const std::string& strSQL, std::vector<UserHolder>& resp) const;

	static int stat_callback(void* data, int argc, char** argv, char** azColName);

	void getStatQueryRSP(const std::string& strSQL, std::vector<StatsHolder>& resp) const;

	static int question_callback(void* data, int argc, char** argv, char** azColName);

	void getQuestionQueryRSP(const std::string& strSQL, std::vector<QuestionHolder>& resp) const;


	// a function that calculates a SINGLE row of user statistics
	int calculateScore(const int& isCorrect, const int& maxTime,const int& timeItTookToAnswer) const;

	// sorts the given vector based the new node second field if the field is higher then
	// any existing node, the node will be added and sorted accordingly.
	void insertAndSortScoreList(std::vector<std::pair<std::string, size_t>>& list, std::pair<std::string, size_t> toAdd) const;
};
