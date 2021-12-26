#include <SynchroClientImpl.hpp>

ParserObject SynchroClientEventsImpl::process(const ParserObject& request_body) {

    std::set<event_t>::iterator it = request_body.events.begin();

    event_t params_search_events = *it;

    std::string user_id = params_search_events.user_id;

    std::string date = params_search_events.date;

    ParserObject response_body;


    response_body.events = DatabaseConnector::Synchro::Events(user_id, date);
    if (response_body.events.empty()) {
        response_body.error = "Not found events";

        return response_body;
    }

    return response_body;
}

ParserObject SynchroClientContactsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<std::string> friends = DatabaseConnector::Synchro::Contacts(request_body.contacts.user_id);
    if (friends.empty()) {
        response_body.error = "Not found contacts";
        
        return response_body;
    }

    response_body.contacts.list_contacts = friends;

    return response_body;
}

ParserObject SynchroClientGroupsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<std::string> names_groups = DatabaseConnector::Synchro::Groups(request_body.user.user_id);
    if (names_groups.empty()) {
        response_body.error = "Not found groups";

        return response_body;
    }

    for (auto ng: names_groups) {
        group_t group { .title = ng };

        response_body.groups.insert(group);
    };

    return response_body;
}
