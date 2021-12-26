#include <GroupImpl.hpp>

ParserObject AddUserImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<group_t>::iterator it_g = request_body.groups.begin();
    std::set<std::string>::iterator it_m = (*it_g).members.begin();


    char *check_group_id = DatabaseConnector::GetID::Group((*it_g).title);
    if (check_group_id == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string group_id = check_group_id;

    char *check_user_id = DatabaseConnector::GetID::User(*it_m);
    if (check_user_id == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string user_id = check_user_id;

    code = DatabaseConnector::Group::Management::AddMember(user_id, group_id);
    if (code != 0) {
        response_body.error = "Error add new member in group";

        return response_body;
    }

    return response_body;
}

ParserObject RmUserImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();
    std::set<std::string> :: iterator it_m = (*it_g).members.begin();

    char* check = DatabaseConnector::GetID::Group((*it_g).title);
    if (check == NULL) {
        response_body.error = "Error get group id";

        return response_body;
    }

    std::string group_id = check;

    char* check_user_id = DatabaseConnector::GetID::User(*it_m);
    if (check_user_id == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string user_id = check_user_id;

    code = DatabaseConnector::Group::Management::RmMember(user_id, group_id);
    if (code != 0) {
        response_body.error = "Error of delete 1 member group";

        return response_body;
    }

    return response_body;
}
