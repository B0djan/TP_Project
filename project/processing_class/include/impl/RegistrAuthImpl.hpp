#pragma once

#include <Handler.hpp>

class RegistrationImpl : public Handler {
    int RegistrationTo(user_t& r);
public:
    RegistrationImpl() = default;
    ParserObject process(const ParserObject& request_body) override;
};

class AuthenticationImpl : public Handler {
    int AutorizationTo(user_t& r);
public:
    AuthenticationImpl() = default;
    ParserObject process(const ParserObject& request_body) override;
};
