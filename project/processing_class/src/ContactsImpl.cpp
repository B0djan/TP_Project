#include <ContactsImpl.hpp>

ParserObject AddUserContactsImpl::process(const ParserObject& request_body) {
    std::set<std::string> :: iterator it_m = request_body.contacts.list_contacts.begin();

    int code;

    ParserObject response_body;

    char* check = SupportProcess::GetUserId(*it_m);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string user_id = check;

    code = AddFriend(request_body.contacts.user_id, user_id);
    if (code != 0) {
        response_body.error = "Error add contact";
        return response_body;
    }

    return response_body;
}

ParserObject RmUserContactsImpl::process(const ParserObject& request_body) {
    std::set<std::string> :: iterator it_m = request_body.contacts.list_contacts.begin();

    int code;

    ParserObject response_body;



    code = DeleteFriend(request_body.contacts.user_id, SupportProcess::GetUserId(*it_m));
    if (code != 0) {
        response_body.error = "Error delete contact";
        return response_body;
    }

    return response_body;
}

int AddUserContactsImpl::AddFriend(const std::string& user_id_main, const std::string& user_id_friend) {
    char command[] = "INSERT INTO contacts (fk_user_id, fk_friend_id) VALUES ($1, $2)";

    const char* arguments[2];

    arguments[0] = user_id_main.c_str();
    arguments[1] = user_id_friend.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    };

    PQclear(res);

    return SUCCESS;
};

int RmUserContactsImpl::DeleteFriend(const std::string& user_id_main, const std::string& user_id_friend) {
    char command[] = "DELETE FROM contacts WHERE (fk_user_id = $1) AND (fk_friend_id = $2)";

    const char* arguments[2];

    arguments[0] = user_id_main.c_str();
    arguments[1] = user_id_friend.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 2, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    };

    PQclear(res);

    return SUCCESS;
};
