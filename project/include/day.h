#pragma once

#include <stdio.h>
#include <assert.h>

#include <date.h>
#include <time.h>

class Day {
public:
    enum { BITS = sizeof(unsigned char)};
    Day();
    ~Day();
    void insert(unsigned char& time_interval, bool flag);
    void erase(unsigned char time_interval);
    // bool in(size_t elem) {
    //     //assert(elem < size);
    //     return storage[elem / BITS] >> (elem % BITS) & 1;
    // }
private:
    unsigned char *storage = nullptr;
    unsigned char *flag_storage = nullptr;
};