#pragma once

#include <Route.hpp>

class RouteImpl : Route {
public:
    ParserObject get_response(const ParserObject& request_body) override;

    RouteImpl();
    ~RouteImpl() = default;
};
