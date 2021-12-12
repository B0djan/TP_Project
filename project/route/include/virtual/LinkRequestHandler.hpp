#pragma once

#include <vector>
#include <set>

#include <Handler.hpp>

class LinkRequestHandler {
public:
    std::set <std::string, Handler*> chain_links;

    virtual ~LinkRequestHandler() = default;
};
