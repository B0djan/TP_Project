#include "parse_json.hpp"

   meetup_t Json::GetMeetup(nlohmann::json& j) {

        meetup_t meetup;

        if (j.contains("group_id"))
            meetup.group_id = j["group_id"];

        if (j.contains("event_name"))
            meetup.event_name = j["event_name"];

        if (j.contains("date"))
            meetup.date = j["date"];

        if (j.contains("description"))
            meetup.date = j["description"];

        if (j.contains("time_begin"))
            meetup.time_begin = j["time_begin"];

        if (j.contains("time_end"))
            meetup.time_end = j["time_end"];

        return meetup;
    }

    nlohmann::json Json::ReturnMeetup(meetup_t& meetup) {
        
        nlohmann::json j = {
            {"group_id", meetup.group_id},
            {"event_name", meetup.event_name},
            {"date", meetup.date},
            {"description", meetup.description},
            {"time_begin", meetup.time_begin},
            {"time_end", meetup.time_end},
        };

        return j;
    }