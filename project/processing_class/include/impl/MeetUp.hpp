#pragma once

#include <Handler.hpp>

typedef struct {
    int hour;
    int min;
} duration_t;

class SearchFreeTimeImpl : public Handler {
    duration_t get_format(const std::string& time);

    unsigned char GetTimeInterval(const duration_t& dur);

    class Day {
    private:
        unsigned char *storage = nullptr;
    public:
        Day() = default;
        ~Day() = default;

        unsigned char* GetStorage() const;

        void UnionDays(Day& added_day);

        void InvertDay(Day& busy_day);

        void InsertEvent(duration_t& begin_time, duration_t& end_time);

        void EraseEvent(duration_t& begin_time, duration_t& end_time);

        bool IsFree(duration_t& begin_time, duration_t& end_time);
    };

    std::vector<std::set<event_t>> GetData(const group_t& g,  const std::string& date);

    std::set<meetup_t> GetMeetUps(std::vector<std::set<event_t>>);

public:

    ParserObject process(const ParserObject& request_body) override;
};

class OutputHistoryMeetUpImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};


//  Оригиналы
/*
class Duration {
    private:
        int hour;
        int min;
    public:
        Duration(const std::string& time);

        unsigned char GetTimeInterval();
    }

    class Day {
    private:
        unsigned char *storage = nullptr;
    public:
        Day() = default;
        ~Day() = default;

        unsigned char* GetStorage() const;

        void UnionDays(Day& added_day);

        void InvertDay(Day& busy_day);

        void InsertEvent(Duration& begin_time, Duration& end_time);

        void EraseEvent(Duration& begin_time, Duration& end_time);

        bool IsFree(Duration& begin_time, Duration& end_time);
    };

*/