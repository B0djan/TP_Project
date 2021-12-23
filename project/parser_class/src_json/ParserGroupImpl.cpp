#include <ParserGroupImpl.hpp>

ParserObject ParserGroupImpl::StrToObject(const std::string& parser_str) const{
    
    // nlohmann::json j = nlohmann::json::parse(parser_str);

    // nlohmann::json::iterator it = j.begin();

    // nlohmann::json value = j[it.key()];

    // group_t group;

    ParserObject res;

    // res = contacts;

    return res;
}

std::string ParserGroupImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {

    contacts_t contacts = other.contacts;

    nlohmann::json value;

    nlohmann::json j;

    j[type_response] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    return res;
}


ParserObject ParserUserGroupImpl::StrToObject(const std::string& parser_str) const {
    ParserObject res;
    return res;
}

std::string ParserUserGroupImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    std::string res;
    return res;
}

ParserObject ParserMeetUpImpl::StrToObject(const std::string& parser_str) const {
    ParserObject res;
    return res;
}

std::string ParserMeetUpImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
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

//     j[type_response] = value;

//     std::string res = j.dump();

//     // {"registration":{"user_id":"value"}}

//     return res;
// }

