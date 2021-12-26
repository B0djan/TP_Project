#include "../include/PGConnection.hpp"

#include "../../include/impl/DataBaseConnectorImpl.hpp"

namespace DatabaseConnector {
    namespace Contact {
        int Add(const std::string &user_id_main, const std::string &user_id_friend) {
            char command[] = "INSERT INTO contacts (fk_user_id, fk_friend_id) VALUES ($1, $2)";

            const char *arguments[2];

            arguments[0] = user_id_main.c_str();
            arguments[1] = user_id_friend.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            };

            PQclear(res);

            return SUCCESS;
        };

        int Delete(const std::string &user_id_main, const std::string &user_id_friend) {
            char command[] = "DELETE FROM contacts WHERE (fk_user_id = $1) AND (fk_friend_id = $2)";

            const char *arguments[2];

            arguments[0] = user_id_main.c_str();
            arguments[1] = user_id_friend.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            };

            PQclear(res);

            return SUCCESS;
        }
    }
}

