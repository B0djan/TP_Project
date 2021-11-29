#include <SelectBasedEventLoop.hpp>

#include <Utils.hpp>

void SelectBasedEventLoop::on_readable(int fd, ResCb cb) {
    const auto& [it, inserted] = on_readable_callbacks.emplace(fd, cb);      //  save the associative array fd - сb
    ASSERT(inserted, "trying to track same fd twice");
}

void SelectBasedEventLoop::on_writable(int fd, ResCb cb) {
    const auto& [it, inserted] = on_writable_callbacks.emplace(fd, cb);    //  save the associative array fd - сb
    ASSERT(inserted, "trying to track same fd twice");
}

void SelectBasedEventLoop::schedule(Cb cb) {
    scheduled_callbacks.push(cb);
}

void SelectBasedEventLoop::schedule(std::unordered_map<int, ResCb>& cbs, const fd_set& ok_fds, const fd_set& err_fds, int& unscheduled) {
    for (auto it = cbs.begin(); it != cbs.end();) {
        if (!unscheduled) {
            break;
        }

        auto& [fd, cb] = *it;

        if (FD_ISSET(fd, &ok_fds) || FD_ISSET(fd, &err_fds)) {
            --unscheduled;

            schedule([cb = cb, success = (bool)FD_ISSET(fd, &ok_fds)] {         //  scheduling to execute a lambda function
                cb(success);
            });

            it = cbs.erase(it);                                                 //  remove the link fd - сb
        } else {
            ++it;
        }
    }
}

void SelectBasedEventLoop::run_until_complete() {
    while (!on_readable_callbacks.empty() || !on_writable_callbacks.empty()) {  //  while there is at least one expected fd
        fd_set track_readability;                                               //  initialize the set of tracked topic descriptors
        FD_ZERO(&track_readability);                                            //  zero them

        fd_set track_writability;
        FD_ZERO(&track_writability);

        fd_set track_errors;
        FD_ZERO(&track_errors);

        int max_fd = -1;

        for (auto& [fd, cb] : on_readable_callbacks) {                          //  fill them with tracked fd in the class
            if (fd > max_fd) {
                max_fd = fd;
            }

            FD_SET(fd, &track_readability);
            FD_SET(fd, &track_errors);
        }

        for (auto& [fd, cb] : on_writable_callbacks) {                          //  fill them with tracked fd in the class
            if (fd > max_fd) {
                max_fd = fd;
            }

            FD_SET(fd, &track_writability);
            FD_SET(fd, &track_errors);
        }

        int active_fd;
        while ((active_fd = select(max_fd + 1, &track_readability, &track_writability, &track_errors, NULL)) == -1) {  //  find the fd on which there was activity
            if (errno == EAGAIN || errno == EINTR) {                              // skipping temporary errors or signals
                continue;
            }

            FATAL("unexpected 'select' error");
        }

        schedule(on_readable_callbacks, track_readability, track_errors, active_fd);
        schedule(on_writable_callbacks, track_writability, track_errors, active_fd);

        ASSERT(!active_fd, "couldn't find callbacks for some fds");

        while (!scheduled_callbacks.empty()) {                                  //  skipping temporary errors or signals
            scheduled_callbacks.front()();                                      //  extract and execute сb from the beginning
            scheduled_callbacks.pop();
        }
    }
}
