#include <RouteImpl.hpp>

void RouteImpl::schedule(ParserObject request) {
    request_queue.push(request);
}

ParserObject RouteImpl::get_response() {
    auto search = request_queue.front();

    auto res = processing_map.chain_links.find(search.get_head());

    res->second->request_body.input(search);

    res->second->process(cb);

    ParserObject res_body = res->second->response_body;



    return res_body;
}