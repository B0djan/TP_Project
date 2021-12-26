#pragma once

#include <Handler.hpp>

class SynchroClientEventsImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class SynchroClientContactsImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class SynchroClientGroupsImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};
