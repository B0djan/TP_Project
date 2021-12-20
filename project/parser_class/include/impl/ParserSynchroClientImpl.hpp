#pragma once

#include <Parser.hpp>

class ParserSynchroClientEventsImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserSynchroClientEventsImpl() = default;
};

class ParserSynchroClientContactsImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserSynchroClientContactsImpl() = default;
};

class ParserSynchroClientGroupsImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserSynchroClientGroupsImpl() = default;
};
