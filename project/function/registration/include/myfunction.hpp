#include "pgbackend.hpp"
#include "parse_json.hpp"

#define SUCCESS     0
#define ERROR      -1

namespace Request
{
        //  interior 

    int RegistrationTo(user_t& r);

    char* GetId(user_t& r);
    

    int AutorizationTo(user_t& r);

        //  external

    std::string Registration(std::string);

    std::string Autorization(std::string);
}