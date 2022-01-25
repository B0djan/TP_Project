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
    event_t buf;
    for (auto event: request_body.events) {
        code = DatabaseConnector::Event::Add(event);
        if (code != 0) {
            response_body.error = "Error add event on iteration: ";

            response_body.error + std::to_string(iter);

            return response_body;
        }

        iter++;

        char* check = DatabaseConnector::GetID::Event(event);
        if (check == NULL) {
            response_body.error = "Error get user id";

            return response_body;
        }

        buf.event_id = check;

        response_body.events.insert(buf);
    }


    return response_body;
}

ParserObject WriteEventImpl::process(const ParserObject& request_body) {
    int code;

    ParserObject response_body;

    std::set<event_t> :: iterator it = request_body.events.begin();

    code = DatabaseConnector::Event::Write(*it);
    if (code != 0) {
        response_body.error = "Error write event";

        return response_body;
    }

    return response_body;
}

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
        code = DatabaseConnector::Event::Delete(event.event_id);
        if (code != 0) {
            response_body.error = "Error delete event on iteration: ";

            response_body.error + std::to_string(iter);

            return response_body;
        }

        iter++;
    }

    return response_body;
}
