#pragma once

#include <Handler.hpp>

class AddUserContactsImpl : public Handler {
    int AddFriend(const std::string& user_id_main, const std::string& user_id_friend);
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmUserContactsImpl : public Handler {
    int DeleteFriend(const std::string& user_id_main, const std::string& user_id_friend);
public:
    ParserObject process(const ParserObject& request_body) override;  
};

char* GetId(user_t& r);