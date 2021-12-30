#pragma once

#include <stdio.h>
#include <assert.h>
#include <map>

#include "../../include/include_business/event.hpp"

#define NUMBER_INTERVAL 12

enum { BITS = sizeof(char) };

class Day {
    char *storage = nullptr;
public:
    Day();
    ~Day();

    char* GetStorage() const;

    void UnionDays(Day& added_day);

    void InvertDay();

    void InsertEvent(Event& event);

    void InsertEvent(Duration& begin_time, Duration& end_time);

    void EraseEvent(Duration& begin_time, Duration& end_time);
    
    bool IsFree(Duration& begin_time, Duration& end_time);

};