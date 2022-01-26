#pragma once

#include <Handler.hpp>

class SearchFreeTimeImpl : public Handler {
    std::set<meetup_t> SearchMeetUps(std::set<std::string>);

    std::set<std::set<event_t>> GetData(const group_t& g, const std::string& date);

    std::set<meetup_t> GetMeetUps(std::vector<std::set<event_t>>);

public:
    ParserObject process(const ParserObject& request_body) override;
};

class OutputHistoryMeetUpImpl : public Handler {
public:
    ParserObject process(const ParserObject& request_body) override;
};