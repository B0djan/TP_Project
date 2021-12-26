#include <EventImpl.hpp>

#include <iostream>

ParserObject AddEventImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        for (std::set<event_t>::iterator it = request_body.events.begin(); it != request_body.events.end(); ++it) {
            Print_struct::_event_t(*it);
        }
    }

    size_t iter = 0;
    for (auto event: request_body.events) {
        code = DatabaseConnector::Event::Add(event);
        if (code != 0) {
            response_body.error = "Error add event on iteration: ";

            response_body.error + std::to_string(iter);

            return response_body;
        }

        iter++;
    }

    return response_body;
}

/*ParserObject WriteEventImpl::process(const ParserObject& request_body) {
    int code;

    event_t event;

    ParserObject response_body;

    //  Сложности с определением нового и старого
    std::set<event_t> :: iterator it = request_body.events.begin();

    if (id.empty()) {
        char* check = GetID::Event(event);
        if (check == NULL) {
            response_body.error = "Error get event id";

            return response_body;
        }

        id = check;
    }


    code = Write(event);
    if (code != 0) {
        response_body.error = "Error write event";
    }

    id.clear();


    return response_body;
}*/

ParserObject RmEventImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    //  Отладка
    if (GLOBAL_KEY_TEST_PROCESSING) {
        for (std::set<event_t>::iterator it = request_body.events.begin(); it != request_body.events.end(); ++it) {
            Print_struct::_event_t(*it);
        }
    }

    size_t iter = 0;
    for (auto event: request_body.events) {
        code = DatabaseConnector::Event::Delete(event);
        if (code != 0) {
            response_body.error = "Error delete event on iteration: ";

            response_body.error + std::to_string(iter);

            return response_body;
        }

        iter++;
    }

    return response_body;
}
