#pragma once

#include <Handler.hpp>

class SynchroClient : public Handler {
public:
    virtual void process() = 0;
};
