//#include <json.hpp>

#include <Parsing.hpp>

class JSON: public Parsing {
    //nlohmann::json& StrToJSON(const std::string parser_str);

    //std::string JSONtoStr(nlohmann::json& j);

    ParserObject StrToObject(const std::string parser_str) override;

    std::string ObjectToStr(const ParserObject& other) override;

    ~JSON() = default;
};