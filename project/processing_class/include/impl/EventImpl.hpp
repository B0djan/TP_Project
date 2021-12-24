#pragma once

#include <set>

#include <Handler.hpp>

class AddEventImpl : public Handler {
    int AddEvent(event_t&);
public:
    ParserObject process(const ParserObject& request_body) override;
};

class WriteEventImpl : public Handler {
    std::string id;
    int WriteEvent(event_t&, std::string& id);
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmEventImpl : public Handler {
    int DeleteEvent(event_t&);
public:
    ParserObject process(const ParserObject& request_body) override;

};
