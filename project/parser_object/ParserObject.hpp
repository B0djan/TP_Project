#pragma once

#include <string>

#include <set>

#include "json.hpp"

typedef struct {
    std::string user_id  = "";
    std::string email    = "";
    std::string password = "";
    std::string nickname = "";
} user_t;

typedef struct {
    std::string user_id  = "";
    std::string building = "";
    std::string housing  = "";
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

bool operator< (const event_t& lhs, const event_t& rhs) {
    return lhs.time_begin < rhs.time_begin;
}

bool operator< (const meetup_t& lhs, const meetup_t& rhs) {
    return lhs.time_begin < rhs.time_begin;
}

bool operator< (const group_t& lhs, const group_t& rhs) {
    return lhs.title < rhs.title;
}


class ParserObject {
public:
    user_t                       user;
    personal_data_t     personal_data;
    addres_data_t        address_data;
    std::set<event_t>          events;
    std::set<group_t>          groups;
    std::set<meetup_t>        meetups;
    contacts_t               contacts;

    std::string                 error;


    ParserObject() = default;
    ParserObject(const ParserObject& other) = default;
    ~ParserObject() = default;

    ParserObject& operator=(const user_t other)                     { this->user = other;                return *this; };
    ParserObject& operator=(const personal_data_t other)            { this->personal_data = other;       return *this; };
    ParserObject& operator=(const addres_data_t other)              { this->address_data = other;        return *this; };
    ParserObject& operator=(const std::set<event_t> other)          { this->events = other;              return *this; };
    ParserObject& operator=(const std::set<group_t> other)          { this->groups = other;              return *this; };
    ParserObject& operator=(const std::set<meetup_t> other)         { this->meetups = other;             return *this; };
    ParserObject& operator=(const contacts_t other)                 { this->contacts = other;            return *this; };
};
