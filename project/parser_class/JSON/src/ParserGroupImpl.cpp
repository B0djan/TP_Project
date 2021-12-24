#include <ParserGroupImpl.hpp>

ParserObject ParserGroupImpl::StrToObject(const std::string& parser_str) const{
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    std::set<group_t> groups;

    for (auto& json_group : value) {
        group_t group;

        if(json_group.contains("group_id"))
            group.group_id = json_group["group_id"];

        if(json_group.contains("title"))
            group.title = json_group["title"];

        if(json_group.contains("members"))
        {
            for (auto& element : json_group["members"])
                group.members.insert(element.dump());
        };

        groups.insert(group);
    };

    ParserObject res;

    res.groups = groups;

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

//     contacts_t list_contacts;

//     if(j.contains("user_id"))
//             list_contacts.user_id = value["user_id"];

//     if(j.contains("list_contacts"))
//     {
//         for (auto& element : value["list_contacts"])
//         list_contacts.list_contacts.insert(element.dump());
//     }

//     ParserObject res;

//     res = list_contacts;

//     return res;
// }

// std::string ParserUserContactsImpl::ObjectToStr(const ParserObject& other) {

//     contacts_t list_contacts = other.list_contacts;

//     nlohmann::json value;

//     value["user_id"] = list_contacts.user_id;

//     value["list_contacts"] = list_contacts.list_contacts;

//     nlohmann::json j;

//     j[type_response] = value;

//     std::string res = j.dump();

//     // {"registration":{"user_id":"value"}}

//     return res;
// }

