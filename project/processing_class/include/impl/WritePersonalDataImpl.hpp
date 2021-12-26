#pragma once

#include <Handler.hpp>

class WritePersonalDataImpl : public Handler {
    int ReWritePersonalData(const personal_data_t&);
public:
    ParserObject process(const ParserObject& request_body) override;
};

class GetPersonalDataImpl : public Handler {
    personal_data_t GetPersonalData(const std::string& user_id);
public:
    ParserObject process(const ParserObject& request_body) override;
};


