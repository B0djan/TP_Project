#include <RouteImpl.hpp>

//  processing classes
#include <ContactsImpl.hpp>
#include <EventImpl.hpp>
#include <GroupImpl.hpp>
#include <RegistrAuthImpl.hpp>
#include <SynchroClientImpl.hpp>
#include <WriteAddressDataImpl.hpp>
#include <WritePersonalDataImpl.hpp>

//  parser_class classes
#include <ParserContactsImpl.hpp>
#include <ParserEventImpl.hpp>
#include <ParserGroupImpl.hpp>
#include <ParserRegistrAuthImpl.hpp>
#include <ParserSynchroClientImpl.hpp>
#include <ParserWriteAddressDataImpl.hpp>
#include <ParserWritePersonalDataImpl.hpp>

//  base
#define REGISTRATION                     "registration"
#define AUTHENTICATION                   "autorization"

//  synchro
#define GET_EVENTS                       "..."
#define GET_CONTACTS                     "..."
#define GET_GROUPS                       "..."

//  personal data
#define WRITE_PERSONAL_DATA              "..."

//  user address
#define WRITE_ADDRESS                    "..."

//  event
#define ADD_EVENT                        "..."
#define WRITE_EVENT                      "..."
#define RM_EVENT                         "..."

//  contacts
#define ADD_USER_CONTACTS                "..."
#define RM_USER_CONTACTS                 "..."

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
    route_map.insert({REGISTRATION,           std::make_pair(new ParserRegistrationImpl,           new RegistrationImpl)});
    route_map.insert({AUTHENTICATION,         std::make_pair(new  ParserAuthenticationImpl,        new AuthenticationImpl)});

    // Synchro
    route_map.insert({GET_EVENTS,             std::make_pair(new  ParserSynchroClientEventsImpl,   new SynchroClientEventsImpl)});
    route_map.insert({GET_CONTACTS,           std::make_pair(new  ParserSynchroClientContactsImpl, new SynchroClientContactsImpl)});
    route_map.insert({GET_GROUPS,             std::make_pair(new  ParserSynchroClientGroupsImpl,   new SynchroClientGroupsImpl)});

    //  Write user personal data
    route_map.insert({WRITE_PERSONAL_DATA,    std::make_pair(new  ParserWritePersonalDataImpl,     new WritePersonalDataImpl)});

    //  Write user address
    route_map.insert({WRITE_ADDRESS,          std::make_pair(new  ParserWriteAddressDataImpl,      new WriteAddressDataImpl)});

    //  Event functional
    route_map.insert({ADD_EVENT,              std::make_pair(new  ParserAddEventImpl,              new AddEventImpl)});
    route_map.insert({WRITE_EVENT,            std::make_pair(new  ParserWriteEventImpl,            new WriteEventImpl)});
    route_map.insert({RM_EVENT,               std::make_pair(new  ParserRmGroupImpl,               new RmGroupImpl)});

    //  Contact functional
    route_map.insert({ADD_USER_CONTACTS,      std::make_pair(new  ParserAddUserContactsImpl,       new AddUserContactsImpl)});
    route_map.insert({RM_USER_CONTACTS,       std::make_pair(new  ParserRmUserContactsImpl,        new RmUserContactsImpl)});

    //  Group functional
    route_map.insert({ADD_GROUP,              std::make_pair(new  ParserAddUserImpl,               new AddUserImpl)});
    route_map.insert({WRITE_GROUP,            std::make_pair(new  ParserWriteGroupImpl,            new WriteGroupImpl)});
    route_map.insert({RM_GROUP,               std::make_pair(new  ParserRmGroupImpl,               new RmGroupImpl)});

    route_map.insert({ADD_USER,               std::make_pair(new  ParserAddUserImpl,               new AddUserImpl)});
    route_map.insert({RM_USER,                std::make_pair(new  ParserRmUserImpl,                new RmUserImpl)});

    route_map.insert({JOIN,                   std::make_pair(new  ParserJoinImpl,                  new JoinImpl)});
    route_map.insert({LEAVE,                  std::make_pair(new  ParserLeaveImpl,                 new LeaveImpl)});

    route_map.insert({SEARCH_GROUP,           std::make_pair(new  ParserSearchGroupImpl,           new SearchGroupImpl)});

    route_map.insert({SEARCH_FREE_TIME,       std::make_pair(new  ParserSearchFreeTimeImpl,        new SearchFreeTimeImpl)});

    route_map.insert({HISTORY_MEETUP,         std::make_pair(new  ParserOutputHistoryMeetUpImpl,   new OutputHistoryMeetUpImpl)});
}

std::string RouteImpl::get_response(const std::string request_body) {
    std::string head;

    auto needed_node = route_map.find(head);

    ParserObject buf = needed_node->second.first->StrToObject(request_body);
    buf = needed_node->second.second->process(buf);
    std::string res = needed_node->second.first->ObjectToStr(buf);

    return res;
}