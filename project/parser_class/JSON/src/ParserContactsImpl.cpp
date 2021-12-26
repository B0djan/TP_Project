#include <ParserContactsImpl.hpp>

ParserObject ParserUserContactsImpl::StrToObject(const std::string& parser_str) const {
    //  {"add_friend":{"user_id":"56","list_contacts":["Ibragim", "Misha"]}}

    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    contacts_t contacts;

    if(value.contains("user_id"))
            contacts.user_id = value["user_id"].get<std::string>();

    if(value.contains("list_contacts"))
    {
        for (auto& element : value["list_contacts"])
        contacts.list_contacts.insert(element.get<std::string>());
    }

    ParserObject res;

    res = contacts;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::from_client(parser_str);
        Print_struct::_contacts_t(contacts);
    }

    return res;
}

std::string ParserUserContactsImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    // {"registration":{"user_id":"value"}} TODO: Отредачить

    nlohmann::json j;
    std::string res;

    if (type_response == ADD_USER_CONTACTS || type_response == RM_USER_CONTACTS) {
        if (other.error.empty()) {
            j[type_response] = "OK";

            res = j.dump();
        } else  {
            j[type_response] = other.error;

            res = j.dump();
        }

        return res;
    }

    contacts_t contacts = other.contacts;

    nlohmann::json value;

    if (!contacts.user_id.empty())
        value["user_id"] = contacts.user_id;

    if (!contacts.list_contacts.empty())
        value["list_contacts"] = contacts.list_contacts;

    j[type_response] = value;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::_contacts_t(contacts);
        Print_struct::from_processing(res);
    }

    return res;
}

