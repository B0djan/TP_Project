#include <Data/WriteAddressDataImpl.hpp>

ParserObject WriteAddressDataImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = DatabaseConnector::Data::Address::ReWrite(request_body.address_data);
    if (code != 0) {
        response_body.error = "Error write address data";

        return response_body;
    }

    return response_body;
}

ParserObject GetAddressDataImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    response_body.address_data = DatabaseConnector::Data::Address::Get(request_body.address_data.user_id);
    if (response_body.address_data.user_id == "Error") {
        response_body.error = "Error get address data";

        return response_body;
    }

    return response_body;
}


