#include <ContactsImpl.hpp>

ParserObject AddUserContactsImpl::process(const ParserObject& request_body) {
    std::set<std::string> :: iterator it_m = request_body.contacts.list_contacts.begin();

    int code;

    ParserObject response_body;

    char* check_user = DatabaseConnector::GetID::User(*it_m);
    if (check_user == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string user_id = check_user;

    code = DatabaseConnector::Contact::Add(request_body.contacts.user_id, user_id);
    if (code != 0) {
        response_body.error = "Error add first contact";

        return response_body;
    }

    code = DatabaseConnector::Contact::Add(user_id, request_body.contacts.user_id);
    if (code != 0) {
        response_body.error = "Error add second contact";

        return response_body;
    }

    return response_body;
}

ParserObject RmUserContactsImpl::process(const ParserObject& request_body) {
    std::set<std::string> :: iterator it_m = request_body.contacts.list_contacts.begin();

    int code;

    ParserObject response_body;

    char* check_user_for_del = DatabaseConnector::GetID::User(*it_m);
    if (check_user_for_del == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string user_id_1 = check_user_for_del;

    code = DatabaseConnector::Contact::Delete(request_body.contacts.user_id, user_id_1);
    if (code != 0) {
        response_body.error = "Error delete for first contact";

        return response_body;
    }

    code = DatabaseConnector::Contact::Delete(user_id_1, request_body.contacts.user_id);
    if (code != 0) {
        response_body.error = "Error delete for second contact";

        return response_body;
    }


    return response_body;
}
