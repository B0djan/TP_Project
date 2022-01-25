#include <ParserWriteGeneralDataImpl.hpp>

ParserObject ParserWriteGeneralDataImpl::StrToObject(const std::string& parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    general_data_t general_data;

    if (value.contains("status"))
        general_data.user_id = value["user_id"].get<std::string>();

    if (value.contains("status"))
        general_data.status = value["status"].get<std::string>();

    if (value.contains("label"))
        general_data.label = value["label"].get<std::string>();

    if (value.contains("description"))
        general_data.description = value["description"].get<std::string>();

    if (value.contains("nickname"))
        general_data.nickname = value["email"].get<std::string>();

    ParserObject res;

    res = general_data;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::from_client(parser_str);
        Print_struct::_general_data_t(general_data);
    }

    return res;
}

std::string ParserWriteGeneralDataImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    nlohmann::json j;

    std::string res;

    if (type_response == WRITE_GENERAL_DATA) {
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


    general_data_t general_data = other.general_data;

    nlohmann::json value;

    if (!general_data.user_id.empty())
        value["user_id"] = general_data.user_id;

    if (!general_data.status.empty())
        value["status"] = general_data.status;

    if (!general_data.label.empty())
        value["label"] = general_data.label;

    if (!general_data.description.empty())
        value["description"] = general_data.description;

    if (!general_data.nickname.empty())
        value["nickname"] = general_data.nickname;

    j[type_response] = value;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::_general_data_t(general_data);
        Print_struct::from_processing(res);
    }

    return res;
}