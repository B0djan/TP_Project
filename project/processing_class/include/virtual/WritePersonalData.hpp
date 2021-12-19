#pragma once

#include <Handler.hpp>

class WritePersonalData : public Handler {
public:
    virtual void process() = 0;
};


