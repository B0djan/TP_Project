#pragma once

#include <Contacts.hpp>

#include <set>

#include <string>

class AddUserContactsImpl : public AddUserContacts {
public:
    void process(ResCb) override;
};

class RmUserContactsImpl : public RmUserContacts {
public:
    void process(ResCb) override;
};
