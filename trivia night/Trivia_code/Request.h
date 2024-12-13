#pragma once
#include <string>

/***********
General class for all the possible client request types.
************/

struct LoginRequest
{
	std::string username;
	std::string password;
};

struct SignUpRequest
{
	std::string username;
	std::string password;
	std::string email;
};

struct GetPlayersInRoonRequest
{
	std::string roomName;
};

struct JoinRoomRequest
{
	std::string RoomName;
};

struct CreateRoomRequest
{
	std::string roomName;
	unsigned int maxPlayers;
	unsigned int questionCount;
	unsigned int answerTimeout;
};

struct UpdateRoomRequest
{
	std::string roomName;
	unsigned int maxPlayers;
	unsigned int questionCount;
	unsigned int answerTimeout;
};

struct GetRoomDataRequest
{
	std::string RoomName;
};

struct ExitRoomRequest
{
	std::string RoomName;
};

struct SubmitAnswerRequest
{
	std::string answer;
	int time_to_answer;
};

struct AddQuestionRequest
{
	std::string answer;
	std::string a1;
	std::string a2;
	std::string a3;
	std::string question;
};