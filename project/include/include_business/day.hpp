#pragma once

#include <cstdint>
#include <cassert>

#include "../../include/include_business/event.hpp"
#include "../../include/include_business/structs.hpp"

#define NUMBER_INTERVAL 12

enum { BITS = sizeof(uint8_t) * 8 };

class Day {
    uint8_t* storage = nullptr;
    size_t size = sizeof(uint8_t) * NUMBER_INTERVAL;

public:
    Day();
    Day(const Day& day);
    ~Day();

    void InsertEvent(Event& event);
    void EraseEvent(Duration& begin_time, Duration& end_time);
    void Free();
    bool IntervalIs(const uint8_t &number) const;
    void InversionDay();
    void UnionDays(Day& added_day);

    uint8_t* GetStorage() const;
    int GetSize() const;
    void Print() const;
    void ShowDay() const;
    
    bool IsFree(Duration& begin_time, Duration& end_time);
};
