#include <string>

#include <iostream>

#include <json.hpp>

#include <ParserObject.hpp>


bool operator< (const event_t& lhs, const event_t& rhs) {
    return lhs.time_begin < rhs.time_begin;
}

bool operator< (const meetup_t& lhs, const meetup_t& rhs) {
    return lhs.time_begin < rhs.time_begin;
}
bool operator< (const group_t& lhs, const group_t& rhs) {
    return lhs.title < rhs.title;
}


namespace Debugging {
    void print_event_t(const event_t &e) {
        std::cout << "user_id      :---: " << e.user_id << std::endl;
        std::cout << "event_name   :---: " << e.event_name << std::endl;
        std::cout << "date         :---: " << e.date << std::endl;
        std::cout << "description  :---: " << e.description << std::endl;
        std::cout << "time_begin   :---: " << e.time_begin << std::endl;
        std::cout << "time_end     :---: " << e.time_end << std::endl;
    }

    void print_user_t(const user_t& u) {
        std::cout << u.user_id << std::endl;
        std::cout << u.email << std::endl;
        std::cout << u.password << std::endl;
        std::cout << u.nickname << std::endl;
    }

    void print_contacts_t(const contacts_t c) {
        std::cout << "user_id      :---: " << c.user_id << std::endl;
        for (std::set<std::string>::iterator it = c.list_contacts.begin(); it != c.list_contacts.end(); ++it) {
            std::cout << "contacts :---: " << *it << std::endl;
        }
    }
}