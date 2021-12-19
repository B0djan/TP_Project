#include <iostream>

#include "pgconnection.hpp"
#include "pgbackend.hpp"

int main() {

    std::cout << PGConnection::GetConnection() << "адрес соединения единственый - OK" << std::endl;

    return 0;
}