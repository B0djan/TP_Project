#include "../../include/PGConnection.hpp"

#include "../../../include/impl/DataBaseConnectorImpl.hpp"

namespace DatabaseConnector {
    namespace Security {
        int ReWritePassword(const std::string& user_id, const std::string& password) {
            char command[] = "UPDATE user_m "
                               "SET password = $1 "
                               "WHERE user_id = $2";

            const char *arguments[2];

            arguments[0] = password.c_str();
            arguments[1] = user_id.c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL,
                                           NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("General ReWrite Password command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            return SUCCESS;
        }

            int ReWriteNickname(const std::string& user_id, const std::string& nickname) {
                char command[] = "UPDATE user_m "
                                   "SET nickname = $1 "
                                   "WHERE user_id = $2";

                const char *arguments[2];

                arguments[0] = nickname.c_str();
                arguments[1] = user_id.c_str();

                PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments,
                                               NULL,
                                               NULL, 0);

                if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                    printf("General ReWrite Nickname command faild: %s\n",
                           PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res);

                    return ERROR;
                }

                PQclear(res);

                return SUCCESS;
            }
    }
}

