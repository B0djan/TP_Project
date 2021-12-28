#include <MeetUpImpl.hpp>

ParserObject SearchFreeTimeImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();
    std::set<event_t> :: iterator it_e = request_body.events.begin();

    response_body = GetMeetUps(GetData(*it_g, (*it_g).title));

    return response_body;
}

ParserObject OutputHistoryMeetUpImpl::process(const ParserObject& request_body) {
    ParserObject response_body;
    return response_body;
}




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

std::set<event_t> SearchFreeTimeImpl::SearchMeetUps(std::set<std::string> all_free_times) {

    std::set<event_t> events;

    for (std::set<std::string>::iterator it = all_free_times.begin(); it != all_free_times.end();) {

        event_t event;

        event.time_begin = *it;

        while (IsMeetUp(StrToDuration(*++it), StrToDuration(*it))) {
            event.time_end = *it;
        }
        events.insert(event);
    }
    return events;
}

std::set<event_t> SearchFreeTimeImpl::GetMeetUps(std::vector<std::set<event_t>> members_evets) {
    Day day = CreateFreeDay(members_evets);

    std::set<std::string> all_free_times = day.GetSetOfFreeTime();

    std::set<event_t> meetups = SearchMeetUps(all_free_times);

    return meetups;
}



