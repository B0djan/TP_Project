#pragma once

#include <Handler.hpp>

class AddUserContactsImpl : public Handler {
    std::string AddFriend(contacts_t& c);
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmUserContactsImpl : public Handler {
    std::string DeleteFriend(contacts_t& c);
public:
    ParserObject process(const ParserObject& request_body) override;  
};

char* GetId(user_t& r);