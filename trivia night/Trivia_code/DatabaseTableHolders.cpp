#include "DatabaseTableHolders.h"

// all are setters and getters

void StatsHolder::setStatId(const size_t& statId)
{
	this->_statId = statId;
}

void StatsHolder::setPlayerId(const size_t& playerId)
{
	this->_playerId = playerId;
}

void StatsHolder::setGameId(const size_t& gameId)
{
	this->_gameId = gameId;
}

void StatsHolder::setQuestionNumber(const size_t& questionNumber)
{
	this->_questionNumber = questionNumber;
}

void StatsHolder::setCorrect(const size_t& correct)
{
	this->_correct = correct;
}

void StatsHolder::setTimeToAnswer(const size_t& timeToAnswer)
{
	this->_timeToAnswer = timeToAnswer;
}

void StatsHolder::setMaxTime(const size_t& maxTime)
{
	this->_maxTime = maxTime;
}

size_t StatsHolder::getStatId() const
{
	return this->_statId;
}

size_t StatsHolder::getPlayerId() const
{
	return this->_playerId;
}

size_t StatsHolder::getGameId() const
{
	return this->_gameId;
}

size_t StatsHolder::getQuestionNumber() const
{
	return this->_questionNumber;
}

size_t StatsHolder::getCorrect() const
{
	return this->_correct;
}

size_t StatsHolder::getTimeToAnswer() const
{
	return this->_timeToAnswer;
}

size_t StatsHolder::getMaxTime() const
{
	return this->_maxTime;
}

void UserHolder::setUserId(const size_t& userId)
{
	this->_userId = userId;
}

void UserHolder::setUsername(const std::string& username)
{
	this->_username = username;
}

void UserHolder::setPassword(const std::string& password)
{
	this->_password = password;
}

void UserHolder::setEmail(const std::string& email)
{
	this->_email = email;
}

size_t UserHolder::getUserId() const
{
	return this->_userId;
}

std::string UserHolder::getUsername() const
{
	return this->_username;
}

std::string UserHolder::getPassword() const
{
	return this->_password;
}

std::string UserHolder::getEmail() const
{
	return this->_email;
}

void QuestionHolder::setQuestionId(const size_t& questionId)
{
	this->_questionId = questionId;
}

void QuestionHolder::setQuestion(const std::string& question)
{
	this->_question = question;
}

void QuestionHolder::setAnswer(const std::string& ans)
{
	this->_answer = ans;
}

void QuestionHolder::setA1(const std::string& a1)
{
	this->_a1 = a1;
}

void QuestionHolder::setA2(const std::string& a2)
{
	this->_a2 = a2;
}

void QuestionHolder::setA3(const std::string& a3)
{
	this->_a3 = a3;
}

size_t QuestionHolder::getQuestionId() const
{
	return this->_questionId;
}

std::string QuestionHolder::getQuestion() const
{
	return this->_question;
}

std::string QuestionHolder::getAnswer() const
{
	return this->_answer;
}

std::string QuestionHolder::getA1() const
{
	return this->_a1;
}

std::string QuestionHolder::getA2() const
{
	return this->_a2;
}

std::string QuestionHolder::getA3() const
{
	return this->_a3;
}
