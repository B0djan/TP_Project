#pragma once

#include <Handler.hpp>

class SynchroClientEventsImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class SynchroClientContactsImpl : public Handler {
    std::set<std::string> GetContacts(const std::string&);
public:
    ParserObject process(const ParserObject& request_body) override;
};

class SynchroClientGroupsImpl : public Handler {
    std::set<std::string> GetGroups(const std::string&);
public:
    ParserObject process(const ParserObject& request_body) override;
};
