#pragma once

#include <Handler.hpp>

class WriteAddressDataImpl : public Handler {
    int ReWriteAddress(const address_data_t&);
public:
    ParserObject process(const ParserObject& request_body) override;
};

class GetAddressDataImpl : public Handler {
    address_data_t GetAddressData(const std::string& user_id);
public:
    ParserObject process(const ParserObject& request_body) override;
};
