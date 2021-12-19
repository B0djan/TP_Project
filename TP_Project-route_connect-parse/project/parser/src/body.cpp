#include "parse_json.hpp"

#include <string>
#include <iostream>

    object_body Json::GetBody(std::string& s) {
        nlohmann::json j = nlohmann::json::parse(s);

        object_body_t object_body {
            .addres_data =   GetAddresData(j["addres_data"]),
            .contacts =           GetContacts(j["contacts"]),
            .event =                    GetEvent(j["event"]),
            .group =                    GetGroup(j["group"]),
            .meetup =                 GetMeetup(j["meetup"]),
            .personal_data = GetPersonData(j["person_data"]),
            .user =                       GetUser(j["user"])
        };

        return object_body;        
    }

    std::string Json::ReturnBody(object_body& object_body) {

        nlohmann::json j {
            {"addres_data", ReturnAddresData(object_body.addres_data)},
            {"contacts", ReturnContats(object_body.contacts)},
            {"event", ReturnEvent(object_body.event)},
            {"group", ReturnGroup(object_body.group)},
            {"meetup", ReturnMeetup(object_body.meetup)},
            {"person_data", ReturnPersonData(object_body.personal_data)},
            {"user", ReturnUser(object_body.user)}
        };

        std::string serialised_string = j.dump();
    }
