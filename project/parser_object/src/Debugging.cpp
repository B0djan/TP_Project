#include <iostream>

#include <ParserObject.hpp>

namespace Debugging {
    void print_from_client(const std::string& in) {
        std::cout  << "From client  :---: " << in << std::endl;
    }

    void print_from_processing(const std::string& in) {
        std::cout << "From processing  :---: " << in << std::endl;
    }

    void print_event_t(const event_t& e) {
        std::cout << "user_id           :---: " << e.user_id << std::endl;
        std::cout << "event_name        :---: " << e.event_name << std::endl;
        std::cout << "date              :---: " << e.date << std::endl;
        std::cout << "description       :---: " << e.description << std::endl;
        std::cout << "time_begin        :---: " << e.time_begin << std::endl;
        std::cout << "time_end          :---: " << e.time_end << std::endl;
    }

    void print_meetup_t(const meetup_t& m) {
        std::cout << "user_id           :---: " << m.group_id << std::endl;
        std::cout << "event_name        :---: " << m.meetup_name << std::endl;
        std::cout << "date              :---: " << m.date << std::endl;
        std::cout << "description       :---: " << m.description << std::endl;
        std::cout << "time_begin        :---: " << m.time_begin << std::endl;
        std::cout << "time_end          :---: " << m.time_end << std::endl;
    }

    void print_user_t(const user_t& u) {
        std::cout << "user_id           :---: " << u.user_id << std::endl;
        std::cout << "email             :---: " << u.email << std::endl;
        std::cout << "password          :---: " << u.password << std::endl;
        std::cout << "nickname          :---: " << u.nickname << std::endl;
    }

    void print_contacts_t(const contacts_t& c) {
        std::cout << "user_id      :---: " << c.user_id << std::endl;
        for (std::set<std::string>::iterator it = c.list_contacts.begin(); it != c.list_contacts.end(); ++it) {
            std::cout << "contacts :---: " << *it << std::endl;
        }
    }

    void print_group_t(const group_t& g) {
        std::cout << "group_id         :---: " << g.group_id << std::endl;
        std::cout << "title            :---: " << g.title << std::endl;
        for (std::set<std::string>::iterator it = g.members.begin(); it != g.members.end(); ++it) {
            std::cout << "member          :---: " << *it << std::endl;
        }
    }

    void print_personal_data_t(const personal_data_t& d) {
        std::cout << "user_id          :---: " << d.user_id << std::endl;
        std::cout << "first_name       :---: " << d.first_name << std::endl;
        std::cout << "surname          :---: " << d.surname << std::endl;
        std::cout << "age              :---: " << d.age << std::endl;
        std::cout << "phone_number     :---: " << d.phone_number << std::endl;
        std::cout << "status           :---: " << d.status << std::endl;
        std::cout << "label            :---: " << d.label << std::endl;
        std::cout << "description      :---: " << d.description << std::endl;
    }

    void print_address_data_t(const address_data_t& a) {
        std::cout << "user_id          :---: " << a.user_id << std::endl;
        std::cout << "building         :---: " << a.building << std::endl;
        std::cout << "housing          :---: " << a.housing << std::endl;
        std::cout << "street           :---: " << a.street << std::endl;
        std::cout << "city             :---: " << a.city << std::endl;
        std::cout << "district         :---: " << a.district << std::endl;
        std::cout << "index            :---: " << a.index << std::endl;
        std::cout << "country          :---: " << a.country << std::endl;
    }

    void print_user_group(const user_t& u, const group_t& g) {
        std::cout << "user_id         :---: " << u.user_id << std::endl;
        std::cout << "nickname        :---: " << u.nickname << std::endl;

        std::cout << "title           :---: " << g.title << std::endl;
    }
}