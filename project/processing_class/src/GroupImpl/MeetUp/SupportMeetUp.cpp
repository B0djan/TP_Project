#include <sstream>

#include <GroupImpl.hpp>

// support class Duration
SearchFreeTimeImpl::Duration::Duration(const std::string& time) {
    std::stringstream stream(time);

    int h, m = 0;

    stream >> h;
    stream.ignore(1);
    stream >> m;

    int total = h * 60 + m;

    hour = total / 60;
    min = total % 60;
}

unsigned char SearchFreeTimeImpl::Duration::GetTimeInterval() {
    int total = hour * 60 * min;

    return (unsigned char)(total / 15 + 1);
}




//  support class Day
unsigned char* SearchFreeTimeImpl::Day::GetStorage() const {
    unsigned char* res;
    return res;
}

void SearchFreeTimeImpl::Day::UnionDays(Day& added_day) {

}

void SearchFreeTimeImpl::Day::InvertDay(Day& busy_day) {

}

void SearchFreeTimeImpl::Day::InsertEvent(Duration& begin_time, Duration& end_time) {

}

void SearchFreeTimeImpl::Day::EraseEvent(Duration& begin_time, Duration& end_time) {

}

bool SearchFreeTimeImpl::Day::IsFree(Duration& begin_time, Duration& end_time) {
    return true;
}

//  Support methods
std::vector<std::set<event_t>> SearchFreeTimeImpl::GetData(group_t) {
    std::vector<std::set<event_t>> res;
    return res;
}

std::set<meetup_t> SearchFreeTimeImpl::GetMeetUps(std::vector<std::set<event_t>>) {
    /*
     Day free_day;
        for (auto member: members) {
            Day user_day;
            for (auto event: events) {
                user_day.InsertEvent(begin, end);
            }
            free_day.UnionDays(user_day);
        }
        free_day.InvertDay();
        set<meetup> res = free_day.SeachMeetUps();
     */
    std::set<meetup_t> res;
    return res;
}



