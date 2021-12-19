#include <VectorRequestImpl.hpp>

//  base
#define REGISTRATION                     "..."
#define AUTHENTICATION                   "..."

//  synchro
#define SYNCHRO                          "..."

//  personal data
#define WRITE_PERSONAL_DATA              "..."

//  user address
#define WRITE_ADDRESS                    "..."

//  event
#define ADD_EVENT                        "..."
#define WRITE_EVENT                      "..."
#define RM_EVENT                         "..."

//  contacts
#define ADD_USER_TO_CONTACTS             "..."
#define RM_USER_TO_CONTACTS              "..."

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

VectorRequestImpl::VectorRequestImpl() {
    //  Base
    request_chain.push_back(REGISTRATION);
    request_chain.push_back(AUTHENTICATION);

    /*// Synchro
    request_chain.push_back(SYNCHRO);

    //  Write user personal data
    request_chain.push_back(WRITE_PERSONAL_DATA);

    //  Write user address
    request_chain.push_back(WRITE_ADDRESS);

    //  Event functional
    request_chain.push_back(ADD_EVENT);
    request_chain.push_back(WRITE_EVENT);
    request_chain.push_back(RM_EVENT);

    //  Contact functional
    request_chain.push_back(ADD_USER_TO_CONTACTS);
    request_chain.push_back(RM_USER_TO_CONTACTS);

    //  Group functional
    request_chain.push_back(ADD_GROUP);
    request_chain.push_back(WRITE_GROUP);
    request_chain.push_back(RM_GROUP);

    request_chain.push_back(ADD_USER);
    request_chain.push_back(RM_USER);

    request_chain.push_back(JOIN);
    request_chain.push_back(LEAVE);

    request_chain.push_back(SEARCH_GROUP);

    request_chain.push_back(SEARCH_FREE_TIME);

    request_chain.push_back(HISTORY_MEETUP);*/

    capacity = request_chain.size();
}