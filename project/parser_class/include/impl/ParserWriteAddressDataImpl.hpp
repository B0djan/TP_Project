#pragma once

#include <Parser.hpp>

class ParserWriteAddressDataImpl : public Parser {
public:
    ParserObject StrToObject(std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserWriteAddressDataImpl() = default;
};