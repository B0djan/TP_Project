#pragma once

#include <Handler.hpp>

class Registration : public Handler {
public:
    Registration() : Handler() {}
    virtual void process() = 0;
};

class Authentication : public Handler {
public:
    Authentication() : Handler() {}
    virtual void process() = 0;
};
