#pragma once

#include <Parser.hpp>

class ParserUserContactsImpl : public Parser {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserUserContactsImpl() = default;
};
