#include "parse_json.hpp"

    contacts_t Json::GetContacts(nlohmann::json& j) {
        
        contacts_t contacts;

        if(j.contains("user_id"))
            contacts.user_id = j["user_id"];

        if(j.contains("contacts"))
        {
            for (auto& element : j["contacts"])
                contacts.contacts.insert(element[0].dump());
        }

        return contacts;
    }

    nlohmann::json Json::ReturnContats(contacts_t& contacts) {

        nlohmann::json j {
            {"user_id", contacts.user_id},
            {"contacts", contacts.contacts}
        };

        return j;
    }