INCLUDE_DIRECTORIES(base_architecture/include/impl)
INCLUDE_DIRECTORIES(base_architecture/include/virtual)

INCLUDE_DIRECTORIES(processing_class/include/impl)
INCLUDE_DIRECTORIES(processing_class/include/virtual)

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
        processing_class/src/WriteAddreesDataImpl.cpp
        processing_class/src/WritePersonalDataImpl.cpp )

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_LIST} ${SOURCE_LIST_PROCESSING_CLASS})

