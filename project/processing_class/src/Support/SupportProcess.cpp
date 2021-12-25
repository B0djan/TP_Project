#include <Handler.hpp>

namespace SupportProcess {
    char* GetUserId(const std::string& nickname) {
        char return_id[] = "SELECT user_id FROM user_m WHERE (nickname = $1)";

        const char* arguments[1];

        arguments[0] = nickname.c_str();

        PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, arguments, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
            PQclear(res);
        }

        char* id = PQgetvalue(res, 0, 0);
        PQclear(res);
        return id;
    }

    char* GetEventId(const event_t &e) {
        char return_id[] = "SELECT event_id FROM event_m WHERE (event_date = $1) AND (time_begin = $2) AND (time_end = $3) AND (description = $4)";

        const char* arguments[4];

        arguments[0] = e.date.c_str();
        arguments[1] = e.time_begin.c_str();
        arguments[2] = e.time_end.c_str();
        arguments[3] = e.description.c_str();


        PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 4, NULL, arguments, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
            PQclear(res);
        };

        char* id = PQgetvalue(res, 0, 0);
        PQclear(res);
        return id;
    }

    char* GetGroupId(const std::string& title) {
        char return_id[] = "SELECT group_id FROM group_m WHERE (title = $1)";

        const char* arguments[1];

        arguments[0] = title.c_str();

        PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, arguments, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
            PQclear(res);
        }

        char* id = PQgetvalue(res, 0, 0);

        PQclear(res);

        return id;
    }
}

