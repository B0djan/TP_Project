#include <LinkRequestHandlerImpl.hpp>

#include <VectorHandlerImpl.hpp>

#include <VectorRequestImpl.hpp>

#include <Utils.hpp>

LinkRequestHandlerImpl::LinkRequestHandlerImpl() {
    VectorHandlerImpl handler;
    VectorRequestImpl request;

    if (handler.capacity != request.capacity) {
        FATAL("the number of requests and the number of handlers do not match");
    }

    for (size_t i = 0; i < handler.capacity; i++) {
        chain_links.insert({request.request_chain[i], handler.handler_chain[i]});
    }
}

