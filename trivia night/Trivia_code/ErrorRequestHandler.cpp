#include "ErrorRequestHandler.h"

ErrorRequestHandler::ErrorRequestHandler(const std::string& errorMsg, const int& code)
{
    this->_errorMsg = errorMsg;
    this->_code = code;
}

RequestResult ErrorRequestHandler::handleRequest(const RequestInfo& reqI) const
{
    RequestResult rr;
    ErrorResponse er;
    if (this->_code == 1) // if its a specific error
    {
        er.message = this->_errorMsg;
    }
    else // if it is a general error
    {
        er.message = "SERVER_ERROR[000]";
    }
   
    rr.buffer = JsonRequestPacketSerializer::serializeResponse(er);
    rr.newHandler = nullptr;
    return rr;
}
