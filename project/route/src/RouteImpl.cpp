#include <RouteImpl.hpp>

#include <ContactsImpl.hpp>
#include <EventImpl.hpp>
#include <GroupImpl.hpp>
#include <RegistrAuthImpl.hpp>
#include <SynchroClientImpl.hpp>
#include <WriteAddressDataImpl.hpp>
#include <WritePersonalDataImpl.hpp>

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

RouteImpl::RouteImpl() {
    //  Base
    chain_links.insert({REGISTRATION, new RegistrationImpl()});
    chain_links.insert({AUTHENTICATION, new AuthenticationImpl()});

    // Synchro
    chain_links.insert({SYNCHRO, new SynchroClientImpl()});

    //  Write user personal data
    chain_links.insert({WRITE_PERSONAL_DATA, new WritePersonalDataImpl()});

    //  Write user address
    chain_links.insert({WRITE_ADDRESS, new WriteAddressDataImpl()});

    //  Event functional
    chain_links.insert({ADD_EVENT, new AddEventImpl()});
    chain_links.insert({WRITE_EVENT, new WriteEventImpl()});
    chain_links.insert({RM_EVENT, new RmGroupImpl()});

    //  Contact functional
    chain_links.insert({ADD_USER_TO_CONTACTS, new AddUserContactsImpl()});
    chain_links.insert({RM_USER_TO_CONTACTS, new RmUserContactsImpl()});

    //  Group functional
    chain_links.insert({ADD_GROUP, new AddUserImpl()});
    chain_links.insert({WRITE_GROUP, new WriteGroupImpl()});
    chain_links.insert({RM_GROUP, new RmGroupImpl()});

    chain_links.insert({ADD_USER, new AddUserImpl()});
    chain_links.insert({RM_USER, new RmUserImpl()});

    chain_links.insert({JOIN, new JoinImpl()});
    chain_links.insert({LEAVE, new LeaveImpl()});

    chain_links.insert({SEARCH_GROUP, new SearchGroupImpl()});

    chain_links.insert({SEARCH_FREE_TIME, new SearchFreeTimeImpl()});

    chain_links.insert({HISTORY_MEETUP, new OutputHistoryMeetUpImpl()});
}

void RouteImpl::schedule(ParserObject request) {
    request_queue.push(request);
}

ParserObject RouteImpl::get_response() {
    auto search = request_queue.front();

    auto res = chain_links.find(search.get_head());

    res->second->request_body.input(search);

    res->second->process();

    ParserObject res_body = res->second->response_body;



    return res_body;
}