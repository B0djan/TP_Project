#pragma once

#include <string>

#include <set>

//  base
#define REGISTRATION                     "registration"  //  completed + test
//  input: nickname, password; output: user_id; error:"null" (если пользователь уже существует)

#define AUTHENTICATION                   "autorization"  //  completed + test
//  input: nickname, password; output: user_id; error:"null" (если введены некорректные данные)

//  synchro
#define GET_EVENTS                       "get_events"  //  completed
//  input: user_id, date; output: set<event_t> [description, time_begin, time_end]

#define GET_CONTACTS                     "get_friends"  //  completed
//  input: user_id; output: set<sring> [nickname]

#define GET_GROUPS                       "get_groups"
//  input: user_id; output: set<string> [title]

//  personal data
#define WRITE_PERSONAL_DATA              "..."

//  user address
#define WRITE_ADDRESS                    "..."

//  event
#define ADD_EVENT                        "add_event"  //  completed + test
//  input: user_id, data, description, time_begin, time_end; output: OK

#define WRITE_EVENT                      "change_event"  //  completed
//  input: user_id, data, description, time_begin, time_end; output: OK

#define RM_EVENT                         "delete_event"  //  completed
//  input: user_id, data, description, time_begin, time_end; output: OK

//  list_contacts
#define ADD_USER_CONTACTS                "add_friend"  //  completed
//  input: user_id, nickname; output: OK

#define RM_USER_CONTACTS                 "delete_friend"  //  completed
//  input: user_id, nickname; output: OK

//  group
#define ADD_GROUP                        "create_group"
//  input: title; output: group_id ???

#define WRITE_GROUP                      "change_group"
//  input: title; output OK

#define RM_GROUP                         "delete_group"
//  input: title; output OK

#define ADD_USER                         "invite"
//  input: nickname, title(group); output: OK

#define RM_USER                          "kick"
//  input: nickname, title(group); output: OK

#define JOIN                             "join_group"
//  input: nickname, title(group); output: OK

#define LEAVE                            "leave_group"
//  input: nickname, title(group); output: OK

#define SEARCH_GROUP                     "search_group"
//  input: title; output: title; error:"null" (не найдена такая группа)

//  meetup in group
#define SEARCH_FREE_TIME                 "get_meetup"
//  input: title, date; output: set<meetup_t>[description, time_begin, time_end]

#define HISTORY_MEETUP                   "get_history"
//  input: title; output: set<meetup_t>[description, time_begin, time_end, date]


/*
Идеи по функционалу:
 - match (голосование по времени встречи)
*/


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
} address_data_t;

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
    std::string meetup_name = "";
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
    std::set<std::string> list_contacts;
} contacts_t;

    bool operator< (const event_t& lhs, const event_t& rhs);

    bool operator< (const meetup_t& lhs, const meetup_t& rhs);

    bool operator< (const group_t& lhs, const group_t& rhs);

class ParserObject {
public:
    user_t                       user;
    personal_data_t     personal_data;
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
    ParserObject& operator=(const address_data_t other)              { this->address_data = other;       return *this; };
    ParserObject& operator=(const std::set<event_t> other)          { this->events = other;              return *this; };
    ParserObject& operator=(const std::set<group_t> other)          { this->groups = other;              return *this; };
    ParserObject& operator=(const std::set<meetup_t> other)         { this->meetups = other;             return *this; };
    ParserObject& operator=(const contacts_t other)                 { this->contacts = other;            return *this; };
};

//  Отладка
namespace Debugging {
    void print_event_t(const event_t& e);

    void print_meetup_t(const meetup_t& e);

    void print_user_t(const user_t& u);

    void print_contacts_t(const contacts_t& c);

    void print_group_t(const group_t& g);

    void print_from_client(const std::string& in);

    void print_from_processing(const std::string& in);

    void print_personal_data_t(const personal_data_t& d);

    void print_address_data_t(const address_data_t& a);

    void print_user_group(const user_t& u, const group_t& g);
}