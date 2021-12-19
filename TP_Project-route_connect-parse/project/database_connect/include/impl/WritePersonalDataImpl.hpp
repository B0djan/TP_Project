#pragma once

#include <WritePersonalData.hpp>

#include "pgbackend.hpp"

class WritePersonalDataImpl : public WritePersonalData {
public:
    void process(ResCb) override;
};
