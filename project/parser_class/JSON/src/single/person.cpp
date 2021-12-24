#include "parse_json.hpp"

    personal_data_t Json::GetPersonData(nlohmann::json& j) {
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

        return personal_data;
    }

    nlohmann::json Json::ReturnPersonData(personal_data_t& personal_data) {
        
        nlohmann::json j = {
            {"user_id", personal_data.user_id},
            {"first_name", personal_data.first_name},
            {"surname", personal_data.surname},
            {"age", personal_data.age},
            {"phone_number", personal_data.phone_number},
            {"status", personal_data.status},
            {"label", personal_data.label},
            {"description", personal_data.description}
        };

        return j;
    }
