#include <WriteAddressDataImpl.hpp>

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

    address_data_t check_address = DatabaseConnector::Data::Address::Get(request_body.address_data.user_id);
    if (check_address.user_id == "Error") {
        response_body.error = "Error get address data";

        return response_body;
    }

    response_body.address_data = check_address;

    return response_body;
}


