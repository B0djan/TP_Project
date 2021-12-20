INCLUDE_DIRECTORIES(base_architecture/include/impl)
INCLUDE_DIRECTORIES(base_architecture/include/virtual)

INCLUDE_DIRECTORIES(processing_class/include/impl)
INCLUDE_DIRECTORIES(processing_class/include/virtual)

INCLUDE_DIRECTORIES(route/include/impl)
INCLUDE_DIRECTORIES(route/include/virtual)


SET(SOURCE_LIST
        base_architecture/src/AsyncFileInputStream.cpp
        base_architecture/src/AsyncFileOutputStream.cpp
        base_architecture/src/SelectBasedEventLoop.cpp
        base_architecture/src/ListeningNetworkSocket.cpp
        base_architecture/src/HttpClientAcceptor.cpp
        base_architecture/src/FileImpl.cpp
        base_architecture/src/main.cpp )

SET(SOURCE_LIST_PROCESSING_CLASS
        processing_class/src/ContactsImpl.cpp
        processing_class/src/EventImpl.cpp
        processing_class/src/GroupImpl.cpp
        processing_class/src/RegistrAuthImpl.cpp
        processing_class/src/SynchroClientImpl.cpp
        processing_class/src/WriteAddressDataImpl.cpp
        processing_class/src/WritePersonalDataImpl.cpp )

SET(SOURCE_LIST_ROUTE
        route/src/RouteImpl.cpp)










INCLUDE_DIRECTORIES(parser/include/)
INCLUDE_DIRECTORIES(parser/include/nlohmann)

INCLUDE_DIRECTORIES(database_connector/include/impl)


INCLUDE_DIRECTORIES(libs/database_connector/postgresql/)
INCLUDE_DIRECTORIES(libs/parsing/include/nlohmann/)
INCLUDE_DIRECTORIES(libs/parsing/include/nlohmann/)

INCLUDE_DIRECTORIES(function/registration/include/)

SET(SOURCE_LIST_PARSER
        parser/src/single/addres.cpp
        parser/src/single/contacts.cpp
        parser/src/single/event.cpp
        parser/src/single/group.cpp
        parser/src/single/meetup.cpp
        parser/src/single/person.cpp
        parser/src/single/user.cpp
        parser/src/methods/reg_and_au.cpp
        parser/src/methods/friend.cpp
        parser/src/methods/get_id.cpp
        parser/src/methods/shedule.cpp)

SET(SOURCE_LIST_FA
        function/registration/src/myfunction.cpp)


SET(SOURCE_LIST_DATA
        database_connector/src/pgconnection.cpp
        )


ADD_EXECUTABLE(${PROJECT_NAME}
        ${SOURCE_LIST}
        ${SOURCE_LIST_PROCESSING_CLASS}
        ${SOURCE_LIST_ROUTE}
        ${SOURCE_LIST_PARSER}
        ${SOURCE_LIST_DATA}
        ${SOURCE_LIST_FA})

