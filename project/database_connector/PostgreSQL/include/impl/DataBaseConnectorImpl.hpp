#include "Structs.hpp"

#define SUCCESS     0
#define ERROR      -1

#define GLOBAL_KEY_TEST_DATABASE_CON false

namespace DatabaseConnector {
    namespace GetID {
        char* User(const std::string& nickname);

        char* Event(const event_t& e);

        char* Group(const std::string& title);
    }

    namespace Group {
        int AddMember(const std::string& member, const std::string);

        int RmMember(const std::string& member, const std::string);
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
    }

    namespace Synchro {
        std::set<std::string> GetContacts(const std::string& user_id);

        std::set<std::string> GetGroups(const std::string& user_id);

        std::set<event_t> GetEvents(const event_t& e);
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

        int Delete(const event_t& e);
    }
}