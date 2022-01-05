#include <SynchroClientImpl.hpp>

ParserObject SynchroClientEventsImpl::process(const ParserObject& request_body) {
    std::set<event_t>::iterator it = request_body.events.begin();

    ParserObject response_body;

    response_body.events = DatabaseConnector::Synchro::Events((*it).user_id, (*it).date);
    if (response_body.events.empty()) {
        response_body.error = "Not found events";

        return response_body;
    }

    return response_body;
}

ParserObject SynchroClientContactsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    response_body.contacts.list_contacts = DatabaseConnector::Synchro::Contacts(request_body.contacts.user_id);
    if (response_body.contacts.list_contacts.empty()) {
        response_body.error = "Not found contacts";
        
        return response_body;
    }

    return response_body;
}

ParserObject SynchroClientGroupsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<group_t>::iterator it_g = request_body.groups.begin();
    std::set<std::string>::iterator it_m = (*it_g).members.begin();;

    char *check_user_id = DatabaseConnector::GetID::User(*it_m);
    if (check_user_id == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string user_id = check_user_id;

    std::set<group_t> groups = DatabaseConnector::Synchro::Groups(user_id);
    if (groups.empty()) {
        response_body.error = "Not found groups";

        return response_body;
    }

    response_body.groups = groups;

    return response_body;
}
