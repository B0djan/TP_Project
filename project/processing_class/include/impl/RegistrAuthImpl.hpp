#pragma once

#include <Handler.hpp>

class RegistrationImpl : public Handler {
    int RegistrationTo(const user_t&);
public:
    RegistrationImpl() = default;
    ParserObject process(const ParserObject& request_body) override;
};

class AuthenticationImpl : public Handler {
    int AutorizationTo(const user_t&);
public:
    AuthenticationImpl() = default;
    ParserObject process(const ParserObject& request_body) override;
};
