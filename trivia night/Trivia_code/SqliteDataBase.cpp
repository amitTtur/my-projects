#include "SqliteDataBase.h"

SqliteDataBase::SqliteDataBase()
{
	this->open();
}

SqliteDataBase::~SqliteDataBase()
{
	this->close();
}

void SqliteDataBase::open()
{
    try
    {
        int file_exist = _access(DB_PATH, 0);
        int res = sqlite3_open(DB_PATH, &this->_db);
        if (res != SQLITE_OK)
        {
            this->_db = nullptr;
            std::cout << "Failed to open database... exiting" << std::endl;
            return;
        }
        initdb();  // case a table is missing
        if (file_exist != 0) // database didn't exist before creating database from scratch. 
        {
            initdb(); //creating a data base
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void SqliteDataBase::close()
{
    sqlite3_close(this->_db);
    this->_db = nullptr;
}

int SqliteDataBase::doesUserExist(const std::string& username) const
{
    // running a user search query
    std::vector<UserHolder> users;
    std::string strSQL = "SELECT * FROM USERS WHERE " + std::string(TUSERS_USERNAME) + " = \"" + username + "\";";
    getUserQueryRSP(strSQL, users);
    if (users.size() == 1) // if there is a result then the user exists return true
    {
        return users[0].getUserId();   
    }
    return 0; // if the user doesn't exists return false
}

int SqliteDataBase::doesPasswordMatch(const std::string& username, const std::string& password) const
{
    if (!doesUserExist(username))
    {
        throw MyException("User doesn't exist...");
    }
    // running a user search query
    std::vector<UserHolder> users;
    std::string strSQL = "SELECT * FROM USERS WHERE " + std::string(TUSERS_USERNAME) + " = \"" + username + "\" AND "+
        std::string(TUSERS_PASSWORD) + " = \"" + password + "\";";
    getUserQueryRSP(strSQL, users);
    if (users.size() == 1) // if there is a result then the user exists return true
    {
        return users[0].getUserId();
    }
    return 0; // if the user doesn't exists return false
}

int SqliteDataBase::addNewUser(const std::string& username, const std::string& password, const std::string& email) const
{
    if (doesUserExist(username))
    {
        throw MyException("User already exists with that name...");
    }
    // running a user search query
    std::string strSQL = "INSERT INTO USERS (" + std::string(TUSERS_EMAIL) + "," + std::string(TUSERS_PASSWORD) + "," +
        std::string(TUSERS_USERNAME) + ") VALUES (\""+email+"\",\""+password+"\",\""+username+"\");";
    simple_exec(strSQL);
    // return the new user id
    return doesUserExist(username);
}

std::string SqliteDataBase::getUserName(const int id) const
{
    // running a user search query
    std::vector<UserHolder> users;
    std::string strSQL = "SELECT * FROM USERS WHERE " + std::string(GENERAL_ID) + " = " + std::to_string(id) + ";";
    getUserQueryRSP(strSQL, users);
    if (users.size() == 1) // if there is a result then the user exists return true
    {
        return users[0].getUsername();
    }
    else // if the user doesn't exists throw an error
    {
        throw MyException("User doesn't exist...");
    }
}

void SqliteDataBase::addQuestion(const std::string& q, const std::string& ca, const std::string& ia,
    const std::string& ia2, const std::string& ia3) const
{
    std::string strSQL = "INSERT INTO QUESTIONS (" + std::string(TQ_QUESTION) + "," +
        std::string(TQ_ANSWER) + "," + std::string(TQ_IA) + "," + std::string(TQ_IA2) +
        "," + std::string(TQ_IA3) + ") VALUES ('" + q + "','" + ca + "','" + ia + "','" +
        ia2 + "','" + ia3 + "');";

    simple_exec(strSQL);
}

std::vector<Question> SqliteDataBase::getQuestions(int numToGive) const
{
    numToGive = this->getNumberOfAvailableQuestions() < numToGive ? this->getNumberOfAvailableQuestions() : numToGive;

    // the RANDOM randomizes the questions order andwhich are chosen
    std::string strSQL = "SELECT * FROM QUESTIONS ORDER BY RANDOM() LIMIT " + std::to_string(numToGive) + ";";
    std::vector<QuestionHolder> q;
    getQuestionQueryRSP(strSQL, q);

    std::vector<Question> ret;
    Question tmp;
    tmp.validate();
    for (size_t i = 0; i < q.size(); i++) // set a vector of the questions
    {
        tmp.setAll(q[i].getQuestion(), q[i].getAnswer(), q[i].getA1(),
            q[i].getA2(), q[i].getA3(), q[i].getQuestionId());
        ret.push_back(tmp);
    }
    return ret; // return the vector
}

double SqliteDataBase::getPlayerAverageAnswerTime(const std::string& playerName) const
{
    size_t userId = doesUserExist(playerName);
    if (!userId)
    {
        throw MyException("User doesn't exist...");
    }
    std::string strSQL = "SELECT * FROM STATISTICS WHERE " + std::string(TSTAT_PLAYERID) + " = " + std::to_string(userId) + ";";
    std::vector<StatsHolder> statVec;
    // gives stat vector its values
    getStatQueryRSP(strSQL, statVec);
    if (statVec.size() == 0) // if he didnt have any stats his avg time is 0
    {
        return 0.0;
    }
    double sum = 0.0;
    for (auto it : statVec) // add the time to answer into the sum
    {
        sum += it.getTimeToAnswer();
    }
    sum /= statVec.size(); // to get the average
    return sum;
}

int SqliteDataBase::getNumOfCorrectAnswers(const std::string& playerName) const
{
    size_t userId = doesUserExist(playerName);
    if (!userId)
    {
        throw MyException("User doesn't exist...");
    }

    std::string strSQL = "SELECT * FROM STATISTICS WHERE " + std::string(TSTAT_PLAYERID) + " = " + std::to_string(userId) +
        " AND " + std::string(TSTAT_CORRECTANS) + " = 1;";

    std::vector<StatsHolder> statVec;
    getStatQueryRSP(strSQL, statVec);
    return statVec.size();
}

int SqliteDataBase::getNumOfTotalAnswers(const std::string& playerName) const
{
    size_t userId = doesUserExist(playerName);
    if (!userId)
    {
        throw MyException("User doesn't exist...");
    }

    std::string strSQL = "SELECT * FROM STATISTICS WHERE " + std::string(TSTAT_PLAYERID) + " = " +
        std::to_string(userId) + ";";

    std::vector<StatsHolder> statVec;
    getStatQueryRSP(strSQL, statVec);
    return statVec.size();
}

int SqliteDataBase::getNumOfPlayerGames(const std::string& playerName) const
{
    size_t userId = doesUserExist(playerName);
    if (!userId)
    {
        throw MyException("User doesn't exist...");
    }

    std::string strSQL = "SELECT DISTINCT "+std::string(TSTAT_GAMEID) +
        " FROM STATISTICS WHERE "+std::string(TSTAT_PLAYERID) + " = "+
        std::to_string(userId) + ";";

    std::vector<StatsHolder> statVec;
    getStatQueryRSP(strSQL, statVec);
    return statVec.size();
}

int SqliteDataBase::getHighestScoreOfPlayer(const std::string& playerName) const
{
    int maxScore = 0,currentGameId=-1,tmpScore=0;

    size_t userId = doesUserExist(playerName);
    if (!userId)
    {
        throw MyException("User doesn't exist...");
    }

    std::string strSQL = "SELECT * FROM STATISTICS WHERE " + std::string(TSTAT_PLAYERID) + " = " +
        std::to_string(userId) + ";";

    std::vector<StatsHolder> statVec;
    this->getStatQueryRSP(strSQL, statVec);
    if (!statVec.size())
    {
        return 0;
    }

    currentGameId = statVec[0].getGameId();
    for (auto it : statVec)
    {
        if (it.getGameId() != currentGameId)// if game row had change change the game id
        {
            currentGameId = it.getGameId();
            if (tmpScore > maxScore) // check if the last game score surpassed the current max game holder
            {
                maxScore = tmpScore;
            }
            tmpScore = calculateScore(it.getCorrect(), it.getMaxTime(), it.getTimeToAnswer());
        }
        else
        {
            tmpScore += calculateScore(it.getCorrect(), it.getMaxTime(), it.getTimeToAnswer());
        }
    }
    if (tmpScore > maxScore)
    {
        maxScore = tmpScore;
    }
    return maxScore;
}

int SqliteDataBase::getHighestGameID() const
{
    std::string strSQL = "SELECT MAX(" + std::string(TSTAT_GAMEID) + ") AS "+std::string(TSTAT_GAMEID)+" FROM STATISTICS;";
    std::vector<StatsHolder> stats;
    getStatQueryRSP(strSQL, stats);
    return stats[0].getGameId();
}

std::vector<std::pair<std::string, size_t>> SqliteDataBase::getTop5scores() const
{
    std::vector<std::pair<std::string, size_t>> list;
    std::pair<std::string, size_t> tmpNode;
    std::vector<UserHolder> users;

    std::string strSQL = "SELECT * FROM USERS;";
    getUserQueryRSP(strSQL, users);
    for (auto it : users)
    {
        // giving the tmpNode the current user (itedor) values
        tmpNode.first = it.getUsername();
        tmpNode.second = getHighestScoreOfPlayer(it.getUsername());

        // inserting it into the top 5 list
        // NOTE: the case the value isnt enough to get in the list is
        // handled by the called function
        this->insertAndSortScoreList(list,tmpNode);
    }
    tmpNode.first = "None";
    tmpNode.second = 0;
    while (list.size() != 5) // filling the list if there is not enough scores
    {
        this->insertAndSortScoreList(list, tmpNode);
    }
    return list;
}

void SqliteDataBase::initdb() const
{
    // creating data base
    std::string strSQL;

    /// creating users table
    strSQL = R"(CREATE TABLE IF NOT EXISTS USERS (
ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
USERNAME TEXT NOT NULL UNIQUE,
PASSWORD TEXT NOT NULL,
EMAIL TEXT NOT NULL
		);)";
    simple_exec(strSQL);

    /// creating questions table
    strSQL = R"(CREATE TABLE IF NOT EXISTS QUESTIONS (
ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
QUESTION TEXT NOT NULL,
ANSWER TEXT NOT NULL,
IA TEXT NOT NULL,
IA2 TEXT NOT NULL,
IA3 TEXT NOT NULL
		);)";
    simple_exec(strSQL);

    /// creating statistics table
    strSQL = R"(CREATE TABLE IF NOT EXISTS STATISTICS (
ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,
PLAYER_ID INTEGER NOT NULL,
GAME_ID INTEGER NOT NULL,
QUESTION_NUMBER INTEGER NOT NULL,
CORRECT INTEGER NOT NULL,
TIME_TO_ANSWER INTEGER NOT NULL,
GAME_MAX_TIME INTEGER NOT NULL,
FOREIGN KEY (PLAYER_ID) REFERENCES USERS(ID)
		);)";
    simple_exec(strSQL);

    // done creating the data base!
}

void SqliteDataBase::simple_exec(const std::string& strSQL) const
{
    // vars
    char** errMSG;
    int res;
    // running a query
    errMSG = nullptr;
    res = sqlite3_exec(this->_db, strSQL.c_str(), nullptr, nullptr, errMSG);
    //std::cout << strSQL << std::endl;
    if (res != SQLITE_OK)
    {
        throw MyException("Problem occurred trying to run general sql on database [simple_exec].");
    }
}

size_t SqliteDataBase::getPlayerId(const std::string& username) const
{
    std::string strSQL = "SELECT * FROM USERS WHERE " + std::string(TUSERS_USERNAME) + " = \"" + username + "\";";
    std::vector<UserHolder> u;
    getUserQueryRSP(strSQL, u);
    if (u.size() == 0)
    {
        throw MyException("User Doesn't exist [getPlayerId -> userQueryResp]");
    }
    return u[0].getUserId();
}

size_t SqliteDataBase::getPlayerGameScore(const std::string& username, const int gameId) const
{
    int id = this->getPlayerId(username);
    std::string strSQL = "SELECT * FROM STATISTICS WHERE " + std::string(TSTAT_PLAYERID) + " = " + std::to_string(id) + " AND " +
        std::string(TSTAT_GAMEID) + " = " + std::to_string(gameId) + ";";
    std::vector<StatsHolder> stats;
    getStatQueryRSP(strSQL, stats);
    size_t ret = 0;
    for (auto stat : stats)
    {
        ret += calculateScore(stat.getCorrect(), stat.getMaxTime(), stat.getTimeToAnswer());
    }
    return ret;
}

int SqliteDataBase::user_callback(void* data, int argc, char** argv, char** azColName)
{
    // setting up the data
    std::vector<UserHolder>* userList = static_cast<std::vector<UserHolder>*>(data);

    // setting the tag object
    UserHolder user;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(azColName[i], TUSERS_USERNAME)) {
            user.setUsername(argv[i]);
        }
        else if (!strcmp(azColName[i], GENERAL_ID)) {
            user.setUserId(atoi(argv[i]));
        }
        else if (!strcmp(azColName[i], TUSERS_PASSWORD)) {
            user.setPassword(argv[i]);
        }
        else if (!strcmp(azColName[i], TUSERS_EMAIL)) {
            user.setEmail(argv[i]);
        }
    }

    // adding the tag to the tag list
    userList->push_back(user);
    return 0;
}

void SqliteDataBase::getUserQueryRSP(const std::string& strSQL, std::vector<struct UserHolder>& resp) const
{
    // vars
    char** errMSG;
    int res;
    // getting sql result
    errMSG = nullptr;
    res = sqlite3_exec(this->_db, strSQL.c_str(), user_callback, &resp, errMSG);
    if (res != SQLITE_OK)
    {
        throw MyException("Problem occurred trying to run sql on users [user query resp].");
    }
}

int SqliteDataBase::stat_callback(void* data, int argc, char** argv, char** azColName)
{
    // setting up the data
    std::vector<StatsHolder>* statList = static_cast<std::vector<StatsHolder>*>(data);

    // setting the tag object
    StatsHolder stat;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(azColName[i], GENERAL_ID)) {
            stat.setStatId(atoi(argv[i]));
        }
        else if (!strcmp(azColName[i], TSTAT_CORRECTANS)) {
            stat.setCorrect(atoi(argv[i]));
        }
        else if (!strcmp(azColName[i], TSTAT_GAMEID)) {
            stat.setGameId(atoi(argv[i]));
        }
        else if (!strcmp(azColName[i], TSTAT_PLAYERID)) {
            stat.setPlayerId(atoi(argv[i]));
        }
        else if (!strcmp(azColName[i], TSTAT_QNUM)) {
            stat.setQuestionNumber(atoi(argv[i]));
        }
        else if (!strcmp(azColName[i], TSTAT_TIME_TO_ANSWER)) {
            stat.setTimeToAnswer(atoi(argv[i]));
        }
        else if (!strcmp(azColName[i], TSTAT_MAX_TIME)) {
            stat.setMaxTime(atoi(argv[i]));
        }
    }

    // adding the tag to the tag list
    statList->push_back(stat);
    return 0;
}

void SqliteDataBase::getStatQueryRSP(const std::string& strSQL, std::vector<StatsHolder>& resp) const
{
    // vars
    char** errMSG;
    int res;
    // getting sql result
    errMSG = nullptr;
    res = sqlite3_exec(this->_db, strSQL.c_str(), stat_callback, &resp, errMSG);
    if (res != SQLITE_OK)
    {
        throw MyException("Problem occurred trying to run sql on users [user query resp].");
    }
}

int SqliteDataBase::question_callback(void* data, int argc, char** argv, char** azColName)
{
    // setting up the data
    std::vector<QuestionHolder>* qList = static_cast<std::vector<QuestionHolder>*>(data);

    // setting the tag object
    QuestionHolder stat;
    for (int i = 0; i < argc; i++) {
        if (!strcmp(azColName[i], GENERAL_ID)) {
            stat.setQuestionId(atoi(argv[i]));
        }
        else if (!strcmp(azColName[i], TQ_ANSWER)) {
            stat.setAnswer(argv[i]);
        }
        else if (!strcmp(azColName[i], TQ_QUESTION)) {
            stat.setQuestion(argv[i]);
        }
        else if (!strcmp(azColName[i], TQ_IA)) {
            stat.setA1(argv[i]);
        }
        else if (!strcmp(azColName[i], TQ_IA2)) {
            stat.setA2(argv[i]);
        }
        else if (!strcmp(azColName[i], TQ_IA3)) {
            stat.setA3(argv[i]);
        }
    }

    // adding the tag to the tag list
    qList->push_back(stat);
    return 0;
}

void SqliteDataBase::getQuestionQueryRSP(const std::string& strSQL, std::vector<QuestionHolder>& resp) const
{
    // vars
    char** errMSG;
    int res;
    // getting sql result
    errMSG = nullptr;
    res = sqlite3_exec(this->_db, strSQL.c_str(), question_callback, &resp, errMSG);
    if (res != SQLITE_OK)
    {
        throw MyException("Problem occurred trying to run sql on users [question query resp].");
    }
}

int SqliteDataBase::calculateScore(const int& isCorrect, const int& maxTime, const int& timeItTookToAnswer) const
{
    if (maxTime <= 0 || !isCorrect ) {
        return 0.0; // Or a fixed penalty value
    }

    // normalize the time it took to answer based on how
    // mouch time the was in the game
    double newTime = static_cast<double>(timeItTookToAnswer) / maxTime;

    // this is the penalty, the more time it took 
    // for the player to answer more score will
    // be deducted from the final score
    double score = 1.0 - (newTime * 0.8);

    // this is a bonus, if the player answerd faster then
    // the time it was givven the more points he will 
    // recive. the division of / maxTime is to make the
    // result between 0 and 1.
    score += 0.2 * (maxTime - timeItTookToAnswer) / maxTime;

    // if the score is higher then 1 or lower then 0
    score = std::max(0.0, std::min(score, 1.0));

    // give the score an easy to read number instead
    // of a number between 0 and 1
    return static_cast<int>(score*1000);
}

void SqliteDataBase::insertAndSortScoreList(std::vector<std::pair<std::string, size_t>>& list, std::pair<std::string, size_t> toAdd) const
{
    // first we need to fill the list if its not full
    // so we wont throw away good values
    if (list.size() != 5)
    {
        list.push_back(toAdd);
    }
    else if (list[0].second < toAdd.second) // first check if to add has good enough
    {                                       // value to enter the list 
        list[0] = toAdd;
    }
    else
    {
        return; // value wasnt high enough, didnt get int the list
    }

    /// sorting the list again
    std::sort(list.begin(), list.end(), &SqliteDataBase::compareScores);
    
    // dont need to return the list because we changed it by reference.
}

int SqliteDataBase::getNumberOfAvailableQuestions() const
{
    std::string strSQL = "SELECT * FROM QUESTIONS;";
    std::vector<QuestionHolder> q;
    getQuestionQueryRSP(strSQL, q);
    return q.size();
}

bool SqliteDataBase::compareScores(const std::pair<std::string, size_t>& leftVar, const std::pair<std::string, size_t>& rightVar)
{
    return leftVar.second < rightVar.second;
}