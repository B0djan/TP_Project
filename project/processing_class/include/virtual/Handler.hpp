#pragma once

#include <functional>

#include <string>

class ParserObject {
public:
    typedef struct object_body {
        std::string request;

        typedef struct user {
            std::string mail;
        } user_t;

        typedef struct personal_data {
            std::string name;
        } personal_data_t;

        typedef struct address_data {
            std::string country;
        } address_data_t;

        typedef struct event {
            std::string note;
        } event_t;

        typedef struct meetup {
            std::string date;
        } meetup_t;

        typedef struct group {
            std::string title;
        } group_t;

        typedef struct contacts {
            std::string user_id;
        } contacts_t;
    } object_body_t;

    ParserObject(const ParserObject& other) = default;
    ~ParserObject() = default;

    ParserObject& operator=(const ParserObject& other) = default;
};

class Handler {
public:
    using ResCb = std::function<void(bool success)>;

    ParserObject request_body, response_body;

    /*std::string request_t;

    void setRequest_t (std::string request_in) { request_t = request_in; }

    std::string getRequest_t () { return request_t; }*/

    virtual void process(ResCb);

    Handler() : request_body{}, response_body{} {}
    virtual ~Handler() = default; //  Деструктор нужно сделать виртуальным, так как класс базовый
};


