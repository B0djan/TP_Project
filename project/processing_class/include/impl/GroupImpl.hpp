#pragma once

#include <set>

#include <Group.hpp>

class AddGroupImpl : public AddGroup {
public:
    void process() override;
};

class WriteGroupImpl : public WriteGroup {
public:
    void process() override;
};

class RmGroupImpl : public RmGroup {
public:
    void process() override;
};

class AddUserImpl : public AddUser {
public:
    void process() override;
};

class RmUserImpl : public RmUser {
public:
    void process() override;
};

class JoinImpl : public Join {
public:
    void process() override;
};

class LeaveImpl : public Leave {
public:
    void process() override;
};

class SearchGroupImpl : public SearchGroup {
public:
    void process() override;
};

class SearchFreeTimeImpl : public SearchFreeTime {
public:
    void process() override;  //  std::set<ParserObject>
};

class OutputHistoryMeetUpImpl : public OutputHistoryMeetUp {
public:
    void process() override;  //  std::set<ParserObject>
};
