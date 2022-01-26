#include <MeetUpImpl.hpp>

#include <MeetUp.hpp>

ParserObject SearchFreeTimeImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();
    std::set<meetup_t> :: iterator it_m = request_body.meetups.begin();

    response_body = GetMeetUps(GetData(*it_g, (*it_m).date));

    return response_body;
}

ParserObject OutputHistoryMeetUpImpl::process(const ParserObject& request_body) {
    ParserObject response_body;
    return response_body;
}




std::set<std::set<event_t>> SearchFreeTimeImpl::GetData(const group_t& g, const std::string& date) {
    std::set<std::set<event_t>> res;

    group_t buf = DatabaseConnector::Group::GetMembers(g.group_id);
    for (std::set<std::string> :: iterator it_m = buf.members.begin(); it_m != buf.members.end(); it_m++) {
        char* check_user_id = DatabaseConnector::GetID::User(*it_m);
        if (check_user_id == NULL) {
            return res;
        }

        std::string user_id = check_user_id;

        //  Отладка
        if (GLOBAL_KEY_TEST_DATABASE_CON) {
            Print_struct::from_processing(user_id);
        }

        res.insert(DatabaseConnector::Synchro::Events(user_id, date));

        std::cout << "IIIII" << std::endl;
    }

    return res;
}

std::set<meetup_t> SearchFreeTimeImpl::GetMeetUps(const std::set<std::set<event_t>> data) {
    MeetUp meetup(data);

    std::set<meetup_t> res = meetup.GetMeetUps();

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        for (std::set<meetup_t>::iterator it = res.begin(); it != res.end(); ++it) {
            Print_struct::_meetup_t(*it);
        }
    }

    return res;
}