#pragma once

#include <RegistrAuth.hpp>

class RegistrationImpl : public Registration {
public:
    void process(ResCb) override;
};

class AuthenticationImpl : public Authentication {
public:
    void process(ResCb) override;
};
