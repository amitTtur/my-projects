#pragma once
#include <map>
#include <mutex>

#include "Room.h"

class RoomManager
{
public:
	// cons and des
	RoomManager() = default;
	~RoomManager() {};

	// generates a room id based on all active rooms
	size_t generateRoomId() const;

	// creates room the given user is the admin, and the given data will be the data for the room.
	void createRoom(LoggedUser user, RoomData data);

	// deletes a room based on the room name
	void deleteRoom(const std::string& roomName);

	// returns a room state.
	// 0 - session didn't start yet
	// 1 - session is ongoing
	// 99 - session aborted
	unsigned int getRoomState(const std::string& roomName) const;

	// updates a room based on the given room name, and the vars given
	void updateRoom(std::string& roomName, const int& newTime, const int& maxPlayers, const int& numOfQuestions);

	// removes player from a room
	void removePlayer(const LoggedUser& user);

	// deletes a inactive room. where the user count in it is equal to 0
	void deleteInactiveRooms();

	// getters
	std::vector<RoomData> getRooms();
	Room& getRoom(const std::string& roomName);
	Room& getRoom(const LoggedUser& userInRoom);

private:
	// id of the room, and the room object
	std::map<size_t, Room> m_rooms;
};