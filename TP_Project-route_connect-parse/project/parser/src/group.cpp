#include "parse_json.hpp"

    group_t Json::GetGroup(nlohmann::json& j) {
        
        group_t group;

        if(j.contains("group_id"))
            group.group_id = j["group_id"];

        if(j.contains("members"))
        {
            for (auto& element : j["members"])
                group.members.insert(element[0].dump());
        }

        return group;
    }

    nlohmann::json Json::ReturnGroup(group_t& group) {

        nlohmann::json j {
            {"grou_id", group.group_id},
            {"members", group.members}
        };

        return j;
    }