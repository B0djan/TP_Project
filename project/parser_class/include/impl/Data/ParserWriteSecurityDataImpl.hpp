#pragma once

#include <Parser.hpp>

class ParserWriteSecurityDataImpl : public Parser {
public:
    ParserObject StrToObject(const std::string& parser_str) const override;

    std::string ObjectToStr(const std::string type_response, const ParserObject& other) const override;

    ~ParserWriteSecurityDataImpl() = default;
};
