#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "time.h"

class Time {
private:
    int hour;
    int min;

public:
    Time(const std::string& time) {
        std::stringstream stream(time);
        int h, m = 0;
        stream >> h;
        stream.ignore(1);
        stream >> m;
        int total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }

    unsigned char GetTimeInterval(Time& t) {
        int total = hour * 60 * min;
        return (unsigned char)(total / 15 + 1);
    }

    void PrintTime() {
        std::cout << hour << ":";
        std::cout << min << std::endl;
    }
};

int main() {
    std::string str = "10:15";
    Time t = {str};
    t.PrintTime();
}