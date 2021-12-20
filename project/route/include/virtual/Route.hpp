#pragma once

#include <queue>

#include <map>

#include <Handler.hpp>

class Route {
public:
    std::map <std::string, Handler*> chain_links;

    virtual ParserObject get_response(const ParserObject& request_body) = 0;

    virtual ~Route() = default;
};

