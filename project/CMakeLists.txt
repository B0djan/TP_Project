INCLUDE_DIRECTORIES(base_architecture/include/impl)
INCLUDE_DIRECTORIES(base_architecture/include/virtual)

INCLUDE_DIRECTORIES(parser_object/include)

INCLUDE_DIRECTORIES(processing_class/include/impl)
INCLUDE_DIRECTORIES(processing_class/include/virtual)

INCLUDE_DIRECTORIES(route/include/impl)
INCLUDE_DIRECTORIES(route/include/virtual)


INCLUDE_DIRECTORIES(parser_class/JSON/libs/single_include/nlohmann)
INCLUDE_DIRECTORIES(parser_class/JSON/include/impl)
INCLUDE_DIRECTORIES(parser_class/virtual)

INCLUDE_DIRECTORIES(database_connector/PostgreSQL/include/impl)

INCLUDE_DIRECTORIES(database_connector/libs/PostgreSQL)

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
        processing_class/src/GroupImpl/Base/GroupImpl.cpp
        processing_class/src/GroupImpl/User/UserGroupImpl.cpp
        processing_class/src/GroupImpl/MeetUp/MeetUpImpl.cpp
        processing_class/src/GroupImpl/MeetUp/SupportMeetUp.cpp
        processing_class/src/RegistrAuthImpl.cpp
        processing_class/src/SynchroClientImpl.cpp
        processing_class/src/WriteAddressDataImpl.cpp
        processing_class/src/WritePersonalDataImpl.cpp
        processing_class/src/Support/SupportProcess.cpp)

SET(SOURCE_LIST_PARSER_CLASS
        parser_class/JSON/src/ParserContactsImpl.cpp
        parser_class/JSON/src/ParserEventImpl.cpp
        parser_class/JSON/src/ParserGroupImpl.cpp
        parser_class/JSON/src/ParserRegistrAuthImpl.cpp
        parser_class/JSON/src/ParserWriteAddressDataImpl.cpp
        parser_class/JSON/src/ParserWritePersonalDataImpl.cpp)

SET(SOURCE_LIST_PARSER_OBJECT
        parser_object/src/ParserObject.cpp)

SET(SOURCE_LIST_DATA
        database_connector/PostgreSQL/src/PGConnection.cpp)


ADD_EXECUTABLE(${PROJECT_NAME}
        ${SOURCE_LIST_SERVER}
        ${SOURCE_LIST_ROUTE}
        ${SOURCE_LIST_PROCESSING_CLASS}
        ${SOURCE_LIST_PARSER_CLASS}
        ${SOURCE_LIST_PARSER_OBJECT}
        ${SOURCE_LIST_DATA})

