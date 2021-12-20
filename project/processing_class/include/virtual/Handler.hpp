#pragma once

#include <functional>

#include <string>

#include <ParserObject.hpp>

class Handler {
public:
    //  using ResCb = std::function<void(bool success)>;

    virtual ParserObject process(const ParserObject &request_body) = 0;

    virtual ~Handler() = default;
};