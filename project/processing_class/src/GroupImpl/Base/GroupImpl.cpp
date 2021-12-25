#include <GroupImpl.hpp>

ParserObject AddGroupImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();
    std::set<std::string> :: iterator it_m = (*it_g).members.begin();

    code = CreateGroup((*it_g).title);
    if (code != 0) {
        response_body.error = "Error of creation group";
        return response_body;
    }


    char* check = SupportProcess::GetGroupId((*it_g).title);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string group_id = check;

    code = SupportProcessGroup::AddMember(*it_m, group_id);
    if (code != 0) {
        response_body.error = "Error add owner in group";
        return response_body;
    }

    return response_body;
}

ParserObject WriteGroupImpl ::process(const ParserObject& request_body) {
    ParserObject response_body;
    return response_body;
}

ParserObject RmGroupImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();
    std::set<std::string> :: iterator it_m = (*it_g).members.begin();

    char* check = SupportProcess::GetGroupId((*it_g).title);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string group_id = check;

    code = DeleteAllMembers(group_id);
    if (code != 0) {
        response_body.error = "Error of delete group members";

        return response_body;
    }

    code = DeleteGroup(group_id);
    if (code != 0) {
        response_body.error = "Error of delete group";

        return response_body;
    }

    return response_body;
}

ParserObject SearchGroupImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    std::set<group_t> :: iterator it_g = request_body.groups.begin();;

    char* check = SupportProcess::GetGroupId((*it_g).title);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    std::string group_id = check;

    //  Тут должны вернуться все данные нужна доп функция GetGroupData(title)
    group_t group;
    group.group_id = group_id;

    response_body.groups.insert(group);

    return response_body;
}

int AddGroupImpl::CreateGroup(const std::string& title) {
    char command[] = "INSERT INTO group_m (title) VALUES ($1)";

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        Debugging::print_from_client(title);
    }

    const char* arguments[1];

    arguments[0] = title.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    } else {
        return SUCCESS;
    }
}

int RmGroupImpl::DeleteGroup(const std::string &group_id) {
    char command[] = "DELETE FROM group_m WHERE (group_id = $1)";

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        Debugging::print_from_client(group_id);
    }

    const char* arguments[1];

    arguments[0] = group_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    } else {
        return SUCCESS;
    }
}

int RmGroupImpl::DeleteAllMembers(const std::string &group_id) {
    char command[] = "DELETE FROM group_members WHERE (fk_group_id = $1)";

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        Debugging::print_from_client(group_id);
    }

    const char* arguments[1];

    arguments[0] = group_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 1, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    } else {
        return SUCCESS;
    }
}
