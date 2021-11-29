#include "group.h"

class Group {
private:
    int group_id;
    std::map <int, User> group_map;
    Day free_time_day;
public:
    Group::Group() {};

    std::map <int, User> Group::GetMap() const { return group_map; }

    int Group::Size() const { return group_map.size(); }

    Group Group::AddUser(User& user) {
        group_map[user.user_id] = user;
    }

    Group Group::DeleteUser(User& user) {
        group_map.erase(user.user_id);
    };

    int Group::Size() {
        return group_map.size();
    }

    Group Group::GetGropup();
};

int main() {

}