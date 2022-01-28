#include <Data/ParserWriteSecurityDataImpl.hpp>

ParserObject ParserWriteSecurityDataImpl::StrToObject(const std::string& parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    user_t user;

    if (value.contains("user_id"))
        user.user_id = value["user_id"].get<std::string>();

    if (value.contains("password"))
        user.password = value["password"].get<std::string>();

    if (value.contains("nickname"))
        user.nickname = value["nickname"].get<std::string>();

    ParserObject res;

    res = user;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::from_client(parser_str);
        Print_struct::_user_t(user);
    }

    return res;
}

std::string ParserWriteSecurityDataImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    nlohmann::json j;

    std::string res;

    if (type_response == WRITE_PASSWORD || type_response == WRITE_NICKNAME) {
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

    return res;
}