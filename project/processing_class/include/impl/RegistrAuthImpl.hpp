#pragma once

#include <Handler.hpp>

class RegistrationImpl : public Handler {
public:
    RegistrationImpl() : Handler() {}
    void process() override;
};

class AuthenticationImpl : public Handler {
public:
    AuthenticationImpl() : Handler() {}
    void process() override;
};
