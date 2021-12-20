#pragma once

#include <Parsing.hpp>

class ParserAddUserContactsImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserAddUserContactsImpl() = default;
};

class ParserRmUserContactsImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserRmUserContactsImpl() = default;
};