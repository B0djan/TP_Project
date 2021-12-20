#pragma once

#include <Parsing.hpp>

class ParserSynchroClientEventsImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserSynchroClientEventsImpl() = default;
};

class ParserSynchroClientContactsImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserSynchroClientContactsImpl() = default;
};

class ParserSynchroClientGroupsImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserSynchroClientGroupsImpl() = default;
};
