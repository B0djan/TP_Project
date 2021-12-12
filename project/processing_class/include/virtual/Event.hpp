#pragma once

#include <set>

#include <Handler.hpp>

class AddEvent : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class WriteEvent : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class RmEvent : public Handler {
public:
    virtual void process(ResCb) = 0;
};
