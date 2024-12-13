#include "JsonRequestPacketSerializer.h"

std::string JsonRequestPacketSerializer::toBinary(int n)
{
    std::string ret;

    while (n != 0) {
        ret = (n % 2 == 0 ? "0" : "1") + ret;
        n >>= 1; // its like shl in assembly, i use it to check n next bit
    }

    // Pad with zeros 
    while (ret.length() % 8 != 0) {
        ret = "0" + ret;
    }

    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::toProtocol(const unsigned short id, const unsigned short len)
{
    std::vector<unsigned char> ret;
    ret.push_back((unsigned char)(id));

    // Extract each byte using bitwise AND and shift operations
    ret.push_back(static_cast<unsigned char>((len >> 24) & 0xFF));
    ret.push_back(static_cast<unsigned char>((len >> 16) & 0xFF));
    ret.push_back(static_cast<unsigned char>((len >> 8) & 0xFF));
    auto tmp = (len & 0xFF);
    ret.push_back((unsigned char)(tmp));

    for (int i = 0; i < 5; i++)
    {
        if (ret[i] == '\0') // replace '\0' with the data filler
        {
            ret[i] = char(DATA_FILLER);
        }
    }

    return ret;
}

/*************
*
* all serializers work the same.
* creates a json var, put the response variables into the json, converting the json into a string with no spaces or '\n'
* then adds the protocolized start into the json data (code and length). after it puts the message
* into a unsigned char vector and return the vector. 
*
*************/

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const AddQuestionResopnse& n)
{
    json j;
    j = {
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(ADD_QUESTION, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const ErrorResponse& n)
{
    json j;
    j = {
        {"message" , n.message}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(ERROR_CODE, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }

    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const SignUpResponse& n)
{
    json j;
    j = {
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(SIGNUP, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const LoginResponse& n)
{
    json j;
    j = {
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(LOGIN, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const LogoutResponse& n)
{
    json j;
    j = {
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(LOGOUT, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const GetRoomsResponse& n)
{
    std::string str;
    for (auto it : n.room)
    {
        str += it.name + ",";
    }
    if (str != "")
    {
        str.pop_back();
    }
    json j;
    j = {
        {"status" , n.status},
        {"rooms" , str}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(GET_ROOM, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const GetPlayerInRoomResponse& n)
{
    std::string str;
    for (auto it : n.players)
    {
        str += it + ",";
    }
    if (str != "")
    {
        str.pop_back();
    }
    json j;
    j = {
        {"players" , str}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(PLAYERS_IN_ROOM, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const JoinRoomResponse& n)
{
    json j;
    j = {
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(JOIN_ROOM, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const CreateRoomResponse& n)
{
    json j;
    j = {
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(CREATE_ROOM, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const GetTop5ScoresResponse& n)
{
    std::string str;
    for (auto it : n.scores)
    {
        str += it.first + "^" + std::to_string(it.second) + ",";
    }
    str.pop_back();
    json j;
    j = {
        {"highScores", str},
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(GET_TOP5, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const GetPersonalStatsResponse& n)
{
    std::string str;
    std::stringstream ss;
    for (auto it : n.scores)
    {
        // Set precision to 3 and force fixed-point notation
        ss.str("");
        ss << std::fixed << std::setprecision(3) << it.second;
        str += it.first + "^" + ss.str() + ",";
    }
    str.pop_back();
    json j;
    j = {
        {"userStats", str},
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(GET_PERSONAL_STATS, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const UpdateRoomResponse& n)
{
    json j;
    j = {
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(UPDATE_ROOM_SETTINGS, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const GetRoomDataResponse& n)
{
    json j;
    j = {
        {"answerTimeout" , n.answerTimeout},
        {"maxPlayers" , n.maxPlayers},
        {"questionCount" , n.questionCount},
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(GET_ROOM_DATA, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const ExitRoomResponse& n)
{
    json j;
    j = {
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(EXIT_ROOM, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const StartGameResopnse& n)
{
    json j;
    j = {
        {"status" , n.status}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(START_GAME, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const GetQuestionResponse& n)
{
    json j;
    std::string answers = "";
    for (auto it : n.answers)
    {
        answers += it + "@#@#@";
    }
    if (!answers.empty())
    {
        answers.pop_back();
        answers.pop_back();
        answers.pop_back();
        answers.pop_back();
        answers.pop_back();
    }
    j = {
        {"status" , n.status},
        {"question" , n.question},
        {"answers" , answers}

    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(GET_QUESTION, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const SubmitAnswerResponse& n)
{
    json j = {
        {"status" , n.status},
        {"correctAns" , n.correctAns}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(SUBMIT_ANSWER, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const GetGameResultsResponse& n)
{
    std::string rslt = "";
    for (auto it : n.results)
    {
        rslt += it.username + "-" + std::to_string(it.score) + "@#@#@";
    }
    if (rslt.size() != 0)
    {
        rslt.pop_back();
        rslt.pop_back();
        rslt.pop_back();
        rslt.pop_back();
        rslt.pop_back();
    }
    json j = {
        {"status" , n.status},
        {"results" , rslt}
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(GET_GAME_RESULTS, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}

std::vector<unsigned char> JsonRequestPacketSerializer::serializeResponse(const LeaveGameResponse& n)
{
    json j = {
        {"status" , n.status},
    };
    // so there will be no spaces
    std::string tmp = j.dump(-1);
    // to remove the '\n'
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\n'), tmp.end());

    std::vector<unsigned char> ret = toProtocol(LEAVE_GAME, tmp.length());
    for (auto c : tmp)
    {
        ret.push_back(c);
    }
    return ret;
}