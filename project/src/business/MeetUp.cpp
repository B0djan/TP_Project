#include "../../include/include_business/MeetUp.hpp"

MeetUp::MeetUp(std::set<std::set<event_t>> group_events) {
    for (auto day: group_events) {
        Day busy_day;
        for (auto event: day) {
            Event user_event (event.time_begin, event.time_end);
            busy_day.InsertEvent(user_event);
        }
        FreeTimeDay.UnionDays(busy_day);
    }
}

Day MeetUp::Get() {
    return FreeTimeDay;
}

void MeetUp::Set(std::set<std::set<event_t>> group_events) {
    this->FreeTimeDay.Free();
    for (auto day: group_events) {
        Day busy_day;
        for (auto event: day) {
            Event user_event (event.time_begin, event.time_end);
            busy_day.InsertEvent(user_event);
        }
        this->FreeTimeDay.UnionDays(busy_day);
    }

}