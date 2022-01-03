#pragma once

#include <set>
#include "../../include/include_business/duration.hpp"

class Event {
    Duration begin;
    Duration end;
public:
    Event(Duration& begin, Duration& end);
    Event(const std::string& begin, const std::string& end);

    Duration GetBegin();
    Duration GetEnd();

    std::set<int> GetIntervals();
};