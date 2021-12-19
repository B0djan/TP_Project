#include "parse_json.hpp"

   event_t Json::GetEvent(nlohmann::json& j) {

        event_t event;

        if (j.contains("user_id"))
            event.user_id = j["user_id"];

        if (j.contains("event_name"))
            event.event_name = j["event_name"];

        if (j.contains("date"))
            event.date = j["date"];

        if (j.contains("description"))
            event.date = j["description"];

        if (j.contains("time_begin"))
            event.time_begin = j["time_begin"];

        if (j.contains("time_end"))
            event.time_end = j["time_end"];

        return event;
    }

    nlohmann::json Json::ReturnEvent(event_t& event) {
        
        nlohmann::json j = {
            {"user_id", event.user_id},
            {"event_name", event.event_name},
            {"date", event.date},
            {"description", event.description},
            {"time_begin", event.time_begin},
            {"time_end", event.time_end},
        };

        return j;
    }