#include "Room.h"

Room::Room(RoomData& data,const std::string& creator)
{
	// 0 for waiting, 99 for aborted, 1 for match started
	this->m_metaData.status = data.status;

	this->m_metaData.admin = creator;

	this->m_metaData.id = data.id;
	this->m_metaData.maxPlayers = data.maxPlayers;
	this->m_metaData.name = data.name;
	this->m_metaData.numOfQuestions = data.numOfQuestions;
	this->m_metaData.questionIdActive = data.questionIdActive;
	this->m_metaData.timePerQuestions = data.timePerQuestions;
}

void Room::addUser(const LoggedUser user)
{
	if (this->m_metaData.maxPlayers <= this->m_users.size())
	{
		throw MyException("Unable to join room...\nThe Room Max capacity has been reached.");
	}
	for (auto it : this->m_users)
	{
		if (it.getUserName() == user.getUserName())
		{
			throw MyException("User is already in the room.");
		}
	}
	this->m_users.push_back(user);
}

void Room::removeUser(const LoggedUser user)
{
	for (auto it = this->m_users.begin(); it != this->m_users.end(); it++)
	{
		if (it->getUserName() == user.getUserName())
		{
			if (this->m_metaData.admin == user.getUserName())
			{
				this->m_metaData.status = 99;
			}
			this->m_users.erase(it);
			break;
		}
	}

}

std::vector<LoggedUser> Room::getAllUsers() const
{
	std::vector<LoggedUser> ret;
	for (LoggedUser it : this->m_users)
	{
		ret.push_back(it);
	}
	return ret;
}

std::vector<std::string> Room::getAllUsersInString() const
{
	std::vector<std::string> ret;
	for (auto it = this->m_users.begin(); it != this->m_users.end(); it++)
	{
		if (it->getUserName() == this->m_metaData.admin)
		{
			ret.push_back(it->getUserName() + " (Admin)");
		}
		else
		{
			ret.push_back(it->getUserName());
		}

	}
	return ret;
}

size_t Room::getRoomState() const
{
	return this->m_metaData.status;
}

void Room::setRoomState(const short int state)
{
	this->m_metaData.status = state;
}

void Room::updateRoom(const int& newTime, const int& maxPlayers, const int& numOfQuestions)
{
	this->m_metaData.maxPlayers = maxPlayers;
	this->m_metaData.timePerQuestions = newTime;
	this->m_metaData.numOfQuestions = numOfQuestions;
}

RoomData Room::getRoomData() const
{
	return this->m_metaData;
}
