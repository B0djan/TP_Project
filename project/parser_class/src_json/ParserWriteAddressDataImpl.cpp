#include <ParserWriteAddressDataImpl.hpp>

ParserObject ParserWriteAddressDataImpl::StrToObject(const std::string& parser_str) {
    
    nlohmann::json j = nlohmann::json::parse(parser_str);

    nlohmann::json::iterator it = j.begin();

    nlohmann::json value = j[it.key()];

    addres_data_t addres_data;

    if(j.contains("user_id"))
        addres_data.user_id = j["user_id"].get<std::string>();

    if (j.contains("building"))
        addres_data.building = j["building"].get<std::string>();

    if (j.contains("housing"))
        addres_data.housing = j["housing"].get<std::string>();

    if (j.contains("street"))
        addres_data.street = j["street"].get<std::string>();

    if (j.contains("city"))
        addres_data.city = j["city"].get<std::string>();

    if (j.contains("district"))
        addres_data.district = j["district"].get<std::string>();
    
    if (j.contains("index"))
        addres_data.index = j["index"].get<std::string>();

    if (j.contains("country"))
        addres_data.country = j["country"].get<std::string>();

    ParserObject res;

    res = addres_data;

    return res;
}

std::string ParserWriteAddressDataImpl::ObjectToStr(const ParserObject& other) {

    addres_data_t addres_data = other.address_data;

    nlohmann::json value;

    value["user_id"] = addres_data.user_id;

    value["building"] = addres_data.building;

    value["housing"] = addres_data.housing;

    value["street"] = addres_data.street;

    value["city"] = addres_data.city;

    value["district"] = addres_data.district;

    value["index"] = addres_data.index;

    value["country"] = addres_data.country;

    nlohmann::json j;

    j["addres"] = value;

    std::string res = j.dump();

    // {"registration":{"user_id":"value"}}

    return res;
}
