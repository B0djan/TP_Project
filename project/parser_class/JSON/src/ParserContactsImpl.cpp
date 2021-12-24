#include <ParserContactsImpl.hpp>

ParserObject ParserUserContactsImpl::StrToObject(const std::string& parser_str) const {

    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    contacts_t contacts;

    if(j.contains("user_id"))
            contacts.user_id = value["user_id"];

    if(j.contains("list_contacts"))
    {
        for (auto& element : value["list_contacts"])
        contacts.list_contacts.insert(element.dump());
    }

    ParserObject res;

    res = contacts;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        std::cout  << "From client  :---: " << parser_str << std::endl;
        for (std::set<std::string>::iterator it = contacts.list_contacts.begin(); it != contacts.list_contacts.end(); ++it) {
            std::cout << "contacts" << *it << std::endl;
        }
    }

    return res;
}

std::string ParserUserContactsImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {

    contacts_t contacts = other.contacts;

    nlohmann::json value;

    if (contacts.user_id != "")
        value["user_id"] = contacts.user_id;
        
    if (!contacts.list_contacts.empty())
        value["list_contacts"] = contacts.list_contacts;

    nlohmann::json j;

    j[type_response] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        for (std::set<std::string>::iterator it = contacts.list_contacts.begin(); it != contacts.list_contacts.end(); ++it) {
            std::cout << "contacts" << *it << std::endl;
        }
        std::cout << "From processing  :---: " << res << std::endl;
    }

    return res;
}

