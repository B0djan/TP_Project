#include <RouteImpl.hpp>

#include <RouteMapKeys.hpp>

//  processing classes
#include <ContactsImpl.hpp>
#include <EventImpl.hpp>
#include <Group/GroupImpl.hpp>
#include <Group/MeetUpImpl.hpp>
#include <RegistrAuthImpl.hpp>
#include <SynchroClientImpl.hpp>
#include <Data/WriteAddressDataImpl.hpp>
#include <Data/WriteGeneralDataImpl.hpp>
#include <Data/WriteSecurityDataImpl.hpp>
#include <Data/WritePersonalDataImpl.hpp>

//  parser_class classes
#include <ParserContactsImpl.hpp>
#include <ParserEventImpl.hpp>
#include <Group/ParserGroupImpl.hpp>
#include <ParserRegistrAuthImpl.hpp>
#include <Data/ParserWriteAddressDataImpl.hpp>
#include <Data/ParserWriteGeneralDataImpl.hpp>
#include <Data/ParserWriteSecurityDataImpl.hpp>
#include <Data/ParserWritePersonalDataImpl.hpp>
#include <Group/ParserMeetUpImpl.hpp>

RouteImpl::RouteImpl() {
    //  Base            REQUEST                                        PARSER                     HANDLER
    route_map.insert({REGISTRATION,           std::make_pair(new ParserRegistrAuthImpl,        new RegistrationImpl)});
    route_map.insert({AUTHENTICATION,         std::make_pair(new ParserRegistrAuthImpl,        new AuthenticationImpl)});

    // Synchro
    route_map.insert({GET_EVENTS,             std::make_pair(new ParserEventImpl,              new SynchroClientEventsImpl)});
    route_map.insert({GET_CONTACTS,           std::make_pair(new ParserUserContactsImpl,       new SynchroClientContactsImpl)});
    route_map.insert({GET_GROUPS,             std::make_pair(new ParserGroupImpl,              new SynchroClientGroupsImpl)});

    //  Write user personal data
    route_map.insert({WRITE_PERSONAL_DATA,    std::make_pair(new ParserWritePersonalDataImpl,  new WritePersonalDataImpl)});
    route_map.insert({GET_PERSONAL_DATA,      std::make_pair(new ParserWritePersonalDataImpl,  new GetPersonalDataImpl)});

    //  Write user general data
    route_map.insert({WRITE_GENERAL_DATA,    std::make_pair(new ParserWriteGeneralDataImpl,    new WriteGeneralDataImpl)});
    route_map.insert({GET_GENERAL_DATA,      std::make_pair(new ParserWriteGeneralDataImpl,    new GetGeneralDataImpl)});

    // Security
    route_map.insert({WRITE_PASSWORD,        std::make_pair(new ParserWriteSecurityDataImpl,    new WritePasswordImpl)});
    route_map.insert({WRITE_NICKNAME,        std::make_pair(new ParserWriteSecurityDataImpl,    new WriteNicknameImpl)});

    //  Write user address
    route_map.insert({WRITE_ADDRESS,          std::make_pair(new ParserWriteAddressDataImpl,   new WriteAddressDataImpl)});
    route_map.insert({GET_ADDRESS,            std::make_pair(new ParserWriteAddressDataImpl,   new GetAddressDataImpl)});

    //  Event functional
    route_map.insert({ADD_EVENT,              std::make_pair(new ParserEventImpl,              new AddEventImpl)});
    route_map.insert({WRITE_EVENT,            std::make_pair(new ParserEventImpl,              new WriteEventImpl)});
    route_map.insert({RM_EVENT,               std::make_pair(new ParserEventImpl,              new RmEventImpl)});

    //  Contact functional
    route_map.insert({ADD_USER_CONTACTS,      std::make_pair(new ParserUserContactsImpl,       new AddUserContactsImpl)});
    route_map.insert({RM_USER_CONTACTS,       std::make_pair(new ParserUserContactsImpl,       new RmUserContactsImpl)});

    //  Group functional
    route_map.insert({ADD_GROUP,              std::make_pair(new ParserGroupImpl,              new AddGroupImpl)});
    route_map.insert({WRITE_GROUP,            std::make_pair(new ParserGroupImpl,              new WriteGroupImpl)});
    route_map.insert({RM_GROUP,               std::make_pair(new ParserGroupImpl,              new RmGroupImpl)});

    route_map.insert({GET_MEMBERS,             std::make_pair(new ParserGroupImpl,              new GetGroupImpl)});

    //route_map.insert({SEARCH_GROUP,           std::make_pair(new Group,              new SearchGroupImpl)});

    route_map.insert({ADD_USER,               std::make_pair(new ParserGroupImpl,             new AddUserImpl)});
    route_map.insert({RM_USER,                std::make_pair(new ParserGroupImpl,             new RmUserImpl)});

    //route_map.insert({JOIN,                   std::make_pair(new Group,          new JoinImpl)});
    //route_map.insert({LEAVE,                  std::make_pair(new Group,          new LeaveImpl)});

    route_map.insert({SEARCH_FREE_TIME,       std::make_pair(new ParserMeetUpImpl,           new SearchFreeTimeImpl)});

    //route_map.insert({HISTORY_MEETUP,         std::make_pair(new ParserMeetUpImpl,             new OutputHistoryMeetUpImpl)});
}

std::string RouteImpl::get_head(const std::string request_body) {
    std::string type_request;

    size_t begin = request_body.find("\"");
    if (begin == request_body.npos) {
        return type_request;
    }

    size_t end = request_body.find("\"", begin + 1);
    if (end == request_body.npos) {
        return type_request;
    }

    type_request = request_body.substr(begin + 1, end - 2);
    return type_request;
}

std::string RouteImpl::get_response(const std::string request_body) {
    std::string res;

    std::string type_request = get_head(request_body);
    if (type_request.empty()) {
        return res;
    }

    auto needed_node = route_map.find(type_request);
    if (needed_node == route_map.end()) {
        return res;
    }

    ParserObject buf;

    buf = needed_node->second.first->StrToObject(request_body);
    buf = needed_node->second.second->process(buf);
    res = needed_node->second.first->ObjectToStr(type_request, buf);

    return res;
}