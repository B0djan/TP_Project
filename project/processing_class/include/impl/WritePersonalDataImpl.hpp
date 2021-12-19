#pragma once

#include <WritePersonalData.hpp>

class WritePersonalDataImpl : public WritePersonalData {
public:
    void process() override;
};
