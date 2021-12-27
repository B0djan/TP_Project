#include <MeetUp.hpp>

ParserObject SearchFreeTimeImpl::process(const ParserObject& request_body) {
    /*
    ParserObject response_body;

        group_t group

        for (auto gr: request_body.groups) {
            group = gr;
        }

        res = GetMeetUps(GetData(group));

        return res;

    */
    ParserObject response_body;
    return response_body;
}

ParserObject OutputHistoryMeetUpImpl::process(const ParserObject& request_body) {
    ParserObject response_body;
    return response_body;
}

// Main functions

Day CreateFreeDay(std::vector<std::set<event_t>> members_evets) {
    Day busy_day;

    for (auto user_events: members_evets) {

        Day user_day;

        for (auto event: user_events) {
            user_day.InsertEvent(event.time_begin, event.time_end);
        }

        busy_day.UnionDays(user_day);
    }

    Day free_day;
    free_day.InvertDay(busy_day);

    return free_day;
}

std::set<meetup_t> SearchMeetUps(std::set<std::string> all_free_times) {

    std::set<meetup_t> meetups;

    for (std::set<std::string>::iterator it = all_free_times.begin(); it != all_free_times.end();) {

        meetup_t meetup;

        meetup.time_begin = *it;

        while ( IsMeetUp (StrToDuration(*++it), StrToDuration(*it)) ) {
            meetup.time_end = *it;
        }
        meetups.insert(meetup);
    }
    return meetups;
}

bool IsMeetUp (duration_t duration1, duration_t duration2) {
    if (duration2 - duration1 <= 15) {
        return true;
    } else {
        return false;
    }
}

std::set<std::string> Day::GetSetOfFreeTime() {
    std::set<std::string> all_free_times;

    for (unsigned char i = 0; i < NUMBER_INTERVAL; i++) {
        if ((storage[i / BITS] >> (i % BITS)) & 1) {
            std::string time = CharToStr(i);
            all_free_times.insert(time);              
        }
    }
    return all_free_times;
}

