#include <WriteGeneralDataImpl.hpp>

ParserObject WriteGeneralDataImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = DatabaseConnector::Data::General::ReWrite(request_body.general_data);
    if (code != 0) {
        response_body.error = "Error write personal data";

        return response_body;
    }

    return response_body;
}

ParserObject GetGeneralDataImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    response_body.general_data = DatabaseConnector::Data::General::Get(request_body.general_data.user_id);
    if (response_body.personal_data.user_id == "Error") {
        response_body.error = "Error get personal data";

        return response_body;
    }

    return response_body;
}

