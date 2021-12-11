#pragma once

#include <Contacts.hpp>

#include <set>

class AddUserToContactsImpl : public AddUserToContacts {
public:
    void process(ResCb) override;
};

class RmUserToContactsImpl : public RmUserToContacts {
public:
    void process(ResCb) override;
};

class OutputContactsImpl : public OutputContacts {
public:
    std::set<ParserObject> process(ResCb) override;
};


