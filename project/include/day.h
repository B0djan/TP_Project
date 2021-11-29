#pragma once

#include <stdio.h>
#include <assert.h>
#include <map>

#include "date.h"
#include "duration.h"
#include "user.h"

class Day {
public:
    enum { BITS = sizeof(unsigned char)};

    Day();
    ~Day();

    void InsertEvent(Duration& begin_time, Duration& end_time, bool flag);

    void EraseEvent(Duration& begin_time, Duration& end_time, bool flag);
    
    bool IsFree(Duration& begin_time, Duration& end_time);

private:
    unsigned char *storage = nullptr;
    unsigned char *flag_storage = nullptr;
};