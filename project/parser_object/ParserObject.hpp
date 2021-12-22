#pragma once

#include <string>

#include <set>

typedef struct {
    std::string user_id  = "";
    std::string email    = "";
    std::string password = "";
    std::string nickname = "";
    std::string login = "";
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
    std::string           title;
    std::set<std::string> members;
} group_t;

typedef struct {
    std::string           user_id;
    std::set<std::string> contacts;
} contacts_t;

class ParserObject {
public:
    user_t                    user;
    personal_data_t  personal_data;
    addres_data_t     address_data;
    std::set<event_t>        event;
    std::set<group_t>        group;
    std::set<meetup_t>      meetup;
    contacts_t            contacts;
    std::string              error;


    ParserObject() = default;
    ~ParserObject() = default;

    ParserObject& operator=(const user_t other)             { this->user = other;               return *this; };
    ParserObject& operator=(const personal_data_t other)    { this->personal_data = other;      return *this; };
    ParserObject& operator=(const addres_data_t other)      { this->address_data = other;       return *this; };
    ParserObject& operator=(const event_t other)            { this->event.insert(other);        return *this; };
    ParserObject& operator=(const group_t other)            { this->group.insert(other);        return *this; };
    ParserObject& operator=(const meetup_t other)           { this->meetup.insert(other);       return *this; };
    ParserObject& operator=(const contacts_t other)         { this->contacts = other;           return *this; };
};
