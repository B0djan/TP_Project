#include <RegistrAuthImpl.hpp>

ParserObject RegistrationImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = RegistrationTo(request_body.user);
    if (code != 0) {
        response_body.error = "Error registration";

        return response_body;
    }

    char* check = SupportProcess::GetUserId(user.nickname);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    response_body.user.user_id = check;

    return response_body;
}

ParserObject AuthenticationImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = AutorizationTo(request_body.user);
    if (code != 0) {
        response_body.error = "Error autorization";

        return response_body;
    }

    char* check = SupportProcess::GetUserId(user.nickname);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    response_body.user.user_id = check;

    return response_body;
}

int RegistrationImpl::RegistrationTo(const user_t& r) {
    char check[] = "SELECT nickname, password FROM user_m WHERE (nickname = $1) AND (password = $2)";

    const char* arguments[2];

    arguments[0] = (r.nickname).c_str();
    arguments[1] = (r.password).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), check, 2, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    }

    int n = PQgetisnull(res, 0, 0);
    int p = PQgetisnull(res, 0, 1);

    PQclear(res);

    if (n == 0 || p == 0) {
        return ERROR;
    }

    char command[] = "INSERT INTO user_m (nickname, password) VALUES ($1 , $2)";
    
    res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    }

    PQclear(res);

    return SUCCESS;
}

int AuthenticationImpl::AutorizationTo(const user_t& r) {
    char check[] = "SELECT nickname, password "
                    "FROM user_m WHERE (nickname = $1) AND (password = $2)";

    const char* arguments[2];

    arguments[0] = (r.nickname).c_str();
    arguments[1] = (r.password).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), check, 2, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    }

    int n = PQgetisnull(res, 0, 0);
    int p = PQgetisnull(res, 0, 1);

    if (n == 1 || p == 1) {
        PQclear(res);

        return ERROR;
    }

    PQclear(res);

    return SUCCESS;
};
