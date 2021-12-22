#pragma once

#include <string>
#include <iostream>

#include "libpq-fe.h"

// (TODO): Сделать класс ридер для конфига к базе

class PGConnection {

    PGConnection() = default;  // equivalent () {}
    ~PGConnection() = default;

    PGConnection(const PGConnection&) = delete;
    PGConnection& operator=(const PGConnection&) = delete;

    std::string dbhost = "hattie.db.elephantsql.com";
    int         dbport = 5432;
    std::string dbname = "geksbdhf";
    std::string dbuser = "geksbdhf";
    std::string dbpass = "7-K2Rtju21HcO6adxmLXZuCEx8SQTVIQ";

    PGconn* connection = PQsetdbLogin(dbhost.c_str(), 
                                    std::to_string(dbport).c_str(), 
                                    nullptr, 
                                    nullptr, 
                                    dbname.c_str(), 
                                    dbuser.c_str(), 
                                    dbpass.c_str());

public:
    static PGconn* GetConnection();

    static void CloseConnection();
};
