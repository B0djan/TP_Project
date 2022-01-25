#pragma once

#include <Structs.hpp>

class ParserObject {
public:
    user_t                       user;
    personal_data_t     personal_data;
    general_data_t       general_data;
    address_data_t       address_data;
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
    ParserObject& operator=(const address_data_t other)             { this->address_data = other;        return *this; };
    ParserObject& operator=(const std::set<event_t> other)          { this->events = other;              return *this; };
    ParserObject& operator=(const std::set<group_t> other)          { this->groups = other;              return *this; };
    ParserObject& operator=(const std::set<meetup_t> other)         { this->meetups = other;             return *this; };
    ParserObject& operator=(const contacts_t other)                 { this->contacts = other;            return *this; };
    ParserObject& operator=(const general_data_t other)             { this->general_data = other;        return *this; };
};
