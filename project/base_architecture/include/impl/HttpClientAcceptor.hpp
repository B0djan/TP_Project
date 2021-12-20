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
        void reply();

        void next_file_part();
        void get_start_line();
        void get_header();
        void request_finished();

        //  CUSTOM !!!!!
        void reply(std::string response);
        void get_massage();
        bool massage = false;
        std::string massage_d;
        RouteImpl route;
        //  CUSTOM !!!!!

        magic_t magic;
        AsyncIOStream* stream;
        char write_buffer[4096];
        EndCb end_cb;
        std::string proto;
        std::ifstream last_resource;
        bool keep_alive = false;

    public:
        HttpClientProcessor(magic_t magic, AsyncIOStream* stream): magic(magic), stream(stream) {}
        ~HttpClientProcessor() { delete stream; }

        void process(EndCb);
    };

    magic_t magic;
public:
    HttpClientAcceptor(magic_t magic): magic(magic) {}

    void accept(AsyncIOStream*) override;
};
