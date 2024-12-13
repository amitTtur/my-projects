#include "JsonRequestPacketDeserializer.h"

/*************
* 
* all deserializers work the same the get the data of the message
* turn it into json format then puts the field of the json into
* the request type then returns it.
* 
*************/

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(const std::vector<unsigned char>& n)
{
    LoginRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);
    json j = json::parse(tmp);

    l.password = j["password"];
    l.username = j["username"];
    return l;
}

SignUpRequest JsonRequestPacketDeserializer::deserializeSignUpRequest(const std::vector<unsigned char>& n)
{
    SignUpRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);

    json j = json::parse(tmp);

    l.password = j["password"];
    l.username = j["username"];
    l.email = j["email"];
    return l;
}

GetPlayersInRoonRequest JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(const std::vector<unsigned char>& n)
{
    GetPlayersInRoonRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);

    json j = json::parse(tmp);

    l.roomName = j["roomName"];
    
    return l;
}

JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(const std::vector<unsigned char>& n)
{
    JoinRoomRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);

    json j = json::parse(tmp);

    l.RoomName = j["roomName"];

    return l;
}

CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(const std::vector<unsigned char>& n)
{
    CreateRoomRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);

    json j = json::parse(tmp);

    l.answerTimeout = j["answerTimeOut"];
    l.maxPlayers = j["maxPlayers"];
    l.questionCount = j["questionCount"];
    l.roomName = j["roomName"];

    return l;
}

UpdateRoomRequest JsonRequestPacketDeserializer::deserializeUpdateRoomRequest(const std::vector<unsigned char>& n)
{
    UpdateRoomRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);

    json j = json::parse(tmp);

    l.roomName = j["roomName"];
    l.answerTimeout = j["answerTimeOut"];
    l.maxPlayers = j["maxPlayers"];
    l.questionCount = j["questionCount"];

    return l;
}

GetRoomDataRequest JsonRequestPacketDeserializer::deserializeGetRoomDataRequest(const std::vector<unsigned char>& n)
{
    GetRoomDataRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);

    json j = json::parse(tmp);

    l.RoomName = j["roomName"];

    return l;
}

ExitRoomRequest JsonRequestPacketDeserializer::deserializeExitRoomRequest(const std::vector<unsigned char>& n)
{
    ExitRoomRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);

    json j = json::parse(tmp);

    l.RoomName = j["roomName"];

    return l;
}

SubmitAnswerRequest JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest(const std::vector<unsigned char>& n)
{
    SubmitAnswerRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);

    json j = json::parse(tmp);

    l.time_to_answer = j["time_to_answer"];
    l.answer = j["answer"];

    return l;
}

AddQuestionRequest JsonRequestPacketDeserializer::deserializeAddQuestionRequest(const std::vector<unsigned char>& n)
{
    AddQuestionRequest l;

    std::string tmp = JsonRequestPacketDeserializer::getDataOfMSG(n);

    json j = json::parse(tmp);

    l.answer = j["answer"];
    l.question = j["question"];
    l.a1 = j["a1"];
    l.a2 = j["a2"];
    l.a3 = j["a3"];

    return l;
}


size_t JsonRequestPacketDeserializer::getMSGCode(const std::vector<unsigned char>& v)
{
    return int(v[0]);
}

int JsonRequestPacketDeserializer::getLenOfMsg(const std::vector<unsigned char>& v)
{
    if (v.size() == 0) // if buffer is empty the length is 0
    {
        return 0;
    }

    std::string t;
    for (size_t i = 1; i < 5; i++)
    {
        if (v[i] == '\0') // if its a zero rep put the binary 0
        {
            t += "00000000";
        }
        else
        {
            t += JsonRequestPacketSerializer::toBinary(int(v[i])); // else put the binary rep of the char
        }
    }
    return stoi(t, 0, 2); // turn t to the number (base 2 to base 10)
}

std::string JsonRequestPacketDeserializer::getDataOfMSG(const std::vector<unsigned char>& v)
{
    int len = JsonRequestPacketDeserializer::getLenOfMsg(v);
    std::string ret;
    for (int i = 0; i < len; i++)
    {
        ret += v[i+5];
    }
    return ret;
}
