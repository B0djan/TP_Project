#include "event.hpp"

Event::Event(Duration& begin, Duration& end) {
    this->begin = begin;
    this->end = end;
}

Event::Event(const std::string& begin, const std::string& end) {
    this->begin = Duration(begin);
    this->end = Duration(end);
}

Duration Event::GetBegin() {
    return begin;
}

Duration Event::GetEnd() {
    return end;
}

void Event::Print() {
    std::cout << "time_begin = " << this->GetBegin() << '\t' << "time_end = " << this->GetEnd() << '\n';
}

std::set<size_t> Event::GetIntervals() {
    std::set<size_t> intervals;

    for (size_t i = GetBegin().GetNumberInterval(); i < GetEnd().GetNumberInterval(); i++)
        intervals.insert(i);
    return intervals;
}
bool operator< (const Event& lhs, const Event& rhs) {
    if (lhs.begin == rhs.end) {
        return lhs.end < rhs.end;
    }

    return lhs.begin < rhs.begin;
}