#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>

#include "date.h"
#include "duration.h"

class Event {
private:
    size_t user_id = 0;
    std::string event = "";
    std::string date = "";
    std::string begin = "";
    std::string end = "";
    size_t group_id = 0;
    bool flag = false; // по умолчанию нельзя двигать двигать

public:
    Event(std::string& s);

    size_t GetUserId() const;
    size_t GetGroupId() const;
    std::string GetEvent() const;
    std::string GetDate() const;
    std::string GetBegin() const;
    std::string GetEnd() const;
};