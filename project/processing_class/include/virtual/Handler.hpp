#pragma once

#include <functional>

#include <string>

#include "ParserObject.hpp"

#include "libpq-fe.h"

#include "PGConnection.hpp"

#define SUCCESS     0
#define ERROR      -1

class Handler {
public:
    //  using ResCb = std::function<void(bool success)>;

    virtual ParserObject process(const ParserObject &request_body) = 0;

    virtual ~Handler() = default;
};