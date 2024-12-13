#include "LoginManager.h"

LoginManager::LoginManager(IDatabase* database)
{
	this->m_database = database;
}

LoginManager::~LoginManager()
{
}

void LoginManager::signUp(const std::string& username, const std::string& password, const std::string& email)
{
	this->m_database->addNewUser(username, password, email);
	std::cout << "User: " << username << " ,had registered into the system and added to the database." << std::endl;
}

void LoginManager::login(const std::string& username, const std::string& password)
{
	int tmpId = m_database->doesUserExist(username); 
	if (tmpId == 0)
	{
		throw MyException("User doesn't exist...");
	}

	tmpId =	m_database->doesPasswordMatch(username, password); // check the password of the user
	if (tmpId == 0)
	{
		throw MyException("Password doesn't match...");
	}

	for (auto it = this->m_loggedUsers.begin(); it != this->m_loggedUsers.end(); it++) // hceks if user is already connected
	{
		if (it->getUserName() == username)
		{
			throw MyException("User is already connected...");
		}
	}

	LoggedUser tmp(m_database->getUserName(tmpId)); // adds the user into the active user list

	this->m_loggedUsers.push_back(tmp);
	std::cout << "User: " << username << " ,had logged in." << std::endl;
}

void LoginManager::logout(const std::string& username)
{
    if (!m_database->doesUserExist(username))
    {
        throw MyException("User Doesn't Exist...");
    }

	for (auto it = m_loggedUsers.begin() ; it != m_loggedUsers.end() ; it++) 
	{
		if (it->getUserName() == username) // if user is in the active user list remove it in order to log him out.
		{
			this->m_loggedUsers.erase(it);
			std::cout << "User: " << username << " ,had logged out." << std::endl;
			return;
		}
	}
	throw MyException("User: "+username+" ,isn't connected therefore cant be disconnected..."); // if username isn't logged
}

