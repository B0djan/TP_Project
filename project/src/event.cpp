#include "event.h"

    Event::Event(std::string& s) {
        nlohmann::json j = nlohmann::json::parse(s);
        user_id = j["user_id"].get<size_t>();
        event = j["event"].get<std::string>();
        date = j["date"].get<std::string>();
        begin = j["begin"].get<std::string>();
        end = j["end"].get<std::string>();
        group_id = j["group_id"].get<size_t>();
    }

    size_t Event::GetUserId() const { return user_id;}
    size_t Event::GetGroupId() const { return group_id;}
    std::string Event::GetEvent() const{ return event;}
    std::string Event::GetDate() const { return date;}
    std::string Event::GetBegin() const { return begin;};
    std::string Event::GetEnd() const { return end;};
