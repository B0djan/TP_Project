#pragma once

#include <Parser.hpp>

class ParserGroupImpl : public Parser {
public:
    ParserObject StrToObject(const std::string& parser_str) const override;

    std::string ObjectToStr(const ParserObject& other) const override;

    ~ParserGroupImpl() = default;
};

class ParserUserGroupImpl : public Parser {
public:
    ParserObject StrToObject(const std::string& parser_str) const override;

    std::string ObjectToStr(const ParserObject& other) const override;

    ~ParserUserGroupImpl() = default;
};

class ParserMeetUpImpl : public Parser {
public:
    ParserObject StrToObject(const std::string& parser_str) const override;

    std::string ObjectToStr(const ParserObject& other) const override;

    ~ParserMeetUpImpl() = default;
};


