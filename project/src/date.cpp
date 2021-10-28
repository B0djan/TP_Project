#include <iostream>
#include <sstream>
#include <time.h>
#include <string>
#include <iomanip>

class Date {
    private:
        int day;
        int month;
        int year;
    public:
        Date(int& new_day, int& new_month, int& new_year) {
            day = new_day;
            month = new_month;
            year = new_year;
        }
        Date() {
            time_t t = time(NULL);
            struct tm *time = localtime(&t);
            std::stringstream s;
            day = time->tm_mday;
            month = time->tm_mon + 1;
            year = time->tm_year + 1900;
        }
        int GetDay() const {return day;}
        int GetMonth() const {return month;}
        int GetYear() const {return year;}

        void PrintDate() {
            std::cout << GetDay() << "." << GetMonth() << "." << GetYear() << "\n";
        }
};

Date ReadDate(std::istream& stream) {
    int d = 0;
    int m = 0;
    int y = 0;
    stream >> d;
    stream.ignore();
    stream >> m;
    stream.ignore(1);
    stream >> y;
    return Date {d,m,y};
}

int main(void) {
    std::string str;
    std::cin >> str;
    std::stringstream s;
    s << str;
    Date date = ReadDate(s);
    Date date2 = Date();
    date.PrintDate();
    date2.PrintDate();
    // time_t t = time(NULL);
    // struct tm *time = localtime(&t);
    // std::stringstream s;
    // s << std::setfill('0');
    // s << std::setw(2) << time->tm_mday << "." << std::setw(2) << time->tm_mon << "." << std::setw(4) << time->tm_year + 1900 << "\n";
    // Date date = ReadDate(s);
    // date.PrintDate();
    return 0;
}