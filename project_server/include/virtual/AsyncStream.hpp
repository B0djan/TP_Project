#pragma once

#include <stddef.h>

#include <functional>

class AsyncInputStream {
public:
    using Cb = std::function<void(bool success, char* const buf, size_t size)>;

    virtual ~AsyncInputStream() = default;

    virtual void read_till(char* const delimiter, size_t del_size, Cb) = 0;
    virtual void read(size_t count, Cb) = 0;
};

class AsyncOutputStream {
public:
    using Cb = std::function<void(bool success)>;

    virtual ~AsyncOutputStream() = default;

    virtual void write(char* const buf, size_t count, Cb) = 0;
};

class AsyncIOStream:
        virtual public AsyncInputStream,
        virtual public AsyncOutputStream
        {};
