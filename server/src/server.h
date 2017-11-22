
#ifndef server_h
#define server_h

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

// TODO: Put this in the class
// The maximum size, in bytes, of a message that can be read.
#define MAX_BUFFER_SIZE 512

// A sychronous TCP server, this is fine since we only have one client suppling
// JSON actions.
class Server {
private:
    boost::asio::io_service &io_service;
    // Used to accept connections from clients.
    tcp::acceptor acceptor;

public:
    // Create a server listening on the specified port for connections, for
    // IP version 4.
    Server(boost::asio::io_service &io_service, int port);

    // Listen to connections from clients, and read the message they send.
    // It is expected that each client that connects will send a message.
    void start_accepts() throw(boost::system::system_error);

private:
    // Listen for a connection from a single client. This blocks until a
    // client has connected and send a message.
    void accept_client() throw(boost::system::system_error);
};

#endif // server_h
