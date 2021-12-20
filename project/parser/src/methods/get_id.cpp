#include "parse_json.hpp"

user_t Json::GetId(std::string& str) {

    nlohmann::json j = nlohmann::json::parse(str);

    nlohmann::json::iterator it = j.begin();

    if (it.key() != ID_KEY) 
    {
        std::cout << "OOOOPS!" <<std::endl;
    }

    nlohmann::json value = j[it.key()];

    return Json::GetUser(value);    
};