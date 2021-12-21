#pragma once

#include <string>
#include <fstream>
#include <magic.h>

#include <ClientAcceptor.hpp>

#include <RouteImpl.hpp>

class HttpClientAcceptor: public ClientAcceptor {
    class HttpClientProcessor {
        using EndCb = std::function<void()>;

        void reply(int code, const char* reason);

        void get_start_line();
        void get_header();
        void request_finished();

        void reply(std::string response);
        void get_massage();
        bool massage = false;
        std::string massage_d;

        magic_t magic;
        AsyncIOStream* stream;
        char write_buffer[4096];
        EndCb end_cb;
        std::string proto;
        bool keep_alive = false;

    public:
        HttpClientProcessor(magic_t magic, AsyncIOStream* stream): magic(magic), stream(stream) {}
        ~HttpClientProcessor() { delete stream; }

        void process(EndCb);
    };

    magic_t magic;
public:
    static RouteImpl route;

    HttpClientAcceptor(magic_t magic): magic(magic) {}

    void accept(AsyncIOStream*) override;
};
