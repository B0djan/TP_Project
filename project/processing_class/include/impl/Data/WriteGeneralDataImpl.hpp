#pragma once

#include <Handler.hpp>

class WriteGeneralDataImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class GetGeneralDataImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};



