#include <boost/asio.hpp>

#ifndef server_h
#define server_h

using boost::asio::ip::tcp;

// TODO: Put this in the class
// The maximum size, in bytes, of a message that can be read.
#define MAX_BUFFER_SIZE 512

// A sychronous TCP server which can communicate with one client at a time, this
// is fine since we only have one client suppling JSON actions.
class Server {
private:
    boost::asio::io_service &io_service;
    // Used to accept connections from clients.
    tcp::acceptor acceptor;
    // Used to communicate with the connected client (singular).
    tcp::socket client_socket;
    // Whether there is a client connected.
    bool is_client_connected;

public:
    // Create a server listening on the specified port for connections, for
    // IP version 4.
    Server(boost::asio::io_service &io_service, int port);

    // Listen for a connection from a single client. Then listens to messages from
    // the client until it disconnects, at which point it waits for another client.
    void accept_client() throw(boost::system::system_error);

private:
    // Listens to messages from the connected client, until the client disconnects.
    void listen_to_client() throw(boost::system::system_error);
};

#endif // server_h
