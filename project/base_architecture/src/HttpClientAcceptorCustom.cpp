#include <strings.h>
#include <iostream>
#include <string_view>
#include <cstring>

#include <HttpClientAcceptorCustom.hpp>

#include <Utils.hpp>

void HttpClientAcceptorCustom::HttpClientProcessor::reply(int code, const char* reason) {
    int size = snprintf(write_buffer, sizeof(write_buffer),
                        "%s %d %s\r\n"
                        "Connection: %s\r\n\r\n",
                        proto.c_str(),
                        code,
                        reason,
                        keep_alive ? "keep-alive" : "close");

    ASSERT(size > 0 && size < sizeof(write_buffer), "too small reply buffer");

    stream->write(write_buffer, size, [this] (bool success) {
        if (!success || !keep_alive)
            end_cb();
    });
}

void HttpClientAcceptorCustom::HttpClientProcessor::reply(std::string response) {
    size_t total_size = response.size();

    int writebuf_filled = snprintf(
            write_buffer, sizeof(write_buffer),
            "%s 200 Ok\r\n"
            "Content-Type: application/json\r\n"
            "Content-Length: %zu\r\n"
            "Connection: %s\r\n"
            "\r\n",
            "%s\r\n",
            "\r\n",
            proto.c_str(),
            total_size,
            keep_alive ? "keep-alive" : "close",
            response.c_str());

    ASSERT(writebuf_filled > 0 && writebuf_filled < sizeof(write_buffer), "too small reply buffer");


    stream->write(write_buffer, writebuf_filled, [this] (bool success) {
        if (!success)
            return end_cb();
        if (keep_alive)
            return get_start_line();
        end_cb();
    });
}

void HttpClientAcceptorCustom::HttpClientProcessor::next_file_part() {
    ssize_t size = last_resource.read(write_buffer, sizeof(write_buffer)).gcount();
    stream->write(write_buffer, size, [this] (bool success) {
        if (!success)
            return end_cb();
        if (keep_alive)
            return get_start_line();
        end_cb();
    });
}

void HttpClientAcceptorCustom::HttpClientProcessor::get_start_line() {
    keep_alive = false;
    stream->read_till(
            "\r\n", 2,
            [this] (bool success, const char* buf, size_t size) {
                if (!success)
                    return end_cb();

                std::string_view start_string(buf, size);

                if (start_string.substr(0, 6) != "POST /")
                    return reply(405, "Method not allowed");

                start_string.remove_prefix(6);

                ssize_t resource_end = start_string.find(" ");

                if (resource_end == start_string.npos)
                    return reply(400, "Bad request");

                proto = start_string.substr(resource_end + 1);

                start_string = start_string.substr(0, resource_end);

                last_resource = std::ifstream(std::string(start_string));

                get_header();
            });
}

void HttpClientAcceptorCustom::HttpClientProcessor::get_header() {
    stream->read_till(
            "\r\n", 2,
            [this] (bool success, const char* buf, size_t size) {
                if (!success)
                    return end_cb();

                std::string_view header(buf, size);

                ssize_t key_end = header.find(": ");

                if (key_end == header.npos)
                    return reply(400, "Bad request");

                if (!strncasecmp("Connection", header.data(), key_end)) {
                    header.remove_prefix(key_end + 2);
                    if (!strncasecmp("keep-alive", header.data(), header.size()))
                        keep_alive = true;
                }

                if (!massage && header.find("json") != header.npos) {
                    get_massage();
                }

                get_header();
            });
}

void HttpClientAcceptorCustom::HttpClientProcessor::get_massage() {
    stream->read_till(
            "\r\n", 2,
            [this] (bool success, const char* buf, size_t size) {
                std::string buff(buf);

                size_t key_start = buff.find("{");

                size_t key_end = buff.find("}\n");

                std::string massage_data = buff.substr(key_start, key_end - 1);

                massage = true;

                massage_d = massage_data;

                std::cout<< massage_d << " " << massage_d.size() << "\n" << std::endl;
            });
}

void HttpClientAcceptorCustom::HttpClientProcessor::process(EndCb end_cb) {
    this->end_cb = end_cb;
    get_start_line();
    massage_d.push_back(9);
    reply(massage_d);
}

void HttpClientAcceptorCustom::accept(AsyncIOStream* stream) {
    HttpClientProcessor* processor = new HttpClientProcessor(magic, stream);
    processor->process([processor] {
        delete processor;
    });
}