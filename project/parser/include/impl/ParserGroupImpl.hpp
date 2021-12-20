#pragma once

#include <Parsing.hpp>

class ParserAddGroupImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserAddGroupImpl() = default;
};

class ParserWriteGroupImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserWriteGroupImpl() = default;
};

class ParserRmGroupImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserRmGroupImpl() = default;
};

class ParserAddUserImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserAddUserImpl() = default;
};

class ParserRmUserImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserRmUserImpl() = default;
};

class ParserJoinImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserJoinImpl() = default;
};

class ParserLeaveImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserLeaveImpl() = default;
};

class ParserSearchGroupImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserSearchGroupImpl() = default;
};

class ParserSearchFreeTimeImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserSearchFreeTimeImpl() = default;
};

class ParserOutputHistoryMeetUpImpl : public Parsing {
public:
    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~ParserOutputHistoryMeetUpImpl() = default;
};
