#include <string>
#include <map>

#include "user.h"
#include "day.h"

#include "group.h"

using namespace std;

class Group {
private:
    string group_id;
    map <int, User> map;
    Day day;
public:
    Group() {
        
    };

    Group AddUser() {

    };

    Group DeleteUser() {

    };

    int Size() {
        return map.size();
    }

    Group GetGropup();
};

int main() {

}