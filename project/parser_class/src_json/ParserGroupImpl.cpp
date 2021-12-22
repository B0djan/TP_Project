#include <ParserGroupImpl.hpp>

ParserObject ParserGroupImpl::StrToObject(const std::string& parser_str) {
    
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    contacts_t contacts;

    ParserObject res;

    res = contacts;

    return res;
}

std::string ParserGroupImpl::ObjectToStr(const ParserObject& other) {

    contacts_t contacts = other.contacts;

    nlohmann::json value;

    nlohmann::json j;

    j["friends"] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    return res;
}


ParserObject ParserUserGroupImpl::StrToObject(const std::string& parser_str) {
    ParserObject res;
    return res;
}

std::string ParserUserGroupImpl::ObjectToStr(const ParserObject& other) {
    std::string res;
    return res;
}

ParserObject ParserMeetUpImpl::StrToObject(const std::string& parser_str) {
    ParserObject res;
    return res;
}

std::string ParserMeetUpImpl::ObjectToStr(const ParserObject& other) {
    std::string res;
    return res;
}



// ParserObject ParserUserContactsImpl::StrToObject(const std::string& parser_str) {

//     nlohmann::json j = nlohmann::json::parse(parser_str);

//     nlohmann::json::iterator it = j.begin();

//     nlohmann::json value = j[it.key()];

//     contacts_t contacts;

//     if(j.contains("user_id"))
//             contacts.user_id = value["user_id"];

//     if(j.contains("contacts"))
//     {
//         for (auto& element : value["contacts"])
//         contacts.contacts.insert(element.dump());
//     }

//     ParserObject res;

//     res = contacts;

//     return res;
// }

// std::string ParserUserContactsImpl::ObjectToStr(const ParserObject& other) {

//     contacts_t contacts = other.contacts;

//     nlohmann::json value;

//     value["user_id"] = contacts.user_id;

//     value["contacts"] = contacts.contacts;

//     nlohmann::json j;

//     j["friends"] = value;

//     std::string res = j.dump();

//     // {"registration":{"user_id":"value"}}

//     return res;
// }

