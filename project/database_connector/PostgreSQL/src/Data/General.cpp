#include "../../include/PGConnection.hpp"

#include "../../../include/impl/DataBaseConnectorImpl.hpp"

namespace DatabaseConnector {
    namespace Data {
        namespace General {
            int CreateNull(const std::string& user_id) {
                char command[] = "INSERT INTO general_data (fk_data_user) "
                                 "VALUES ($1)";

                const char* arguments[1];

                arguments[0] = user_id.c_str();


                PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

                if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                    printf("General CreateNull command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res);

                    return ERROR;
                }

                PQclear(res);

                return SUCCESS;
            }

            int ReWrite(const general_data_t &d) {
                char command_1[] = "UPDATE general_data "
                                 "SET status = $1, label = $2, description = $3 "
                                 "WHERE fk_data_user = $4";

                const char *arguments_part_1[4];

                arguments_part_1[0] = d.status.c_str();
                arguments_part_1[1] = d.label.c_str();
                arguments_part_1[2] = d.description.c_str();
                arguments_part_1[3] = d.user_id.c_str();

                PGresult *res_1 = PQexecParams(PGConnection::GetConnection(), command_1, 4, NULL, arguments_part_1, NULL, NULL, 0);

                if (PQresultStatus(res_1) != PGRES_COMMAND_OK) {
                    printf("General ReWrite Part 1 command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res_1);

                    return ERROR;
                }

                PQclear(res_1);

                // Part 2 nickname

                char command_2[] = "UPDATE user_m "
                                 "SET nickname = $1 "
                                 "WHERE user_id = $2";

                const char *arguments_part_2[2];

                arguments_part_2[0] = d.nickname.c_str();
                arguments_part_2[1] = d.user_id.c_str();

                PGresult *res_2 = PQexecParams(PGConnection::GetConnection(), command_2, 2, NULL, arguments_part_2, NULL, NULL, 0);

                if (PQresultStatus(res_2) != PGRES_COMMAND_OK) {
                    printf("General ReWrite Part 2 command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res_2);

                    return ERROR;
                }

                PQclear(res_2);

                return SUCCESS;
            }

            general_data_t Get(const std::string &user_id) {
                general_data_t Data;

                char command[] = "SELECT status, label, description FROM general_data WHERE (fk_data_user = $1)";

                const char *arguments[1];

                arguments[0] = user_id.c_str();

                PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

                if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                    printf("General Get command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res);

                    Data.user_id = "Error";

                    return Data;
                }

                std::cout << user_id << std::endl;

                Data.status = PQgetvalue(res, 0, 0);
                Data.label = PQgetvalue(res, 0, 1);
                Data.description = PQgetvalue(res, 0, 2);

                Print_struct::_general_data_t(Data);

                PQclear(res);

                return Data;
            }
        }
    }
}

