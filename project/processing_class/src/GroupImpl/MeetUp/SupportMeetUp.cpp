#include <sstream>

#include <MeetUp.hpp>

#define NUMBER_INTERVAL 12

enum { BITS = sizeof(unsigned char) };

// support class Duration
duration_t Day::get_format(const std::string &time) {
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

unsigned char Day::GetTimeInterval(const duration_t& dur) {
    int total = dur.hour * 60 * dur.min;
    return (unsigned char)(total / 15 + 1);
}


//  support class Day
unsigned char* Day::GetStorage() const {
    unsigned char* res;
    return res;
}

void Day::UnionDays(Day& added_day) {
    for (unsigned char i = 0; i < NUMBER_INTERVAL; i ++) {
        storage[i] |= added_day.GetStorage()[i];
    };
}

void Day::InvertDay() {
    for (unsigned char i = 0; i < NUMBER_INTERVAL; i ++) {
        storage[i] = ~this->GetStorage()[i];
    };
}

void Day::InsertEvent(std::string& begin_time, std::string& end_time) {
    unsigned char begin = GetTimeInterval(get_format(begin_time));
    unsigned char end = GetTimeInterval(get_format(end_time));

    while (begin < end) {
        storage[begin / BITS] |= ((unsigned char)1 << (begin % BITS));
        begin ++;
    }
}

void Day::EraseEvent(std::string& begin_time, std::string& end_time) {
    unsigned char begin = GetTimeInterval(get_format(begin_time));
    unsigned char end = GetTimeInterval(get_format(end_time));

    while (begin < end) {
        storage[begin / BITS] &= ~((unsigned char)1 << (begin % BITS));
        begin++;
    }
}

bool Day::IsFree(std::string& begin_time, std::string& end_time) {
    unsigned char begin = GetTimeInterval(get_format(begin_time));
    unsigned char end = GetTimeInterval(get_format(end_time));;

    bool answer = true;

    while (begin < end) {
        answer = bool(storage[begin / BITS] >> (begin % BITS) & 1);
    }

    return answer;
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

std::set<meetup_t> Day::SearchMeetUps() {
    std::set<meetup_t> res;

    return res;
}

std::set<meetup_t> SearchFreeTimeImpl::GetMeetUps(std::vector<std::set<event_t>> user_events) {
    Day free_day;

    for (auto member: user_events) {
        Day user_day;

        for (auto event: member) {
            user_day.InsertEvent(event.time_begin, event.time_end);
        }

        free_day.UnionDays(user_day);
    }

    free_day.InvertDay();

    return free_day.SearchMeetUps();
}



