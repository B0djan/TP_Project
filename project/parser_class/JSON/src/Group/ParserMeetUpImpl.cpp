#include <Group/ParserMeetUpImpl.hpp>

ParserObject ParserMeetUpImpl::StrToObject(const std::string& parser_str) const {
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    group_t group;

    meetup_t meetup;

    {
        if (value.contains("group_id"))
        {
            group.group_id = value["group_id"].get<std::string>();
        }

        if (value.contains("date"))
        {
            meetup.date = value["date"].get<std::string>();
        }

        if (value.contains("members")) {
            for (auto &element_in : value["members"])
            {
                group.members.insert(element_in.get<std::string>());
            }
        }
    }

    ParserObject res;

    std::set<group_t> groups;

    groups.insert(group);

    res = groups;
    res.meetups.insert(meetup);

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::from_client(parser_str);
        for (std::set<group_t>::iterator it = groups.begin(); it != groups.end(); ++it) {
            Print_struct::_group_t(*it);
        }
    }

    return res;
}

std::string ParserMeetUpImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    nlohmann::json j;

    std::string res;

    if (!other.error.empty()) {
        j[type_response] = "Error get meetup";

        res = j.dump();

        return res;
    }

    std::set<meetup_t> meetups = other.meetups;

    if (meetups.empty()) {
        j[type_response] = "Not found events";

        res = j.dump();

        return res;
    }

    nlohmann::json json_meetups;

    if (!meetups.empty())
    {
        for (auto& meetup: meetups)
        {
            nlohmann::json json_meetup;

            if (!meetup.meetup_name.empty())
                json_meetup["meetup_name"] = meetup.meetup_name;

            if (!meetup.time_begin.empty())
                json_meetup["time_begin"] = meetup.time_begin;

            if (!meetup.time_end.empty())
                json_meetup["time_end"]   = meetup.time_end;

            if (!meetup.description.empty())
                json_meetup["description"] = meetup.description;

            if (!meetup.date.empty())
                json_meetup["meetup_date"] = meetup.date;

            json_meetups.push_back(json_meetup);
        }
    }

    j[type_response] = json_meetups;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        for (std::set<meetup_t>::iterator it = meetups.begin(); it != meetups.end(); ++it) {
            Print_struct::_meetup_t(*it);
        }
        Print_struct::from_processing(res);
    }

    return res;
}
