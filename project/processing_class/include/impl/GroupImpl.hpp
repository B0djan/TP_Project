#pragma once

#include <set>

#include <Handler.hpp>

class AddGroupImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class WriteGroupImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmGroupImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class AddUserImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmUserImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class JoinImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class LeaveImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class SearchGroupImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class SearchFreeTimeImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;  //  std::set<ParserObject>
};

class OutputHistoryMeetUpImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;  //  std::set<ParserObject>
};
