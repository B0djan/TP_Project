#include <Handler.hpp>

namespace SupportProcess {
    char* GetId(user_t &r) {
        char return_id[] = "SELECT user_id FROM user_m WHERE (nickname = $1)";

        const char* reg[1];

        reg[0] = r.nickname.c_str();

        PGresult *res = PQexecParams(PGConnection::GetConnection(), return_id, 1, NULL, reg, NULL, NULL, 0);

        if (PQresultStatus(res) != PGRES_TUPLES_OK) {
            printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
            PQclear(res);
        };

        char* id = PQgetvalue(res, 0, 0);
        PQclear(res);
        return id;
    }
}

