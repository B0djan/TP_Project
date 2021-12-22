#include <ParserContactsImpl.hpp>

ParserObject ParserUserContactsImpl::StrToObject(const std::string& parser_str) const {

    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    contacts_t contacts;

    if(j.contains("user_id"))
            contacts.user_id = value["user_id"];

    if(j.contains("contacts"))
    {
        for (auto& element : value["contacts"])
        contacts.contacts.insert(element.dump());
    }

    ParserObject res;

    res = contacts;

    return res;
}

std::string ParserUserContactsImpl::ObjectToStr(const ParserObject& other) const {

    contacts_t contacts = other.contacts;

    nlohmann::json value;

    if (contacts.user_id != "")
        value["user_id"] = contacts.user_id;
        
    if (!contacts.contacts.empty())
        value["contacts"] = contacts.contacts;

    nlohmann::json j;

    j["friends"] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    return res;
}

