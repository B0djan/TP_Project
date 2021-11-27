#pragma once

#include <string>
#include <sstream>

class Time {
private:
    int hour;
    int min;

public:
    Time(std::string& time);

    void PrintTime();
};