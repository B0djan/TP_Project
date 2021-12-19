#pragma once

#include <SynchroClient.hpp>

class SynchroClientImpl : public SynchroClient {
public:
    void process() override;
};
