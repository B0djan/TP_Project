#pragma once

#include <Handler.hpp>

class Registration : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class Authentication : public Handler {
public:
    virtual void process(ResCb) = 0;
};
