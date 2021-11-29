#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>

#include "date.h"
#include "duration.h"

class Event {
    size_t user_id = 0;
    std::string event = "";
    std::string date = "";
    std::string begin = "";
    std::string end = "";
    size_t group_id = 0;
    bool flag = false; // по умолчанию нельзя двигать двигать

public:
    Event(std::string& s);
    // std::ostream& operator<<(std::ostream& stream) {
    //     stream << "user_id: " << user_id << std::endl;
    //     stream << "event: " << event << std::endl;
    //     stream << "date: " << date << std::endl;
    //     stream << "begin: " << begin << std::endl;
    //     stream << "end: " << end << std::endl;
    //     stream << "group_id: " << group_id << std::endl;
    //     return stream;
    // }

    size_t GetUserId();
    size_t GetGroupId();
    std::string GetEvent();
    std::string GetDate();
    std::string GetBegin();
    std::string GetEnd();
};