#include <string>

#include "../../include/include_business/event.hpp"


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
std::set<int> Event::GetIntervals() {
    std::set<int> intervals;
    for (auto i = this->GetBegin().GetNumberInterval(); i < this->GetEnd().GetNumberInterval(); i++)
        intervals.insert(i);
    return intervals;
}
