#pragma once

#include <queue>

#include <Handler.hpp>

#include <LinkRequestHandlerImpl.hpp>

class Route {
public:
    std::queue<ParserObject> request_queue;

    LinkRequestHandlerImpl processing_map;

    virtual Handler* find_handler() = 0;

    virtual ~Route() = default;
};
