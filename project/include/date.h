#pragma once

#include <string>
#include <iostream>

class Date {
        int day;
        int month;
        int year;
    public:
        Date(int& new_day, int& new_month, int& new_year);

        Date GetDate(std::string& date_string);

        int GetDay() const {return day;}
        int GetMonth() const {return month;}
        int GetYear() const {return year;}

        void PrintDate() {
            std::cout << GetDay() << "." << GetMonth() << "." << GetYear() << "\n";
        }

        Date GetStringDate() {
            
        }
};
