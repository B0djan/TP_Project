#include <RegistrAuthImpl.hpp>

ParserObject RegistrationImpl::process(const ParserObject& request_body) {

    user_t user = request_body.user;

    int code = this = RegistrationTo(user);

    ParserObject response_body;

    if (code == ERROR) {
        response_body.error = "USER_COLLISION";
        return response_body;
    };

    std::string id = GetId(user);

    response_body.user.user_id = id;

    return response_body;
}

ParserObject AuthenticationImpl::process(const ParserObject& request_body) {

    user_t user = request_body.user;

    int code = AutorizationTo(user);

    ParserObject response_body;

    if (code == ERROR) {
        response_body.error = "ERROR";
        return response_body;
    };

    std::string id = GetId(user);

    response_body.user.user_id = id;

    return response_body;
}

int RegistrationImpl::RegistrationTo(user_t& r) {
    
    char check[] = "SELECT nickname, password FROM user_m WHERE (nickname = $1) AND (password = $2)";

    const char* reg[2];

    reg[0] = (r.nickname).c_str();
    reg[1] = (r.password).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), check, 2, NULL, reg, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        return ERROR;
    };

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
}

int AuthenticationImpl::AutorizationTo(user_t& r) {

    char check[] = "SELECT nickname, password "
                    "FROM user_m WHERE (nickname = $1) AND (password = $2)";

    const char* aut[2];

    aut[0] = (r.nickname).c_str();
    aut[1] = (r.password).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), check, 2, NULL, aut, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        return ERROR;
    };

    int n = PQgetisnull(res, 0, 0);
    int p = PQgetisnull(res, 0, 1);

    if (n == 1 || p == 1) {
        return ERROR;
    };

    PQclear(res);

    return SUCCESS;
};

char* GetId(user_t& r) {

    char return_id[] = "SELECT user_id FROM user_m WHERE (nickname = $1)";

    const char* reg[1];

    reg[0] = r.nickname.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, reg, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
    };

    char* id = PQgetvalue(res, 0, 0);
    PQclear(res);
    return id;

}
