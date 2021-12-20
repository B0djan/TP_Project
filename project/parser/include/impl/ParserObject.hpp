#pragma once

#include <string>

#include <set>

typedef struct {
    std::string user_id  = "";
    std::string email    = "";
    std::string password = "";
    std::string nickname = "";
} user_t;

typedef struct {
    std::string user_id  = "";
    std::string building = "";
    std::string housing  = ""; // корпус
    std::string street   = "";
    std::string city     = "";
    std::string district = "";
    std::string index    = "";
    std::string country  = "";
} addres_data_t;

typedef struct {
    std::string user_id      = "";
    std::string first_name   = "";
    std::string surname      = "";
    std::string age          = "";
    std::string phone_number = "";
    std::string status       = "";
    std::string label        = "";
    std::string description  = "";
} personal_data_t;

typedef struct {
    std::string user_id     = "";
    std::string event_name  = "";
    std::string date        = "";
    std::string description = "";
    std::string time_begin  = "";
    std::string time_end    = "";
} event_t;

typedef struct {
    std::string group_id    = "";
    std::string event_name  = "";
    std::string date        = "";
    std::string description = "";
    std::string time_begin  = "";
    std::string time_end    = "";
} meetup_t;

typedef struct {
    std::string           group_id;
    std::set<std::string> members;
} group_t;

typedef struct {
    std::string           user_id;
    std::set<std::string> contacts;
} contacts_t;

class ParserObject {
public:
    std::string head;

    user_t                    user;
    personal_data_t  personal_data;
    addres_data_t     address_data;
    event_t                  event;
    group_t                  group;
    meetup_t                meetup;
    contacts_t            contacts;


    ParserObject() = default;
    ~ParserObject() = default;

    ParserObject& operator=(const ParserObject& other) = default;

    const std::string get_head() const { return head; };
};
