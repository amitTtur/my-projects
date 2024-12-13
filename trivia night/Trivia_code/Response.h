#pragma once
#include <string>
#include "Room.h"

/***********
General class for all the possible server response types.
************/

struct ErrorResponse
{
	std::string message;
};

struct LoginResponse
{
	unsigned int status;
};

struct SignUpResponse
{
	unsigned int status;
};

struct LogoutResponse
{
	unsigned int status;
};

struct GetRoomsResponse
{
	unsigned int status;
	std::vector<RoomData> room;
};

struct GetPlayerInRoomResponse
{
	std::vector<std::string> players;
};

struct GetTop5ScoresResponse
{
	unsigned int status;
	// player and their score
	std::vector<std::pair<std::string,size_t>> scores;
};

struct GetPersonalStatsResponse
{
	unsigned int status;
	// stat and its score
	std::vector<std::pair<std::string, double>> scores;
};

struct JoinRoomResponse
{
	unsigned int status;
};

struct CreateRoomResponse
{
	unsigned int status;
};

struct UpdateRoomResponse
{
	unsigned int status;
};

struct GetRoomDataResponse
{
	unsigned int maxPlayers;
	unsigned int questionCount;
	unsigned int answerTimeout;
	unsigned int status;
};

struct ExitRoomResponse
{
	unsigned int status;
};

struct LeaveGameResponse
{
	unsigned int status;
};

struct GetQuestionResponse
{
	unsigned int status;
	std::string question;
	// need to randomize the answers order
	std::vector<std::string> answers;
};

struct SubmitAnswerResponse
{
	unsigned int status;
	std::string correctAns;
};

struct PlayerResults
{
	int score;
	std::string username;
};

struct GetGameResultsResponse
{
	int status;
	std::vector<PlayerResults> results;
};

struct StartGameResopnse
{
	int status;
};

struct AddQuestionResopnse
{
	int status;
};