#include <ParserEventImpl.hpp>

ParserObject ParserEventImpl::StrToObject(const std::string& parser_str) const {
    // {"add_event":{["user_id":"56","event_name":"breakfast","event_date":"01:06:2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"]}}


    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];  // []

    std::set<event_t> events;

    for (auto& element : value)
    {
        event_t event;

        if(element.contains("user_id"))
        {
            event.user_id = element["user_id"].get<std::string>();
        }

        if(element.contains("event_name"))
        {
            event.event_name = element["event_name"].get<std::string>();
        }

        if(element.contains("event_date"))
        {
            event.date = element["event_date"].get<std::string>();
        }

        if(element.contains("description"))
        {
            event.description = element["description"].get<std::string>();
        }

        if(element.contains("time_begin"))
        {
            event.time_begin = element["time_begin"].get<std::string>();
        }
        
        if(element.contains("time_end"))
        {
            event.time_end = element["time_end"].get<std::string>();
        }

        events.insert(event);
    }

    ParserObject res;

    res = events;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Debugging::print_from_client(parser_str);
        for (std::set<event_t>::iterator it = events.begin(); it != events.end(); ++it) {
            Debugging::print_event_t(*it);
        }
    }

    return res;
}

std::string ParserEventImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
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

    std::set<event_t> events = other.events;

    nlohmann::json json_events;

    if (!events.empty()) 
    {
        for (auto& event: events) 
        {
            nlohmann::json json_event;

            if (!event.event_name.empty())
                json_event["event_name"] = event.event_name;
            
            if (!event.time_begin.empty())
                json_event["time_begin"] = event.time_begin;

            if (!event.time_end.empty())
                json_event["time_end"]   = event.time_end;

            if (!event.description.empty())
                json_event["description"] = event.description;
            
            if (!event.date.empty())
                json_event["event_date"] = event.date;

            json_events.push_back(json_event);
        }
    }

    j[type_response] = json_events;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        for (std::set<event_t>::iterator it = events.begin(); it != events.end(); ++it) {
            Debugging::print_event_t(*it);
        }
        Debugging::print_from_processing(res);
    }

    return res;
}