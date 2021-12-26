#include "Structs.hpp"

#define SUCCESS     0
#define ERROR      -1

#define GLOBAL_KEY_TEST_DATABASE_CON false

namespace DatabaseConnector {
    namespace Process {
        char* GetUserId(const std::string& nickname);

        char* GetEventId(const event_t& e);

        char* GetGroupId(const std::string& title);
    }

    namespace Group {
        int AddMember(const std::string& member, const std::string);

        int RmMember(const std::string& member, const std::string);
    }

    namespace PersonalData {
        int CreateAddressData(const std::string& user_id);

        int CreatePersonalData(const std::string& user_id);
    }

    namespace Synchro {
        std::set<std::string> GetContacts(const std::string& user_id);

        std::set<std::string> GetGroups(const std::string& user_id);

        std::set<event_t> GetEvents(const event_t& e);
    }

    namespace RegAuth {
        int RegistrationTo(const user_t &r);

        int AutorizationTo(const user_t &r);
    }
}
