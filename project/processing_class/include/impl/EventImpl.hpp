#pragma once

#include <set>

#include <Handler.hpp>

class AddEventImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class WriteEventImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmEventImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;

};
