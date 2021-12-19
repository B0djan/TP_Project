#pragma once

#include <Handler.hpp>

#include <set>

class AddUserContacts : public Handler {
public:
    virtual void process() = 0;
};

class RmUserContacts : public Handler {
public:
    virtual void process() = 0;
};
