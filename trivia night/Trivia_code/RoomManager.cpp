#include "RoomManager.h"

size_t RoomManager::generateRoomId() const
{
	size_t ret;
	std::mutex mtx;
	mtx.lock(); // case a room is trying to get the room size
	ret = this->m_rooms.size();
	mtx.unlock();
	return ret;
}

void RoomManager::createRoom(LoggedUser user, RoomData data)
{
	if (data.id < this->m_rooms.size())
	{
		throw MyException("Room with that id Already exists!!! [roomManager -> createRoom]");
	}
	for (auto it : this->m_rooms)
	{
		if (data.name == it.second.getRoomData().name)
		{
			throw MyException("Room already exist with that name...");
		}
	}
	Room room(data,user.getUserName());
	room.addUser(user);
	this->m_rooms.insert(std::pair<size_t, Room>(data.id, room));
}

void RoomManager::deleteRoom(const std::string& roomName)
{
	for (auto it = this->m_rooms.begin(); it != this->m_rooms.end(); it++)
	{
		if (it->second.getRoomData().name == roomName)
		{
			this->m_rooms.erase(it);
			break;
		}
	}
}

unsigned int RoomManager::getRoomState(const std::string& roomName) const
{
	for (auto it = this->m_rooms.begin(); it != this->m_rooms.end(); it++)
	{
		if (it->second.getRoomData().name == roomName)
		{
			return it->second.getRoomState();
		}
	}
}

void RoomManager::updateRoom(std::string& roomName, const int& newTime, const int& maxPlayers, const int& numOfQuestions)
{
	Room& room = getRoom(roomName);
	room.updateRoom(newTime, maxPlayers, numOfQuestions);
}

void RoomManager::removePlayer(const LoggedUser& user)
{
	for (auto& it : this->m_rooms)
	{
		it.second.removeUser(user);
	}
}

void RoomManager::deleteInactiveRooms()
{
	bool flag = true;
	while (flag)
	{
		flag = false;
		for (auto it : this->m_rooms)
		{
			if (it.second.getAllUsers().size() == 0)
			{
				try
				{
					this->deleteRoom(it.second.getRoomData().name);
					flag = true;
					break;
				}
				catch (...) {}
			}
		}
	}
}

std::vector<RoomData> RoomManager::getRooms()
{
	std::vector<RoomData> ret;
	for (auto it = this->m_rooms.begin(); it != this->m_rooms.end(); it++)
	{
		ret.push_back(it->second.getRoomData());
	}
	return ret;
}

Room& RoomManager::getRoom(const std::string& roomName)
{
	for (auto it = this->m_rooms.begin(); it != this->m_rooms.end(); it++)
	{
		if (it->second.getRoomData().name == roomName)
		{
			return it->second;
		}
	}
	throw MyException("Room with that name doesn't exist...");
}

Room& RoomManager::getRoom(const LoggedUser& userInRoom)
{
	for (auto& it : this->m_rooms)
	{
		Room& tmp = it.second;
		for( auto jt : tmp.getAllUsers())
		{
			if (jt.getUserName()==userInRoom.getUserName())
			{
				return tmp;
			}
		}
	}
	throw MyException("User isn't in any room...");
}

