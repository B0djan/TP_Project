#pragma once

#include <string_view>

#include <iostream>

class Test {
public:
    std::string_view buf;
    const char* buf1;

    void input_view(std::string_view in) {
        buf = in;
    }

    void input_str(const char* in) {
        buf1 = in;
    }

    void print_view() {
        std::cout << buf << "\n" << std::endl;
    }

    void print_str() {
        std::cout << buf1 << "\n" << std::endl;
    }

    Test() = default;
};