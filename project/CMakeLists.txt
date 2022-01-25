INCLUDE_DIRECTORIES(base_architecture/include/impl)
INCLUDE_DIRECTORIES(base_architecture/include/virtual)

INCLUDE_DIRECTORIES(parser_object/include)

INCLUDE_DIRECTORIES(processing_class/include/impl)
INCLUDE_DIRECTORIES(processing_class/include/virtual)

INCLUDE_DIRECTORIES(route/include/impl)
INCLUDE_DIRECTORIES(route/include/virtual)

INCLUDE_DIRECTORIES(parser_class/JSON/libs/single_include/nlohmann)
INCLUDE_DIRECTORIES(parser_class/include/impl)
INCLUDE_DIRECTORIES(parser_class/include/virtual)

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
        "database_connector/PostgreSQL/src/Group/Management.cpp"
        processing_class/src/GroupImpl/User/UserGroupImpl.cpp
        processing_class/src/GroupImpl/MeetUp/MeetUpImpl.cpp
        processing_class/src/GroupImpl/MeetUp/SupportMeetUp.cpp
        processing_class/src/SynchroClientImpl.cpp
        processing_class/src/RegistrAuthImpl.cpp
        processing_class/src/WriteAddressDataImpl.cpp
        processing_class/src/WriteGeneralDataImpl.cpp
        processing_class/src/WritePersonalDataImpl.cpp
        database_connector/PostgreSQL/src/GetID.cpp)

SET(SOURCE_LIST_PARSER_CLASS
        parser_class/JSON/src/ParserContactsImpl.cpp
        parser_class/JSON/src/ParserEventImpl.cpp
        parser_class/JSON/src/ParserGroupImpl/ParserGroupImpl.cpp
        parser_class/JSON/src/ParserGroupImpl/ParserMeetUpImpl.cpp
        parser_class/JSON/src/ParserRegistrAuthImpl.cpp
        parser_class/JSON/src/ParserWriteAddressDataImpl.cpp
        parser_class/JSON/src/ParserWriteGeneralDataImpl.cpp
        parser_class/JSON/src/ParserWritePersonalDataImpl.cpp)

SET(SOURCE_LIST_PARSER_OBJECT
        parser_object/src/Structs.cpp)

SET(SOURCE_LIST_DATABASE
        database_connector/PostgreSQL/src/GetID.cpp
        database_connector/PostgreSQL/src/RegAuth.cpp
        database_connector/PostgreSQL/src/Contact.cpp
        database_connector/PostgreSQL/src/Event.cpp
        database_connector/PostgreSQL/src/Data/Address.cpp
        database_connector/PostgreSQL/src/Data/Personal.cpp
        database_connector/PostgreSQL/src/Data/General.cpp
        database_connector/PostgreSQL/src/Group/Base.cpp
        database_connector/PostgreSQL/src/Group/Management.cpp
        database_connector/PostgreSQL/src/SynchronizationClient.cpp
        database_connector/PostgreSQL/src/PGConnection.cpp)


ADD_EXECUTABLE(${PROJECT_NAME}
        ${SOURCE_LIST_SERVER}
        ${SOURCE_LIST_ROUTE}
        ${SOURCE_LIST_PROCESSING_CLASS}
        ${SOURCE_LIST_PARSER_CLASS}
        ${SOURCE_LIST_PARSER_OBJECT}
        ${SOURCE_LIST_DATABASE})

