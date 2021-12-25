#include <ParserGroupImpl.hpp>

ParserObject ParserGroupImpl::StrToObject(const std::string& parser_str) const {
    // {"add_event":{["user_id":"56","event_name":"breakfast","event_date":"01:06:2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"]}} TODO: Отредачить

    // {"create_group":{"title":"Texnosrac","members":["56"]}};

    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    group_t group;

    {
        if (value.contains("group_id"))
        {
            group.group_id = value["group_id"].get<std::string>();
        }

        if (value.contains("title"))
        {
            group.title = value["title"].get<std::string>();
        }

        if (value.contains("members")) {
            for (auto &element_in : value["members"])
            {
                group.members.insert(element_in.get<std::string>());
            }
        };
    }

    ParserObject res;

    std::set<group_t> groups;

    groups.insert(group);

    res = groups;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Debugging::print_from_client(parser_str);
        for (std::set<group_t>::iterator it = groups.begin(); it != groups.end(); ++it) {
            Debugging::print_group_t(*it);
        }
    }

    return res;
}

std::string ParserGroupImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    // {"add_event":{["user_id":"56","event_name":"breakfast","event_date":"01:06:2000", "description":"2132", "time_begin":"15:45", "time_end":"16:00"]}} TODO: Отредачить

    nlohmann::json j;
    std::string res;

    if (type_response == ADD_GROUP || type_response == WRITE_GROUP || type_response == RM_GROUP) {
        if (other.error.empty()) {
            j[type_response] = "OK";

            res = j.dump();
        } else  {
            j[type_response] = other.error;

            res = j.dump();
        }

        return res;
    }

    std::set<group_t> groups = other.groups;

    nlohmann::json json_groups;

    if (groups.empty()) {
        json_groups[type_response] = "Not found";
    }

        for (auto& group: groups)
        {
            nlohmann::json json_group;
            nlohmann::json json_group_members;

            if (!group.group_id.empty())
            {
                json_group["group_id"] = group.group_id;
            }

            if (!group.title.empty())
            {
                json_group["title"] = group.title;
            }

            if (!(group.members.empty()))
            {
                for (auto& member: group.members)
                {
                    json_group_members["members"] = member;
                }

                json_group.push_back(json_group_members);
            }

            json_groups.push_back(json_group);
        }
    }

    j[type_response] = json_groups;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        for (std::set<group_t>::iterator it = groups.begin(); it != groups.end(); ++it) {
            Debugging::print_group_t(*it);
        }
        Debugging::print_from_processing(res);
    }

    return res;
}

