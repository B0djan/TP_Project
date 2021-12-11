#pragma once

#include <Handler.hpp>

#include <set>

class AddUserToContacts : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class RmUserToContacts : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class OutputContacts : public Handler {
public:
    virtual std::set<JSONObject> process(ResCb) = 0;
};


