#pragma once

#include <stdio.h>
#include <assert.h>
#include <map>

#include "duration.h"

class Day {

private:
    unsigned char *storage = nullptr;
public:

    Day();
    ~Day();

    unsigned char* GetStorage() const;

    void UnionDays(Day& aded_day);

    void InvertDay(Day& busy_day);

    void InsertEvent(Duration& begin_time, Duration& end_time);

    void EraseEvent(Duration& begin_time, Duration& end_time);
    
    bool IsFree(Duration& begin_time, Duration& end_time);

};