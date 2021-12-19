#pragma once

#include <WriteAddressData.hpp>

class WriteAddressDataImpl : public WriteAddress {
public:
    void process() override;
};
