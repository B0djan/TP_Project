#pragma once

#include <Contacts.hpp>

#include <set>

#include <string>

class AddUserToContactsImpl : public AddUserToContacts {
public:
    void process(ResCb) override;
};

class RmUserToContactsImpl : public RmUserToContacts {
public:
    void process(ResCb) override;
};
