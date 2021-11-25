#include <iostream>
#include <nlohmann/json.hpp>

/*class Event {
private:
    size_t user_id = NULL;
    std::string event = NULL;
    std::string date = NULL;
    std::string begin = NULL;
    std::string end = NULL;
    size_t group_id = NULL;

public:
    size_t GetUserId() const { return user_id;}
    size_t GetGroupId() const { return group_id;}
    std::string GetEvent() { return event;}
    std::string GetDate() const { return date;}
    std::string GetBegin() const { return begin;};
    std::string GetEnd() const { return end;};
};*/

struct Event {
    size_t user_id = 0;
    std::string event = "";
    std::string date = "";
    std::string begin = "";
    std::string end = "";
    size_t group_id = 0;
};

void PrintEvent(Event& e) {
   std::cout << e.user_id << std::endl;
   std::cout << e.event << std::endl;
   std::cout << e.date << std::endl;
   std::cout << e.begin << std::endl;
   std::cout << e.end << std::endl;
   std::cout << e.group_id << std::endl;
}

int main() {
    std::string json_string = "{\"user_id\": 12345, \"event\": \"event_name\", \"date\": \"date_string\", \"begin\": \"15:45\", \"end\": \"17:15\", \"group_id\": 123}";
    nlohmann::json j1 = nlohmann::json::parse(json_string);
    Event event{};
    event.user_id = j1["user_id"].get<size_t>();
    event.event = j1["event"].get<std::string>();
    event.date = j1["date"].get<std::string>();
    event.begin = j1["begin"].get<std::string>();
    event.end = j1["end"].get<std::string>();
    event.group_id = j1["group_id"].get<size_t>();
    PrintEvent(event);
    return 0;
}