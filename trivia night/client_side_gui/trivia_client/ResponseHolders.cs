using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace trivia_client
{
    public class loginRespHolder
    {
        public int status { get; set; }
    }
    public class SignUpRespHolder
    {
        public int status { get; set; }
    }

    public class ErrorRespHolder
    {
        public string message { get; set; }
    }

    public class LogoutRespHolder
    {
        public int status { get; set; }
    }

    public class createRoomRespHolder
    {
        public int status { get; set; }
    }
    public class getPlayersInRoomRespHolder
    {
        public string players { get; set; }
    }
    public class UpdateRoomRespHolder
    {
        public int status { get; set; }
    }
    public class GetRoomDataRespHolder
    {
        public int maxPlayers { get; set; }
        public int questionCount { get; set; }
        public int answerTimeout { get; set; }
        public int status { get; set; }

        public GetRoomDataRespHolder(int maxPlayers, int questionCount, int answerTimeout, int status)
        {
            this.maxPlayers = maxPlayers;
            this.questionCount = questionCount;
            this.answerTimeout = answerTimeout;
            this.status = status;
        }
    }

    public class GetRoomRespHolder
    {
        public string rooms { get; set; }

        public GetRoomRespHolder(string rooms)
        {
            this.rooms = rooms;
        }
    }

    public class JoinRoomRespHolder
    {
        public int status { get; set; }
    }

    public class ExitRoomRespHolder
    {
        public int status { get; set; }
    }
    public class GetPersonalStatsRespHolder
    {
        public int status { get; set; }
        public string userStats { get; set; }
    }

    public class GetTop5RespHolder
    {
        public int status { get; set; }
        public string highScores { get; set; }
    }

    public class StartGameRespHolder
    {
        public int status { get; set; }
    }

    public class LeaveGameRespHolder
    {
        public int status { get; set; }
    }

    public class GetQuestionRespHolder
    {
        public int status { get; set; }
        public string question { get; set; }
        public string answers { get; set; }
    }

    public class SubmitAnswerRespHolder
    {
        public int status { get; set; }
        public string correctAns { get; set; }
    }

    public class GameResultRespHolder
    {
        public int status { get; set; }
        public string results { get; set; }
    }

    public class AddQuestionRespHolder
    {
        public int status { get; set; }
    }
}
