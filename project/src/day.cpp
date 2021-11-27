#include <stdio.h>
#include <assert.h>

#include "date.h"
#include "time.h"
#include "day.h"

#define TIME_INTERVAL 12

class Day {
public:
    enum { BITS = sizeof(unsigned char)};
    Day() {
        storage = new unsigned char[TIME_INTERVAL];
        flag_storage = new unsigned char[TIME_INTERVAL];
        unsigned char size = TIME_INTERVAL * BITS;
    }
    ~Day() {
        delete [] storage;
        delete [] flag_storage;
    }

    void insert(Time& begin, Time& end, unsigned char time_interval, bool flag) { // если можно двигать то flag = true;
        //assert(time_interval < size);
        storage[time_interval / BITS] |= ((unsigned char)1 << (time_interval % BITS));
        if (flag)
            flag_storage[time_interval / BITS] |= ((unsigned char)1 << (time_interval % BITS));
        else (flag_storage[time_interval / BITS] &= ~((unsigned char)1 << (time_interval % BITS)));
    }
    void erase(unsigned char time_interval) {
        //assert(elem < size);
        storage[time_interval / BITS] &= ~((unsigned char)1 << (time_interval % BITS));
        flag_storage[time_interval / BITS] &= ~((unsigned char)1 << (time_interval % BITS));
    }
    // bool in(size_t elem) {
    //     //assert(elem < size);
    //     return storage[elem / BITS] >> (elem % BITS) & 1;
    // }
private:
    unsigned char *storage = nullptr;
    unsigned char *flag_storage = nullptr;
};

int main() {
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
}
