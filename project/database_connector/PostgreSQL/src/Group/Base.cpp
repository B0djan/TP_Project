#include "../../include/PGConnection.hpp"

#include "../../../include/impl/DataBaseConnectorImpl.hpp"

namespace DatabaseConnector {
    namespace Group {
        int Create(const std::string& title) {
            char command[] = "INSERT INTO group_m (title) VALUES ($1)";

            const char* arguments[1];

            arguments[0] = title.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::from_client(title);
            }

            return SUCCESS;
        }

        int Delete(const std::string &group_id) {
            char command[] = "DELETE FROM group_m WHERE (group_id = $1)";

            const char* arguments[1];

            arguments[0] = group_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::from_client(group_id);
            }

            return SUCCESS;
        }

        int DeleteAllMembers(const std::string &group_id) {
            char command[] = "DELETE FROM group_members WHERE (fk_group_id = $1)";

            const char* arguments[1];

            arguments[0] = group_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::from_client(group_id);
            }

            return SUCCESS;
        }

        group_t GetData(const std::string &group_id) {
            Print_struct::from_processing(group_id);

            char command_get_title[] = "Select title FROM group_m WHERE (group_id = $1)";

            const char* arguments_t[1];

            arguments_t[0] = group_id.c_str();

            PGresult *res_t = PQexecParams(PGConnection::GetConnection(), command_get_title, 1, NULL, arguments_t, NULL, NULL, 0);

            group_t group;

            if (PQgetisnull(res_t, 0, 0)) {
                group.group_id = "Error";

                return group;
            }

            group.title = PQgetvalue(res_t, 0, 0);

            PQclear(res_t);

            char command_get_members[] = "Select fk_user_id FROM group_members WHERE (fk_group_id = $1)";

            const char* arguments_g[1];

            arguments_g[0] = group_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command_get_members, 1, NULL, arguments_g, NULL, NULL, 0);

            if (PQgetisnull(res, 0, 0)) {
                group.group_id = "Error";

                return group;
            }

            int n_rows = PQntuples(res);

            std::string buf;
            for (int i = 0; i < n_rows; i++) {
                char *member = PQgetvalue(res, i, 0);

                buf = member;

                char* check_user_id = DatabaseConnector::GetID::User(buf);
                if (check_user_id == NULL) {
                    group.group_id = "Error";

                    return group;
                }

                group.members.insert(check_user_id);

                Print_struct::_group_t(group);
            }

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::from_client(group_id);
            }


            return group;
        }
    }
}
