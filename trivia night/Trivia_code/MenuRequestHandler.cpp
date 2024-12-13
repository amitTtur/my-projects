#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory& factory, LoggedUser user) : m_factoryHandler(factory)
{
    this->m_user.setUserName(user.getUserName());
}

bool MenuRequestHandler::isRequestRelevant(const RequestInfo& reqI) const
{
    if (reqI.codeId == GET_ROOM || reqI.codeId == LOGOUT || reqI.codeId == PLAYERS_IN_ROOM || 
        reqI.codeId == JOIN_ROOM || reqI.codeId == CREATE_ROOM || reqI.codeId == GET_TOP5 || 
        reqI.codeId == GET_PERSONAL_STATS || reqI.codeId == UPDATE_ROOM_SETTINGS ||
        reqI.codeId == GET_ROOM_DATA || reqI.codeId == EXIT_ROOM || reqI.codeId == START_GAME || reqI.codeId == ADD_QUESTION)
    {
        return true;
    }
    return false;
}

RequestResult MenuRequestHandler::handleRequest(const RequestInfo& reqI) const
{
    if (!isRequestRelevant(reqI))
    {
        throw MyException("Irrelevant request [STAGE NOT REACHED OR STAGE PASSED]. { MENU HANDLER }");
    }
    
    switch (reqI.codeId)
    {
    case LOGOUT:
    {
        return this->handleLogout();
    }
    case CREATE_ROOM:
    {
        return this->handleCreateRoom(reqI);
    }
    case GET_ROOM:
    {
        return this->handleGetRooms(reqI);
    }
    case PLAYERS_IN_ROOM:
    {
        return this->handleGetPlayersInRoom(reqI);
    }
    case JOIN_ROOM:
    {
        return this->handleJoinRoom(reqI);
    }
    case GET_TOP5:
    {
        return this->handleGetTop5();
    }
    case GET_PERSONAL_STATS:
    {
        return this->handleGetPersonalStats();
    }
    case UPDATE_ROOM_SETTINGS:
    {
        return this->handleUpdateRoom(reqI);
    }
    case GET_ROOM_DATA:
    {
        return this->handleGetRoomData(reqI);
    }
    case EXIT_ROOM:
    {
        return this->handleExitRoom(reqI);
    }
    case START_GAME:
    {
        return this->handleStartGame();
    }
    case ADD_QUESTION:
    {
        return this->handleAddQuestion(reqI);
    }
    }
}

/***********************
All handlers works in a similar pattern.

firstly - if there is a need to deserialize the request do it.

the handler functions use a function that is made in order to complete
the request, based on the request contents. code id, buffer contents ect...

if an error throws, catch it and throw myException to return an error message in communicator.

if no error happened serialize the server response and put it in requestResult buffer

then put in requestResult newHandler to the next handler For Example:
if its a Login the next handler will be the menu handler ect...

lastly the functions will return the requestResult.
*************************/

RequestResult MenuRequestHandler::handleLogout() const
{
    RequestResult rr;
    LogoutResponse lr;
    lr.status = 1;
    try 
    {
        this->m_factoryHandler.getLoginManager()->logout(this->m_user.getUserName());
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't logout because: " << e.what() << std::endl;
        lr.status = 0;
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleLogout] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(lr);
    
    if (lr.status == 1)
    {
        rr.newHandler = this->m_factoryHandler.createLoginRequestHandler();
    }
    else
    {
        rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    }
    return rr;
}

RequestResult MenuRequestHandler::handleCreateRoom(const RequestInfo& reqI) const
{
    RequestResult rr;
    CreateRoomResponse crr;
    crr.status = 1;
    CreateRoomRequest tmp = JsonRequestPacketDeserializer::deserializeCreateRoomRequest(reqI.data);
    RoomData rData;
    rData.maxPlayers = tmp.maxPlayers;
    rData.name = tmp.roomName;
    if (tmp.questionCount > this->m_factoryHandler.getStatManager()->getAvailableQuestions())
    {
        throw MyException("Number of question Listed is more then the number of available questions...");
    }
    rData.numOfQuestions = tmp.questionCount;
    rData.timePerQuestions = tmp.answerTimeout;
    rData.id = this->m_factoryHandler.getRoomManager()->generateRoomId();
    rData.questionIdActive = -1;
    rData.status = 0;
    try
    {
        this->m_factoryHandler.getRoomManager()->createRoom(this->m_user, rData);
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't create room because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleCreateRoom] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(crr);

    if (crr.status == 1)
    {
        // would probebly switch it to a game handler in future verseions
        rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    }
    else
    {
        rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    }
    return rr;
}

RequestResult MenuRequestHandler::handleGetRooms(const RequestInfo& reqI) const
{
    RequestResult rr;
    GetRoomsResponse grr;
    grr.status = 1;

    try
    {
        grr.room = this->m_factoryHandler.getRoomManager()->getRooms();
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't get rooms because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleGetRooms] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(grr);

    rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    return rr;
}

RequestResult MenuRequestHandler::handleGetPlayersInRoom(const RequestInfo& reqI) const
{
    RequestResult rr;
    GetPlayerInRoomResponse gpirr;

    GetPlayersInRoonRequest tmp = JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(reqI.data);

    try
    {
        gpirr.players = this->m_factoryHandler.getRoomManager()->getRoom(tmp.roomName).getAllUsersInString();
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't get players in room because: " << e.what() << std::endl;
        throw MyException("CAN'T GET PLAYERS IN ROOM.");
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleGetPlayersInRoom] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(gpirr);

    rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    return rr;
}

RequestResult MenuRequestHandler::handleJoinRoom(const RequestInfo& reqI) const
{
    RequestResult rr;
    JoinRoomResponse jrp;

    JoinRoomRequest tmp = JsonRequestPacketDeserializer::deserializeJoinRoomRequest(reqI.data);
    jrp.status = 1;
    try
    {
        this->m_factoryHandler.getRoomManager()->getRoom(tmp.RoomName).addUser(this->m_user);
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << "couldn't join the room because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleJoinRoom] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(jrp);

    // need in the future to switch to the game handler ....
    rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    return rr;
}

RequestResult MenuRequestHandler::handleGetTop5() const
{
    RequestResult rr;
    GetTop5ScoresResponse gt5;

    gt5.status = 1;
    try
    {
        gt5.scores = this->m_factoryHandler.getStatManager()->getTop5bestScores();
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't get top 5 because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleGetTop5] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(gt5);

    rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    return rr;
}

RequestResult MenuRequestHandler::handleGetPersonalStats() const
{
    RequestResult rr;
    GetPersonalStatsResponse gpsr;
    gpsr.status = 1;
    try
    {
        gpsr.scores = this->m_factoryHandler.getStatManager()->getUserStatistics(this->m_user.getUserName());
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't get player stats because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleGetPersonalStats] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(gpsr);

    rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    return rr;
}

RequestResult MenuRequestHandler::handleUpdateRoom(const RequestInfo& reqI) const
{
    RequestResult rr;
    UpdateRoomResponse urr;
    urr.status = 1;
    UpdateRoomRequest tmp = JsonRequestPacketDeserializer::deserializeUpdateRoomRequest(reqI.data);
    
    if (tmp.questionCount > this->m_factoryHandler.getStatManager()->getAvailableQuestions())
    {
        throw MyException("Number of question Listed is more then the number of available questions...");
    }

    try
    {
        this->m_factoryHandler.getRoomManager()->updateRoom(tmp.roomName,tmp.answerTimeout,tmp.maxPlayers,tmp.questionCount);
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't update room because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleUpdateRoom] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(urr);

    if (urr.status == 1)
    {
        // would probebly switch it to a game handler in future verseions
        rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    }
    else
    {
        rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    }
    return rr;
}

RequestResult MenuRequestHandler::handleGetRoomData(const RequestInfo& reqI) const
{
    RequestResult rr;
    GetRoomDataResponse grdr;
    
    GetRoomDataRequest tmp = JsonRequestPacketDeserializer::deserializeGetRoomDataRequest(reqI.data);
    
    try
    {
        Room& tmpRoom = this->m_factoryHandler.getRoomManager()->getRoom(tmp.RoomName);
        grdr.answerTimeout = tmpRoom.getRoomData().timePerQuestions;
        grdr.maxPlayers = tmpRoom.getRoomData().maxPlayers;
        grdr.questionCount = tmpRoom.getRoomData().numOfQuestions;
        grdr.status = tmpRoom.getRoomState();
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't get room data because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleGetRoomData] , Error is: " << e.what() << std::endl;
        throw;
    }
    
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(grdr);

    try
    {
        if (grdr.status == 1)
        {
            rr.newHandler = this->m_factoryHandler.createGameHandler(this->m_user,
                this->m_factoryHandler.getGameManager()->returnTheRoomUserIsIn(this->m_user));
        }
        else
        {
            rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
        }
    }
    catch (...)
    {
        throw;
    }

    return rr;
}

RequestResult MenuRequestHandler::handleExitRoom(const RequestInfo& reqI) const
{
    RequestResult rr;
    ExitRoomResponse err;
    err.status = 1;
    ExitRoomRequest tmp = JsonRequestPacketDeserializer::deserializeExitRoomRequest(reqI.data);

    try
    {
        this->m_factoryHandler.getRoomManager()->getRoom(tmp.RoomName).removeUser(this->m_user);
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't exit room because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleExitRoom] , Error is: " << e.what() << std::endl;
        throw;
    }
    
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(err);

    rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    return rr;
}

RequestResult MenuRequestHandler::handleStartGame() const
{
    RequestResult rr;
    StartGameResopnse sgr;
    sgr.status = 1;
    try
    {
        rr.newHandler = this->m_factoryHandler.createGameHandler(this->m_user,
            this->m_factoryHandler.getGameManager()->createGame(this->m_factoryHandler.getRoomManager()->getRoom(this->m_user)));
        this->m_factoryHandler.getRoomManager()->getRoom(this->m_user).setRoomState(1);
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't start game because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleStartGame] , Error is: " << e.what() << std::endl;
        throw;
    }

    rr.buffer = JsonRequestPacketSerializer::serializeResponse(sgr);

    return rr;
}

RequestResult MenuRequestHandler::handleAddQuestion(const RequestInfo& reqI) const
{
    RequestResult rr;
    AddQuestionResopnse aqr;
    aqr.status = 1;
    AddQuestionRequest tmp = JsonRequestPacketDeserializer::deserializeAddQuestionRequest(reqI.data);

    try
    {
        this->m_factoryHandler.getStatManager()->addQuestion(tmp.question, tmp.answer, tmp.a1, tmp.a2, tmp.a3);
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't add question because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [MenuRequestHandler -> handleAddQuestion] , Error is: " << e.what() << std::endl;
        throw;
    }

    rr.buffer = JsonRequestPacketSerializer::serializeResponse(aqr);

    rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    return rr;
}
