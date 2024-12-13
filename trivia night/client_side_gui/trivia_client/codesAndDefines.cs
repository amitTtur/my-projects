using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace trivia_client
{
    public static class globalVars
    {
        public static bool exitRequested { get; set; } = false;
        public static bool logoutRequested { get; set; } = false;
        public static bool isAdmin { get; set; } = false;
        public static string activeUserName { get; set; } = "";
        public static bool exitedRoom { get; set; } = false;

    }
    public enum codeTypes
    {
        EXIT = 0,

        LOGIN = 1,
        SIGNUP = 2,
        LOGOUT = 3,

        DATA_FILLER = 5, // for comms fill

        GET_ROOM = 8,
        PLAYERS_IN_ROOM = 11,
        JOIN_ROOM = 12,
        CREATE_ROOM = 13,
        GET_TOP5 = 14,
        GET_PERSONAL_STATS = 15,
        UPDATE_ROOM_SETTINGS = 16,
        GET_ROOM_DATA = 17,
        EXIT_ROOM = 18,
        START_GAME = 19,
        ADD_QUESTION = 50,

        GET_QUESTION = 20,
        SUBMIT_ANSWER = 21,
        GET_GAME_RESULTS = 22,
        LEAVE_GAME = 23,

        ERROR_CODE = 99
    };
    
}
