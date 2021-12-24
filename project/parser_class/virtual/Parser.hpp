#pragma once

#include <string>

#include "ParserObject.hpp"

#include "json.hpp"


class Parser {
public:
    virtual ParserObject StrToObject(const std::string& parser_str) const = 0;

    virtual std::string ObjectToStr(const std::string type_response, const ParserObject& other) const = 0;

    virtual ~Parser() = default;
};