#include <stdio.h>
#include "date.h"

//{"user_id, "event(_name), "date", begin, end,}

class Day {
    enum { BITS = 8 * sizeof(unsigned char) }; //96 бит, 12 чанков
    enum {NUMBER_CHANKS = 12};
public:
    Day() /*создать класс*/ {

    }
    void add_event() {

    }
    void delite_event() {

    } 

private:
    unsigned char* storage = nullptr;

    size_t size = BITS * NUMBER_CHANKS;

    /*на size_t поместится 64 числа, а надо 96, поэтому
    придется использовать объект состоящий из нескольких
    типов. 96 бит/8 бит = 12 чанков. 8 бит - unsigned char*/

 }
 