#include "../../include/PGConnection.hpp"

#include "../../../include/impl/DataBaseConnectorImpl.hpp"

namespace DatabaseConnector {
    namespace Data {
        namespace Address {
            int CreateNull(const std::string& user_id) {
                char command[] = "INSERT INTO user_address (fk_address_user) "
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

            int ReWrite(const address_data_t &a) {
                char command[] = "UPDATE user_address "
                                 "SET (building = $1, housing = $2, housing = $3, city = $4, district = $5, index = $6, country = $7)"
                                 "WHERE (fk_address_user = $8)";

                const char *arguments[8];

                arguments[0] = a.building.c_str();
                arguments[1] = a.housing.c_str();
                arguments[2] = a.street.c_str();
                arguments[3] = a.city.c_str();
                arguments[4] = a.district.c_str();
                arguments[5] = a.index.c_str();
                arguments[6] = a.country.c_str();
                arguments[7] = a.user_id.c_str();

                PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 8, NULL, arguments, NULL, NULL, 0);

                if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                    printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res);

                    return ERROR;
                }

                PQclear(res);

                return SUCCESS;
            }

            address_data_t Get(const std::string &user_id) {
                address_data_t Data;

                char command[] = "SELECT building, housing, street, city, district, index, country FROM address_data WHERE fk_address_user = $1";

                const char *arguments[1];

                arguments[0] = user_id.c_str();

                PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

                if (PQresultStatus(res) != PGRES_COMMAND_OK) {
                    printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

                    PQclear(res);

                    Data.user_id = "Error";

                    return Data;
                }

                Data.building = PQgetvalue(res, 0, 0);
                Data.housing = PQgetvalue(res, 0, 1);
                Data.street = PQgetvalue(res, 0, 2);
                Data.city = PQgetvalue(res, 0, 3);
                Data.district = PQgetvalue(res, 0, 4);
                Data.index = PQgetvalue(res, 0, 5);
                Data.country = PQgetvalue(res, 0, 6);

                PQclear(res);

                return Data;
            }
        }
    }
}

