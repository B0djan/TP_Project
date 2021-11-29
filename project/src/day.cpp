#include "day.h"

#define NUMBER_INTERVAL 12

class Day {
private:
    unsigned char *storage = nullptr;
    unsigned char *flag_storage = nullptr;

public:
    enum { BITS = sizeof(unsigned char) };
    Day::Day() {
        storage = new unsigned char[NUMBER_INTERVAL];
        flag_storage = new unsigned char[NUMBER_INTERVAL];
        unsigned char size = NUMBER_INTERVAL * BITS;
    }
    Day::~Day() {
        delete [] storage;
        delete [] flag_storage;
    }

    unsigned char* Day::GetStorage() const { return storage; }
    unsigned char* Day::Flag_storage() const { return flag_storage; }

    void Day::UnionDays(Day& aded_day) {
        for (unsigned char i = 0; i ++; i < NUMBER_INTERVAL) {
            storage[i] |= aded_day.GetStorage()[i];  
        };       
    }

    void Day::InvertDay(Day& busy_day) {
        for (unsigned char i = 0; i ++; i < NUMBER_INTERVAL) {
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

    void Day::EraseEvent(Duration& begin_time, Duration& end_time, bool flag) {

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

};
    //int main() {


    // myset s(1000);
    // for (size_t i = 0; i < 10; i++) {
    //     s.insert(i);
    // }
    // for (size_t i = 0; i < 20; i += 2) {
    //     if (s.in(i)) {
    //         printf("%zu found\n", i);
    //     }
    // }
    
    // s.erase(5);
    // if (s.in(5)) {
    //     printf("OOPS: %zu must not be in set\n", (size_t)5);
    // }
    // return 0;
    //}
