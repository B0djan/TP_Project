#pragma once

#include <cstdint>
#include <cassert>
#include <iostream>

#include "event.hpp"
#include "Structs.hpp"
#include "config.hpp"

enum { BITS = 8 * sizeof(uint8_t),
       NUMBER_CHUNKS = ((24 * 60 + BITS * MINIMUM_TRACKED_TIME - 1) / (BITS * MINIMUM_TRACKED_TIME))
};

class Day {
    uint8_t* storage = nullptr;
    size_t size = sizeof(uint8_t) * NUMBER_CHUNKS;

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
    size_t GetSize() const;
    void Print() const;
    void ShowDay() const;
    
    bool IsFree(Duration& begin_time, Duration& end_time);
};
