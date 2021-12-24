#include <ContactsImpl.hpp>

ParserObject AddUserContactsImpl::process(const ParserObject& request_body) {

    contacts_t contacts = request_body.contacts;

    std::string code = AddFriend(contacts);

    ParserObject response_body;
    return response_body;
}

ParserObject RmUserContactsImpl::process(const ParserObject& request_body) {

    contacts_t contacts = request_body.contacts;

    std::string code = DeleteFriend(contacts);

    ParserObject response_body;
    return response_body;
}

std::string AddUserContactsImpl::AddFriend(contacts_t& c) {
    std::string code;
    return code;
};

std::string RmUserContactsImpl::DeleteFriend(contacts_t& c) {
    std::string code;
    return code;
};


