#pragma once

#include <string>
#include <set>
#include <vector>

#include <functional>

#include <libpq-fe.h>

#include <ParserObject.hpp>

#include "../../../database_connector/PostgreSQL/include/PGConnection.hpp"

#include "../../../database_connector/include/impl/DataBaseConnectorImpl.hpp"

#define GLOBAL_KEY_TEST_PROCESSING true

class Handler {
public:
    virtual ParserObject process(const ParserObject &request_body) = 0;

    virtual ~Handler() = default;
};
