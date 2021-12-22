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
    ParserRegistrAuthImpl par_reg_auth;

    ParserEventImpl par_event;

    ParserUserContactsImpl par_user_contacts;

    ParserGroupImpl par_group;

    ParserWritePersonalDataImpl par_write_data;

    ParserWriteAddressDataImpl par_write_address;

    ParserUserGroupImpl par_user_group;

    ParserMeetUpImpl par_meetup;


    //  Base            REQUEST                                        PARSER                     HANDLER
    route_map.insert({REGISTRATION,           std::make_pair(&par_reg_auth,        new RegistrationImpl)});
    route_map.insert({AUTHENTICATION,         std::make_pair(&par_reg_auth,        new AuthenticationImpl)});

    // Synchro
    route_map.insert({GET_EVENTS,             std::make_pair(&par_event,              new SynchroClientEventsImpl)});
    route_map.insert({GET_CONTACTS,           std::make_pair(&par_user_contacts,       new SynchroClientContactsImpl)});
    route_map.insert({GET_GROUPS,             std::make_pair(&par_group,              new SynchroClientGroupsImpl)});

    //  Write user personal data
    route_map.insert({WRITE_PERSONAL_DATA,    std::make_pair(&par_write_data,  new WritePersonalDataImpl)});

    //  Write user address
    route_map.insert({WRITE_ADDRESS,          std::make_pair(&par_write_address,   new WriteAddressDataImpl)});

    //  Event functional
    route_map.insert({ADD_EVENT,              std::make_pair(&par_event,              new AddEventImpl)});
    route_map.insert({WRITE_EVENT,            std::make_pair(&par_event,              new WriteEventImpl)});
    route_map.insert({RM_EVENT,               std::make_pair(&par_event,              new RmGroupImpl)});

    //  Contact functional
    route_map.insert({ADD_USER_CONTACTS,      std::make_pair(&par_user_contacts,       new AddUserContactsImpl)});
    route_map.insert({RM_USER_CONTACTS,       std::make_pair(&par_user_contacts,       new RmUserContactsImpl)});

    //  Group functional
    route_map.insert({ADD_GROUP,              std::make_pair(&par_group,              new AddUserImpl)});
    route_map.insert({WRITE_GROUP,            std::make_pair(&par_group,              new WriteGroupImpl)});
    route_map.insert({RM_GROUP,               std::make_pair(&par_group,              new RmGroupImpl)});

    route_map.insert({SEARCH_GROUP,           std::make_pair(&par_group,              new SearchGroupImpl)});

    route_map.insert({ADD_USER,               std::make_pair(&par_user_group,          new AddUserImpl)});
    route_map.insert({RM_USER,                std::make_pair(&par_user_group,          new RmUserImpl)});

    route_map.insert({JOIN,                   std::make_pair(&par_user_group,          new JoinImpl)});
    route_map.insert({LEAVE,                  std::make_pair(&par_user_group,          new LeaveImpl)});

    route_map.insert({SEARCH_FREE_TIME,       std::make_pair(&par_meetup,             new SearchFreeTimeImpl)});

    route_map.insert({HISTORY_MEETUP,         std::make_pair(&par_meetup,             new OutputHistoryMeetUpImpl)});
}

std::string RouteImpl::get_head(const std::string request_body) {
    size_t begin = request_body.find("\"");
    size_t end = request_body.find("\"", begin);

    std::string type_request = request_body.substr(begin, end);
    std::cout << type_request << "\n" << std::endl;

    return type_request;
}

std::string RouteImpl::get_response(const std::string request_body) {
    std::string type_request = get_head(request_body);

    auto needed_node = route_map.find(type_request);
    if (needed_node == route_map.end()) {
        std::string res;
        return res;
    }

    ParserObject buf = needed_node->second.first->StrToObject(request_body);
    buf = needed_node->second.second->process(buf);
    std::string res = needed_node->second.first->ObjectToStr(buf);

    return res;
}