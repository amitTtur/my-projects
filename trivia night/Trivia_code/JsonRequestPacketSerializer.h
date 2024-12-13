#pragma once

#include <vector>
#include <bitset>
#include <iostream>
#include <sstream>

#include "codesAndDefines.h"

using json = nlohmann::json;


#include "JsonRequestPacketDeserializer.h"
#include "Response.h"

static class JsonRequestPacketSerializer
{
public:

    /**************************
    GENERAL EXPLANATION:
    The functions returns a vector of unsigned chars based of the given response type.
    the return value is a serialized response which matches the protocol of the communication.
    ***************************/

    // v1
    static std::vector<unsigned char> serializeResponse(const ErrorResponse& n);
    static std::vector<unsigned char> serializeResponse(const SignUpResponse& n);
    static std::vector<unsigned char> serializeResponse(const LoginResponse& n);

    // v2
    static std::vector<unsigned char> serializeResponse(const LogoutResponse& n);
    static std::vector<unsigned char> serializeResponse(const GetRoomsResponse& n);
    static std::vector<unsigned char> serializeResponse(const GetPlayerInRoomResponse& n);
    static std::vector<unsigned char> serializeResponse(const JoinRoomResponse& n);
    static std::vector<unsigned char> serializeResponse(const CreateRoomResponse& n);
    static std::vector<unsigned char> serializeResponse(const GetTop5ScoresResponse& n);
    static std::vector<unsigned char> serializeResponse(const GetPersonalStatsResponse& n);
    static std::vector<unsigned char> serializeResponse(const UpdateRoomResponse& n);
    static std::vector<unsigned char> serializeResponse(const GetRoomDataResponse& n);
    static std::vector<unsigned char> serializeResponse(const ExitRoomResponse& n);
    // start of v4
    static std::vector<unsigned char> serializeResponse(const StartGameResopnse& n);

    // v4
    static std::vector<unsigned char> serializeResponse(const GetQuestionResponse& n);
    static std::vector<unsigned char> serializeResponse(const SubmitAnswerResponse& n);
    static std::vector<unsigned char> serializeResponse(const GetGameResultsResponse& n);
    static std::vector<unsigned char> serializeResponse(const LeaveGameResponse& n);

    // bonus functions
    static std::vector<unsigned char> serializeResponse(const AddQuestionResopnse& n);

    ///////////////////////////////////////////////

    // extra functions
    // turns a number into its binary representation, fills a '\0' char into the defined data_filler
    static std::string toBinary(int n);

    // turns the response into its protocol version
    static std::vector<unsigned char> toProtocol(const unsigned short id, const unsigned short len);
};