#pragma once

#include <sys/select.h>

#include <queue>

#include <unordered_map>

#include "../virtual_interface/EventLoop.hpp"

class SelectBasedEventLoop: public EventLoop {
    std::unordered_map<int, ResCb> on_readable_callbacks;
    std::unordered_map<int, ResCb> on_writable_callbacks;
    std::queue<Cb> scheduled_callbacks;

    void chedule(std::unordered_map<int, RecCb>&, const fd_set& ok_fds, const fd_set& err_fds, int& unscheduled);

public:
    void on_readable(int fd, ResCb) override;
    void on_writable(int fd, ResCb) override;
    void schedule(Cb) override;

    void run_until_complete();
};
