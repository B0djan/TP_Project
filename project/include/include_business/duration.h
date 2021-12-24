#pragma once

#include <iostream>
#include <string>
#include <sstream>

class Duration {
private:
    int hour;
    int min;
public:
    
    Duration(const std::string& time);
    
    unsigned char GetTimeInterval();

    void PrintDuration();
};