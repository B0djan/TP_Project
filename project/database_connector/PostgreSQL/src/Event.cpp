#include "../include/PGConnection.hpp"

#include "../../include/impl/DataBaseConnectorImpl.hpp"

namespace DatabaseConnector {
    namespace Event {
        int Add(const event_t& e) {
            char command[] = "INSERT INTO event_m (event_name, event_date, time_begin, time_end, description, fk_user_id) VALUES ($1, $2, $3, $4, $5, $6)";

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::_event_t(e);
            }

            const char* arguments[6];

            arguments[0] = e.event_name.c_str();
            arguments[1] = e.date.c_str();
            arguments[2] = e.time_begin.c_str();
            arguments[3] = e.time_end.c_str();
            arguments[4] = e.description.c_str();
            arguments[5] = e.user_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 6, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("Add command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            return SUCCESS;
        }


        int Write(const event_t& e) {
            char command[] = "UPDATE event_m "
                             "SET event_name = $1, event_date = $2, time_begin = $3, time_end = $4, description = $5 "
                             "WHERE (event_id = $6)";


            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::_event_t(e);
            }

            const char* arguments[6];

            arguments[0] = e.event_name.c_str();
            arguments[1] = e.date.c_str();
            arguments[2] = e.time_begin.c_str();
            arguments[3] = e.time_end.c_str();
            arguments[4] = e.description.c_str();
            arguments[5] = e.event_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 6, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("Write command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            return SUCCESS;
        }


        int Delete(const std::string& event_id) {
            char command[] = "DELETE FROM event_m WHERE (event_id = $1)";

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                std::cout << "----------------------------" << std::endl;
                Print_struct::from_client(event_id);
            }

            const char* arguments[1];

            arguments[0] = event_id.c_str();


            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            return SUCCESS;

        }
    }
}

