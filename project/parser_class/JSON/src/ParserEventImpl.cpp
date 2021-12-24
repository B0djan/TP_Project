#include <ParserEventImpl.hpp>

ParserObject ParserEventImpl::StrToObject(const std::string& parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];  // []

    std::set<event_t> events;

   // {"add_event":{["user_id":"56","event_name":"breakfast","event_date":"01:06:2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"]}}

    for (auto& element : value)
    {
        event_t event;

        if(element.contains("user_id"))
        {
            event.user_id = element["user_id"].get<std::string>();
        };

        if(element.contains("event_name"))
        {
            event.event_name = element["event_name"].get<std::string>();
        };

        if(element.contains("event_date"))
        {
            event.date = element["event_date"].get<std::string>();
        };

        if(element.contains("description"))
        {
            event.description = element["description"].get<std::string>();
        };

        if(element.contains("time_begin"))
        {
            event.time_begin = element["time_begin"].get<std::string>();
        };
        
        if(element.contains("time_end"))
        {
            event.time_end = element["time_end"].get<std::string>();
        };

        events.insert(event);
    };

    ParserObject res;

    res.events = events;

    //  Отладка
    if (global_key_test_parser) {
        std::cout << parser_str << std::endl;
        for (std::set<event_t>::iterator it = events.begin(); it != events.end(); ++it) {
            std::cout << (*it).date << std::endl;
            std::cout << (*it).time_begin << std::endl;
            std::cout << (*it).time_end << std::endl;
            std::cout << (*it).description << std::endl;
            std::cout << (*it).user_id << std::endl;
        }
    }

    return res;
}

std::string ParserEventImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {

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
        };
    }

    nlohmann::json j;

    j[type_response] = json_events;

    std::string res = j.dump();

    //  Отладка
    if (global_key_test_parser) {
        for (std::set<event_t>::iterator it = events.begin(); it != events.end(); ++it) {
            std::cout << (*it).date << std::endl;
            std::cout << (*it).time_begin << std::endl;
            std::cout << (*it).time_end << std::endl;
            std::cout << (*it).description << std::endl;
            std::cout << (*it).user_id << std::endl;
        }
        std::cout << res << std::endl;
    }

    return res;
};