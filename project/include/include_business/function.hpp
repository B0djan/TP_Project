#pragma once

#include "../../include/include_business/day.hpp"
#include "../../include/include_business/structs.hpp"

Day GetFreeDay(std::set<std::set<event_t>> group_events);