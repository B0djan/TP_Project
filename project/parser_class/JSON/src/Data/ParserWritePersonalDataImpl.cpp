#include <Data/ParserWritePersonalDataImpl.hpp>

ParserObject ParserWritePersonalDataImpl::StrToObject(const std::string& parser_str) const {

    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    personal_data_t personal_data;

    if (value.contains("user_id"))
        personal_data.user_id = value["user_id"].get<std::string>();

    if (value.contains("first_name"))
        personal_data.first_name = value["first_name"].get<std::string>();

    if (value.contains("surname"))
        personal_data.surname = value["surname"].get<std::string>();

    if (value.contains("age"))
        personal_data.age = value["age"].get<std::string>();

    if (value.contains("phone_number"))
        personal_data.phone_number = value["phone_number"].get<std::string>();

    if (value.contains("email"))
        personal_data.email = value["email"].get<std::string>();

    ParserObject res;

    res = personal_data;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::from_client(parser_str);
        Print_struct::_personal_data_t(personal_data);
    }

    return res;
}

std::string ParserWritePersonalDataImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    // {"registration":{"user_id":"value"}} Отредачить

    nlohmann::json j;

    std::string res;

    if (type_response == WRITE_PERSONAL_DATA) {
        if (other.error.empty()) {
            j[type_response] = "OK";

            res = j.dump();
        } else  {
            j[type_response] = other.error;

            res = j.dump();
        }

        return res;
    }

    if (!other.error.empty()) {
        j[type_response] = other.error;

        res = j.dump();

        return res;
    }


    personal_data_t personal_data = other.personal_data;

    nlohmann::json value;

    if (!personal_data.user_id.empty())
        value["user_id"] = personal_data.user_id;

    if (!personal_data.first_name.empty())
        value["first_name"] = personal_data.first_name;

    if (!personal_data.surname.empty())
        value["surname"] = personal_data.surname;

    if (!personal_data.age.empty())
        value["age"] = personal_data.age;

    if (!personal_data.phone_number.empty())
        value["phone_number"] = personal_data.phone_number;

    if (!personal_data.email.empty())
        value["email"] = personal_data.email;

    j[type_response] = value;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::_personal_data_t(personal_data);
        Print_struct::from_processing(res);
    }

    return res;
}