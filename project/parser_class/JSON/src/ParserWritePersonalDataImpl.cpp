#include <ParserWritePersonalDataImpl.hpp>

ParserObject ParserWritePersonalDataImpl::StrToObject(const std::string& parser_str) const {
    // {"registration":{"user_id":"value"}} Отредачить
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    personal_data_t personal_data;

    if (j.contains("user_id"))
        personal_data.user_id = j["user_id"].get<std::string>();

    if (j.contains("first_name"))
        personal_data.first_name = j["first_name"].get<std::string>();

    if (j.contains("surname"))
        personal_data.surname = j["surname"].get<std::string>();

    if (j.contains("age"))
        personal_data.age = j["age"].get<std::string>();

    if (j.contains("phone_number"))
        personal_data.phone_number = j["phone_number"].get<std::string>();

    if (j.contains("status"))
        personal_data.phone_number = j["status"].get<std::string>();

    if (j.contains("label"))
        personal_data.phone_number = j["label"].get<std::string>();

    if (j.contains("description"))
        personal_data.phone_number = j["description"].get<std::string>();

    ParserObject res;

    res = personal_data;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::from_client(parser_str);
        Print_struct::personal_data_t(personal_data);
    }

    return res;
}

std::string ParserWritePersonalDataImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    // {"registration":{"user_id":"value"}} Отредачить
    nlohmann::json j;
    std::string res;

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

    if (!personal_data.status.empty())
        value["status"] = personal_data.status;

    if (!personal_data.label.empty())
        value["label"] = personal_data.label;

    if (!personal_data.description.empty())
        value["description"] = personal_data.description;

    j[type_response] = value;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::personal_data_t(personal_data);
        Print_struct::from_processing(res);
    }

    return res;
}