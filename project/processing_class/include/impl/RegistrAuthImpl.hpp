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

int RegistrationTo(user_t& r);

int AutorizationTo(user_t& r);

char* GetId(user_t& r);
