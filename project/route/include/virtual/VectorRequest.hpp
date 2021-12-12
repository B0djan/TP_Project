#pragma once

#include <vector>
#include <string>

class VectorRequest {
public:
    std::vector<std::string> request_chain;

    size_t capacity;

    virtual ~VectorRequest() = default;
};
