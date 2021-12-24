#include <ParserWriteAddressDataImpl.hpp>

ParserObject ParserWriteAddressDataImpl::StrToObject(const std::string& parser_str) const {
    
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    address_data_t address_data;

    if(j.contains("user_id"))
        address_data.user_id = j["user_id"].get<std::string>();

    if (j.contains("building"))
        address_data.building = j["building"].get<std::string>();

    if (j.contains("housing"))
        address_data.housing = j["housing"].get<std::string>();

    if (j.contains("street"))
        address_data.street = j["street"].get<std::string>();

    if (j.contains("city"))
        address_data.city = j["city"].get<std::string>();

    if (j.contains("district"))
        address_data.district = j["district"].get<std::string>();
    
    if (j.contains("index"))
        address_data.index = j["index"].get<std::string>();

    if (j.contains("country"))
        address_data.country = j["country"].get<std::string>();

    ParserObject res;

    res = address_data;

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        std::cout  << "From client  :---: " << parser_str << std::endl;
        std::cout << address_data.user_id << std::endl;
        std::cout << address_data.building << std::endl;
        std::cout << address_data.housing << std::endl;
        std::cout << address_data.street << std::endl;
        std::cout << address_data.city << std::endl;
        std::cout << address_data.district << std::endl;
        std::cout << address_data.index << std::endl;
        std::cout << address_data.country << std::endl;
    }

    return res;
}

std::string ParserWriteAddressDataImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {

    address_data_t address_data = other.address_data;

    nlohmann::json value;

    if (address_data.user_id != "")
        value["user_id"] = address_data.user_id;

    if (address_data.building != "")
        value["building"] = address_data.building;

    if (address_data.housing != "")
        value["housing"] = address_data.housing;

    if (address_data.street != "")
        value["street"] = address_data.street;

    if (address_data.city != "")
        value["city"] = address_data.city;

    if (address_data.district != "")
        value["district"] = address_data.district;

    if (address_data.index != "")
        value["index"] = address_data.index;

    if (address_data.country != "")
        value["country"] = address_data.country;

    nlohmann::json j;

    j[type_response] = value;

    std::string res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        std::cout << address_data.user_id << std::endl;
        std::cout << address_data.building << std::endl;
        std::cout << address_data.housing << std::endl;
        std::cout << address_data.street << std::endl;
        std::cout << address_data.city << std::endl;
        std::cout << address_data.district << std::endl;
        std::cout << address_data.index << std::endl;
        std::cout << address_data.country << std::endl;
        std::cout << "From processing  :---: " << res << std::endl;
    }

    // {"registration":{"user_id":"value"}}

    return res;
}
