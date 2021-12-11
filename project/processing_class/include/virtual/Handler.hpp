#pragma once

#include <functional>

#include <string>

typedef std::string str;

class JSONObject {
public:
    typedef struct object_body {
        str request;

        typedef struct user {
            str mail;
        } user_t;

        typedef struct personal_data {
            str name;
        } personal_data_t;

        typedef struct address_data {
            str country;
        } address_data_t;

        typedef struct event {
            str note;
        } event_t;

        typedef struct meetup {
            str date;
        } meetup_t;

        typedef struct group {
            str title;
        } group_t;

        typedef struct contacts {
            str user_id;
        } contacts_t;
    } object_body_t;

    JSONObject(const JSONObject&) = default;
    ~JSONObject() = default;

    JSONObject& operator=(const JSONObject& other) = default;
};

class Handler {
public:
    using ResCb = std::function<void(bool success)>;

    JSONObject request_body, response_body;

protected:
    virtual ~Handler(){}; //  Деструктор нужно сделать виртуальным, так как класс базовый
};


