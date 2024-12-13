#pragma once
#include <vector>
#include <bitset>

#include "Request.h"
#include "codesAndDefines.h" 
#include "JsonRequestPacketSerializer.h"

// json redefining as a new name type.
using json = nlohmann::json;

class JsonRequestPacketDeserializer
{
public:

    /**************************
    GENERAL EXPLANATION:
    The functions receives a vector of unsigned chars then calculates the return value based of
    the return type.
    the return value is a filled returned object of the given return type.
    ***************************/

    // v1
	static LoginRequest deserializeLoginRequest(const std::vector<unsigned char>& n);
    static SignUpRequest deserializeSignUpRequest(const std::vector<unsigned char>& n);

    // v2
    static GetPlayersInRoonRequest deserializeGetPlayersInRoomRequest(const std::vector<unsigned char>& n);
    static JoinRoomRequest deserializeJoinRoomRequest(const std::vector<unsigned char>& n);
    static CreateRoomRequest deserializeCreateRoomRequest(const std::vector<unsigned char>& n);
    static UpdateRoomRequest deserializeUpdateRoomRequest(const std::vector<unsigned char>& n);
    static GetRoomDataRequest deserializeGetRoomDataRequest(const std::vector<unsigned char>& n);
    static ExitRoomRequest deserializeExitRoomRequest(const std::vector<unsigned char>& n);

    // v4
    static SubmitAnswerRequest deserializeSubmitAnswerRequest(const std::vector<unsigned char>& n);

    // bonus functions
    static AddQuestionRequest deserializeAddQuestionRequest(const std::vector<unsigned char>& n);

    //////////////////////////////////////////////

    // general functions
    // returns the message code from the message
    static size_t getMSGCode(const std::vector<unsigned char>& v);

    // returns the message length from the message
    static int getLenOfMsg(const std::vector<unsigned char>& v);
    static std::string getDataOfMSG(const std::vector<unsigned char>& v);

   
};