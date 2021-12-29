#pragma once

#include <string>
#include <fstream>

#include <ClientAcceptor.hpp>

#include <RouteImpl.hpp>

class HttpClientAcceptor: public ClientAcceptor {
    class HttpClientProcessor: public RouteImpl {
        using EndCb = std::function<void()>;

        void reply(int code, const char* reason);

        void get_start_line();
        void get_header();
        void request_finished();

        void reply(std::string response);
        void get_massage(const char* input);
        bool massage = false;
        std::string massage_d;


        AsyncIOStream* stream;
        char write_buffer[4096];
        EndCb end_cb;
        std::string proto;
        bool keep_alive = false;

    public:
        HttpClientProcessor(AsyncIOStream* stream): stream(stream) {}
        ~HttpClientProcessor() { delete stream; }

        void process(EndCb);
    };

public:

    HttpClientAcceptor() = default;

    void accept(AsyncIOStream*) override;
};
