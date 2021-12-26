#include <ParserGroupImpl.hpp>

ParserObject ParserUserGroupImpl::StrToObject(const std::string& parser_str) const {
    // {"add_event":{["user_id":"56","event_name":"breakfast","event_date":"01:06:2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"]}} TODO: Отредачить
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    user_t user;

    std::set<group_t> groups;

    group_t group;

    if (value.contains("nickname"))
        user.nickname = value["nickname"].get<std::string>();

    if(value.contains("title"))
        group.title = value["title"].get<std::string>();

    groups.insert(group);

    ParserObject res;

    res = user;
    res = groups;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Debugging::print_from_client(parser_str);
        Debugging::print_user_group(user, group);
    }

    return res;
}

std::string ParserUserGroupImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    nlohmann::json j;
    std::string res;

    if (type_response == ADD_USER || type_response == RM_USER || type_response == JOIN || type_response == LEAVE) {
        if (other.error.empty()) {
            j[type_response] = "OK";

            res = j.dump();
        } else {
            j[type_response] = other.error;

            res = j.dump();
        }

        return res;
    }

    user_t user = other.user;

    group_t group;

    for (auto g: other.groups) {
        group = g;
    }

    nlohmann::json value;

    if (user.user_id != "")
        value["user_id"] = user.user_id;

    if (user.nickname != "")
        value["nickname"] = user.nickname;

    if (!group.title.empty()) {
        value["title"] = group.title;
    };

    j[type_response] = value;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Debugging::print_user_group(user, group);
        Debugging::print_from_processing(res);
    }

    return res;
}