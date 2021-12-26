#include <WritePersonalDataImpl.hpp>

ParserObject WritePersonalDataImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = ReWritePersonalData(request_body.personal_data);
    if (code != 0) {
        response_body.error = "Error write personal data";

        return response_body;
    }

    return response_body;
}

ParserObject GetPersonalDataImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    personal_data_t check_personal_data = GetPersonalData(request_body.personal_data.user_id);
    if (check_personal_data.user_id == "Error") {
        response_body.error = "Error get personal data";

        return response_body;
    }

    return response_body;
}


int WritePersonalDataImpl::ReWritePersonalData(const personal_data_t& d) {
    char command[] = "UPDATE user_address "
                     "SET (building = $1, housing = $2, housing = $3, city = $4, district = $5, index = $6, country = $7)"
                     "WHERE (fk_address_user = $8)";

    const char* arguments[8];

    arguments[0] = d.first_name.c_str();
    arguments[1] = d.surname.c_str();
    arguments[2] = d.age.c_str();
    arguments[3] = d.phone_number.c_str();
    arguments[4] = d.status.c_str();
    arguments[5] = d.label.c_str();
    arguments[6] = d.description.c_str();
    arguments[7] = d.user_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 8, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    }

    PQclear(res);

    return SUCCESS;
}

personal_data_t GetPersonalDataImpl::GetPersonalData(const std::string &user_id) {
    personal_data_t Data;

    char command[] = "SELECT first_name, last_name, age, phone_number, status, label, description FROM personal_data WHERE fk_data_user = $1";

    const char* arguments[1];

    arguments[0] = user_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        Data.user_id = "Error";

        return Data;
    }

    Data.first_name = PQgetvalue (res,0,0);
    Data.surname = PQgetvalue (res,0,1);
    Data.age = PQgetvalue (res,0,2);
    Data.phone_number = PQgetvalue (res,0,3);
    Data.status = PQgetvalue (res,0,4);
    Data.label = PQgetvalue (res,0,5);
    Data.description = PQgetvalue (res,0,6);

    PQclear(res);

    return Data;
}
