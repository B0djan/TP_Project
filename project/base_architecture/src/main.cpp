#include <iostream>
#include <string>
#include <csignal>

#include <SelectBasedEventLoop.hpp>

#include <ListeningNetworkSocket.hpp>

#include <HttpClientAcceptor.hpp>

#include <Utils.hpp>

int main(int argc, const char * argv[]) {
    errno = 0;
    ASSERT(argc == 3, "2 arguments expected: ip and port");
    std::cout << "Starting server..." << std::endl;

    signal(SIGPIPE, SIG_IGN);

    SelectBasedEventLoop loop;
    ListeningNetworkSocket listening_socket(argv[1], std::stoi(argv[2]), loop);


    HttpClientAcceptor client_acceptor;

    listening_socket.start_listening(client_acceptor);

    loop.run_until_complete();


    return 0;
}
