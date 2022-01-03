#include "../../include/include_business/function.hpp"

Day GetFreeDay(std::set<std::set<event_t>> group_events) {
    Day free_time;
    for (auto day: group_events) {
        Day busy_day;
        for (auto event: day) {
            Event user_event (event.time_begin, event.time_end);
            busy_day.InsertEvent(user_event);
        }
        free_time.UnionDays(busy_day);
    }
    free_time.InversionDay();
    return free_time;
}

//  day to set of duration

//  set of duration to set of meetups

