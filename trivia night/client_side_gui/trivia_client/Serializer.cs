using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Nodes;
using System.Threading.Tasks;


namespace trivia_client
{
    internal static class Serializer
    {
        public static string serializeLogin(string username, string password)
        {
            LoginRequest tmp = new LoginRequest(username, password); 
            string msgToSend = JsonConvert.SerializeObject(tmp);
            msgToSend = toProtocol(((int)codeTypes.LOGIN),msgToSend.Length) + msgToSend;
            return msgToSend;
        }

        public static string serializeSignUp(string username, string password,string email)
        {
            SignUpRequest tmp = new SignUpRequest(username, password,email);
            string msgToSend = JsonConvert.SerializeObject(tmp);
            string protocolMsg = toProtocol(((int)codeTypes.SIGNUP), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }

        public static string serializeCreateRoom(string roomName, int maxPlayers, int questionCount, int answerTimeOut)
        {
            CreateRoomRequest tmp = new CreateRoomRequest(roomName,maxPlayers,questionCount,answerTimeOut);
            string msgToSend = JsonConvert.SerializeObject(tmp);
            string protocolMsg = toProtocol(((int)codeTypes.CREATE_ROOM), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }

        public static string serializeGetPlayersInRoom(string roomName)
        {
            getPlayersInRoomRequest tmp = new getPlayersInRoomRequest(roomName);
            string msgToSend = JsonConvert.SerializeObject(tmp);
            string protocolMsg = toProtocol(((int)codeTypes.PLAYERS_IN_ROOM), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }
        public static string serializeUpdateRoom(string roomName, int maxPlayers,int questionCount, int answerTimeOut)
        {
            UpdateRoomRequest tmp = new UpdateRoomRequest(roomName,maxPlayers,questionCount,answerTimeOut);
            string msgToSend = JsonConvert.SerializeObject(tmp);
            string protocolMsg = toProtocol(((int)codeTypes.UPDATE_ROOM_SETTINGS), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }
        public static string serializeGetRoomData(string roomName)
        {
            GetRoomDataRequest tmp = new GetRoomDataRequest(roomName);
            string msgToSend = JsonConvert.SerializeObject(tmp);
            string protocolMsg = toProtocol(((int)codeTypes.GET_ROOM_DATA), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }
        
        public static string serializeJoinRoom(string roomName)
        {
            JoinRoomRequest tmp = new JoinRoomRequest(roomName);
            string msgToSend = JsonConvert.SerializeObject(tmp);
            string protocolMsg = toProtocol(((int)codeTypes.JOIN_ROOM), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }

        public static string serializeExitRoom(string roomName)
        {
            ExitRoomRequest tmp = new ExitRoomRequest(roomName);
            string msgToSend = JsonConvert.SerializeObject(tmp);
            string protocolMsg = toProtocol(((int)codeTypes.EXIT_ROOM), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }

        public static string serializeStartGame()
        {
            string msgToSend = "";
            string protocolMsg = toProtocol(((int)codeTypes.START_GAME), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }

        public static string serializeGetQuestion()
        {
            string msgToSend = "";
            string protocolMsg = toProtocol(((int)codeTypes.GET_QUESTION), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }

        public static string serializeSubmitAnswer(string answer,int time_to_answer)
        {
            SubmitAnswerRequest tmp = new SubmitAnswerRequest(answer,time_to_answer);
            string msgToSend = JsonConvert.SerializeObject(tmp);
            string protocolMsg = toProtocol(((int)codeTypes.SUBMIT_ANSWER), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }

        public static string serializeLeaveGame()
        {
            string msgToSend = "";
            string protocolMsg = toProtocol(((int)codeTypes.LEAVE_GAME), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }

        public static string serializeGameResults()
        {
            string msgToSend = "";
            string protocolMsg = toProtocol(((int)codeTypes.GET_GAME_RESULTS), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }

        public static string serializeAddQuestion(string answer,string a1, string a2, string a3, string question)
        {
            AddQuestionRequest tmp = new AddQuestionRequest(answer,a1,a2,a3,question);
            string msgToSend = JsonConvert.SerializeObject(tmp);
            string protocolMsg = toProtocol(((int)codeTypes.ADD_QUESTION), msgToSend.Length);

            msgToSend = protocolMsg + msgToSend;

            return msgToSend;
        }


        public static string toProtocol(int id, int len)
        {
            string result = "";

            // Add the id as a byte
            result += (char)id;

            // Extract each byte of the length using bit shifting and casting
            result += (char)((len >> 24) & 0xFF);
            result += (char)((len >> 16) & 0xFF);
            result += (char)((len >> 8) & 0xFF);
            result += (char)(len & 0xFF);

            char[] tmp = result.ToCharArray();
            //Replace '\0' characters with -1
            for (int i = 0; i < 5; i++)
            {
                if (tmp[i] == '\0')
                {
                    tmp[i] = (char)(codeTypes.DATA_FILLER);
                }
            }
            string str = new string(tmp);
            return str;
        }



    }
}
