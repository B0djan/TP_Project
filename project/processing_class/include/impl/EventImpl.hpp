#pragma once

#include <set>

#include <Handler.hpp>

class AddEventImpl : public Handler {
public:
    void process() override;
};

class WriteEventImpl : public Handler {
public:
    void process() override;
};

class RmEventImpl : public Handler {
public:
    void process() override;

};
