#pragma once

#include <Handler.hpp>

class WriteAddressDataImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class GetAddressDataImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};
