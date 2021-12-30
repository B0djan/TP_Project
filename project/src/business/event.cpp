#include <string>

#include "../../include/include_business/event.hpp"


Event::Event(Duration& begin, Duration& end) {
    this->begin = begin;
    this->end = end;
}
Event::Event(std::string& begin, std::string& end) {
    this->begin = Duration(begin);
    this->end = Duration(end);
}
Duration Event::GetBegin() {
    return begin;
}
Duration Event::GetEnd() {
    return end;
}
