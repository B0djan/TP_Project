#pragma once

#include <AsyncStream.hpp>

#include <EventLoop.hpp>

#include <File.hpp>

class AsyncFileOutputStream: virtual public AsyncOutputStream {
    EventLoop& e;
    WritableFile& file;

public:
    AsyncFileOutputStream(EventLoop& e, WritableFile& file):
        e(e),
        file(file)
    {}

    void write(char* const buf, size_t count, Cb cb) override;
};
