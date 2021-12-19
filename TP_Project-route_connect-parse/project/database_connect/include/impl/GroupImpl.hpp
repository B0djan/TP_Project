#pragma once

#include "pgbackend.hpp"

class AddGroupImpl
public:
    void AddGroup();
};

class WriteGroupImpl : public WriteGroup {
public:
    void process(ResCb) override;
};

class RmGroupImpl : public RmGroup {
public:
    void process(ResCb) override;
};

class AddUserImpl : public AddUser {
public:
    void process(ResCb) override;
};

class RmUserImpl : public RmUser {
public:
    void process(ResCb) override;
};

class JoinImpl : public Join {
public:
    void process(ResCb) override;
};

class LeaveImpl : public Leave {
public:
    void process(ResCb) override;
};

class SearchGroupImpl : public SearchGroup {
public:
    void process(ResCb) override;
};

class SearchFreeTimeImpl : public SearchFreeTime {
public:
    void process(ResCb) override;  //  std::set<ParserObject>
};

class OutputHistoryMeetUpImpl : public OutputHistoryMeetUp {
public:
    void process(ResCb) override;  //  std::set<ParserObject>
};
