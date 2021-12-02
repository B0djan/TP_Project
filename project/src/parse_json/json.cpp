#include "json.h"

class Json {

    User_event GetEvent(std::string& s) {
        nlohmann::json j = nlohmann::json::parse(s);

        User_event ue;

        if (j.contains("user_id"))
            ue.user_id = j["user_id"];

        if (j.contains("event_name"))
            ue.event_name = j["event_name"];

        if (j.contains("date"))
            ue.date = j["date"];

        if (j.contains("time_begin"))
            ue.time_begin = j["time_begin"];

        if (j.contains("time_end"))
            ue.time_end = j["time_end"];
    }

    std::string ReturnEvent(User_event& event) {
        nlohmann::json j = {
            {"user_id", event.user_id},
            {"event_name", event.event_name},
            {"date", event.date},
            {"time_begin", event.time_begin},
            {"time_end", event.time_end},
        };
    }

    User_Registration_Data GetRegistration(std::string& s) {
        nlohmann::json j = nlohmann::json::parse(s);

        User_Registration_Data rd;

        if (j.contains("login"))
            rd.login = j["login"].get<std::string>();

        if (j.contains("passwor"))
            rd.password = j["password"].get<std::string>();

        return rd;
    }

    std::string ReturnRegistration(unsigned char& code) {
        nlohmann::json j = {"code", code};

        std::string serialized_string = j.dump();

        return serialized_string;
    }

    User_data GetPersonData(std::string& s) {
        nlohmann::json j = nlohmann::json::parse(s);
        
        User_data ud;

        if (j.contains("user_id"))
            ud.user_id = j["user_id"].get<size_t>();

        if (j.contains("email"))
            ud.email = j["email"].get<std::string>();

        if (j.contains("first_name"))
            ud.first_name = j["first_name"].get<std::string>();

        if (j.contains("surname"))
            ud.surname = j["surname"].get<std::string>();

        if (j.contains("age"))
            ud.age = j["age"].get<size_t>();

        if (j.contains("address")) {
            nlohmann::json j_address = nlohmann::json::parse(j["address"]);

            if (j_address.contains("building"))
                ud.address.building = j_address["building"].get<std::string>();

            if (j.contains("housing"))
                ud.address.housing = j_address["housing"].get<std::string>();

            if (j.contains("street"))
                ud.address.street = j_address["street"].get<std::string>();

            if (j.contains("city"))
                ud.address.city = j_address["city"].get<std::string>();

            if (j.contains("region"))
                ud.address.region = j_address["region"].get<size_t>();
            
            if (j.contains("index"))
                ud.address.index = j_address["index"].get<std::string>();

            if (j.contains("country"))
                ud.address.country = j_address["country"].get<std::string>();
        };

        return ud;       
    }

    std::string ReturnPersonData(User_data& data) {
        nlohmann::json j = {
            {"user_id", data.user_id},
            {"email", data.email},
            {"first_name", data.first_name},
            {"surname", data.surname},
            {"age", data.age},
            {"address", 
                {"building", data.address.building},
                {"street", data.address.street},
                {"city", data.address.city},
                {"region", data.address.region},
                {"index", data.address.index},
                {"country", data.address.country}
            }
        };

        std::string serialized_string = j.dump();

        return serialized_string;
    }
};
