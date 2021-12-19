#include <WriteAddressDataImpl.hpp>

void WriteAddressDataImpl:: WriteAddress(addres_data_t& a) {
    const char command[] = "INSERT INTO user_address (building, housing, street, city, district, index, country, fk_address_user) VALUES ($1 , $2, $3, $4, $5, $6, $7, $8)";

    const char* adr[8];

    adr[0] = (a.building).c_str();
    adr[1] = (a.housing).c_str();
    adr[2] = (a.street).c_str();
    adr[3] = (a.city).c_str();
    adr[4] = (a.district).c_str();
    adr[5] = (a.index).c_str();
    adr[6] = (a.country).c_str();
    adr[7] = (a.user_id).c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 8, NULL, adr, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        PGConnection::CloseConnection();
    } else {
        return 0;
    };
};
