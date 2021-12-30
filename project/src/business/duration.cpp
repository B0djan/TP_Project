#include "../../include/include_business/duration.hpp"

Duration::Duration(const int& h, const int& m) {
    total = h * 60 + m;
    hour = total / 60;
    min = total % 60;
}

Duration::Duration(const std::string &time) {
    std::stringstream stream(time);
    int h, m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;
    total = h * 60 + m;
    hour = total / 60;
    min = total % 60;
}

Duration::Duration(const int& number) {
    total = number * 15;
    hour = total / 60;
    min = total % 60;
}

int Duration::GetNumberInterval() const {
    return (total) / 15;
}

// как вывести объект??;
std::string Duration::GetTimeString() const{
    std::stringstream stream;
    stream << this;
    return stream.str();
}
std::ostream& operator<< (std::ostream& out, const Duration& duration) {
    out << std::setfill('0') << std::setw(2) << duration.hour << ':';
    out << std::setfill('0') << std::setw(2) << duration.min;
    return out;
}
bool operator==(const Duration& lhs, const Duration& rhs) {
    return lhs.total == rhs.total;
}
bool operator<(const Duration& lhs, const Duration& rhs) {
    return lhs.total < rhs.total;
}
Duration operator+(const Duration& lhs, const Duration& rhs) {
    return Duration (lhs.hour + rhs.hour, lhs.min + rhs.min);
}
Duration operator-(const Duration& lhs, const Duration& rhs) {
    return Duration (lhs.hour - rhs.hour, lhs.min - rhs.min);
}