#pragma once

#include <set>

#include <Parsing.hpp>

class ParserAddEventImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserAddEventImpl() = default;
};

class ParserWriteEventImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserWriteEventImpl() = default;
};

class ParserRmEventImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserRmEventImpl() = default;
};

