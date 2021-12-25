#include <GroupImpl.hpp>

ParserObject AddUserImpl::process(const ParserObject& request_body) {
    int code;
    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();

    std::string group_id = SupportProcess::GetGroupId((*it_g).title);
    if (group_id.empty()) {
        response_body.error = "Error get id group";
        return response_body;
    }


    code = SupportProcessGroup::AddMember(response_body.user.user_id, group_id);
    if (code != 0) {
        response_body.error = "Error new member in group";
        return response_body;
    }

    return response_body;
}

ParserObject RmUserImpl::process(const ParserObject& request_body) {
    int code;
    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();

    std::string group_id = SupportProcess::GetGroupId((*it_g).title);
    if (group_id.empty()) {
        response_body.error = "Error get id group";
        return response_body;
    }

    code = SupportProcessGroup::RmMember(response_body.user.user_id, group_id);
    if (code != 0) {
        response_body.error = "Error delete member in group";
        return response_body;
    }

    return response_body;
}

ParserObject JoinImpl::process(const ParserObject& request_body) {
    ParserObject response_body;
    return response_body;
}

ParserObject LeaveImpl::process(const ParserObject& request_body) {
    ParserObject response_body;
    return response_body;
}
