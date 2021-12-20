#include "parse_json.hpp"

    user_t Json::GetUser(nlohmann::json& j) {

        user_t user;

        if (j.contains("user_id"))
            user.user_id = j["user_id"].get<std::string>();

        if (j.contains("login"))
            user.login = j["login"].get<std::string>();

        if (j.contains("password"))
            user.password = j["password"].get<std::string>();

        if (j.contains("nickname"))
            user.nickname = j["nickname"].get<std::string>();

        return user;
    }

    nlohmann::json ReturnUser(user_t& user) {

        nlohmann::json j {
            {"user_id", user.user_id},
            {"login", user.login},
            {"password", user.password},
            {"nickname", user.nickname}
        };

        return j;
    }