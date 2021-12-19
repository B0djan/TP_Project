#pragma once

#include <set>

#include <Event.hpp>

class AddEventImpl : public AddEvent {
public:
    void process() override;
};

class WriteEventImpl : public WriteEvent {
public:
    void process() override;
};

class RmEventImpl : public RmEvent {
public:
    void process() override;

};
