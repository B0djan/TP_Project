#pragma once

#include "json.hpp"
#include "ParserObject.hpp"

#include <set>

#include <iostream>

#define AU_KEY     "autorization"
#define REG_KEY    "registration"
#define ID_KEY     "getUser"
#define SH_KEY     "getSheduleFromDate"
#define GR_KEY     "getGroups"
#define GFR_KEY    "getFriends"
#define DFR_KEY    "deleteFriend"
#define MKGR_KEY   "setGroup"
#define LVGR_KEY   "logOutGroup"
#define SRGR_KEY   "searchGroup"
#define MEET_KEY   "meetUp"
#define ADD_E_KEY  "setSheduleFromDate"

namespace Json
{
    //  METHODS

    user_t GetId(std::string& str);


    user_t Registration(std::string& str);

    user_t Autorization(std::string& str);


    event_t GetShedule(std::string& str);

    user_t DeleteFriend(std::string& str);
    

    group_t CreateGroup(std::string& str);



    //  SINGLE

    user_t GetUser(nlohmann::json& j);

    nlohmann::json ReturnUser(user_t& user);


    personal_data_t GetPersonData(nlohmann::json& j);

    nlohmann::json  ReturnPersonData(personal_data_t& person);



    addres_data_t GetAddresData(std::string& str);

    nlohmann::json  ReturnAddresData(addres_data_t& addres);



    event_t GetEvent(nlohmann::json& j);

    nlohmann::json ReturnEvent(event_t& event);



    meetup_t GetMeetup(nlohmann::json& j);

    nlohmann::json ReturnMeetup(meetup_t& meetup);



    contacts_t GetContacts(std::string& str);

    nlohmann::json ReturnContats(contacts_t& contacts_t);  
    


    group_t GetGroup(nlohmann::json& j);

    nlohmann::json ReturnGroup(group_t& group);




};