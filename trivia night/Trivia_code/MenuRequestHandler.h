#pragma once
#include "IRequestHandler.h"
#include "codesAndDefines.h"
#include "MyException.h"
#include "Response.h"

#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class MenuRequestHandler : public IRequestHandler
{
public:
	// IRequestHandler is abstract so i don't need to call its constructor
	// cons and des
	MenuRequestHandler(RequestHandlerFactory& factory, LoggedUser user);
	virtual ~MenuRequestHandler() = default;

	// see explanations in the IRequestHandler class
	virtual bool isRequestRelevant(const RequestInfo& reqI) const override;
	virtual RequestResult handleRequest(const RequestInfo& reqI) const override;


private:
	// vars
	LoggedUser m_user;
	RequestHandlerFactory& m_factoryHandler;

	// private vars
	// handles a logout requests, removes the user from the logged user list
	RequestResult handleLogout() const;
	
	// creates a new room
	RequestResult handleCreateRoom(const RequestInfo& reqI) const;

	// returns all active rooms
	RequestResult handleGetRooms(const RequestInfo& reqI) const;

	// retruns all currect players in a room
	RequestResult handleGetPlayersInRoom(const RequestInfo& reqI) const;

	// adding a user into an existing room
	RequestResult handleJoinRoom(const RequestInfo& reqI) const;

	// get the top 5 players with the highest scores
	RequestResult handleGetTop5() const;

	// returns a user personal statistics
	RequestResult handleGetPersonalStats() const;

	// updates an active room
	RequestResult handleUpdateRoom(const RequestInfo& reqI) const;

	// returns an active room data
	RequestResult handleGetRoomData(const RequestInfo& reqI) const;

	// handles the case a user exists the room, if the user is the admin closes the room completely 
	// and sends according messages to all players that were in the room
	RequestResult handleExitRoom(const RequestInfo& reqI) const;

	// v4 start
	// starts game based on the room the admin is currently in
	RequestResult handleStartGame() const;

	// bonusses
	// add a question into a the database based on the given message info.
	RequestResult handleAddQuestion(const RequestInfo& reqI) const;
};