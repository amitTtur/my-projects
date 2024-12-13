#pragma once
#include <string>
#include <vector>

class Question
{
public:
	// constructors and des
	Question(const std::string& question, const std::string& ans, const std::vector<std::string>& possAns,size_t id);
	Question();
	~Question() = default;

	// sets al field of the class
	void setAll(const std::string& question, const std::string& ans, const std::string& a1,
		const std::string& a2, const std::string& a3, size_t id);

	// copies field f another question class into this class
	void setAllCopy(const Question q);

	// getters
	std::string getQuestion() const;
	std::vector<std::string> getPossibleAnswers() const;
	size_t getId() const;
	std::string getCorrectAnswer() const;
	bool getValid() const;

	// turns the valid field to true 
	void validate();

private:
	// vars
	size_t m_id;
	std::string m_question;
	std::vector<std::string> m_possibleAnswers;
	std::string m_correctAns;
	bool m_isValid;
};