#include "Question.h"


Question::Question(const std::string& question, const std::string& ans, const std::vector<std::string>& possAns, size_t id)
{
	this->m_question = question;
	this->m_correctAns = ans;

	for (auto it : possAns)
	{
		this->m_possibleAnswers.push_back(it);
	}
	this->m_isValid = true;
	this->m_id = id;
}

Question::Question()
{
	this->m_isValid = false;
}

void Question::setAll(const std::string& question, const std::string& ans, const std::string& a1, const std::string& a2, const std::string& a3, size_t id)
{
	this->m_correctAns = ans;
	this->m_id = id;
	this->m_question = question;

	this->m_possibleAnswers.clear(); // clearing any existing answers
	this->m_possibleAnswers.push_back(a1);
	this->m_possibleAnswers.push_back(a2);
	this->m_possibleAnswers.push_back(a3);
}

void Question::setAllCopy(const Question q)
{
	this->m_correctAns = q.getCorrectAnswer();
	this->m_id = q.getId();
	this->m_isValid = q.getValid();
	this->m_possibleAnswers = q.getPossibleAnswers();
	this->m_question = q.getQuestion();
}

std::string Question::getQuestion() const
{
	return this->m_question;
}

std::vector<std::string> Question::getPossibleAnswers() const
{
	return this->m_possibleAnswers;
}

size_t Question::getId() const
{
	return this->m_id;
}

std::string Question::getCorrectAnswer() const
{
	return this->m_correctAns;
}

void Question::validate()
{
	this->m_isValid = true;
}

bool Question::getValid() const
{
	return this->m_isValid;
}
