#pragma once

#include <Parsing.hpp>

class ParserWriteAddressDataImpl : public Parsing {
public:
    ParserObject StrToObject(std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserWriteAddressDataImpl() = default;
};