#include "parse_json.hpp"

    addres_data_t Json::GetAddresData(nlohmann::json& j) {

        addres_data_t addres_data;

        if(j.contains("user_id"))
            addres_data.user_id = j["user_id"].get<std::string>();

        if (j.contains("building"))
            addres_data.building = j["building"].get<std::string>();

        if (j.contains("housing"))
            addres_data.housing = j["housing"].get<std::string>();

        if (j.contains("street"))
            addres_data.street = j["street"].get<std::string>();

        if (j.contains("city"))
            addres_data.city = j["city"].get<std::string>();

        if (j.contains("district"))
            addres_data.district = j["district"].get<std::string>();
        
        if (j.contains("index"))
            addres_data.index = j["index"].get<std::string>();

        if (j.contains("country"))
            addres_data.country = j["country"].get<std::string>();
    }

    nlohmann::json Json::ReturnAddresData(addres_data_t& addres_data) {

        nlohmann::json j {
            {"user_id", addres_data.user_id},
            {"building", addres_data.building},
            {"housing", addres_data.housing},
            {"street", addres_data.street},
            {"city", addres_data.city},
            {"district", addres_data.district},
            {"index", addres_data.index},
            {"country", addres_data.country}
        };

        return j;
    };