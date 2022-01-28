#include <Group/GroupImpl.hpp>

ParserObject AddGroupImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();
    std::set<std::string> :: iterator it_m = (*it_g).members.begin();

    code = DatabaseConnector::Group::Create(*it_g);
    if (code != 0) {
        response_body.error = "Error of creation group";
        return response_body;
    }


    char* check_group_id = DatabaseConnector::GetID::Group((*it_g).title);
    if (check_group_id == NULL) {
        response_body.error = "Error get group id";

        return response_body;
    }

    std::string group_id = check_group_id;

    char* check_user_id = DatabaseConnector::GetID::User(*it_m);
    if (check_user_id == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string user_id = check_user_id;

    code = DatabaseConnector::Group::Management::AddMember(user_id, group_id);
    if (code != 0) {
        response_body.error = "Error add owner in group";

        return response_body;
    }

    group_t buf;

    buf.group_id = group_id;

    response_body.groups.insert(buf);

    if (GLOBAL_KEY_TEST_PROCESSING) {
        Print_struct::_group_t(*it_g);
    }

    return response_body;
}

ParserObject WriteGroupImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<group_t> :: iterator it = request_body.groups.begin();

    code = DatabaseConnector::Group::Write(*it);
    if (code != 0) {
        response_body.error = "Error write group";

        return response_body;
    }

    return response_body;
}

ParserObject RmGroupImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();
    std::set<std::string> :: iterator it_m = (*it_g).members.begin();

    Print_struct::from_client((*it_g).group_id);

    code = DatabaseConnector::Group::DeleteAllMembers((*it_g).group_id);
    if (code != 0) {
        response_body.error = "Error of delete group members";

        return response_body;
    }

    code = DatabaseConnector::Group::Delete((*it_g).group_id);
    if (code != 0) {
        response_body.error = "Error of delete group";

        return response_body;
    }

    if (GLOBAL_KEY_TEST_PROCESSING) {
        Print_struct::_group_t(*it_g);
    }

    return response_body;
}

ParserObject GetGroupImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();

    group_t group = DatabaseConnector::Group::GetMembers((*it_g).group_id);
    if (group.group_id == "Error") {
        response_body.error = "Error get data group members";

        return response_body;
    }

    response_body.groups.insert(group);

    if (GLOBAL_KEY_TEST_PROCESSING) {
        Print_struct::_group_t(*it_g);
    }

    return response_body;
}




ParserObject SearchGroupImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    //  Отложили, данный функционал пока не нужен
    /*std::set<group_t> :: iterator it_g = request_body.groups.begin();;

    char* check = GetID::Group((*it_g).title);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string group_id = check;

    //  Тут должны вернуться все данные нужна доп функция GetGroupData(title)
    group_t group;
    group.group_id = group_id;

    response_body.groups.insert(group);*/

    return response_body;
}

