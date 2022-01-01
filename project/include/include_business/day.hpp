#pragma once

#include <stdio.h>
#include <assert.h>
#include <map>
#include <cstdint>

#include "../../include/include_business/event.hpp"

#define NUMBER_INTERVAL 6

enum { BITS = sizeof(uint16_t) * 8 };

class Day {
    uint16_t* storage = nullptr;
    int size = sizeof(uint16_t) * NUMBER_INTERVAL;
public:
    Day();
    ~Day();

    uint16_t* GetStorage() const;

    int GetSize() const;

    void Print() const;

    void ShowDay() const;

    void UnionDays(Day& added_day);

    void InversionDay();

    void InsertEvent(Event& event);

    void EraseEvent(Duration& begin_time, Duration& end_time);
    
    bool IsFree(Duration& begin_time, Duration& end_time);

    bool IntervalIs(uint16_t number) const;

};