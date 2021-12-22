#pragma once

#include <string>

#include "ParserObject.hpp"

#include "nlohmann/json.hpp"

class Parser {
public:
    virtual ParserObject StrToObject(const std::string& parser_str) = 0;

    virtual std::string ObjectToStr(const ParserObject& other) = 0;

    virtual ~Parser() = default;
};
