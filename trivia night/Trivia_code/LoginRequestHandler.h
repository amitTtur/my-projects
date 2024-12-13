#pragma once

#include "MyException.h"
#include "IRequestHandler.h"
#include "Response.h"
#include "codesAndDefines.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonRequestPacketSerializer.h"

#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class LoginRequestHandler : public IRequestHandler
{
public:
	// IRequestHandler is abstract so i don't need to call its constructor
	// cons and des
	LoginRequestHandler(RequestHandlerFactory& factory);
	virtual ~LoginRequestHandler() = default;

	// see explanations in the IRequestHandler class
	virtual bool isRequestRelevant(const RequestInfo& reqI) const override;
	virtual RequestResult handleRequest(const RequestInfo& reqI) const override;
private:
	RequestHandlerFactory& m_factoryHandler;
};
