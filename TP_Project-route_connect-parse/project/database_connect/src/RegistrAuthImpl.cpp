#include "RegistrAuthImpl.hpp"

char* RegistrationImpl::Registration(user_t& r) 
{
    char command[] = "INSERT into USER_M (email, password, nickname) VALUES ($1 , $2, $3)";

    const char* reg[3];

    reg[0] = (r.email).c_str();
    reg[1] = (r.password).c_str();
    reg[2] = (r.nickname).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 3, NULL, reg, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        PGConnection::CloseConnection();
    };

    char return_id[] = "SELECT user_id FROM user_m WHERE email = $1";

    const char* get_id[1];

    get_id[0] = reg[0];

    res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, get_id, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        PGConnection::CloseConnection();
    } else {
        char* id = PQgetvalue(res, 0, 0);
        PQclear(res);
        return id;
    };

};

int AuthenticationImpl::Authentication(user_t& r) 
{
    const char command[] = "SELECT user_id FROM user_m WHERE (email = $1) AND (password = $2)";

    const char* aut[2];

    aut[0] = (r.email).c_str();
    aut[1] = (r.password).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, aut, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        PGConnection::CloseConnection();
    };

    if (PQgetisnull(res, 0, 0) == 0) {
        return 0;
    } else {
        return -1;
    };

};
