#pragma once

#include <Parser.hpp>

class ParserRegistrAuthImpl : public Parser {
public:
    ParserObject StrToObject(const std::string& parser_str) const override;

    std::string ObjectToStr(const ParserObject& other) const override;

    ~ParserRegistrAuthImpl() = default;
};

