#include <ContactsImpl.hpp>

ParserObject AddUserContactsImpl::process(const ParserObject& request_body) {
    contacts_t contacts = request_body.contacts;

    std::string code = AddFriend(contacts);

    ParserObject response_body;

    response_body.error;

    return response_body;
}

ParserObject RmUserContactsImpl::process(const ParserObject& request_body) {
    contacts_t contacts = request_body.contacts;

    std::string code = DeleteFriend(contacts);
    
    ParserObject response_body;

    response_body.contacts.user_id = code;

    return response_body;
}

std::string AddUserContactsImpl::AddFriend(contacts_t& c) {
    std::string friend_nickname;

    //  friend_nickname.front() (TODO) : чекни обращение чтоб без костылей

    for (auto f: c.list_contacts) {
        friend_nickname = f;
    }

    user_t friend_;

    friend_.nickname = friend_nickname;

    std::string friend_id = SupportProcess::GetUserId(friend_);

    char command[] = "INSERT INTO contacts VALUES ($1, $2)";

    const char* arguments[2];

    arguments[0] = c.user_id.c_str();
    arguments[1] = friend_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        return "ERROR";
    };

    PQclear(res);

    return "OK";
};

std::string RmUserContactsImpl::DeleteFriend(contacts_t& c) {
    std::string friend_nickname;

    for (auto f: c.list_contacts) {
        friend_nickname = f;
    };

    user_t friend_;

    friend_.nickname = friend_nickname;

    std::string friend_id = SupportProcess::GetUserId(friend_);

    char command[] = "DELETE FROM list_contacts WHERE (fk_user_id = $1) AND (fk_friend_id = $2)";

    const char* arguments[2];

    arguments[0] = c.user_id.c_str();
    arguments[1] = friend_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command field: %s\n", PQerrorMessage(PGConnection::GetConnection()));
        PQclear(res);
        return "ERROR";
    };

    PQclear(res);

    return "OK";
};
