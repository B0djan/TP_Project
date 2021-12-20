#pragma once

#include <set>

#include <Handler.hpp>

class AddGroupImpl : public Handler {
public:
    void process() override;
};

class WriteGroupImpl : public Handler {
public:
    void process() override;
};

class RmGroupImpl : public Handler {
public:
    void process() override;
};

class AddUserImpl : public Handler {
public:
    void process() override;
};

class RmUserImpl : public Handler {
public:
    void process() override;
};

class JoinImpl : public Handler {
public:
    void process() override;
};

class LeaveImpl : public Handler {
public:
    void process() override;
};

class SearchGroupImpl : public Handler {
public:
    void process() override;
};

class SearchFreeTimeImpl : public Handler {
public:
    void process() override;  //  std::set<ParserObject>
};

class OutputHistoryMeetUpImpl : public Handler {
public:
    void process() override;  //  std::set<ParserObject>
};
