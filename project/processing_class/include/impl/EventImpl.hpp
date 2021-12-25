#pragma once

#include <set>

#include <Handler.hpp>

class AddEventImpl : public Handler {
    int AddEvent(const event_t&);
public:
    ParserObject process(const ParserObject& request_body) override;
};

class WriteEventImpl : public Handler {
    std::string id;
    int WriteEvent(const event_t&);
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmEventImpl : public Handler {
    int DeleteEvent(const event_t&);
public:
    ParserObject process(const ParserObject& request_body) override;

};
