#include "include/include_business/day.hpp"

int main() {
    std::string time1 = "11:40";
    std::string time2 = "02:55";

    Duration t1 (time1);
    Duration t2 (time2);

    std::cout << "t1 = " << t1 << std::endl;
    std::cout << "t2 = " << t2 << std::endl;

    if (t1 < t2) {
        std::cout << "t1 < t2" << std::endl;
    } else {
        std::cout << "t2 < t1" << std::endl;
    }

    std::cout << "t1 + t2 = " << t1 + t2 << std::endl;
    std::cout << "t1 - t2 = " << t1 - t2 << std::endl;

    std::cout << "time of 11 interval = " << Duration (11) << std::endl;
    std::cout << "time of 3 interval = " << Duration (3) << std::endl;

    std::cout << "interval of time 11:40 = " << t1.GetNumberInterval() << std::endl;
    std::cout << "interval of time 02:55 = " << t2.GetNumberInterval() << std::endl;

    std::cout << "   ///   Test Events   ///   " << std::endl;

    Event event1 (t2, t1);
    std::cout << "event begin = " << event1.GetBegin() << std::endl;
    std::cout << "event end = " << event1.GetEnd() << std::endl;

    Day day1;

    //day1.InsertEvent(event1);

    std::string x = "00:08";
    std::string y = "02:47";

    Event event2 (x,y);

    day1.InsertEvent(event2);

    std::cout << day1.GetStorage()[0] << std::endl;

    std::cout << "   ///   Invitation   ///" << std::endl;

    day1.InvertDay();

    std::cout << day1.GetStorage()[0] << std::endl;

    return 0;
}
