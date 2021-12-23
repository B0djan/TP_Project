#include <ParserRegistrAuthImpl.hpp>


#include <iostream>

ParserObject ParserRegistrAuthImpl::StrToObject(const std::string& parser_str) const {
    //  std::cout << parser_str << "    - parser_str\n" << std::endl;
    
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

    //  std::cout << user.user_id << " " << user.email << " " << user.password << " " << user.nickname << " \n" << std::endl;

    ParserObject res;

    res = user;

    return res;
}

std::string ParserRegistrAuthImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {

    user_t user = other.user;

    nlohmann::json value;

    if (user.user_id != "")
        value["user_id"] = user.user_id;

    if (user.email != "")
        value["email"] = user.email;

    if (user.password != "")
        value["password"] = user.password;

    if (user.nickname != "")
        value["nickname"] = user.nickname;

    nlohmann::json j;

    j[type_response] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    return res;
}

