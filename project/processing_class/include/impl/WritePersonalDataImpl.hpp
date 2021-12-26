#pragma once

#include <Handler.hpp>

class WritePersonalDataImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class GetPersonalDataImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};


