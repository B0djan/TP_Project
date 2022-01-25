#include "../../include/PGConnection.hpp"

#include "../../../include/impl/DataBaseConnectorImpl.hpp"

namespace DatabaseConnector {
    namespace Group {
        int Create(const group_t& group) {
            char command[] = "INSERT INTO group_m (title, description) VALUES ($1, $2)";
            const char* arguments[2];

            arguments[0] = group.title.c_str();
            arguments[1] = group.description.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("Create command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::_group_t(group);
            }

            return SUCCESS;
        }

        int Write(const group_t& g) {
            char command[] = "UPDATE group_m "
                             "SET title = $1, description = $2"
                             "WHERE (group_id = $3)";


            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::_group_t(g);
            }

            const char* arguments[3];

            arguments[0] = g.title.c_str();
            arguments[1] = g.description.c_str();
            arguments[2] = g.group_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 3, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("Write command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            return SUCCESS;
        }

        int Delete(const std::string &group_id) {
            char command[] = "DELETE FROM group_m WHERE (group_id = $1)";

            const char* arguments[1];

            arguments[0] = group_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("Delete command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

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

        int DeleteAllMembers(const std::string& group_id) {
            char command[] = "DELETE FROM group_members WHERE (fk_group_id = $1)";

            const char* arguments[1];

            arguments[0] = group_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("DeleteAllMembers command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

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

        group_t GetMembers(const std::string &group_id) {
            char command_get_members[] = "Select fk_user_id FROM group_members WHERE (fk_group_id = $1)";

            const char* arguments_g[1];

            arguments_g[0] = group_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command_get_members, 1, NULL, arguments_g, NULL, NULL, 0);

            group_t group;
            if (PQgetisnull(res, 0, 0)) {
                group.group_id = "Error";

                return group;
            }

            int n_rows = PQntuples(res);

            std::string buf;
            for (int i = 0; i < n_rows; i++) {
                char *member = PQgetvalue(res, i, 0);

                buf = member;

                char* check_user_id = DatabaseConnector::GetNickname::User(buf);
                if (check_user_id == NULL) {
                    group.group_id = "Error";

                    return group;
                }

                group.members.insert(check_user_id);

                Print_struct::_group_t(group);
            }

            //  Отладка
            if (GLOBAL_KEY_TEST_DATABASE_CON) {
                Print_struct::_group_t(group);
            }


            return group;
        }
    }
}
