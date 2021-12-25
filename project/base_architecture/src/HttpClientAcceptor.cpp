#include <strings.h>
#include <iostream>
#include <string_view>

#include <HttpClientAcceptor.hpp>

#include <Utils.hpp>

#include <cstdlib>

void HttpClientAcceptor::HttpClientProcessor::reply(int code, const char* reason) {
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
        else
            get_start_line();
    });
}

void HttpClientAcceptor::HttpClientProcessor::reply(std::string response) {
    size_t total_size = response.size();

    int writebuf_filled = snprintf(
            write_buffer, sizeof(write_buffer),
            "%s 200 Ok\r\n"
            "Content-Type: application/json\r\n"
            "Content-Length: %zu\r\n"
            "Connection: %s\r\n\r\n"
            "%s",
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

void HttpClientAcceptor::HttpClientProcessor::get_start_line() {
    keep_alive = false;
    stream->read_till(
            "\r\n", 2,
            [this] (bool success, const char* buf, size_t size) {
                if (!success)
                    return end_cb();

                std::string_view start_string(buf, size);

                std::cout << buf << std::endl;
                std::cout << "---------------------------------" << std::endl;
                std::cout << start_string << std::endl;

                if (start_string.substr(0, 6) != "POST /")
                    return reply(405, "Method not allowed");

                start_string.remove_prefix(6);

                ssize_t resource_end = start_string.find(" ");

                if (resource_end == start_string.npos)
                    return reply(400, "Bad request");

                proto = start_string.substr(resource_end + 1);

                get_header();
            });
}

void HttpClientAcceptor::HttpClientProcessor::get_header() {
    stream->read_till(
            "\r\n", 2,
            [this] (bool success, const char* buf, size_t size) {
                if (!success) {
                    return end_cb();
                }

                if (!size) {
                    return request_finished();
                }

                std::string_view header(buf, size);

                ssize_t key_end = header.find(": ");

                if (key_end == header.npos) {
                    return reply(400, "Bad request");
                }

                if (!strncasecmp("Connection", header.data(), key_end)) {
                    header.remove_prefix(key_end + 2);

                    if (!strncasecmp("keep-alive", header.data(), header.size())) {
                        keep_alive = true;
                    }
                }

                if (!massage) {
                    get_massage(buf);
                    if (massage_d.empty()) {
                        return reply(400, "Bad request, null json");
                    }
                }

                get_header();
            });
}

void HttpClientAcceptor::HttpClientProcessor::get_massage(const char* input) {
    std::string buff(input);

    size_t key_start = buff.find("{");
    if (key_start == buff.npos) {
        return;
    }


    size_t key_end = buff.find("}}");
    if (key_end == buff.npos) {
        size_t key_end = buff.find("]}");
        if (key_end == buff.npos) {
            return;
        }
    }

    massage_d = buff.substr(key_start, key_end - key_start + 2);

    massage = true;
}

void HttpClientAcceptor::HttpClientProcessor::request_finished() {
    std::string response = get_response(massage_d);
    if (response.empty()) {
        return reply(400, "Bad request");
    }

    reply(response);
}

void HttpClientAcceptor::HttpClientProcessor::process(EndCb end_cb) {
    this->end_cb = end_cb;
    get_start_line();
}

void HttpClientAcceptor::accept(AsyncIOStream* stream) {
    HttpClientProcessor* processor = new HttpClientProcessor(stream);
    processor->process([processor] {
        delete processor;
    });
}


