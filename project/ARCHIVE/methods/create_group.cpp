#include "parse_json.hpp"

group_t Json::CreateGroup(std::string& str) {

    nlohmann::json j = nlohmann::json::parse(str);

    nlohmann::json::iterator it = j.begin();

    if (it.key() != DFR_KEY) 
    {
        std::cout << "OOOOPS!" <<std::endl;
    }

    nlohmann::json value = j[it.key()];

    return Json::GetGroup(value);    
};