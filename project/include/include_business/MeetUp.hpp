#pragma once

#include "day.hpp"
#include "structs.hpp"

class MeetUp {
    Day FreeTimeDay;
public:
    MeetUp(std::set<std::set<event_t>> group_events);

    Day Get();
    void Set(std::set<std::set<event_t>> group_events);
};

