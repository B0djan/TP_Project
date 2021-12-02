#include "day.h"

#define NUMBER_INTERVAL 12

    enum { BITS = sizeof(unsigned char) };
    Day::Day() {
        storage = new unsigned char[NUMBER_INTERVAL];
        flag_storage = new unsigned char[NUMBER_INTERVAL];
    }
    Day::~Day() {
        delete [] storage;
        delete [] flag_storage;
    }

    unsigned char* Day::GetStorage() const { return storage; }
    unsigned char* Day::FlagStorage() const { return flag_storage; }

    void Day::UnionDays(Day& aded_day) {
        for (unsigned char i = 0; i < NUMBER_INTERVAL; i ++) {
            storage[i] |= aded_day.GetStorage()[i];  
        };       
    }

    void Day::InvertDay(Day& busy_day) {
        for (unsigned char i = 0; i < NUMBER_INTERVAL; i ++) {
            storage[i] = ~busy_day.GetStorage()[i];  
        };       
    }

    void Day::InsertEvent(Duration& begin_time, Duration& end_time, bool flag) {
        unsigned char begin = begin_time.GetTimeInterval();
        unsigned char end = end_time.GetTimeInterval();

        while (begin < end) {
            storage[begin / BITS] |= ((unsigned char)1 << (begin % BITS));

            if (flag) {
                flag_storage[begin / BITS] |= ((unsigned char)1 << (begin % BITS));
            } else {
                (flag_storage[begin / BITS] &= ~((unsigned char)1 << (begin % BITS)));
            }

            begin ++;
        }
    }

    void Day::EraseEvent(Duration& begin_time, Duration& end_time) {

        char begin = begin_time.GetTimeInterval();
        char end = end_time.GetTimeInterval();

        while (begin < end) {
            storage[begin / BITS] &= ~((unsigned char)1 << (begin % BITS));
            flag_storage[begin / BITS] &= ~((unsigned char)1 << (begin % BITS));
            
            begin++;
        }
    }

    bool Day::IsFree(Duration& begin_time, Duration& end_time) {

        char begin = begin_time.GetTimeInterval();
        char end = end_time.GetTimeInterval();

        bool answer = true;

        while (begin < end) {
            answer = bool(storage[begin / BITS] >> (begin % BITS) & 1);
        }
        return answer;
    }

