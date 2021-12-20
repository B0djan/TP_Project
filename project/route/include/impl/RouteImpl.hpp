#pragma once

#include <Route.hpp>

class RouteImpl : Route {
public:
    std::string get_response(const std::string request_body) override;

    RouteImpl();
    ~RouteImpl() = default;
};
