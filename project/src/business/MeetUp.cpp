#include "../../include/include_business/MeetUp.hpp"

MeetUp::MeetUp(std::set<std::set<event_t>> &group_events) {
    for (auto day: group_events) {
        for (auto event: day) {
            Event user_event (event.time_begin, event.time_end);
            FreeTimeDay.InsertEvent(user_event);
        }
    }
}

MeetUp::~MeetUp() {
    std::cout << "Удалил meetup" << std::endl;
}

Day MeetUp::Get() {
    return FreeTimeDay;
}

void MeetUp::Set(std::set<std::set<event_t>> group_events) {
    FreeTimeDay.Free();
    for (auto day: group_events) {
        for (auto event: day) {
            Event user_event (event.time_begin, event.time_end);
            FreeTimeDay.InsertEvent(user_event);
        }
    }
}