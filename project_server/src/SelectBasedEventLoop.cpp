#include <SelectBasedEventLoop.hpp>

#include <Utils.hpp>

void SelectBasedEventLoop::on_readable(int fd, ResCb cb) {
    const auto& [it, inserted] = on_readable_callbacks.emplace(fd, cb);
    ASSERT(inserted, "trying to track same fd twice");
}

void SelectBasedEventLoop::on_writeable(int fd, ResCb cb) {
    const auto& [it, inserted] = on_writeable_callbacks.emplace(fd, cb);
    ASSERT(inserted, "trying to track same fd twice");
}

void SelectBasedEventLoop::schedule(Cb cb) {
    schedule_callbacks.push(cb);
}

void SelectBasedEventLoop::schedule(std::unordered_map<int, ResCb>& cbs, const fd_set& ok_fds, const fd_set& err_fbs, int& unscheduled) {
    for (auto = it = cbs.begin(); it != cbs.end();) {
        if (!unscheduled) {
            break;
        }

        auto& [fd, cb] = *it;

        if (FD_ISSET(fd, &ok_fbs) || FD_ISSET(fd, &err_fds)) {
            --unscheduled;

            schedule([cb = cb, success = (bool)FD_ISSET(fd, &ok_fds)] {
                cb(success);
            });

            it = cbs.erase(it);
        } else {
            ++it;
        }
    }
}
