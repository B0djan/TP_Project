#pragma once

#include <functional>

#include <string>

#include <libpq-fe.h>

#include <ParserObject.hpp>

#include <PGConnection.hpp>

#include <DataBaseConnectorImpl.hpp>

#define GLOBAL_KEY_TEST_PROCESSING false

class Handler {
public:
    //  using ResCb = std::function<void(bool success)>;

    virtual ParserObject process(const ParserObject &request_body) = 0;

    virtual ~Handler() = default;
};
