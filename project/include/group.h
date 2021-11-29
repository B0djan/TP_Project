#pragma once

#include <string>
#include <map>

#include "user.h"
#include "day.h"

class Group {
private:
    std::string group_id;
    std::map <int, User> group_map;
    Day day;
public:
    Group();

    std::map <int, User> GetMap() const;

    unsigned char* GetStorage();
    unsigned char* Flag_storage();

    void AddUser(User& user);

    void DeleteUser(User& user);

    void GetFreeTime(Group& group);

    int Size() const;
};
