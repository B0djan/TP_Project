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



unsigned char StrToChar(const std::string& time);

std::string CharToStr(const unsigned char& time);


unsigned char DurarationToChar(const duration_t& duraton);

unsigned char DurarationToChar(const duration_t& duraton);


enum { BITS = sizeof(unsigned char) };

class Day {
    unsigned char *storage = nullptr;
public:
    
    Day();

    ~Day();

    unsigned char* GetStorage() const;

    void UnionDays(Day& added_day);

    void InvertDay(Day& busy_day);

    void InsertEvent(std::string& begin_time, std::string& end_time);

    void EraseEvent(std::string& begin_time, std::string& end_time);

    bool IsFree(unsigned char time_interval);

    std::set<std::string> GetSetOfFreeTime();
};

Day CreateFreeDay(std::vector<std::set<event_t>> members_evets);

class SearchFreeTimeImpl : public Handler {

    std::set<meetup_t> SearchMeetUps(std::set<std::string>);

    std::vector<std::set<event_t>> GetData(const group_t& g, const std::string& date);

    std::set<meetup_t> GetMeetUps(std::vector<std::set<event_t>>);

public:

    ParserObject process(const ParserObject& request_body) override;
};

class OutputHistoryMeetUpImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};