#pragma once

#include <Route.hpp>

class RouteImpl : Route {
public:
    void schedule(ParserObject request) override;

    ParserObject get_response() override;

    RouteImpl() = default;
    ~RouteImpl() = default;
};
