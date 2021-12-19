#pragma once

#include <vector>
#include <map>

#include <Handler.hpp>

class LinkRequestHandler {
public:
    std::map <std::string, Handler*> chain_links;

    virtual ~LinkRequestHandler() = default;
};
