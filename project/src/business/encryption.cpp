#include <string>
#include <iostream>

#include <string>

enum { CIPHER_NUMBER = 31011212 };

std::string Encryption(std::string& str) {

    std::string encrypt_string = str;

    for (int i = 0; i < encrypt_string.size(); i++) {
        encrypt_string[i] ^= CIPHER_NUMBER;
    };
    
    return encrypt_string;
};