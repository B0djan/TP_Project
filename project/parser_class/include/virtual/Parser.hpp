#pragma once

#include <string>

#include "ParserObject.hpp"

class Parser {
public:
    virtual ParserObject StrToObject(std::string parser_str) = 0;

    virtual std::string ObjectToStr(const ParserObject& other) = 0;

    virtual ~Parser() = default;
};
