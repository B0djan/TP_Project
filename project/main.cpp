#include "include/include_business/day.hpp"

#include "include/include_business/structs.hpp"
#include <vector>

int main() {

//    Day day1;
//    Day day2;

//    for (int i = 0; i < 96; i++) {
//        if (day1.IntervalIs(i)) {
//            std::cout << "interval number " << i << " is found" << std::endl;
//        } else {
//            std::cout << "interval number " << i << " is not found" << std::endl;
//        }
//    }

    int a = 1;  // 000001
    int b = 4;  // 000100
    int c = 8;  // 001000
    int f = 0;
    int d = 0;
    d |= a;
    d |= b;
    d |= c;
    d |= f;  // 001101

    std::cout << "d = " << d << ". Ожидалось 13" << std::endl;


    std::vector<std::set<event_t>> group_events;

    event_t e11;
    e11.time_begin = "01:15";
    e11.time_end = "02:30";

    event_t e12;
    e12.time_begin = "06:45";
    e12.time_end = "07:15";

    event_t e21;
    e21.time_begin = "11:30";
    e21.time_end = "12:30";

    event_t e22;
    e22.time_begin = "17:00";
    e22.time_end = "18:00";

    event_t e31;
    e31.time_begin = "22:30";
    e31.time_end = "23:00";

//    event_t e32;
//    e32.time_begin = "21:00";
//    e32.time_end = "22:00";

    std::set<event_t> d1;
        d1.insert(e11);
        d1.insert(e12);
    std::set<event_t> d2;
        d2.insert(e21);
        d2.insert(e22);
    std::set<event_t> d3;
        d3.insert(e31);
        //d3.insert(e32);

    group_events.push_back(d1);
    group_events.push_back(d2);
    group_events.push_back(d3);


    Day free_day;

    Day _day1;
    Day _day2;
    Day _day3;

    for (auto event: group_events[0]) {
        std::cout << event.time_begin << "  " << event.time_end << std::endl;
        Event _event (event.time_begin, event.time_end);
        _day1.InsertEvent(_event);
        _day1.ShowDay();
    }

    for (auto event: group_events[1]) {
        std::cout << event.time_begin << "  " << event.time_end << std::endl;
        Event _event (event.time_begin, event.time_end);
        _day2.InsertEvent(_event);
        _day2.ShowDay();
    }

    for (auto event: group_events[2]) {
        std::cout << event.time_begin << "  " << event.time_end << std::endl;
        Event _event (event.time_begin, event.time_end);
        _day3.InsertEvent(_event);
        _day3.ShowDay();
    }

    free_day.UnionDays(_day1);
    free_day.UnionDays(_day2);
    free_day.UnionDays(_day3);

    free_day.Print();



//    for (auto members_events: group_events) {
//        Day _day;
//        for (auto event: members_events) {
//            std::cout << event.time_begin << "  " << event.time_end << std::endl;
//            Event _event (event.time_begin, event.time_end);
//            _day.InsertEvent(_event);
//            _day.ShowDay();
//        }
//        std::cout << "  ___________ // ____________  " << std::endl;
//    }

    std::cout << "   ///   InversionDay   ///   " << std::endl;

//    free_day.Print();

    return 0;
}
