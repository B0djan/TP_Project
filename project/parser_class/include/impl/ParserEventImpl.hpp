#pragma once

#include <set>

#include <Parser.hpp>

class ParserEventImpl : public Parser {
public:
    ParserObject StrToObject(const std::string& parser_str) const override;

    std::string ObjectToStr(const ParserObject& other) const override;

    ~ParserEventImpl() = default;
};

