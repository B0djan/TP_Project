#pragma once

#include <set>

#include <Handler.hpp>

class AddGroup : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class WriteGroup : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class RmGroup : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class AddUser : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class RmUser : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class Join : public Handler {
public:
    virtual void process(ResCb) = 0;
};
class Leave : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class SearchGroup : public Handler {
public:
    virtual void process(ResCb) = 0;
};

class SearchFreeTime : public Handler {
public:
    virtual void process(ResCb) = 0;  //  std::set<ParserObject>
};

class OutputHistoryMeetUp : public Handler {
public:
    virtual void process(ResCb) = 0;  //  std::set<ParserObject>
};
