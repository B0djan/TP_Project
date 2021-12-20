INCLUDE_DIRECTORIES(base_architecture/include/impl)
INCLUDE_DIRECTORIES(base_architecture/include/virtual)

INCLUDE_DIRECTORIES(parser_object)

INCLUDE_DIRECTORIES(processing_class/include/impl)
INCLUDE_DIRECTORIES(processing_class/include/virtual)

INCLUDE_DIRECTORIES(route/include/impl)
INCLUDE_DIRECTORIES(route/include/virtual)


INCLUDE_DIRECTORIES(parser/include/libs/single_include/nlohmann)
INCLUDE_DIRECTORIES(parser/include/impl)
INCLUDE_DIRECTORIES(parser/include/virtual)


SET(SOURCE_LIST_SERVER
        base_architecture/src/AsyncFileInputStream.cpp
        base_architecture/src/AsyncFileOutputStream.cpp
        base_architecture/src/SelectBasedEventLoop.cpp
        base_architecture/src/ListeningNetworkSocket.cpp
        base_architecture/src/HttpClientAcceptor.cpp
        base_architecture/src/FileImpl.cpp
        base_architecture/src/main.cpp)

SET(SOURCE_LIST_ROUTE
        route/src/RouteImpl.cpp)

SET(SOURCE_LIST_PROCESSING_CLASS
        processing_class/src/ContactsImpl.cpp
        processing_class/src/EventImpl.cpp
        processing_class/src/GroupImpl.cpp
        processing_class/src/RegistrAuthImpl.cpp
        processing_class/src/SynchroClientImpl.cpp
        processing_class/src/WriteAddressDataImpl.cpp
        processing_class/src/WritePersonalDataImpl.cpp)

SET(SOURCE_LIST_PARSER_CLASS
        parser/src_json/ParserContactsImpl.cpp
        parser/src_json/ParserEventImpl.cpp
        parser/src_json/ParserGroupImpl.cpp
        parser/src_json/ParserRegistrAuthImpl.cpp
        parser/src_json/ParserSynchroClientImpl.cpp
        parser/src_json/ParserWriteAddressDataImpl.cpp
        parser/src_json/ParserWritePersonalDataImpl.cpp)





INCLUDE_DIRECTORIES(parser/include/)

INCLUDE_DIRECTORIES(database_connector/include/impl)
INCLUDE_DIRECTORIES(database_connector/include/libs/postgresql)

INCLUDE_DIRECTORIES(function/registration/include)

SET(SOURCE_LIST_PARSER
        parser/src_json/single/addres.cpp
        parser/src_json/single/contacts.cpp
        parser/src_json/single/event.cpp
        parser/src_json/single/group.cpp
        parser/src_json/single/meetup.cpp
        parser/src_json/single/person.cpp
        parser/src_json/single/user.cpp
        parser/src_json/methods/reg_and_au.cpp
        parser/src_json/methods/friend.cpp
        parser/src_json/methods/get_id.cpp
        parser/src_json/methods/shedule.cpp)

SET(SOURCE_LIST_FA
        function/registration/src/myfunction.cpp)


SET(SOURCE_LIST_DATA
        database_connector/src_postge_sql/pgconnection.cpp)


ADD_EXECUTABLE(${PROJECT_NAME}
        ${SOURCE_LIST_SERVER}
        ${SOURCE_LIST_ROUTE}
        ${SOURCE_LIST_PROCESSING_CLASS}
        ${SOURCE_LIST_PARSER_CLASS}


        ${SOURCE_LIST_PARSER}
        ${SOURCE_LIST_DATA}
        ${SOURCE_LIST_FA})

