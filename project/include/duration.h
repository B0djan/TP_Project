#pragma once

#include <string>
#include <sstream>

class Duration {
private:
    int hour;
    int min;

public:
    Duration(std::string& time);
    
    unsigned char GetTimeInterval();

    void PrintDuration();
};