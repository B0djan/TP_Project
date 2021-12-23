#include <ParserEventImpl.hpp>

ParserObject ParserEventImpl::StrToObject(const std::string& parser_str) const {
    
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
        };

        if(element.contains("event_name"))
        {
            event.event_name = element["event_name"].get<std::string>();
        };

        if(element.contains("date"))
        {
            event.date = element["date"].get<std::string>();
        };

        if(element.contains("description"))
        {
            event.user_id = element["description"].get<std::string>();
        };

        if(element.contains("time_begin"))
        {
            event.user_id = element["time_begin"].get<std::string>();
        };
        
        if(element.contains("time_end"))
        {
            event.user_id = element["time_end"].get<std::string>();
        };

        // events.insert(event);
    };

    ParserObject res;

    res.events = events;

    return res;
}

std::string ParserEventImpl::ObjectToStr(const ParserObject& other) const {

    std::set<event_t> events = other.events;

    nlohmann::json json_events;

    if (!events.empty()) 
    {
        for (auto& event: events) 
        {
            nlohmann::json json_event;

            if (event.event_name != "")
                json_event["event_name"] = event.event_name;
            
            if (event.time_begin != "")
                json_event["time_begin"] = event.time_begin;

            if (event.time_end != "")
                json_event["time_end"]   = event.time_end;

            if (event.description != "")
                json_event["description"] = event.description;
            
            if (event.date != "")
                json_event["date"] = event.date;

            json_events.push_back(json_event);
        };
    }

    nlohmann::json j;

    j["events"] = json_events;

    std::string res = j.dump();

    return res;
};