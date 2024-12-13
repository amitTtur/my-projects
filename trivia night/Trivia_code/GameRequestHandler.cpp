#include "GameRequestHandler.h"

GameRequestHandler::GameRequestHandler(RequestHandlerFactory& factory, LoggedUser user, Game& game) : m_factoryHandler(factory) ,
	m_game(game)
{
	this->m_user.setUserName(user.getUserName());
}

bool GameRequestHandler::isRequestRelevant(const RequestInfo& reqI) const
{
	if (reqI.codeId == GET_QUESTION || reqI.codeId == SUBMIT_ANSWER ||
		reqI.codeId == GET_GAME_RESULTS || reqI.codeId == LEAVE_GAME)
	{
		return true;
	}
	else
	{
		return false;
	}
}

RequestResult GameRequestHandler::handleRequest(const RequestInfo& reqI) const
{
    if (!this->isRequestRelevant(reqI))
    {
        throw MyException("STAGE NOT REACHED YET... [GameHandler -> handleRequest]");
    }
	switch (reqI.codeId)
	{
	case GET_QUESTION:
	{
        return handleGetQuestion();
	}
    case SUBMIT_ANSWER:
    {
        return handleSubmitAnswer(reqI);
    }
    case GET_GAME_RESULTS:
    {
        return handleGetGameResults();
    }
    case LEAVE_GAME:
    {
        return handleLeaveGame();
    }
	}
    return RequestResult();
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

lastly the functions will return a requestResult.
*************************/



RequestResult GameRequestHandler::handleGetQuestion() const
{
    RequestResult rr;
    GetQuestionResponse gqr;
    gqr.status = 1;
    // no deserializer for this request
    
    try
    {
        Question tmp = this->m_game.getQuestionForUser(this->m_user);
        if (tmp.getId() == -1)
        {
            if (this->m_game.allPlayersFinished())
            {
                gqr.status = 0;
            }
            else
            {
                gqr.status = 2;
            }
        }
        else
        {
            gqr.question = tmp.getQuestion();

            // putting the answers
            auto answers = tmp.getPossibleAnswers();
            answers.push_back(tmp.getCorrectAnswer());
            std::default_random_engine rng(std::chrono::system_clock::now().time_since_epoch().count());
            std::shuffle(answers.begin(), answers.end(), rng);
            gqr.answers = answers;
        }
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't get question because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [GameHandler -> handleGetQuestion] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(gqr);

    rr.newHandler = this->m_factoryHandler.createGameHandler(this->m_user,this->m_game);
    return rr;
}

RequestResult GameRequestHandler::handleSubmitAnswer(const RequestInfo& reqI) const
{
    RequestResult rr;
    SubmitAnswerResponse sar;
    sar.status = 1;
    
    SubmitAnswerRequest sarReq = JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest(reqI.data);

    try
    {
        sar.correctAns = this->m_game.submitAnswer(this->m_user, sarReq.answer, sarReq.time_to_answer);
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't submit answer because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [GameHandler -> handleSubmitAnswer] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(sar);

    rr.newHandler = this->m_factoryHandler.createGameHandler(this->m_user, this->m_game);
    return rr;
}

RequestResult GameRequestHandler::handleGetGameResults() const
{
    RequestResult rr;
    GetGameResultsResponse grss;
    grss.status = 1;

    // no deserializer for this request

    try
    {
        grss.results = this->m_game.getPlayersScores();
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't get game results because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [GameHandler -> handleGetGameResults] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(grss);

    rr.newHandler = this->m_factoryHandler.createGameHandler(this->m_user, this->m_game);
    return rr;
}

RequestResult GameRequestHandler::handleLeaveGame() const
{
    RequestResult rr;
    LeaveGameResponse lgr;
    lgr.status = 1;

    // no deserializer for this request

    try
    {
        this->m_game.removePlayer(this->m_user);
    }
    catch (MyException& e)
    {
        std::cout << "User: " << this->m_user.getUserName() << " couldn't leave game because: " << e.what() << std::endl;
        throw MyException(e.what());
    }
    catch (std::exception& e)
    {
        std::cout << "GENERAL ERROR!!! at [GameHandler -> handleLeaveGame] , Error is: " << e.what() << std::endl;
        throw;
    }
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(lgr);

    rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(this->m_user);
    return rr;
}
