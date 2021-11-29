INCLUDE_DIRECTORIES(base_architecture/include/impl)
INCLUDE_DIRECTORIES(base_architecture/include/virtual)

SET(SOURCE_LIST
        base_architecture/src/AsyncFileInputStream.cpp
        base_architecture/src/AsyncFileOutputStream.cpp
        base_architecture/src/SelectBasedEventLoop.cpp
        base_architecture/src/ListeningNetworkSocket.cpp
        base_architecture/src/HttpClientAcceptor.cpp
        base_architecture/src/FileImpl.cpp
        base_architecture/src/main.cpp )

ADD_EXECUTABLE(${PROJECT_NAME} ${SOURCE_LIST})
