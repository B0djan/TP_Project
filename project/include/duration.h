#pragma once

#include <iostream>
#include <string>
#include <sstream>

class Duration {
private:
    int hour;
    int min;

public:
    Duration(unsigned char& t);
    
    Duration(const std::string& time);
    
    unsigned char GetTimeInterval();

    void PrintDuration();
};