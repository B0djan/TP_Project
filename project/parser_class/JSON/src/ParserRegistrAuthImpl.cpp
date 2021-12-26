#include <ParserRegistrAuthImpl.hpp>


#include <iostream>

ParserObject ParserRegistrAuthImpl::StrToObject(const std::string& parser_str) const {
    //  {"registration":{"login":"mars444","password":"qqqqqqqqqqqqqqqq"}}

    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    user_t user;

    if (value.contains("user_id"))
        user.user_id = value["user_id"].get<std::string>();

    if (value.contains("email"))
        user.email = value["email"].get<std::string>();

    if (value.contains("password"))
        user.password = value["password"].get<std::string>();

    if (value.contains("nickname"))
        user.nickname = value["nickname"].get<std::string>();

    ParserObject res;

    res = user;

    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::from_client(parser_str);
        Print_struct::_user_t(user);
    }

    return res;
}

std::string ParserRegistrAuthImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    // {"registration":{"user_id":"value"}}

    nlohmann::json j;
    std::string res;

    if (!other.error.empty()) {
        j[type_response] = other.error;

        res = j.dump();

        return res;
    }

    user_t user = other.user;

    nlohmann::json value;

    if (!user.user_id.empty())
        value["user_id"] = user.user_id;

    if (!user.email.empty())
        value["email"] = user.email;

    if (!user.password.empty())
        value["password"] = user.password;

    if (!user.nickname.empty())
        value["nickname"] = user.nickname;

    j[type_response] = value;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::_user_t(user);
        Print_struct::from_processing(res);
    }

    return res;
}

