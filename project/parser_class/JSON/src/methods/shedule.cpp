#include "parse_json.hpp"

event_t Json::GetShedule(std::string&str) {

    nlohmann::json j = nlohmann::json::parse(str);

    nlohmann::json::iterator it = j.begin();

    if (it.key() != SH_KEY) 
    {
        std::cout << "OOOOPS!" <<std::endl;
    }

    nlohmann::json value = j[it.key()];
 
    return Json::GetEvent(value);
};