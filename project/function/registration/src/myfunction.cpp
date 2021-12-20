#include "myfunction.hpp"

    int Request::RegistrationTo(user_t& r)
    {
        char check[] = "SELECT nickname, password FROM user_m WHERE (nickname = $1) AND (password = $2)";

        const char* reg[2];

        reg[0] = (r.nickname).c_str();
        reg[1] = (r.password).c_str();

        PGresult *res = PQexecParams(PGConnection::GetConnection(), check, 2, NULL, reg, NULL, NULL, 0);

        // if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        //     printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));
        //     PQclear(res);
        //     return ERROR;
        // };

        int n = PQgetisnull(res, 0, 0);
        int p = PQgetisnull(res, 0, 1);

        PQclear(res);

        if (n == 0 || p == 0) {
            return ERROR;
        };

        char command[] = "INSERT INTO user_m (nickname, password) VALUES ($1 , $2)";
        
        res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, reg, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
            PQclear(res);
            return ERROR;
        };
        PQclear(res);
        return SUCCESS;
    };  

    char* Request::GetId(user_t& r)
    {
        char return_id[] = "SELECT user_id FROM user_m WHERE (nickname = $1)";

        const char* reg[1];

        reg[0] = r.nickname.c_str();

        PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, reg, NULL, NULL, 0);

        // if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        //     printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
        //     PQclear(res);
        // };

        char* id = PQgetvalue(res, 0, 0);
        PQclear(res);
        return id;
    }; 

    std::string Request::Registration(std::string str)
    {
        user_t user = Json::Registration(str);

        int code = Request::RegistrationTo(user);

        if (code == ERROR) {
            nlohmann::json error = {"registrationStatus", "USER_COLLISION"};
            return error.dump(); 
        };

        std::string id = Request::GetId(user);

        nlohmann::json answer;

        answer["user_id"] = id;

        return answer.dump();
    };

    int Request::AutorizationTo(user_t& r)
    {
        char check[] = "SELECT nickname, password "
                       "FROM user_m WHERE (nickname = $1) AND (password = $2)";

        const char* aut[2];

        aut[0] = (r.nickname).c_str();
        aut[1] = (r.password).c_str();

        PGresult *res = PQexecParams(PGConnection::GetConnection(), check, 2, NULL, aut, NULL, NULL, 0);

        // if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        //     printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));
        //     PQclear(res);
        //     return ERROR;
        // };

        int n = PQgetisnull(res, 0, 0);
        int p = PQgetisnull(res, 0, 1);

        if (n == 1 || p == 1) {
            return ERROR;
        };

        PQclear(res);

        return SUCCESS;
    };

    std::string Request::Autorization(std::string str)
    {
        user_t user = Json::Autorization(str);

        int code = Request::AutorizationTo(user);

        if (code == ERROR) {
            nlohmann::json error = {"autorizationStatus", "ERROR"};
            return error.dump(); 
        };

        std::string id = Request::GetId(user);

        nlohmann::json answer;

        answer["user_id"] = id;

        return answer.dump();
    };
