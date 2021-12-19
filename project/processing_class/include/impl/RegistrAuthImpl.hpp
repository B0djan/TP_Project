#pragma once

#include <RegistrAuth.hpp>

class RegistrationImpl : public Registration {
public:
    RegistrationImpl() : Registration() {}
    void process() override;
};

class AuthenticationImpl : public Authentication {
public:
    AuthenticationImpl() : Authentication() {}
    void process() override;
};
