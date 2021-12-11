#pragma once

#include <Handler.hpp>

class WritePersonalData : public Handler {
public:
    virtual void process(ResCb) = 0;
};


