#include <string>

#include <set>

#include "json.hpp"

#include "ParserObject.hpp"

    bool operator< (const event_t& lhs, const event_t& rhs) {
    return lhs.time_begin < rhs.time_begin;
    }

    bool operator< (const meetup_t& lhs, const meetup_t& rhs) {
    return lhs.time_begin < rhs.time_begin;
    }

    bool operator< (const group_t& lhs, const group_t& rhs) {
    return lhs.title < rhs.title;
    }
