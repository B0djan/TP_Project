#pragma once

#include <stdio.h>
#include <assert.h>

#include <date.h>
#include <duration.h>

class Day {
public:
    enum { BITS = sizeof(unsigned char)};
    Day();
    ~Day();
    void InsertEvent(unsigned char& time_interval, bool flag);
    void EraseEvent(unsigned char time_interval);

private:
    unsigned char *storage = nullptr;
    unsigned char *flag_storage = nullptr;
};