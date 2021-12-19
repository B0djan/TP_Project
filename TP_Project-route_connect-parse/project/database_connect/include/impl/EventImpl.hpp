#pragma once

#include <set>

#include "pgbackend.hpp"

class AddEventImpl {
public:
    int AddEvent(event_t& e);
};

class WriteEventImpl {
public:
    std::set<event_t> ShowEvents(event_t& e);
};

class RmEventImpl {
public:
    int RmEvent(event_t& e);

};
