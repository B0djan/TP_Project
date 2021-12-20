#pragma once

#include <set>

#include <Parser.hpp>

class ParserAddEventImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserAddEventImpl() = default;
};

class ParserWriteEventImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserWriteEventImpl() = default;
};

class ParserRmEventImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserRmEventImpl() = default;
};

