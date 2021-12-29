#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdint>

class Duration {
private:
    int hour;
    int min;
    int total;

    Duration(const int& h, const int& m) {
        total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }
public:

    Duration(const std::string &time) {
        std::stringstream stream(time);
        int h, m = 0;
        stream >> h;
        stream.ignore(1);
        stream >> m;
        total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }

    Duration(const char& time_interval) {
        total = int(time_interval * 15);
        hour = total / 60;
        min = total % 60;
    }

    int GetTimeInterval() {
        return (total + 14)/ 15;
    }

    void PrintDuration() {
        std::cout << std::setfill('0') << std::setw(2) << hour << ":";
        std::cout << std::setfill('0') << std::setw(2) << min << std::endl;
    }

    friend bool operator==(const Duration& lhs, const Duration& rhs);
    friend bool operator<(const Duration& lhs, const Duration& rhs);
    friend Duration operator+(const Duration& lhs, const Duration& rhs);
    friend Duration operator-(const Duration& lhs, const Duration& rhs);

};

bool operator==(const Duration& lhs, const Duration& rhs) {
    return lhs.total == rhs.total;
}
bool operator<(const Duration& lhs, const Duration& rhs) {
    return lhs.total < rhs.total;
}
Duration operator+(const Duration& lhs, const Duration& rhs) {
    Duration sum (lhs.hour + rhs.hour, lhs.min + rhs.min);
    return sum;
}
Duration operator-(const Duration& lhs, const Duration& rhs) {
    Duration sum (lhs.hour - rhs.hour, lhs.min - rhs.min);
    return sum;
}

int main() {

    std::cout << "// Test Duration(string) //:" << std::endl;
    std::string time1 = "10:45";
    std::string time2 = "08:50";
    Duration t1 (time1);
    Duration t2 (time2);
    std::cout << "t1 = ";
    t1.PrintDuration();
    std::cout << "t2 = ";
    t2.PrintDuration();

    std::cout << "// Test Duration<: //" << std::endl;
    if (t1 < t2)
        std::cout << "t1 < t2";
    else
        std::cout << "t2 < t1";
    std::cout << std::endl;

    std::cout << "// Test Duration + / -: //" << std::endl;
    Duration t3 = t1 + t2;
    std::cout << "t3 = ";
    t3.PrintDuration();
    Duration t6 = t1 - t2;
    std::cout << "t6 = ";
    t6.PrintDuration();

    std::cout << "// Test Duration(char): //" << std::endl;
    char two = 2;
    char eleven = 11;
    Duration t4 (two);
    Duration t5 (eleven);
    std::cout << "Expected 00:30 ... ";
    t4.PrintDuration();
    std::cout << "Expected 02:45 ... ";
    t5.PrintDuration();

    std::cout << "// Test GetTimeInterval(Duration): //" << std::endl;
    int _two = t4.GetTimeInterval();
    int _eleven = t5.GetTimeInterval();
    std::cout << "Expected 2 ... ";
    std:: cout << _two << std::endl;
    std::cout << "Expected 11 ... ";
    std::cout << _eleven << std::endl;

    return 0;
}
