#include <sstream>

#include <MeetUp.hpp>

#define NUMBER_INTERVAL 12

enum { BITS = sizeof(unsigned char) };

// support class Duration
duration_t SearchFreeTimeImpl::get_format(const std::string &time) {
    std::stringstream stream(time);

    int h, m = 0;

    stream >> h;
    stream.ignore(1);
    stream >> m;

    int total = h * 60 + m;

    duration_t dur;
    dur.hour = total / 60;
    dur.min = total % 60;

    return dur;
}

unsigned char SearchFreeTimeImpl::GetTimeInterval(const duration_t& dur) {
    int total = dur.hour * 60 * dur.min;
    return (unsigned char)(total / 15 + 1);
}


//  support class Day
unsigned char* SearchFreeTimeImpl::Day::GetStorage() const {
    unsigned char* res;
    return res;
}

void SearchFreeTimeImpl::Day::UnionDays(Day& added_day) {
    for (unsigned char i = 0; i < NUMBER_INTERVAL; i ++) {
        storage[i] |= added_day.GetStorage()[i];
    };
}

void SearchFreeTimeImpl::Day::InvertDay(Day& busy_day) {
    for (unsigned char i = 0; i < NUMBER_INTERVAL; i ++) {
        storage[i] = ~busy_day.GetStorage()[i];
    };
}

/*void SearchFreeTimeImpl::Day::InsertEvent(duration_t& begin_time, duration_t& end_time) {
    unsigned char begin = begin_time.GetTimeInterval();
    unsigned char end = end_time.GetTimeInterval();

    while (begin < end) {
        storage[begin / BITS] |= ((unsigned char)1 << (begin % BITS));
        begin ++;
    }
}

void SearchFreeTimeImpl::Day::EraseEvent(duration_t& begin_time, duration_t& end_time) {
    char begin = begin_time.GetTimeInterval();
    char end = end_time.GetTimeInterval();

    while (begin < end) {
        storage[begin / BITS] &= ~((unsigned char)1 << (begin % BITS));
        begin++;
    }
}*/

bool SearchFreeTimeImpl::Day::IsFree(duration_t& begin_time, duration_t& end_time) {
    // bool Day::IsFree(Duration& begin_time, Duration& end_time) {

    //     char begin = begin_time.GetTimeInterval();
    //     char end = end_time.GetTimeInterval();

    //     bool answer = true;

    //     while (begin < end) {
    //         answer = bool(storage[begin / BITS] >> (begin % BITS) & 1);
    //     }
    //     return answer;
    //}
    return true;
}


//  DatabaseConnector methods
std::vector<std::set<event_t>> SearchFreeTimeImpl::GetData(const group_t& g, const std::string& date) {
    std::vector<std::set<event_t>> res;

    for (std::set<std::string> :: iterator it_m = g.members.begin(); it_m != g.members.end(); it_m++) {
        char* check_user_id = DatabaseConnector::GetID::User(*it_m);
        if (check_user_id == NULL) {
            return res;
        }

        std::string user_id = check_user_id;

        res.push_back(DatabaseConnector::Synchro::Events(user_id, date));
    }

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
        set<meetup> res = free_day.SearchMeetUps();
     */
    std::set<meetup_t> res;
    return res;
}



