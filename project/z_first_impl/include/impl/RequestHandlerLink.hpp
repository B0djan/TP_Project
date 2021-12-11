#pragma once

#include <string>

#include <RouteCollection>

typedef std::string str;

//  base
#define REGISTRATION                     "..."
#define AUTHENTICATION                   "..."

//  synchro
#define SYNCHRO                          "..."

//  contacts
#define ADD_USER_TO_CONTACTS             "..."
#define RM_USER_TO_CONTACTS              "..."

#define OUTPUT_CONTACTS                  "..."

//  personal data
#define WRITE_PERSONAL_DATA              "..."

//  user address
#define WRITE_ADDRESS                    "..."

//  event
#define ADD_EVENT                        "..."
#define WRITE_EVENT                      "..."
#define RM_EVENT                         "..."

#define OUTPUT_EVENTS                    "..."

//  group
#define ADD_GROUP                        "..."
#define WRITE_GROUP                      "..."
#define RM_GROUP                         "..."

#define ADD_USER                         "..."
#define RM_USER                          "..."

#define JOIN                             "..."
#define LEAVE                            "..."

#define SEARCH_GROUP                     "..."

#define SEARCH_FREE_TIME                 "..."

#define HISTORY_MEETUP                   "..."

void check_request(str request) {
    if (request == REGISTRATION)
        registration(data, cb);
    if (request == AUTHENTICATION)
        authentication(data, cb);
}

// chain of responsibility;

//  https://refactoring.guru/ru/design-patterns/chain-of-responsibility/cpp/example
