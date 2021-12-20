#pragma once

#include <Handler.hpp>

class AddUserContactsImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmUserContactsImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};