#pragma once

#include <queue>

#include <Handler.hpp>

#include <LinkRequestHandlerImpl.hpp>

class Route {
public:
    std::queue<ParserObject> request_queue;

    LinkRequestHandlerImpl processing_map;

    virtual ParserObject get_response() = 0;

    virtual void schedule(ParserObject request) = 0;

    virtual ~Route() = default;
};
