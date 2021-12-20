#pragma once

#include <Parser.hpp>

class ParserRegistrationImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserRegistrationImpl() = default;
};

class ParserAuthenticationImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserAuthenticationImpl() = default;
};
