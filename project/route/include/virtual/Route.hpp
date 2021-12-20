#pragma once

#include <queue>

#include <map>

#include <Handler.hpp>

class Route {
public:
    std::map <std::string, Handler*> chain_links;

    virtual std::string get_response(const std::string request_body) = 0;

    virtual ~Route() = default;
};

