#pragma once

#include <queue>

#include <map>

#include <Handler.hpp>

class Route {
public:
    std::queue<ParserObject> request_queue;

    std::map <std::string, Handler*> chain_links;


    virtual ParserObject get_response() = 0;

    virtual void schedule(ParserObject request) = 0;

    virtual ~Route() = default;
};

