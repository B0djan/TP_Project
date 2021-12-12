#include <VectorHandlerImpl.hpp>

#include <ContactsImpl.hpp>
#include <EventImpl.hpp>
#include <GroupImpl.hpp>
#include <RegistrAuthImpl.hpp>
#include <SynchroClientImpl.hpp>
#include <WriteAddressDataImpl.hpp>
#include <WritePersonalDataImpl.hpp>

VectorHandlerImpl::VectorHandlerImpl() {
    //  Base
    handler_chain.push_back(new RegistrationImpl());
    handler_chain.push_back(new AuthenticationImpl());

    /*// Synchro
    handler_chain.push_back(new SynchroClientImpl());

    //  Write user personal data
    handler_chain.push_back(new WritePersonalDataImpl());

    //  Write user address
    handler_chain.push_back(new WriteAddressDataImpl());

    //  Event functional
    handler_chain.push_back(new AddEventImpl());
    handler_chain.push_back(new WriteEventImpl());
    handler_chain.push_back(new RmEventImpl());

    //  Contact functional
    handler_chain.push_back(new AddUserToContactsImpl());
    handler_chain.push_back(new RmUserToContactsImpl());

    //  Group functional
    handler_chain.push_back(new AddGroupImpl());
    handler_chain.push_back(new WriteGroupImpl());
    handler_chain.push_back(new RmGroupImpl());

    handler_chain.push_back(new AddUserImpl());
    handler_chain.push_back(new RmUserImpl());

    handler_chain.push_back(new JoinImpl());
    handler_chain.push_back(new LeaveImpl());

    handler_chain.push_back(new SearchGroupImpl());

    handler_chain.push_back(new SearchFreeTimeImpl());

    handler_chain.push_back(new OutputHistoryMeetUpImpl());*/

    capacity = handler_chain.size();
}

