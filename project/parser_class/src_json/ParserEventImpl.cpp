#include <ParserEventImpl.hpp>

ParserObject ParserEventImpl::StrToObject(const std::string& parser_str) {

    //  {}
    
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    std::set<event_t> events;

    for (auto& element : value[""])

        if(j.contains("user_id"))
            contacts.user_id = value["user_id"];

        if(j.contains("contacts"))
        {
            for (auto& element : value["contacts"])
            contacts.contacts.insert(element.dump());
        }

    ParserObject res;

    res.events = events;

    return res;
}

std::string ParserEventImpl::ObjectToStr(const ParserObject& other) {

    contacts_t contacts = other.contacts;

    nlohmann::json value;

    nlohmann::json j;

    j["friends"] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    return res;
}


