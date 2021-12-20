#pragma once

#include <Handler.hpp>

class SynchroClientImpl : public Handler {
public:
    void process() override;
};
