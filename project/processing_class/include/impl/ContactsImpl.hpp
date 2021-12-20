#pragma once

#include <Handler.hpp>

#include <set>

#include <string>

class AddUserContactsImpl : public Handler {
public:
    void process() override;
};

class RmUserContactsImpl : public Handler {
public:
    void process() override;
};
