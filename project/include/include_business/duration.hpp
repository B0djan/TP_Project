#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Duration {
    int hour;
    int min;
    int total;

    Duration(const int& h, const int& m);
public:
    Duration(const std::string &time);
    Duration(const int& number);

    int GetNumberInterval() const;
    std::string GetTimeString() const;

    friend std::ostream& operator<< (std::ostream &out, const Duration& duration);

    friend bool operator== (const Duration& lhs, const Duration& rhs);
    friend bool operator< (const Duration& lhs, const Duration& rhs);
    friend Duration operator+ (const Duration& lhs, const Duration& rhs);
    friend Duration operator- (const Duration& lhs, const Duration& rhs);
};
