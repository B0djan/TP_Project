#pragma once

#include <string>
#include <iostream>
#include <sstream>

class Date {
        int day;
        int month;
        int year;
    public:
        Date(int& new_day, int& new_month, int& new_year);

        Date GetDate(std::string& date_string);
        Date GetStringDate();

        int GetDay();
        int GetMonth();
        int GetYear();

        void PrintDate();
};
