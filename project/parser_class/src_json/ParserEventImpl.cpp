#include <ParserEventImpl.hpp>

ParserObject ParserEventImpl::StrToObject(const std::string& parser_str) const {

    /* 

    {
        "get_events":
        [
            {"user_id":"1", "event_name":"qwerty", "":"", "":"", },
            {},
            {}
        ]
    }

    */
    
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

        // (TODO) : ошибка вставки
        //events.insert(event);
    }

    ParserObject res;

    res.events = events;

    return res;
}

std::string ParserEventImpl::ObjectToStr(const ParserObject& other) const {

    contacts_t contacts = other.contacts;

    nlohmann::json value;

    nlohmann::json j;

    j["friends"] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    return res;
}