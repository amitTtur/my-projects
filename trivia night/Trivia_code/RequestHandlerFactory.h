#pragma once
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "ExitRequestHandler.h"
#include "LoginManager.h"
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "ErrorRequestHandler.h"
#include "GameRequestHandler.h"
#include "GameManager.h"


class MenuRequestHandler;
class LoginRequestHandler;
class ExitRequestHandler;
class ErrorRequestHandler;
class GameRequestHandler;

class RequestHandlerFactory
{
public:
	// cons and des
	RequestHandlerFactory(IDatabase* database);
	~RequestHandlerFactory();

	// getters for fields
	LoginManager* getLoginManager();
	RoomManager* getRoomManager();
	StatisticsManager* getStatManager();
	GameManager* getGameManager();

	/// handles creators
	// need to dynamically delete when finished using 
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(LoggedUser user);
	ExitRequestHandler* createExitRequestHandler();
	ErrorRequestHandler* createErrorHandler(const std::string& errorMsg, const int code);
	GameRequestHandler* createGameHandler(LoggedUser user, Game& game);

private:
	// vars
	LoginManager* m_loginManager;
	RoomManager* m_roomManager;
	StatisticsManager* m_statManager;
	GameManager* m_GameManager;
};