#include <EventImpl.hpp>

#include <iostream>

ParserObject AddEventImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<event_t> :: iterator it = request_body.events.begin();

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        for (std::set<event_t>::iterator it = request_body.events.begin(); it != request_body.events.end(); ++it) {
            Debugging::print_event_t(*it);
        }
    }

    size_t iter = 0;
    for (auto event: request_body.events) {
        code = AddEvent(event);
        if (code != 0) {
            response_body.error = "Error add event on iteration: ";

            response_body.error + std::to_string(iter);

            return response_body;
        }

        iter++;
    }

    return response_body;
}

ParserObject WriteEventImpl::process(const ParserObject& request_body) {
    int code;

    event_t event;

    ParserObject response_body;

    std::set<event_t> :: iterator it = request_body.events.begin();

    if (id.empty()) {
        char* check = SupportProcess::GetEventId(event);
        if (check == NULL) {
            response_body.error = "Error get event id";

            return response_body;
        }

        id = check;
    }


    code = WriteEvent(event);
    if (code != 0) {
        response_body.error = "Error write event";
    }

    id.clear();


    return response_body;
}

ParserObject RmEventImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<event_t> :: iterator it = request_body.events.begin();

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        for (std::set<event_t>::iterator it = request_body.events.begin(); it != request_body.events.end(); ++it) {
            Debugging::print_event_t(*it);
        }
    }

    size_t iter = 0;
    for (auto event: request_body.events) {
        code = DeleteEvent(event);
        if (code != 0) {
            response_body.error = "Error delete event on iteration: ";

            response_body.error + std::to_string(iter);

            return response_body;
        }

        iter++;
    }

    return response_body;
}

int AddEventImpl::AddEvent(const event_t& e) {
    char command[] = "INSERT INTO event_m (event_date, time_begin, time_end, description, fk_user_id) VALUES ($1, $2, $3, $4, $5)";

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        Debugging::print_event_t(e);
    }

    const char* arguments[5];

    arguments[0] = e.date.c_str();
    arguments[1] = e.time_begin.c_str();
    arguments[2] = e.time_end.c_str();
    arguments[3] = e.description.c_str();
    arguments[4] = e.user_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 5, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    } else {
        return SUCCESS;
    }
}


int WriteEventImpl::WriteEvent(const event_t& e) {
    char command[] = "UPDATE event_m "
                     "SET (event_date = $1, time_begin = $2, time_end = $3, description = $4)"
                     "WHERE (fk_user_id = $5)";


    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        Debugging::print_event_t(e);
    }

    const char* arguments[5];

    arguments[0] = e.event_name.c_str();
    arguments[1] = e.time_begin.c_str();
    arguments[2] = e.time_end.c_str();
    arguments[3] = e.description.c_str();
    arguments[4] = id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 5, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    } else {
        return SUCCESS;
    }
}


int RmEventImpl::DeleteEvent(const event_t& e){
    char command[] = "DELETE FROM event_m WHERE (event_date = $1) AND (time_begin = $2) AND (time_end = $3) AND (fk_user_id = $4)";

    const char* arguments[4];

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        Debugging::print_event_t(e);
    }

    arguments[0] = e.event_name.c_str();
    arguments[1] = e.time_begin.c_str();
    arguments[2] = e.time_end.c_str();
    arguments[3] = e.user_id.c_str();

    PGresult *res = PQexecParams(PGConnection::GetConnection(), command, 4, NULL, arguments, NULL, NULL, 0);

    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        printf("command faild: %s\n", PQerrorMessage(PGConnection::GetConnection()));

        PQclear(res);

        return ERROR;
    } else {
        return SUCCESS;
    }
}
