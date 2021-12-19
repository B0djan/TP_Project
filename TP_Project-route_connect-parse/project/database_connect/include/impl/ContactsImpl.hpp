#pragma once

#include <string>
#include <set>

#include "pgbackend.hpp"

class AddUserToContactsImpl {
public:
    int AddUserToContacts(contacts_t& c);
};

class RmUserToContactsImpl {
public:
    int RmUserToContacts(contacts_t& c);
};

class ShowUserContactsImpl {
public:
    std::set<contacts_t> ShowUserContacts(contacts_t& c);
};
