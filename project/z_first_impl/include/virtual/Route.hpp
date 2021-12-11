#pragma once

#include <functional>

#include <set>

typedef std::string str;

class Route {
public:
    //  classification
    virtual void check_request(str request) = 0;
};
