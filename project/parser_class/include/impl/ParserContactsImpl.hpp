#pragma once

#include <Parser.hpp>

class ParserAddUserContactsImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserAddUserContactsImpl() = default;
};

class ParserRmUserContactsImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserRmUserContactsImpl() = default;
};