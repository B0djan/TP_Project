#include "project/libs/parsing/include/nlohmann/json.hpp"
#include "struct.hpp"

class Json {

    //  User

    user_t GetUser(nlohmann::json& j);

    nlohmann::json ReturnUser(user_t& user);

    //  PersonData

    personal_data_t GetPersonData(nlohmann::json& j);

    nlohmann::json ReturnPersonData(personal_data_t& person);

    //  AddresData

    addres_data_t GetAddresData(nlohmann::json& j);

    nlohmann::json ReturnAddresData(addres_data_t& addres);

    //  Event

    event_t GetEvent(nlohmann::json& j);

    nlohmann::json ReturnEvent(event_t& event);

    //  Meetup

    meetup_t GetMeetup(nlohmann::json& j);

    nlohmann::json ReturnMeetup(meetup_t& meetup);

    //  Contacts

    contacts_t GetContacts(nlohmann::json& j);

    nlohmann::json ReturnContats(contacts_t& contacts_t);  
    
    //  Group

    group_t GetGroup(nlohmann::json& j);

    nlohmann::json ReturnGroup(group_t& group);

    //  ObjectBody

    object_body_t GetBody(std::string& s);

    std::string ReturnBody(object_body_t& object_body);
    
};