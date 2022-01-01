#include "include/include_business/function.hpp"

int main() {
    std::set<std::set<event_t>> group_events;

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

    std::set<event_t> d1;
        d1.insert(e11);
        d1.insert(e12);
    std::set<event_t> d2;
        d2.insert(e21);
        d2.insert(e22);
    std::set<event_t> d3;
        d3.insert(e31);
        //d3.insert(e32);

    group_events.insert(d1);
    group_events.insert(d2);
    group_events.insert(d3);

    Day free = GetFreeDay(group_events);
    free.Print();
}
