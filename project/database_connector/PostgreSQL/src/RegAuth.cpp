#include <PGConnection.hpp>

#include <DataBaseConnectorImpl.hpp>

namespace DatabaseConnector {
    namespace RegAuth {
        int RegistrationTo(const user_t &r) {
            char check[] = "SELECT nickname, password FROM user_m WHERE (nickname = $1) AND (password = $2)";

            const char *arguments[2];

            arguments[0] = (r.nickname).c_str();
            arguments[1] = (r.password).c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), check, 2, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            int n = PQgetisnull(res, 0, 0);
            int p = PQgetisnull(res, 0, 1);

            PQclear(res);

            if (n == 0 || p == 0) {
                return ERROR;
            }

            char command[] = "INSERT INTO user_m (nickname, password) VALUES ($1 , $2)";

            res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            return SUCCESS;
        }

        int AutorizationTo(const user_t &r) {
            char check[] = "SELECT nickname, password "
                           "FROM user_m WHERE (nickname = $1) AND (password = $2)";

            const char *arguments[2];

            arguments[0] = (r.nickname).c_str();
            arguments[1] = (r.password).c_str();

            PGresult *res = PQexecParams(PGConnection::GetConnection(), check, 2, NULL, arguments, NULL, NULL, 0);

            if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));

                PQclear(res);

                return ERROR;
            }

            int n = PQgetisnull(res, 0, 0);
            int p = PQgetisnull(res, 0, 1);

            if (n == 1 || p == 1) {
                PQclear(res);

                return ERROR;
            }

            PQclear(res);

            return SUCCESS;
        }
    }
}

