#include "date.h"

    Date::Date(int& new_day, int& new_month, int& new_year) {
        day = new_day;
        month = new_month;
        year = new_year;
    }

    Date Date::GetDate(std::string& date_string) {
        std::stringstream stream(date_string);
        int d, m, y = 0;
        stream >> d;
        stream.ignore(1);
        stream >> m;
        stream.ignore(1);
        stream >> y;
        return Date {d, m, y};           
    }
    
    int Date::GetDay() const {return day;}
    int Date::GetMonth() const {return month;}
    int Date::GetYear() const {return year;}

    void Date::PrintDate() {
        std::cout << GetDay() << "." << GetMonth() << "." << GetYear() << "\n";
    }