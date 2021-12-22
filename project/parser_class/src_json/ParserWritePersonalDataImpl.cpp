#include <ParserWritePersonalDataImpl.hpp>

ParserObject ParserWritePersonalDataImpl::StrToObject(const std::string& parser_str) {
    
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

    return res;
}

std::string ParserWritePersonalDataImpl::ObjectToStr(const ParserObject& other) {

    personal_data_t personal_data = other.personal_data;

    nlohmann::json value;

    value["user_id"] = personal_data.user_id;

    value["first_name"] = personal_data.first_name;

    value["surname"] = personal_data.surname;

    value["age"] = personal_data.age;

    value["phone_number"] = personal_data.phone_number;

    value["status"] = personal_data.status;

    value["label"] = personal_data.label;

    value["description"] = personal_data.description;

    nlohmann::json j;

    j["person"] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    return res;
}