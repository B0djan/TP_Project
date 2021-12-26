#pragma once

#include <set>

#include <vector>

#include <Handler.hpp>

class AddGroupImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class WriteGroupImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmGroupImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};



class AddUserImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class RmUserImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class JoinImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};

class LeaveImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};



class SearchGroupImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};



class SearchFreeTimeImpl : public Handler {
    class Duration {
    private:
        int hour;
        int min;
    public:
        Duration(const std::string& time);

        unsigned char GetTimeInterval();
    };

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

    std::vector<std::set<event_t>> GetData(group_t);

    std::set<meetup_t> GetMeetUps(std::vector<std::set<event_t>>);

public:
    ParserObject process(const ParserObject& request_body) override;
};

class OutputHistoryMeetUpImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};
