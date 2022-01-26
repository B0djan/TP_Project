#include "duration.hpp"
#include "config.hpp"

Duration::Duration(const size_t& h, const size_t& m) {
    total = h * 60 + m;

    hour = total / 60;

    min = total % 60;
}

Duration::Duration(const std::string &time) {
    std::stringstream stream(time);

    size_t h, m = 0;
    stream >> h;
    stream.ignore(1);
    stream >> m;

    total = h * 60 + m;

    hour = total / 60;

    min = total % 60;
}

Duration::Duration(const size_t& number) {
    total = number * 15;

    hour = total / 60;

    min = total % 60;
}

Duration::Duration (const Duration &copy) :
    hour(copy.hour), min(copy.min), total(copy.total){
}

int Duration::GetNumberInterval() const {
    return (total) / 15;
}

std::string Duration::GetTimeString() const{
    std::stringstream stream;

    stream << std::setfill('0') << std::setw(2) << this->hour << ':';

    stream << std::setfill('0') << std::setw(2) << this->min;

    return stream.str();
}
std::ostream& operator<< (std::ostream& out, const Duration& duration) {
    out << std::setfill('0') << std::setw(2) << duration.hour << ':';

    out << std::setfill('0') << std::setw(2) << duration.min;

    return out;
}

Duration& Duration::operator= (const Duration& dur) {
    hour = dur.hour;

    min = dur.min;

    total = dur.total;

    return *this;
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