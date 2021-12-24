#include <EventImpl.hpp>

ParserObject AddEventImpl::process(const ParserObject& request_body) {
    int code;

    for (auto event: request_body.events) {
        code += AddEvent(event);
    };

    ParserObject response_body;

    if (code != 0) {
        return response_body;
    };

    return response_body;
}

ParserObject WriteEventImpl::process(const ParserObject& request_body) {
    int code;

    for (auto event: request_body.events) {
        code += WriteEvent(event);
    };

    ParserObject response_body;

    if (code != 0) {
        return response_body;
    };

    return response_body;
}

ParserObject RmEventImpl::process(const ParserObject& request_body) {

    int code;

    for (auto event: request_body.events) {
        code += DeleteEvent(event);
    };

    ParserObject response_body;

    if (code != 0) {
        return response_body;
    };

    return response_body;
}

int AddEventImpl::AddEvent(event_t& e) {

    char command[] = "INSERT INTO event_m (event_date, time_begin, time_end, fk_user_id) VALUES ($1, $2, $3, $4)";

    const char* arguments[4];

    arguments[0] = e.event_name.c_str();
    arguments[1] = e.time_begin.c_str();
    arguments[2] = e.time_end.c_str();
    arguments[3] = e.user_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 4, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        return ERROR;
    } else {
        return SUCCESS;
    };
}


int WriteEventImpl::WriteEvent(event_t& e) {
    char command[] = "UPDATE event_m "
                     "SET (event_date = $1, time_begin = $2, time_end = $3, description = $4)"
                     "WHERE (fk_user_id = $5)";
    //  (nickname = $1) AND (password = $2)
    const char* arguments[5];

    arguments[0] = e.event_name.c_str();
    arguments[1] = e.time_begin.c_str();
    arguments[2] = e.time_end.c_str();
    arguments[3] = e.description.c_str();
    arguments[4] = e.user_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 5, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        return ERROR;
    } else {
        return SUCCESS;
    };
}


int RmEventImpl::DeleteEvent(event_t& e){

    char command[] = "DELETE FROM event_m WHERE (event_date = $1) AND (time_begin = $2) AND (time_end = $3) AND (fk_user_id = $4)";

    const char* arguments[4];

    arguments[0] = e.event_name.c_str();
    arguments[1] = e.time_begin.c_str();
    arguments[2] = e.time_end.c_str();
    arguments[3] = e.user_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 4, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        return ERROR;
    } else {
        return SUCCESS;
    };
}
