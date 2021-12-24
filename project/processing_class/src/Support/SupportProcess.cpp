#include <Handler.hpp>

namespace SupportProcess {
    char* GetUserId(user_t &r) {
        char return_id[] = "SELECT user_id FROM user_m WHERE (nickname = $1)";

        const char* arguments[1];

        arguments[0] = r.nickname.c_str();

        PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, arguments, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            printf("command field: %s\n", PQerrorMessage(PGConnection::GetConnection()));
            PQclear(res);
        };

        char* id = PQgetvalue(res, 0, 0);
        PQclear(res);
        return id;
    }

    char* GetEventId(event_t &r) {
        char return_id[] = "SELECT event_id FROM event_m WHERE (event_date = $1) AND (time_begin = $2) AND (time_end = $3) AND (description = $4)";

        const char* arguments[4];

        arguments[0] = r.date.c_str();
        arguments[1] = r.time_begin.c_str();
        arguments[2] = r.time_end.c_str();
        arguments[3] = r.description.c_str();


        PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 4, NULL, arguments, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            printf("command field: %s\n", PQerrorMessage(PGConnection::GetConnection()));
            PQclear(res);
        };

        char* id = PQgetvalue(res, 0, 0);
        PQclear(res);
        return id;
    }
}

