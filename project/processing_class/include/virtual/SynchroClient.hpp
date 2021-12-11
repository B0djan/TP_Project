#pragma once

#include <Handler.hpp>

class SynchroClient : public Handler {
public:
    virtual void process(ResCb) = 0;
};
