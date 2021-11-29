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

    #define CODE 0;

    // int compare (unsigned char day1, unsigned char day2, 
    //              unsigned char* free_time_day) {

    //     unsigned char busy_time_day = day1 | day2; //...

    //     *free_time_day = ~busy_time_day;
    
    //     return CODE;
    // }

    Day GetFreeTime(Group& group) {
        std::map<int, User> m = group.GetMap();
        Day busy;
        for (auto item: m) {
            busy.UnionDays(item.second.day);     
        }
        Day free;
        free.InvertDay(busy);
    }

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