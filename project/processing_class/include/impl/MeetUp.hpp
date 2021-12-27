#pragma once

#include <Handler.hpp>

#define NUMBER_INTERVAL 12

typedef struct {
    int hour;
    int min;
    int total = hour * 60 + min;
} duration_t;

int operator-(const duration_t& lhs, const duration_t& rhs);

duration_t StrToDuration(const std::string &time);

std::string DurationToStr(const duration_t& time);

duration_t CharToDuration(const unsigned char& time_interval);

unsigned char StrToChar(const std::string& time);

std::string CharToStr(const unsigned char& time);

unsigned char DurarationToChar(const duration_t& duraton);

unsigned char DurarationToChar(const duration_t& duraton);

Day CreateFreeDay(std::vector<std::set<event_t>> members_evets);


enum { BITS = sizeof(unsigned char) };

class Day {
    unsigned char *storage = nullptr;

public:
    
    Day() {};

    ~Day() {};

    unsigned char* GetStorage() const;

    void UnionDays(Day& added_day);

    void InvertDay(Day& busy_day);

    void InsertEvent(std::string& begin_time, std::string& end_time);

    void EraseEvent(std::string& begin_time, std::string& end_time);

    bool Day::IsFree(unsigned char time_interval);

    std::set<meetup_t> SearchMeetUps();

    std::set<std::string> Day::GetSetOfFreeTime();
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