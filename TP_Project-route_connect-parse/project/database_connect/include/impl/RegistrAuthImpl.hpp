#pragma once

#include "pgbackend.hpp"

class RegistrationImpl {
public:
    char* Registration(user_t& r);
};

class AuthenticationImpl {
public:
    int Authentication(user_t& r);
};
