#include <RegistrAuthImpl.hpp>

ParserObject RegistrationImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code =  DatabaseConnector::RegAuth::RegistrationTo(request_body.user);
    if (code != 0) {
        response_body.error = "Error registration";

        return response_body;
    }

    char* check = DatabaseConnector::Process::GetUserId(request_body.user.nickname);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    response_body.user.user_id = check;

    return response_body;
}

ParserObject AuthenticationImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = DatabaseConnector::RegAuth::AutorizationTo(request_body.user);
    if (code != 0) {
        response_body.error = "Error autorization";

        return response_body;
    }

    char* check = DatabaseConnector::Process::GetUserId(request_body.user.nickname);
    if (check == NULL) {
        response_body.error = "Error get user id";

        return response_body;
    }

    response_body.user.user_id = check;

    return response_body;
}

