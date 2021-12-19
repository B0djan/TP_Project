#include "parse_json.hpp"

    user_t Json::GetUser(nlohmann::json& j) {

        user_t user;

        if (j.contains("user_id"))
            user.email = j["user_id"].get<std::string>();

        if (j.contains("email"))
            user.email = j["email"].get<std::string>();

        if (j.contains("passwor"))
            user.password = j["password"].get<std::string>();

        if (j.contains("nickname"))
            user.nickname = j["nickname"].get<std::string>();

        return user;
    }

    nlohmann::json Json::ReturnUser(user_t& user) {

        nlohmann::json j {
            {"user_id", user.user_id},
            {"email", user.email},
            {"password", user.password},
            {"nickname", user.nickname}
        };

        return j;
    }