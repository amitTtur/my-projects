#include "ExitRequestHandler.h"

ExitRequestHandler::ExitRequestHandler(RequestHandlerFactory& factory) : m_factoryHandler(factory)
{
}

bool ExitRequestHandler::isRequestRelevant(const RequestInfo& reqI) const
{
    if (reqI.codeId == EXIT)
    {
        return true;
    }
    return false;
}

RequestResult ExitRequestHandler::handleRequest(const RequestInfo& reqI) const
{
    RequestResult l;
    l.newHandler = nullptr; // no new handler after an exit request
    l.buffer;
    return l;
}