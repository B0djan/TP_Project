#pragma once

#include <Route.hpp>

typedef std::string str;

typedef struct user data;

typedef struct personal data;

typedef struct address data;

typedef struct event data;

typedef struct group data;

typedef struct meetup data;

class RouteCollection: public Route {
    using ResCb = std::function<void(bool success)>;

public:
    void check_request(str request) override;

    //  base
    virtual void registration(user& data, ResCb) = 0;
    virtual void authentication(user& data, ResCb) = 0;

    //  synchro
    virtual void synchro_client(user& data, ResCb) = 0;

    //  contacts
    virtual void add_user_to_contacts(user& data, ResCb) = 0;
    virtual void rm_user_to_contacts(user& data, ResCb) = 0;

    virtual std::set<user> output_contacts(user& data, ResCb) = 0;

    //  personal data
    virtual void write_personal_data(personal& data, ResCb);

    //  user address
    virtual void write_address(address& data, ResCb) = 0;

    //  event
    virtual void add_event(event& data, ResCb) = 0;
    virtual void write_event(event& data, ResCb) = 0;
    virtual void rm_event(event& data, ResCb) = 0;

    virtual std::set<event> output_events(event& data, ResCb) = 0;

    //  group
    virtual void add_group(group& data, ResCb) = 0;
    virtual void write_group(group& data, ResCb) = 0;
    virtual void rm_group(group& data, ResCb) = 0;

    virtual void add_user(group& data, ResCb) = 0;
    virtual void rm_user(group& data, ResCb) = 0;

    virtual void join(group& data, ResCb) = 0;
    virtual void leave(group& data, ResCb) = 0;

    virtual void search_group(group& data, ResCb) = 0;

    virtual std::set<meetup> search_free_time(group& data, ResCb) = 0;

    virtual std::set<meetup> history_meetup(group& data, ResCb) = 0;
};
