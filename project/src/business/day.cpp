#include <stdio.h>
#include <assert.h>
#include <map>

#include "../../include/include_business/day.hpp"

    Day::Day() {
        storage = new uint16_t[NUMBER_INTERVAL];
    }
    Day::~Day() {
        delete [] storage;
    }
    uint16_t* Day::GetStorage() const {
        return storage;
    }
    int Day::GetSize() const{
        return size;
    }

    void Day::Print() const {
        for (int i = 0; i < 96; i++) {
            if (IntervalIs(i)) {
                std::cout << "interval number " << std::setw(2) << i << " there is an event" << std::endl;
            } else {
                std::cout << "interval number " << std::setw(2) << i << " no event" << std::endl;
            }
        }
    }


    void Day::UnionDays(Day& added_day) {
        for (int i = 0; i < NUMBER_INTERVAL; i ++) {
            storage[i] |= added_day.GetStorage()[i];
            std::cout << '[' << i << ']' << storage[i] << std::endl;
        }
    }

    void Day::ShowDay() const{
        for (int i = 0; i < NUMBER_INTERVAL; i ++) {
            std::cout << '[' << i << ']' << storage[i] << std::endl;
        }
    }

    // (TODO) сделать InvertDay(void) - меняет состоянии исходного объекта;

    void Day::InversionDay() {
        for (int i = 0; i < NUMBER_INTERVAL; i ++) {
            storage[i] = ~ storage[i];
        }
    }

    // (TODO) : InsertEvent(std::string, std::string)

    // конвертация в Duration внутри InsertEvent

    // имеет ли смысл duration как отдельный класс

    void Day::InsertEvent(Event& event) {
        uint16_t begin = event.GetBegin().GetNumberInterval();
        uint16_t end = event.GetEnd().GetNumberInterval();
        while (begin <= end) {
            storage[begin / BITS] |= ((uint16_t)1 << (begin % BITS));
            begin ++;
        };
    }
    bool Day::IntervalIs(uint16_t number) const{
        return storage[number / BITS] >> (number % BITS) & 1;
    }

    /*
    vector<set<event_t>> GetData(group_t) {

        необходимо получить массив занятых временных интервалов
        всех членов группы
    }

    set<meetup> GetMeetUps(vector<set<event_t>>) {
        Day free_day;

        for (auto member: mebmers) {
            Day user_day;

            for (auto event: events) {
                user_day.InsertEvent(begin, end);
            };

            free_day.UnionDays(user_day);
        };

        free_day.InvertDay();

        set<meetup> res = free_day.SeachMeetUps();
    };


    process(const ParserObject& request_body) {
        ParserObject res;

        group_t group

        for (auto gr: request_body.groups) {
            group = gr;
        }

        res = GetMeetUps(GetData(group));

        return res;
    }

    */

    void Day::EraseEvent(Duration& begin_time, Duration& end_time) {
        uint16_t begin = begin_time.GetNumberInterval();
        uint16_t end = end_time.GetNumberInterval();
        while (begin < end) {
            storage[begin / BITS] &= ~((uint16_t)1 << (begin % BITS));
            begin++;
        }
    }

    // bool Day::IsFree(Duration& begin_time, Duration& end_time) {

    //     char begin = begin_time.GetTimeInterval();
    //     char end = end_time.GetTimeInterval();

    //     bool answer = true;

    //     while (begin < end) {
    //         answer = bool(storage[begin / BITS] >> (begin % BITS) & 1);
    //     }
    //     return answer;
    //}

    // (TODO) : реализовать метод, который бегаю по дню, и метод создает set<meetup>

