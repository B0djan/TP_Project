#pragma once

#include "day.hpp"
#include "structs.hpp"

class MeetUp {
    Day FreeTimeDay;
    std::set<Event> DayMeetUp;

public:
    MeetUp(const std::set<std::set<event_t>> &group_events);
    ~MeetUp() = default;

    Day GetFreeTimeDay();
    std::set<meetup_t> GetMeetUps();
    std::set<Event> GetDayMeetUp();
    void Set(const std::set<std::set<event_t>> &group_events);
};
