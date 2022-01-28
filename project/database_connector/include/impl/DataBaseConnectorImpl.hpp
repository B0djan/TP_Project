#include "Structs.hpp"

#define SUCCESS     0
#define ERROR      -1

#define GLOBAL_KEY_TEST_DATABASE_CON true

namespace DatabaseConnector {
    namespace GetID {
        char* User(const std::string& nickname);

        char* Event(const event_t& e);

        char* Group(const std::string& title);
    }

    namespace GetNickname {
        char* User(const std::string& user_id);
    }

    namespace Security {
        int ReWritePassword(const std::string& user_id, const std::string& password);
        int ReWriteNickname(const std::string& user_id, const std::string& nickname);
    }

    namespace Group {
        int Create(const group_t& group);

        int Write(const group_t& group);

        int DeleteAllMembers(const std::string &group_id);

        int Delete(const std::string& group_id);

        group_t GetMembers(const std::string& group_id);

        namespace Management {
            int AddMember(const std::string& member, const std::string);

            int RmMember(const std::string& member, const std::string);
        }
    }

    namespace Data {
        namespace Address {
            int CreateNull(const std::string& user_id);
            int ReWrite(const address_data_t& a);
            address_data_t Get(const std::string &user_id);
        }

        namespace Personal {
            int CreateNull(const std::string& user_id);
            int ReWrite(const personal_data_t& a);
            personal_data_t Get(const std::string &user_id);
        }

        namespace General {
            int CreateNull(const std::string& user_id);
            int ReWrite(const general_data_t& a);
            general_data_t Get(const std::string &user_id);
        }
    }

    namespace Synchro {
        std::set<std::string> Contacts(const std::string& user_id);

        std::set<group_t> Groups(const std::string& user_id);

        std::set<event_t> Events(const std::string& user_id, const std::string& date);
    }

    namespace RegAuth {
        int Registration(const user_t &r);

        int Autorization(const user_t &r);
    }

    namespace Contact {
        int Add(const std::string& user_id_main, const std::string& user_id_friend);

        int Delete(const std::string& user_id_main, const std::string& user_id_friend);
    }

    namespace Event {
        int Add(const event_t& e);

        int Write(const event_t& e);

        int Delete(const std::string& event_id);
    }
}
