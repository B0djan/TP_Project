#include "MeetUp.hpp"
#include "day.hpp"

int main() {

    // Эмуляция множества events

    std::set<std::set<event_t>> group_events;

    event_t e11;
    e11.time_begin = "00:00";
    e11.time_end = "01:15";

    event_t e12;
    e12.time_begin = "02:15";
    e12.time_end = "02:30";

    event_t e21;
    e21.time_begin = "11:30";
    e21.time_end = "12:30";

    event_t e22;
    e22.time_begin = "17:00";
    e22.time_end = "18:00";

    event_t e31;
    e31.time_begin = "22:30";
    e31.time_end = "23:00";

    std::set<event_t> d1;
        d1.insert(e11);
        d1.insert(e12);
    std::set<event_t> d2;
        d2.insert(e21);
        d2.insert(e22);
    std::set<event_t> d3;
        d3.insert(e31);

    group_events.insert(d1);
    group_events.insert(d2);
    group_events.insert(d3);

    Duration dur1("01:15");
    Duration dur2("02:30");

    std::cout << dur1 << '\n' << dur2 << '\n';

    Event event (dur1, dur2);

    event.Print();
    std::cout << "__________" << '\n';

//    Day day;
//    day.InsertEvent(event);
//    day.Print();

    std::cout << "__________" << '\n';

//    std::set<size_t> intervals;
//    intervals = event.GetIntervals();
//    for (auto elem: intervals) {
//        std::cout << elem << '\n';
//    }
//    std::cout << "__________" << '\n';

    // работа алгоритма

    MeetUp meetup (group_events);

    meetup.GetFreeTimeDay().Print();

    std::cout << "__________" << '\n';

    std::set<meetup_t> meetups = meetup.GetMeetUps();
    for (auto &elem : meetups) {
        std::cout << "time_begin = " << elem.time_begin << '\t';
        std::cout << "time_end = " << elem.time_end << '\n';
    }
}
