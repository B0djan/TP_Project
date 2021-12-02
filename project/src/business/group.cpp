#include "group.h"

    Group::Group() {};

    std::map <int, User> Group::GetMap() const { return group_map; }

    int Group::Size() const { return group_map.size(); }

    void Group::GetFreeTime(Group& group) {
        std::map<int, User> m = group.GetMap();
        Day busy;
        for (auto item: m) {
            busy.UnionDays(item.second.day);     
        }
        Day free;
        free.InvertDay(busy);
    }

    void Group::AddUser(User& user) {
        group_map[user.user_id] = user;
    }

    void Group::DeleteUser(User& user) {
        group_map.erase(user.user_id);
    };