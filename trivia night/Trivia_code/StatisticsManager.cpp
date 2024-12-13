#include "StatisticsManager.h"

StatisticsManager::StatisticsManager(IDatabase* db)
{
	this->m_db = db;
}

std::vector<std::pair<std::string, size_t>> StatisticsManager::getTop5bestScores() const
{
	return this->m_db->getTop5scores();
}

std::vector<std::pair<std::string, double>> StatisticsManager::getUserStatistics(const std::string& username) const
{
	std::vector<std::pair<std::string, double>> vec;

	vec.push_back(std::pair<std::string, double>("Games",this->m_db->getNumOfPlayerGames(username)));
	vec.push_back(std::pair<std::string, double>("BestScore",this->m_db->getHighestScoreOfPlayer(username)));
	vec.push_back(std::pair<std::string, double>("NumberOfCorrectAns", this->m_db->getNumOfCorrectAnswers(username)));
	vec.push_back(std::pair<std::string, double>("TotalQuestionsAnswered", this->m_db->getNumOfTotalAnswers(username)));
	vec.push_back(std::pair<std::string, double>("AvgTimeToAnswer", this->m_db->getPlayerAverageAnswerTime(username)));

	return vec;
}

void StatisticsManager::addQuestion(const std::string& question, const std::string& answer, const std::string& wrong_ans1, const std::string& wrong_ans2, const std::string& wrong_ans3) const
{
	this->m_db->addQuestion(question, answer, wrong_ans1, wrong_ans2, wrong_ans3);
}

int StatisticsManager::getAvailableQuestions() const
{
	return this->m_db->getNumberOfAvailableQuestions();
}
