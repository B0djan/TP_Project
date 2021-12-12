#pragma once

#include <Route.hpp>

class RouteImpl : Route {
public:
    //void run_until_complete() override;

    Handler* find_handler(ParserObject request) override;

    RouteImpl() = default;
    ~RouteImpl() = default;
};
