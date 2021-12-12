#pragma once

#include <RegistrAuth.hpp>

class RegistrationImpl : public Registration {
public:
    RegistrationImpl() : Registration() {}
    void process(ResCb) override;
};

class AuthenticationImpl : public Authentication {
public:
    AuthenticationImpl() : Authentication() {}
    void process(ResCb) override;
};
