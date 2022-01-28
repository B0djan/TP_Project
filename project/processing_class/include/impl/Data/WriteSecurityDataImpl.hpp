#pragma once

#include <Handler.hpp>

class WritePasswordImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class WriteNicknameImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};


