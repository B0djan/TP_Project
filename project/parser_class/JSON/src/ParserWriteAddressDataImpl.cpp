#include <ParserWriteAddressDataImpl.hpp>

ParserObject ParserWriteAddressDataImpl::StrToObject(const std::string& parser_str) const {
    // {"registration":{"user_id":"value"}} TODO: Отредачить

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
        Print_struct::from_client(parser_str);
        Print_struct::_address_data_t(address_data);
    }

    return res;
}

std::string ParserWriteAddressDataImpl::ObjectToStr(const std::string type_response, const ParserObject& other) const {
    // {"registration":{"user_id":"value"}} TODO: Отредачить

    nlohmann::json j;
    std::string res;

    if (!other.error.empty()) {
        j[type_response] = other.error;

        res = j.dump();

        return res;
    }

    address_data_t address_data = other.address_data;

    nlohmann::json value;

    if (!address_data.user_id.empty())
        value["user_id"] = address_data.user_id;

    if (!address_data.building.empty())
        value["building"] = address_data.building;

    if (!address_data.housing.empty())
        value["housing"] = address_data.housing;

    if (!address_data.street.empty())
        value["street"] = address_data.street;

    if (!address_data.city.empty())
        value["city"] = address_data.city;

    if (!address_data.district.empty())
        value["district"] = address_data.district;

    if (!address_data.index.empty())
        value["index"] = address_data.index;

    if (!address_data.country.empty())
        value["country"] = address_data.country;

    j[type_response] = value;

    res = j.dump();

    //  Отладка
    if (GLOBAL_KEY_TEST_PARSER) {
        Print_struct::_address_data_t(address_data);
        Print_struct::from_processing(res);
    }

    return res;
}
