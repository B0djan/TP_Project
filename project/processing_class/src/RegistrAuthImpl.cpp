#include <RegistrAuthImpl.hpp>

ParserObject RegistrationImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = DatabaseConnector::RegAuth::Registration(request_body.user);
    if (code != 0) {
        response_body.error = "Error registration";

        return response_body;
    }

    char* check = DatabaseConnector::GetID::User(request_body.user.nickname);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    response_body.user.user_id = check;

    code = DatabaseConnector::Data::Personal::CreateNull(response_body.user.user_id);
    if (code != 0) {
        response_body.error = "Error create first personal data";

        return response_body;
    }

    code = DatabaseConnector::Data::Address::CreateNull(response_body.user.user_id);
    if (code != 0) {
        response_body.error = "Error create first address data";

        return response_body;
    }

    return response_body;
}

ParserObject AuthenticationImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = DatabaseConnector::RegAuth::Autorization(request_body.user);
    if (code != 0) {
        response_body.error = "Error autorization";

        return response_body;
    }

    char* check = DatabaseConnector::GetID::User(request_body.user.nickname);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    response_body.user.user_id = check;

    return response_body;
}

