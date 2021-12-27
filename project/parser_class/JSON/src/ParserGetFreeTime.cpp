#include <ParserEventImpl.hpp>

#include <iostream>

ParserObject /*Класс*/::StrToObject(const std::string& parser_str) const {
    // {"create_group":{"title":"Texnosrac","members":["56"]}};

    // {"get_meetup": {"title":"Texnosrack", "date":"10-20-2021"}}
    //{"get_meetup":[{"time_begin" ,"time_end"}]};

    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    group_t group;

    {
        if (value.contains("title"))
        {
            group.title = value["title"].get<std::string>();
        }

        if (value.contains("date")) {
            for (auto &element_in : value["date"])
            {
                group.members.insert(element_in.get<std::string>());
            }
        }
    }

    ParserObject res;

    std::set<group_t> groups;

    groups.insert(group);

    res = groups;

    return res;
}


std::string /*Класс*/::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    nlohmann::json j;

    std::string res;

    std::set<event_t> events = other.events;

    nlohmann::json json_events;

    for (auto& event: events) 
    {
        nlohmann::json json_event;

        if (!event.time_begin.empty())
            json_event["time_begin"] = event.time_begin;

        if (!event.time_end.empty())
            json_event["time_end"]   = event.time_end;

        json_events.push_back(json_event);
    }

    j[type_response] = json_events;

    res = j.dump();

    return res;
}