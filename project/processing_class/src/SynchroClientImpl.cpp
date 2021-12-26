#include <SynchroClientImpl.hpp>

ParserObject SynchroClientEventsImpl::process(const ParserObject& request_body) {
    std::set<event_t>::iterator it = request_body.events.begin();

    event_t params_search_events = *it;

    ParserObject response_body;

    response_body.events = DatabaseConnector::Synchro::GetEvents(params_search_events);
    if (response_body.events.empty()) {
        response_body.error = "Not found events";

        return response_body;
    }

    return response_body;
}

ParserObject SynchroClientContactsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<std::string> friends = DatabaseConnector::Synchro::GetContacts(request_body.user.user_id);

    if (friends.empty()) {
        response_body.error = "Not found contacts";
        
        return response_body;
    }

    response_body.contacts.list_contacts = friends;

    return response_body;
}

ParserObject SynchroClientGroupsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<std::string> names_groups = DatabaseConnector::Synchro::GetGroups(request_body.user.user_id);

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

std::set<std::string> SynchroClientContactsImpl::GetContacts(const std::string& id) {
    char command[] = "SELECT fk_user_id, nickname "
                     "FROM contacts LEFT JOIN user_m ON fk_friend_id = user_id"
                     "WHERE fk_user_id = $1";

    const char* arguments[1];

    arguments[0] = id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

    std::set<std::string> friends;

    if (PQgetisnull(res, 0, 1))
        return friends;

    int n_rows = PQnfields(res);

    for (int i = 0; i < n_rows; i ++) {
        char* Friend = PQgetvalue(res, i, 1);

        friends.insert(Friend);
    }

    return friends;
};

std::set<std::string> SynchroClientGroupsImpl::GetGroups(const std::string& id) {

    char command[] = "SELECT fk_user_id, title "
                     "FROM group_members "
                     "LEFT JOIN group_m "
                     "ON fk_group_id = group_id "
                     "WHERE fk_user_id = $1";

    const char* arguments[1];

    arguments[0] = id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

    std::set<std::string> groups;

    if (PQgetisnull(res, 0, 1))
        return groups;                // в верхней функции првоерить пустое ли множество, если да то Not found

    int n_rows = PQnfields(res);

    for (int i = 0; i < n_rows; i++) {
        char* Group_name = PQgetvalue(res, i, 1);

        groups.insert(Group_name);
    }

    return groups;
};
