#pragma once

#include <Handler.hpp>

class RegistrationImpl : public Handler {
public:
    RegistrationImpl() = default;
    ParserObject process(const ParserObject& request_body)override;
};

class AuthenticationImpl : public Handler {
public:
    AuthenticationImpl() = default;
    ParserObject process(const ParserObject& request_body) override;
};
