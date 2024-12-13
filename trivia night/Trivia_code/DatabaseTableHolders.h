#pragma once
#include <string>

class StatsHolder
{
public:
	// Setters
	void setStatId(const size_t& statId);
	void setPlayerId(const size_t& playerId);
	void setGameId(const size_t& gameId);
	void setQuestionNumber(const size_t& questionNumber);
	void setCorrect(const size_t& correct);
	void setTimeToAnswer(const size_t& timeToAnswer);
	void setMaxTime(const size_t& maxTime);

	// Getters 
	size_t getStatId() const;
	size_t getPlayerId() const;
	size_t getGameId() const;
	size_t getQuestionNumber() const;
	size_t getCorrect() const;
	size_t getTimeToAnswer() const;
	size_t getMaxTime() const;

private:
	// vars
	size_t _statId;
	size_t _playerId;
	size_t _gameId;
	size_t _questionNumber;
	size_t _correct;
	size_t _timeToAnswer;
	size_t _maxTime;
};

class UserHolder
{
public:
	// Setters
	void setUserId(const size_t& userId);
	void setUsername(const std::string& username);
	void setPassword(const std::string& password);
	void setEmail(const std::string& email);

	// Getters
	size_t getUserId() const;
	std::string getUsername() const;
	std::string getPassword() const;
	std::string getEmail() const;

private:
	// vars
	size_t _userId;
	std::string _username;
	std::string _password;
	std::string _email;
};

class QuestionHolder
{
public:
	// Setters
	void setQuestionId(const size_t& questionId);
	void setQuestion(const std::string& question);
	void setAnswer(const std::string& ans);
	void setA1(const std::string& a1);
	void setA2(const std::string& a2);
	void setA3(const std::string& a3);

	// Getters
	size_t getQuestionId() const;
	std::string getQuestion() const;
	std::string getAnswer() const;
	std::string getA1() const;
	std::string getA2() const;
	std::string getA3() const;

private:
	// vars
	size_t _questionId;
	std::string _question;
	std::string _answer;
	std::string _a1;
	std::string _a2;
	std::string _a3;
};