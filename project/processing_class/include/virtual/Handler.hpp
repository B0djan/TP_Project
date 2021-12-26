#pragma once

#include <functional>

#include <string>

#include <libpq-fe.h>

#include <ParserObject.hpp>

#include <PGConnection.hpp>

#define GLOBAL_KEY_TEST_PROCESSING true

#define SUCCESS     0
#define ERROR      -1

class Handler {
public:
    //  using ResCb = std::function<void(bool success)>;

    virtual ParserObject process(const ParserObject &request_body) = 0;

    virtual ~Handler() = default;
};

namespace SupportProcess {
    char* GetUserId(const std::string& nickname);  //  промежуточный класс

    char* GetEventId(const event_t& e);  //  промежуточный класс

    char* GetGroupId(const std::string& title);  //  промежуточный класс
}

namespace SupportProcessGroup {
    int AddMember(const std::string& member, const std::string);

    int RmMember(const std::string& member, const std::string);
}

namespace SupportPersonalData {
    int CreateAddressData(const std::string& user_id);

    int CreatePersonalData(const std::string& user_id);
}