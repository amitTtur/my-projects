#pragma once

#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class IRequestHandler;
class RequestHandlerFactory;

class ExitRequestHandler : public IRequestHandler
{
public:
	// cons and des
	// IRequestHandler is abstract so i don't need to call its constructor
	ExitRequestHandler(RequestHandlerFactory& factory);
	virtual ~ExitRequestHandler() = default;

	// checks if message code is relevant for this handler
	virtual bool isRequestRelevant(const RequestInfo& reqI) const override;
	// handler the user message
	virtual RequestResult handleRequest(const RequestInfo& reqI) const override;
private:
	// var
	RequestHandlerFactory& m_factoryHandler;
};