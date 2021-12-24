#include <SynchroClientImpl.hpp>

ParserObject SynchroClientEventsImpl::process(const ParserObject& request_body) {

    event_t event_buf;

    for (auto e: request_body.events) {

        event_buf.date = e.date;
        event_buf.user_id = e.user_id;
    }

    char command[] = "SELECT description, time_begin, time_end FROM event_m WHERE (date = $1, fk_user_id = $2)";

    const char* arguments[2];

    arguments[0] = event_buf.date.c_str();
    arguments[1] = event_buf.user_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

    std::set<event_t> events;

    event_t event;

    int n_rows = PQntuples(res);

    for (int i = 0; i < n_rows; i++) {

        event.description = PQgetvalue(res, i, 0);
        event.time_begin = PQgetvalue(res, i, 1);
        event.time_end = PQgetvalue(res, i, 2);

        events.insert(event);
    }

    ParserObject response_body;

    response_body.events = events;
    
    return response_body;
}

ParserObject SynchroClientContactsImpl::process(const ParserObject& request_body) {
    contacts_t user;

    user.user_id = request_body.contacts.user_id;

    std::set<std::string> friends = GetContacts(user);

    ParserObject response_body;

    response_body.contacts.list_contacts = friends;

    return response_body;
}

ParserObject SynchroClientGroupsImpl::process(const ParserObject& request_body) {
    ParserObject response_body;
    return response_body;
}

std::set<std::string> SynchroClientContactsImpl::GetContacts(contacts_t& c) {
    char command[] = "SELECT list_contacts.fk_user_id, user_m.nickname "
                     "FROM list_contacts LEFT JOIN user_m ON list_contacts.fk_friend_id = user_m.user_id"
                     "WHERE fk_user_id = $1";

    const char* arguments[1];

    arguments[0] = c.user_id.c_str();

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
