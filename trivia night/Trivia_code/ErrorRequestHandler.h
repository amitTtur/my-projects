#pragma once
#include "IRequestHandler.h"
#include "codesAndDefines.h"
#include "MyException.h"
#include "Response.h"

#include "RequestHandlerFactory.h"

class RequestHandlerFactory;

class ErrorRequestHandler : public IRequestHandler
{
public:
	// cons and des
	// IRequestHandler is abstract so i don't need to call its constructor
	ErrorRequestHandler(const std::string& errorMsg, const int& code);
	virtual ~ErrorRequestHandler() = default;

	// irrelevant for this class, I only need to override it
	virtual bool isRequestRelevant(const RequestInfo& reqI) const { return true; };

	virtual RequestResult handleRequest(const RequestInfo& reqI) const override;

private:
	// vars
	std::string _errorMsg;
	// 1-for calc error, 0- for general error
	int _code;
};