using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Nodes;
using System.Threading.Tasks;

namespace trivia_client
{
    internal static class deserializer
    {
        public static int getMSGcode(string messege)
        {
            return ((short)messege[0]);
        }

        public static int getMSGlength(string messege)
        {
            string t = "";
            for (int i = 1; i < 5; i++)
            {
                if (messege[i] == ((char)codeTypes.DATA_FILLER))
                {
                    t += "00000000";
                }
                else
                {
                    t += toBinary(((short)messege[i]));
                }
            }
            // converting the binary string into a int
            return Convert.ToInt32(t, 2);
        }

        public static string toBinary(int n)
        {
            string ret = "";

            while (n != 0)
            {
                ret = (n % 2 == 0 ? "0" : "1") + ret;
                n >>= 1; // its like shl in assembly, i use it to check n next bit
            }

            // Pad with zeros 
            while (ret.Length % 8 != 0)
            {
                ret = "0" + ret;
            }

            return ret;
        }

        public static string getMSGdata(string messege)
        {
            int len = getMSGlength(messege);
            string ret = "";
            for (int i = 0; i < len; i++)
            {
                ret += messege[i + 5];
            }
            return ret;
        }

        public static loginRespHolder deserializeLoginResp(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<loginRespHolder>(tmp);
        }

        public static SignUpRespHolder deserializeSignUpResp(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<SignUpRespHolder>(tmp);
        }

        public static ErrorRespHolder deserializeErrorResp(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<ErrorRespHolder>(tmp);
        }

        public static LogoutRespHolder deserializeLogoutResp(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<LogoutRespHolder>(tmp);
        }

        public static createRoomRespHolder deserializeCreateRoomResp(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<createRoomRespHolder>(tmp);
        }

        public static getPlayersInRoomRespHolder deserializeGetPlayersInRoomResp(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<getPlayersInRoomRespHolder>(tmp);
        }

        public static UpdateRoomRespHolder deserializeUpdateRoomResp(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<UpdateRoomRespHolder>(tmp);
        }

        public static GetRoomDataRespHolder deserializeGetRoomDataResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<GetRoomDataRespHolder>(tmp);
        }

        public static GetRoomRespHolder deserializeGetRoomsResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<GetRoomRespHolder>(tmp);
        }

        public static JoinRoomRespHolder deserializeJoinRoomResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<JoinRoomRespHolder>(tmp);
        }

        public static ExitRoomRespHolder deserializeExitRoomResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<ExitRoomRespHolder>(tmp);
        }

        public static GetPersonalStatsRespHolder deserializeGetPersonalStatsResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<GetPersonalStatsRespHolder>(tmp);
        }

        public static GetTop5RespHolder deserializeGetTop5Response(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<GetTop5RespHolder>(tmp);
        }

        public static LeaveGameRespHolder deserializeLeaveGameResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<LeaveGameRespHolder>(tmp);
        }

        public static GetQuestionRespHolder deserializeGetQuestionResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<GetQuestionRespHolder>(tmp);
        }

        public static SubmitAnswerRespHolder deserializeSubmitAnswerResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<SubmitAnswerRespHolder>(tmp);
        }

        public static StartGameRespHolder deserializeStartGameResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<StartGameRespHolder>(tmp);
        }
        public static GameResultRespHolder deserializeGetGameResultsResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<GameResultRespHolder>(tmp);
        }

        public static AddQuestionRespHolder deserializeAddQuestionResponse(string messege)
        {
            string tmp = getMSGdata(messege);
            return JsonConvert.DeserializeObject<AddQuestionRespHolder>(tmp);
        }
    }
}
