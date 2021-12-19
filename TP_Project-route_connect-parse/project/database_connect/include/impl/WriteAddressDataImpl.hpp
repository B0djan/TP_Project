#pragma once

#include <WriteAddressData.hpp>

#include "pgbackend.hpp"

class WriteAddressDataImpl {
public:
    char* WriteAddress(addres_data_t&);
};