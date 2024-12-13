#pragma once
#include <ctime>
#include <vector>

class IRequestHandler;

struct RequestInfo
{
	size_t codeId;
	std::time_t receivalTime;
	std::vector<unsigned char> data;
};

struct RequestResult
{
	std::vector<unsigned char> buffer;
	IRequestHandler* newHandler;
};

class IRequestHandler
{
public:
	// overall, deriving classes function explanation
	// returns true if the code id matches the request handler ,else false
	virtual bool isRequestRelevant(const RequestInfo& reqI) const = 0;

	// handles the given request
	virtual RequestResult handleRequest(const RequestInfo& reqI) const = 0;
private:
};



