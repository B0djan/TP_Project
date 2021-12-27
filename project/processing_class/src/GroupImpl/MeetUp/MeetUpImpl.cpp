#include <MeetUp.hpp>

ParserObject SearchFreeTimeImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();
    std::set<event_t> :: iterator it_e = request_body.events.begin();

    response_body = GetMeetUps(GetData(*it_g, (*it_e).date));

    return response_body;
}

ParserObject OutputHistoryMeetUpImpl::process(const ParserObject& request_body) {
    ParserObject response_body;
    return response_body;
}

// Main functions




