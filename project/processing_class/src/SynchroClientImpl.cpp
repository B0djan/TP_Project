#include <SynchroClientImpl.hpp>

ParserObject SynchroClientEventsImpl::process(const ParserObject& request_body) {

    std::set<event_t>::iterator it = request_body.events.begin();

    event_t params_search_events = *it;

    std::string user_id = params_search_events.user_id;

    std::string date = params_search_events.date;

    // отладка

    std::cout << "user id: " << user_id << std::endl;

    std::cout << "event's date :" << date << std::endl;

    std::cout << "если значения пустые - не произошло "
    "присвоения значений итератору. SynhroClientImpl" << std::endl;

    //

    ParserObject response_body;

    // ТЫ ВЫШЕЛ ЗДЕСЬ, СУКА!

    response_body.events = DatabaseConnector::Synchro::Events(params_search_events);
    if (response_body.events.empty()) {
        response_body.error = "Not found events";

        return response_body;
    }

    // отладка

    for (auto e: response_body.events) {
        std::cout << "event_name:" << e.event_name << std::endl;
        std::cout << "time_begin" << e.time_begin << std::endl;
        std::cout << "time_end" << e.time_end << std::endl;
    }

    std::cout << "Если строки пустые - то response не получил ничего от Synhro::Events" <<std::endl;

    //

    return response_body;
}

ParserObject SynchroClientContactsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<std::string> friends = DatabaseConnector::Synchro::Contacts(request_body.user.user_id);
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
