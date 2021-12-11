#pragma once

#include <Handler.hpp>

class WriteAddress : public Handler {
public:
    virtual void process(ResCb) = 0;
};
