#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>

#include "date.h"
#include "time.h"
#include "event.h"

class Event {
    size_t user_id = 0;
    std::string event = "";
    std::string date = "";
    std::string begin = "";
    std::string end = "";
    size_t group_id = 0;
    bool flag = false; // по умолчанию нельзя двигать двигать

public:
    Event(std::string& s) {
        nlohmann::json j = nlohmann::json::parse(s);
        user_id = j["user_id"].get<size_t>();
        event = j["event"].get<std::string>();
        date = j["date"].get<std::string>();
        begin = j["begin"].get<std::string>();
        end = j["end"].get<std::string>();
        group_id = j["group_id"].get<size_t>();
    }

    // std::ostream& operator<<(std::ostream& stream) {
    //     stream << "user_id: " << user_id << std::endl;
    //     stream << "event: " << event << std::endl;
    //     stream << "date: " << date << std::endl;
    //     stream << "begin: " << begin << std::endl;
    //     stream << "end: " << end << std::endl;
    //     stream << "group_id: " << group_id << std::endl;
    //     return stream;
    // }

    size_t GetUserId() const { return user_id;}
    size_t GetGroupId() const { return group_id;}
    std::string GetEvent() { return event;}
    std::string GetDate() const { return date;}
    std::string GetBegin() const { return begin;};
    std::string GetEnd() const { return end;};
};

int main() {
    std::string json_string = "{\"user_id\": 12345, \"event\": \"event_name\", \"date\": \"date_string\", \"begin\": \"15:45\", \"end\": \"17:15\", \"group_id\": 123}";
    Event event {json_string};
    //std::cout << event << std::endl;
    return 0;
}