#pragma once

#include <set>

#include <Group.hpp>

class AddGroupImpl : public AddGroup {
public:
    void process(ResCb) override;
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
    std::set<JSONObject> process(ResCb) override;
};

class OutputHistoryMeetUpImpl : public OutputHistoryMeetUp {
public:
    std::set<JSONObject> process(ResCb) override;
};
