#include <Data/WriteSecurityDataImpl.hpp>

ParserObject WritePasswordImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = DatabaseConnector::Security::ReWritePassword(request_body.user.user_id, request_body.user.password);
    if (code != 0) {
        response_body.error = "Error rewrite password";

        return response_body;
    }

    return response_body;
}

ParserObject WriteNicknameImpl::process(const ParserObject& request_body) {
    ParserObject response_body;

    int code = DatabaseConnector::Security::ReWriteNickname(request_body.user.user_id, request_body.user.nickname);
    if (code != 0) {
        response_body.error = "Error rewrite nickname";

        return response_body;
    }

    return response_body;
}
