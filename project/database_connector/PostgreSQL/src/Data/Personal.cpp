#include "../../include/PGConnection.hpp"

#include "../../../include/impl/DataBaseConnectorImpl.hpp"

namespace DatabaseConnector {
    namespace Data {
        namespace Personal {
            int CreateNull(const std::string& user_id) {
                char command[] = "INSERT INTO personal_data (fk_data_user) "
                                 "VALUES ($1)";

                const char* arguments[1];

                arguments[0] = user_id.c_str();


                PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

                if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                    printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res);

                    return ERROR;
                }

                PQclear(res);

                return SUCCESS;
            }

            int ReWrite(const personal_data_t &d) {
                char command[] = "UPDATE personal_data "
                                 "SET first_name = $1, last_name = $2, age = $3, phone_number = $4, status = $5, label = $6, description = $7, email = $8 "
                                 "WHERE fk_data_user = $9";

                const char *arguments[9];

                arguments[0] = d.first_name.c_str();
                arguments[1] = d.surname.c_str();
                arguments[2] = d.age.c_str();
                arguments[3] = d.phone_number.c_str();
                arguments[4] = d.status.c_str();
                arguments[5] = d.label.c_str();
                arguments[6] = d.description.c_str();
                arguments[7] = d.email.c_str();
                arguments[8] = d.user_id.c_str();

                PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 9, NULL, arguments, NULL, NULL, 0);

                if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                    printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res);

                    return ERROR;
                }

                PQclear(res);

                return SUCCESS;
            }

            personal_data_t Get(const std::string &user_id) {
                personal_data_t Data;

                char command[] = "SELECT first_name, last_name, age, phone_number, status, label, description, email FROM personal_data WHERE (fk_data_user = $1)";

                const char *arguments[1];

                arguments[0] = user_id.c_str();

                PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

                if (PQresultStatus(res) != PGRES_TUPLES_OK) {
                    printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res);

                    Data.user_id = "Error";

                    return Data;
                }

                std::cout << user_id << std::endl;

                Data.first_name = PQgetvalue(res, 0, 0);
                Data.surname = PQgetvalue(res, 0, 1);
                Data.age = PQgetvalue(res, 0, 2);
                Data.phone_number = PQgetvalue(res, 0, 3);
                Data.status = PQgetvalue(res, 0, 4);
                Data.label = PQgetvalue(res, 0, 5);
                Data.description = PQgetvalue(res, 0, 6);
                Data.email = PQgetvalue(res, 0, 7);

                Print_struct::_personal_data_t(Data);

                PQclear(res);

                return Data;
            }
        }
    }
}


