#pragma once


#include <C>
#include <vector>

#include <Handler.hpp>
#include <Contactsimpl.hpp>
#include <EventImpl.hpp>
#include <GroupImpl.hpp>
#include <RegistrAuthImpl.hpp>
#include <SynchroClientImpl.hpp>
#include <WriteAddressDataImpl.hpp>
#include <WritePersonalDataImpl.hpp>

class VectorHandler {
public:
    typedef std::vector<Handler*> vec;
    vec handler_chain;

    virtual VectorHandler();
    virtual ~VectorHandler() = default;
};

VectorHandler::VectorHandler() {
    //  Base
    handler_chain.push_back(new Registration());
    handler_chain.push_back(new Authentication());

    // Synchro
    handler_chain.push_back(new SynchroClient());

    //  Write user personal data
    handler_chain.push_back(new WritePersonalData());

    //  Write user address
    handler_chain.push_back(new WriteAddress());

    //  Event functional
    handler_chain.push_back(new AddEvent());
    handler_chain.push_back(new WriteEvent());
    handler_chain.push_back(new RmEvent());

    handler_chain.push_back(new OutputEvents());

    //  Contact functional
    handler_chain.push_back(new AddUserToContacts());
    handler_chain.push_back(new RmUserToContacts());
    handler_chain.push_back(new OutputContacts());

    //  Group functional
    handler_chain.push_back(new AddGroup());
    handler_chain.push_back(new WriteGroup());
    handler_chain.push_back(new RmGroup());

    handler_chain.push_back(new AddUser());
    handler_chain.push_back(new RmUser());

    handler_chain.push_back(new Join());
    handler_chain.push_back(new Leave());

    handler_chain.push_back(new SearchGroup());

    handler_chain.push_back(new SearchFreeTime());

    handler_chain.push_back(new OutputHistoryMeetUp());
}
