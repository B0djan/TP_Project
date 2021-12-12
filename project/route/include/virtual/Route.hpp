#pragma once

#include <vector>
#include <string>

class Route {
public:
    std::vector<std::string> request_chain;
    virtual ~Route() = default;
};
