#pragma once
#include "SqliteDataBase.h"

class StatisticsManager
{
public:
	// cons and des
	StatisticsManager(IDatabase* db);
	~StatisticsManager() = default;

	// returns the top 5 best results. a user can only appear once in the scores 
	// right var is the username, second is his score 
	std::vector<std::pair<std::string, size_t>> getTop5bestScores() const;
	
	// returns a vector containing the given user statistics based of his username and current existing data.
	// first one is the field second is the value
	// ex: avg time to answer, 8.98
	std::vector<std::pair<std::string, double>> getUserStatistics(const std::string& username) const;

	// adds a question to the database
	void addQuestion(const std::string& question, const std::string& answer, const std::string& wrong_ans1,
		const std::string& wrong_ans2,const std::string& wrong_ans3) const;

	// returns the number of questions the database contains
	int getAvailableQuestions() const;

private:
	IDatabase* m_db;
};