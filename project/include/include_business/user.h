#pragma once

#include <string>

#include "day.h"

struct User {
    int user_id;
    std::string user_name;
    std::string user_login;
    std::string user_password;
    Day day;
};