#pragma once

#include <stdio.h>
#include <assert.h>
#include <map>

#include "duration.h"

class Day {

private:
    unsigned char *storage = nullptr;
    unsigned char *flag_storage = nullptr;
public:

    Day();
    ~Day();

    unsigned char* GetStorage() const;
    unsigned char* FlagStorage() const;

    void UnionDays(Day& aded_day);

    void InvertDay(Day& busy_day);

    void InsertEvent(Duration& begin_time, Duration& end_time, bool flag);

    void EraseEvent(Duration& begin_time, Duration& end_time);
    
    bool IsFree(Duration& begin_time, Duration& end_time);

};