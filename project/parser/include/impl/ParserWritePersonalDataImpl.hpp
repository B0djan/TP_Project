#pragma once

#include <Parsing.hpp>

class ParserWritePersonalDataImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserWritePersonalDataImpl() = default;
};
