#include "parse_json.hpp"

user_t Json::Registration(std::string& str) {

    nlohmann::json j = nlohmann::json::parse(str);

    nlohmann::json::iterator it = j.begin();

    if (it.key() != REG_KEY) 
    {
        std::cout << "OOOOPS!" <<std::endl;
    }

    nlohmann::json value = j[it.key()];

    return GetUser(value);    
};


user_t Json::Autorization(std::string& str) {

    nlohmann::json j = nlohmann::json::parse(str);

    nlohmann::json::iterator it = j.begin();

    if (it.key() != AU_KEY)
    {
        std::cout << "OOOOPS!" <<std::endl;
    }

    nlohmann::json value = j[it.key()];

    return GetUser(value);
};