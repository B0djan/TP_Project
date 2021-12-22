#include <ParserRegistrAuthImpl.hpp>

ParserObject ParserRegistrAuthImpl::StrToObject(const std::string& parser_str) const {
    
    // {"registration":{"login":"mars444","password":"qqqqqqqqqqqqqqqq"}}

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

    return res;
}

std::string ParserRegistrAuthImpl::ObjectToStr(const ParserObject& other) const {

    user_t user = other.user;

    nlohmann::json value;

    value["user_id"] = user.user_id;

    value["email"] = user.email;

    value["password"] = user.password;

    value["nickname"] = user.nickname;

    nlohmann::json j;

    j["registration"] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    return res;
}

