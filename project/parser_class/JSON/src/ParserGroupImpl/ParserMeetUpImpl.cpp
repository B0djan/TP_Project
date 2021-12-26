    #include <ParserGroupImpl.hpp>

ParserObject ParserMeetUpImpl::StrToObject(const std::string& parser_str) const {
    // {"add_event":{["user_id":"56","event_name":"breakfast","event_date":"01:06:2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"]}} TODO: Отредачить

    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];  // []

    std::set<meetup_t> meetups;

    for (auto& element : value)
    {
        meetup_t meetup;

        if(element.contains("user_id"))
        {
            meetup.group_id = element["user_id"].get<std::string>();
        };

        if(element.contains("event_name"))
        {
            meetup.meetup_name = element["event_name"].get<std::string>();
        };

        if(element.contains("event_date"))
        {
            meetup.date = element["event_date"].get<std::string>();
        };

        if(element.contains("description"))
        {
            meetup.description = element["description"].get<std::string>();
        };

        if(element.contains("time_begin"))
        {
            meetup.time_begin = element["time_begin"].get<std::string>();
        };

        if(element.contains("time_end"))
        {
            meetup.time_end = element["time_end"].get<std::string>();
        };

        meetups.insert(meetup);
    };

    ParserObject res;

    res = meetups;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::from_client(parser_str);
        for (std::set<meetup_t>::iterator it = meetups.begin(); it != meetups.end(); ++it) {
            Print_struct::meetup_t(*it);
        }
    }

    return res;
}

std::string ParserMeetUpImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    // {"add_event":{["user_id":"56","event_name":"breakfast","event_date":"01:06:2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"]}} TODO: Отредачить

    nlohmann::json j;
    std::string res;

    if (type_response == ADD_EVENT || type_response == WRITE_EVENT || type_response == RM_EVENT) {
        if (other.error.empty()) {
            j[type_response] = "OK";

            res = j.dump();
        } else  {
            j[type_response] = other.error;

            res = j.dump();
        }

        return res;
    }

    std::set<meetup_t> meetups = other.meetups;

    nlohmann::json json_events;

    if (!meetups.empty())
    {
        for (auto& meetup: meetups)
        {
            nlohmann::json json_event;

            if (!meetup.meetup_name.empty())
                json_event["meetup_name"] = meetup.meetup_name;

            if (!meetup.time_begin.empty())
                json_event["time_begin"] = meetup.time_begin;

            if (!meetup.time_end.empty())
                json_event["time_end"]   = meetup.time_end;

            if (!meetup.description.empty())
                json_event["description"] = meetup.description;

            if (!meetup.date.empty())
                json_event["event_date"] = meetup.date;

            json_events.push_back(json_event);
        }
    }

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        for (std::set<meetup_t>::iterator it = meetups.begin(); it != meetups.end(); ++it) {
            Print_struct::meetup_t(*it);
        }
        Print_struct::from_processing(res);
    }

    return res;
}
