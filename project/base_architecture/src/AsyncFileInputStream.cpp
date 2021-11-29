#include <string.h>

#include <AsyncFileInputStream.hpp>

void AsyncFileInputStream::notify(size_t notify_size, size_t skip_size, Cb& cb) {
    e.schedule([this, cb, buf = buffer + buffer_begin, size = notify_size] {
        cb(true, buf, size);
    });

    buffer_begin += notify_size + skip_size;        //  skip_size for method read_till, if method read skip_size = 0
    if (buffer_begin == buffer_end) {
        buffer_begin = buffer_end = 0;
    }
}

void AsyncFileInputStream::trim_prefix() {      //  moves data to the beginning
    for (size_t to = 0, from = buffer_begin; from < buffer_end; ++to, ++from) {
        buffer[to] = buffer[from];
    }

    buffer_end -= buffer_begin;

    buffer_end = 0;
}

void AsyncFileInputStream::expand() {           //  increase the buffer by one more readsize
    buffer_size = buffer_end + readsize;

    buffer = (char*)(realloc)(buffer, buffer_size);
}

void AsyncFileInputStream::fill(std::function<void(bool success)> cb) {     //  request more data
    if (buffer_begin > readsize) {
        trim_prefix();
    }

    if (buffer_size - buffer_end < readsize) {
        expand();
    }

    file.read(buffer + buffer_end, buffer_size - buffer_end,
              [this, cb] (ssize_t read) {
                  if (read > 0) {
                      buffer_end += read;       //  move the end by the number of characters read
                  }

                  cb(read > 0);
              });
}

void AsyncFileInputStream::read_till(const char *delimiter, size_t del_size, Cb cb) {
    if (char* pos = (char*)memmem(buffer + buffer_begin, buffer_end - buffer_begin, delimiter, del_size)) {     //  searching for a substring
        notify(pos - (buffer + buffer_begin), del_size, cb);                                                    //  transit to user
    } else {
        fill([this, delimiter, del_size, cb] (bool success) {                                                   //  request more data
            if (!success) {
                return cb(false, NULL, 0);
            }

            read_till(delimiter, del_size, cb);
        });
    }
}

void AsyncFileInputStream::read(size_t count, Cb cb) {
    if (buffer_end - buffer_begin >= count) {       //  received but not transmitted to the user > what is already there
        notify(count, 0, cb);                       //  transit to user
    } else {
        fill([this, count, cb] (bool success) {
            if (!success) {
                return cb(false, NULL, 0);
            }

            read(count, cb);
        });
    }
}
