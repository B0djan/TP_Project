#pragma once

#include <vector>

#include <Handler.hpp>

class VectorHandler {
public:
    std::vector<Handler*> handler_chain;

    size_t capacity;

    virtual ~VectorHandler() = default;
};
