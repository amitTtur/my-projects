using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace trivia_client
{

    public class LoginRequest
    {
        public string username { get; set; }
        public string password { get; set; }

        public LoginRequest(string username, string password)
        {
            this.username = username;
            this.password = password;
        }
    }

    public class SignUpRequest
    {
        public string username { get; set; }
        public string password { get; set; }
        public string email { get; set; }

        public SignUpRequest(string username, string password, string email)
        {
            this.username = username;
            this.password = password;
            this.email = email;
        }
    }

    public class CreateRoomRequest
    {
        public string roomName { get; set; }
        public int maxPlayers { get; set; }
        public int questionCount { get; set; }
        public int answerTimeOut { get; set; }


        public CreateRoomRequest(string roomName,int maxPlayers,int questionCount,int answerTimeOut)
        {
            this.roomName = roomName;
            this.maxPlayers = maxPlayers;
            this.questionCount = questionCount;
            this.answerTimeOut = answerTimeOut;
        }
    }

    public class getPlayersInRoomRequest
    {
        public string roomName { get; set; }

        public getPlayersInRoomRequest(string roomName)
        {
            this.roomName = roomName;
        }
    }

    public class UpdateRoomRequest
    {
        public string roomName { get; set; }
        public int maxPlayers { get; set; }
        public int questionCount { get; set; }
        public int answerTimeOut { get; set; }


        public UpdateRoomRequest(string roomName, int maxPlayers, int questionCount, int answerTimeOut)
        {
            this.roomName = roomName;
            this.maxPlayers = maxPlayers;
            this.questionCount = questionCount;
            this.answerTimeOut = answerTimeOut;
        }
    }

    public class GetRoomDataRequest
    {
        public string roomName { get; set; }

        public GetRoomDataRequest(string roomName)
        {
            this.roomName = roomName;
        }
    }

    public class JoinRoomRequest
    {
        public string roomName { get; set; }

        public JoinRoomRequest(string roomName)
        {
            this.roomName = roomName;
        }
    }

    public class ExitRoomRequest
    {
        public string roomName { get; set; }

        public ExitRoomRequest(string roomName)
        {
            this.roomName = roomName;
        }
    }

    public class SubmitAnswerRequest
    {
        public string answer { get; set; }
        public int time_to_answer { get; set; }

        public SubmitAnswerRequest(string answer,int time_to_answer)
        {
            this.answer = answer;
            this.time_to_answer = time_to_answer;
        }
    }

    public class AddQuestionRequest
    {
        public string answer { get; set; }
        public string a1 { get; set; }
        public string a2 { get; set; }
        public string a3 { get; set; }
        public string question { get; set; }

        public AddQuestionRequest(string answer,string a1,string a2,string a3,string question)
        {
            this.answer = answer;
            this.a1 = a1;
            this.a2 = a2;
            this.a3 = a3;
            this.question = question;
        }
    }
}
