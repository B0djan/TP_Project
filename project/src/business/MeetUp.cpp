#include "MeetUp.hpp"

MeetUp::MeetUp(const std::set<std::set<event_t>> &group_events) {
    for (auto &day: group_events) {
        for (auto &event: day) {
            Event user_event(event.time_begin, event.time_end);
            FreeTimeDay.InsertEvent(user_event);
            this->FreeTimeDay.InversionDay();
        }
    }
    for (size_t i = 0; i < 94; i++) {
        if (this->FreeTimeDay.IntervalIs(i)) {
            size_t begin_e = i;
            size_t end_e = i;
            while (this->FreeTimeDay.IntervalIs(i + 1)) {
                end_e = i;
                i++;
            }
            Duration begin(begin_e);
            Duration end(end_e);
            Event event(begin, end);
            this->DayMeetUp.insert(event);
        }
    }
}

Day MeetUp::GetDay() {
    return FreeTimeDay;
}
std::set<Event> MeetUp::GetDayMeetUp() {
    return DayMeetUp;
}

void MeetUp::Set(const std::set<std::set<event_t>> &group_events) {
    FreeTimeDay.Free();
    for (auto &day: group_events) {
        for (auto &event: day) {
            Event user_event (event.time_begin, event.time_end);
            FreeTimeDay.InsertEvent(user_event);
        }
    }
}

std::set<meetup_t> GetMeetUps (MeetUp& m) {
    std::set<meetup_t> answer;
    for (auto elem : m.GetDayMeetUp()) {
        meetup_t meetup;
        meetup.time_begin = elem.GetBegin().GetTimeString();
        meetup.time_end = elem.GetEnd().GetTimeString();
        answer.insert(meetup);
    }
    return answer;
}