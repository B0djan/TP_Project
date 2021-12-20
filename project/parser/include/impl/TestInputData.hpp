#pragma once

#include <string_view>

#include <iostream>

#include <HttpClientAcceptorCustom.hpp>

class Test {
public:
    friend class HttpClientAcceptorCustom;

    std::string buf1;

    void input_str(std::string in) {
        buf1 = in;
    }

    void print_str() {
        std::cout << buf1 << "\n" << std::endl;
    }

    Test() = default;
    ~Test() = default;
};
