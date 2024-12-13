#pragma once
#include <vector>
#include <algorithm>

#include "SqliteDataBase.h"

class LoggedUser
{
public:
	// constructors
	LoggedUser() = default;
	LoggedUser(std::string username) { m_username = username; };
	// destructor
	~LoggedUser() = default;

	// getter setter
	std::string getUserName() const { return this->m_username; };
	void setUserName(const std::string& username) { this->m_username = username; };

private:
	// username of logged user
	std::string m_username;
};

class LoginManager
{
public:
	// cons and des
	LoginManager(IDatabase* database);
	~LoginManager();

	// added a user to the database
	void signUp(const std::string& username, const std::string& password, const std::string& email);

	// Adds a user into the m_loggedUsers vector
	void login(const std::string& username, const std::string& password);

	// Removes a user from the m_loggedUsers vector
	void logout(const std::string& username);

private:
	//vars
	IDatabase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
};

