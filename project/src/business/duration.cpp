#include "duration.h"

    Duration::Duration(unsigned char& t) {
        unsigned char total = t * 15;
        hour = total / 60;
        min = total % 60;
    }

    Duration::Duration(const std::string& time) {
        std::stringstream stream(time);
        int h, m = 0;
        stream >> h;
        stream.ignore(1);
        stream >> m;
        int total = h * 60 + m;
        hour = total / 60;
        min = total % 60;
    }

    unsigned char Duration::GetTimeInterval() {
        int total = hour * 60 * min;
        return (unsigned char)(total / 15 + 1);
    }

    void Duration::PrintDuration() {
        std::cout << hour << ":";
        std::cout << min << std::endl;
    }
