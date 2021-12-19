#include "EventImpl.hpp"

int AddEventImpl::AddEvent(event_t& e) {
    const char command[] = "INSERT INTO event_m (event_date, time_begin, time_end, description, fk_user_id) VALUES ($1 , $2, $3, $4, $5)";

    const char* reg[5];

    reg[0] = (e.date).c_str();
    reg[1] = (e.time_begin).c_str();
    reg[2] = (e.time_end).c_str();
    reg[3] = (e.description).c_str();
    reg[4] = (e.user_id).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 5, NULL, reg, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        PGConnection::CloseConnection();
    } else {
        return 0;
    };
};

std::set<event_t> WriteEventImpl::ShowEvents(event_t& e) {
    const char command[] = "SELECT  FROM event_m WHERE (event_date = $1) AND (fk_user_id = $2)";

    const char* reg[2];

    reg[0] = (e.date).c_str();
    reg[1] = (e.user_id).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, reg, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        PGConnection::CloseConnection();
    };

    int nrows = PQntuples(res);

    std::set<event_t> result;
    event_t event;
    
    for(int i = 0; i < nrows; i++) {
        event.date = (res,i,0);
        //  event.description = (res,i,1);
        event.event_name = (res,i,2);
        event.time_begin = (res,i,3);
        event.time_end = (res,i,4);
        event.user_id = (res,i,5);

        result.insert(event);
    };

    return result;
};

int RmEventImpl::RmEvent(event_t& e) {
    const char command[] = "DELETE FROM event_m WHERE (event_date = $1) AND (time_begin = $2) AND (time_end = $3) AND (description = $4) AND (fk_user_id = $5)";

    const char* reg[5];

    reg[0] = (e.date).c_str();
    reg[1] = (e.time_begin).c_str();
    reg[2] = (e.time_end).c_str();
    reg[3] = (e.description).c_str();
    reg[4] = (e.user_id).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 5, NULL, reg, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
       PGConnection::CloseConnection();
    } else {
        return 0;
    };
};
