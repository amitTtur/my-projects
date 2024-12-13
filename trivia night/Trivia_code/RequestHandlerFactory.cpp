#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database)
{
    // creating the managers
    this->m_loginManager = new LoginManager(database);
    this->m_statManager = new StatisticsManager(database);
    this->m_roomManager = new RoomManager();
    this->m_GameManager = new GameManager(this->m_roomManager, database);
}

RequestHandlerFactory::~RequestHandlerFactory()
{
    // deleting them, DO IT IN THIS ORDER
    delete this->m_GameManager;
    delete this->m_roomManager;
    delete this->m_statManager;
    delete this->m_loginManager;
}

LoginManager* RequestHandlerFactory::getLoginManager()
{
    return this->m_loginManager;
}

RoomManager* RequestHandlerFactory::getRoomManager()
{
    return this->m_roomManager;
}

StatisticsManager* RequestHandlerFactory::getStatManager()
{
    return this->m_statManager;
}

GameManager* RequestHandlerFactory::getGameManager()
{
    return this->m_GameManager;
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
    LoginRequestHandler* ret = new LoginRequestHandler(*this);
    return ret;
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(LoggedUser user)
{
    MenuRequestHandler* tmp = new MenuRequestHandler(*this,user);
    return tmp;
}

ExitRequestHandler* RequestHandlerFactory::createExitRequestHandler()
{
    ExitRequestHandler* tmp = new ExitRequestHandler(*this);
    return tmp;
}

ErrorRequestHandler* RequestHandlerFactory::createErrorHandler(const std::string& errorMsg, const int code)
{
    ErrorRequestHandler* tmp = new ErrorRequestHandler(errorMsg,code);
    return tmp;
}

GameRequestHandler* RequestHandlerFactory::createGameHandler(LoggedUser user, Game& game)
{
    GameRequestHandler* tmp = new GameRequestHandler(*this,user,game);
    return tmp;
}
