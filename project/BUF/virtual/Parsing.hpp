#pragma once

#include <string>

#include "../../parser/include/ParserObject.hpp"

class Parsing {
public:
    virtual ParserObject StrToObject(const std::string parser_str) = 0;

    virtual std::string ObjectToStr(const ParserObject& other) = 0;

    virtual ~Parsing() = default;
};
