#include "structs.hpp"

bool operator< (const event_t& lhs, const event_t& rhs) {
    if (lhs.date == rhs.date)
    {
        if (lhs.time_begin == rhs.time_begin)
        {
            if (lhs.time_end == rhs.time_end)
            {
                if (lhs.event_name == rhs.event_name)
                {
                    return lhs.description < rhs.description;
                }
                return lhs.event_name < rhs.event_name;
            }
            return lhs.time_end < rhs.time_end;
        }
        return lhs.time_begin < rhs.time_begin;
    }
    return lhs.date < rhs.date;
}

bool operator< (const meetup_t& lhs, const meetup_t& rhs) {
    if (lhs.date == rhs.date)
    {
        if (lhs.time_begin == rhs.time_begin)
        {
            if (lhs.time_end == rhs.time_end)
            {
                if (lhs.meetup_name == rhs.meetup_name)
                {
                    return lhs.description < rhs.description;
                }
                return lhs.meetup_name < rhs.meetup_name;
            }
            return lhs.time_end < rhs.time_end;
        }
        return lhs.time_begin < rhs.time_begin;
    }
    return lhs.date < rhs.date;
}

bool operator< (const group_t& lhs, const group_t& rhs) {
    if (lhs.title == rhs.title)
    {
        return (lhs.members < rhs.members);
    }
    return (lhs.title < rhs.title);
}
