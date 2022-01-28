#include <Data/WritePersonalDataImpl.hpp>

ParserObject WritePersonalDataImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = DatabaseConnector::Data::Personal::ReWrite(request_body.personal_data);
    if (code != 0) {
        response_body.error = "Error write personal data";

        return response_body;
    }

    return response_body;
}

ParserObject GetPersonalDataImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    response_body.personal_data = DatabaseConnector::Data::Personal::Get(request_body.personal_data.user_id);
    if (response_body.personal_data.user_id == "Error") {
        response_body.error = "Error get personal data";

        return response_body;
    }

    return response_body;
}

