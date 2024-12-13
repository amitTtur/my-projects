#pragma once
#include <random>

#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class RequestHandlerFactory;
class Game;

class GameRequestHandler : public IRequestHandler
{
public:
	// constructor
	GameRequestHandler(RequestHandlerFactory& factory, LoggedUser user,Game& game);

	// cheks if the request code matches the handler
	virtual bool isRequestRelevant(const RequestInfo& reqI) const override;

	// handles request
	virtual RequestResult handleRequest(const RequestInfo& reqI) const override;

private:
	// vars
	RequestHandlerFactory& m_factoryHandler;
	Game& m_game;
	LoggedUser m_user;
	// don't need a gameManager var because there is one inside factoryHandler

	// private functions
	// returns the connected user nect question
	RequestResult handleGetQuestion() const;

	// submits the user answer, returns the correct one in the returned buffer
	RequestResult handleSubmitAnswer(const RequestInfo& reqI) const;

	// gets the game results in the user active game 
	RequestResult handleGetGameResults() const;

	// dicconects the user from the game he's in
	RequestResult handleLeaveGame() const;
};