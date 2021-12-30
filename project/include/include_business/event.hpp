#pragma once

#include "../../include/include_business/duration.hpp"

#include "../../include/include_business/duration.hpp"

class Event {
    Duration begin;
    Duration end;
public:
    Event(Duration& begin, Duration& end);
    Event(std::string& begin, std::string& end);
    Duration GetBegin();
    Duration GetEnd();
};