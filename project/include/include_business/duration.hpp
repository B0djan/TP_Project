#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Duration {
    size_t hour;
    size_t min;
    size_t total;

    Duration(const size_t& h, const size_t& m);
public:
    Duration() = default;
    Duration(const std::string &time);
    Duration(const size_t& number);
    Duration(const Duration &copy);

    int GetNumberInterval() const;
    std::string GetTimeString() const;
    Duration& operator= (const Duration& dur);

    friend std::ostream& operator<< (std::ostream &out, const Duration& duration);
    friend bool operator== (const Duration& lhs, const Duration& rhs);
    friend bool operator< (const Duration& lhs, const Duration& rhs);
    friend Duration operator+ (const Duration& lhs, const Duration& rhs);
    friend Duration operator- (const Duration& lhs, const Duration& rhs);
};
