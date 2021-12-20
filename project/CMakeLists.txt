INCLUDE_DIRECTORIES(base_architecture/include/impl)
INCLUDE_DIRECTORIES(base_architecture/include/virtual)

INCLUDE_DIRECTORIES(processing_class/include/impl)
INCLUDE_DIRECTORIES(processing_class/include/virtual)

INCLUDE_DIRECTORIES(route/include/impl)
INCLUDE_DIRECTORIES(route/include/virtual)

INCLUDE_DIRECTORIES(parser/include/impl)
INCLUDE_DIRECTORIES(parser/include/virtual)

INCLUDE_DIRECTORIES(database_connector/include/impl)
INCLUDE_DIRECTORIES(database_connector/include/virtual)


INCLUDE_DIRECTORIES(libs/database_connector/postgresql/)
INCLUDE_DIRECTORIES(libs/database_connector/postgresql/internal/)
INCLUDE_DIRECTORIES(libs/database_connector/postgresql/internal/libpq/)
INCLUDE_DIRECTORIES(libs/database_connector/postgresql/libpq/)
INCLUDE_DIRECTORIES(libs/parsing/include/nlohmann/)
INCLUDE_DIRECTORIES(libs/parsing/include/nlohmann/)



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

SET(SOURCE_LIST_PARSER
        parser/src/JSON.cpp)

ADD_EXECUTABLE(${PROJECT_NAME}
        ${SOURCE_LIST}
        ${SOURCE_LIST_PROCESSING_CLASS}
        ${SOURCE_LIST_ROUTE}
        ${SOURCE_LIST_PARSER})

