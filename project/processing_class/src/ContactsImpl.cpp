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
        response_body.error = "Error add contact";

        return response_body;
    }

    return response_body;
}

ParserObject RmUserContactsImpl::process(const ParserObject& request_body) {
    std::set<std::string> :: iterator it_m = request_body.contacts.list_contacts.begin();

    int code;

    ParserObject response_body;

    code = DatabaseConnector::Contact::Delete(request_body.contacts.user_id,
                                              DatabaseConnector::GetID::User(*it_m));
    if (code != 0) {
        response_body.error = "Error delete contact";

        return response_body;
    }

    return response_body;
}
