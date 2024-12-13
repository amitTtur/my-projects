#include "LoginRequestHandler.h"

LoginRequestHandler::LoginRequestHandler(RequestHandlerFactory& factory) : m_factoryHandler(factory) 
{
}

bool LoginRequestHandler::isRequestRelevant(const RequestInfo& reqI) const
{
    if (reqI.codeId == SIGNUP || reqI.codeId == LOGIN)
    {
        return true;
    }
    return false;
}

RequestResult LoginRequestHandler::handleRequest(const RequestInfo& reqI) const
{
    if (!isRequestRelevant(reqI)) // if request isn't relevent throw an exception
    {
        throw MyException("Irrelevant request [STAGE NOT REACHED OR STAGE PASSED].");
    }
    RequestResult rr;
    if (reqI.codeId == LOGIN)
    {
        auto tmp = JsonRequestPacketDeserializer::deserializeLoginRequest(reqI.data);
        
        // need to be changed when data base is complete
        LoginResponse lr;
        // checks on db
        std::cout << "Data received: " << std::endl << "username: " << tmp.username <<
            std::endl << "password: " << tmp.password << std::endl;
        // determining the status
        lr.status = 1;
        try
        {
            this->m_factoryHandler.getLoginManager()->login(tmp.username, tmp.password); // try to log the user
        }
        catch (MyException& c) // cases login failed
        {
            std::cout << "User " << tmp.username << " ,failed to register because: " << c.what();
            throw MyException(std::string(c.what()));
        }
        catch (std::exception& e)
        {
            std::cout << "GENERAL ERROR!!! " << e.what();
            throw MyException("Server side error...");
        }

        // serialize the response
        rr.buffer = JsonRequestPacketSerializer::serializeResponse(lr);
       

        if (lr.status) // if login was a success the new handler should be a menu handler else redo the login
        {
            LoggedUser tmpUser;
            tmpUser.setUserName(tmp.username);
            rr.newHandler = this->m_factoryHandler.createMenuRequestHandler(tmpUser);
            if (!rr.newHandler)
            {
                std::cout << "ERROR ERROR!!!!!!!!!!!!!!!!!!!!" << std::endl;
            }
        }
        else
        {
            rr.newHandler = this->m_factoryHandler.createLoginRequestHandler();
        }
        return rr;
    }
    else
    {
        auto tmp = JsonRequestPacketDeserializer::deserializeSignUpRequest(reqI.data);
        SignUpResponse sr;

        std::cout << "Data received: " << std::endl << "username: " << tmp.username <<
            std::endl << "password: " << tmp.password << std::endl << "email: " <<
            tmp.email << std::endl;

        // determining the status
        sr.status = 1;
        try
        {
            this->m_factoryHandler.getLoginManager()->signUp(tmp.username, tmp.password, tmp.email); // signing up
        }
        catch (MyException& c) // cases signup failed
        {
            std::cout << "User " << tmp.username << " ,failed to register because: " << c.what();
            throw MyException(std::string(c.what()));
        }
        catch (std::exception& e)
        {
            std::cout << "GENERAL ERROR!!! " << e.what();
            throw MyException("Server side error...");
        }


        rr.buffer = JsonRequestPacketSerializer::serializeResponse(sr);

        // changing the next handler to login, after sign up login is the next step
        rr.newHandler = this->m_factoryHandler.createLoginRequestHandler();
        return rr;
    }
}
