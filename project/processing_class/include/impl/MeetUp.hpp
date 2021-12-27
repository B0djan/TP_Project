#pragma once

#include <Handler.hpp>

typedef struct {
    int hour;
    int min;
} duration_t;

class Day {
    unsigned char *storage = nullptr;

    duration_t Day::StrToDuration(const std::string &time);

    std::string Day::DurationToStr(const duration_t& time);

    duration_t CharToDuration(const unsigned char& time_interval);

    unsigned char Day::DurarationToChar(const duration_t& duraton);
public:
    Day() = default;
    ~Day() = default;

    unsigned char* GetStorage() const;

    void UnionDays(Day& added_day);

    void InvertDay();

    void InsertEvent(std::string& begin_time, std::string& end_time);

    void EraseEvent(std::string& begin_time, std::string& end_time);

    bool IsFree(std::string& begin_time, std::string& end_time);

    std::set<meetup_t> SearchMeetUps();
};

class SearchFreeTimeImpl : public Handler {

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