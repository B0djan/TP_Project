#include "../include/PGConnection.hpp"

#include "../../include/impl/DataBaseConnectorImpl.hpp"

namespace DatabaseConnector {
    namespace GetID {
        char *User(const std::string& nickname) {
            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::from_processing(nickname);
            }

            char return_id[] = "SELECT user_id FROM user_m WHERE (nickname = $1)";

            const char *arguments[1];

            arguments[0] = nickname.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                printf("User command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);
            }

            char *id = PQgetvalue(res, 0, 0);

            PQclear(res);

            return id;
        }

        char *Event(const event_t& e) {
            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::_event_t(e);
            }

            char return_id[] = "SELECT event_id FROM event_m WHERE (event_name = $1) AND (event_date = $2) AND (time_begin = $3) AND (time_end = $4) AND (description = $5)";

            const char *arguments[5];

            arguments[0] = e.event_name.c_str();
            arguments[1] = e.date.c_str();
            arguments[2] = e.time_begin.c_str();
            arguments[3] = e.time_end.c_str();
            arguments[4] = e.description.c_str();


            PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 5, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                printf("Event command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);
            };

            char *id = PQgetvalue(res, 0, 0);

            PQclear(res);

            return id;
        }

        char *Group(const std::string& title) {
            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::from_client(title);
            }

            char return_id[] = "SELECT group_id FROM group_m WHERE (title = $1)";

            const char *arguments[1];

            arguments[0] = title.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                printf("Group command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);
            }

            char *id = PQgetvalue(res, 0, 0);

            PQclear(res);

            return id;
        }
    }

    namespace GetNickname {
        char *User(const std::string& user_id) {
            char return_id[] = "SELECT nickname FROM user_m WHERE (user_id = $1)";

            const char *arguments[1];

            arguments[0] = user_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);
            }

            char *id = PQgetvalue(res, 0, 0);

            PQclear(res);

            return id;
        }
    }
}
