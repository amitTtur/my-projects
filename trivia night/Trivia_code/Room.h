#pragma once
#include <vector>

#include "LoginManager.h"

struct RoomData
{
	/// <summary>
	/// 0- session didnt start yet
	/// 1- session is ongoing
	/// 99- session aborted
	/// </summary>
	size_t status;

	std::string admin;
	unsigned int id;
	std::string name;
	unsigned int maxPlayers;
	unsigned int numOfQuestions;
	unsigned int timePerQuestions;
	unsigned int questionIdActive;
};

class Room
{
public:
	// cons and des
	Room(RoomData& data, const std::string& creator);
	~Room() = default;

	// Adds a user into the user field
	void addUser(const LoggedUser user);

	// Removes a user from the user field
	void removeUser(const LoggedUser user);

	// getter for the users field
	std::vector<LoggedUser> getAllUsers() const;

	// the user field in string vector instead of a logged user vector. the admin as a '(admin)' text near him
	std::vector<std::string> getAllUsersInString() const;

	// getter and setter for room state field in the metaData field
	size_t getRoomState() const;
	void setRoomState(const short int state);

	// updates room metaData according to the given vars
	void updateRoom(const int& newTime, const int& maxPlayers, const int& numOfQuestions);

	// returns the room data
	RoomData getRoomData() const;

private:
	// vars
	std::vector<LoggedUser> m_users;
	RoomData m_metaData;
	
	
};