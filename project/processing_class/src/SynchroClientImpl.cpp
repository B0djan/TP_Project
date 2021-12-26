#include <SynchroClientImpl.hpp>

ParserObject SynchroClientEventsImpl::process(const ParserObject& request_body) {
    std::set<event_t> :: iterator it = request_body.events.begin();

    ParserObject response_body;

    response_body.events = DatabaseConnector::Synchro::Events(*it);
    if (response_body.events.empty()) {
        response_body.error = "Error synchronization events";

        return response_body;
    }


    return response_body;
}

ParserObject SynchroClientContactsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    response_body.contacts.list_contacts = DatabaseConnector::Synchro::Contacts(request_body.user.user_id);
    if (response_body.contacts.list_contacts.empty()) {
        response_body.error = "Error synchronization contacts";

        return response_body;
    }

    return response_body;
}

ParserObject SynchroClientGroupsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<std::string> names_groups = DatabaseConnector::Synchro::Groups(request_body.user.user_id);
    if (request_body.groups.empty()) {
        response_body.error = "Error synchronization contacts";

        return response_body;
    };

    for (auto ng: names_groups) {
        group_t group { .title = ng };

        response_body.groups.insert(group);
    };

    return response_body;
}
