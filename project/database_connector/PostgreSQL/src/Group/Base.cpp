#include <PGConnection.hpp>

#include <DataBaseConnectorImpl.hpp>

namespace DatabaseConnector {
    namespace Group {
        int Create(const std::string& title) {
            char command[] = "INSERT INTO group_m (title) VALUES ($1)";

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::from_client(title);
            }

            const char* arguments[1];

            arguments[0] = title.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            return SUCCESS;
        }

        int Delete(const std::string &group_id) {
            char command[] = "DELETE FROM group_m WHERE (group_id = $1)";

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::from_client(group_id);
            }

            const char* arguments[1];

            arguments[0] = group_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            return SUCCESS;
        }

        int DeleteAllMembers(const std::string &group_id) {
            char command[] = "DELETE FROM group_members WHERE (fk_group_id = $1)";

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::from_client(group_id);
            }

            const char* arguments[1];

            arguments[0] = group_id.c_str();

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
