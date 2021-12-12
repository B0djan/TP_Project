#pragma once

#include <set>

#include <Event.hpp>

class AddEventImpl : public AddEvent {
public:
    void process(ResCb) override;
};

class WriteEventImpl : public WriteEvent {
public:
    void process(ResCb) override;
};

class RmEventImpl : public RmEvent {
public:
    void process(ResCb) override;

};
