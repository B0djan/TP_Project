#include "day.h"

#define NUMBER_INTERVAL 12

    enum { BITS = sizeof(unsigned char) };
    Day::Day() {
        storage = new unsigned char[NUMBER_INTERVAL];
    }
    Day::~Day() {
        delete [] storage;
    }

    unsigned char* Day::GetStorage() const { return storage; };

    void Day::UnionDays(Day& aded_day) {
        for (unsigned char i = 0; i < NUMBER_INTERVAL; i ++) {
            storage[i] |= aded_day.GetStorage()[i];  
        };       
    }

    // (TODO) сделать InverDay(void) - меняет состоянии исходного объекта;

    void Day::InvertDay(Day& busy_day) {
        for (unsigned char i = 0; i < NUMBER_INTERVAL; i ++) {
            storage[i] = ~busy_day.GetStorage()[i];  
        };
    }

    // (TODO) : InsertEvent(std::string, std::string)

    // конвертация в Duration внутри InsertEvent

    // имеет ли смысл duration как отдельный класс

    void Day::InsertEvent(Duration& begin_time, Duration& end_time) {
        unsigned char begin = begin_time.GetTimeInterval();
        unsigned char end = end_time.GetTimeInterval();

        while (begin < end) {
            storage[begin / BITS] |= ((unsigned char)1 << (begin % BITS));
            begin ++;
        }
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

        char begin = begin_time.GetTimeInterval();
        char end = end_time.GetTimeInterval();

        while (begin < end) {
            storage[begin / BITS] &= ~((unsigned char)1 << (begin % BITS));            
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

