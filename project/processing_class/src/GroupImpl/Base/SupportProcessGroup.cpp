#include <Handler.hpp>


namespace SupportProcessGroup {
    int AddMember(const std::string &user_id, const std::string group_id) {
        char command[] = "INSERT INTO group_members (fk_group_id, fk_user_id) VALUES ($1, $2)";

        //  Отладка
        if (GLOBAL_KEY_TEST_PROCESSING) {
            Print_struct::from_client(user_id);
            Print_struct::from_processing(group_id);
        }

        const char *arguments[2];

        arguments[0] = group_id.c_str();
        arguments[1] = user_id.c_str();

        PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

            PQclear(res);

            return ERROR;
        }

        PQclear(res);

        return SUCCESS;
    }

    int RmMember(const std::string &user_id, const std::string group_id) {
        char command[] = "DELETE FROM group_members WHERE (fk_group_id = $1) AND (fk_user_id = $2)";

        //  Отладка
        if (GLOBAL_KEY_TEST_PROCESSING) {
            Print_struct::from_client(user_id);
            Print_struct::from_processing(group_id);
        }

        const char *arguments[2];

        arguments[0] = group_id.c_str();
        arguments[1] = user_id.c_str();

        PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_COMMAND_OK) {
            printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

            PQclear(res);

            return ERROR;
        }

        PQclear(res);

        return SUCCESS;
    }
}
