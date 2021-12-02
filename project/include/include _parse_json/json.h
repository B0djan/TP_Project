#include "nlohmann/json.hpp"
#include  "event.h"

#include <string>

typedef struct {
    std::string login      = "";
    std::string password   = "";
} User_Registration_Data;

typedef struct {
    std::string building   = "";
    std::string housing    = ""; // корпус 
    std::string street     = "";
    std::string city       = "";
    std::string region     = "";
    std::string index      = "";
    std::string country    = "";
} User_Address;

typedef struct {
    size_t user_id;
    std::string email      = "";
    std::string first_name = "";
    std::string surname    = "";
    User_Address address;
    size_t age;
} User_data;

typedef struct {
    size_t user_id;
    std::string event_name = "";
    std::string date       = "";
    std::string time_begin = "";
    std::string time_end   = "";
} User_event;