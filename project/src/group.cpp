#include <string>
#include <map>

#include "user.h"
#include "day.h"

#include "group.h"

class Group {
private:
    int group_id;
    std::map <int, User> group_map;
    Day day;
public:
    Group() {};

    std::map <int, User> GetMap() const { return group_map; }

    int Size() const { return group_map.size(); }

    Group AddUser(User& user) {
        group_map[user.user_id] = user;
    }

    Group DeleteUser(User& user) {
        group_map.erase(user.user_id);
    };

    int Size() {
        return group_map.size();
    }

    Group GetGropup();
};

int main() {

}